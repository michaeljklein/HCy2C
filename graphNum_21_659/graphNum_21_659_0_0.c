#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_659_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][6] = {{18446744071562067969LLU,4294967295LLU,18446744073441116160LLU,288230376151711743LLU,18446744073692774400LLU,17179869183LLU},{18446744073709551615LLU,16383LLU,18446744073441116160LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,268435455LLU,18158513697557839872LLU,18446744073709551615LLU,17179869183LLU},{18446744071562067968LLU,18446744073709551615LLU,15528270777148243967LLU,279037771069257183LLU,18446744073692774400LLU,17179869183LLU},{2147483647LLU,18446744069414600704LLU,18446744073709551615LLU,18446744073709551615LLU,18428729675216846847LLU,17179869183LLU},{0LLU,18446744073709535232LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{17906312118425092095LLU,6916666941805428735LLU,234745854LLU,8646911284551351296LLU,17997905830541561LLU,17179869183LLU},{18446742978492891135LLU,18410714177178958335LLU,18446744073707454399LLU,15852670688344146943LLU,18443366369709776863LLU,17179868160LLU},{18428729676246399737LLU,17867961127074299903LLU,18446744073575283707LLU,18446744073708507135LLU,18446742974214701055LLU,17179804078LLU},{18014398239989695LLU,18302624483296395264LLU,18446673706030726911LLU,18442521949058891775LLU,18158514797069467647LLU,17175740415LLU},{18444492273895800833LLU,13835058059374755815LLU,18446744073709551615LLU,288230376139128783LLU,13799029258263199232LLU,17149968381LLU},{17293804974769242111LLU,4611686018418868223LLU,18392700877912670208LLU,18446743042917400575LLU,17870283321389351423LLU,16944920527LLU},{17888298819410460667LLU,18446181106572132351LLU,70368744144894LLU,18446744073708506112LLU,288212788260633595LLU,17179804671LLU},{18446737411141137151LLU,18393720125460054015LLU,18442310842622934945LLU,16140901047315988687LLU,18446744060563539910LLU,16366124016LLU},{575615296514031599LLU,18446743661333969404LLU,4611685744622436351LLU,17005592210130862076LLU,18443102281012871167LLU,13891075087LLU},{18446737412215011327LLU,18433233270599565315LLU,18442451855192621031LLU,18442521931880071167LLU,18176809557907468271LLU,16362504177LLU},{11456488777162161665LLU,18446603340499115007LLU,17365827373697597439LLU,288161094034210812LLU,17282526014169153534LLU,11806830399LLU},{18435485074632737279LLU,140736478576423LLU,18446744073709543424LLU,18446744073495641295LLU,4503599627370364929LLU,8294711289LLU},{12682048587605999105LLU,18446603340490604543LLU,17528009749457543167LLU,288163374661894143LLU,16717361816782635006LLU,11609630479LLU},{18338517991508934267LLU,18446612112986392575LLU,17293826966897524735LLU,9223372020748587007LLU,16271502090516299774LLU,12213806079LLU},{17996524023820795903LLU,14122725481476784124LLU,1152921246908801534LLU,18163017297184226304LLU,2305617674828151419LLU,6425615871LLU}};

static uint_fast64_t D[21][6] = {{15017482759692091391LLU,18446744073709537752LLU,4377709945110396927LLU,18172302605181521712LLU,18428729675216846847LLU,17179869183LLU},{15017482759692091390LLU,18446744073709537752LLU,10838592734281859071LLU,18346070979117753754LLU,18446744073709551615LLU,17179869183LLU},{3429261314017460225LLU,11936565760354186791LLU,18446744073548739283LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744069414600703LLU,9067387987976781823LLU,18263783094690865013LLU,18428729675216846847LLU,17179869183LLU},{18446744073709551615LLU,6510178313355395071LLU,14069034128759967020LLU,274441468528029903LLU,18446744073692774400LLU,17179869183LLU},{18446744073709551615LLU,6510178313355378687LLU,7608151339588504876LLU,18259186792149637733LLU,18446744073709551615LLU,17179869183LLU},{3458763415169901261LLU,17809412560592533615LLU,18446744073571908499LLU,16140901064495857663LLU,18443366369709776863LLU,17179868160LLU},{17876808922055990579LLU,1007790245036488631LLU,18446744073650595582LLU,8646911284551352319LLU,17997905830541561LLU,17179869183LLU},{18446744073440059327LLU,6692043038442651647LLU,18446673705187012207LLU,2877816928422854655LLU,18176528096060157101LLU,17175740415LLU},{18446744072608398073LLU,17541976815868837887LLU,14069034129469413816LLU,15839146489163022543LLU,18446744073699939154LLU,17179804078LLU},{16388286138453852159LLU,18446744073701027293LLU,4540737622242230271LLU,18227192506271125311LLU,17863921999877767167LLU,16944920527LLU},{15920749798341214207LLU,18446744073507167202LLU,18229673201049272319LLU,18391853141815214016LLU,13787376181298855935LLU,17149968381LLU},{3458764513348929423LLU,18163008636727588975LLU,18446744073693036039LLU,10371806708367359999LLU,18443366373985324943LLU,17175739985LLU},{16941274786389927LLU,14843859458306736124LLU,4611685744613844735LLU,16717361816799281148LLU,14393223827451739903LLU,13891076095LLU},{18435477376431878267LLU,4593680396344817591LLU,18442310842574667744LLU,9223372036854774991LLU,4071254050245435872LLU,16366124031LLU},{18445670950228672481LLU,14122724936018690047LLU,234187180622217726LLU,16415607241467494396LLU,14411518601426139771LLU,13891519919LLU},{18144997942275145727LLU,4611686017619984157LLU,18443362869295702016LLU,18227193591622794303LLU,9150601398755131903LLU,8286863355LLU},{9690769774077804543LLU,18446744073683978751LLU,3463202126644117503LLU,18446673706039054332LLU,16700416984398954495LLU,11609630479LLU},{17997502576290955263LLU,18446744072699772672LLU,18442517568192249855LLU,18172305971148291075LLU,4502530061278117887LLU,8294711289LLU},{9223371212146020335LLU,13853072040770142060LLU,18446743816010719263LLU,17005662561481261055LLU,18446532964255145503LLU,6423837945LLU},{12682136497122178591LLU,18433093083848491263LLU,18446678102744498151LLU,2305789391110406143LLU,18285740386813997038LLU,12211519319LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][6] = {{15017482759692091391LLU,18446744073709537752LLU,4377709945110396927LLU,18172302605181521712LLU,18428729675216846847LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,6],[3,7],[4,6],[4,8],[5,9],[5,10],[6,11],[7,8],[7,12],[8,13],[9,10],[9,12],[10,13],[11,12],[11,13]]\n", fout);
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

