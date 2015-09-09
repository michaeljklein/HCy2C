module Cycles.Findcy where

import Cycles.Aux
import Data.Function

-- | Given two edges and whether the graph is directed, this function gives whether they are adjacent
edgeAdjacent :: [Int] -> [Int] -> Bool -> Bool
edgeAdjacent e1 e2 directed = if directed
                                 then (e1 !! 1) == head e2
                                 else overlapping && not thesame
  where
    -- (a,b) ; (c,d)
    thesame = (a == c) && (b == d)
    overlapping  = overlapping0 || overlapping1 || overlapping2 || overlapping3
    overlapping0 = a == c
    overlapping1 = a == d
    overlapping2 = b == c
    overlapping3 = b == d
    a = head e1
    b = e1 !! 1
    c = head e2
    d = e2 !! 1

-- | Given an edge, graph and whether it is directed, this function returns the list of indices of edges adjacent to the given edge
eadjpos :: [Int] -> [[Int]] -> Bool -> [Int]
eadjpos e1 graph directed = map fst $ filter (\e2 -> edgeAdjacent e1 (snd e2) directed) (enum graph)

-- | This is the maximum of a list two levels deep
max2 :: [[Int]] -> Int
max2 lists = maximum $ map maximum lists

-- | This gives a list = [[Int]] such that (list !! i) !! j = the jth edge adjacent to the ith edge
edgeAdjacencyLists :: [[Int]] -> Bool -> [[Int]]
edgeAdjacencyLists graph directed = map (\ei -> eadjpos (graph!!ei) graph directed) [0..max_edge]
  where
    max_edge = length $ init graph

-- | This is the analogous function to 'eadjpos', except for vertex adjacency instead of edge adjacency
vadjpos :: Int -> [[Int]] -> Bool -> [Int]
vadjpos v1 graph directed = if directed
                               then not_v1 $ has_v1_fst graph
                               else not_v1 $ has_v1 graph
  where
    has_v1     = filter (\e ->v1 `elem` e)
    has_v1_fst = filter (\e ->head e == v1)
    not_v1     = map (\e -> if head e == v1 then last e else head e)

-- | This is the analogous function to 'edgeAdjacencyLists', except for vertex adjacency instead of edge adjacency
vertexAdjacencyLists :: [[Int]] -> Bool -> [[Int]]
vertexAdjacencyLists graph directed = map (\vi -> vadjpos vi graph directed) [0..max_vertex]
  where
    max_vertex = max2 graph

-- | Following is the generator for a one-time use C program to find all cycles in a graph.
--
--      The general program will work with directed and undirected graphs and will find all *directed* cycles in the graph
--      I plan to modify the original program to work with graphs and digraphs and each modification to optinally only count cycles instead of listing them
--      This cannot be solved in O(V+E) time because even planar graphs can have O(2^v) cycles and listing/counting a graph cycle takes at least 1 CPU cycle
--
--      The algorithm performs a depth first search from an arbitrary vertex, marking seen vertices on the way, and only outputting cycles through
--              \ the initial vertex. As all cycles through that vertex have been found by the end, it is removed and the process repeated.
--              \ This way, there is no need to check if a cycle has been found yet and there are no sources of repetition.
--
--      The only weaknesses of this algorithm that I know are:
--              1) It requires full out-adjacency lists for each vertex (best fit for directed, sparse graphs)
--              2) For undirected graphs, if the cycles are considered to be undirected, it outputs one "forward" and one "backward" copy of each cycle
--                      N.B. For the purposes of inputting the cycles into the Max-Cycles part of the code, this is a strength as the algorithm needs both
--              3) Although the output file is formatted, it is annoying to integrate generating, compiling, running, and parsing into a single function
--              4) The generated code is in C. Yeah, I said it. On the plus side, unless you're running this on very big graphs
--                      \ (where it would take an obscene amount of time to finish), you shouldn't run into overflow issues.
--
--      The biggest plus? This algorithm is stupid-fast. The last big test I ran outputted ~1.5GB of cycles from ~2k strongly-connected graphs, |E|<=36  in under 30s.
--
-- Note: graph (edgelist), cfilename, are assumed variables
generateFindCyCode :: [[Int]] -> String -> Bool -> Bool -> String
generateFindCyCode graph cfilename justCount directed = unlines $ map (`formatByDict` dict) codelist
    where
        glen = gmax + 1 -- length graph
        gmax = max2 adj_lists -- length $ tail graph
        maxd = digLen10 glen
        outfilename = init cfilename ++ "txt"

        dict = [(":print_cycle",   print_cycle),
                (":init_lookup",   init_lookup),
                (":init_str",      init_str),
                (":init_strs",     init_strs),
                (":fwrite_str",    fwrite_str),
                -- (":adj_lists",    adj_lists),
                -- (":cadj_lists",   cadj_lists),
                (":voss",          voss),
                (":init_vos",      init_vos),
                (":init_vomax",    init_vomax),
                (":init_paths",    init_paths),
                (":init_fresh",    init_fresh),
                (":init_file",     init_file),
                (":fwrite_graph",  fwrite_graph),
                (":ifstart",       ifstart),
                (":assign_fresh",  assign_fresh),
                (":assign_cpath",  assign_cpath),
                (":assign_apath",  assign_apath),
                (":put_cycle",     put_cycle),
                (":fwrite_finish", fwrite_finish)]

        --"void print_cycle(outfileFILE * outfile, unsigned int * this_current_path){",
        print_cycle = if not justCount then "void print_cycle(FILE * outfile, unsigned int * this_current_path){" else "void print_cycle(unsigned int * this_current_path){"

        -- :init_lookup   char lookup[4][1] = {"0","1","2","3"};
        init_lookup_list = "    char lookup[" ++ show glen ++ "][" ++ show maxd ++ "] = {" ++ tail (init $ show vallist) ++ "};"
                where
                    vallist = map (\n -> padStrLeft0s (show n) maxd) [0..gmax]

        -- :init_str      char str[13] = "[_,_,_,_]\n"; -- Note that there could be multiple '_'s
        init_str_list = "    char str[" ++ show (3 + glen * maxd + glen - 1) ++ "] = \"[" ++ init (concat $ replicate glen (concat (replicate (digLen10 glen) "_") ++ ",")) ++ "]\\n\";"

        {- :init_strs
            str[1] = lookup[this_current_path[0]][0];
            str[3] = lookup[this_current_path[1]][0];
            str[5] = lookup[this_current_path[2]][0];
            str[7] = lookup[this_current_path[3]][0];
        -}
        init_strs_list = unlines $ map (\pathpos -> unlines $ map (\digpos -> "    str[" ++ show (pathpos * (maxd+1) + digpos + 1) ++ "] = lookup[this_current_path[" ++ show pathpos ++ "]][" ++ show digpos ++ "];") [0..(maxd-1)]) [0..gmax]
        -- numparts = \j -> "    str[" ++ (show (j * (maxd + 1) + i
        -- pathparts = \i -> unlines $ map numparts [0..(maxd-1)]
        -- init_strs_list = unlines $ map pathparts [0..(glen-1)]
        -- :fwrite_str    fwrite(str, 1, 13, outfile);
        fwrite_str_list = "    fwrite(str, 1, " ++ show (3 + glen * digLen10 glen + glen - 1) ++ ", outfile);"

        init_lookup = if not justCount then init_lookup_list else ""
        init_str    = if not justCount then init_str_list else ""
        init_strs   = if not justCount then init_strs_list else ""
        fwrite_str  = if not justCount then fwrite_str_list else "    count++;"
        init_file   = if not justCount then init_file_write else ""
        fwrite_graph= if not justCount then fwrite_graph_write else ""

        --"    if (start != 2 ) {"
        ifstart = "    if (start != " ++ show (glen - 2) ++ " ) {" -- (glen - 2) because if there are only 2 vertices left, there is no room for an additional cycle in the remaining graph
        {- :init_vos
                          const unsigned int vo0[3] = {1, 2, 3};
                          const unsigned int vo1[1] = {2};
                          const unsigned int vo2[1] = {3};
                          const unsigned int vo3[1] = {1};
                          const unsigned int * vos[4] = {vo0,vo1,vo2,vo3};
        -}
        --adj_lists = if directed then dadj_lists else uadj_lists
        --uadj_lists = map (\v ->sort $ map (otherElem v) (filter (\e -> elem v e) graph)) [0..(glen - 1)]
        --dadj_lists= map (\v ->sort $ map (otherElem v) (filter (\e -> (last e) == v) graph)) [0..(glen -1)]
        adj_lists = vertexAdjacencyLists graph directed --edgeAdjacencyLists graph directed

        cadj_lists = unlines' $ zipWith (\l i -> "    const unsigned int vo" ++ show i ++ "[" ++ show (length l) ++ "] = {" ++ trim (show l) ++ "};") adj_lists [0..]
        voss = "    const unsigned int * vos[" ++ show glen ++ "] = {" ++ tail (concat $ zipWith (++) [",vo" | x <- [0..]] (map show [0..gmax])) ++ "};"
--        (init $ tail $ tail $ zipWith (++) [",vo" | x <- [0..]] (map show [0..gmax])) ++ "};"
        init_vos = cadj_lists ++ voss

        -- :init_vomax    const unsigned int vomax[4] = {3, 1, 1, 1};
        init_vomax = "    const unsigned int vomax[" ++ show glen ++ "] = {" ++ trim (show $ map length adj_lists) ++ "};"

        -- :init_paths    unsigned int current_path[4];
        --                unsigned int adjacency_path[4];
        init_paths = "    unsigned int current_path[" ++ show glen ++ "];\n    unsigned int adjacency_path[" ++ show glen ++ "];"

        -- :init_fresh    unsigned char fresh[4] = {1,1,1,1};
        --                unsigned char inplay[4] = {1,1,1,1};
        init_fresh = "    unsigned char fresh[" ++ show glen ++ "] = {" ++ trim (show $ replicate glen 1) ++ "};\n    unsigned char inplay[" ++ show glen ++ "] = {" ++ trim (show $ replicate glen 1) ++ "};"

        -- :init_file     FILE * outfile = fopen("checking.txt", "w");
        init_file_write = "    FILE * outfile = fopen(\"" ++ outfilename ++ "\", \"w\");"

        -- :fwrite_graph  fwrite("[[0,1],[0,2],[0,3],[1,2],[3,1],[2,3]]\n",1,39,outfile);
        fwrite_graph_write = "    fwrite(\"" ++ show graph ++ "\\n\", 1," ++ show (length' $ '0':show graph) ++ ",outfile);"

        -- :assign_fresh  fresh[0] = inplay[0]; fresh[1] = inplay[1]; fresh[2] = inplay[2]; fresh[3] = inplay[3];
        assign_fresh = "    " ++ concatMap (\i -> "fresh[" ++ show i ++ "] = inplay[" ++ show i ++ "]; ") [0..(glen - 1)]

        -- :assign_cpath  current_path[0] = start; current_path[1] = 0; current_path[2] = 0; current_path[3] = 0;
        assign_cpath = "    current_path[0] = start; " ++ concatMap (\i -> "current_path[" ++ show i ++ "] = 0; ") [1..(glen-1)]

        -- :assign_apath  adjacency_path[0] = 0; adjacency_path[1] = 0; adjacency_path[2] = 0; adjacency_path[3] = 0;,
        assign_apath = "    " ++ concatMap (\i -> "adjacency_path[" ++ show i ++ "] = 0; ") [0..(glen-1)]

        --"                                    print_cycle(outfile, current_path);",
        put_cycle = if not justCount then "                                    print_cycle(outfile, current_path);" else "                                    print_cycle(current_path);"

        -- :fwrite_finish            fwrite(\"DONE.\", 1, 5, outfile);
        fwrite_finish = if not justCount
                           then "            fwrite(\"DONE.\", 1, 5, outfile);\n            fclose(outfile);"
                           else "            printf(\"%llu\\n\", count);\n"--            fwrite(str, 1, 21, outfile);\n            fwrite(\"DONE.\", 1, 5, outfile);"
        codelist = ["#include <stdio.h>",
                    "unsigned long long count = 0;",
                    "",
                    --"void print_cycle(outfileFILE * outfile, unsigned int * this_current_path){",
                    ":print_cycle",
                    ":init_lookup",
                    ":init_str",
                    ":init_strs",
                    ":fwrite_str",
                    -- :init_lookup   char lookup[4][1] = {"0","1","2","3"};
                    -- :init_str      char str[13] = "[_,_,_,_]\n";
                    {- :init_strs
                        str[1] = lookup[this_current_path[0]][0];
                        str[3] = lookup[this_current_path[1]][0];
                        str[5] = lookup[this_current_path[2]][0];
                        str[7] = lookup[this_current_path[3]][0];
                    -}
                    -- :fwrite_str    fwrite(str, 1, 13, outfile);
                    "}",
                    "",
                    "int main(int argc, const char * argv[]) {",
                    ":init_vos",
                    ":init_vomax",
                    {- :init_vos
                                      const unsigned int vo0[3] = {1, 2, 3};
                                      const unsigned int vo1[1] = {2};
                                      const unsigned int vo2[1] = {3};
                                      const unsigned int vo3[1] = {1};
                                      const unsigned int * vos[4] = {vo0,vo1,vo2,vo3};
                    -}
                    -- :init_vomax    const unsigned int vomax[4] = {3, 1, 1, 1};

                    ":init_paths",
                    -- :init_paths    unsigned int current_path[4];
                    --                unsigned int adjacency_path[4];
                    "    register unsigned int path_position = 0;",
                    ":init_fresh",
                    -- :init_fresh    unsigned char fresh[4] = {1,1,1,1};
                    --                unsigned char inplay[4] = {1,1,1,1};
                    "    register unsigned int start = 0;",
                    "    register unsigned int fresh_found;",
                    "    register unsigned int fresh_found_adjacency;",
                    "",
                    "    register unsigned int possible_fresh;",
                    "    register unsigned int possible_fresh_adjacency;",
                    "    register unsigned int local_max;",
                    ":init_file",
                    -- :init_file     FILE * outfile = fopen("checking.txt", "w");
                    ":fwrite_graph",
                    -- :fwrite_graph  fwrite("[[0,1],[0,2],[0,3],[1,2],[3,1],[2,3]]\n",1,39,outfile);
                    "",
                    "    starter_loop:",
                    --"    if (start != 2 ) {",
                    ":ifstart",
                    "        inplay[start] = 0;",
                    ":assign_fresh",
                    ":assign_cpath",
                    ":assign_apath",
                    -- :assign_fresh  fresh[0] = inplay[0]; fresh[1] = inplay[1]; fresh[2] = inplay[2]; fresh[3] = inplay[3];
                    -- :assign_cpath  current_path[0] = start; current_path[1] = 0; current_path[2] = 0; current_path[3] = 0;
                    -- :assign_apath  adjacency_path[0] = 0; adjacency_path[1] = 0; adjacency_path[2] = 0; adjacency_path[3] = 0;,
                    "",
                    "        fresh_found = 0;",
                    "        fresh_found_adjacency = 0;",
                    "        path_position = 0;",
                    "        begin_stepper:{",
                    "                local_max = vomax[current_path[path_position]];",
                    "                possible_fresh_adjacency = adjacency_path[path_position];",
                    "                begin_find_fresh:{",
                    "                    possible_fresh = vos[current_path[path_position]][possible_fresh_adjacency];",
                    "                    if (possible_fresh_adjacency != local_max) {",
                    "                        if (possible_fresh == start) {",
                    "                                if (path_position > 1) {",
                    --"                                    print_cycle(outfile, current_path);",
                    ":put_cycle",
                    "                                } else {",
                    "                                        ;",
                    "                                }",
                    "                                possible_fresh_adjacency++;",
                    "                                goto begin_find_fresh;",
                    "                        } else {",
                    "                            if (fresh[possible_fresh] && (possible_fresh_adjacency >= adjacency_path[path_position])) {",
                    "                                fresh_found = possible_fresh;",
                    "                                fresh_found_adjacency = possible_fresh_adjacency;",
                    "                                possible_fresh_adjacency++;",
                    "                                goto begin_check_for_cycle;",
                    "                            }",
                    "                        }",
                    "                        possible_fresh_adjacency++;",
                    "                        goto begin_find_fresh;",
                    "                    } else {",
                    "                        goto end_find_fresh;",
                    "                    }",
                    "                }end_find_fresh: goto step_back;",
                    "            begin_check_for_cycle:{",
                    "                if (possible_fresh_adjacency != local_max) {",
                    "                    possible_fresh = vos[current_path[path_position]][possible_fresh_adjacency];",
                    "                    if (possible_fresh == start) {",
                    "                            if (path_position > 1) {",
                    --"                                    print_cycle(outfile, current_path);",
                    ":put_cycle",
                    "                            } else {",
                    "                                    ;",
                    "                            }",
                    "                            goto end_check_for_cycle;",
                    "                    }",
                    "                    possible_fresh_adjacency++;",
                    "                    goto begin_check_for_cycle;",
                    "                } else {",
                    "                    goto end_check_for_cycle;",
                    "                }",
                    "            }end_check_for_cycle: goto step_forward;",
                    "            step_forward:",
                    "                adjacency_path[path_position] = fresh_found_adjacency;",
                    "                path_position++;",
                    "                current_path[path_position] = fresh_found;",
                    "                fresh[fresh_found] = 0;",
                    "                goto begin_stepper;",
                    "            step_back:",
                    "                if (path_position == 0) {",
                    "                    goto end_stepper;",
                    "                } else {",
                    "                    fresh[current_path[path_position]] = 1;",
                    "                    current_path[path_position] = 0;",
                    "                    adjacency_path[path_position] = 0;",
                    "                    path_position--;",
                    "                    adjacency_path[path_position]++;",
                    "                    goto begin_stepper;",
                    "                }",
                    "        }end_stepper:;",
                    "    ",
                    "        start++;",
                    "        goto starter_loop;",
                    "    } else {",
                    "",
                    ":fwrite_finish",
                    --"            fwrite(\"DONE.\", 1, 5, outfile);",
                    "            return 0;",
                    "    }",
                    "    return 0;",
                    "}",
                    ""]


