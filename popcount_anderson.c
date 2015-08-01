#include <stdio.h>
static inline int popcount_anderson(unsigned *buf, int n) {
    int cnt=0;
    uint64_t v;
    while (n--) {
        v = *buf;
        cnt += ((v & 0xfff) * 0x1001001001001ULL & 0x84210842108421ULL) % 0x1f;
        cnt += (((v & 0xfff000) >> 12) * 0x1001001001001ULL & 0x84210842108421ULL) % 0x1f;
        cnt += ((v >> 24) * 0x1001001001001ULL & 0x84210842108421ULL) % 0x1f;
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
    return popcount_anderson(ull2buf(x), 4);
}
int main(){
    printf("%d\n", counter(18446744073709551615LLU));
}