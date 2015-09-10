#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_593_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][6] = {{18446744065119617025LLU,1073741823LLU,18446744072635809792LLU,288230376151711743LLU,18446744073642442752LLU,4294967295LLU},{18446744073709551615LLU,32767LLU,18446744072635809792LLU,18446744073709551615LLU,18446744073709551615LLU,4294967295LLU},{18446744073709551615LLU,18446744073709551615LLU,1073741823LLU,18158513697557839872LLU,18446744073709551615LLU,4294967295LLU},{18446744065119617024LLU,18446744073709551615LLU,18264348286653562879LLU,276829943810219869LLU,18446744073642442752LLU,4294967295LLU},{8589934591LLU,18446744072635842560LLU,18446744073709551615LLU,18446744073709551615LLU,18158513697624948735LLU,4294967295LLU},{0LLU,18446744073709518848LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4294967295LLU},{144115188075855871LLU,18408462892761350142LLU,1064828791LLU,12682136550675312640LLU,287108874286116783LLU,4294967294LLU},{18446739692842909695LLU,8646761748822491135LLU,18446744073575299071LLU,17870283321406132223LLU,18446744056579685114LLU,4294967041LLU},{18374686486914117551LLU,18293619349908422655LLU,18446744073673899487LLU,18446744072635826175LLU,18446739675730149375LLU,4294951165LLU},{72057589658745595LLU,16140302920515026944LLU,18446462602490798077LLU,18446744073709551615LLU,17870287719452639231LLU,4293935103LLU},{18445618173802577921LLU,13835058056220638719LLU,18446744073709551615LLU,288019269919178748LLU,13835058055282162688LLU,4287494111LLU},{18446735269026725887LLU,4611686018410479611LLU,18443366372915281920LLU,18446744060824649727LLU,17870283321339020287LLU,4236230395LLU},{72061992084439039LLU,18446744073701294078LLU,281474976710655LLU,18446744072635822080LLU,575334869576450047LLU,4294951166LLU},{18446739692842909695LLU,18446744072652554241LLU,18446462603027808255LLU,18158513698631581695LLU,18159639580351922175LLU,4293934851LLU},{18122429890597748225LLU,18446673706005282790LLU,18378978921526853631LLU,72057335534384127LLU,17146881593059573756LLU,4092558839LLU},{18441114574141784575LLU,70368338376191LLU,18446744073709535232LLU,18443155267756490700LLU,4611686018427125763LLU,3482970015LLU},{18446700084688059905LLU,18446673705988390891LLU,18389323177386852351LLU,288230157108379647LLU,16717361816732434428LLU,4043259123LLU},{16284454401727266791LLU,18446743816010571775LLU,13835075647464275967LLU,14717763582242603007LLU,14195279784188051455LLU,3137337599LLU},{2234348158969178111LLU,18429855575099572030LLU,4611684987635236803LLU,18446727579965583360LLU,4597115564408688591LLU,1876936702LLU},{9169328577185840767LLU,18446678102894444288LLU,18446742977486258175LLU,18446726481590612223LLU,18429007850584932348LLU,1979596771LLU},{16716935481140346879LLU,14123288430494318847LLU,14123008055968777215LLU,18158531289739952127LLU,18176475097244433663LLU,2679242527LLU}};

static uint_fast64_t D[21][6] = {{86808659216039935LLU,18446744073709525556LLU,273593681657724927LLU,18175614346070077683LLU,18158513697624948735LLU,4294967295LLU},{86808659216039934LLU,18446744073709525556LLU,12206631489302953983LLU,18344967065488235097LLU,18446744073709551615LLU,4294967295LLU},{18359935414493511681LLU,11068046443796293067LLU,18446744073065306521LLU,18446744073709551615LLU,18446744073709551615LLU,4294967295LLU},{18446744073709551615LLU,18446744072635842559LLU,6331310479008333823LLU,18265990921949902327LLU,18158513697624948735LLU,4294967295LLU},{18446744073709551615LLU,7378697629913317375LLU,18173150392696071782LLU,271129727639473932LLU,18446744073642442752LLU,4294967295LLU},{18446744073709551615LLU,7378697629913284607LLU,6240112585050842726LLU,18260290705779156390LLU,18446744073709551615LLU,4294967295LLU},{18446739680715943213LLU,3593645861529118155LLU,18446744073472520671LLU,18158513697557839871LLU,18446744056579685114LLU,4294967041LLU},{57306540986782419LLU,16082881150141464574LLU,18446744073159171889LLU,12682136550675316735LLU,287108874286116783LLU,4294967294LLU},{18446744069330369275LLU,14948801164567642111LLU,18446462598992154484LLU,12088575149859667967LLU,18158513697518364069LLU,4293935103LLU},{18446744072362110895LLU,8417074663133282303LLU,18173150396159063247LLU,6629298650415632140LLU,18446744073681918554LLU,4294951165LLU},{3294086654419009535LLU,18446744073692633977LLU,14983690627022061567LLU,18391843242750459123LLU,17751600225371291647LLU,4236230395LLU},{15238331382506717183LLU,18446744073574268086LLU,3733269428624687103LLU,18230304057911735292LLU,13665510775232397311LLU,4287494111LLU},{18446744067140778105LLU,287108857128281547LLU,18446744072702657532LLU,17564952296742191103LLU,18446744073658233072LLU,4293934851LLU},{18431993023690147719LLU,18159635216589783039LLU,18173150396279946243LLU,1152921504606846732LLU,576460752287633167LLU,4294951166LLU},{12675098989029359615LLU,4611686018156852095LLU,14987965541115740160LLU,18442508754865881027LLU,9178159428841243647LLU,3481006015LLU},{8736913956326604799LLU,18446744073658802144LLU,18374704007433158655LLU,18176527821256274175LLU,16496950352734584831LLU,4043259123LLU},{9790965296599662591LLU,18446744073303748671LLU,288212852685144063LLU,18442241573526962112LLU,4543867106407481343LLU,3482970015LLU},{18446743861106696319LLU,4593676017494652191LLU,18446743041910767552LLU,18443137950448353279LLU,18433233273971786688LLU,1876492175LLU},{18446740774646087649LLU,14123288157042479083LLU,18446480190914692095LLU,13839561435866202111LLU,18230571278706736383LLU,3136765811LLU},{16711239735621591015LLU,13853072196089937919LLU,13907115649316143167LLU,14987979559885078476LLU,2305790026493738047LLU,2680153087LLU},{9160277653551834655LLU,18429785481236054014LLU,18389323177391030211LLU,4611686017420750911LLU,16716514093271338956LLU,1979702526LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][6] = {{86808659216039935LLU,18446744073709525556LLU,273593681657724927LLU,18175614346070077683LLU,18158513697624948735LLU,4294967295LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4294967295LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4294967295LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4294967295LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4294967295LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4294967295LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4294967295LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4294967295LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4294967295LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4294967295LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4294967295LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4294967295LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4294967295LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4294967295LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4294967295LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4294967295LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4294967295LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4294967295LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4294967295LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4294967295LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4294967295LLU}};

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

    } else {
        A[i][0] = A[i-1][0] & D[i][0];
        A[i][1] = A[i-1][1] & D[i][1];
        A[i][2] = A[i-1][2] & D[i][2];
        A[i][3] = A[i-1][3] & D[i][3];
        A[i][4] = A[i-1][4] & D[i][4];
        A[i][5] = A[i-1][5] & D[i][5];

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,6],[3,7],[4,6],[4,7],[5,8],[5,9],[6,10],[7,11],[8,9],[8,12],[9,13],[10,12],[10,13],[11,12],[11,13]]\n", fout);
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
