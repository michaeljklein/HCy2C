#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_15_199_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 14;
static uint_fast32_t endhere = 0;
char str[25] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[15][3] = {{18446744069414584320LLU,18446744073709551615LLU,4503599627370495LLU},{4294967295LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744069414584320LLU,4503599627370495LLU},{18446744073709551615LLU,4294967295LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,4503595332403200LLU},{15987778612740751359LLU,15987778612168228848LLU,4503534630338544LLU},{18446744073137029104LLU,13546263697243897615LLU,4502567694237455LLU},{13546263697243897615LLU,9204215245764034559LLU,4487104801009919LLU},{9204215243612090623LLU,18446744071557607679LLU,4239716693512191LLU},{17831738841639620607LLU,17831738841639620607LLU,281474976710655LLU},{18442484428224593919LLU,18442484428223602143LLU,4203364232519135LLU},{18446744073708559839LLU,18379115303902624765LLU,3903261967891453LLU},{18379115303902624765LLU,17365739133594501119LLU,3307184695771067LLU},{17365739133342810043LLU,18446744073457860539LLU,2247105682863991LLU},{1152912120371738487LLU,1152912120371738487LLU,4353481930440703LLU}};

static uint_fast64_t D[15][3] = {{15987459677059284991LLU,15987459676486688222LLU,4503599054773726LLU},{18446744073136954846LLU,13541686284307512301LLU,4503598485322733LLU},{13541686284307512301LLU,9132032015342764031LLU,4503597458620091LLU},{9132032013174013627LLU,18446744071540801211LLU,4503599215798135LLU},{16679054247160440695LLU,16679054247160440695LLU,4503599627370495LLU},{18442803424035536896LLU,18442803424034684927LLU,4203364232593407LLU},{18446462603026890751LLU,18383693678911684607LLU,3903261968957439LLU},{18383693678911684607LLU,17437937757178494976LLU,3307184712581119LLU},{17437937756943679487LLU,18446462602792927231LLU,2247105951301631LLU},{2305843005455597567LLU,2305843005455597567LLU,4353481930375168LLU},{18446744009285107711LLU,18446744013580009457LLU,4503535202861041LLU},{281474976710641LLU,18446743111636877087LLU,4502568835219231LLU},{18446743111636877087LLU,18446728676251860991LLU,4487106952950271LLU},{18446728680546759167LLU,281474976707071LLU,4239716836646911LLU},{18446497783104872447LLU,18446497783104872447LLU,281470681808895LLU}};

uint_fast8_t X[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[15][3] = {{15987459677059284991LLU,15987459676486688222LLU,4503599054773726LLU},{18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU}};

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
        A[i][2] = A[i-1][2] & C[i][2];

    } else {
        A[i][0] = A[i-1][0] & D[i][0];
        A[i][1] = A[i-1][1] & D[i][1];
        A[i][2] = A[i-1][2] & D[i][2];

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
    fputs("[[0,3],[0,4],[0,5],[0,6],[0,7],[1,3],[1,4],[1,5],[1,6],[1,7],[2,3],[2,4],[2,5],[2,6],[2,7]]\n", fout);
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

