#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_18_1156_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 17;
static uint_fast32_t endhere = 0;
char str[28] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[18][10] = {{18446744069414592511LLU,18446744039349813247LLU,36028797018963967LLU,18446735397875613696LLU,18446730879570018183LLU,18446181124293000959LLU,18446744065119617023LLU,18437737011893764095LLU,288230101273772019LLU,268435440LLU},{18446744073709551615LLU,562949953421311LLU,0LLU,18446744056529682432LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU,0LLU,18446744073707454464LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,2097151LLU,0LLU,18446744073709486080LLU,18446744073709551615LLU,268435455LLU},{18446744069414584320LLU,18446744073709551615LLU,18446744073709551615LLU,18446735311976267775LLU,17579765961068642177LLU,18408463476875326439LLU,15487808460879157085LLU,18437736874454841334LLU,18446744073709551615LLU,268435455LLU},{4294967295LLU,13836183955189006272LLU,17937832844469469183LLU,18446744073608753151LLU,18446744073709551615LLU,13835048708351197183LLU,18437165076725087995LLU,9007199254736639LLU,18446744073708503040LLU,268435455LLU},{18446744073709551615LLU,4611123068473966655LLU,18446744073709518848LLU,8796093022079LLU,18428729675200069631LLU,9209861237452570623LLU,18445618173785931775LLU,18446744073709551101LLU,18446462598733889535LLU,268435455LLU},{17861135367483154433LLU,18446460949461596119LLU,18410715276690620415LLU,9079239187873398783LLU,17762196654934457851LLU,18446744073708353519LLU,18446744073709551615LLU,18446743936270663679LLU,18158790773682732543LLU,268435455LLU},{0LLU,18446181123756130304LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18428729683787907071LLU,18160765497371525119LLU,18445477436314091519LLU,18446744069406194943LLU,18446743523953737728LLU,17311555355196522495LLU,14987979559889010687LLU,4217705129181123LLU,13762156036314103806LLU,268434447LLU},{18014397972561919LLU,4899916394578837568LLU,11096869481840902140LLU,18446744073105571839LLU,549755813887LLU,18446744073707454464LLU,18446742390082371583LLU,18446744073709551615LLU,17573045745866506241LLU,268370939LLU},{18446708889203113859LLU,18446742767501574143LLU,18446744039349877695LLU,18410715276675907580LLU,18446744073608888319LLU,562949953421311LLU,18446744071562067968LLU,17293399806814781439LLU,18438012284669263871LLU,267976543LLU},{18230571291587371135LLU,18446744073707453951LLU,18410715311050326015LLU,18446744073709520895LLU,18370200472230297599LLU,18446744073709551615LLU,2147483647LLU,18446717548058574848LLU,18167520896271514895LLU,264762367LLU},{18374677692168535807LLU,18412967067914600435LLU,18446742424442109443LLU,18437745670547832831LLU,18446532967472824447LLU,18226067691867705343LLU,18446605535242616831LLU,17888297719647174605LLU,18354138669066878943LLU,255328143LLU},{14969973957469470719LLU,17617518800909893631LLU,9223372036854743551LLU,9006786937879904LLU,10358278593200521215LLU,17573045719827218431LLU,18446744073709551615LLU,576459103035981823LLU,10375449253970442238LLU,218037375LLU},{18445899133317282559LLU,18367915652578017279LLU,18446496133837481955LLU,17581523530404593695LLU,18446744066193294311LLU,18446739709855006719LLU,13979050089465774079LLU,13726833119049285631LLU,4611659347754221567LLU,195559150LLU},{4611677767862321135LLU,17266800962882752511LLU,18446744073583722014LLU,18438293210159644671LLU,9223363240757624735LLU,18446185521735532512LLU,18446744073709547583LLU,18005532047712452607LLU,18446743944843743223LLU,125689745LLU},{18446743661342326687LLU,16136397464767578048LLU,13546827644904931309LLU,18446320761731842047LLU,18446744073709494255LLU,18446739950538850335LLU,18446744071562072063LLU,18374580926492442623LLU,17863527917568409599LLU,196820990LLU}};

static uint_fast64_t D[18][10] = {{17352123047884095487LLU,18446319799656051139LLU,18446744073709551615LLU,4359458051015573503LLU,18306076472021875839LLU,58546795155558399LLU,18444615934560960511LLU,14969965161379527693LLU,18158646737445190814LLU,268435455LLU},{6369649727914377214LLU,18446523737239607529LLU,18446744073709551615LLU,10820663330490810367LLU,15845527073074296701LLU,16881743203195644854LLU,15487664948839569245LLU,18446744073709516708LLU,18446744073709551615LLU,268435455LLU},{18446744067894788099LLU,13833911159957225407LLU,17784384305339749179LLU,18446744072465534938LLU,18446744073709551615LLU,4611024615483899903LLU,13662205936384556275LLU,18446744073709538559LLU,18446744073709551615LLU,268435455LLU},{12077094351609937917LLU,4613616200175691606LLU,1873497444986072260LLU,7626080768383482223LLU,7439945749576997251LLU,18446744073708353487LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,562949953421311LLU,18446744073709518848LLU,18446744073709551615LLU,13807330394604531455LLU,1585267068301664125LLU,18444759455190482943LLU,18014398509481055LLU,18446511855298520732LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,17275155866994999295LLU,14759214901LLU,18446744073709551615LLU,18429677364028899327LLU,8250488550298809295LLU,18443133471423873020LLU,18446694817144504319LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,17898283374567751679LLU,18446744069288552191LLU,17362436492722438016LLU,18392405245379735779LLU,14972216894386310712LLU,18432340277485757427LLU,18446744073708919139LLU,268435455LLU},{6878662047513444351LLU,18446664852685414141LLU,18446744073709551615LLU,15540444570427850751LLU,11529198495383234559LLU,18446181123758227004LLU,18446744073709551615LLU,3494793310839504895LLU,288141919100282865LLU,268435440LLU},{18446744073709551615LLU,18446181123756130303LLU,17235606397093281791LLU,18446744049788827317LLU,13608015324767809278LLU,15400720328740756601LLU,7743617262194977710LLU,18446744073709534043LLU,18446744073709551615LLU,268435455LLU},{18446744072862240007LLU,4611686018427125823LLU,9772784363310678012LLU,18446744072769216511LLU,18446744073709551615LLU,9223315955302531071LLU,18319515252036497863LLU,18445529868022521343LLU,17573045745866506239LLU,268370939LLU},{18446744072498049787LLU,18446723078291455999LLU,18444525809000043323LLU,18446744066178677776LLU,18446744073709551615LLU,17293892671055593471LLU,143992034183610367LLU,18439558182985334720LLU,13762106779750105087LLU,268434447LLU},{18172299268570202111LLU,8698583926542695551LLU,15996785876419981047LLU,14116422247002375151LLU,18442240956188582839LLU,18446744073709551615LLU,18446744073709551615LLU,4287400456977645567LLU,6629210619685895937LLU,264762355LLU},{1152857870150959103LLU,14361978944356290556LLU,4323455642275674508LLU,18381579180611435900LLU,1134907105966825423LLU,18446744073709551132LLU,18446744073709551615LLU,16500766272464617471LLU,12105673706672433151LLU,267976540LLU},{14987979559887965623LLU,17870283321406128127LLU,2218782244732927LLU,18446743661392691168LLU,9364105127163592703LLU,18446744039884848895LLU,18304880683333451712LLU,18446741907384239103LLU,14123288431433315195LLU,217999359LLU},{18374686478824373839LLU,18446744073709551603LLU,18446741906906939391LLU,18446744072651573247LLU,18374413800787935231LLU,18446673979843248611LLU,18446603338366582847LLU,18444923281968463871LLU,18417470676131438023LLU,255302651LLU},{274684392897507303LLU,16716939466895246335LLU,18412967076370579454LLU,4575657221408423935LLU,4503118490370047LLU,1152921504606846944LLU,18446742390082367488LLU,17293822466019491903LLU,18292353949446947070LLU,100454399LLU},{18301573354471029183LLU,18374669162363289039LLU,18446464765543835647LLU,17365880163140632575LLU,18442521940603174911LLU,17573045745863393279LLU,13835198790625132543LLU,11529215037965074431LLU,18405615741688872767LLU,183465727LLU},{18429848974815127551LLU,18284069121838546943LLU,18410996751667273343LLU,1146161416135245795LLU,18446743532540002239LLU,18446251466394959871LLU,4611686018427387903LLU,8928385032901296128LLU,15924481888161366014LLU,98565559LLU}};

uint_fast8_t X[18] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[18][10] = {{17352123047884095487LLU,18446319799656051139LLU,18446744073709551615LLU,4359458051015573503LLU,18306076472021875839LLU,58546795155558399LLU,18444615934560960511LLU,14969965161379527693LLU,18158646737445190814LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,268435455LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[0,4],[1,2],[1,3],[1,5],[2,4],[2,6],[3,5],[3,7],[4,7],[4,8],[5,6],[5,8],[6,7],[6,8],[7,8]]\n", fout);
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
