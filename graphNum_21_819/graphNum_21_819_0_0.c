#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_819_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][7] = {{2249045129035775LLU,18302628869326241730LLU,18365678979769171967LLU,18433249767501873151LLU,18446743797824946175LLU,4577684666076618759LLU,4092LLU},{18446744073709551615LLU,268435455LLU,18302628885633695744LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,144115188075855871LLU,0LLU,18446744072635809792LLU,18446744073709551615LLU,4095LLU},{18446739675663040512LLU,18446744073709551615LLU,14121036562900701183LLU,17870267369863512063LLU,17870283322425327358LLU,18446744073709551615LLU,4095LLU},{4398046511103LLU,18446741874954731520LLU,18446690197636120575LLU,18437736874052157439LLU,576460752303357951LLU,18446744073692774400LLU,4095LLU},{18433233274827440127LLU,264241023LLU,9223372036854775744LLU,11382812702007915999LLU,5764607522898968463LLU,18446744005000744051LLU,4095LLU},{16717361816799248385LLU,18446744073709451263LLU,18302628885633695807LLU,18410715273469362175LLU,18446708890410942463LLU,18446462667452317695LLU,4095LLU},{18446743519658770431LLU,17869997448181579715LLU,36028764638937079LLU,18446742974197923840LLU,18293286970987642879LLU,18410849397769232895LLU,4095LLU},{18444501069714161663LLU,9219994337133199359LLU,18446603336221194367LLU,1099511627775LLU,538740902105972736LLU,13871086645504638968LLU,4095LLU},{18433228876780961791LLU,2199019061119LLU,14409266939052412864LLU,13835044861142433791LLU,17870318505744662431LLU,18446744005006852095LLU,4095LLU},{1097497959791LLU,18230483314022547454LLU,18433214170267123679LLU,18433250867013484543LLU,576460751296724991LLU,1693274259083755008LLU,4092LLU},{18446743936144764915LLU,18419720293833506817LLU,4611087879803518973LLU,18446744073306882048LLU,18446744073709550079LLU,18444770724796170751LLU,4035LLU},{18446392006650363649LLU,1152920920466093311LLU,18446744072635809852LLU,9187343239835799548LLU,13708957129350283384LLU,17437935626872668158LLU,3867LLU},{16447145838082294015LLU,18302067994043023351LLU,18302628886707437567LLU,18446532964188946431LLU,18446181261195083775LLU,4604088393079454671LLU,3327LLU},{0LLU,18446744073441116160LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18410580036758141311LLU,9222219748668866559LLU,18446594573682605647LLU,273800101887LLU,9474936379206008824LLU,13582829984757579759LLU,2813LLU},{13832946966897623039LLU,14985727656995045439LLU,3458764513820506623LLU,18446744022035726272LLU,9204231735217225735LLU,14123288014083202936LLU,1971LLU},{18445600581482472447LLU,18410716994671333247LLU,17866969324640534527LLU,12754189746666732751LLU,17289346457224609759LLU,17221202024590409723LLU,3303LLU},{2292327812419288847LLU,36028784134062046LLU,14987979541639581632LLU,18443356482679144447LLU,17874786517306548159LLU,17843261655459294847LLU,3900LLU},{18410583335192493047LLU,18428727613347348479LLU,18446735823075081983LLU,4503599355772991LLU,9799831689646569976LLU,18228862031732277231LLU,2767LLU},{17075960937127839743LLU,18443964437447558135LLU,18302637681726683647LLU,18446532965266620355LLU,18445162972767617023LLU,5759857220485282777LLU,1527LLU}};

static uint_fast64_t D[21][7] = {{18446743850238075889LLU,1117454729814169215LLU,18443430076943695932LLU,3710966092953288703LLU,18316694930365085790LLU,16789418379541217279LLU,4035LLU},{4210871650798764030LLU,18446744073488148867LLU,9511602413006487551LLU,16616419407070468709LLU,18446744073050303218LLU,18446744073709551615LLU,4095LLU},{14235872422910787585LLU,12149915748716926588LLU,18421284674103250841LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446741874954731519LLU,9142243733876669695LLU,15980636077357491610LLU,576460751899620845LLU,18446744073692774400LLU,4095LLU},{18446744073709551615LLU,6296828325482463231LLU,13939340013259965286LLU,3710948759487709183LLU,17870283322414571038LLU,18446744073709551615LLU,4095LLU},{16320121459823312896LLU,18446744073558438375LLU,18158513697557839871LLU,17815533677264232309LLU,18446708889852947194LLU,18446462667452317695LLU,4095LLU},{4594601208892588031LLU,18446744073634967323LLU,576460752303423487LLU,10147669631573962959LLU,5764607522797715335LLU,18446744005000744051LLU,4095LLU},{18444495486121005421LLU,3382677380914435711LLU,18439756470610819103LLU,18446744073709551615LLU,538740903179714559LLU,13871086645504638968LLU,4095LLU},{14235877452453162643LLU,17410486079407718336LLU,18320045116276707313LLU,18446744073709551615LLU,18293286970987642879LLU,18410849397769232895LLU,4095LLU},{16320121459823345663LLU,18446744073558438375LLU,18365615770731445503LLU,18378134543892729648LLU,13258597302172934649LLU,18446462667441648524LLU,4095LLU},{18446743936144764915LLU,15532629241777618943LLU,107237561469765620LLU,3710966092953272320LLU,18200957951644792926LLU,18444770724812947455LLU,4035LLU},{18446740773161000303LLU,8967660816606167039LLU,18429714304224721743LLU,18442240732802646015LLU,18116069443472695231LLU,1693274259083755519LLU,4092LLU},{18159619250592972799LLU,18302067993975844851LLU,17870283321406128127LLU,18221295811436756175LLU,17293294803284852735LLU,4604367614250777027LLU,3327LLU},{4611157986233024511LLU,1152920920458787871LLU,1152921504606846972LLU,1149534750692590588LLU,2179742219647287296LLU,17437937743249772158LLU,3867LLU},{18446744073709551615LLU,6296828325214027775LLU,8960601060309364838LLU,1830324666639082906LLU,18446744073295058189LLU,18446744073709551615LLU,4095LLU},{10227674584081477595LLU,14113858893012516865LLU,3332065589877223421LLU,18446744022035726272LLU,18419423391602704383LLU,18432810780907667839LLU,1971LLU},{17807228802313287735LLU,18284580254925914110LLU,18446735277681401795LLU,18446743247998025727LLU,18014290791702200319LLU,13813069970197708783LLU,2813LLU},{287878532430823183LLU,18446744060673654222LLU,18365678978695692287LLU,18442520849614360572LLU,13835057650749900793LLU,17843036323747702334LLU,3900LLU},{18336942444513321983LLU,18446743592671118327LLU,18445618719263456511LLU,17298115062481812483LLU,16717354120209529343LLU,17221146018736798665LLU,3303LLU},{10227674719532064719LLU,13868307280463659007LLU,17150833263690902527LLU,18446744007087161343LLU,18413644071806410687LLU,6327346362169950079LLU,1982LLU},{9214254920694234935LLU,4593669961794191326LLU,16140901063486988224LLU,1149533977732563967LLU,10988782987704795128LLU,18283488526770106111LLU,2909LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][7] = {{18446743850238075889LLU,1117454729814169215LLU,18443430076943695932LLU,3710966092953288703LLU,18316694930365085790LLU,16789418379541217279LLU,4035LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4095LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,4],[1,5],[2,4],[2,6],[3,7],[3,8],[4,9],[5,7],[5,10],[6,11],[6,12],[7,11],[8,10],[8,12],[9,11],[9,13],[10,13],[12,13]]\n", fout);
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

