//
//  pack.c
//  popcount_profile
//
//  Created by Michael Klein on 7/29/15.
//  Copyright (c) 2015 Michael Klein. All rights reserved.
//

#include <stdio.h>

unsigned * ull2buf(unsigned long long x){ //takes ~1.1476 picoseconds on 64bit 2.5GHZ Macbook Pro
    unsigned * buf;
    unsigned y[8];
    unsigned long long z = x;
    y[0] = z & 65535; //16 ones
    z >>= 16;
    y[1] = z & 65535;
    z >>= 16;
    y[2] = z & 65535;
    z >>= 16;
    y[3] = z & 65535;
    
    buf = y;
    return buf;
}

int main(){
    unsigned * buf0 = NULL;
    unsigned long long int i = 0;
    while (i ^ 4294967295000LLU) {
        buf0 = ull2buf(i++);
    }
    printf("%d\n", buf0[0]);
}
