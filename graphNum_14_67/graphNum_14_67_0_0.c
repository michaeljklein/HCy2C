#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_14_67_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 13;
static uint_fast32_t endhere = 0;
char str[24] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[14][4] = {{18446744063758991359LLU,18194330310305447935LLU,18446735281911490435LLU,15LLU},{137438953471LLU,18446744073709549568LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18442240474082183167LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,4503599627370495LLU,18446744073705357312LLU,15LLU},{17257785078935691001LLU,9191846839194683385LLU,18446744069418582015LLU,15LLU},{18446743936270598144LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{11528942295780948455LLU,16429131440647568999LLU,18437745670547045502LLU,15LLU},{18221845567311052703LLU,18446709988247207935LLU,13844065254536904703LLU,15LLU},{18446744073709547520LLU,3440182765289463807LLU,4312135070262476286LLU,15LLU},{17887167421895151615LLU,18302628885633695679LLU,14933934682341900209LLU,12LLU},{576424880803676159LLU,18446743904058081279LLU,18446251251881476095LLU,3LLU},{8063694123355338429LLU,9191846839463180793LLU,8791021937011491839LLU,11LLU},{18122266097666203627LLU,18442275658185771007LLU,18438862753021034495LLU,12LLU},{18446744073708433535LLU,18446743248000514048LLU,4611624720637362175LLU,15LLU}};

static uint_fast64_t D[14][4] = {{18437736908814548865LLU,9223372036049469439LLU,17566000074070228990LLU,15LLU},{18446744046542209022LLU,12626320877818912767LLU,18446744073709499875LLU,15LLU},{1131515964605587637LLU,8786522872999836981LLU,18446744073707125564LLU,15LLU},{17329462688682401611LLU,18446707373479557118LLU,18446744073709551615LLU,15LLU},{13690942863977217023LLU,18446708915107266175LLU,16032072425780804615LLU,15LLU},{18432509521298456575LLU,15480681096830347979LLU,18446744073707835103LLU,15LLU},{18338657674062209023LLU,18446744073642444799LLU,17131687890292566011LLU,15LLU},{14987979558932708607LLU,16145193553595727841LLU,18445529886270423039LLU,15LLU},{9007199254740991LLU,18228160955915272191LLU,14987979287155437471LLU,5LLU},{18442186872890327039LLU,16690340184742427371LLU,8934587506716155135LLU,11LLU},{18444907889291165695LLU,2304991437444337567LLU,13769754210612543472LLU,14LLU},{18014187403182866415LLU,18442240508441919487LLU,16096426892894142455LLU,12LLU},{4604930602880201663LLU,18446744065119615103LLU,8718786153500606479LLU,11LLU},{18446743953412440063LLU,18443339968479707135LLU,14406733729689010175LLU,5LLU}};

uint_fast8_t X[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[14][4] = {{18437736908814548865LLU,9223372036049469439LLU,17566000074070228990LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU}};

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
        A[i][3] = A[i-1][3] & C[i][3];

    } else {
        A[i][0] = A[i-1][0] & D[i][0];
        A[i][1] = A[i-1][1] & D[i][1];
        A[i][2] = A[i-1][2] & D[i][2];
        A[i][3] = A[i-1][3] & D[i][3];

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
    fputs("[[0,2],[0,4],[0,5],[0,6],[1,3],[1,4],[1,5],[1,6],[2,4],[2,5],[2,6],[3,5],[3,6],[4,6]]\n", fout);
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

