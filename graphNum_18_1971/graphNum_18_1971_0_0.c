#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_18_1971_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 17;
static uint_fast32_t endhere = 0;
char str[28] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[18][10] = {{0LLU,18446603336221196288LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,140737488355327LLU,0LLU,18446744073642442752LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU,0LLU,18446744073709551584LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,31LLU,18446744004990074880LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{6548118409475784703LLU,18446734040628136942LLU,18446744073709551615LLU,16717237845923725311LLU,18432985333314870527LLU,18446740197501501465LLU,68704690079LLU,18446744073709551600LLU,18446744073709551615LLU,15LLU},{18445195961102761857LLU,140733729275769LLU,18446744069875957758LLU,18405226514644729731LLU,15850700363507102685LLU,18446744073709551615LLU,18446744073709551615LLU,18446744039349813263LLU,18446744073709551615LLU,15LLU},{18302626686609522815LLU,18446744073709551615LLU,18446189919848103937LLU,18446744023243685887LLU,18446744004486758387LLU,18163017296916840447LLU,18446744073709551615LLU,13835058089641902079LLU,18446744073709551615LLU,15LLU},{18446744004107927131LLU,16715373890096709631LLU,14984011408465526769LLU,18446744073696967783LLU,18446744073709551615LLU,3445253165450588927LLU,16113738729125838847LLU,4035224748580403215LLU,18446744073709543424LLU,15LLU},{18446709427282110975LLU,18446743592421556167LLU,18446743884592573839LLU,18446726481590313983LLU,18376938279485280187LLU,18446744073709551615LLU,4610823795152781311LLU,18432613700025188349LLU,18446744073441124351LLU,15LLU},{17546059332605444087LLU,18340909482466344959LLU,18235074891197972479LLU,9223389629040820223LLU,18446744039886684159LLU,18444492823651680255LLU,18338654658995681311LLU,18446744073702115327LLU,18446739675931475967LLU,15LLU},{18446743798831644672LLU,18446744073709551615LLU,18446744073709551615LLU,18430979273843015679LLU,17437933354769972992LLU,18445609307780939775LLU,18446744039014002431LLU,1675323541221780943LLU,18446185383556283388LLU,15LLU},{274877906943LLU,13830554455654789120LLU,9214294468321081599LLU,18446744073709436927LLU,18446744073709551615LLU,17834093995670626175LLU,9223301731989848061LLU,18444791341058424830LLU,18375248313906339839LLU,15LLU},{18446744073709551615LLU,18446603336221200383LLU,18446739676199911423LLU,18446744073709551615LLU,18446744073707454719LLU,14987979553446558975LLU,18289188455495737343LLU,18446744073608625983LLU,13907115649315798947LLU,15LLU},{18444421905118265343LLU,18446744043644722942LLU,4398046511103LLU,18293551317634777084LLU,8646770547062865391LLU,18446744073709551615LLU,17298326168730075135LLU,4573396556782239743LLU,4467504669869994999LLU,15LLU},{18446743798865199103LLU,18446744073709551615LLU,18446744073709551615LLU,18446743935666618371LLU,18446743798814867231LLU,4611686018427323391LLU,1152921504606846960LLU,18446744073692250064LLU,18445125592590450556LLU,12LLU},{9259400816156991231LLU,18446740225404174335LLU,18446743790208138231LLU,18446744073708436991LLU,18446708889339559935LLU,18446744073709551615LLU,16139626730519265279LLU,18229233873139531770LLU,17861838786489482783LLU,10LLU},{9223372036854775807LLU,18157387797650993152LLU,17868031521122680831LLU,18446744073709551615LLU,35184372088831LLU,18446743532543672288LLU,18140437726395138047LLU,18446744072769894655LLU,13771998864397541887LLU,7LLU},{11529188657764237215LLU,576460752303423487LLU,1152921504606846974LLU,18446726756401414140LLU,18446709439093276671LLU,18446744073709551615LLU,17870278717203283967LLU,9223372003568779263LLU,9216563860603928319LLU,11LLU}};

static uint_fast64_t D[18][10] = {{18446744073709551615LLU,14461621353440083967LLU,10476164381634060090LLU,3384972189160165037LLU,13716746803833995263LLU,8763365731576670123LLU,18446744054208983862LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{44122302111023102LLU,18446696382010745739LLU,18446744073709551615LLU,15543868151002300415LLU,17126577456680474366LLU,18443321621363818453LLU,18446744037937581279LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446743585727607555LLU,3985316170829217791LLU,7970585079034083037LLU,18446744073688430422LLU,18446744073709551615LLU,9686800794478614655LLU,18446744060262612969LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18402622259580472573LLU,18446598314848607348LLU,18446738686750960103LLU,17964647807277758971LLU,6050163886904633601LLU,18446744073709551614LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18445618173802577921LLU,140733730258815LLU,18446744073708503040LLU,18406211642703478783LLU,15852670619624603633LLU,18163017297185210367LLU,18446744073709551615LLU,14239916585989900655LLU,18446744073709551615LLU,15LLU},{18221560793805357055LLU,18446734040628198383LLU,18446189919849152511LLU,16717361799753629695LLU,18433233274294231039LLU,18446744073441116185LLU,2296922052902256639LLU,18041885544262139888LLU,18446744073709551615LLU,15LLU},{6628762089580134399LLU,18446744073708507128LLU,18446744069875957759LLU,18445634941355032451LLU,18444525807389896927LLU,18446740197501566975LLU,16149822089511985055LLU,18446744072449226399LLU,18446744073709551615LLU,15LLU},{18410715817856462847LLU,18374685998635286527LLU,18302628748165377535LLU,9223372036921589759LLU,18446744073709551615LLU,18446744073709551615LLU,9150750462071273503LLU,18432617548308479997LLU,18446740665953083391LLU,15LLU},{17582052876464652275LLU,18410979149817430015LLU,18375248329039478783LLU,18446744073696968679LLU,18446744039886684159LLU,18444492274164301823LLU,18383691479903109119LLU,13258597302978707471LLU,18446743083451147205LLU,15LLU},{18446744069674367071LLU,16717361816531894215LLU,14987953107051216769LLU,18446744073709543551LLU,18376938279485280187LLU,3445253714937967359LLU,11528775241299918847LLU,9223367671020519423LLU,18446744073677913146LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446739675664089087LLU,12609471398885195775LLU,13788806942690377727LLU,14123073734583516203LLU,18442240536345508799LLU,18445055223848828927LLU,16586193365188353983LLU,15LLU},{18446744073709551615LLU,17131130032563945471LLU,15815216924254920634LLU,9223372036812304045LLU,18446744073707454464LLU,9068560791409096703LLU,18293621634738653175LLU,1675336739826155279LLU,15708093567939379168LLU,15LLU},{18446744073709551615LLU,11161045776530931711LLU,3875241926236043391LLU,18429852101015117823LLU,17365873215913590783LLU,18392669988772630527LLU,9223372035914858108LLU,18446466992213847550LLU,18434262413650689023LLU,15LLU},{17275522297570000895LLU,18446706415360538587LLU,18446744073709551615LLU,11528370363440300031LLU,18391011512923699199LLU,2251799813685223LLU,18446744073709551600LLU,17140522885521113087LLU,16679643070407384895LLU,12LLU},{13110521674019635199LLU,18446744039618248255LLU,18446744073709551615LLU,18176514889042886655LLU,1152895090155094015LLU,18446497366463741951LLU,18446744066191768063LLU,18442521939860773759LLU,4372995173685131255LLU,15LLU},{18446743933984635887LLU,17906241730218786815LLU,17365877927609368479LLU,18446744073659213727LLU,18446744073709551615LLU,18446744073709551615LLU,17942340915441958927LLU,16140898864399908863LLU,11384802954940776447LLU,7LLU},{18446744043625367479LLU,9196346075403780095LLU,18392278184679671806LLU,18446744073707585532LLU,18446744073709551615LLU,15922757957310168575LLU,18445055163719745523LLU,18163017280005324793LLU,17581876542222827519LLU,10LLU},{18415218635799674879LLU,18446607734267703807LLU,18446740225132625919LLU,9511602412941475839LLU,18446744073707716471LLU,18446744073709551584LLU,18444456539767963647LLU,14123288431433875447LLU,14951665439602634733LLU,5LLU}};

uint_fast8_t X[18] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[18][10] = {{18446744073709551615LLU,14461621353440083967LLU,10476164381634060090LLU,3384972189160165037LLU,13716746803833995263LLU,8763365731576670123LLU,18446744054208983862LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU}};

#if UINTPTR_MAX == 0xffffffffffffffff // 64-bit. Hopefully this means the cpu has 'popcnt'.
int counter (uint64_t * buf){
    uint64_t cnt[18];
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
            "popcnt %2, %2  \n\t"
            "add %2, %0     \n\t"
            "popcnt %3, %3  \n\t"
            "add %3, %1     \n\t"
            : "+r" (cnt[16]), "+r" (cnt[17])
            : "r" (buf[16]), "r" (buf[17]));


    return cnt[0] + cnt[1] + cnt[2] + cnt[3] + cnt[4] + cnt[5] + cnt[6] + cnt[7] + cnt[8] + cnt[9] + cnt[10] + cnt[11] + cnt[12] + cnt[13] + cnt[14] + cnt[15] + cnt[16] + cnt[17];
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
        A[i][7] = A[i-1][7] & C[i][7];
        A[i][8] = A[i-1][8] & C[i][8];
        A[i][9] = A[i-1][9] & C[i][9];

    } else {
        A[i][0] = A[i-1][0] & D[i][0];
        A[i][1] = A[i-1][1] & D[i][1];
        A[i][2] = A[i-1][2] & D[i][2];
        A[i][3] = A[i-1][3] & D[i][3];
        A[i][4] = A[i-1][4] & D[i][4];
        A[i][5] = A[i-1][5] & D[i][5];
        A[i][6] = A[i-1][6] & D[i][6];
        A[i][7] = A[i-1][7] & D[i][7];
        A[i][8] = A[i-1][8] & D[i][8];
        A[i][9] = A[i-1][9] & D[i][9];

    }
}

void printout(){
    sprintf(str, "[                  ,%5d]\n", this);
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
    fputs("[[0,3],[0,4],[0,5],[0,6],[1,4],[1,6],[1,7],[2,5],[2,6],[2,7],[3,4],[3,5],[3,7],[4,6],[4,7],[5,6],[5,7],[6,7]]\n", fout);
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
