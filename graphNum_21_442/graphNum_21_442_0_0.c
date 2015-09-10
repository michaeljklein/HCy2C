#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_442_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][5] = {{72057593903710209LLU,18446726481523507200LLU,17293822586282573823LLU,18446744073709551615LLU,1023LLU},{18014398509481983LLU,18446726481523507200LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,17592186044415LLU,18446744056529682432LLU,18446744073709551615LLU,1023LLU},{18446744073575333888LLU,18446708889337462783LLU,17293822586282573823LLU,18446744073709551615LLU,1023LLU},{18392700878315323391LLU,18446744073709551615LLU,1152921504606846975LLU,18446744073705357312LLU,1023LLU},{18428729675200069632LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18428729675468505087LLU,70368744177663LLU,1152921487426977792LLU,18446744073705357312LLU,1023LLU},{72057594037919745LLU,18446744073709486080LLU,18446673722145243135LLU,18446744056533876735LLU,1023LLU},{18446744073575342079LLU,18446726481523572735LLU,17293892937846882303LLU,18446673722145243135LLU,1023LLU},{18446742974466359295LLU,70368744177663LLU,1152921504606846912LLU,18437770100321812224LLU,1023LLU},{18428730774711697407LLU,18446744073709551615LLU,18446744056529682495LLU,17302829763995369727LLU,1023LLU},{72057594008510433LLU,18446742991373664255LLU,18194049655669522431LLU,243194378808459263LLU,1023LLU},{18445829276277137439LLU,18429011150176714752LLU,2305772915283722239LLU,18445688526440546303LLU,1008LLU},{18437729719038255103LLU,18230571290522091519LLU,18437807230314082511LLU,7466967649602238845LLU,975LLU},{14987979559755841047LLU,18446726482597248768LLU,17302825576469364735LLU,18444211348674969599LLU,828LLU},{288229280918224867LLU,18013573871828991LLU,18302206432650461120LLU,1145039104740687616LLU,1023LLU},{18446604369160830975LLU,13839561654909534207LLU,9223372036853727295LLU,14852871557969051888LLU,735LLU},{18428870412682001343LLU,18446744009234707443LLU,18391565615246606335LLU,17437931091334823935LLU,442LLU},{18446176722487403007LLU,18429855574037299455LLU,4603175798378066943LLU,18427884719841344511LLU,963LLU},{18446612080648781439LLU,14123270907967307535LLU,17365876864604704767LLU,16032612363156817907LLU,637LLU},{1136031975207829479LLU,4611685966884634623LLU,18410433578442686400LLU,3740233992113487631LLU,447LLU}};

static uint_fast64_t D[21][5] = {{18428729675468505087LLU,70368744177663LLU,1152921487426977792LLU,18446744073705357312LLU,1023LLU},{18428729675468505086LLU,12297817654349004799LLU,18446744067982928554LLU,18446744073709551615LLU,1023LLU},{12285819783198277633LLU,18446738209647536810LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18392700878181105663LLU,6148961603732635647LLU,1152921493153600853LLU,18446744073705357312LLU,1023LLU},{6196953087261802495LLU,18446679569027388757LLU,17293822586282573823LLU,18446744073709551615LLU,1023LLU},{6178938688752320511LLU,6148932283422561621LLU,18446744062256305493LLU,18446744073709551615LLU,1023LLU},{72057593903710209LLU,18446726481523507200LLU,17293822586282573823LLU,18446744073709551615LLU,1023LLU},{18436419015011205119LLU,3530611001625935871LLU,17293822556013117647LLU,18446673722142839145LLU,1023LLU},{18439054734166851583LLU,14916203440827793407LLU,2305843005123411760LLU,18446744056532086422LLU,1023LLU},{18230571291547128637LLU,18446740504339858371LLU,18028936784800382975LLU,17302829763999563775LLU,1023LLU},{288230376066133187LLU,18446730050893200444LLU,17711629875191742463LLU,18437770100321812479LLU,1023LLU},{18445648956101754879LLU,18428800043944247295LLU,1152921504539800575LLU,18445632501813353471LLU,1008LLU},{18436599335157178367LLU,3530821025522581503LLU,18194049900281318607LLU,243180069044614505LLU,1023LLU},{14985358151832829463LLU,14987135134958878464LLU,16140896871789051900LLU,18444281166161162199LLU,828LLU},{18432661787552776191LLU,18159639597464682495LLU,4611686002270924803LLU,7466968166502889532LLU,975LLU},{18445648960092238655LLU,18446740762038092739LLU,18137093561714275327LLU,18212536891423333375LLU,1008LLU},{1152921504599275911LLU,18446744005997752560LLU,18381709129157705727LLU,18439628481131184127LLU,442LLU},{17582052878597992187LLU,13839547635330137919LLU,8498114341604687871LLU,14986114504499134448LLU,735LLU},{14984575214162018295LLU,288229293819953151LLU,18194542424850632700LLU,11202689779004336067LLU,831LLU},{4597611443884161519LLU,18443366373922959615LLU,13833074382710243267LLU,8642126104146870079LLU,491LLU},{18446634120297834111LLU,18433216781146328847LLU,8351869433864582143LLU,18355915191960443903LLU,725LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][5] = {{18428729675468505087LLU,70368744177663LLU,1152921487426977792LLU,18446744073705357312LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,3],[2,4],[3,5],[4,6],[4,7],[5,8],[5,9],[6,8],[6,10],[7,10],[7,11],[8,12],[9,11],[9,12],[10,13],[11,13],[12,13]]\n", fout);
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
