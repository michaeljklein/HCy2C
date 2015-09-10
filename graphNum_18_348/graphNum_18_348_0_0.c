#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_18_348_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 17;
static uint_fast32_t endhere = 0;
char str[28] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[18][3] = {{18428800043943986175LLU,4602696411358695423LLU,268435392LLU},{68719476735LLU,18446744073709551360LLU,268435455LLU},{18446744073709551615LLU,18446726481523507455LLU,268435455LLU},{18410715276690325504LLU,18437752121016049663LLU,268435455LLU},{18446708958057201663LLU,13844065254536904191LLU,268435455LLU},{18428729743919022079LLU,4602669436673425407LLU,268435392LLU},{18014398509481473LLU,18446726481523504896LLU,268419135LLU},{6196953041449517055LLU,13853072453791641685LLU,268419135LLU},{18446744004990074880LLU,18446744073709551615LLU,268435455LLU},{72022478386363905LLU,13853072453791645440LLU,268419135LLU},{18445688542546871295LLU,4611158252577624063LLU,268189692LLU},{18429855575106666495LLU,18438282232490622975LLU,264503235LLU},{72055532186238945LLU,18176528096067321855LLU,254737471LLU},{18446711019909676575LLU,14123288431433875200LLU,217809919LLU},{18437521366954406847LLU,4030599620704866291LLU,184498143LLU},{17578956445620064251LLU,18409167099626782719LLU,129826676LLU},{18442785780309892863LLU,16138930670956183359LLU,99868657LLU},{4598033382343768047LLU,9072413557126135807LLU,189791695LLU}};

static uint_fast64_t D[18][3] = {{72022478386363905LLU,13853072453791645440LLU,268419135LLU},{18446744027896742910LLU,18446737036835133951LLU,268435455LLU},{12285749529254820865LLU,18446744073709551530LLU,268435455LLU},{6196917971609190399LLU,13844055872037682261LLU,268435455LLU},{18374756848415801343LLU,18437750948203644927LLU,268435455LLU},{18446744027897265664LLU,18446724135898698751LLU,268419135LLU},{18446744073708504063LLU,4602664745423814143LLU,268435392LLU},{18392736062552408575LLU,4602714003544735743LLU,268435392LLU},{6160994590267539455LLU,18446733518397924949LLU,268435455LLU},{18428800043943986175LLU,4602696411358695423LLU,268435392LLU},{4395492155604336333LLU,15690541101758807868LLU,264493503LLU},{14123274396491579187LLU,16609275425742389187LLU,268183167LLU},{18435977655850212351LLU,13829658349399904255LLU,217825241LLU},{18439566461803325439LLU,9219782135668342783LLU,254738406LLU},{17363610307268673273LLU,16085731904636059455LLU,128442167LLU},{4602671118363262863LLU,17433417664876773360LLU,182186463LLU},{1152774716331653031LLU,8430668133692407795LLU,192836863LLU},{17581463267706920571LLU,14951669287641677583LLU,100503421LLU}};

uint_fast8_t X[18] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[18][3] = {{72022478386363905LLU,13853072453791645440LLU,268419135LLU},{18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,268435455LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,4],[1,5],[2,4],[2,5],[3,4],[3,6],[5,7],[6,8],[6,9],[7,10],[7,11],[8,10],[8,11],[9,10],[9,11]]\n", fout);
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

