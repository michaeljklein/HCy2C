#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_14_19_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 13;
static uint_fast32_t endhere = 0;
char str[24] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[14][3] = {{13808032159597853433LLU,18321206234096599033LLU,4611685881021988091LLU},{137438953471LLU,18446744073709551488LLU,4611686018427387903LLU},{18446744073709551615LLU,18446726481523507327LLU,4611686018427387903LLU},{18446744073709551615LLU,17592186044415LLU,4611686018427371520LLU},{18446744064909844479LLU,14987432001487749247LLU,4611686018393849823LLU},{18446743936270598144LLU,18446744073709551615LLU,4611686018427387903LLU},{17869302557032644519LLU,18446743936255934463LLU,4611404680889630719LLU},{18446744069947654143LLU,17884915621882134527LLU,4607445854679203775LLU},{9218982704698095503LLU,576355199187156967LLU,4544055607948162039LLU},{17154210155991121531LLU,18446743764740340991LLU,3530822101683732479LLU},{18446744073709547520LLU,9214363802512654335LLU,3373188408749850609LLU},{16357003477831913471LLU,18158232222581129151LLU,3888409402594680719LLU},{2303588872971354111LLU,18446727581001578495LLU,2251236743402455039LLU},{18446744073707418111LLU,18446743523752398720LLU,3446379606091759615LLU}};

static uint_fast64_t D[14][3] = {{17869438887885545407LLU,14987979559886913663LLU,4611460893393928159LLU},{18446744046235934718LLU,8042269967083863935LLU,4611686018427387677LLU},{4242170699294171853LLU,17545144538933231541LLU,4611686018427378403LLU},{14404475061179137331LLU,18446742011751933694LLU,4611686018427387903LLU},{18446603437151879137LLU,18338657545201123327LLU,4611629699024551163LLU},{18246842414419410943LLU,11306075703359625675LLU,4611686018427381246LLU},{13808036456502917887LLU,18428745066752245753LLU,4611685987886989311LLU},{18302769554268339743LLU,18446638245715377407LLU,4210790880505508855LLU},{17293821743899082747LLU,18443366339631382527LLU,3888559208957214655LLU},{9223345632469448687LLU,18010000462872551LLU,4582973474848374783LLU},{144115188075855871LLU,15705881469684478975LLU,1728396819542822911LLU},{18425331084758614015LLU,4526029698936864747LLU,4544130789213697535LLU},{18337988629827158015LLU,18446744067124092319LLU,3240306945990459264LLU},{18446743953433427967LLU,18446735251845152767LLU,1404876723341738111LLU}};

uint_fast8_t X[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[14][3] = {{17869438887885545407LLU,14987979559886913663LLU,4611460893393928159LLU},{18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU}};

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
    fputs("[[0,3],[0,4],[0,5],[0,6],[1,4],[1,5],[1,6],[2,4],[2,5],[2,6],[3,4],[3,5],[3,6],[4,6]]\n", fout);
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

