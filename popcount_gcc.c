#include <stdio.h>
static inline int popcount_gcc(unsigned *buf, int n) {
    int cnt = 0;
    int i;
    for (i = 0; i < n - n % 4; i += 4) {
        cnt += (__builtin_popcount(buf[i+0]) + __builtin_popcount(buf[i+1])) +
        (__builtin_popcount(buf[i+2]) + __builtin_popcount(buf[i+3]));
    }
    for (; i < n; i++) {
        cnt += __builtin_popcount(buf[i]);
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
    return popcount_gcc(ull2buf(x), 4);
}
int main(){
    printf("%d\n", counter(18446744073709551615LLU));
}