#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_18_965_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 17;
static uint_fast32_t endhere = 0;
char str[28] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[18][3] = {{18446739676484273100LLU,3776745751548264447LLU,201779494911LLU},{4398046511103LLU,18446744073709535232LLU,274877906943LLU},{18446744073709551615LLU,18445618173802725375LLU,274877906943LLU},{18446744073441116160LLU,1125626102677503LLU,274877906943LLU},{15951595948786843647LLU,18446744073709551575LLU,274877890560LLU},{18446744057603407872LLU,18303753120166969343LLU,274877399039LLU},{17582000168427864063LLU,144114930369363967LLU,274861654015LLU},{18446743799901208320LLU,16268112855801266175LLU,274626002943LLU},{1151865973444165887LLU,18320326611858741247LLU,270851102685LLU},{18446743194264417264LLU,13363230586500546559LLU,261942624255LLU},{18375812160531201807LLU,16703841085801627647LLU,223136776179LLU},{18446739675663040512LLU,18446744073709551615LLU,274877906943LLU},{72057594037731315LLU,18156261897211477952LLU,128276463375LLU},{18446741142226032605LLU,3777394187456987199LLU,201779494911LLU},{6148917622446292019LLU,18446744073709551573LLU,102270762752LLU},{18446739676736782335LLU,18445618448680599807LLU,201779478783LLU},{3746097688219730175LLU,2179742000561717247LLU,270835646463LLU},{18375812379575123763LLU,16994333193409134528LLU,102911278899LLU}};

static uint_fast64_t D[18][3] = {{4398046511103LLU,18446744073172713408LLU,102270762752LLU},{18446742607420303718LLU,18446095637800796159LLU,274877906943LLU},{6148914691510261401LLU,18446744073709551509LLU,274877906943LLU},{14704028482992603135LLU,18446266610358239427LLU,274877890560LLU},{13545402712060854271LLU,1125625455902590LLU,274877906943LLU},{17311770996914520063LLU,18446583544728676815LLU,274861648230LLU},{14974257638668238847LLU,18446425490063218419LLU,274877388441LLU},{70936092177596415LLU,18446269084622930943LLU,270835631052LLU},{18392700620478889983LLU,16285000807598783951LLU,274625723767LLU},{18374690877718134783LLU,18446321861240311807LLU,220912930800LLU},{72056769353872383LLU,13798906039883527167LLU,260376097743LLU},{12297830848488538111LLU,18446266609711464554LLU,274877906943LLU},{18446740555929210831LLU,8569354850326794239LLU,186755502079LLU},{18446744073162063223LLU,18446744073172697087LLU,102270762752LLU},{18446744073709551615LLU,3776268288087015551LLU,201779494911LLU},{3742719988747533363LLU,14670475786049486844LLU,102270763007LLU},{18379189805494829055LLU,18446726755995614403LLU,274626001971LLU},{18446739950289273855LLU,4502491100606350335LLU,198629639167LLU}};

uint_fast8_t X[18] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[18][3] = {{4398046511103LLU,18446744073172713408LLU,102270762752LLU},{18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,274877906943LLU}};

#if UINTPTR_MAX == 0xffffffffffffffff // 64-bit. Hopefully this means the cpu has 'popcnt'.
int counter (uint64_t * buf){
    uint64_t cnt[18];
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
    cnt[15] = 0;
    cnt[16] = 0;
    cnt[17] = 0;

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
            "popcnt %4, %4 \n\t"
            "add %4, %0    \n\t"
            "popcnt %5, %5 \n\t"
            "add %5, %1    \n\t"
            "popcnt %6, %6 \n\t"
            "add %6, %2    \n\t"
            "popcnt %7, %7 \n\t"
            "add %7, %3    \n\t"
            : "+r" (cnt[12]), "+r" (cnt[13]), "+r" (cnt[14]), "+r" (cnt[15])
            : "r" (buf[12]), "r" (buf[13]), "r" (buf[14]), "r" (buf[15]));
    __asm__(
            "popcnt %2, %2  \n\t"
            "add %2, %0     \n\t"
            "popcnt %3, %3  \n\t"
            "add %3, %1     \n\t"
            : "+r" (cnt[16]), "+r" (cnt[17])
            : "r" (buf[16]), "r" (buf[17]));


    return cnt[0] + cnt[1] + cnt[2] + cnt[3] + cnt[4] + cnt[5] + cnt[6] + cnt[7] + cnt[8] + cnt[9] + cnt[10] + cnt[11] + cnt[12] + cnt[13] + cnt[14] + cnt[15] + cnt[16] + cnt[17];
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
        A[i][2] = A[i-1][2] & C[i][2];

    } else {
        A[i][0] = A[i-1][0] & D[i][0];
        A[i][1] = A[i-1][1] & D[i][1];
        A[i][2] = A[i-1][2] & D[i][2];

    }
}

void printout(){
    sprintf(str, "[                  ,%5d]\n", this);
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
    str[16] = X[15] ^ 48;
    str[17] = X[16] ^ 48;
    str[18] = X[17] ^ 48;

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
    fputs("[[0,1],[0,6],[0,10],[1,2],[1,7],[2,3],[2,8],[3,4],[3,8],[4,5],[4,9],[5,6],[5,9],[6,10],[7,10],[7,11],[8,11],[9,11]]\n", fout);
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

