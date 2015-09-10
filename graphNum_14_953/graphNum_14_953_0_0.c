#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_14_953_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 13;
static uint_fast32_t endhere = 0;
char str[24] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[14][3] = {{18446181123757178879LLU,18446744073709551615LLU,268435455LLU},{18446744073708503040LLU,18446744073709551615LLU,268435455LLU},{562949953421311LLU,18446744073709535232LLU,268435455LLU},{18446744073709551615LLU,18446735277616545791LLU,268435455LLU},{18446744073709551615LLU,8796093022207LLU,268435200LLU},{18438862774346973168LLU,18446620928407011327LLU,268431615LLU},{9160321642071588623LLU,18301641386482724607LLU,268373947LLU},{18446594522830860543LLU,13538941972594556927LLU,267452287LLU},{17942058855412207615LLU,8583860889768157166LLU,252706807LLU},{14411500039651262463LLU,18446743780460592605LLU,16777215LLU},{17148581481119866366LLU,1132637681847599043LLU,232652543LLU},{18446742009706954717LLU,18410398101878013951LLU,197123568LLU},{16120601876490615739LLU,18441607155384581183LLU,133937935LLU},{18117453534717769591LLU,18446735827362759679LLU,259487743LLU}};

static uint_fast64_t D[14][3] = {{7916202245010349550LLU,17129280514113105659LLU,268435387LLU},{13834420055069163519LLU,16068833501704599415LLU,268435421LLU},{18446594383074279133LLU,13509351881252995071LLU,268435326LLU},{16048293009551780795LLU,8632767166971633582LLU,268435431LLU},{17541466602132633463LLU,18446743230795872733LLU,268435455LLU},{4611685889578369023LLU,17365880161127366652LLU,250540031LLU},{18446744065120665599LLU,2305842979148922823LLU,232652543LLU},{13835619081090236415LLU,18446743592673214463LLU,197123569LLU},{18446713287383973887LLU,18446744073575349375LLU,133937951LLU},{18446251492500307967LLU,18374687579183237119LLU,259487743LLU},{18392137936817618719LLU,18445899648777846783LLU,268374015LLU},{4611686018326721023LLU,18439988674255896576LLU,267452415LLU},{18014398508676620287LLU,18392692082222301183LLU,252706815LLU},{14987979553445642239LLU,72057593937264639LLU,16776960LLU}};

uint_fast8_t X[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[14][3] = {{7916202245010349550LLU,17129280514113105659LLU,268435387LLU},{18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,268435455LLU}};

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
    fputs("[[0,1],[0,3],[0,4],[0,5],[0,6],[1,2],[1,3],[1,4],[1,5],[1,6],[2,3],[2,4],[2,5],[2,6]]\n", fout);
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
