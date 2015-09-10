#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_513_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][5] = {{9223372045444710399LLU,18446744073709486081LLU,18446744072635809792LLU,8796093022207LLU,4503599627369984LLU},{9223372036854775807LLU,13835058055282163712LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,4611686018427387903LLU,0LLU,18446744073709547520LLU,4503599627370495LLU},{18446744073692774400LLU,9223372036854775807LLU,15984917017765347327LLU,18446744039349815255LLU,4503599627370495LLU},{9223372036871553023LLU,18446744073709486080LLU,18446744073709551615LLU,18158513731917578239LLU,4503599627370495LLU},{18446744073692774401LLU,13835058055282229247LLU,18446744073709551615LLU,18446744039349817343LLU,4503599627370495LLU},{18446744073709551615LLU,3890403504388177919LLU,18446744072635809792LLU,288230362834792447LLU,4503599627369984LLU},{18446744065153171455LLU,18446744073709551615LLU,1073741823LLU,18446735311976263680LLU,4503599610593791LLU},{9223372036854775808LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{16987274312052374529LLU,18446744056529720989LLU,18446744073709551615LLU,4323455642273583103LLU,4503597496663853LLU},{18446744073692775423LLU,13835058072462032895LLU,18446673709260341247LLU,18446744039351910399LLU,4503326896882175LLU},{18446744065186724867LLU,18446744056529944575LLU,70368744177663LLU,18446735346333913088LLU,4503597479952383LLU},{18446603342527332351LLU,18230571291595767553LLU,18392700878181089280LLU,287110931580714815LLU,4499407168864254LLU},{9223512773806254079LLU,18446743042917335295LLU,4611686017353662463LLU,18159639047696285695LLU,4437622353034753LLU},{18445055223849157107LLU,18446462603023875583LLU,18442521678475755519LLU,18444492273628451839LLU,4270470941438459LLU},{11529214530655747967LLU,13835339529453535219LLU,18446673979037974467LLU,16573193818073726963LLU,3658109543190271LLU},{18014391911942438851LLU,18446730879503163359LLU,17293892886256942335LLU,13798888039704829951LLU,3288639160253375LLU},{18419722467891477567LLU,18429855557994149887LLU,1152917381435097087LLU,18437728626505019392LLU,1961251837038575LLU},{18444915036114526199LLU,18230290916127538447LLU,18443366116290773055LLU,2302535673690701823LLU,4289100370539514LLU},{18410724067951703551LLU,18446532748433682495LLU,4611686018423194623LLU,9205634165380215039LLU,2097847642095584LLU},{9259400421275856863LLU,14123287606749761527LLU,17365827385512951759LLU,17023571106432221183LLU,2761831407386143LLU}};

static uint_fast64_t D[21][5] = {{18446744073699276803LLU,14916981826341044223LLU,14754003489793245183LLU,18446744052666733507LLU,4503599610593791LLU},{13027564260471865342LLU,9223372036854775807LLU,11066915854500932266LLU,18446744073709549206LLU,4503599627370495LLU},{14642551850092462081LLU,15732927985110876160LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{9223372036854775807LLU,18446744073709486080LLU,8610741747180721493LLU,18158513731917577597LLU,4503599627370495LLU},{18446744073709551615LLU,2713816088598675455LLU,14754003489793245183LLU,18446744039349814211LLU,4503599627370495LLU},{13027564260471865343LLU,18446744073709551615LLU,3692740583916306432LLU,18158513731917577276LLU,4503599627370495LLU},{18446744065126119427LLU,16093569242130546686LLU,18446744073709551615LLU,18446735311976267775LLU,4503599610593791LLU},{14642551850119514109LLU,17364820302650671105LLU,18446744073709551615LLU,288230362834792447LLU,4503599627369984LLU},{9223372036854775807LLU,11937188125453451263LLU,7379828219208619349LLU,18446744073709549929LLU,4503599627370495LLU},{13757299149823279103LLU,18446744073709551615LLU,18446673705220230915LLU,18277172958067687423LLU,4503326896882175LLU},{16257539422700961791LLU,18446744073709524637LLU,3692740587956416764LLU,4204796416125566012LLU,4503597496663853LLU},{11412576687923972095LLU,17364820302650894691LLU,18446744072890666755LLU,14241947712986546175LLU,4503326896946898LLU},{18446744073164022171LLU,14984600764699377663LLU,935850683486175231LLU,18446743506221061119LLU,4437622342970879LLU},{18446744071424130663LLU,18162951322445283327LLU,18375795629206011903LLU,18446741729629650691LLU,4499407162151935LLU},{9772810646604218239LLU,18446744072904194033LLU,17528009748716191680LLU,16203886175775883056LLU,3658349155450479LLU},{18012254456908873203LLU,18446744060820708511LLU,4607252787493613823LLU,4571852292699951359LLU,4270501928959929LLU},{11495332392666724351LLU,18428799837785781115LLU,18446739949731696627LLU,17712076790291234815LLU,1961200178941670LLU},{17904614609904439295LLU,17365862845832482247LLU,18446744022106831887LLU,10319752242571247615LLU,3288420235344795LLU},{9772811189506277151LLU,14984601859111467007LLU,72003991836295167LLU,18221562150478479344LLU,3615193758658159LLU},{18446743660974292815LLU,13853059258783891447LLU,17298260146492800975LLU,17293786940167585779LLU,2812894237637631LLU},{18446612125871144183LLU,18432969375927500607LLU,18443362869295694847LLU,9222521013578215439LLU,2108569620961278LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][5] = {{18446744073699276803LLU,14916981826341044223LLU,14754003489793245183LLU,18446744052666733507LLU,4503599610593791LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,4],[3,6],[4,7],[5,6],[5,8],[6,9],[7,10],[7,11],[8,10],[8,12],[9,12],[9,13],[10,13],[11,12],[11,13]]\n", fout);
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
