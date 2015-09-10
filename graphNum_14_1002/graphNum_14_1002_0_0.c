#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_14_1002_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 13;
static uint_fast32_t endhere = 0;
char str[24] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[14][3] = {{18446743936270598144LLU,18446744073709551615LLU,4294967295LLU},{137438953471LLU,18446744073709550592LLU,4294967295LLU},{18446744073709551615LLU,18446744004990075903LLU,4294967295LLU},{18128923228314271743LLU,18446462661814510294LLU,4294967295LLU},{18446181120534903808LLU,17294104044054192111LLU,4294967295LLU},{16032808626124489727LLU,1152921504606846975LLU,4294967040LLU},{18446744033845163772LLU,14987126192794556415LLU,4294951167LLU},{18446603465070211071LLU,4611633241060278175LLU,4293935091LLU},{17429071295389106131LLU,18389322353826856959LLU,4228907007LLU},{18446744073172746239LLU,18446739744281847807LLU,4090490877LLU},{13817034448899670015LLU,18437459797524611071LLU,3489611263LLU},{9007199254740991LLU,14987900391830192124LLU,2944399567LLU},{18446744073674948541LLU,18229725629715053571LLU,2080229375LLU},{9223248891082701951LLU,17582050746231160828LLU,3086220287LLU}};

static uint_fast64_t D[14][3] = {{16339231933986766847LLU,18446744048202004484LLU,4294967295LLU},{18446743936928122086LLU,18446744030497622015LLU,4294967295LLU},{2107512276504214297LLU,18446744073709551611LLU,4294967295LLU},{16140896666449281024LLU,6153605940823195647LLU,4294967126LLU},{18309382223489990655LLU,12681863797434351327LLU,4294967209LLU},{18157634085034393599LLU,18058018472218002406LLU,4294967295LLU},{18437737011876986847LLU,18392665143247896575LLU,4254498803LLU},{17437937721737199600LLU,18442521528110143487LLU,4268740351LLU},{18446744060690294527LLU,1152895116323651487LLU,4294554111LLU},{10371211598718042111LLU,6904018208893418927LLU,3489611095LLU},{17797028359205552127LLU,17687324586414178173LLU,4090490876LLU},{18446743994193899407LLU,18176526412354121727LLU,2044526591LLU},{18446744056256781815LLU,18446638516432535551LLU,2939649987LLU},{18439988571189231615LLU,18446603271796686079LLU,1560272703LLU}};

uint_fast8_t X[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[14][3] = {{16339231933986766847LLU,18446744048202004484LLU,4294967295LLU},{18446744073709551615LLU,18446744073709551615LLU,4294967295LLU},{18446744073709551615LLU,18446744073709551615LLU,4294967295LLU},{18446744073709551615LLU,18446744073709551615LLU,4294967295LLU},{18446744073709551615LLU,18446744073709551615LLU,4294967295LLU},{18446744073709551615LLU,18446744073709551615LLU,4294967295LLU},{18446744073709551615LLU,18446744073709551615LLU,4294967295LLU},{18446744073709551615LLU,18446744073709551615LLU,4294967295LLU},{18446744073709551615LLU,18446744073709551615LLU,4294967295LLU},{18446744073709551615LLU,18446744073709551615LLU,4294967295LLU},{18446744073709551615LLU,18446744073709551615LLU,4294967295LLU},{18446744073709551615LLU,18446744073709551615LLU,4294967295LLU},{18446744073709551615LLU,18446744073709551615LLU,4294967295LLU},{18446744073709551615LLU,18446744073709551615LLU,4294967295LLU}};

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
    fputs("[[0,3],[0,4],[0,6],[1,3],[1,5],[1,6],[2,4],[2,5],[2,6],[3,5],[3,6],[4,5],[4,6],[5,6]]\n", fout);
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

