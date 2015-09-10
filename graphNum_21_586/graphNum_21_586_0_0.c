#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_586_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][5] = {{18446744073675997185LLU,1048575LLU,18446744073709551600LLU,18446673704969568255LLU,288230376151711743LLU},{18446744073709551615LLU,3LLU,18446744073709551600LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,15LLU,18446744073705357312LLU,288230376151711743LLU},{18446744073675997184LLU,18446744073709551615LLU,6878542363954773983LLU,18446673704969000925LLU,288230376151711743LLU},{33554431LLU,18446744073708503044LLU,18446744073709551615LLU,70368744177663LLU,288230376151711680LLU},{0LLU,18446744073709551612LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,15562142160955375615LLU,18446744072635809797LLU,18446684530929565695LLU,288230376147517503LLU},{18446743798898753535LLU,18446744073709551615LLU,1073741823LLU,18158584066297823232LLU,288230101277999103LLU},{274877906943LLU,18446744073708503052LLU,18446744072635809855LLU,288230376151711743LLU,288230376147517440LLU},{18419511369712787457LLU,18446726481524542719LLU,1151865973444182015LLU,18446744056533876735LLU,288226249560503295LLU},{14987977910588022783LLU,17592185847759LLU,18446744009285042160LLU,18446673722145227775LLU,288164353901068095LLU},{18374123525490294783LLU,18445688542546886655LLU,18158513698628386815LLU,13830624721319755775LLU,287733395826409469LLU},{9223367368225325043LLU,18446744073646637055LLU,288230375950384383LLU,17586556544852426752LLU,284289177795690479LLU},{18442240739293265919LLU,14123288431433871375LLU,18433233274827178047LLU,278090679920361459LLU,274139035130118207LLU},{4503530773675263LLU,18446743816010469372LLU,18446743248002351103LLU,18374545740572459007LLU,234115712363282368LLU},{4584420329053486977LLU,14123288427139157052LLU,18446744072702914800LLU,16717302442907140095LLU,209979507989229775LLU},{18446743867148017791LLU,18378116960245252095LLU,1151848449977614335LLU,18230148134502154239LLU,125886175167643647LLU},{14443323830685926655LLU,18374687321484964815LLU,18446744073693577215LLU,4611684921600114687LLU,125876489193312057LLU},{18446744044685492115LLU,72057589948481535LLU,18159639533040173040LLU,18416275506765742848LLU,209927490825617407LLU},{18428562545655676815LLU,14987979555660619132LLU,18158531288938574835LLU,17289842336775274495LLU,211387156745123295LLU},{18442275520746578943LLU,18391839135942832383LLU,4610825100822581247LLU,2161445712649519103LLU,134964912555279359LLU}};

static uint_fast64_t D[21][5] = {{8279247240673886207LLU,18446744073709551613LLU,17352302564632166463LLU,70368740834355LLU,288230376151711680LLU},{8279247240673886206LLU,18446744073709551613LLU,6513728527595645599LLU,18446744073707869849LLU,288230376151711743LLU},{10167496833035665409LLU,7591215647613255686LLU,18446744073709551610LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073708503043LLU,17717116400991294847LLU,70368741948791LLU,288230376151711680LLU},{18446744073709551615LLU,10855528426096295935LLU,1094441509077385157LLU,18446673704968717260LLU,288230376151711743LLU},{18446744073709551615LLU,10855528426096295931LLU,11933015546113906021LLU,18446744073707039078LLU,288230376151711743LLU},{18446743798860036883LLU,9033516603991392247LLU,18446744073709551615LLU,18158584066302017535LLU,288230101277999103LLU},{10167496833074382061LLU,14119841204577239054LLU,18446744073709551600LLU,18446684530929565695LLU,288230376147517503LLU},{18446744073704389395LLU,4326902869132312575LLU,1094441509077385215LLU,18446733247748703180LLU,288230101277999103LLU},{14048414100065615871LLU,18446744073709354959LLU,18217060425001615167LLU,4256957179027767347LLU,288164353901068081LLU},{9191578347233083391LLU,18446744073709538557LLU,287108048650223871LLU,14189857263422603263LLU,288226249560503246LLU},{2151516656641175025LLU,17578661845169432223LLU,18446744073508224252LLU,17870263383064838143LLU,284289451598125679LLU},{17166727271250073327LLU,14986867901891778926LLU,18446744073706356723LLU,13835018347739086847LLU,287733396893492669LLU},{18446744004851514423LLU,4597963839458246655LLU,14933724175796273151LLU,18374536634822299599LLU,234115598995423231LLU},{18446744064041909211LLU,13852227203409903615LLU,4593949783474831359LLU,18436602657267512304LLU,274138873628459007LLU},{18083641112764432383LLU,18378134548136329215LLU,18446726482581274623LLU,4358990930368266495LLU,125876231433355257LLU},{576425813789900799LLU,14123288431432892172LLU,18217060491656687664LLU,16398672769534918451LLU,209927556064082951LLU},{9223350012799352723LLU,18446744069620105213LLU,17591179407615LLU,16681895969507245824LLU,209979490879668175LLU},{17870318299217126655LLU,18446727323337031935LLU,18446730054919524351LLU,2089248000135987199LLU,125886384798696440LLU},{15705176460517502463LLU,18375798979280336863LLU,18446744073696772095LLU,8971169485981483263LLU,123839935960964987LLU},{576460732946710455LLU,4611686015154847740LLU,18176528043470749680LLU,18426416302584221455LLU,178982857317023687LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][5] = {{8279247240673886207LLU,18446744073709551613LLU,17352302564632166463LLU,70368740834355LLU,288230376151711680LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,4],[3,6],[4,7],[5,8],[5,9],[6,10],[6,11],[7,12],[7,13],[8,10],[8,12],[9,11],[9,13],[10,11],[12,13]]\n", fout);
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
