#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_14_81_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 13;
static uint_fast32_t endhere = 0;
char str[24] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[14][3] = {{9222809086834245632LLU,18446744065186725886LLU,4376933963569528831LLU},{2199023255551LLU,18446744073709486080LLU,4611686018427387903LLU},{18446744073709551615LLU,18446462598732906495LLU,4611686018427387903LLU},{18446744073709551615LLU,281474976710655LLU,4611686018427125760LLU},{18446742698900389856LLU,18444698979732619263LLU,4611686018159177201LLU},{17581914387998834687LLU,8342873727939624859LLU,4611685743817777151LLU},{18442381211567651871LLU,14861878770322634879LLU,4611545555816939407LLU},{5624995893783528447LLU,18446743866716454911LLU,4539769161877815295LLU},{18446741874686296064LLU,18446744073709551615LLU,4611686018427387903LLU},{18428714282104389631LLU,17856772522524012479LLU,3740239482176141567LLU},{144115188071526393LLU,4609997168567123952LLU,3385862460484616178LLU},{18446744004721639271LLU,18446742149429526543LLU,2017599437588660223LLU},{17869597207292837887LLU,18446744031830474750LLU,4395511320757141503LLU},{18443355516311698683LLU,18446464797756096497LLU,2882180609766064127LLU}};

static uint_fast64_t D[14][3] = {{15823381897603448831LLU,8342731787846526867LLU,3740239482176002175LLU},{18446742135419352510LLU,18221190242740666367LLU,4611686018427283901LLU},{18248405370116100045LLU,12082594850281606463LLU,4611686018427385579LLU},{7487770681526942323LLU,18446741495247405036LLU,4611686018427387903LLU},{18302631033115246591LLU,14123252989363748863LLU,4570974241934934015LLU},{9223370937343115264LLU,18446673703958739455LLU,4591903330186788737LLU},{14123288422961381375LLU,9223372036821270527LLU,4600145440933662207LLU},{18446743798830661631LLU,18302896614567575067LLU,4611663466616324095LLU},{11157314034066259967LLU,6589705632858976979LLU,4611686018427232086LLU},{4538713630715150335LLU,16103746359013636862LLU,4376933963569512406LLU},{18446743944826437439LLU,18365677089983561727LLU,1977064704203094975LLU},{18446743518577681919LLU,144062406675398655LLU,3385685417645834238LLU},{16111626567406321663LLU,18446531730509390327LLU,3739034425732626433LLU},{18338552129477648367LLU,18446744073709494271LLU,2098677219994634239LLU}};

uint_fast8_t X[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[14][3] = {{15823381897603448831LLU,8342731787846526867LLU,3740239482176002175LLU},{18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU}};

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
    fputs("[[0,2],[0,3],[0,5],[0,6],[1,3],[1,4],[1,5],[1,6],[2,4],[2,5],[3,5],[3,6],[4,6],[5,6]]\n", fout);
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

