#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_594_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][6] = {{18446744073172680705LLU,67108863LLU,18446744073709289472LLU,4398046511103LLU,18446744073709551552LLU,16383LLU},{18446744073709551615LLU,511LLU,18446744073709289472LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,262143LLU,18446739675663040512LLU,18446744073709551615LLU,16383LLU},{18446744073172680704LLU,18446744073709551615LLU,8499978460489842687LLU,3708164636671LLU,18446744073709551552LLU,16383LLU},{536870911LLU,18446744073642443264LLU,18446744073709551615LLU,18446744073709551615LLU,18446744056529682495LLU,16383LLU},{0LLU,18446744073709551104LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{17874786921033498623LLU,17834253938124128255LLU,13835058055282393079LLU,13474400649185591295LLU,18446739692709740527LLU,16383LLU},{18446743937344339967LLU,9220970703325495295LLU,4611686018427385727LLU,17270169874965987328LLU,18445622571849211962LLU,16383LLU},{18444492274159779503LLU,15996783531367597055LLU,18446744073709420511LLU,18446744073709535232LLU,18303750387492978751LLU,16383LLU},{2251799728729083LLU,18437138739525582336LLU,18446744056530722301LLU,18446744073709551615LLU,144115153717166079LLU,16383LLU},{18446445006546788353LLU,18445618173848764347LLU,18229726866665635839LLU,18428733866282844159LLU,12636747336291188735LLU,16368LLU},{14987978734718427135LLU,1125899905263615LLU,18446743042917138432LLU,18014398508498943LLU,18010994318403174336LLU,16143LLU},{17872535258658766847LLU,18446744073709291519LLU,13835058072462032895LLU,18446744073709535232LLU,18303750421719556095LLU,16383LLU},{576460615938211839LLU,18446744073642966528LLU,18446744056530731007LLU,18446739675663056895LLU,142998067216375871LLU,16383LLU},{4611686011958198145LLU,4611685743593521082LLU,18446744073646636092LLU,14987702275929014271LLU,12105288769473609340LLU,15612LLU},{18419415711798419583LLU,18175402471038296063LLU,18229657597432840191LLU,18212838368062996419LLU,18397202965973647311LLU,13299LLU},{17293822277042838015LLU,1059929200261095LLU,18446743866745815036LLU,13849694737964793855LLU,15995510406424558591LLU,11215LLU},{16068737367051075559LLU,18446744057602338815LLU,18429854750472929283LLU,4611633241868467455LLU,18138229288556429248LLU,7743LLU},{8680697071407202183LLU,18446743799905140734LLU,13835128423963426815LLU,18446480190855954495LLU,18311631960787713663LLU,15612LLU},{18419715750026535423LLU,18445622571786305025LLU,18446678085899124735LLU,18429851177127509955LLU,1151865957331706367LLU,13299LLU},{18012287167981813663LLU,288230118453475326LLU,13853072247582883836LLU,14123077325150995455LLU,18337528449212874495LLU,11741LLU}};

static uint_fast64_t D[21][6] = {{8073601458768969727LLU,18446744073709551308LLU,14920148419829825535LLU,18446740710485852160LLU,18446744056529682495LLU,16383LLU},{8073601458768969726LLU,18446744073709551308LLU,7324446575863267327LLU,18446742262753110698LLU,18446744073709551615LLU,16383LLU},{10373142614940581889LLU,11068046444198888243LLU,18446744073709394329LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073642443263LLU,16095680304456400895LLU,18446741831560418645LLU,18446744056529682495LLU,16383LLU},{18446744073709551615LLU,7378697629510664191LLU,3526595653879883366LLU,3363223699455LLU,18446744073709551552LLU,16383LLU},{18446744073709551615LLU,7378697629510663679LLU,11122297497846441574LLU,18446741486619481429LLU,18446744073709551615LLU,16383LLU},{10376293404244104365LLU,2158123475725187891LLU,18446744073709417247LLU,17270174273012498431LLU,18445622571849211962LLU,16383LLU},{17871635995364764499LLU,17518403536213772287LLU,18446744073709493745LLU,13474400649185591295LLU,18446739692709740527LLU,16383LLU},{18446744073624595451LLU,17819845936948445183LLU,18446744056529898740LLU,11121260012968673279LLU,144115170895986661LLU,16383LLU},{18446744073436593839LLU,5546029889812955135LLU,3526595653880575823LLU,7325487423964561408LLU,18303750387494027226LLU,16383LLU},{14045529920071794687LLU,18446744073707972335LLU,14974467664981786623LLU,18446740762288721148LLU,18010994307445935039LLU,16143LLU},{9015751206789709823LLU,18446744073688498072LLU,18175406590721523711LLU,18446743814941963011LLU,12636747330068558975LLU,16368LLU},{10376293541334188537LLU,4593676016891199283LLU,18446744073709535292LLU,14917033636795580415LLU,142998084262035440LLU,16383LLU},{18445844947666501127LLU,13853068056818616319LLU,17361653709162692547LLU,3529713800137670655LLU,18303750421853765583LLU,16383LLU},{18415210131361791999LLU,18176528096067307247LLU,18446673708454789119LLU,18230567980175982528LLU,18438862523098663887LLU,13167LLU},{214976505919832063LLU,4611686018423717886LLU,14974468760940837948LLU,14987979559821905151LLU,17437876183503339068LLU,15519LLU},{9097134871339335655LLU,18446744057586597791LLU,18428747264152305663LLU,18446691039440796687LLU,13807754153314514815LLU,7926LLU},{18293197244825860607LLU,18446678102999236576LLU,18176514900870823935LLU,18443366356825928691LLU,14951738553331857663LLU,11257LLU},{14987979473486217727LLU,18158518095560834663LLU,18446744060019082239LLU,18159635458188967935LLU,6484453376955247555LLU,13167LLU},{18084660875876237191LLU,288230102347376639LLU,14106398902039084032LLU,287966493361032447LLU,18353291529498787836LLU,15519LLU},{16122882164357326847LLU,18445688542495505951LLU,18446691281045029887LLU,18433228893960011727LLU,4322593612270364611LLU,6007LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][6] = {{8073601458768969727LLU,18446744073709551308LLU,14920148419829825535LLU,18446740710485852160LLU,18446744056529682495LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,6],[3,7],[4,6],[4,7],[5,8],[5,9],[6,10],[7,11],[8,10],[8,11],[9,12],[9,13],[10,12],[11,13],[12,13]]\n", fout);
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
