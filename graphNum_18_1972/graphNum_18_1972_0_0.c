#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_18_1972_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 17;
static uint_fast32_t endhere = 0;
char str[28] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[18][10] = {{0LLU,0LLU,18446744073709551608LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,7LLU,0LLU,18446744073709551552LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU,18446743936270598144LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,137438953471LLU,0LLU,18446744073709551600LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,13402271035519115207LLU,14964845619317160441LLU,18446704200038479917LLU,1729377987107769052LLU,17147496737737272798LLU,18446742974197923854LLU,18446744073709551615LLU,72057594037927935LLU},{4611686018393833472LLU,18446742982787858400LLU,18427040750177878015LLU,18230567168420872071LLU,17852409660382906367LLU,18442244872128692223LLU,18446744073640361983LLU,1099511627775LLU,18446744073709535232LLU,72057594037927935LLU},{18446735277650083839LLU,17428702959016869887LLU,16674577620246986303LLU,4323231341903609855LLU,18446744073709551615LLU,18307132485261066239LLU,18412967050703011825LLU,18446744073709551615LLU,18446708889337479167LLU,72057594037927935LLU},{16140909860588879871LLU,18446744073679922719LLU,18446737313430663679LLU,18446744073298503295LLU,18176527975743225855LLU,18446744073693822963LLU,18446744073709551615LLU,18446744073709551615LLU,35184372088831LLU,72057594037923840LLU},{3981126888653583352LLU,14699685110232381623LLU,18446744073709551613LLU,18446744073709551615LLU,11920605999066235647LLU,13897511947573395455LLU,17901245568084557823LLU,18014329102784790429LLU,18446496133837373391LLU,72057594033737535LLU},{18444281158268092415LLU,18418666944781846527LLU,18446744073441116167LLU,18444509866081845759LLU,18446741876833779711LLU,4611686018427379584LLU,18446726208793083648LLU,18446744054818334335LLU,14193375664294461439LLU,72057589747154939LLU},{18225223267026730951LLU,4572279418608680959LLU,18446673705233809407LLU,18340908657832624127LLU,18446744073709551608LLU,18446497783104929791LLU,9799828665989390591LLU,18444562360917032959LLU,4595923419731587903LLU,72055399309638910LLU},{18446743228674690623LLU,18446744073305751548LLU,70368744177663LLU,18446744069948375015LLU,18444987054128250879LLU,18446744069683017855LLU,18446744073709551615LLU,7424183985719187967LLU,18446737461600059390LLU,70933893154340863LLU},{2305843009213693951LLU,18446744069414584320LLU,18086174628404787183LLU,15564404990381391871LLU,18446744073709551615LLU,9223367913686171647LLU,18444773743537422334LLU,18437701690078527503LLU,17906312118425091583LLU,68664500348518399LLU},{18446744073709551615LLU,4294967295LLU,18446742698245734104LLU,18446744073625664507LLU,9511602400121583743LLU,18446744073708634109LLU,18446744073709551615LLU,13834771082751508479LLU,18446744073457893375LLU,58546765065854975LLU},{18401672893046456061LLU,16068808268905971711LLU,18446744073709551615LLU,18446744039349813248LLU,18446744073709551615LLU,14123262043154808831LLU,17942204576002179071LLU,18392692984006049791LLU,18446497783104917455LLU,49434040637198113LLU},{9223371864921798619LLU,18446744073640344575LLU,18446744073709551615LLU,34359738367LLU,18446462596719562688LLU,18446744073474607103LLU,18446744073709551615LLU,18012648086969810847LLU,18446742166743957497LLU,34902690882519039LLU},{16426668534601220607LLU,18427884288197263359LLU,2286139760842903544LLU,18300655262261837823LLU,18446744073709551559LLU,18442521949058891775LLU,9223371796334771983LLU,72057043141263344LLU,14986290710028746744LLU,26177172701967359LLU},{18446736367699492863LLU,18446744069950906339LLU,18446682425629081599LLU,18446744043640528799LLU,18430979413427486719LLU,18446743940565565327LLU,18446744073709551615LLU,18446744073707450111LLU,18446717683819069447LLU,51789742286503935LLU}};

static uint_fast64_t D[18][10] = {{18446744073709551615LLU,18446744073709551615LLU,3299814108682836855LLU,8001037715416100013LLU,18446624463424806793LLU,9780604347606763670LLU,14546350043746519451LLU,18446744073709551610LLU,18446744073709551615LLU,72057594037927935LLU},{11941691809653824366LLU,7198266426069396517LLU,18446744073709551609LLU,18446744073709551615LLU,309462967763267839LLU,18182571473654513663LLU,13774822408154625910LLU,18446744073709551605LLU,18446744073709551615LLU,72057594037927935LLU},{15728434670438186229LLU,11248477652681490431LLU,15147012921248180142LLU,10445706397717889022LLU,18446744073709551606LLU,8930312330755964927LLU,8572315695517957869LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{9223361667327092635LLU,18446744068668216282LLU,18446661117488086239LLU,18446744034285114195LLU,18137400716231028607LLU,18446744069111412585LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{16140901064495857664LLU,18446744073709551615LLU,18392700671955304447LLU,17942340915429375999LLU,18158654435046195199LLU,18446744073709551615LLU,18446744073676013567LLU,14657930358486466559LLU,6893791597009786458LLU,72057594037925239LLU},{18446744073709551615LLU,17428719451661658111LLU,16285008006234501127LLU,1134643222802850303LLU,18446708752972251135LLU,2305843009196940272LLU,18410765822013206512LLU,18446743948299383615LLU,17356450295646584831LLU,72057594037927882LLU},{4611686018427387903LLU,18446744073709551104LLU,13835058021459173375LLU,18441677524128759297LLU,18446744073642442797LLU,17870283321406128127LLU,17149697966391426527LLU,18347557255185956846LLU,12643257819517151663LLU,72057594037926589LLU},{18446744073709551615LLU,18446726490113441791LLU,18437860019725664255LLU,18446726540579160063LLU,17870278648213274623LLU,18302629013878730463LLU,18446744073709551615LLU,3888000659156847839LLU,18446732508955131893LLU,72057594037927935LLU},{18439988648490270719LLU,18383693678924529663LLU,7LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709549568LLU,18446739677810524159LLU,9223372028801681407LLU,432345547249021950LLU,71471509729705982LLU},{4341469009993006592LLU,1152912579161489148LLU,18446744073709551615LLU,18374685651277709287LLU,13112371052543869944LLU,18374407199439978495LLU,9259400833252737023LLU,18374687166864818175LLU,18446735827372343295LLU,71837262214020159LLU},{17870283317178254335LLU,18158511223656546815LLU,18446744073709551613LLU,18446744073708503551LLU,18446673705032482815LLU,18437173374745575423LLU,18441659931803779071LLU,16285016235391842333LLU,18374686479663251455LLU,71738733243396091LLU},{18445633566961565695LLU,18442258065186095031LLU,18446744073709551615LLU,18410732868876632063LLU,17253290172451913471LLU,144115170893619199LLU,18446744073709543424LLU,18446744073181003775LLU,18428764825178865423LLU,72056971057750015LLU},{18446744073709551615LLU,18446744073709551615LLU,8064820517299945087LLU,9213086655300239359LLU,9223442405598953435LLU,17274594309756157951LLU,15843627050586864571LLU,11492757439514673147LLU,6911829159102633823LLU,58546765065852279LLU},{18446744073709551615LLU,18446744073709551615LLU,18311596480760050687LLU,17329851346525580975LLU,18446734692955152383LLU,18446744038137642423LLU,18446744072635817983LLU,16990902717603905535LLU,17888274556080585978LLU,68664500348518399LLU},{17149003629158350799LLU,8643950780770025471LLU,18446744073709551611LLU,18446744073709551615LLU,9223372036854775807LLU,18408321639876853760LLU,13815917756587833206LLU,9221683186994251767LLU,18302628611024224248LLU,34335307956486143LLU},{18429850624590863999LLU,18307132482828283757LLU,18446744073709551615LLU,18446744073709551615LLU,16058691602271370751LLU,18446744002833678335LLU,18446603337294938111LLU,18392700809998499839LLU,576460752236299263LLU,49415339259199456LLU},{18446735346336006143LLU,18446735273325756415LLU,18446674254721187839LLU,18428729640873885695LLU,18446744073709551615LLU,16068841133995786239LLU,18446671505388466175LLU,18446744034765701119LLU,18149330851320561663LLU,51710306731589614LLU},{16158915463005339647LLU,144115188075855615LLU,144115188075855864LLU,1152921504606322687LLU,13690907681726921664LLU,18446744073709517823LLU,140737488355327LLU,18446743042917252016LLU,18446743927542185983LLU,26036280723746847LLU}};

uint_fast8_t X[18] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[18][10] = {{18446744073709551615LLU,18446744073709551615LLU,3299814108682836855LLU,8001037715416100013LLU,18446624463424806793LLU,9780604347606763670LLU,14546350043746519451LLU,18446744073709551610LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU}};

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
    fputs("[[0,3],[0,4],[0,6],[0,7],[1,3],[1,5],[1,6],[1,7],[2,4],[2,5],[2,6],[2,7],[3,6],[3,7],[4,6],[4,7],[5,6],[5,7]]\n", fout);
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

