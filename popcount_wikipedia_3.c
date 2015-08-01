#include <stdio.h>
#import <stdint.h>
const uint64_t m1  = UINT64_C(0x5555555555555555); // binary: 0101...
const uint64_t m2  = UINT64_C(0x3333333333333333); // binary: 00110011..
const uint64_t m4  = UINT64_C(0x0f0f0f0f0f0f0f0f); // binary:  4 zeros,  4 ones ...
const uint64_t m8  = UINT64_C(0x00ff00ff00ff00ff); // binary:  8 zeros,  8 ones ...
const uint64_t m16 = UINT64_C(0x0000ffff0000ffff); // binary: 16 zeros, 16 ones ...
const uint64_t m32 = UINT64_C(0x00000000ffffffff); // binary: 32 zeros, 32 ones
const uint64_t hff = UINT64_C(0xffffffffffffffff); // binary: all ones
const uint64_t h01 = UINT64_C(0x0101010101010101); // the sum of 256 to the power of 0,1,2,3...
static inline int popcount_wikipedia_3(uint64_t *buf, int n) {
    int cnt=0;
    uint64_t x;
    do {
        x = *buf;
        x -= (x >> 1) & m1;             //put count of each 2 bits into those 2 bits
        x = (x & m2) + ((x >> 2) & m2); //put count of each 4 bits into those 4 bits
        x = (x + (x >> 4)) & m4;        //put count of each 8 bits into those 8 bits
        cnt += (x * h01)>>56;  //returns left 8 bits of x + (x<<8) + (x<<16) + (x<<24)+...
        buf++;
    } while (--n);
    return cnt;
}
int counter(unsigned long long x){
    return popcount_wikipedia_3(&x, 1);
}
int main(){
    printf("%d\n", counter(18446744073709551615LLU));
    int y=0;
    for (unsigned long long i = 0; i < 10000000000; i++) {
    y += counter(i);
}
printf("%d\n", y);
}