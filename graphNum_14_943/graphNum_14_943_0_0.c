#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_14_943_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 13;
static uint_fast32_t endhere = 0;
char str[24] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[14][3] = {{18446743111636811776LLU,18374687579183250559LLU,4503599627370495LLU},{68719476735LLU,18446744073709551552LLU,4503599627370495LLU},{18446744073709551615LLU,18446742974197923903LLU,4503599627370495LLU},{18446744004990074880LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073642508287LLU,72057592963132415LLU,4503599627369984LLU},{17292691102985355263LLU,18446744073709551615LLU,4503599560262143LLU},{18446611719594311616LLU,18014329240249310847LLU,4503595399508991LLU},{18446744063509002303LLU,18444562636190907903LLU,4503054165454847LLU},{11522036884396509183LLU,15494634517968191487LLU,4433780639006711LLU},{18383667150924410748LLU,4462923194642177919LLU,4291385091849215LLU},{18446744051966255091LLU,18419709221206392575LLU,3648178768967679LLU},{8718863050573872335LLU,18157616496069574652LLU,1125810786271180LLU},{18446744037068074974LLU,18406174362328604543LLU,2127552726334463LLU},{18383667153172560757LLU,4466293197840056259LLU,3799490607709759LLU}};

static uint_fast64_t D[14][3] = {{16391407196698574847LLU,7998392077302360013LLU,4503599571983449LLU},{18446744005124165530LLU,18446743993100093567LLU,4503599627370495LLU},{5679973852302667877LLU,18446744073709551611LLU,4503599627370495LLU},{12766770289992269823LLU,18446743054807381892LLU,4503599627370495LLU},{18446741943405772799LLU,18379078869555265535LLU,4503599615648767LLU},{13668055433162522623LLU,10516017280096139318LLU,4503599627370406LLU},{9791388530183766015LLU,14987979002072268767LLU,4463153885191923LLU},{18446183322778468351LLU,17365879853600997375LLU,4473910309093375LLU},{18122484899599351807LLU,9223372036854253549LLU,4503365954298205LLU},{576460726508436991LLU,18428166657064042492LLU,3082927517204419LLU},{17870846271352209023LLU,1152498742385967103LLU,2146216599093244LLU},{18446744066193346559LLU,18433233274291093471LLU,3795789016473343LLU},{576460752244701687LLU,18445046427756265408LLU,3658658764291587LLU},{18446744013579960287LLU,18392664594834259967LLU,1059926995107839LLU}};

uint_fast8_t X[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[14][3] = {{16391407196698574847LLU,7998392077302360013LLU,4503599571983449LLU},{18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU}};

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
    fputs("[[0,1],[0,5],[0,6],[1,2],[1,5],[1,6],[2,3],[2,5],[2,6],[3,4],[3,5],[3,6],[4,5],[4,6]]\n", fout);
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

