#include <stdio.h>
unsigned long long count = 0;

void print_cycle(FILE * outfile, unsigned int * this_current_path){
    char lookup[10][2] = {"00","01","02","03","04","05","06","07","08","09"};
    char str[32] = "[__,__,__,__,__,__,__,__,__,__]\n";
    str[1] = lookup[this_current_path[0]][0];
    str[2] = lookup[this_current_path[0]][1];

    str[4] = lookup[this_current_path[1]][0];
    str[5] = lookup[this_current_path[1]][1];

    str[7] = lookup[this_current_path[2]][0];
    str[8] = lookup[this_current_path[2]][1];

    str[10] = lookup[this_current_path[3]][0];
    str[11] = lookup[this_current_path[3]][1];

    str[13] = lookup[this_current_path[4]][0];
    str[14] = lookup[this_current_path[4]][1];

    str[16] = lookup[this_current_path[5]][0];
    str[17] = lookup[this_current_path[5]][1];

    str[19] = lookup[this_current_path[6]][0];
    str[20] = lookup[this_current_path[6]][1];

    str[22] = lookup[this_current_path[7]][0];
    str[23] = lookup[this_current_path[7]][1];

    str[25] = lookup[this_current_path[8]][0];
    str[26] = lookup[this_current_path[8]][1];

    str[28] = lookup[this_current_path[9]][0];
    str[29] = lookup[this_current_path[9]][1];


    fwrite(str, 1, 32, outfile);
}

int main(int argc, const char * argv[]) {
    const unsigned int vo0[2] = {1,2};
    const unsigned int vo1[3] = {0,2,3};
    const unsigned int vo2[3] = {0,1,4};
    const unsigned int vo3[3] = {1,4,5};
    const unsigned int vo4[3] = {2,3,6};
    const unsigned int vo5[3] = {3,6,7};
    const unsigned int vo6[3] = {4,5,8};
    const unsigned int vo7[3] = {5,8,9};
    const unsigned int vo8[3] = {6,7,9};
    const unsigned int vo9[2] = {7,8};
    const unsigned int * vos[10] = {vo0,vo1,vo2,vo3,vo4,vo5,vo6,vo7,vo8,vo9};
    const unsigned int vomax[10] = {2,3,3,3,3,3,3,3,3,2};
    unsigned int current_path[10];
    unsigned int adjacency_path[10];
    register unsigned int path_position = 0;
    unsigned char fresh[10] = {1,1,1,1,1,1,1,1,1,1};
    unsigned char inplay[10] = {1,1,1,1,1,1,1,1,1,1};
    register unsigned int start = 0;
    register unsigned int fresh_found;
    register unsigned int fresh_found_adjacency;

    register unsigned int possible_fresh;
    register unsigned int possible_fresh_adjacency;
    register unsigned int local_max;
    FILE * outfile = fopen("findcy_temp.txt", "w");
    fwrite("[[0,1],[0,2],[1,2],[1,3],[2,4],[3,4],[3,5],[4,6],[5,6],[5,7],[6,8],[7,8],[7,9],[8,9]]\n", 1,86,outfile);

    starter_loop:
    if (start != 8 ) {
        inplay[start] = 0;
    fresh[0] = inplay[0]; fresh[1] = inplay[1]; fresh[2] = inplay[2]; fresh[3] = inplay[3]; fresh[4] = inplay[4]; fresh[5] = inplay[5]; fresh[6] = inplay[6]; fresh[7] = inplay[7]; fresh[8] = inplay[8]; fresh[9] = inplay[9]; 
    current_path[0] = start; current_path[1] = 0; current_path[2] = 0; current_path[3] = 0; current_path[4] = 0; current_path[5] = 0; current_path[6] = 0; current_path[7] = 0; current_path[8] = 0; current_path[9] = 0; 
    adjacency_path[0] = 0; adjacency_path[1] = 0; adjacency_path[2] = 0; adjacency_path[3] = 0; adjacency_path[4] = 0; adjacency_path[5] = 0; adjacency_path[6] = 0; adjacency_path[7] = 0; adjacency_path[8] = 0; adjacency_path[9] = 0; 

        fresh_found = 0;
        fresh_found_adjacency = 0;
        path_position = 0;
        begin_stepper:{
                local_max = vomax[current_path[path_position]];
                possible_fresh_adjacency = adjacency_path[path_position];
                begin_find_fresh:{
                    possible_fresh = vos[current_path[path_position]][possible_fresh_adjacency];
                    if (possible_fresh_adjacency != local_max) {
                        if (possible_fresh == start) {
                                if (path_position > 1) {
                                    print_cycle(outfile, current_path);
                                } else {
                                        ;
                                }
                                possible_fresh_adjacency++;
                                goto begin_find_fresh;
                        } else {
                            if (fresh[possible_fresh] && (possible_fresh_adjacency >= adjacency_path[path_position])) {
                                fresh_found = possible_fresh;
                                fresh_found_adjacency = possible_fresh_adjacency;
                                possible_fresh_adjacency++;
                                goto begin_check_for_cycle;
                            }
                        }
                        possible_fresh_adjacency++;
                        goto begin_find_fresh;
                    } else {
                        goto end_find_fresh;
                    }
                }end_find_fresh: goto step_back;
            begin_check_for_cycle:{
                if (possible_fresh_adjacency != local_max) {
                    possible_fresh = vos[current_path[path_position]][possible_fresh_adjacency];
                    if (possible_fresh == start) {
                            if (path_position > 1) {
                                    print_cycle(outfile, current_path);
                            } else {
                                    ;
                            }
                            goto end_check_for_cycle;
                    }
                    possible_fresh_adjacency++;
                    goto begin_check_for_cycle;
                } else {
                    goto end_check_for_cycle;
                }
            }end_check_for_cycle: goto step_forward;
            step_forward:
                adjacency_path[path_position] = fresh_found_adjacency;
                path_position++;
                current_path[path_position] = fresh_found;
                fresh[fresh_found] = 0;
                goto begin_stepper;
            step_back:
                if (path_position == 0) {
                    goto end_stepper;
                } else {
                    fresh[current_path[path_position]] = 1;
                    current_path[path_position] = 0;
                    adjacency_path[path_position] = 0;
                    path_position--;
                    adjacency_path[path_position]++;
                    goto begin_stepper;
                }
        }end_stepper:;
    
        start++;
        goto starter_loop;
    } else {

            fwrite("DONE.", 1, 5, outfile);
            fclose(outfile);
            return 0;
    }
    return 0;
}

