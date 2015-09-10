#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_478_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][4] = {{13835269161514958847LLU,18158513698631581695LLU,1099511627775LLU,281474976710640LLU},{70368744177663LLU,18446744073441116160LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,268435455LLU,18446744073692774400LLU,281474976710655LLU},{18446744073709486080LLU,6917529027104210943LLU,18446743523959330133LLU,281474976710655LLU},{13835128424026406911LLU,18446744073709551615LLU,18428730224955883519LLU,281474976710655LLU},{4611686018427322369LLU,18446744073441116160LLU,18446743523970514943LLU,281474976710655LLU},{9223372036854775807LLU,18158513697826275327LLU,18014398492704767LLU,281474976710640LLU},{18446744073709420543LLU,288230376151711743LLU,18446743523936960512LLU,281474976448527LLU},{18446673704965373952LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709486083LLU,1152921504338411520LLU,18446743523970514944LLU,281474976448527LLU},{18410996747372593151LLU,18446726482597249023LLU,16158775825028612095LLU,281474909863935LLU},{13871016487851917311LLU,18158531289743884287LLU,2287969348192567295LLU,281457863950320LLU},{18446744073709551107LLU,1152921504606830592LLU,18446744069448137728LLU,281208483215375LLU},{18446744073709486591LLU,18446744073441132543LLU,18446743528231928831LLU,277350699763711LLU},{17219781404532137983LLU,18392489704290254847LLU,13704164425810051071LLU,266631565770747LLU},{17836503021387775975LLU,4598157696078708675LLU,16282632511161368572LLU,228646816055197LLU},{18184972073977249727LLU,18445632454568967423LLU,1692330913540603855LLU,206604100173567LLU},{14118714737738904575LLU,18159638772829978623LLU,18141607580999290879LLU,122304562450416LLU},{18445055223833550367LLU,18446744009272442943LLU,18338651012836097027LLU,268074537154687LLU},{18230571033897668543LLU,18445688542279499007LLU,4610841077547597775LLU,203407771320063LLU},{18275607077684461551LLU,18445883155853344719LLU,7493320864408010748LLU,173687889526719LLU}};

static uint_fast64_t D[21][4] = {{18446744073709486083LLU,1152921504338411520LLU,18446743523970514944LLU,281474976448527LLU},{18446720617461448702LLU,6533221859259842559LLU,18446744073698366805LLU,281474976710655LLU},{9223465861847056385LLU,18446744073530594645LLU,18446744073709551615LLU,281474976710655LLU},{13835128424026341375LLU,17678129738020814847LLU,18428730224955883519LLU,281474976710655LLU},{9223372036854775807LLU,1152921503712062122LLU,18446743523953737728LLU,281474976710655LLU},{18446720617461448703LLU,17293822570176446463LLU,18428730224955883519LLU,281474976710655LLU},{18446603336220934147LLU,18446744073530594645LLU,18446743523953737727LLU,281474976448527LLU},{234562480766973LLU,18446744073709551615LLU,18014398492704767LLU,281474976710640LLU},{9223301668110598143LLU,11913522214628666026LLU,18446744073703959210LLU,281474976710655LLU},{13835269161514958847LLU,18158513698631581695LLU,1099511627775LLU,281474976710640LLU},{18446744073709511483LLU,14987979559683551484LLU,18446743737045094159LLU,281457863789807LLU},{18446744073709526215LLU,4611686018364411651LLU,18446743860634972400LLU,281474909762335LLU},{16766605657829015551LLU,18388253625303433215LLU,3145956754253152255LLU,277350700023802LLU},{15515407577395494911LLU,18217004147037700095LLU,15300788418968027135LLU,281208483217397LLU},{17870280022871210979LLU,1139410705523212224LLU,18444491990180548604LLU,228635537436557LLU},{17221751729385621311LLU,18392489771932053759LLU,13830272858807353103LLU,266625798315259LLU},{18442240473880850679LLU,4611685193792622579LLU,18158496073092366591LLU,122320624272351LLU},{18437173923692912527LLU,18446740762226850831LLU,17834216933889933248LLU,206605084163647LLU},{17415415426292087807LLU,18428997131202002943LLU,7778191262011609087LLU,226220725628924LLU},{15556502937487277815LLU,4382001355099721715LLU,17931051127835458815LLU,122982078872533LLU},{14986787689271916159LLU,18176528044526912511LLU,18361171262341856319LLU,131241179339251LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][4] = {{18446744073709486083LLU,1152921504338411520LLU,18446743523970514944LLU,281474976448527LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU}};

#if UINTPTR_MAX == 0xffffffffffffffff // 64-bit. Hopefully this means the cpu has 'popcnt'.
int counter (uint64_t * buf){
    uint64_t cnt[21];
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
    cnt[18] = 0;
    cnt[19] = 0;
    cnt[20] = 0;

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
            "popcnt %4, %4 \n\t"
            "add %4, %0    \n\t"
            "popcnt %5, %5 \n\t"
            "add %5, %1    \n\t"
            "popcnt %6, %6 \n\t"
            "add %6, %2    \n\t"
            "popcnt %7, %7 \n\t"
            "add %7, %3    \n\t"
            : "+r" (cnt[16]), "+r" (cnt[17]), "+r" (cnt[18]), "+r" (cnt[19])
            : "r" (buf[16]), "r" (buf[17]), "r" (buf[18]), "r" (buf[19]));
    __asm__(
           "popcnt %1, %1  \n\t"
           "add %1, %0     \n\t"
            : "+r" (cnt[20])
            : "r" (buf[20]));


    return cnt[0] + cnt[1] + cnt[2] + cnt[3] + cnt[4] + cnt[5] + cnt[6] + cnt[7] + cnt[8] + cnt[9] + cnt[10] + cnt[11] + cnt[12] + cnt[13] + cnt[14] + cnt[15] + cnt[16] + cnt[17] + cnt[18] + cnt[19] + cnt[20];
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
    sprintf(str, "[                     ,%5d]\n", this);
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
    str[19] = X[18] ^ 48;
    str[20] = X[19] ^ 48;
    str[21] = X[20] ^ 48;

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,4],[3,5],[4,6],[5,7],[6,8],[6,9],[7,10],[7,11],[8,10],[8,12],[9,11],[9,13],[10,13],[11,12],[12,13]]\n", fout);
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

