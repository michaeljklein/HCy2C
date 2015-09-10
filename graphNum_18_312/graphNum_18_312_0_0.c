#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_18_312_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 17;
static uint_fast32_t endhere = 0;
char str[28] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[18][3] = {{288230102079115263LLU,18428729950077975552LLU,1023LLU},{18374686479940059135LLU,18446744073709551615LLU,1023LLU},{72057594037927935LLU,18446744073441116160LLU,1023LLU},{18302628885633694720LLU,18446743936360079359LLU,1023LLU},{18446743799100081151LLU,18446673842404327423LLU,1023LLU},{18374686754549529601LLU,18446743936539033599LLU,1023LLU},{72057044282114047LLU,18428800043675810816LLU,1023LLU},{18446744073709549567LLU,13853072316084257791LLU,1023LLU},{18446744073441116160LLU,18446744073709551615LLU,1023LLU},{18374687579183250435LLU,13853072316621131775LLU,1023LLU},{288230360044539903LLU,4610626364096118780LLU,1022LLU},{18446743815744126975LLU,18429789604409244675LLU,1009LLU},{18446463698244468675LLU,18176528088013213695LLU,971LLU},{18374967954648333375LLU,4899916265462693887LLU,831LLU},{14069232038544608759LLU,11492974248188657663LLU,751LLU},{4611685953986166783LLU,9219133419529699264LLU,446LLU},{14123288221802500095LLU,18432968567403052095LLU,739LLU},{18446480147955843023LLU,18227745540268949452LLU,478LLU}};

static uint_fast64_t D[18][3] = {{18374687579183250435LLU,13853072316621131775LLU,1023LLU},{12249790986358269950LLU,18446744073530596010LLU,1023LLU},{18398705861294118913LLU,18446744073709551615LLU,1023LLU},{6341068000728186879LLU,18446673842404324693LLU,1023LLU},{18206551910331187199LLU,18446743936270602239LLU,1023LLU},{288230376062232575LLU,18446673842404323328LLU,1023LLU},{18398706410155143171LLU,13853072316352692223LLU,1023LLU},{18446742975092711421LLU,18428800043675811839LLU,1023LLU},{6244991299766714367LLU,18446744073620071765LLU,1023LLU},{288230102079115263LLU,18428729950077975552LLU,1023LLU},{18429641170339495515LLU,16555232173778784255LLU,1009LLU},{18391790482553306535LLU,1909526161269735423LLU,1022LLU},{1152921343340855295LLU,9212775493542083827LLU,831LLU},{17582052832447811583LLU,18439326493390667532LLU,971LLU},{18443155216201154399LLU,17722777217982005187LLU,445LLU},{18379173586624576755LLU,14933936259419017215LLU,739LLU},{18442258066268225295LLU,8142508094056890367LLU,446LLU},{14920425425690639615LLU,14978795785687137535LLU,631LLU}};

uint_fast8_t X[18] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[18][3] = {{18374687579183250435LLU,13853072316621131775LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,1023LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,4],[3,5],[4,6],[5,7],[6,8],[6,9],[7,10],[7,11],[8,9],[8,10],[9,11],[10,11]]\n", fout);
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

