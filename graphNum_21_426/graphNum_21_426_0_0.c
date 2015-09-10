#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_426_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][5] = {{18446744071562067969LLU,17293822569102704640LLU,288230376151711743LLU,18446744073692774400LLU,17179869183LLU},{4611686018427387903LLU,17293822569102704640LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,1152921504606846975LLU,18158513697557839872LLU,18446744073709551615LLU,17179869183LLU},{18446744071562067968LLU,16140901064495857663LLU,288230376151711743LLU,18446744073692774400LLU,17179869183LLU},{4611686020574871551LLU,18446744073709551615LLU,18446744073709551615LLU,18428729675216846847LLU,17179869183LLU},{13835058055282163712LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{13835058059577131007LLU,4611686018427387903LLU,18158513697557839872LLU,18428729675216846847LLU,17179869183LLU},{18446744073709486081LLU,18446744072635809792LLU,288230376151711743LLU,13853072453791645184LLU,17179869183LLU},{18446744071562133503LLU,17293822570176446463LLU,18446744073709551615LLU,4611686018410611199LLU,17179869120LLU},{18446673709260341247LLU,4611686018427387903LLU,18446744073642442752LLU,17870283046544998399LLU,17179861045LLU},{13835128424026341375LLU,18446744073709551615LLU,18158513697624948735LLU,9097271522166308863LLU,17178828799LLU},{16095688588015959553LLU,18446744073709486080LLU,72001518089261052LLU,18419545864709079036LLU,17164074815LLU},{18446744073701163519LLU,18446726481523572735LLU,18446744073709551615LLU,13871086852301062147LLU,16927930367LLU},{18446744071570456065LLU,17293840161288683520LLU,288230376151711743LLU,9223372036838064124LLU,17164074752LLU},{14986923758126628859LLU,4611474912194854899LLU,17600067326651137024LLU,18433229150601740287LLU,16369318948LLU},{18230501196655358719LLU,17582052880825925631LLU,18445688542479778815LLU,17437093058435871717LLU,13908304895LLU},{18428799992135147455LLU,18392700053497050111LLU,9223367638875373507LLU,17257723678014037951LLU,12545105903LLU},{13853068330555932655LLU,18443366373989023551LLU,15852675086390395903LLU,8989255208869036031LLU,7496335355LLU},{18445899391056678907LLU,18446515442940903411LLU,17870283305299999747LLU,14411515508043877919LLU,16173233407LLU},{14987979559756840929LLU,18442241572587175680LLU,13853072453791645695LLU,9209861237971631743LLU,8049327544LLU},{18433180496255776287LLU,17298326117187256575LLU,4611681895195869183LLU,18446691090977257452LLU,10724798279LLU}};

static uint_fast64_t D[21][5] = {{13835058059577131007LLU,4611686018427387903LLU,18158513697557839872LLU,18428729675216846847LLU,17179869183LLU},{13835058059577131006LLU,11529215046068469759LLU,18350667281658981034LLU,18446744073709551615LLU,17179869183LLU},{9223372032559808513LLU,18062436905507269290LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{4611686018427387903LLU,9223372036854775807LLU,18254590489608410453LLU,18428729675216846847LLU,17179869183LLU},{18446744073709551615LLU,14219365223484446037LLU,288230376151711743LLU,18446744073692774400LLU,17179869183LLU},{13835058055282163711LLU,7301836195843364181LLU,18254590489608410453LLU,18446744073709551615LLU,17179869183LLU},{18446744071562067969LLU,17293822569102704640LLU,288230376151711743LLU,18446744073692774400LLU,17179869183LLU},{16547814473801400319LLU,4611686018427387903LLU,18378331416335020239LLU,4604268324677746687LLU,17179869120LLU},{15733987659485282303LLU,18446744073709551615LLU,18226926354932371248LLU,13842475749048582143LLU,17179869183LLU},{18446744072825511213LLU,18173093493146960700LLU,6629298651489370111LLU,9115285645790977338LLU,17178828799LLU},{18446744072446108371LLU,17567473149665295555LLU,12105675798371893247LLU,17870283321396257477LLU,17179861045LLU},{17723342216639873023LLU,18446726482597249023LLU,18432388630850632911LLU,13832232266777952767LLU,16927930367LLU},{14920160845169164287LLU,4611686018427387903LLU,18176458001131488252LLU,9209596321118289919LLU,17164074752LLU},{17361641288117518335LLU,18446744073709551615LLU,18428799770135903235LLU,13866848169544908799LLU,16927930367LLU},{18230571289917583471LLU,17362502395770179391LLU,16139845533333192703LLU,17905467693481849312LLU,13907869695LLU},{14986924028429574073LLU,18392432871970173936LLU,8088464913644650495LLU,9209857114801741631LLU,16368721902LLU},{18446739949362182887LLU,17577817612773179151LLU,14987979559888749567LLU,18302628869518359285LLU,7497316793LLU},{18446744021748664219LLU,18378977890668638451LLU,4035225266123964355LLU,16717361816594663311LLU,12545156711LLU},{18162963694315634287LLU,17362502463420043071LLU,16139775439403992063LLU,9222263519741214716LLU,13947928539LLU},{18213616770755590143LLU,18446744022166798335LLU,18445684161613397955LLU,16392191990101440495LLU,10636699647LLU},{14122440501804089343LLU,18446727580028502015LLU,18159639581358308415LLU,15907836471554293375LLU,7901281791LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][5] = {{13835058059577131007LLU,4611686018427387903LLU,18158513697557839872LLU,18428729675216846847LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,3],[2,4],[3,5],[4,6],[4,7],[5,8],[5,9],[6,7],[6,10],[7,11],[8,10],[8,12],[9,12],[9,13],[10,13],[11,12],[11,13]]\n", fout);
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
