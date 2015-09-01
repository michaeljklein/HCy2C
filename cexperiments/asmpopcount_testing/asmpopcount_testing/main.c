//
//  main.c
//  asmpopcount_testing
//
//  Created by Michael Klein on 8/31/15.
//  Copyright (c) 2015 Michael Klein. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

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

#define buflen 7

int counter2 (uint64_t* buf){
    uint64_t cnt[buflen];
    for (int i = 0; i < (buflen); i++) {
        cnt[i] = 0;
    }
    __asm__(
            "popcnt %4, %4  \n\t"
            "add %4, %0     \n\t"
            "popcnt %5, %5  \n\t"
            "add %5, %1     \n\t"
            "popcnt %6, %6  \n\t"
            "add %6, %2     \n\t"
            "popcnt %7, %7  \n\t"
            "add %7, %3     \n\t" // +r means input/output, r means intput
            : "+r" (cnt[0]), "+r" (cnt[1]), "+r" (cnt[2]), "+r" (cnt[3])
            : "r"  (buf[0]), "r"  (buf[1]), "r"  (buf[2]), "r"  (buf[3]));
    __asm__(
            "popcnt %2, %2  \n\t"
            "add %2, %0     \n\t"
            "popcnt %3, %3  \n\t"
            "add %3, %1     \n\t"
            : "+r" (cnt[4]), "+r" (cnt[5])
            : "r"  (buf[4]), "r"  (buf[5]));
    __asm__(
            "popcnt %1, %1  \n\t"
            "add %1, %0     \n\t"
            : "+r" (cnt[6])
            : "r"  (buf[6]));
    
    return cnt[0] + cnt[1] + cnt[2] + cnt[3] + cnt[4] + cnt[5] + cnt[6];
}

int counter1 (unsigned long long * buf)
{
    int cnt = 0;
    for (int j = 0; j != (buflen); j++) {
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

int checkeq(unsigned long long * buf){
    return (counter1(buf) == counter2(buf));
}

int main(int argc, const char * argv[]) {
    unsigned long long i = 0;
    for (; i < (1000000000); i++) {
        unsigned long long buf0[buflen];
        unsigned long long * buf = buf0;
        
        for (int j = 0; j < buflen; j++) {
            buf0[j] = 0;
        }
        
        int pos = ((int) random()) % buflen;
        buf0[pos] = i;
        
        if (counter1(buf) != counter2(buf)) {
            printf("%llu, ", i);
        }
    }
    
    printf("Done %llu.\n", i);
    return 0;
}

















