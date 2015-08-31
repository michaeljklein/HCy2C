#include <stdio.h>
#include <stdint.h>


int popcount_jelinek2(uint64_t * buf, int n)
{
    int cnt = 0;
    uint64_t i;
    do {
        i = *buf;
        unsigned int i1 = i, i2 = i >> 32;
        i1 = i1 - ((i1 >> 1) & 0x55555555);
        i2 = i2 - ((i2 >> 1) & 0x55555555);
        i1 = (i1 & 0x33333333) + ((i1 >> 2) & 0x33333333);
        i2 = (i2 & 0x33333333) + ((i2 >> 2) & 0x33333333);
        i1 = (i1 + (i1 >> 4)) & 0xF0F0F0F;
        i2 = (i2 + (i2 >> 4)) & 0xF0F0F0F;
        cnt += ((i1 + i2) * 0x1010101) >> 24;
        buf++;
    } while (--n);
    return cnt;
}
int counter(unsigned long long x){
    return popcount_jelinek2(&x, 1);
}
int main(){
    printf("%d\n", counter(18446744073709551615LLU));
    int y=0;
    for (unsigned long long i = 0; i < 10000000000; i++) {
    y += counter(i);
}
printf("%d\n", y);
}