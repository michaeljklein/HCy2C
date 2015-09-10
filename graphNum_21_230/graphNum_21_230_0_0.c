#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_230_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][10] = {{18446744073709551615LLU,17179869183LLU,18446726481523507200LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{562949953421311LLU,18446744056529682432LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446181123756130304LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU,18428729675200069632LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU,0LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,0LLU,18446744073709550592LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU,18446744073708503040LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1048575LLU,18446744072635809792LLU,255LLU},{18446744073709551488LLU,18446741909046034431LLU,18444527458267955199LLU,16176929861514821631LLU,18446744073709551615LLU,18446744073709551489LLU,18446744073709422591LLU,18446744073577431039LLU,18446744006063816703LLU,255LLU},{18445618173802692735LLU,18446744073168453373LLU,18304880685447380991LLU,2304699237947408383LLU,17275522297033129976LLU,18154009548174647423LLU,13834495105320484798LLU,17870283312950344687LLU,18446739744314343167LLU,255LLU},{18156261897742073855LLU,18446605534162255359LLU,18446742956745424383LLU,18446744073709551615LLU,16104309247730253319LLU,17870211853149806591LLU,18373560579236298621LLU,17293822027936692191LLU,18446466996643004411LLU,255LLU},{17865779721512419327LLU,18437877609778774011LLU,9367484991010700287LLU,18444456539699806207LLU,18446744073709551615LLU,18437593937910169599LLU,9077005015142366971LLU,16140866429879316479LLU,18429011149904150007LLU,255LLU},{17284815335756660735LLU,17879290516332346359LLU,9223367570080266239LLU,18442170096611753952LLU,13762991525564744191LLU,18446744073709551615LLU,18154007933266952191LLU,13832841439840042942LLU,17311836967075249135LLU,255LLU},{16122882302299602943LLU,576460743713224687LLU,18446735276525744126LLU,18437735757490681887LLU,9222228265586950143LLU,17275522295456071679LLU,18446744073709551103LLU,9081508648592605183LLU,1152921504598325215LLU,252LLU},{13798470706356289535LLU,18446744073641914335LLU,18446743934089027457LLU,18446601102292813823LLU,18300341342970052607LLU,16104300386138980351LLU,17861137583686287351LLU,18446744073709543293LLU,18446744073709551615LLU,3LLU},{9295411900185509885LLU,18446744073709551615LLU,17870212952661950463LLU,18374686478614650749LLU,18446742991369271263LLU,18445635757262471163LLU,17311828031899168767LLU,18437593903579267071LLU,16104300520356708288LLU,247LLU},{9223336575440518651LLU,16104309248803995584LLU,18446744073708519415LLU,9079256848778919935LLU,18446674804459958271LLU,18375812362125966839LLU,1152903633247395839LLU,18428443801631588348LLU,13761874421750951999LLU,239LLU},{18446673150914460663LLU,13762991527712251967LLU,18437596136900394991LLU,18446744006063800059LLU,18446744073709551615LLU,13907115614423415791LLU,18446708339513475071LLU,18410152256927170307LLU,9079238977419743231LLU,223LLU},{18446602236675749871LLU,9222228269882941439LLU,17275526691388653535LLU,18158509368230772223LLU,18442310842792279998LLU,18446744073709551615LLU,18446673696239091711LLU,18374677543958593791LLU,18444456531161513983LLU,190LLU},{18446462590075269087LLU,18300341351558938623LLU,16104309046940532671LLU,17870006244475863031LLU,18163017297118093181LLU,4611685949699389407LLU,18446744073709551600LLU,18445600302376681471LLU,18153938611437830143LLU,127LLU},{18446741857371152319LLU,18153938612629012479LLU,13761857244029255678LLU,17276089645569932271LLU,288230376150646523LLU,18446744072618766271LLU,18446742956745358351LLU,18446744073708519423LLU,17861133151280037887LLU,253LLU}};

static uint_fast64_t D[21][10] = {{18373542849057587069LLU,18446744073168453373LLU,17867961152848265215LLU,16067699699174858621LLU,17275522279844739039LLU,18153991947262328699LLU,13816471771106111422LLU,17861133151141559279LLU,18446744073641377534LLU,255LLU},{18446735208355954430LLU,17275522263210262527LLU,18153974913558380411LLU,13799029258263064510LLU,18446744073571073007LLU,18446743931907456765LLU,18446598868364425215LLU,18298053800300118015LLU,18446744073709551615LLU,255LLU},{18302065935680274431LLU,18446744056259133310LLU,18446725923041410815LLU,18428157789533372415LLU,17861133151011602431LLU,9076969589715238910LLU,16104590792500181983LLU,18158513697556758007LLU,18446744073675464573LLU,255LLU},{8932854399475105275LLU,16104307048698543615LLU,18446742956745407991LLU,9079256848778919935LLU,16104308148201582583LLU,17869085935790972407LLU,17220621203790094205LLU,17275522288434673631LLU,18446744073573203899LLU,255LLU},{17865708798981569527LLU,13762850788059512763LLU,18293478714969619439LLU,18444456538626047739LLU,18446744073709551615LLU,18365536309008071663LLU,9076969314232286971LLU,16104308697957396475LLU,18446744073436917239LLU,255LLU},{17284673532545726447LLU,9213221066300709879LLU,8052150191920117727LLU,18153939651740532223LLU,13762921156786519486LLU,18446744073709551615LLU,18153939686100271103LLU,13762956341158608574LLU,18446744073172351983LLU,255LLU},{16122605147992354783LLU,17723880590797436911LLU,16104300516044697535LLU,17861270607140683735LLU,9217724665894494077LLU,12663836210381060063LLU,18446744073709551103LLU,9219976465708220415LLU,18446744073684252639LLU,255LLU},{13799022643878289343LLU,18153938629472808927LLU,13761874146838962172LLU,17293398122709382127LLU,18012110966947299067LLU,16104300518192181183LLU,17861272806163939303LLU,18446744073709526909LLU,18446744073709551615LLU,255LLU},{18375249429625044991LLU,18446744073709551615LLU,18446744073709535487LLU,18446744073693036543LLU,18446744056798117887LLU,18446726756401414143LLU,18429011150176780287LLU,288230376151711743LLU,17275522228850524159LLU,251LLU},{9367487224930631679LLU,17179869183LLU,18446744073709551488LLU,18446744072669364223LLU,18446743008557662207LLU,18445653358174797823LLU,17329851366121668607LLU,18446744073709551615LLU,16104300520356708289LLU,247LLU},{18446744073709551615LLU,18446744073709551552LLU,17592185028607LLU,18446744073709420544LLU,18446675903988629503LLU,18376938279485308927LLU,2305843009213693951LLU,18446744073709551612LLU,13761874421750952063LLU,239LLU},{18446744073709551615LLU,18446744073709543551LLU,18446744073644539903LLU,18014331937488895LLU,18446744073575333888LLU,13979173243358019583LLU,18446744073709551615LLU,18446744073709551367LLU,9079238977419747327LLU,223LLU},{18446744073709551615LLU,18446744073708519423LLU,18446744069548802047LLU,18446739813101993983LLU,18442381211570536447LLU,18446743936270598144LLU,18446744073709551615LLU,18446744073709535743LLU,18444456531161776127LLU,190LLU},{18446744073709551615LLU,18446744073577431039LLU,18446743807421579263LLU,18446471394825863167LLU,18167520896812580863LLU,9223372036854775807LLU,18446603336221197296LLU,18446744073709551615LLU,18153938611454607359LLU,127LLU},{18446744073709551615LLU,18446744056798117887LLU,18446727031279321087LLU,18429292625153490943LLU,576460752303423487LLU,18446744073709551615LLU,18446744073709550623LLU,18302628885633728511LLU,17861133151280037887LLU,253LLU},{18446744073709535487LLU,18446744073709551615LLU,18307114893075021951LLU,4611686018427387903LLU,18446744073709551608LLU,18446744073709543679LLU,18446744073701425151LLU,18446744065388052479LLU,18446739744382517247LLU,255LLU},{18446744073707487231LLU,18446607734267707391LLU,18446744073709551615LLU,18428729675200200703LLU,18446744073709551119LLU,18446744073709043711LLU,18446744073189457919LLU,18446743541133606911LLU,18446466996779352063LLU,255LLU},{18446744073445310463LLU,18438018349431521279LLU,9511602413006487551LLU,18446744073709551615LLU,134217727LLU,18446744073677045759LLU,18446744040423555071LLU,18446709988849090559LLU,18429011150176780287LLU,255LLU},{18446744039886684159LLU,17888297719915610111LLU,18446744073709551615LLU,18446744073709551584LLU,18446744073709519871LLU,137438953471LLU,18446741943405771776LLU,18444562642640044031LLU,17311836967612186623LLU,255LLU},{18446739744382517247LLU,1152921504606846975LLU,18446744073709551614LLU,18446744073709549631LLU,18446744073707519999LLU,18446744071629176831LLU,140737488355327LLU,18307132485260017664LLU,1152921504606846975LLU,252LLU},{18446189919849152511LLU,18446744073709551615LLU,18446744073709551491LLU,18446744073709424639LLU,18446744073579528191LLU,18446743940565565439LLU,18446607734267707391LLU,144115188075855871LLU,18446744072635809792LLU,3LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][10] = {{18373542849057587069LLU,18446744073168453373LLU,17867961152848265215LLU,16067699699174858621LLU,17275522279844739039LLU,18153991947262328699LLU,13816471771106111422LLU,17861133151141559279LLU,18446744073641377534LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[0,4],[0,5],[0,6],[0,7],[0,8],[1,2],[1,3],[1,4],[1,5],[1,6],[1,7],[1,8],[2,3],[2,4],[2,5],[2,6],[2,7],[2,8]]\n", fout);
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
