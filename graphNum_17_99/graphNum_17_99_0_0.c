#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_17_99_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 16;
static uint_fast32_t endhere = 0;
char str[27] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[17][10] = {{18439706933003810816LLU,18446743795608516327LLU,18446744073709551615LLU,9511461744237608959LLU,16137030096334605823LLU,8718968878571907057LLU,4359345890082618094LLU,18266441179656617919LLU,18446726481523769343LLU,281474976710655LLU},{18446744073709551615LLU,549755813887LLU,0LLU,18446744073675997184LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,33554431LLU,0LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,0LLU,18446744056529682432LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU,18158513697557839872LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18410715826446401535LLU,9475133605177982975LLU,18446744005015228415LLU,9115221796008755199LLU,18382554582799613951LLU,18446741890691706751LLU,268524928280551679LLU,18446744073709289472LLU,281474976710655LLU},{0LLU,18446743523953737728LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{16717361816795088895LLU,36028728184123390LLU,9217179578676543360LLU,18446744073708502928LLU,18446744073709551615LLU,18446550493085826959LLU,16411257779221299199LLU,18439953489895104495LLU,17592186044415LLU,281474976710640LLU},{11529171336190492671LLU,18446744073709551519LLU,18446741048567791743LLU,9079397586267275263LLU,18446744070475743152LLU,14411516677281782911LLU,18446744073709551609LLU,18446744073709551615LLU,18446744073709551615LLU,281474959933455LLU},{18302628889928663039LLU,18446709988849090559LLU,16708073138808683007LLU,18446744073707454079LLU,18446744073709551615LLU,18446453527358997503LLU,2305825176429756415LLU,286893370010237436LLU,18446741839251243004LLU,281473918695327LLU},{144115188075855871LLU,18013307793947099136LLU,11529215046068430831LLU,18445037629582825981LLU,18361122904231376911LLU,18446744073709551615LLU,18445053299703939071LLU,18446743970227644291LLU,9222844202553964547LLU,281407330909823LLU},{18446744073709551615LLU,7459086333076701183LLU,18446739508159315967LLU,18446743457381744639LLU,18446744073054980095LLU,18392700867947266047LLU,18446744073709551559LLU,18446744073709551615LLU,18415781826231273471LLU,277145649676287LLU},{18424224924470607809LLU,18446744071157841919LLU,18302628885642084351LLU,16703846748719677439LLU,18011724497203191805LLU,18446744073709551615LLU,9007062915299147775LLU,18446744053275164671LLU,18446744065119870975LLU,268074410296317LLU},{9223301461952149567LLU,18446744073709551596LLU,144115188075855871LLU,11529078706324635648LLU,18446744043642683263LLU,18009897108877864947LLU,18446744073709551614LLU,17293822569102704639LLU,18230483339255480295LLU,228695163797503LLU},{18445626969492950783LLU,2301332799551963135LLU,17293822569102507004LLU,18446744073709354675LLU,18446739675663302655LLU,18446744073709551615LLU,16701599011945054207LLU,9799828528550444028LLU,16145404114367381503LLU,192964172840895LLU},{17150833280929628151LLU,18446576947942128767LLU,18446682498843803523LLU,18446744073709551615LLU,4398046511103LLU,18446744021901279135LLU,18446744073709543487LLU,9223372036854775807LLU,2305843009011318588LLU,136329912385520LLU},{18445758876931227599LLU,18157664874581066751LLU,18302699254377873404LLU,17293819268957208575LLU,18446739710022777087LLU,18446744073709551615LLU,18446744056529690623LLU,11529215046068469759LLU,16428709219861002495LLU,202258532794367LLU}};

static uint_fast64_t D[17][10] = {{9799797604786110463LLU,480935657471LLU,18446744073701163008LLU,18446744073709551615LLU,9115283442748096447LLU,18446741874749210623LLU,18446744073206231039LLU,13250150854653903087LLU,8012712977650052472LLU,281474974285110LLU},{18074330129590050814LLU,18446743754782725303LLU,18446744073709551615LLU,18083078295217242111LLU,11500960208330271190LLU,6809442636531021501LLU,12635971757513044683LLU,18266158556581461813LLU,18446744073709551615LLU,281474976710655LLU},{13258597296435622747LLU,18389814453157703672LLU,4002855582830677503LLU,18446744073702208351LLU,18446744073709551615LLU,18441228095381830119LLU,15708360851605782527LLU,18434253621577108943LLU,18446744073709551615LLU,281474976710655LLU},{18244069840541707517LLU,14830298573521289215LLU,14987979559880258511LLU,13235463415054097593LLU,17647196810176520169LLU,18446744073709551615LLU,8572034199102423039LLU,18446739485476156410LLU,18446744073709551615LLU,281474976710655LLU},{5763234954561273767LLU,8357119601888066383LLU,18302542703692349306LLU,5764460735279136767LLU,18446739635374650943LLU,17708151440502640475LLU,18446744073709543348LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744069414584320LLU,18446744073709551615LLU,18442238274555609087LLU,288230376150663071LLU,16137522815003787248LLU,9223231299366419457LLU,16176929852921740280LLU,18302575533548896255LLU,13109950180688134143LLU,281474967624681LLU},{18446744073709551615LLU,13762999911488421887LLU,18046854374725369525LLU,18257229775585521638LLU,7745335567247212543LLU,12381410048713162750LLU,18423865412907412863LLU,18351594255051767551LLU,18446744073709551615LLU,281474976710655LLU},{18446735286206463999LLU,18446743795610353543LLU,18410714244824694783LLU,18302628885658849279LLU,18446744073709551615LLU,13842939354613254143LLU,4611686015197773823LLU,18104329760304791487LLU,18446737232887126991LLU,281474971444959LLU},{18439707199291785215LLU,18446744073693030142LLU,286101713050402815LLU,18446744073709551600LLU,18446189705067220479LLU,18446678103010246655LLU,18428729692379430511LLU,5764607523034234879LLU,15770831829903341239LLU,281474976710655LLU},{18446744073709551615LLU,16212958658533785599LLU,18373552883179143167LLU,144115188059029500LLU,18446744073709289472LLU,4609397921845084159LLU,18444703366974799808LLU,18226067558807584767LLU,18442248990951997439LLU,278822825910271LLU},{18446744073709551615LLU,4611686018427387903LLU,18446744039364886463LLU,18401636884054147063LLU,14699467708626894847LLU,18446744073675997184LLU,18442214085803114495LLU,18446470568040857599LLU,18415215028019134463LLU,279756166001657LLU},{18446744073709551615LLU,18446744073709551615LLU,18430945740885844197LLU,18444745161570252815LLU,18429291781192417279LLU,17005099165065150463LLU,18014398493227519LLU,18446744073709551488LLU,3891109956044193791LLU,281447898283535LLU},{216045237420662783LLU,18446743962032013308LLU,18446744073709551615LLU,18373560545002389503LLU,4602643600574906135LLU,18442240474115735551LLU,17283688782746353663LLU,16708632724998455269LLU,8968813104791977953LLU,228695161372471LLU},{18419157876664893439LLU,18446744073189432767LLU,18446744073709551615LLU,18430981461055111167LLU,17888294421305179132LLU,16104872267470454463LLU,18446744073189451739LLU,13835058055248609407LLU,17274400795709656446LLU,268074410295804LLU},{18446744071528512499LLU,18428518156381191171LLU,13834987720891428863LLU,18446744073680190463LLU,18446744073709551615LLU,4503599627370495LLU,18302522233005793280LLU,18167520896783216543LLU,18446730810590355231LLU,133990082137855LLU},{13835058054812401247LLU,18439425707671977981LLU,18320643266694619135LLU,18446744073709291519LLU,18446744073709551615LLU,18442801773669252599LLU,18446744057066553343LLU,18446739675696594943LLU,18446743105190181871LLU,192652905037823LLU},{18338650944382695935LLU,17266782846576492543LLU,18446744073701425055LLU,13708851661026623487LLU,576460752303226867LLU,18446744073709551615LLU,18446744073709551615LLU,18158518095604350975LLU,18444475781221253117LLU,102254028259315LLU}};

uint_fast8_t X[17] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[17][10] = {{9799797604786110463LLU,480935657471LLU,18446744073701163008LLU,18446744073709551615LLU,9115283442748096447LLU,18446741874749210623LLU,18446744073206231039LLU,13250150854653903087LLU,8012712977650052472LLU,281474974285110LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU}};

#if UINTPTR_MAX == 0xffffffffffffffff // 64-bit. Hopefully this means the cpu has 'popcnt'.
int counter (uint64_t * buf){
    uint64_t cnt[17];
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
           "popcnt %1, %1  \n\t"
           "add %1, %0     \n\t"
            : "+r" (cnt[16])
            : "r" (buf[16]));


    return cnt[0] + cnt[1] + cnt[2] + cnt[3] + cnt[4] + cnt[5] + cnt[6] + cnt[7] + cnt[8] + cnt[9] + cnt[10] + cnt[11] + cnt[12] + cnt[13] + cnt[14] + cnt[15] + cnt[16];
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
    sprintf(str, "[                 ,%5d]\n", this);
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
    fputs("[[0,2],[0,3],[0,4],[0,5],[0,6],[1,2],[1,3],[1,4],[1,6],[2,4],[2,5],[2,6],[3,5],[3,6],[4,5],[4,6],[5,6]]\n", fout);
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

