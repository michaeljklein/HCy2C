#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_14_63_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 13;
static uint_fast32_t endhere = 0;
char str[24] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[14][3] = {{18446744069206679551LLU,18438268928510399487LLU,17592169275388LLU},{8589934591LLU,18446744073709551600LLU,17592186044415LLU},{18446744073709551615LLU,18446743523953737743LLU,17592186044415LLU},{18446744073709551615LLU,549755813887LLU,17592186044412LLU},{14915913177240698337LLU,18014253923702931391LLU,17592186036227LLU},{18446744065119617024LLU,18446744073709551615LLU,17592186044415LLU},{18441123370268262175LLU,18446744073701425023LLU,17587907854335LLU},{18446744073709547520LLU,9187129917264887327LLU,17560896531315LLU},{9189558755749007359LLU,17288456952359157759LLU,17076217323519LLU},{17906312075492196351LLU,18446744073709511167LLU,13743894429647LLU},{14771595403878988217LLU,17951203528919744508LLU,12635659566595LLU},{18437728353238777831LLU,18446744072644198335LLU,8693013783039LLU},{576460752303403263LLU,18446744073709354736LLU,17562105544695LLU},{18428729469025910779LLU,18446743525027479551LLU,12781822574143LLU}};

static uint_fast64_t D[14][3] = {{18445618181318901505LLU,18014257771993628479LLU,17590692864603LLU},{18446744068660846590LLU,9113519638575039455LLU,17592186044414LLU},{7563405235427729709LLU,14829913218524119034LLU,17592186044415LLU},{17802720152927420115LLU,18446744072627059775LLU,17592186044415LLU},{18442240469648678911LLU,18438299721320634367LLU,17589385486332LLU},{11527362764112658431LLU,12950055291402436581LLU,17592186044413LLU},{14915921965748059647LLU,18446709432600493055LLU,17592184815015LLU},{17871409221312970751LLU,16710579680612139007LLU,16148539121661LLU},{16140192927467962367LLU,4269409148212338693LLU,14816429207491LLU},{4611631455162859519LLU,18445653332201963519LLU,17416039955327LLU},{18433233270531432447LLU,18446181122682396671LLU,8690284863484LLU},{18302417778994314175LLU,18375812276499249148LLU,12635587936255LLU},{18446744072089960447LLU,16212958245405323263LLU,16148271724255LLU},{18157662669115488111LLU,2305843009213693939LLU,6576659755004LLU}};

uint_fast8_t X[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[14][3] = {{18445618181318901505LLU,18014257771993628479LLU,17590692864603LLU},{18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU}};

#if UINTPTR_MAX == 0xffffffffffffffff // 64-bit. Hopefully this means the cpu has 'popcnt'.
int counter (uint64_t * buf){
    uint64_t cnt[14];
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


    return cnt[0] + cnt[1] + cnt[2] + cnt[3] + cnt[4] + cnt[5] + cnt[6] + cnt[7] + cnt[8] + cnt[9] + cnt[10] + cnt[11] + cnt[12] + cnt[13];
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
    sprintf(str, "[              ,%5d]\n", this);
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
    fputs("[[0,2],[0,4],[0,5],[0,6],[1,3],[1,4],[1,6],[2,4],[2,5],[2,6],[3,5],[3,6],[4,6],[5,6]]\n", fout);
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

