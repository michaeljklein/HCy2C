#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_518_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][5] = {{18446744073675997185LLU,18428729675200069695LLU,288230376151711743LLU,18446744073709289472LLU,16777215LLU},{576460752303423487LLU,18428729675200069632LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18014398509481983LLU,18158513697557839872LLU,18446744073709551615LLU,16777215LLU},{18446744073675997184LLU,18410715276690587647LLU,141148018509217791LLU,18446744073709289472LLU,16777215LLU},{576460752336977919LLU,18446744073709551552LLU,18446744073709551615LLU,18446739675663302655LLU,16777215LLU},{17870283321406128128LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,15188507427200895LLU,6629298651489304576LLU,18444496671942272357LLU,16777215LLU},{18446743798898753535LLU,18446744073709551615LLU,18158513697557905407LLU,17296074367842910207LLU,16777215LLU},{1729382531788177407LLU,72057594037927872LLU,18446744073709486080LLU,18444492274969608191LLU,16777215LLU},{13743842570641864705LLU,18446744073642442789LLU,288230376151711743LLU,1151997914839515120LLU,16777208LLU},{18446744073675999231LLU,18428729675267178495LLU,18446726550242983935LLU,18379190079298732047LLU,16776199LLU},{18446744056578961403LLU,18433180497463999743LLU,17870283304226324479LLU,1150669704726175711LLU,16761855LLU},{18446735569674305535LLU,72057594037927935LLU,18158513714737709055LLU,17298326151617314815LLU,16531087LLU},{4035234045104226303LLU,18446744073709551552LLU,18446744056529879040LLU,1150674119952695295LLU,16761855LLU},{18446736136609986567LLU,288230376084603903LLU,864708720641179647LLU,17365880147168722928LLU,16531448LLU},{8790920910786660351LLU,18446743798898753503LLU,18446743030029303795LLU,18432087549317479439LLU,15981511LLU},{18446744073676128135LLU,18428729950077715455LLU,1151849480769765375LLU,18176528096067060735LLU,13581375LLU},{4609440745957359615LLU,14987979559889010684LLU,18433233274760593152LLU,14987847356228304895LLU,12317693LLU},{17872535105112113151LLU,18446678103011884995LLU,18446744056596726015LLU,4609570832870526975LLU,7327615LLU},{18446737270481229951LLU,1152921230735835135LLU,18159638566672531455LLU,17568542132682095664LLU,15794121LLU},{18444633010547457951LLU,18428800043944001532LLU,4610828399294807823LLU,15960651320122949631LLU,10450175LLU}};

static uint_fast64_t D[21][5] = {{18254584900491411455LLU,72057594037927935LLU,18379137234021580800LLU,18446739675663302655LLU,16777215LLU},{18254584900491411454LLU,12285819783466713087LLU,18277126102837734058LLU,18446744073709551615LLU,16777215LLU},{768619925521563649LLU,18436147420244370816LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{576460752303423487LLU,6196953087261802432LLU,18401672847250904405LLU,18446739675663302655LLU,16777215LLU},{18446744073709551615LLU,18385283133136804479LLU,67606839687970815LLU,18446744073709289472LLU,16777215LLU},{17870283321406128127LLU,6171520943708019327LLU,18328131668429657429LLU,18446744073709551615LLU,16777215LLU},{17293822294238252371LLU,18437560365785511423LLU,18446744073709551615LLU,17296074367842910207LLU,16777215LLU},{1921541430182064813LLU,18442505237086129920LLU,6629298651489370111LLU,18444496671942272357LLU,16777215LLU},{18446744073689451859LLU,18432968511823491327LLU,11885052261908152319LLU,17296074368916232858LLU,16777215LLU},{18300200586957553663LLU,18230571291595767807LLU,18446726485601369283LLU,18379187501138444287LLU,16776199LLU},{13698226884175724543LLU,288230376151711717LLU,18379137298663195452LLU,1151996094953816063LLU,16777208LLU},{16140892543276202671LLU,71209651475894271LLU,6917529027641081855LLU,18446739659556877685LLU,16531087LLU},{4227384714260375545LLU,18429789603402611712LLU,17582052945254416383LLU,1150678500885974991LLU,16761855LLU},{18446744073702742023LLU,18445684145507009535LLU,932297968143302655LLU,17298326168730021936LLU,16531087LLU},{8783743297511745535LLU,18429789603402612698LLU,18446744060607544515LLU,18445422082736312271LLU,16761207LLU},{18418032489529343879LLU,17582052945254155253LLU,1151813196030407487LLU,11312689730746843135LLU,13582334LLU},{4071115305433169919LLU,1152921504606846927LLU,18379190063188873200LLU,8068731930292781055LLU,15981561LLU},{18446744073707485671LLU,18446673722082313215LLU,14771591548374089727LLU,17771204129603961075LLU,7192351LLU},{18446741805960502815LLU,14986924012616040447LLU,4593939694596653055LLU,17973866108272197436LLU,12222189LLU},{18410856010125672447LLU,18429789604409245680LLU,18446744072640000015LLU,11528686249679048703LLU,13624703LLU},{17906307570054625791LLU,4611685760666435535LLU,18176527255327412223LLU,8636211927724326131LLU,7725019LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][5] = {{18254584900491411455LLU,72057594037927935LLU,18379137234021580800LLU,18446739675663302655LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,4],[3,6],[4,7],[5,8],[5,9],[6,7],[6,8],[7,10],[8,11],[9,11],[9,12],[10,12],[10,13],[11,13],[12,13]]\n", fout);
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
