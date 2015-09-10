#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_15_976_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 14;
static uint_fast32_t endhere = 0;
char str[25] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[15][2] = {{1125899906842623LLU,4611686018427125760LLU},{18445618173836263423LLU,4611686018427387903LLU},{18446744073675997184LLU,4611686018427387903LLU},{6915277227827396096LLU,4611686018360499701LLU},{18446744056563237375LLU,4611686001314627583LLU},{18445618190982577665LLU,4611686018360541183LLU},{18159067817058500607LLU,4611683836545990655LLU},{288230376134671359LLU,4611406732743147516LLU},{18446743867551115263LLU,4539909898961682435LLU},{18433233273887793151LLU,4358921368545066959LLU},{18176524781392887783LLU,3746979618142289919LLU},{4610564515761651231LLU,4395249250380808188LLU},{4611633173149775807LLU,3382449610616732675LLU},{18392700738593091583LLU,1950058361356289023LLU},{18230569079656151023LLU,2878915603417005119LLU}};

static uint_fast64_t D[15][2] = {{18446278396228680705LLU,4611686018427387903LLU},{6532471259481228286LLU,4611686018427279781LLU},{11914738491709194239LLU,4611686018427233882LLU},{17681132119910252543LLU,4611686001314494303LLU},{1148883582513577983LLU,4611686018360478960LLU},{17298326168710398975LLU,4611686001314427663LLU},{18446567602026176827LLU,4582023393263484927LLU},{18446743809429585917LLU,4569463930105364479LLU},{18445883145610362567LLU,4611513144882233343LLU},{14987975436720406499LLU,3735720497738927359LLU},{4611421929478291263LLU,4340520062711775168LLU},{18176528089617000447LLU,3730105559890772031LLU},{18391855349979217655LLU,2017467013235998719LLU},{4611617839822897039LLU,3386644204657573887LLU},{18445688404570996351LLU,2107473450605756412LLU}};

uint_fast8_t X[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[15][2] = {{18446278396228680705LLU,4611686018427387903LLU},{18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,4611686018427387903LLU}};

#if UINTPTR_MAX == 0xffffffffffffffff // 64-bit. Hopefully this means the cpu has 'popcnt'.
int counter (uint64_t * buf){
    uint64_t cnt[15];
    cnt[0] = 0;
    cnt[1] = 0;
    cnt[2] = 0;
    cnt[3] = 0;
    cnt[4] = 0;
    cnt[5] = 0;
    cnt[6] = 0;
    cnt[7] = 0;
    cnt[8] = 0;
    cnt[9] = 0;
    cnt[10] = 0;
    cnt[11] = 0;
    cnt[12] = 0;
    cnt[13] = 0;
    cnt[14] = 0;

    __asm__(
            "popcnt %4, %4 \n\t"
            "add %4, %0    \n\t"
            "popcnt %5, %5 \n\t"
            "add %5, %1    \n\t"
            "popcnt %6, %6 \n\t"
            "add %6, %2    \n\t"
            "popcnt %7, %7 \n\t"
            "add %7, %3    \n\t"
            : "+r" (cnt[0]), "+r" (cnt[1]), "+r" (cnt[2]), "+r" (cnt[3])
            : "r" (buf[0]), "r" (buf[1]), "r" (buf[2]), "r" (buf[3]));
    __asm__(
            "popcnt %4, %4 \n\t"
            "add %4, %0    \n\t"
            "popcnt %5, %5 \n\t"
            "add %5, %1    \n\t"
            "popcnt %6, %6 \n\t"
            "add %6, %2    \n\t"
            "popcnt %7, %7 \n\t"
            "add %7, %3    \n\t"
            : "+r" (cnt[4]), "+r" (cnt[5]), "+r" (cnt[6]), "+r" (cnt[7])
            : "r" (buf[4]), "r" (buf[5]), "r" (buf[6]), "r" (buf[7]));
    __asm__(
            "popcnt %4, %4 \n\t"
            "add %4, %0    \n\t"
            "popcnt %5, %5 \n\t"
            "add %5, %1    \n\t"
            "popcnt %6, %6 \n\t"
            "add %6, %2    \n\t"
            "popcnt %7, %7 \n\t"
            "add %7, %3    \n\t"
            : "+r" (cnt[8]), "+r" (cnt[9]), "+r" (cnt[10]), "+r" (cnt[11])
            : "r" (buf[8]), "r" (buf[9]), "r" (buf[10]), "r" (buf[11]));
    __asm__(
            "popcnt %2, %2  \n\t"
            "add %2, %0     \n\t"
            "popcnt %3, %3  \n\t"
            "add %3, %1     \n\t"
            : "+r" (cnt[12]), "+r" (cnt[13])
            : "r" (buf[12]), "r" (buf[13]));
    __asm__(
           "popcnt %1, %1  \n\t"
           "add %1, %0     \n\t"
            : "+r" (cnt[14])
            : "r" (buf[14]));


    return cnt[0] + cnt[1] + cnt[2] + cnt[3] + cnt[4] + cnt[5] + cnt[6] + cnt[7] + cnt[8] + cnt[9] + cnt[10] + cnt[11] + cnt[12] + cnt[13] + cnt[14];
}

#elif UINTPTR_MAX == 0xffffffff // 32-bit
int counter (unsigned long long i)
{
  unsigned int i1 = i, i2 = i >> 32;
  i1 = i1 - ((i1 >> 1) & 0x55555555);
  i2 = i2 - ((i2 >> 1) & 0x55555555);
  i1 = (i1 & 0x33333333) + ((i1 >> 2) & 0x33333333);
  i2 = (i2 & 0x33333333) + ((i2 >> 2) & 0x33333333);
  i1 = (i1 + (i1 >> 4)) & 0xF0F0F0F;
  i2 = (i2 + (i2 >> 4)) & 0xF0F0F0F;
  return ((i1 + i2) * 0x1010101) >> 24;
}

#else
#error "this cpu doesn't seem to be 32-bit or 64-bit. I don't know how to deal with this."
#endif
void f(uint_fast8_t i, uint_fast8_t y0){
    if(y0){
        A[i][0] = A[i-1][0] & C[i][0];
        A[i][1] = A[i-1][1] & C[i][1];

    } else {
        A[i][0] = A[i-1][0] & D[i][0];
        A[i][1] = A[i-1][1] & D[i][1];

    }
}

void printout(){
    sprintf(str, "[               ,%5d]\n", this);
    str[1] = X[0] ^ 48;
    str[2] = X[1] ^ 48;
    str[3] = X[2] ^ 48;
    str[4] = X[3] ^ 48;
    str[5] = X[4] ^ 48;
    str[6] = X[5] ^ 48;
    str[7] = X[6] ^ 48;
    str[8] = X[7] ^ 48;
    str[9] = X[8] ^ 48;
    str[10] = X[9] ^ 48;
    str[11] = X[10] ^ 48;
    str[12] = X[11] ^ 48;
    str[13] = X[12] ^ 48;
    str[14] = X[13] ^ 48;
    str[15] = X[14] ^ 48;

}


void checkifbest(){
    uint_fast64_t * thisbuf = A[maxpos];
    this = counter(thisbuf);

    if(this == best){
        printout();
        fwrite(str, 1, sizeof(str), fout);
    }

    if(this > best){
        printout();
        fwrite(str, 1, sizeof(str), fout);
        best = this;
    }

}

int r(){
    goto startnocarry;
    
    startnocarry:
        if(i == maxpos){
            if(X[i]){
                X[i] = 0;
                i--;
                goto startcarry;
            }else{
                f(i, 0);
                checkifbest();
                X[i] = 1;
                f(i, 1);
                checkifbest();
                X[i] = 0;
                i--;
                goto startcarry;
            }
        }else{
            f(i, X[i]);
            i++;
            goto startnocarry;
        }
        
    startcarry:
        if(X[i] && (i != endhere)){
            X[i] = 0;
            i--;
            goto startcarry;
        }else{
            if(i == endhere){
                goto end;
            }else{
                X[i] = 1;
                f(i, 1);
                i++;
                goto startnocarry;
            }
        }

    end:
        return 0;
}
int main(){
fout = fopener;
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,4],[3,5],[3,6],[4,5],[4,7],[5,8],[6,7],[6,8],[7,8]]\n", fout);
    if(endhere){
        uint_fast8_t bitpos = 0;
        uint_fast8_t thisbit;
        while(starthere){
            thisbit = starthere & 1;
            X[bitpos] = thisbit;
            f(bitpos, thisbit);
            bitpos++;
            starthere >>= 1;
        }
        i = endhere;
        r();
    }else{
        i = 0;
        r();
    }
    fwrite("FINISHED.", 1, 9, fout);
    fclose(fout);
    return 0;
}

