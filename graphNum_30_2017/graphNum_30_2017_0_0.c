#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_30_2017_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 29;
static uint_fast32_t endhere = 0;
char str[40] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[30][7] = {{0LLU,18446739675663040512LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,4398046511103LLU,0LLU,18446744073708503040LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446462598733889535LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{0LLU,18446744073441116160LLU,18446744073709551615LLU,16141182539470471167LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446730879838453759LLU,18446744073709551615LLU,2305843009213693951LLU,18446744073709550592LLU,18446744073709551615LLU,274877906943LLU},{0LLU,18446744073172647936LLU,18446744073709551615LLU,17294104044068929535LLU,18446744073705358335LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446691296883015679LLU,18446744073709551615LLU,17293822569102704639LLU,18446744056533876735LLU,18446744073709551615LLU,274877906943LLU},{0LLU,18446744072098873336LLU,18446744073709551615LLU,17870564796338798591LLU,18446708906515235839LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446251492500275207LLU,18446744073709551615LLU,17870283321406128127LLU,18374721664041615359LLU,18446744073709551615LLU,274877906943LLU},{18374686479671623680LLU,18446744069951258607LLU,18446744073709551615LLU,18158795172356292607LLU,72040019030705151LLU,18446744073709551612LLU,274877906943LLU},{72057594037927935LLU,18438299824408231928LLU,18446744073709551615LLU,18158513697557839871LLU,18446726481522458623LLU,18446744073709547523LLU,274877906943LLU},{18302558516889518080LLU,18446744065656029135LLU,18446744073709551615LLU,18302910359895277567LLU,72048815124251647LLU,18446744073707458558LLU,274877906943LLU},{18374756848415801343LLU,18167520896812580863LLU,18446744073709551615LLU,18302628885633695743LLU,18446735277616005119LLU,18446744072637906941LLU,274877906943LLU},{18014257634554675200LLU,18446744057065570191LLU,18446744073709551615LLU,18374967951785721855LLU,72053213171024895LLU,18446743799904342015LLU,274877906943LLU},{18446673842404327423LLU,288230376151711743LLU,18446744073709551615LLU,18374686479671623679LLU,18446739675662778367LLU,18446673979842232318LLU,274877906943LLU},{17437515269298716672LLU,18446744039884652303LLU,18446744073709551615LLU,18410996740214751231LLU,9295427449049187327LLU,18437807106833256447LLU,274877906943LLU},{18446743936807469055LLU,18446744073709551615LLU,18446744073709551488LLU,18410715276690587647LLU,9223369837831389183LLU,17302829630917967871LLU,274877906943LLU},{16284030264441569280LLU,18446744005522816527LLU,18446744073709551615LLU,18429011104364494847LLU,13907114566988268543LLU,1148488206077661183LLU,274877906940LLU},{18446744073176875007LLU,18446744073709551615LLU,18446744073709518975LLU,18428729675200069631LLU,13835056955770470399LLU,18442240405362442239LLU,274877906691LLU},{13977060253657661440LLU,18446743936799144975LLU,18446744073709551615LLU,18438018166180282367LLU,16212958125957809151LLU,1150740040251215871LLU,274877899006LLU},{18446744073705422847LLU,18446744073709551615LLU,18446744073692807167LLU,18437736874454810623LLU,16140900514740011007LLU,18444492239535996927LLU,274877652989LLU},{9363120232081520640LLU,18446743799351801871LLU,18446744073709551615LLU,18442521216051838975LLU,17365879905442579455LLU,1151865957337993215LLU,274873970943LLU},{18446744073709488127LLU,18446744073709551615LLU,18446744056546459647LLU,18442240474082181119LLU,17293822294224781311LLU,18445618156622774271LLU,274814988286LLU},{135240188929109888LLU,18446743524457115663LLU,18446744073709551615LLU,18444770816842268671LLU,17942340795184964607LLU,10375800952736157695LLU,274406308095LLU},{18446744073709549695LLU,18446744073709551615LLU,18446708906517331967LLU,18444492273895866367LLU,17870283183967166463LLU,9222809078311387135LLU,271117711359LLU},{126224176333836016LLU,18446742974667743246LLU,18446744073709551615LLU,18445887920656089087LLU,18230571240056157183LLU,14987768450435239935LLU,261790891263LLU},{18446744073709551503LLU,18446744073709551615LLU,18302664070005784575LLU,18445618173802708991LLU,18158513628838359039LLU,13834776576010469375LLU,223068814335LLU},{108192151143288028LLU,18446741875088998412LLU,18446744073709551615LLU,18446415686237421567LLU,18374686462491753471LLU,17293752199284781055LLU,201796091647LLU},{18446744073709551603LLU,18446744073709551615LLU,144115188075855871LLU,18446181123756130240LLU,18302628851273955327LLU,16140760324860010495LLU,128714276351LLU},{18446744073709551613LLU,18446744073709551615LLU,18446744073709551615LLU,18446462598731792447LLU,18374686462491753471LLU,17293752199284781055LLU,201796091647LLU}};

static uint_fast64_t D[30][7] = {{18446744073709551615LLU,297901680429629439LLU,144150389644624001LLU,18446579879972438080LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{72128100762192022LLU,18446739675931508744LLU,18446744073709551615LLU,18446626792469954559LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18374615972947359593LLU,18148846791057965047LLU,18302593684064927614LLU,18446744073709551551LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,893669856916799487LLU,432451168933872003LLU,2305678815477629120LLU,18446744073709550592LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,17850967101129359359LLU,18158443294420303613LLU,16141182539469422463LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,2085100656774873087LLU,1009052727512368007LLU,4611521824695517632LLU,18446744056533875712LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,17255260496756473855LLU,17870142515131055611LLU,16140901064483274495LLU,18446744073705358335LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,4467012278444621823LLU,2162255844669360015LLU,9223207843139683264LLU,18374721646872230912LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,16064339869756751871LLU,17293540956552559607LLU,13835058055231831551LLU,18446708906513137663LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,9214369235646545919LLU,4468662078983344031LLU,18446579880061568960LLU,18374756831252708352LLU,18446744073709547523LLU,274877906943LLU},{18446744073709551615LLU,13690942865058693103LLU,16140337839395567599LLU,9223372036653448191LLU,72022409657450495LLU,18446744073709551612LLU,274877906943LLU},{18446744073709551615LLU,18158518095604350975LLU,9081474547611312063LLU,18446579880330006464LLU,18374827200013663233LLU,18446744072637902855LLU,274877906943LLU},{18302628885633695743LLU,9223372032559546335LLU,13833931605081583583LLU,18446744072904243199LLU,18446673704948596734LLU,18446744073707458555LLU,274877906943LLU},{18446744073709551615LLU,4398046511103LLU,18307099484867248127LLU,18446579881403752384LLU,18374967937535572995LLU,18446673978773729295LLU,274877906943LLU},{18158372960069484543LLU,18446744065119092671LLU,9221119136453615551LLU,18446744070488322047LLU,18446603336187641853LLU,18446743799903289335LLU,274877906943LLU},{18446744073709551615LLU,4398046511103LLU,18311605285669568384LLU,18446579885698727873LLU,18375249412579392519LLU,17302759948303724575LLU,274877906943LLU},{17870001571551510527LLU,18446744056528633727LLU,18442238272907231231LLU,18446744060824641534LLU,18446462598665732091LLU,18437806968316887023LLU,274877906943LLU},{18446744073709551615LLU,4398046511103LLU,18320616887274143744LLU,18446579902878613443LLU,18375812362667031567LLU,17311767697322668095LLU,274877906691LLU},{17293259068319727615LLU,18446744039347715839LLU,18437732472104943615LLU,18446744022169927677LLU,18446181123621912567LLU,1143913755587903455LLU,274877906940LLU},{18446744073709551615LLU,4398046511103LLU,18338640090449838080LLU,18446579971598122951LLU,18376938262842309663LLU,17329783195360555135LLU,274877652743LLU},{16139774062921515007LLU,18446744004985880063LLU,18428720870517112831LLU,18446743867551088635LLU,18445618173534273519LLU,18428728575671664575LLU,274877899003LLU},{18446744073709551615LLU,4398046511103LLU,18374686462491754496LLU,18446580246476095439LLU,18379190063192865855LLU,17365814191436329215LLU,274814746383LLU},{13832804052133347327LLU,18446743936262208511LLU,18410697684504543231LLU,18446743249075765239LLU,18444492273358995423LLU,18410713077633777535LLU,274873966583LLU},{18446744073709551615LLU,4398046511103LLU,18446708889337462784LLU,18446581345987854303LLU,18383693663893978239LLU,17437876183587877375LLU,271060860703LLU},{9218864030557138943LLU,18446743798814865407LLU,18374686479671623679LLU,18446740775174537199LLU,18442240473008439231LLU,18374682081558003455LLU,274403934191LLU},{18446744073709551615LLU,4398046511103LLU,18302628885633695744LLU,18446585744034627583LLU,18392700865296203007LLU,17582000167890973695LLU,220066545471LLU},{18437728061114277631LLU,18446743523920179198LLU,18446744073709551615LLU,18446730879569756127LLU,18437736872307326847LLU,18302620089406455295LLU,261447712735LLU},{18446744073709551615LLU,4398046511103LLU,0LLU,18446603336221196224LLU,18410715268100652543LLU,17870248136497166335LLU,100898045823LLU},{18428712048519003615LLU,18446742974130806781LLU,18446744073709551615LLU,18446691297150894079LLU,18428729670905102079LLU,18158496105103358975LLU,187887976383LLU},{18410680023328455607LLU,18446741874552061947LLU,18446744073709551615LLU,18446532967477018623LLU,18410715268100652543LLU,17870248136497166335LLU,100898045823LLU}};

uint_fast8_t X[30] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[30][7] = {{18446744073709551615LLU,297901680429629439LLU,144150389644624001LLU,18446579879972438080LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU}};

#if UINTPTR_MAX == 0xffffffffffffffff // 64-bit. Hopefully this means the cpu has 'popcnt'.
int counter (uint64_t * buf){
    uint64_t cnt[30];
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
    cnt[28] = 0;
    cnt[29] = 0;

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
    __asm__(
            "popcnt %2, %2  \n\t"
            "add %2, %0     \n\t"
            "popcnt %3, %3  \n\t"
            "add %3, %1     \n\t"
            : "+r" (cnt[28]), "+r" (cnt[29])
            : "r" (buf[28]), "r" (buf[29]));


    return cnt[0] + cnt[1] + cnt[2] + cnt[3] + cnt[4] + cnt[5] + cnt[6] + cnt[7] + cnt[8] + cnt[9] + cnt[10] + cnt[11] + cnt[12] + cnt[13] + cnt[14] + cnt[15] + cnt[16] + cnt[17] + cnt[18] + cnt[19] + cnt[20] + cnt[21] + cnt[22] + cnt[23] + cnt[24] + cnt[25] + cnt[26] + cnt[27] + cnt[28] + cnt[29];
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
    sprintf(str, "[                              ,%5d]\n", this);
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
    str[29] = X[28] ^ 48;
    str[30] = X[29] ^ 48;

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
    fputs("[[0,1],[0,14],[0,15],[1,2],[1,15],[2,3],[2,15],[3,4],[3,15],[4,5],[4,15],[5,6],[5,15],[6,7],[6,15],[7,8],[7,15],[8,9],[8,15],[9,10],[9,15],[10,11],[10,15],[11,12],[11,15],[12,13],[12,15],[13,14],[13,15],[14,15]]\n", fout);
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
