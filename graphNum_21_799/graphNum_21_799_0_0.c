#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_799_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][7] = {{137438953471LLU,18446735277884964864LLU,141863388261777407LLU,18446744073709551614LLU,18014398509457407LLU,18446744073709289472LLU,1023LLU},{18446744073709551615LLU,268435455LLU,18374686479671623680LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU,0LLU,18446744073642442752LLU,18446744073709551615LLU,1023LLU},{18446743936270598144LLU,18446744073709551615LLU,18410700982216293311LLU,17509991362665641983LLU,18428729675233099231LLU,18446744073709551615LLU,1023LLU},{0LLU,18446744073441116160LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{16137237491752108031LLU,132118521LLU,18446744073709551614LLU,9216044848375488511LLU,14735777980745777137LLU,18446744069414692074LLU,1023LLU},{17870283321406095361LLU,18446744073708765183LLU,18374686479671623681LLU,18446744073709550595LLU,18446742974264836095LLU,18446673709260341247LLU,1023LLU},{9214362913454686207LLU,18446744073667607791LLU,63015098670645219LLU,18446743798831644672LLU,13708957231154724863LLU,18437765801059450455LLU,1023LLU},{18302628885625372671LLU,18444509866081812479LLU,18446181123756081151LLU,274877906943LLU,18446604157566582784LLU,17302829768324147198LLU,1023LLU},{16137237354313187327LLU,8795956705273LLU,18410700982216293310LLU,17865776423243874303LLU,18428730774711697395LLU,18446744069414846463LLU,1023LLU},{128721086431LLU,16127390197431140351LLU,16282500569960939519LLU,18446744073709490175LLU,18014398506328063LLU,1150445335592566768LLU,1023LLU},{18446744039349616251LLU,18446735346067570688LLU,2305842993107304063LLU,18445622558964318206LLU,18446744073709535039LLU,18275606453571026959LLU,1008LLU},{17802729326660026241LLU,18383658275510681479LLU,18446744073575333889LLU,18311583308329516995LLU,4611402327314661375LLU,13789599575960453023LLU,974LLU},{18446717672545550463LLU,14122864018858704895LLU,18374686479805841407LLU,18446744072702917695LLU,18155108527226286095LLU,16858029211288305663LLU,827LLU},{18444490487197859839LLU,2251799813684731LLU,18446735208360181734LLU,17865776148365968383LLU,18320783987070468083LLU,18437807238937575167LLU,1023LLU},{18446743970629353459LLU,9187220094332141567LLU,18392137928227627038LLU,1072954866LLU,18432943274609082367LLU,18311636055893342207LLU,742LLU},{18302068133605665791LLU,18444632458407101439LLU,13402499323237761023LLU,18446744073696956287LLU,16284884242389794816LLU,13979162247910386174LLU,447LLU},{562881130397687LLU,18437631256712675327LLU,16717361816799240702LLU,1125642208755702LLU,2296829210201677823LLU,4503458870476011504LLU,751LLU},{18446321275111407551LLU,18175401165368311808LLU,11240984669790666735LLU,18446676990598643679LLU,17256878969622347767LLU,18436892310592288783LLU,476LLU},{72031205758180979LLU,18446736324246388735LLU,7998674397080577663LLU,1151865973444181502LLU,18158512872924115775LLU,17924272889970034672LLU,627LLU},{18392173112593476495LLU,18445019341545000863LLU,18158300529606795263LLU,18311583308330303311LLU,7493881942912274431LLU,10907707061831728063LLU,479LLU}};

static uint_fast64_t D[21][7] = {{18446744073709551615LLU,7669647757597999103LLU,18392120816111663494LLU,17325343432935469059LLU,18428729675215862979LLU,18446744073709551615LLU,1023LLU},{7592273093712740350LLU,18446744073599211694LLU,144115188075855871LLU,10572860220228675580LLU,18446744073670169950LLU,18446744073709551615LLU,1023LLU},{10854470979996811265LLU,10777096316490327889LLU,18403575986844717885LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446735277884964863LLU,59496453155385083LLU,8058531783211048958LLU,18014398498966461LLU,18446744073709289472LLU,1023LLU},{18446744073709551615LLU,7669647757329563647LLU,18345796972498529474LLU,7873883853480876035LLU,18446744073681824417LLU,18446744073709551615LLU,1023LLU},{8313556676317773824LLU,18446744073666682543LLU,18446744073709551615LLU,15762422083920327681LLU,18446742974230721887LLU,18446673709260341247LLU,1023LLU},{14839493156843618303LLU,18446744073504977400LLU,144115188075855871LLU,4026482984683835390LLU,14735777980740509680LLU,18446744069414692074LLU,1023LLU},{15905258130469047139LLU,18444499254155028445LLU,18409794846659121983LLU,18446744073709551615LLU,18446604157633691647LLU,17302829768324147198LLU,1023LLU},{4019460574898271389LLU,10777106928375168099LLU,18430919768574394337LLU,18446744073709551615LLU,13708957231154724863LLU,18437765801059450455LLU,1023LLU},{8313556676317806591LLU,18446744073666682543LLU,59496453155385083LLU,14960694079334120448LLU,3728980491462509375LLU,18446673709260233493LLU,1023LLU},{18446744039349616251LLU,8825771040064929791LLU,18392137911156850191LLU,18445618432369229211LLU,18440189032966061831LLU,18275606453571289087LLU,1008LLU},{18446744064991684575LLU,14971266983146815487LLU,18446463079761279478LLU,17325347559530496615LLU,18435284715956206843LLU,1150445335592566783LLU,1023LLU},{14843830270828085247LLU,14122864018856014335LLU,3314649325744685055LLU,4034378641101017087LLU,17938936827444457472LLU,16858099304308878586LLU,827LLU},{18374826563815014399LLU,18383658275309584256LLU,15276209936040722431LLU,18303687650905702398LLU,1116609033572163583LLU,13789599843094230927LLU,974LLU},{17311705026216840035LLU,18446742258011082655LLU,18442310427287750271LLU,14960694079334121471LLU,8358680630300246847LLU,17302800846047658940LLU,1023LLU},{18446181246674395551LLU,15415818497061011583LLU,13400194626499510271LLU,18446744073696956287LLU,16158915359926124543LLU,14983951842336012415LLU,447LLU},{4019462546833522417LLU,4548631117971587043LLU,18379181269784190976LLU,18446743799904599538LLU,13821265230660894719LLU,18441782494203019223LLU,742LLU},{18446744067803969599LLU,17364610502075334783LLU,13835055856267034607LLU,18446744073492496159LLU,18444975929978453767LLU,18300935774897404031LLU,441LLU},{72031197168371703LLU,14987627663554772991LLU,17221767174087991806LLU,144114981112118519LLU,18147231743499694335LLU,7707844774364970992LLU,639LLU},{18446321309343285151LLU,18159041463139172351LLU,18158511979437228007LLU,18334152983496885071LLU,17256700741293441011LLU,11528159308218892287LLU,479LLU},{1150668469989392127LLU,288223744454819323LLU,8002887728322576382LLU,4034378367309446654LLU,18357797431313170431LLU,18438827036472786675LLU,627LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][7] = {{18446744073709551615LLU,7669647757597999103LLU,18392120816111663494LLU,17325343432935469059LLU,18428729675215862979LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,4],[1,5],[2,4],[2,6],[3,7],[3,8],[4,7],[5,9],[5,10],[6,11],[6,12],[7,13],[8,9],[8,11],[9,12],[10,12],[10,13],[11,13]]\n", fout);
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

