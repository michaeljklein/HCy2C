#include <stdio.h>
unsigned char *lut;

void init_lut(void)
{
    unsigned char lut[65536];
    
    for (int i = 0; i < 65536; i++) {
        int bit_count = 0;
        // count bits using Wegner/Kernigan
        for (int j = i; j != 0; j &= j - 1)
            bit_count++;
        lut[i] = bit_count;
    }
}


static inline int popcount_lut8(unsigned *buf, int n)
{
  int cnt=0;
  unsigned int i;
  do {
    i = *buf;
    cnt += lut[i&255];
    cnt += lut[i>>8&255];
    cnt += lut[i>>16&255];
    cnt += lut[i>>24];  /* APD: removed the unneeded &255 */
    buf++;
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
    return popcount_lut8(ull2buf(x), 4);
}
int main(){
    printf("%d\n", counter(18446744073709551615LLU));
}