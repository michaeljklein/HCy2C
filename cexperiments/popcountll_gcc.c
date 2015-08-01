#include <stdio.h>
#import <stdint.h>
static inline int popcountll_gcc(uint64_t *buf, int n) {
    int cnt = 0;
    int i;
    for (i = 0; i < n - n % 4; i += 4) {
        cnt += (__builtin_popcountll(buf[i+0]) + __builtin_popcountll(buf[i+1])) +
        (__builtin_popcountll(buf[i+2]) + __builtin_popcountll(buf[i+3]));
    }
    for (; i < n; i++) {
        cnt += __builtin_popcountll(buf[i]);
    }
    return cnt;
}
int counter(unsigned long long x){
    return popcountll_gcc(&x, 1);
}
int main(){
    printf("%d\n", counter(18446744073709551615LLU));
    int y;
    for (unsigned long long i = 0; i < 100000000; i++) {
        y = counter(i);
    }
    printf("%d\n", y);
}

"int main(){\n    printf(\"%d\\n\", counter(18446744073709551615LLU));\n    int y;\n    for (unsigned long long i = 0; i < 100000000; i++) {\n    y = counter(i);\n}\nprintf(\"%d\\n\", y);\n}"