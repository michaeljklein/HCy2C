#include <stdio.h>
static inline int popcount_wegner(unsigned *buf, int n) {
    int cnt=0;
    unsigned v;
    while (n--) {
        v = *buf;
        while (v) {
            cnt++;
            v &= v-1;  /*  clear the least significant bit set */
        }
        buf++;
    }
    return cnt;
}
unsigned * ull2buf(unsigned long long x){ //takes ~1.1476 picoseconds on 64bit 2.5GHZ Macbook Pro, gcc O3
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

int counter(unsigned long long x) {
    return popcount_wegner(ull2buf(x), 4);
}
int main(){
    printf("%d\n", counter(18446744073709551615LLU));
    int y;
    for (unsigned long long i = 0; i < 1000000000; i++) {
    y = counter(i);
}
printf("%d\n", y);
}