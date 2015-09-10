#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_18_317_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 17;
static uint_fast32_t endhere = 0;
char str[28] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[18][3] = {{18446739701433368575LLU,576460752303161359LLU,1073741312LLU},{8589934591LLU,18446744073709551612LLU,1073741823LLU},{18446744073709551615LLU,18446739675663040515LLU,1073741823LLU},{18446744073709543424LLU,18428733385336684535LLU,1073741823LLU},{18446739684252983295LLU,18014398509481983LLU,1073741820LLU},{4398046502913LLU,18428734073246580732LLU,1073741823LLU},{17825238529039400959LLU,18436184364036128769LLU,1073741315LLU},{18446744073709043711LLU,17888293321869361151LLU,1073676799LLU},{18446744065119617024LLU,18446744073709551615LLU,1073741823LLU},{18445620990139432929LLU,18446678103011885055LLU,1072758599LLU},{1125899906834463LLU,18428800043676860412LLU,1058005503LLU},{18445635765988261859LLU,17906246147995860991LLU,1072701439LLU},{18433233034276237247LLU,14402370870842489868LLU,1013972963LLU},{18446739941984468991LLU,4503599611264107519LLU,872218140LLU},{18159428491232149015LLU,18445670744186683391LLU,785365503LLU},{288229825993236991LLU,9206483538000465916LLU,457172927LLU},{18445688336356605927LLU,14555576838236666943LLU,1022574567LLU},{18176524789479308927LLU,18373842041843761151LLU,668859004LLU}};

static uint_fast64_t D[18][3] = {{932262715051733699LLU,18439292751054897151LLU,1073676799LLU},{18446744068563681278LLU,18446742263739099815LLU,1073741823LLU},{6459666011291893761LLU,18446744073709551614LLU,1073741823LLU},{18446739684252975103LLU,18012154388370783LLU,1073741820LLU},{11987078076153462783LLU,18428733041381736433LLU,1073741823LLU},{18446744068563681279LLU,18011032327815183LLU,1073741820LLU},{6770423150757286595LLU,17888297719915610111LLU,1073676799LLU},{17514481389573500221LLU,18436184364036390908LLU,1073741315LLU},{11987078067563528191LLU,18446741485633492313LLU,1073741823LLU},{18446744069145083903LLU,8628896885773488079LLU,1058005501LLU},{18446742491418361855LLU,9835858219996491839LLU,1072758598LLU},{17514496160858369343LLU,8636355972924493772LLU,1058012857LLU},{14771754001216994043LLU,18335834119818182655LLU,872207359LLU},{4593741988662077319LLU,18432968361040150524LLU,1013919231LLU},{18446743111108100095LLU,1981580534286893311LLU,469172111LLU},{18446531797628813303LLU,17077631924219887423LLU,788119414LLU},{13853069698167470207LLU,9219149912140992511LLU,866120381LLU},{4610841456032868335LLU,15839120581720014076LLU,494366703LLU}};

uint_fast8_t X[18] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[18][3] = {{932262715051733699LLU,18439292751054897151LLU,1073676799LLU},{18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,1073741823LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,4],[3,6],[4,7],[5,6],[5,8],[6,9],[7,9],[7,10],[8,10],[8,11],[9,11],[10,11]]\n", fout);
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

