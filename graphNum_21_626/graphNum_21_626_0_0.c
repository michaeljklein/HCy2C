#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_626_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][6] = {{18445899648762642687LLU,70368743981055LLU,288230360045580288LLU,13835339530258873344LLU,18011003286294888447LLU,16143LLU},{18446744073709551615LLU,63LLU,18446744073709547520LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,4095LLU,18446743798831644672LLU,18446744073709551615LLU,16383LLU},{18446744073692774400LLU,18446744073709551615LLU,6304432502802997247LLU,13835058287167927637LLU,18446744073709551615LLU,16383LLU},{16777215LLU,18446744073172680768LLU,18446744073709551615LLU,4611686018427387903LLU,18446744073705357312LLU,16383LLU},{18446744073692774401LLU,536870911LLU,18446744073709547520LLU,13835058330160070655LLU,18446744073709551615LLU,16383LLU},{18446638520593285119LLU,18157387781544869887LLU,18374686479671627259LLU,17140133108650082303LLU,18446744004994266111LLU,16383LLU},{17291570768248831999LLU,13817043656772681719LLU,72057594037927935LLU,4573405146716831744LLU,18445618242520997880LLU,16383LLU},{18446726481536580667LLU,17293356341812756607LLU,18446744073709551407LLU,4611686018427326463LLU,18302885552879303680LLU,16383LLU},{17592185905151LLU,18374686479134785472LLU,18446744073441132542LLU,18446744072702918655LLU,144115187538985983LLU,16383LLU},{17969353536726630145LLU,18446673705393697276LLU,18392687684041572351LLU,18446462873610747903LLU,12601071715313778687LLU,16368LLU},{0LLU,18446744073709551552LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446620929478884863LLU,18446462583700422911LLU,18374686479940059007LLU,18446740225418792959LLU,18303754717357928455LLU,16383LLU},{18158513696551206659LLU,13816973305137070077LLU,18392687684041572351LLU,9184814088214021119LLU,12599963449661849592LLU,16368LLU},{18374699948676338687LLU,18366242230368227327LLU,14984390753934913790LLU,14986290710028745983LLU,17437928797847356031LLU,15471LLU},{72057529412091879LLU,18446743042382625216LLU,18446743042650013695LLU,9223345647552364543LLU,1152815947761909710LLU,13308LLU},{18446461774099054783LLU,16140958234805465087LLU,287966490139820031LLU,18410925270526590972LLU,18283206072858574719LLU,11983LLU},{9799269839188066295LLU,2305842803029966847LLU,18446744060812062720LLU,13871078056207318019LLU,15850367211416453119LLU,6975LLU},{11529214978419801599LLU,16284734775162304719LLU,18446742974252449633LLU,17987376361961947084LLU,18438860021486583751LLU,13215LLU},{18379067001910853439LLU,18446678090125379583LLU,18374687579182268415LLU,18446529395137908735LLU,18310791595508576313LLU,15603LLU},{9223090510204178415LLU,16149907438613494720LLU,4611685193542008831LLU,18412949483497193468LLU,4467499634419826654LLU,10205LLU}};

static uint_fast64_t D[21][6] = {{8651295865333350399LLU,18446744073601004028LLU,18379172555777966079LLU,9223371826465083391LLU,12601071715313136008LLU,16368LLU},{3361683591019888638LLU,18446744073709551575LLU,6226673597019758591LLU,18446743960587511125LLU,18446744073709551615LLU,16383LLU},{15085060482689662977LLU,14759517157280710760LLU,18446744073709550124LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073172680767LLU,18291226262143074303LLU,4611685878167592959LLU,18446744073705357312LLU,16383LLU},{18446744073709551615LLU,3687226916428840959LLU,233276717349717459LLU,13835058265671856128LLU,18446744073709551615LLU,16383LLU},{3361683591019888639LLU,18446744073709551575LLU,18213467356359835647LLU,4611685808037695487LLU,18446744073705357312LLU,16383LLU},{16424909314929878531LLU,10346833948247129969LLU,18446744073709550511LLU,4573405421594738687LLU,18445618242520997880LLU,16383LLU},{15951616382892349949LLU,17940370573641580782LLU,18446744073709550712LLU,17140133108650082303LLU,18446744004994266111LLU,16383LLU},{18446744073709412351LLU,8821422882820194303LLU,1152921504338413050LLU,14756545280433454323LLU,144115187543179263LLU,16383LLU},{18446744073705847867LLU,12087102781383507967LLU,17527099286452436743LLU,17525257057941259020LLU,18302885552879304703LLU,16383LLU},{12678896837483036671LLU,18446744073709354967LLU,68468770959474687LLU,13835058055282162688LLU,18011003286291336823LLU,16143LLU},{18446744073709551615LLU,3687226916428840895LLU,12220070476689794515LLU,18446743911953685162LLU,18446744073709551615LLU,16383LLU},{16424909315988309959LLU,2163975291410120689LLU,1152921504606843902LLU,16024871800369577203LLU,143858589548535807LLU,16383LLU},{11528102611951131135LLU,17940370590321626831LLU,18443155250631097464LLU,17140137231818686463LLU,18011020783112675959LLU,16143LLU},{18446744009083158499LLU,12087660315383167487LLU,18392686601709813735LLU,8878815329262765004LLU,18361049783486906318LLU,13308LLU},{18446739950525214783LLU,18437741259616407551LLU,14118802407886417951LLU,14409334013556685887LLU,18388465327462678143LLU,15471LLU},{9241302858991665143LLU,18446743867518598655LLU,18379189873124048895LLU,9223363034400964607LLU,14915886745927579115LLU,7158LLU},{9209824970866163647LLU,18446730875173856252LLU,18446462873560219647LLU,18446672588539154431LLU,13807754967365696284LLU,12025LLU},{18087582002613057311LLU,18439919404962807805LLU,14987979559888024575LLU,16139528599123262719LLU,12104681702396207097LLU,15603LLU},{9798988364227022823LLU,9006168034574275LLU,4611686018213478368LLU,17872508732927377344LLU,6485073786789560319LLU,13215LLU},{18392614016209911679LLU,18446691288560410623LLU,18374967941762641951LLU,14411375613375888447LLU,18335829687189599483LLU,7543LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][6] = {{8651295865333350399LLU,18446744073601004028LLU,18379172555777966079LLU,9223371826465083391LLU,12601071715313136008LLU,16368LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,6],[3,7],[4,6],[4,8],[5,7],[5,9],[6,10],[7,11],[8,11],[8,12],[9,12],[9,13],[10,11],[10,13],[12,13]]\n", fout);
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

