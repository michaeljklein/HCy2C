#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_811_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][7] = {{18419713679852339199LLU,2199023255431LLU,1152920679973124160LLU,9151314442816651263LLU,17870300913456906239LLU,18446744004994269183LLU,16383LLU},{18446744073709551615LLU,268435455LLU,18158513697557839872LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU,0LLU,18446744069414584320LLU,18446744073709551615LLU,16383LLU},{18446735277616529408LLU,18446744073709551615LLU,576459927669700735LLU,18335842794909204479LLU,17870283325495441405LLU,18446744073709551615LLU,16383LLU},{8796093022207LLU,18446741874954731520LLU,18432951799645208575LLU,18446737468016295935LLU,576460752303423391LLU,18446744073705357312LLU,16383LLU},{18419722475945328639LLU,268435335LLU,18446744073709551552LLU,4314307153629044221LLU,14987979559350525951LLU,18446744004990826868LLU,16383LLU},{9223372036854743041LLU,18446744073696706559LLU,18158513697557839935LLU,18446691262657462271LLU,18446726485818473727LLU,18445618242522185727LLU,16383LLU},{18446744070488129535LLU,18212543698913099775LLU,252096025478037501LLU,18446742974197923840LLU,18366746863257780223LLU,18159497758840356863LLU,16383LLU},{18442256966748209151LLU,18446744073709550847LLU,18446743944860520439LLU,1099511627775LLU,432345147615739904LLU,288203764467230712LLU,16380LLU},{0LLU,18446744073441116160LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{8645705707505LLU,8645187233676001276LLU,18296717910916990975LLU,16285014053548457983LLU,576460752303411167LLU,12393905141382642688LLU,16354LLU},{18446737475563878911LLU,18446741891597729795LLU,18437650013036216287LLU,18433228868157423616LLU,18446744069683019711LLU,18429609249563739135LLU,16159LLU},{8680687869439246081LLU,4467509254479151103LLU,18446744069414584380LLU,18445882022082904063LLU,18334048396733579007LLU,18104461774655848395LLU,15610LLU},{18446603301458772223LLU,14954202442411786367LLU,18158513701852807167LLU,18446708889337462723LLU,13815337352165129712LLU,6913034224106702847LLU,13279LLU},{4503588839489523LLU,18301494173494050812LLU,18446744073574039551LLU,16285012954036846591LLU,18442205289710079967LLU,18176526168556993543LLU,16355LLU},{14987714513162203135LLU,14123288431433873151LLU,13832946967186993143LLU,1095233306611LLU,9628693666855911408LLU,14122997793144428351LLU,11255LLU},{18370464355008643039LLU,18446479916039011823LLU,17293820266968768255LLU,18446744073706404927LLU,9223160634269499407LLU,4611630905289207784LLU,7868LLU},{18437173923964526583LLU,18410717398404423652LLU,14717763238649265791LLU,18446743042917335039LLU,18444496396928943103LLU,4465319030005169662LLU,6127LLU},{18140455319120116543LLU,36027145352380319LLU,4611676668552018368LLU,9133370413051400191LLU,16719613513533751295LLU,17537016880794959871LLU,11647LLU},{8680683608832211215LLU,18446742008635604991LLU,18437650008741511132LLU,18446744073693806655LLU,18374686347576213503LLU,18378936092108816331LLU,15423LLU},{576320014513047539LLU,18418596460065899516LLU,18158531289608372223LLU,16717360717304430531LLU,13833915662700904435LLU,18226206505311312959LLU,13287LLU}};

static uint_fast64_t D[21][7] = {{3239900127241961471LLU,18446744073694405887LLU,18430482253542739967LLU,16717292482874831619LLU,4035225262877572099LLU,18445618242521433739LLU,16383LLU},{10151127755938922494LLU,18446744073606030585LLU,576460752303423487LLU,14728373429645846102LLU,18446744071070918421LLU,18446744073709551615LLU,16383LLU},{8295616317770629121LLU,7444903183206030086LLU,18269667995082666074LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446741874954731519LLU,18430482253542739967LLU,12961210728658721193LLU,576460750683856779LLU,18446744073705357312LLU,16383LLU},{18446744073709551615LLU,11001840890875478015LLU,179544800095631397LLU,9092996104620933119LLU,17870283325458673916LLU,18446744073709551615LLU,16383LLU},{3239900127241928704LLU,18446744073694405887LLU,17870283321406128127LLU,17254917259937707863LLU,18446726483582776437LLU,18445618242522185727LLU,16383LLU},{16107578067787513855LLU,18446744073608331137LLU,1152921504606846975LLU,1787710512285093116LLU,14987979558947590047LLU,18446744004990826868LLU,16383LLU},{18442247444665708125LLU,7491068084815133743LLU,18296717776825336563LLU,18446744073709551615LLU,432345151910707199LLU,288203764467230712LLU,16380LLU},{8295625836631708067LLU,18166378797303995350LLU,18383559812444175708LLU,18446744073709551615LLU,18366746863257780223LLU,18159497758840356863LLU,16383LLU},{18446744073709551615LLU,11001840890607042559LLU,18047359400033013669LLU,3718370644063705513LLU,18446744072053217514LLU,18446744073709551615LLU,16383LLU},{18446737475563878911LLU,16046180336786210815LLU,252078568567734221LLU,9206448353880031232LLU,18064336545237499388LLU,18429609249567932415LLU,16159LLU},{18446743923322236913LLU,3600847804408266751LLU,18228882355835895863LLU,16158053204430487551LLU,18252690849904182015LLU,12393905141382643711LLU,16354LLU},{16140123656689745919LLU,14954202442424631297LLU,11529215046068469759LLU,2292326975806635968LLU,11509511796758953904LLU,6914151271242891646LLU,13279LLU},{17871373545141043199LLU,4467509254377930751LLU,8070450532247928828LLU,17941283185241361663LLU,17181127025268871135LLU,18104470489988300737LLU,15610LLU},{18446735792875239519LLU,14981011662506294319LLU,18446726482572081859LLU,9206448353880047615LLU,17995679371297095164LLU,6340936282369157119LLU,16157LLU},{9106273773614554567LLU,18446464307053993958LLU,17230768600873303644LLU,18446744073706404927LLU,18374418173064642559LLU,18277820604712779759LLU,7871LLU},{14105273964439790523LLU,13842938764013335519LLU,13832814500866113023LLU,18446744069431230451LLU,18411837843702808575LLU,18328102088093982527LLU,11255LLU},{16859172428503317311LLU,18446742422028285695LLU,18446238285509390335LLU,18428730774447440883LLU,16717361710473674751LLU,17536510830030870427LLU,11647LLU},{4538643261970948087LLU,18446743996399668732LLU,18160763195261509631LLU,16717360721579474703LLU,4611672549409685507LLU,4464699318296423662LLU,6127LLU},{16140125843841069055LLU,14087541109391622141LLU,11311353328195076087LLU,18013363690602495LLU,11356096527822750704LLU,1152921480514764158LLU,13287LLU},{18443322462231068511LLU,4611420761044287407LLU,8070450529001536192LLU,9133370413051530495LLU,16753179417391661055LLU,17582052885005074425LLU,15420LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][7] = {{3239900127241961471LLU,18446744073694405887LLU,18430482253542739967LLU,16717292482874831619LLU,4035225262877572099LLU,18445618242521433739LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU}};

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
        A[i][5] = A[i-1][5] & C[i][5];
        A[i][6] = A[i-1][6] & C[i][6];

    } else {
        A[i][0] = A[i-1][0] & D[i][0];
        A[i][1] = A[i-1][1] & D[i][1];
        A[i][2] = A[i-1][2] & D[i][2];
        A[i][3] = A[i-1][3] & D[i][3];
        A[i][4] = A[i-1][4] & D[i][4];
        A[i][5] = A[i-1][5] & D[i][5];
        A[i][6] = A[i-1][6] & D[i][6];

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
    fputs("[[0,1],[0,2],[0,3],[1,4],[1,5],[2,4],[2,6],[3,7],[3,8],[4,9],[5,7],[5,10],[6,10],[6,11],[7,11],[8,12],[8,13],[9,12],[9,13],[10,12],[11,13]]\n", fout);
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
