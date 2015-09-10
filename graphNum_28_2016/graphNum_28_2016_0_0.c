#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_28_2016_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 27;
static uint_fast32_t endhere = 0;
char str[38] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[28][6] = {{0LLU,18446744073441116160LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,268435455LLU,18374686479671623680LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU,18446744073709289472LLU,18446744073709551615LLU,70368744177663LLU},{0LLU,18446744073709518848LLU,18302628885633695743LLU,18446744072636071935LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744072904278015LLU,18446744073709551615LLU,18446739676736782335LLU,18446744073709551615LLU,70368744177663LLU},{0LLU,18446744073709486072LLU,17726168133330272255LLU,18437741271964712959LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744070488293383LLU,18446744073709551615LLU,9007198717870079LLU,18446744073709551615LLU,70368744177663LLU},{18374686479671623680LLU,18446744073709354991LLU,15420325124116578303LLU,18442244871860518911LLU,18446744073709550592LLU,70368744177663LLU},{72057594037927935LLU,18446744043644780536LLU,18446744073709551615LLU,18442240473813745663LLU,18446744073708504063LLU,70368744177663LLU},{18302558516889518080LLU,18446744073709092815LLU,6196953087261802495LLU,18444496671808421887LLU,18446744073173728768LLU,70368744177663LLU},{18374756848415801343LLU,18446743558313476095LLU,18446744073709551615LLU,18444492273761648639LLU,18446743799368515071LLU,70368744177663LLU},{18014257634554675200LLU,18446744073708568463LLU,6196953087261802495LLU,18445622571782373373LLU,18446673979575893760LLU,70368744177663LLU},{18446673842404327423LLU,18446727031279321087LLU,18446744073709551615LLU,18445618173735600127LLU,18428800043675811583LLU,70368744177663LLU},{17437515269298716672LLU,18446744073707519759LLU,6196953087261802495LLU,18446185521769349109LLU,16158880553377988480LLU,70368744177663LLU},{18446743936807469055LLU,18445635765988753407LLU,18446744073709551615LLU,18446181123722575871LLU,2305807824707387263LLU,70368744177648LLU},{16284030264441569280LLU,18446744073705422351LLU,6196953087261802495LLU,18446466996762836949LLU,17311819650237988800LLU,70368744176655LLU},{18446744073176875007LLU,18303754785540538367LLU,18446744073709551615LLU,18446462598716063743LLU,17293804976849551295LLU,70368744113151LLU},{13977060253657661440LLU,18446744073701227535LLU,6196953087261802495LLU,18446607734259580757LLU,17888289198667988960LLU,70368742145551LLU},{18446744073705422847LLU,144115188075855871LLU,18446744073709551614LLU,18446603336212807679LLU,17870274525279551455LLU,70368679165439LLU},{9363120232081520640LLU,18446744073692837903LLU,6196953087261802495LLU,18446678103007952213LLU,18176523972882989040LLU,70367736561423LLU},{18446744073709488127LLU,18446744073709551615LLU,18446744073709550593LLU,18446673704961179647LLU,18158509299494551535LLU,70352637001471LLU},{135240188929109888LLU,18446744073676058639LLU,6196953087261802495LLU,18446713287382136149LLU,18320641359990489080LLU,70248014872463LLU},{18446744073709549695LLU,18446744073709551615LLU,18446744073708504063LLU,18446708889335365631LLU,18302626686602051575LLU,69406134108031LLU},{126224176333836016LLU,18446744073642500110LLU,6196953087261802495LLU,18446730879569220949LLU,18392700053544239100LLU,67018468163535LLU},{18446744073709551503LLU,18446744073709551615LLU,18446744071563116543LLU,18446726481522458623LLU,18374685380155801595LLU,57105616469951LLU},{108192151143288028LLU,18446744073575383052LLU,6196953087261802495LLU,18446739675662734677LLU,18428729400321114110LLU,51659799461871LLU},{18446744073709551603LLU,18446744073709551615LLU,18446735279764013055LLU,18446735277616005119LLU,18410714726932676605LLU,32950854746079LLU},{18446744073709551613LLU,18446744073709551615LLU,18374695275764645887LLU,18446739675662778367LLU,18428729400321114110LLU,51659799461871LLU}};

static uint_fast64_t D[28][6] = {{18446744073709551615LLU,145259270458310655LLU,12249799784689304578LLU,18446744073709398698LLU,18446744073709551615LLU,70368744177663LLU},{72128100762192022LLU,18446744073441148936LLU,6196953087261802495LLU,18446744073709442389LLU,18446744073709551615LLU,70368744177663LLU},{18374615972947359593LLU,18301484803519643639LLU,18446735275467996157LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,435777809227448319LLU,12321874975210343430LLU,18446739676736629418LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18156225534403543039LLU,18230553695112656891LLU,18446744072636071935LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,1016814880323272703LLU,12610140544328277006LLU,9002803355560618LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,17865706999392436223LLU,17582017752288194551LLU,18437741271427579903LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,2178888964532862975LLU,13763132434867567646LLU,18010004757785258LLU,18446744073708504063LLU,70368744177663LLU},{18446744073709551615LLU,17284669959435059183LLU,14987909173956567023LLU,18437736872307326975LLU,18446744073709550592LLU,70368744177663LLU},{18446744073709551615LLU,4503036127929696255LLU,18374959225159842878LLU,36024407562234538LLU,18446743799367469055LLU,70368744177663LLU},{18302628885633695743LLU,16122596394916380639LLU,4611545246562500575LLU,18428729670905102335LLU,18446744073173728255LLU,70368744177663LLU},{18446744073709551615LLU,9151296850899238911LLU,18375240768889617534LLU,72053213171133099LLU,18428799770139037695LLU,70368744177663LLU},{18158372960069484543LLU,13798466308309254079LLU,18446462529979776959LLU,18410715268100653052LLU,18446673979306407935LLU,70368744177663LLU},{18446744073709551615LLU,18445618174071144447LLU,18375803856349166846LLU,144110824388930223LLU,2287969075461103615LLU,70368744177648LLU},{17870001571551510527LLU,9151314442815799167LLU,18446180986250002303LLU,18374686462491754483LLU,16158845093187416063LLU,70368744177663LLU},{18446744073709551615LLU,18302628885902131199LLU,18376930031268265471LLU,288226046824524479LLU,4593952824310644735LLU,70368744113136LLU},{17293259068319727615LLU,18446744073707454207LLU,18445617898790452990LLU,18302628851273957327LLU,16140760324860010495LLU,70368744176655LLU},{18446744073709551615LLU,268435455LLU,18379182381106462718LLU,576456491695713023LLU,9205920322009726975LLU,70368679102448LLU},{16139774062921515007LLU,18446744073705356799LLU,18444491723871354367LLU,18158513628838362943LLU,13834776576010469375LLU,70368742145023LLU},{18446744073709551615LLU,268435455LLU,18383687080782855168LLU,1152917381438090239LLU,18429855317407891455LLU,70352575074288LLU},{13832804052133347327LLU,18446744073701161983LLU,18442239374033158143LLU,17870283183967173887LLU,9222809078311387135LLU,70367735445503LLU},{18446744073709551615LLU,268435455LLU,18392696480133545984LLU,2305839160922845183LLU,18430981234494668799LLU,69391580340209LLU},{9218864030557138943LLU,18446744073692772351LLU,18437734674357813247LLU,17293822294224794623LLU,18445618156622774271LLU,70247407153150LLU},{18446744073709551615LLU,268435455LLU,18410715274543104000LLU,4611682719892357119LLU,18433233068668223487LLU,56337035640819LLU},{18437728061114277631LLU,18446744073675993086LLU,18428725277153558527LLU,16140900514740031487LLU,18444492239535996927LLU,66930614460413LLU},{18446744073709551615LLU,268435455LLU,18446735277616529408LLU,9223369837831389183LLU,18437736737015332863LLU,25829899730935LLU},{18428712048519003615LLU,18446744073642434557LLU,18410715276690587647LLU,13835056955770486783LLU,18442240405362442239LLU,48099321954299LLU},{18410680023328455607LLU,18446744073575317499LLU,18446744073709551615LLU,9223369837831323647LLU,18437736737015332863LLU,25829899730935LLU}};

uint_fast8_t X[28] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[28][6] = {{18446744073709551615LLU,145259270458310655LLU,12249799784689304578LLU,18446744073709398698LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU}};

#if UINTPTR_MAX == 0xffffffffffffffff // 64-bit. Hopefully this means the cpu has 'popcnt'.
int counter (uint64_t * buf){
    uint64_t cnt[28];
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
    cnt[21] = 0;
    cnt[22] = 0;
    cnt[23] = 0;
    cnt[24] = 0;
    cnt[25] = 0;
    cnt[26] = 0;
    cnt[27] = 0;

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
            "popcnt %4, %4 \n\t"
            "add %4, %0    \n\t"
            "popcnt %5, %5 \n\t"
            "add %5, %1    \n\t"
            "popcnt %6, %6 \n\t"
            "add %6, %2    \n\t"
            "popcnt %7, %7 \n\t"
            "add %7, %3    \n\t"
            : "+r" (cnt[20]), "+r" (cnt[21]), "+r" (cnt[22]), "+r" (cnt[23])
            : "r" (buf[20]), "r" (buf[21]), "r" (buf[22]), "r" (buf[23]));
    __asm__(
            "popcnt %4, %4 \n\t"
            "add %4, %0    \n\t"
            "popcnt %5, %5 \n\t"
            "add %5, %1    \n\t"
            "popcnt %6, %6 \n\t"
            "add %6, %2    \n\t"
            "popcnt %7, %7 \n\t"
            "add %7, %3    \n\t"
            : "+r" (cnt[24]), "+r" (cnt[25]), "+r" (cnt[26]), "+r" (cnt[27])
            : "r" (buf[24]), "r" (buf[25]), "r" (buf[26]), "r" (buf[27]));


    return cnt[0] + cnt[1] + cnt[2] + cnt[3] + cnt[4] + cnt[5] + cnt[6] + cnt[7] + cnt[8] + cnt[9] + cnt[10] + cnt[11] + cnt[12] + cnt[13] + cnt[14] + cnt[15] + cnt[16] + cnt[17] + cnt[18] + cnt[19] + cnt[20] + cnt[21] + cnt[22] + cnt[23] + cnt[24] + cnt[25] + cnt[26] + cnt[27];
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
    sprintf(str, "[                            ,%5d]\n", this);
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
    str[22] = X[21] ^ 48;
    str[23] = X[22] ^ 48;
    str[24] = X[23] ^ 48;
    str[25] = X[24] ^ 48;
    str[26] = X[25] ^ 48;
    str[27] = X[26] ^ 48;
    str[28] = X[27] ^ 48;

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
    fputs("[[0,1],[0,13],[0,14],[1,2],[1,14],[2,3],[2,14],[3,4],[3,14],[4,5],[4,14],[5,6],[5,14],[6,7],[6,14],[7,8],[7,14],[8,9],[8,14],[9,10],[9,14],[10,11],[10,14],[11,12],[11,14],[12,13],[12,14],[13,14]]\n", fout);
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

