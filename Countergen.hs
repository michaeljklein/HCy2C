import Control.Monad
--import System.Directory
import System.IO
import System.Process
import Prelude hiding (catch)
import System.Directory
import Control.Exception
import System.IO.Error hiding (catch)

--TODO: add arg for initialization of counter extras (ex, in main for lut8/16)

-- makeCounterPip examples:
-- (convert)
--  int counter(unsigned long long x){
--        return popcount_fbsd1(ull2buf(x),4);
--  }
--
--  int counter(unsigned long long x){
--        return popcount_wikipedia_2(&x, 1);
--  }

makeCounterPipe :: [Char] -> [Char] -> [[Char]]
makeCounterPipe fstr bits = if bits == "16"
                        then convert ++ ["int counter(unsigned long long x) {",
                                       "    return " ++ fstr ++ "(ull2buf(x), 4);",
                                       "}"]
                        else ["int counter(unsigned long long x){",
                             "    return " ++ fstr ++ "(&x, 1);",
                             "}"]

elemIndexS :: [Char] -> [([[Char]], [[Char]])] -> Int
elemIndexS x l = maximum $ zipWith (\e i -> if (head $ fst e) == x then i else 0) l [0..]

makeCounter :: [Char] -> [Char]
makeCounter pname = if elem pname (map (\x -> head $ fst x) cdict)
                    then (unlines $ snd tup) ++ (unlines (makeCounterPipe (head $ fst tup) (head $ tail $ fst tup)))
                    else "[NO POPCOUNT WITH GIVEN NAME FOUND]"
  where
      tup = cdict !! (elemIndexS pname cdict)

lookupCounter :: [Char] -> [Char]
lookupCounter name = if filtered_dict == [] then "" else head $ fst $ head filtered_dict
                where
                  filtered_dict :: [([[Char]],[[Char]])]
                  filtered_dict = filter (\s -> name == (last $ fst s)) cdict

testCounterSimple :: Int -> IO ()
testCounterSimple n = do
  putStr ((head $ fst (cdict !! n)) ++ ":\n")
  testh <- openFile ((head $ fst (cdict !! n)) ++ ".c") WriteMode
  hPutStr testh "include <stdio.h>\n"
  let counter = makeCounter (head $ fst (cdict !! n))
  hPutStr testh counter
  hPutStr testh "int main(){\n    printf(\"%d\\n\", counter(18446744073709551615LLU));\n}"
  hClose testh
  comp_results <- readProcess "gcc" [(head $ fst (cdict !! n)) ++ ".c", "-O3", "-o", head $ fst (cdict !! n)] []
  putStr comp_results
  run_results <- readProcess ("./" ++ (head $ fst (cdict !! n))) [] []
  putStr run_results
  putStr $ show $ run_results == "64"

-- putBestCounter :: IO Handle -> IO ()
-- putBestCounter filehandle = do
-- --     doesFileExist "best_counter"
--     when (doesFileExist "best_counter") do
--             best <- readFile "best_counter"
-- --            best <- hGetLine settings
-- --            hclose settings
--             counter_name <- lookupCounter best
--             counter <- makeCounter counter_name
--             hPutStr filehandle counter
--     when (not $ doesFileExist "best_counter") do
--             comp_results <- readProcess "g++" ["popcnt.cpp", "-O3", "-o", "popcnt"] []
--             putStr comp_results
--             raw_string <- readProcess "./popcnt" [] []
--             putStr raw_string
--             pair_string <- map (take 2) $ filter (\l -> "32511665" == last l) $ map words $ lines raw_string
--             pairs <- zip (map head raw_string) (map (\x -> read x :: Integer) $ map last raw_string)
--             best <- fst $ head $ filter (\x -> (maximum $ map snd pairs) == snd x) pairs
--             settings <- openFile "best_counter" WriteMode
--             settings_results <- hPutStr settings best
--             hClose settings
--             counter_name <- lookupCounter best
--             counter <- makeCounter counter_name
--             hPutStr filehandle counter

findBestCounter :: IO [Char]
findBestCounter = do
  let comp_results = readProcess "g++" ["popcnt.cpp", "-O3", "-o", "popcnt"] []
--  putStr comp_results
  raw_string <- readProcess "./popcnt" [] []
--  putStr raw_string
  let pair_string = map (take 2) $ filter (\l -> "32511665" == last l) $ map words $ lines $ liftM (\x -> x) raw_string
  let pairs = zip (map head pair_string) (map (\x -> read x :: Integer) $ map last pair_string)
  let best = fst $ head $ filter (\x -> (maximum $ map snd pairs) == snd x) pairs
  settings <- openFile "best_counter" WriteMode
  settings_results <- hPutStr settings best
  hClose settings
  return best

putBestCounter filehandle = do
--  best <- handle (\_ ->findBestCounter) (readFile "best_counter")
  best <- catch (readFile "best_counter") handler --(\_ ->findBestCounter)
  let counter =  makeCounter $ lookupCounter best
  hPutStr filehandle counter
    where
      handler :: SomeException -> IO [Char]
      handler _ = findBestCounter

main :: IO ()
main = do
  null <- mapM_ testCounterSimple [0..(length $ tail $ cdict)]
  putStr "Done."

------------------------------------------------------------------------------------------------
--The following is only data:
------------------------------------------------------------------------------------------------
--for wikipedia 2 and 3
consts = ["#import <stdint.h>",
          "const uint64_t m1  = UINT64_C(0x5555555555555555); // binary: 0101...",
          "const uint64_t m2  = UINT64_C(0x3333333333333333); // binary: 00110011..",
          "const uint64_t m4  = UINT64_C(0x0f0f0f0f0f0f0f0f); // binary:  4 zeros,  4 ones ...",
          "const uint64_t m8  = UINT64_C(0x00ff00ff00ff00ff); // binary:  8 zeros,  8 ones ...",
          "const uint64_t m16 = UINT64_C(0x0000ffff0000ffff); // binary: 16 zeros, 16 ones ...",
          "const uint64_t m32 = UINT64_C(0x00000000ffffffff); // binary: 32 zeros, 32 ones",
          "const uint64_t hff = UINT64_C(0xffffffffffffffff); // binary: all ones",
          "const uint64_t h01 = UINT64_C(0x0101010101010101); // the sum of 256 to the power of 0,1,2,3..."]

--sse2s start with sse2b (begin) and end with sse2e (end)
cdict :: [([[Char]], [[Char]])]
cdict =[(["popcount_lut8",        "16", "8-bit_LUT"         ],    lut8),
        (["popcount_lut16",       "16", "16-bit_LUT"        ],    lut16),
        (["popcount_fbsd1",       "16", "FreeBSD_version_1" ],    fbsd1),
        (["popcount_fbsd2",       "16", "FreeBSD_version_2" ],    fbsd2),
        (["popcount_wikipedia_2", "64", "Wikipedia_#2"      ],    consts ++ wiki2),
        (["popcount_wikipedia_3", "64", "Wikipedia_#3"      ],    consts ++ wiki3),
        (["popcount_gcc",         "16", "gcc_popcount"      ],    gcc),
        (["popcountll_gcc",       "64", "gcc_popcountll"    ],    llgcc),
        (["popcount_wegner",      "16", "Wegner//Kernigan"  ],    wegner),
        (["popcount_anderson",    "16", "Anderson"          ],    ander),
        (["popcount_hakmem_169",  "16", "HAKMEM_169//X11"   ],    hakmem),
        (["popcount_roladc8",     "16", "8x_shift_and_add"  ],    rol8),
        (["popcount_roladc32",    "16", "32x_shift_and_add" ],    rol32),
        (["popcount_7words",      "16", "Bitslice(7)"       ],    fbsd2 ++ words7),
        (["popcount_24words",     "16", "Bitslice(24)"      ],    words24),
        (["popcount_lauradox",    "16", "Lauradox"          ],    laurad),
        (["popcount_sse2_8bit",   "16", "SSE2_8-bit"        ],    sse2b ++ sse28  ++ sse2e),
        (["popcount_sse2_16bit",  "16", "SSE2_16-bit"       ],    sse2b ++ sse216 ++ sse2e),
        (["popcount_sse2_32bit",  "16", "SSE2_32-bit"       ],    sse2b ++ sse232 ++ sse2e),
        (["popcount_ssse3",       "16", "SSSE3"             ],    ssse3)]

convert = ["unsigned * ull2buf(unsigned long long x){ //takes ~1.1476 picoseconds on 64bit 2.5GHZ Macbook Pro, gcc O3",
           "unsigned * buf;",
           "unsigned y[8];",
           "unsigned long long z = x;",
           "y[0] = z & 65535; //16 ones",
           "z >>= 16;",
           "y[1] = z & 65535;",
           "z >>= 16;",
           "y[2] = z & 65535;",
           "z >>= 16;",
           "y[3] = z & 65535;",
           "",
           "buf = y;",
           "return buf;",
           "}",
           ""]

lut8 =    ["unsigned char *lut;",
          "",
          "void init_lut(void)",
          "{",
          "    lut = new unsigned char[65536];",
          "    ",
          "    for (int i = 0; i < 65536; i++) {",
          "        int bit_count = 0;",
          "        // count bits using Wegner/Kernigan",
          "        for (int j = i; j != 0; j &= j - 1)",
          "            bit_count++;",
          "        lut[i] = bit_count;",
          "    }",
          "}",
          "",
          "",
          "static inline int popcount_lut8(unsigned *buf, int n)",
          "{",
          "  int cnt=0;",
          "  unsigned int i;",
          "  do {",
          "    i = *buf;",
          "    cnt += lut[i&255];",
          "    cnt += lut[i>>8&255];",
          "    cnt += lut[i>>16&255];",
          "    cnt += lut[i>>24];  /* APD: removed the unneeded &255 */",
          "    buf++;",
          "  } while(--n);",
          "  return cnt;",
          "}"]

lut16 =   ["unsigned char *lut;",
          "",
          "void init_lut(void)",
          "{",
          "    lut = new unsigned char[65536];",
          "    ",
          "    for (int i = 0; i < 65536; i++) {",
          "        int bit_count = 0;",
          "        // count bits using Wegner/Kernigan",
          "        for (int j = i; j != 0; j &= j - 1)",
          "            bit_count++;",
          "        lut[i] = bit_count;",
          "    }",
          "}",
          "",
          "static inline int popcount_lut16(unsigned *buf, int n)",
          "{",
          "  int cnt=0;",
          "  do {",
          "    cnt += lut[(*buf)&65535];",
          "    cnt += lut[(*buf)>>16];",
          "    buf++;",
          "  } while(--n);",
          "  return cnt;",
          "}"]

fbsd1 =  ["static inline int popcount_fbsd1(unsigned *buf, int n)",
          "{",
          "    int cnt=0;",
          "    do {",
          "        unsigned m = *buf++;",
          "        m = (m & 0x55555555) + ((m & 0xaaaaaaaa) >> 1);",
          "        m = (m & 0x33333333) + ((m & 0xcccccccc) >> 2);",
          "        m = (m & 0x0f0f0f0f) + ((m & 0xf0f0f0f0) >> 4);",
          "        m = (m & 0x00ff00ff) + ((m & 0xff00ff00) >> 8);",
          "        m = (m & 0x0000ffff) + ((m & 0xffff0000) >> 16);",
          "        cnt += m;",
          "    } while(--n);",
          "    return cnt;",
          "}"]


fbsd2 =  ["static inline int popcount_fbsd2(unsigned *buf, int n)",
          "{",
          "    int cnt=0;",
          "    do {",
          "        unsigned v = *buf++;",
          "        v -= ((v >> 1) & 0x55555555);",
          "        v = (v & 0x33333333) + ((v >> 2) & 0x33333333);",
          "        v = (v + (v >> 4)) & 0x0F0F0F0F;",
          "        v = (v * 0x01010101) >> 24;",
          "        cnt += v;",
          "    } while(--n);",
          "    return cnt;",
          "}"]

wiki2 =  ["static inline int popcount_wikipedia_2(uint64_t *buf, int n) {",
          "    int cnt=0;",
          "    uint64_t x;",
          "    do {",
          "        x = *buf;",
          "        x -= (x >> 1) & m1;             //put count of each 2 bits into those 2 bits",
          "        x = (x & m2) + ((x >> 2) & m2); //put count of each 4 bits into those 4 bits",
          "        x = (x + (x >> 4)) & m4;        //put count of each 8 bits into those 8 bits",
          "        x += x >>  8;  //put count of each 16 bits into their lowest 8 bits",
          "        x += x >> 16;  //put count of each 32 bits into their lowest 8 bits",
          "        x += x >> 32;  //put count of each 64 bits into their lowest 8 bits",
          "        cnt += x & 0x7f;",
          "        buf++;",
          "    } while (--n);",
          "    return cnt;",
          "}"]

wiki3 =  ["static inline int popcount_wikipedia_3(uint64_t *buf, int n) {",
          "    int cnt=0;",
          "    uint64_t x;",
          "    do {",
          "        x = *buf;",
          "        x -= (x >> 1) & m1;             //put count of each 2 bits into those 2 bits",
          "        x = (x & m2) + ((x >> 2) & m2); //put count of each 4 bits into those 4 bits",
          "        x = (x + (x >> 4)) & m4;        //put count of each 8 bits into those 8 bits",
          "        cnt += (x * h01)>>56;  //returns left 8 bits of x + (x<<8) + (x<<16) + (x<<24)+...",
          "        buf++;",
          "    } while (--n);",
          "    return cnt;",
          "}"]

gcc =    ["static inline int popcount_gcc(unsigned *buf, int n) {",
          "    int cnt = 0;",
          "    int i;",
          "    for (i = 0; i < n - n % 4; i += 4) {",
          "        cnt += (__builtin_popcount(buf[i+0]) + __builtin_popcount(buf[i+1])) +",
          "        (__builtin_popcount(buf[i+2]) + __builtin_popcount(buf[i+3]));",
          "    }",
          "    for (; i < n; i++) {",
          "        cnt += __builtin_popcount(buf[i]);",
          "    }",
          "    return cnt;",
          "}"]

llgcc =  ["#import <stdint.h>",
          "static inline int popcountll_gcc(uint64_t *buf, int n) {",
          "    int cnt = 0;",
          "    int i;",
          "    for (i = 0; i < n - n % 4; i += 4) {",
          "        cnt += (__builtin_popcountll(buf[i+0]) + __builtin_popcountll(buf[i+1])) +",
          "        (__builtin_popcountll(buf[i+2]) + __builtin_popcountll(buf[i+3]));",
          "    }",
          "    for (; i < n; i++) {",
          "        cnt += __builtin_popcountll(buf[i]);",
          "    }",
          "    return cnt;",
          "}"]

wegner =  ["static inline int popcount_wegner(unsigned *buf, int n) {",
          "    int cnt=0;",
          "    unsigned v;",
          "    while (n--) {",
          "        v = *buf;",
          "        while (v) {",
          "            cnt++;",
          "            v &= v-1;  /*  clear the least significant bit set */",
          "        }",
          "        buf++;",
          "    }",
          "    return cnt;",
          "}"]

ander =   ["static inline int popcount_anderson(unsigned *buf, int n) {",
          "    int cnt=0;",
          "    uint64_t v;",
          "    while (n--) {",
          "        v = *buf;",
          "        cnt += ((v & 0xfff) * 0x1001001001001ULL & 0x84210842108421ULL) % 0x1f;",
          "        cnt += (((v & 0xfff000) >> 12) * 0x1001001001001ULL & 0x84210842108421ULL) % 0x1f;",
          "        cnt += ((v >> 24) * 0x1001001001001ULL & 0x84210842108421ULL) % 0x1f;",
          "        buf++;",
          "    }",
          "    return cnt;",
          "}"]

hakmem =  ["static inline int popcount_hakmem_169(unsigned *buf, int n) {",
          "    int cnt=0;",
          "    unsigned tmp, w;",
          "    ",
          "    while (n--) {",
          "        w = *buf;",
          "        tmp = w - ((w >> 1) & 033333333333) - ((w >> 2) & 011111111111);",
          "        cnt += ((tmp + (tmp >> 3)) & 030707070707) % 63;",
          "        buf++;",
          "    }",
          "    return cnt;",
          "}"]

rol8 =    ["#if !defined(__GNUC__)",
          "#error gnuc required.",
          "#endif",
          "#if defined(__GNUC__)",
          "#define ROLADC8 __asm__(\"rolb %%al; \"\\",
          "\"adcl $0,%1;\": \"=a\"(c), \"=r\"(cnt) : \"0\"(c), \"1\"(cnt))",
          "static inline int popcount_roladc8(char *buf, int n)",
          "{",
          "    int cnt=0;",
          "    do {",
          "        char c = *buf++;",
          "        ROLADC8; ROLADC8; ROLADC8; ROLADC8; ROLADC8; ROLADC8; ROLADC8; ROLADC8;",
          "    } while(--n);",
          "    return cnt;",
          "}",
          "#endif"]

rol32 =   ["#if !defined(__GNUC__)",
          "#error gnuc required.",
          "#endif",
          "if defined(__GNUC__)",
          "#define ROLADC32 __asm__(\"roll %0; \"\\",
          "\"adcl $0,%1;\": \"=r\"(c), \"=r\"(cnt) : \"0\"(c), \"1\"(cnt))",
          "static inline int popcount_roladc32(unsigned *buf, int n)",
          "{",
          "    int cnt=0;",
          "    do {",
          "        unsigned c = *buf++;",
          "        ROLADC32; ROLADC32; ROLADC32; ROLADC32; ROLADC32; ROLADC32; ROLADC32; ROLADC32;",
          "        ROLADC32; ROLADC32; ROLADC32; ROLADC32; ROLADC32; ROLADC32; ROLADC32; ROLADC32;",
          "        ROLADC32; ROLADC32; ROLADC32; ROLADC32; ROLADC32; ROLADC32; ROLADC32; ROLADC32;",
          "        ROLADC32; ROLADC32; ROLADC32; ROLADC32; ROLADC32; ROLADC32; ROLADC32; ROLADC32;",
          "    } while(--n);",
          "    return cnt;",
          "}",
          "#endif /* defined(__GNUC__) */"]


words7 =  ["#define FULL_ADD(c1, c0, w0, w1, s1, s2) w1 = s1; c0 = w0; w0 &= w1; \\",
          "c0 ^= w1; w1 = s2; c1 = c0; c0 ^= w1; c1 &= w1; c1 |= w0",
          "",
          "#define MASK55 0x55555555",
          "#define MASK33 0x33333333",
          "#define MASK0F 0x0f0f0f0f",
          "",
          "unsigned count_bits7(unsigned *src)",
          "{",
          "    unsigned c0, c1, t0, t1, d0, d1, e0, e1, f1, f2;",
          "    ",
          "    t0 = src[0];",
          "    FULL_ADD(c1, c0, t0, t1, src[1], src[2]); // c1:c0         Up to 4 live vars+src[]",
          "    FULL_ADD(d1, d0, c0, t1, src[3], src[4]); // d1:d0, c1     Up to 5 live vars+src[]",
          "    FULL_ADD(e1, e0, d0, t1, src[5], src[6]); // e1:e0, d1, c1 Up to 6 live vars+src[]",
          "    FULL_ADD(f2, f1, c1, t1,     d1,     e1); // f2:f1:e0",
          "    ",
          "    e0 -= (e0 >> 1) & MASK55;                    // 2 bits, 0-2",
          "    f1 -= (f1 >> 1) & MASK55;",
          "    f2 -= (f2 >> 1) & MASK55;",
          "    ",
          "    e0 = (e0 & MASK33) + ((e0 >> 2) & MASK33);   // 4 bits, 0-4",
          "    f1 = (f1 & MASK33) + ((f1 >> 2) & MASK33);",
          "    f2 = (f2 & MASK33) + ((f2 >> 2) & MASK33);",
          "    ",
          "    e0 += e0 >> 4; f1 += f1 >> 4; f2 += f2 >> 4; // 4 bits, 0-8",
          "    e0 &= MASK0F; f1 &= MASK0F; f2 &= MASK0F;    // 8 bits, 0-8",
          "    ",
          "    e0 += (f1 << 1) + (f2 << 2);  // 8 bits, 0-8+16+32 = 56",
          "    e0 += e0 >> 8;                // 8 bits, 0-112",
          "    e0 += e0 >> 16;               // 8 bits, 0-224",
          "    ",
          "    return e0 & 255;",
          "}",
          "",
          "static inline int popcount_7words(unsigned *buf, int n) {",
          "    int cnt=0, i;",
          "    for (i=0; i<n-n%7; i+=7) {",
          "        cnt += count_bits7(buf+i);",
          "    }",
          "    return cnt + popcount_fbsd2(buf+i, n-i);",
          "}"]

words24 = ["static inline int merging2(const unsigned *data)",
          "{",
          "    unsigned count1,count2,half1,half2;",
          "    count1=data[0];",
          "    count2=data[1];",
          "    half1=data[2]&0x55555555;",
          "    half2=(data[2]>>1)&0x55555555;",
          "    count1 = count1 - ((count1 >> 1) & 0x55555555);",
          "    count2 = count2 - ((count2 >> 1) & 0x55555555);",
          "    count1+=half1;",
          "    count2+=half2;",
          "    count1 = (count1 & 0x33333333) + ((count1 >> 2) & 0x33333333);",
          "    count2 = (count2 & 0x33333333) + ((count2 >> 2) & 0x33333333);",
          "    count1+=count2;",
          "    count1 = (count1&0x0F0F0F0F)+ ((count1 >> 4) & 0x0F0F0F0F);",
          "    count1 = count1  + (count1 >> 8);",
          "    count1 = count1 + (count1 >> 16);",
          "    ",
          "    return count1 & 0x000000FF;",
          "}",
          "",
          "static inline int merging3(const unsigned *data)",
          "{",
          "    unsigned count1,count2,half1,half2,acc=0;",
          "    int i;",
          "    ",
          "    for(i=0;i<24;i+=3)",
          "    {",
          "        count1=data[i];",
          "        count2=data[i+1];",
          "        //w = data[i+2];",
          "        half1=data[i+2]&0x55555555;",
          "        half2=(data[i+2]>>1)&0x55555555;",
          "        count1 = count1 - ((count1 >> 1) & 0x55555555);",
          "        count2 = count2 - ((count2 >> 1) & 0x55555555);",
          "        count1+=half1;",
          "        count2+=half2;",
          "        count1 = (count1 & 0x33333333) + ((count1 >> 2) & 0x33333333);",
          "        count1 += (count2 & 0x33333333) + ((count2 >> 2) & 0x33333333);",
          "        acc += (count1 & 0x0F0F0F0F)+ ((count1>>4) &0x0F0F0F0F);",
          "    }",
          "    acc = (acc & 0x00FF00FF)+ ((acc>>8)&0x00FF00FF);",
          "    acc = acc + (acc >> 16);",
          "    return acc & 0x00000FFFF;",
          "}",
          "static inline int popcount_fbsd2(unsigned *buf, int n)",
          "{",
          "    int cnt=0;",
          "    do {",
          "        unsigned v = *buf++;",
          "        v -= ((v >> 1) & 0x55555555);",
          "        v = (v & 0x33333333) + ((v >> 2) & 0x33333333);",
          "        v = (v + (v >> 4)) & 0x0F0F0F0F;",
          "        v = (v * 0x01010101) >> 24;",
          "        cnt += v;",
          "    } while(--n);",
          "    return cnt;",
          "}",
          "",
          "",
          "static inline int popcount_24words(unsigned *buf, int n) {",
          "    int cnt=0, i;",
          "    ",
          "    for (i=0; i<n-n%24; i+=24) {",
          "        cnt += merging3(buf+i);",
          "    }",
          "    for (;i<n-n%3; i+=3) {",
          "        cnt += merging2(buf+i);",
          "    }",
          "    cnt += popcount_fbsd2(buf+i, n-i);",
          "    return cnt;",
          "}"]

laurad = ["#import <stdint.h>",
          "static inline int popcount_lauradoux(unsigned *buf, int n) {",
          "    const uint64_t* data = (uint64_t*) buf;",
          "    uint32_t size = n/(sizeof(uint64_t)/sizeof(int));",
          "    const uint64_t m1  = UINT64_C(0x5555555555555555);",
          "    const uint64_t m2  = UINT64_C(0x3333333333333333);",
          "    const uint64_t m4  = UINT64_C(0x0F0F0F0F0F0F0F0F);",
          "    const uint64_t m8  = UINT64_C(0x00FF00FF00FF00FF);",
          "    const uint64_t m16 = UINT64_C(0x0000FFFF0000FFFF);",
          "    const uint64_t h01 = UINT64_C(0x0101010101010101);",
          "    ",
          "    uint32_t bitCount = 0;",
          "    uint32_t i, j;",
          "    uint64_t count1, count2, half1, half2, acc;",
          "    uint64_t x;",
          "    uint32_t limit30 = size - size % 30;",
          "    ",
          "    // 64-bit tree merging (merging3)",
          "    for (i = 0; i < limit30; i += 30, data += 30) {",
          "        acc = 0;",
          "        for (j = 0; j < 30; j += 3) {",
          "            count1  =  data[j];",
          "            count2  =  data[j+1];",
          "            half1   =  data[j+2];",
          "            half2   =  data[j+2];",
          "            half1  &=  m1;",
          "            half2   = (half2  >> 1) & m1;",
          "            count1 -= (count1 >> 1) & m1;",
          "            count2 -= (count2 >> 1) & m1;",
          "            count1 +=  half1;",
          "            count2 +=  half2;",
          "            count1  = (count1 & m2) + ((count1 >> 2) & m2);",
          "            count1 += (count2 & m2) + ((count2 >> 2) & m2);",
          "            acc    += (count1 & m4) + ((count1 >> 4) & m4);",
          "        }",
          "        acc = (acc & m8) + ((acc >>  8)  & m8);",
          "        acc = (acc       +  (acc >> 16)) & m16;",
          "        acc =  acc       +  (acc >> 32);",
          "        bitCount += (uint32_t)acc;",
          "    }",
          "    ",
          "    for (i = 0; i < size - limit30; i++) {",
          "        x = data[i];",
          "        x =  x       - ((x >> 1)  & m1);",
          "        x = (x & m2) + ((x >> 2)  & m2);",
          "        x = (x       +  (x >> 4)) & m4;",
          "        bitCount += (uint32_t)((x * h01) >> 56);",
          "    }",
          "    return bitCount;",
          "}"]

sse2b =  ["#if !(defined(__GNUC__) && defined(__SSE2__))",
          "#error gcc and sse2 required.",
          "#endif",
          "#if defined(__GNUC__) && defined(__SSE2__)",
          "#include <emmintrin.h>",
          "",
          "static inline __m128i _mm_srli1_epi8(__m128i v) {",
          "    // Avg returns (a_i + b_i + 1) >> 1; so make b_i = -1 to compute (a >> 1)",
          "    const __m128i neg1 = _mm_set1_epi8(0xFF);",
          "    return _mm_avg_epu8(v,neg1);",
          "}",
          "static inline __m128i _mm_srli2_epi8(__m128i v) {",
          "    // Faster than mask-and-shift approach used in srli4",
          "    return _mm_srli1_epi8(_mm_srli1_epi8(v));",
          "}",
          "static inline __m128i _mm_srli4_epi8(__m128i v) {",
          "    // Using ANDNOT lets us share the magic number with what's used for the popcount itself",
          "    const __m128i mask = _mm_set1_epi32(0x0F0F0F0F);",
          "    return _mm_srli_epi16(_mm_andnot_si128(mask,v),4);",
          "}",
          "",
          "static inline __m128i popcount_sse2_8_helper_1(unsigned* buf, int N) {",
          "    __m128i* vbuf = (__m128i*)buf;",
          "    __m128i total,count0,count1,count2,count3;",
          "    int i;",
          "    __m128i B0 = _mm_set1_epi32(0x55555555);",
          "    __m128i B1 = _mm_set1_epi32(0x33333333);",
          "    __m128i B2 = _mm_set1_epi32(0x0F0F0F0F);",
          "    total = _mm_setzero_si128();",
          "    for (i = 0; i < N; i+=4) {",
          "        __m128i v0 = _mm_load_si128(vbuf+i+0);",
          "        __m128i v1 = _mm_load_si128(vbuf+i+1);",
          "        __m128i v2 = _mm_load_si128(vbuf+i+2);",
          "        __m128i v3 = _mm_load_si128(vbuf+i+3);",
          "        ",
          "        count0 = _mm_sub_epi8(v0, _mm_and_si128(B0, _mm_srli1_epi8(v0)));",
          "        count1 = _mm_sub_epi8(v1, _mm_and_si128(B0, _mm_srli1_epi8(v1)));",
          "        count2 = _mm_sub_epi8(v2, _mm_and_si128(B0, _mm_srli1_epi8(v2)));",
          "        count3 = _mm_sub_epi8(v3, _mm_and_si128(B0, _mm_srli1_epi8(v3)));",
          "        ",
          "        count0 = _mm_add_epi8(_mm_and_si128(B1,count0),",
          "                              _mm_and_si128(B1,_mm_srli2_epi8(count0)));",
          "        count1 = _mm_add_epi8(_mm_and_si128(B1,count1),",
          "                              _mm_and_si128(B1,_mm_srli2_epi8(count1)));",
          "        count2 = _mm_add_epi8(_mm_and_si128(B1,count2),",
          "                              _mm_and_si128(B1,_mm_srli2_epi8(count2)));",
          "        count3 = _mm_add_epi8(_mm_and_si128(B1,count3),",
          "                              _mm_and_si128(B1,_mm_srli2_epi8(count3)));",
          "        ",
          "        count0 = _mm_and_si128(B2,_mm_add_epi8(count0,",
          "                                               _mm_srli4_epi8(count0)));",
          "        count1 = _mm_and_si128(B2,_mm_add_epi8(count1,",
          "                                               _mm_srli4_epi8(count1)));",
          "        count2 = _mm_and_si128(B2,_mm_add_epi8(count2,",
          "                                               _mm_srli4_epi8(count2)));",
          "        count3 = _mm_and_si128(B2,_mm_add_epi8(count3,",
          "                                               _mm_srli4_epi8(count3)));",
          "        ",
          "        total = _mm_add_epi8(total,_mm_add_epi8(_mm_add_epi8(count0,count1),",
          "                                                _mm_add_epi8(count2,count3)));",
          "    }",
          "    ",
          "    // Reduce 16*8b->{-,-,-,16b,-,-,-,16b}",
          "    const __m128i ZERO = _mm_setzero_si128();",
          "    return _mm_sad_epu8(total,ZERO);",
          "}"]

sse28 =   ["static inline int popcount_sse2_8bit(unsigned* buf,int n) {",
          "    int N = n/4;",
          "    __m128i count32 = _mm_setzero_si128();",
          "    // 2^5 loop iters might overflow 8-bit counter, so",
          "    // cap it at 2^4 iters per chunk",
          "    const int inner_maxits = 16;",
          "    while (N > inner_maxits) {",
          "        count32 = _mm_add_epi32(count32,popcount_sse2_8_helper_1(buf,inner_maxits));",
          "        buf += inner_maxits*4;",
          "        N -= inner_maxits;",
          "    }",
          "    if (N > 0) count32 = _mm_add_epi32(count32,popcount_sse2_8_helper_1(buf,N));",
          "    ",
          "    // Layout coming from PSADBW accumulation is 2*{0,32}: 0 S1 0 S0",
          "    int count;",
          "    _mm_store_ss((float*)&count,(__m128)(_mm_add_epi32(count32,_mm_shuffle_epi32(count32,_MM_SHUFFLE(2,2,2,2)))));",
          "    return count;",
          "}"]

sse216 = ["static inline __m128i reduce_16_to_32(__m128i v) {",
          "    // Reduce 8*16->4*32",
          "    const __m128i ZERO = _mm_setzero_si128();",
          "    __m128i temp1 = _mm_unpacklo_epi16(v,ZERO);",
          "    __m128i temp2 = _mm_unpackhi_epi16(v,ZERO);",
          "    return _mm_add_epi32(temp1,temp2);",
          "}",
          "",
          "static inline __m128i popcount_sse2_16_helper_1(unsigned* buf, int N) {",
          "    __m128i* vbuf = (__m128i*)buf;",
          "    __m128i total,count0,count1,count2,count3;",
          "    int i;",
          "    __m128i B0 = _mm_set1_epi32(0x55555555);",
          "    __m128i B1 = _mm_set1_epi32(0x33333333);",
          "    __m128i B2 = _mm_set1_epi32(0x0F0F0F0F);",
          "    __m128i B3 = _mm_set1_epi32(0x00FF00FF);",
          "    total = _mm_setzero_si128();",
          "    for (i = 0; i < N; i+=4) {",
          "        __m128i v0 = _mm_load_si128(vbuf+i+0);",
          "        __m128i v1 = _mm_load_si128(vbuf+i+1);",
          "        __m128i v2 = _mm_load_si128(vbuf+i+2);",
          "        __m128i v3 = _mm_load_si128(vbuf+i+3);",
          "        ",
          "        count0 = _mm_sub_epi16(v0, _mm_and_si128(B0, _mm_srli_epi16(v0,1)));",
          "        count1 = _mm_sub_epi16(v1, _mm_and_si128(B0, _mm_srli_epi16(v1,1)));",
          "        count2 = _mm_sub_epi16(v2, _mm_and_si128(B0, _mm_srli_epi16(v2,1)));",
          "        count3 = _mm_sub_epi16(v3, _mm_and_si128(B0, _mm_srli_epi16(v3,1)));",
          "        ",
          "        count0 = _mm_add_epi16(_mm_and_si128(B1,count0),",
          "                               _mm_and_si128(B1,_mm_srli_epi16(count0,2)));",
          "        count1 = _mm_add_epi16(_mm_and_si128(B1,count1),",
          "                               _mm_and_si128(B1,_mm_srli_epi16(count1,2)));",
          "        count2 = _mm_add_epi16(_mm_and_si128(B1,count2),",
          "                               _mm_and_si128(B1,_mm_srli_epi16(count2,2)));",
          "        count3 = _mm_add_epi16(_mm_and_si128(B1,count3),",
          "                               _mm_and_si128(B1,_mm_srli_epi16(count3,2)));",
          "        ",
          "        count0 = _mm_and_si128(B2,_mm_add_epi16(count0,",
          "                                                _mm_srli_epi16(count0,4)));",
          "        count1 = _mm_and_si128(B2,_mm_add_epi16(count1,",
          "                                                _mm_srli_epi16(count1,4)));",
          "        count2 = _mm_and_si128(B2,_mm_add_epi16(count2,",
          "                                                _mm_srli_epi16(count2,4)));",
          "        count3 = _mm_and_si128(B2,_mm_add_epi16(count3,",
          "                                                _mm_srli_epi16(count3,4)));",
          "        ",
          "        count0 = _mm_and_si128(B3,_mm_add_epi16(count0,",
          "                                                _mm_srli_epi16(count0,8)));",
          "        count1 = _mm_and_si128(B3,_mm_add_epi16(count1,",
          "                                                _mm_srli_epi16(count1,8)));",
          "        count2 = _mm_and_si128(B3,_mm_add_epi16(count2,",
          "                                                _mm_srli_epi16(count2,8)));",
          "        count3 = _mm_and_si128(B3,_mm_add_epi16(count3,",
          "                                                _mm_srli_epi16(count3,8)));",
          "        ",
          "        total = _mm_add_epi16(total,_mm_add_epi16(_mm_add_epi16(count0,count1),",
          "                                                  _mm_add_epi16(count2,count3)));",
          "        ",
          "    }",
          "    ",
          "    return reduce_16_to_32(total);",
          "}",
          "",
          "",
          "static inline int popcount_sse2_16bit(unsigned* buf,int n) {",
          "    int N = n/4, base = 0;",
          "    uint32_t tmp[4];",
          "    __m128i count32 = _mm_setzero_si128();",
          "    // 2^12 loop iters might overflow 16-bit counter, so",
          "    // cap it at 2^11 iters per chunk",
          "    const int maxiters = 2048;",
          "    while (N > maxiters) {",
          "        count32 = _mm_add_epi32(count32,popcount_sse2_16_helper_1(buf+base,maxiters));",
          "        base += maxiters*4;",
          "        N -= maxiters;",
          "    }",
          "    if (N > 0) count32 = _mm_add_epi32(count32,popcount_sse2_16_helper_1(buf+base, N));",
          "    _mm_store_si128((__m128i*)tmp,count32);",
          "    return tmp[0]+tmp[1]+tmp[2]+tmp[3];",
          "}",
          "//popcount_sse2_16bit(ull2buf(x),4)",
          ""]


sse232 = ["int popcount_sse2_32bit(unsigned* buf, int n) {",
          "    __m128i* vbuf = (__m128i*)buf;",
          "    int N = n/4;",
          "    __m128i total,count0,count1,count2,count3;",
          "    int i;",
          "    unsigned tmp[4];",
          "    unsigned magic[] = {0x55555555, 0x55555555, 0x55555555, 0x55555555,",
          "      0x33333333, 0x33333333, 0x33333333, 0x33333333,",
          "      0x0F0F0F0F, 0x0F0F0F0F, 0x0F0F0F0F, 0x0F0F0F0F,",
          "      0x00FF00FF, 0x00FF00FF, 0x00FF00FF, 0x00FF00FF,",
          "      0x0000FFFF, 0x0000FFFF, 0x0000FFFF, 0x0000FFFF};",
          "    __m128i B0 = _mm_load_si128((__m128i*)(magic));",
          "    __m128i B1 = _mm_load_si128((__m128i*)(magic+4));",
          "    __m128i B2 = _mm_load_si128((__m128i*)(magic+8));",
          "    __m128i B3 = _mm_load_si128((__m128i*)(magic+12));",
          "    __m128i B4 = _mm_load_si128((__m128i*)(magic+16));",
          "    total = _mm_xor_si128(total,total);",
          "    for (i = 0; i < N; i+=4) {",
          "        __m128i v0 = _mm_load_si128(vbuf+i+0);",
          "        __m128i v1 = _mm_load_si128(vbuf+i+1);",
          "        __m128i v2 = _mm_load_si128(vbuf+i+2);",
          "        __m128i v3 = _mm_load_si128(vbuf+i+3);",
          "        ",
          "        count0 = _mm_sub_epi32(v0, _mm_and_si128(B0, _mm_srli_epi32(v0,1)));",
          "        count1 = _mm_sub_epi32(v1, _mm_and_si128(B0, _mm_srli_epi32(v1,1)));",
          "        count2 = _mm_sub_epi32(v2, _mm_and_si128(B0, _mm_srli_epi32(v2,1)));",
          "        count3 = _mm_sub_epi32(v3, _mm_and_si128(B0, _mm_srli_epi32(v3,1)));",
          "        ",
          "        count0 = _mm_add_epi32( _mm_and_si128(B1,count0),",
          "                               _mm_and_si128(B1,_mm_srli_epi32(count0,2)));",
          "        count1 = _mm_add_epi32( _mm_and_si128(B1,count1),",
          "                               _mm_and_si128(B1,_mm_srli_epi32(count1,2)));",
          "        count2 = _mm_add_epi32( _mm_and_si128(B1,count2),",
          "                               _mm_and_si128(B1,_mm_srli_epi32(count2,2)));",
          "        count3 = _mm_add_epi32( _mm_and_si128(B1,count3),",
          "                               _mm_and_si128(B1,_mm_srli_epi32(count3,2)));",
          "        ",
          "        count0 = _mm_and_si128(B2,_mm_add_epi32(count0,",
          "                                                _mm_srli_epi32(count0,4)));",
          "        count1 = _mm_and_si128(B2,_mm_add_epi32(count1,",
          "                                                _mm_srli_epi32(count1,4)));",
          "        count2 = _mm_and_si128(B2,_mm_add_epi32(count2,",
          "                                                _mm_srli_epi32(count2,4)));",
          "        count3 = _mm_and_si128(B2,_mm_add_epi32(count3,",
          "                                                _mm_srli_epi32(count3,4)));",
          "        ",
          "        count0 = _mm_and_si128(B3,_mm_add_epi32(count0,",
          "                                                _mm_srli_epi32(count0,8)));",
          "        count1 = _mm_and_si128(B3,_mm_add_epi32(count1,",
          "                                                _mm_srli_epi32(count1,8)));",
          "        count2 = _mm_and_si128(B3,_mm_add_epi32(count2,",
          "                                                _mm_srli_epi32(count2,8)));",
          "        count3 = _mm_and_si128(B3,_mm_add_epi32(count3,",
          "                                                _mm_srli_epi32(count3,8)));",
          "        ",
          "        count0 = _mm_and_si128(B4,_mm_add_epi32(count0,",
          "                                                _mm_srli_epi32(count0,16)));",
          "        count1 = _mm_and_si128(B4,_mm_add_epi32(count1,",
          "                                                _mm_srli_epi32(count1,16)));",
          "        count2 = _mm_and_si128(B4,_mm_add_epi32(count2,",
          "                                                _mm_srli_epi32(count2,16)));",
          "        count3 = _mm_and_si128(B4,_mm_add_epi32(count3,",
          "                                                _mm_srli_epi32(count3,16)));",
          "        ",
          "        total = _mm_add_epi32(total,_mm_add_epi32(_mm_add_epi32(count0,count1),",
          "                                                  _mm_add_epi32(count2,count3)));",
          "    }",
          "    _mm_store_si128((__m128i*)tmp,total);",
          "    return tmp[0]+tmp[1]+tmp[2]+tmp[3];",
          "}"]

sse2e =   ["#endif"]

ssse3 =  ["#if !(defined(__GNUC__) && defined(__SSSE3__))",
          "#error gcc required.",
          "#endif",
          "#if defined(__GNUC__) && defined(__SSSE3__)",
          "#include <tmmintrin.h>",
          "",
          "__m128i popcount_ssse3_helper_1(unsigned* buf, int N) {",
          "    __m128i* vbuf = (__m128i*)buf;",
          "    __m128i total = _mm_setzero_si128();",
          "    // LUT of count of set bits in each possible 4-bit nibble, from low-to-high:",
          "    // 0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4",
          "    const unsigned _LUT[] = {0x02010100, 0x03020201, 0x03020201, 0x04030302};",
          "    const __m128i LUT = _mm_load_si128((__m128i*)_LUT);",
          "    const __m128i mask = _mm_set1_epi32(0x0F0F0F0F);",
          "    ",
          "    for (int i = 0; i < N; i+=4) {",
          "        __m128i v0 = _mm_load_si128(vbuf+i+0);",
          "        __m128i v1 = _mm_load_si128(vbuf+i+1);",
          "        __m128i v2 = _mm_load_si128(vbuf+i+2);",
          "        __m128i v3 = _mm_load_si128(vbuf+i+3);",
          "        ",
          "        // Split each byte into low and high nibbles",
          "        __m128i v0_lo = _mm_and_si128(mask,v0);",
          "        __m128i v1_lo = _mm_and_si128(mask,v1);",
          "        __m128i v2_lo = _mm_and_si128(mask,v2);",
          "        __m128i v3_lo = _mm_and_si128(mask,v3);",
          "        ",
          "        __m128i v0_hi = _mm_and_si128(mask,_mm_srli_epi16(v0,4));",
          "        __m128i v1_hi = _mm_and_si128(mask,_mm_srli_epi16(v1,4));",
          "        __m128i v2_hi = _mm_and_si128(mask,_mm_srli_epi16(v2,4));",
          "        __m128i v3_hi = _mm_and_si128(mask,_mm_srli_epi16(v3,4));",
          "        ",
          "        // Compute POPCNT of each byte in two halves using PSHUFB instruction for LUT",
          "        __m128i count0 = _mm_add_epi8(_mm_shuffle_epi8(LUT,v0_lo),_mm_shuffle_epi8(LUT,v0_hi));",
          "        __m128i count1 = _mm_add_epi8(_mm_shuffle_epi8(LUT,v1_lo),_mm_shuffle_epi8(LUT,v1_hi));",
          "        __m128i count2 = _mm_add_epi8(_mm_shuffle_epi8(LUT,v2_lo),_mm_shuffle_epi8(LUT,v2_hi));",
          "        __m128i count3 = _mm_add_epi8(_mm_shuffle_epi8(LUT,v3_lo),_mm_shuffle_epi8(LUT,v3_hi));",
          "        ",
          "        total = _mm_add_epi8(total,_mm_add_epi8(_mm_add_epi8(count0,count1),",
          "                                                _mm_add_epi8(count2,count3)));",
          "        ",
          "    }",
          "    // Reduce 16*8b->{-,-,-,16b,-,-,-,16b}",
          "    const __m128i ZERO = _mm_setzero_si128();",
          "    return _mm_sad_epu8(total,ZERO);",
          "}",
          "",
          "",
          "inline int popcount_ssse3(unsigned* buf,int n) {",
          "    int N = n/4;",
          "    __m128i count32 = _mm_setzero_si128();",
          "    // 2^5 loop iters might overflow 8-bit counter, so",
          "    // cap it at 2^4 iters per chunk",
          "    const int inner_maxits = 16;",
          "    while (N > inner_maxits) {",
          "        count32 = _mm_add_epi32(count32,popcount_ssse3_helper_1(buf,inner_maxits));",
          "        buf += inner_maxits*4;",
          "        N -= inner_maxits;",
          "    }",
          "    if (N > 0) count32 = _mm_add_epi32(count32,popcount_ssse3_helper_1(buf,N));",
          "    ",
          "    // Layout coming from PSADBW accumulation is 2*{0,32}: 0 S1 0 S0",
          "    int count;",
          "    _mm_store_ss((float*)&count,(__m128)(_mm_add_epi32(count32,_mm_shuffle_epi32(count32,_MM_SHUFFLE(2,2,2,2)))));",
          "    return count;",
          "}",
          "#endif"]











