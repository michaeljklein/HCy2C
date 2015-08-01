#include <stdio.h>
#include <stdint.h>


int popcount_jelinek3(uint64_t * buf, int n)
{
    int cnt = 0;
    uint64_t i;
    do {
        i = *buf;
        i = i - ((i >> 1) & 0x5555555555555555);
        i = (i & 0x3333333333333333) + ((i >> 2) & 0x3333333333333333);
        i = (i + (i >> 4)) & 0xF0F0F0F0F0F0F0F;
        cnt += ((((unsigned int) i) + (unsigned int) (i >> 32)) * 0x1010101) >> 24;
        buf++;
    } while (--n);
    return cnt;
}
int counter(unsigned long long x){
    return popcount_jelinek3(&x, 1);
}
int main(){
    printf("%d\n", counter(18446744073709551615LLU));
    int y=0;
    for (unsigned long long i = 0; i < 10000000000; i++) {
    y += counter(i);
}
printf("%d\n", y);
}