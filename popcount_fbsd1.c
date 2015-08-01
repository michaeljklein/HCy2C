#include <stdio.h>
static inline int popcount_fbsd1(unsigned *buf, int n)
{
    int cnt=0;
    do {
        unsigned m = *buf++;
        m = (m & 0x55555555) + ((m & 0xaaaaaaaa) >> 1);
        m = (m & 0x33333333) + ((m & 0xcccccccc) >> 2);
        m = (m & 0x0f0f0f0f) + ((m & 0xf0f0f0f0) >> 4);
        m = (m & 0x00ff00ff) + ((m & 0xff00ff00) >> 8);
        m = (m & 0x0000ffff) + ((m & 0xffff0000) >> 16);
        cnt += m;
    } while(--n);
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
    return popcount_fbsd1(ull2buf(x), 4);
}
int main(){
    printf("%d\n", counter(18446744073709551615LLU));
}