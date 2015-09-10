#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_422_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][5] = {{1152921504069976065LLU,18442240474082181120LLU,70368744177663LLU,18446744073709550592LLU,262143LLU},{288230376151711743LLU,18442240474082181120LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,4503599627370495LLU,18446673704965373952LLU,18446744073709551615LLU,262143LLU},{18446744073172680704LLU,18437736874454810623LLU,70368744177663LLU,18446744073709550592LLU,262143LLU},{17582052945791287295LLU,18446744073709551615LLU,18446744073709551615LLU,18446743798831645695LLU,262143LLU},{18158513697557839872LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18158513698631581695LLU,18014398509481983LLU,18446673704965373952LLU,18446743798831645695LLU,262143LLU},{1152921504606814209LLU,18446744073692774400LLU,17293892937846882303LLU,18446673979843280895LLU,262143LLU},{18446744073172713471LLU,18442240474098958335LLU,1152921504606846975LLU,18428800043944246272LLU,262143LLU},{18446726482597249023LLU,18014398509481983LLU,18446744073709289472LLU,16149486051268756479LLU,262143LLU},{18158531289743884287LLU,18446744073709551615LLU,18446673704965636095LLU,2305823492899078143LLU,262128LLU},{1113934469405867777LLU,18230571291595766784LLU,18437803930923551999LLU,17816239813818841087LLU,261903LLU},{18446744073705357567LLU,18446743798831645695LLU,9007199254740991LLU,11529145227080105976LLU,258295LLU},{1152921504074170113LLU,18442240748960087040LLU,18437807243198988287LLU,17798366464856554503LLU,261903LLU},{18429011082531045375LLU,18014398509481983LLU,18446743798898753532LLU,18162313592831935487LLU,249711LLU},{18446726550175676895LLU,18446532966470324175LLU,11474045950632919043LLU,16428843368584380287LLU,212223LLU},{18445634683656994815LLU,4611686018427387903LLU,18446744072636070912LLU,2305787482818494463LLU,177918LLU},{4324581542156824563LLU,18446727568149446652LLU,18302136305498193919LLU,18445053850533494734LLU,126913LLU},{18433233210398967807LLU,288230102330834943LLU,8142507868587819004LLU,13618823687632261112LLU,246783LLU},{18445687717409849103LLU,18442258066268224515LLU,18438299823338683455LLU,9171580640132594751LLU,180030LLU},{18176511603375995895LLU,18446730878764662780LLU,13798677689419957247LLU,16715948686643822559LLU,97747LLU}};

static uint_fast64_t D[21][5] = {{18158513698631581695LLU,18014398509481983LLU,18446673704965373952LLU,18446743798831645695LLU,262143LLU},{18158513698631581694LLU,12294826982721454079LLU,18446720617461492394LLU,18446744073709551615LLU,262143LLU},{12105675797298151425LLU,18445242873833761450LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{17582052945254416383LLU,6160924290242838527LLU,18446697161213433173LLU,18446743798831645695LLU,262143LLU},{6917529027641081855LLU,18430230875075859797LLU,70368744177663LLU,18446744073709550592LLU,262143LLU},{6629298651489370111LLU,6153418290863887701LLU,18446697161213433173LLU,18446744073709551615LLU,262143LLU},{1152921504069976065LLU,18442240474082181120LLU,70368744177663LLU,18446744073709550592LLU,262143LLU},{18274084007924727807LLU,14933936364360564735LLU,18446690262920786700LLU,18428799879282777087LLU,262143LLU},{18331173764416405503LLU,3530822107858468863LLU,18446727515754138867LLU,18446673869626845183LLU,262143LLU},{4611686018232831651LLU,18445830315068093232LLU,16849232843388223487LLU,2305823767760207500LLU,262128LLU},{14987979559546696029LLU,18443154232723639503LLU,1597581599065505791LLU,16149486051285532019LLU,262143LLU},{18293577525521055743LLU,14987979285027880959LLU,1152868521886941132LLU,11529144531253288952LLU,258295LLU},{18388263520908083199LLU,18176528096067321855LLU,18446739933365256255LLU,17798366409085154303LLU,261903LLU},{18216994251433050111LLU,288230376151711743LLU,18446677845309669312LLU,11529145007973601279LLU,258295LLU},{18446744073591879879LLU,18446466995722322880LLU,10311272821841461247LLU,6917520781303873311LLU,212211LLU},{4593953094750425019LLU,18445896285816094527LLU,18012005697369145343LLU,13829973896603893484LLU,249708LLU},{1152921504576562161LLU,18446726739488948220LLU,4358991858085396479LLU,16625178761926541254LLU,126927LLU},{18446742991040068959LLU,4608097006101974223LLU,15540796414148738048LLU,17969325129811901819LLU,177919LLU},{18392485648662527943LLU,18446466996779352000LLU,18444769625641041983LLU,8643252058109247263LLU,212891LLU},{18217047285688296447LLU,14123288414521409535LLU,4359418210898690047LLU,17221750462357688318LLU,125431LLU},{18445899596833988415LLU,4607463636062960703LLU,17575297544806727676LLU,13641350493941742841LLU,186238LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][5] = {{18158513698631581695LLU,18014398509481983LLU,18446673704965373952LLU,18446743798831645695LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU}};

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
        A[i][4] = A[i-1][4] & C[i][4];

    } else {
        A[i][0] = A[i-1][0] & D[i][0];
        A[i][1] = A[i-1][1] & D[i][1];
        A[i][2] = A[i-1][2] & D[i][2];
        A[i][3] = A[i-1][3] & D[i][3];
        A[i][4] = A[i-1][4] & D[i][4];

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,3],[2,4],[3,5],[4,6],[4,7],[5,8],[5,9],[6,7],[6,10],[7,11],[8,10],[8,12],[9,11],[9,12],[10,13],[11,13],[12,13]]\n", fout);
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
