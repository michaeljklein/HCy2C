//
//  main.c
//  new_sprinter_testing
//
//  Created by Michael Klein on 8/30/15.
//  Copyright (c) 2015 Michael Klein. All rights reserved.
//

#include <stdio.h>
#include <stdint.h>

//uint_fast64_t practically tripled the overall speed...

//static unsigned long long int ONES = 18446744073709551615LLU;
uint_fast64_t y; //unsigned long long int y;
uint_fast32_t best = 1; //unsigned int best = 1;
uint_fast32_t i; //unsigned int i;
uint_fast32_t this; //unsigned int this;
static uint_fast32_t maxpos = 14; //static int maxpos = 14;
static uint_fast32_t endhere = 1; //static unsigned int endhere = 1; // *
uint_fast32_t starthere = 2; //unsigned int starthere = 2; // *
char str[25] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
FILE * fout;

//static unsigned long long int C[15][6] = 
static uint_fast64_t C[15][6] = {{0,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,0,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,0,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,0,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,0,1152921504606846975LLU},{18446744073709486080LLU,18446744073709551615LLU,16137488128863633345LLU,16137488128863633345LLU,16137488128863633345LLU,1152921504606814208LLU},{18446744069414649855LLU,16137488128863633345LLU,18446744073709551615LLU,18361175680251852863LLU,18361175680251852863LLU,1152921503533137919LLU},{18446462603027808255LLU,18361175680251852863LLU,18361175680251852863LLU,18446744073709551615LLU,18446742768019507199LLU,1152886321308499967LLU},{281474976710655LLU,18446742768019507199LLU,18446742768019507199LLU,18446742768019507199LLU,18446744073709551615LLU,35184372088831LLU},{16137488128863633345LLU,18446744069414649855LLU,18446744073709551615LLU,18012146709538267123LLU,18012146709538267123LLU,1008590805809496032LLU},{18361175680251852863LLU,18446462603027808255LLU,18012146709538267123LLU,18446744073709551615LLU,18446737438119296719LLU,1147573479914929183LLU},{18446742768019507199LLU,281474976710655LLU,18446737438119296719LLU,18446737438119296719LLU,18446744073709551615LLU,1152921341393077247LLU},{18012146709538267123LLU,18012146709538267123LLU,18446462603027808255LLU,18446744073709551615LLU,18446471394724674039LLU,1125759169321758713LLU},{18446737438119296719LLU,18446737438119296719LLU,281474976710655LLU,18446471394724674039LLU,18446744073709551615LLU,1152920674637971303LLU},{18446471394724674039LLU,18446471394724674039LLU,18446471394724674039LLU,281474976710655LLU,18446744073709551615LLU,1152887419721088251LLU}};

//static unsigned long long int D[15][6] =
static uint_fast64_t D[15][6] = {{18446744073709551615LLU,7745465120565624830LLU,7745465120565624830LLU,7745465120565624830LLU,7745465120565624830LLU,1152921504606846975LLU},{7745465120565624830LLU,18446744073709551615LLU,11500961565784304509LLU,11500961565784304509LLU,11500961565784304509LLU,1152921504606846975LLU},{11500961565784304509LLU,11500961565784304509LLU,18446744073709551615LLU,17647355133939130267LLU,17647355133939130267LLU,1152921504606846975LLU},{17647355133939130267LLU,17647355133939130267LLU,17647355133939130267LLU,18446744073709551615LLU,18446450400839595239LLU,1152921504606846975LLU},{18446450400839595239LLU,18446450400839595239LLU,18446450400839595239LLU,18446450400839595239LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709486080LLU,9115143259038023679LLU,9115143259038023679LLU,9115143259038023679LLU,484081364189020159LLU},{18446744073709551615LLU,9115143259038023679LLU,18446744073709486080LLU,14699748915276677119LLU,14699748915276677119LLU,718803473948194238LLU},{18446744073709551615LLU,14699748915276677119LLU,14699748915276677119LLU,18446744073709486080LLU,18429235449676431359LLU,1102959695836401613LLU},{18446744073709551615LLU,18429235449676431359LLU,18429235449676431359LLU,18429235449676431359LLU,18446744073709486080LLU,1152919979846924915LLU},{9115143259038023679LLU,18446744073709551615LLU,18446744069414649855LLU,4602670297957498495LLU,4602670297957498495LLU,569687554516877311LLU},{14699748915276677119LLU,18446744073709551615LLU,4602670297957498495LLU,18446744069414649855LLU,17888086476244110335LLU,918734290154422271LLU},{18429235449676431359LLU,18446744073709551615LLU,17888086476244110335LLU,17888086476244110335LLU,18446744069414649855LLU,1151823642028408831LLU},{4602670297957498495LLU,4602670297957498495LLU,18446744073709551615LLU,18446462603027808255LLU,576460749080051679LLU,287666361046384447LLU},{17888086476244110335LLU,17888086476244110335LLU,18446744073709551615LLU,576460749080051679LLU,18446462603027808255LLU,1117992202035783167LLU},{576460749080051679LLU,576460749080051679LLU,576460749080051679LLU,18446744073709551615LLU,281474976710655LLU,36028796213108719LLU}};

//unsigned int X[15] =
uint_fast8_t X[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

//unsigned long long int A[15][6] =
uint_fast64_t A[15][6] = {{18446744073709551615LLU,7745465120565624830LLU,7745465120565624830LLU,7745465120565624830LLU,7745465120565624830LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU}};


#if (defined(__gnuc__) && defined(popcnt))
//uint32_t

// WAIT!!! Not only will this work with 64bit uints, it can also be ~easily extended to work with N of them in haskell

int counter (uint64_t* buf){ //worked for 6 inputs
    uint64_t cnt[6];
    for (int i = 0; i < (6); i++) {
        cnt[i] = 0;
    }
    
    __asm__(
        "popcnt %6, %6   \n\t"
        "add %6, %0      \n\t"
        "popcnt %7, %7   \n\t"
        "add %7, %1      \n\t"
        "popcnt %8, %8   \n\t"
        "add %8, %2      \n\t"
        "popcnt %9, %9   \n\t"
        "add %9, %3      \n\t"
        "popcnt %10, %10 \n\t"
        "add %10, %4     \n\t"
        "popcnt %11, %11 \n\t"
        "add %10, %5     \n\t"// +r means input/output, r means intput
        : "+r" (cnt[0]), "+r" (cnt[1]), "+r" (cnt[2]), "+r" (cnt[3]), "+r" (cnt[4]), "+r" (cnt[5])
        : "r"  (buf[0]), "r"  (buf[1]), "r"  (buf[2]), "r"  (buf[3]), "r"  (buf[4]), "r"  (buf[5]));
    
    return cnt[0] + cnt[1] + cnt[2] + cnt[3] + cnt[4] + cnt[5];
}

//int counter (unsigned long long i) {
//    unsigned int i1 = i, i2 = i >> 32;
//    uint64_t cnt[2];
//    cnt[0] = 0; cnt[1] = 0;
//    
//    {
//        __asm__(
//                "popcnt %2, %2  \n\t"
//                "add %2, %0     \n\t"
//                "popcnt %3, %3  \n\t"
//                "add %3, %1     \n\t"
//                : "+r" (cnt[0]), "+r" (cnt[1])
//                : "r"  (i1), "r"  (i2));
//    }
//    return cnt[0] + cnt[1];
//}
//
//int counter2 (unsigned long long i, unsigned long long j) {
//    unsigned int i1 = i, i2 = i >> 32;
//    unsigned int j1 = j, j2 = j >> 32;
//    uint64_t cnt[4];
//    cnt[0] = 0; cnt[1] = 0; cnt[2] = 0; cnt[3] = 0;
//    {
//        __asm__(
//                "popcnt %4, %4  \n\t"
//                "add %4, %0     \n\t"
//                "popcnt %5, %5  \n\t"
//                "add %5, %1     \n\t"
//                "popcnt %6, %6  \n\t"
//                "add %6, %2     \n\t"
//                "popcnt %7, %7  \n\t"
//                "add %7, %3     \n\t" // +r means input/output, r means intput
//                : "+r" (cnt[0]), "+r" (cnt[1]), "+r" (cnt[2]), "+r" (cnt[3])
//                : "r"  (i1), "r"  (i2), "r"  (j1), "r"  (j2));
//    }
//    return cnt[0] + cnt[1] + cnt[2] + cnt[3];
//}

// retreived and modified from http://danluu.com/assembly-intrinsics/
//uint32_t builtin_popcnt_unrolled_errata_manual(const uint64_t* buf, int len) {
//    assert(len % 4 == 0);
//    uint64_t cnt[4];
//    for (int i = 0; i < 4; ++i) {
//        cnt[i] = 0;
//    }
//    
//    for (int i = 0; i < len; i+=4) {
//        __asm__(
//                "popcnt %4, %4  \n\t"
//                "add %4, %0     \n\t"
//                "popcnt %5, %5  \n\t"
//                "add %5, %1     \n\t"
//                "popcnt %6, %6  \n\t"
//                "add %6, %2     \n\t"
//                "popcnt %7, %7  \n\t"
//                "add %7, %3     \n\t" // +r means input/output, r means intput
//                : "+r" (cnt[0]), "+r" (cnt[1]), "+r" (cnt[2]), "+r" (cnt[3])
//                : "r"  (buf[i]), "r"  (buf[i+1]), "r"  (buf[i+2]), "r"  (buf[i+3]));
//    }
//    return cnt[0] + cnt[1] + cnt[2] + cnt[3];
//}

#else
int counter (unsigned long long * buf)
{
    int cnt = 0;
    for (int j = 0; j != (6); j++) {
        unsigned long long i = buf[j];
        unsigned int i1 = i, i2 = i >> 32;
        i1 = i1 - ((i1 >> 1) & 0x55555555);
        i2 = i2 - ((i2 >> 1) & 0x55555555);
        i1 = (i1 & 0x33333333) + ((i1 >> 2) & 0x33333333);
        i2 = (i2 & 0x33333333) + ((i2 >> 2) & 0x33333333);
        i1 = (i1 + (i1 >> 4)) & 0xF0F0F0F;
        i2 = (i2 + (i2 >> 4)) & 0xF0F0F0F;
        cnt += ((i1 + i2) * 0x1010101) >> 24;
    }
    return cnt;
}
#endif

//void f(int i, int y0){
void f(uint_fast8_t i, uint_fast8_t y0){
//    printf("[%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d,%5d]\n", X[0],X[1],X[2],X[3],X[4],X[5],X[6],X[7],X[8],X[9],X[10],X[11],X[12],X[13],X[14],this );
    if(y0){
        A[i][0] = A[i-1][0] & C[i][0];
        A[i][1] = A[i-1][1] & C[i][1];
        A[i][2] = A[i-1][2] & C[i][2];
        A[i][3] = A[i-1][3] & C[i][3];
        A[i][4] = A[i-1][4] & C[i][4];
        A[i][5] = A[i-1][5] & C[i][5];

    } else {
        A[i][0] = A[i-1][0] & D[i][0];
        A[i][1] = A[i-1][1] & D[i][1];
        A[i][2] = A[i-1][2] & D[i][2];
        A[i][3] = A[i-1][3] & D[i][3];
        A[i][4] = A[i-1][4] & D[i][4];
        A[i][5] = A[i-1][5] & D[i][5];

    }
}

//static char remainder_mod_100[128] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,
//    17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33,
//    34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
//    50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66,
//    67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82,
//    83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99,
//    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18,
//    19, 20, 21, 22, 23, 24, 25, 26, 27}; // lookup table for remainder modulo 100
//
//static char * two_dig_lookup[100] = {" 0", " 1", " 2", " 3", " 4", " 5", " 6", " 7", " 8", " 9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31", "32", "33", "34", "35", "36", "37", "38", "39", "40", "41", "42", "43", "44", "45", "46", "47", "48", "49", "50", "51", "52", "53", "54", "55", "56", "57", "58", "59", "60", "61", "62", "63", "64", "65", "66", "67", "68", "69", "70", "71", "72", "73", "74", "75", "76", "77", "78", "79", "80", "81", "82", "83", "84", "85", "86", "87", "88", "89", "90", "91", "92", "93", "94", "95", "96", "97", "98", "99"}; //lookup table for pairs of digits base 10
//
//void newer_print(){
//    str[0] = 91; //"[";
//    str[1]  = X[0]  ^ 48;
//    str[2]  = X[1]  ^ 48;
//    str[3]  = X[2]  ^ 48;
//    str[4]  = X[3]  ^ 48;
//    str[5]  = X[4]  ^ 48;
//    str[6]  = X[5]  ^ 48;
//    str[7]  = X[6]  ^ 48;
//    str[8]  = X[7]  ^ 48;
//    str[9]  = X[8]  ^ 48;
//    str[10] = X[9]  ^ 48;
//    str[11] = X[10] ^ 48;
//    str[12] = X[11] ^ 48;
//    str[13] = X[12] ^ 48;
//    str[14] = X[13] ^ 48;
//    str[15] = X[14] ^ 48;
//    str[16] = 44; //",";
//    
//    unsigned int x = this;
//    unsigned char remainder = 0;
//    unsigned int str_pos = 17;
//    while (x) {
//        remainder = remainder_mod_100[x & 127]; // = Mod[x, 100]
//        unsigned int test = (x - (x % 100))/100;
//        x = ( (x - remainder) >> 2) * 3264175145; // integer division x/100
//        
//        if (test != x) {
//            printf("test: %d, x: %d\n", test, x);
//        }
//        
//        str[str_pos]     = two_dig_lookup[remainder][0]; // load first digit into str
//        str[str_pos + 1] = two_dig_lookup[remainder][1]; // load second digit into str
//        str_pos += 2;
//    }
//    str[23] = 93; //"]";
//    str[24] = 10; //"\n";
//
//    fwrite(str, 1, sizeof(str), fout);
//}

void new_print(){
    //str[i+1] = X[i] ^ 48
    //char str[24]; //= "[               ,     ]\n"; // 4 + 5 + 15 = 24 ("[,]\n" + this + X's)
    sprintf(str, "[               ,%5d]\n", this);
    str[1]  = X[0]  ^ 48;
    str[2]  = X[1]  ^ 48;
    str[3]  = X[2]  ^ 48;
    str[4]  = X[3]  ^ 48;
    str[5]  = X[4]  ^ 48;
    str[6]  = X[5]  ^ 48;
    str[7]  = X[6]  ^ 48;
    str[8]  = X[7]  ^ 48;
    str[9]  = X[8]  ^ 48;
    str[10] = X[9]  ^ 48;
    str[11] = X[10] ^ 48;
    str[12] = X[11] ^ 48;
    str[13] = X[12] ^ 48;
    str[14] = X[13] ^ 48;
    str[15] = X[14] ^ 48;
    fwrite(str, 1, sizeof(str), fout);
}

void checkifbest(){
//    this = 0;
//    this += counter(A[maxpos][0]);
//    this += counter(A[maxpos][1]);
//    this += counter(A[maxpos][2]);
//    this += counter(A[maxpos][3]);
//    this += counter(A[maxpos][4]);
//    this += counter(A[maxpos][5]);
    
//    this = counter2(A[maxpos][0], A[maxpos][1]) + counter2(A[maxpos][2], A[maxpos][3]) + counter2(A[maxpos][4], A[maxpos][5]);

//    unsigned long long int thisbuf[6] = {A[maxpos][0], A[maxpos][1], A[maxpos][2], A[maxpos][3], A[maxpos][4], A[maxpos][5]};
    // YAYYY!!! I think I finally used a pointer well!!!!
    unsigned long long int * thisbuf = A[maxpos];
    this = counter(thisbuf);

    if(this == best){
//        sprintf(str, "[%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d,%5d]\n", X[0],X[1],X[2],X[3],X[4],X[5],X[6],X[7],X[8],X[9],X[10],X[11],X[12],X[13],X[14],this );
//        fwrite(str, 1, sizeof(str), fout);
        new_print();
//        newer_print();
    }

    if(this > best){
//        sprintf(str, "[%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d,%5d]\n", X[0],X[1],X[2],X[3],X[4],X[5],X[6],X[7],X[8],X[9],X[10],X[11],X[12],X[13],X[14],this );
//        fwrite(str, 1, sizeof(str), fout);
        new_print();
//        newer_print();
        best = this;
    }

//    if(this < best){
//        ;
//    }
}

int r(){
    goto startnocarry;
    
    startnocarry:
        if(i == maxpos){
            if(X[i]){
                X[i] = 0;
                i--;
                goto startcarry;
            }else{
                f(i, 0);
                checkifbest();
                X[i] = 1;
                f(i, 1);
                checkifbest();
                X[i] = 0;
                i--;
                goto startcarry;
            }
        }else{
            f(i, X[i]);
            i++;
            goto startnocarry;
        }
        
    startcarry:
        if(X[i] && (i != endhere)){ //without the second part, if the setbit is 1 then the whole thing will fail to end until you get all ones..
            X[i] = 0;
            i--;
            goto startcarry;
        }else{
            if(i == endhere){
                goto end;
            }else{
                X[i] = 1;
                f(i, 1);
                i++;
                goto startnocarry;
            }
        }

    end:
        return 0;
}

//int main(int argc, const char * argv[]) {
int main() {
    fout = fopen("runner_1_2_out.txt", "w");
    fputs("[[0,1],[0,2],[0,3],[0,4],[0,5],[1,2],[1,3],[1,4],[1,5],[2,3],[2,4],[2,5],[3,4],[3,5],[4,5]]\n", fout);
    if(endhere){
        // unsigned int bitpos = 0;
        uint_fast8_t bitpos = 0;
        // unsigned int thisbit;
        uint_fast8_t thisbit;
        while(starthere){
            thisbit = starthere & 1;
            X[bitpos] = thisbit;
            f(bitpos, thisbit);
            bitpos++;
            starthere >>= 1;
        }
        i = endhere;
        r();
    }else{
        i = 1;
        r();
    }
    fwrite("FINISHED.", 1, 9, fout);
    fclose(fout);
    return 0;
}

// old printing:
// real	0m0.046s
// user	0m0.005s
// sys	0m0.008s
//
// new printing:
// real	0m0.009s
// user	0m0.003s
// sys	0m0.005s