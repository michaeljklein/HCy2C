#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_18_1162_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 17;
static uint_fast32_t endhere = 0;
char str[28] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[18][11] = {{137438953471LLU,18446744073709027328LLU,18446181123755081731LLU,18412967074356788767LLU,18446744056529616895LLU,18437736702790336511LLU,18444479079706001407LLU,18338657674012129791LLU,1099511627774LLU,18446744073709551104LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,1LLU,0LLU,18446744073709551612LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU,0LLU,18446744073709551608LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,7LLU,0LLU,18446744073709551600LLU,18446744073709551615LLU,67108863LLU},{18446743936270598144LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,13835023684738178815LLU,3458535815271727100LLU,16032814534917353439LLU,17842126615324122735LLU,18446742974197923851LLU,18446744073709551615LLU,67108863LLU},{0LLU,0LLU,18446744073709551614LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,524287LLU,18311600625639489534LLU,18446743558179258367LLU,18401743261673717247LLU,18446744073709551487LLU,18014204995435495231LLU,18446460948727201787LLU,18446744073709551615LLU,18446739675663041023LLU,67108863LLU},{18446462598732316673LLU,18429855574033170191LLU,274877906943LLU,18446744073708503040LLU,18445611576707776511LLU,9169328837006064895LLU,18446744039349682175LLU,18428729331871121407LLU,18446708889333268495LLU,18444496646172557308LLU,67108863LLU},{18379172349674520575LLU,18446743815944404991LLU,18446744073709551615LLU,1048575LLU,18230474534572523420LLU,18446602511218376701LLU,18356742449637882879LLU,18446744073709551359LLU,18392697579650416639LLU,17296074368891223039LLU,67108863LLU},{4575648628772427711LLU,14978919446604627839LLU,17564038512114531319LLU,18225501374760088503LLU,18446743523953737729LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16140620618163544063LLU,990474158087209343LLU,67108848LLU},{18446744069414567935LLU,18374685371603615743LLU,18444488975348400127LLU,12970366918224433151LLU,549755813887LLU,18446744073707454464LLU,18437736874450616335LLU,14123288397074075647LLU,18446743660841662415LLU,18155694437961957375LLU,67104783LLU},{18156270693803622271LLU,18446744073709550591LLU,14987825628261121999LLU,18446660510238638078LLU,18446744073709551615LLU,2097151LLU,1152357455145992184LLU,18446678100864401407LLU,18203831155738754367LLU,18406132512226017266LLU,66064383LLU},{18445616524528975871LLU,15708555495966992383LLU,18446744065119584255LLU,18302626669497679871LLU,18442240474080083975LLU,16285016235391813631LLU,1099511627775LLU,18446744073705357312LLU,18442223909534171135LLU,981783206936174927LLU,63831551LLU},{7493912814130560999LLU,18446702291974094847LLU,17865797313897692927LLU,18446744073709549567LLU,9799550764427771903LLU,18446711087286976511LLU,18446744073709551615LLU,4194303LLU,15274820153342939376LLU,18446409820697665535LLU,54517712LLU},{2251794512084991LLU,4539628423869366264LLU,18446743867546918974LLU,17842153415912718335LLU,9007178048339967LLU,18437736872374435808LLU,18446743249059021048LLU,14911488734934335487LLU,9232379210331324415LLU,18084202035962642431LLU,45612813LLU},{18446744073709531391LLU,18446250384930897927LLU,4611683817784090623LLU,18446744073709543024LLU,18446744073709470719LLU,18444773579202494495LLU,18446735271136362495LLU,18446744073709501376LLU,9223372036854677471LLU,16140192976789827072LLU,32469247LLU},{18446607605385134079LLU,18446181132345605119LLU,18446744071578058735LLU,1152912296163409919LLU,18446198200411881468LLU,18444492308253769599LLU,18446744065183580095LLU,4611632142223409151LLU,18444913661693657072LLU,17829750920469020407LLU,25102327LLU},{18156401535720390527LLU,562949953421304LLU,16032805604615514078LLU,18446744073708519423LLU,18402266629340790271LLU,2251799813685219LLU,4323419366981869432LLU,18446744073705422847LLU,13684178671669084031LLU,9222162578359189503LLU,47251327LLU}};

static uint_fast64_t D[18][11] = {{18446744073709551615LLU,18446744073709551615LLU,18304818013284597759LLU,4179339912794662911LLU,18437737011648920671LLU,540158726644957183LLU,17879079172031119119LLU,17582050779784007679LLU,18446743041197991529LLU,18446743188082078719LLU,67108863LLU},{8355075060016349182LLU,11312370448594793462LLU,18446744073709551615LLU,18446744073709551615LLU,13244205457654700279LLU,12535397872955996122LLU,11204954349130698270LLU,12023387111193221998LLU,18446744073709551611LLU,18446744073709551615LLU,67108863LLU},{14816842583578044867LLU,17538973426842324379LLU,8996396933939866746LLU,16084288543963970779LLU,18446744073709551614LLU,18446744073709551615LLU,17646866956688556023LLU,18246049364023440603LLU,18446744073709551606LLU,18446744073709551615LLU,67108863LLU},{13721570503824709181LLU,8042144271981985389LLU,11186941093446538119LLU,16631202779975097143LLU,18046805515199053817LLU,9123024682011720301LLU,18446744073709551611LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446743798831644673LLU,18446744073709551615LLU,17239779304313452527LLU,18144435344516837175LLU,9223303295766806013LLU,6917071630543454201LLU,1855877771151015934LLU,18446740561290513511LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,16710150120032698365LLU,4177996823480035308LLU,5602477174565349135LLU,15235065592451386807LLU,8041666841599848941LLU,6624051672202440629LLU,18446744073709551613LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,16716370057311027199LLU,18411623469511867916LLU,2161727787834937279LLU,18446744039351655932LLU,14984038910151222271LLU,18305430426228881447LLU,16590867335070095775LLU,18446744073709551512LLU,67108863LLU},{18375781043497074687LLU,11313041993252107263LLU,18446744073709551615LLU,18446744073709551615LLU,18162911622870335367LLU,18014397426746779647LLU,18428729949588289724LLU,1080317453289914367LLU,18378483093322334206LLU,17296070864191289447LLU,67108863LLU},{8358185028655513599LLU,18429183771610709766LLU,18446744073709551615LLU,18446744073709551615LLU,16715391491930386943LLU,18376087249969216531LLU,4323455575669874559LLU,18446744004993760248LLU,1870058172614443007LLU,18444496638453452796LLU,67108863LLU},{18005391292912041467LLU,18336122724234820059LLU,9151297257544855422LLU,11511094819499704062LLU,18446744073709551615LLU,18446744073709551615LLU,18446742974197923847LLU,18446744073709551615LLU,18212556609554448143LLU,18439975368350760946LLU,66479727LLU},{18444492308194393879LLU,14109711455695667199LLU,13978399126572761027LLU,18439971628884688799LLU,18446744073709551612LLU,18446744073709551615LLU,573324945141006335LLU,18392632696495668479LLU,18437737967389744630LLU,8016300683017846783LLU,66691062LLU},{1098878300752675823LLU,18446744065120079679LLU,18416309591836752127LLU,17329006825093186035LLU,18446744073709551615LLU,18446744073709551615LLU,18216893366946234367LLU,13976639091756697563LLU,16140900857799768063LLU,11096025056906576255LLU,67107225LLU},{16212571600141156321LLU,9219985814442344399LLU,18442240542679236142LLU,9772678837681782783LLU,9510034509425278975LLU,9196316348247834239LLU,18446744073709551611LLU,18446744073709551615LLU,17364753979765944335LLU,18446713278290198526LLU,53987279LLU},{18431526832773151871LLU,17887875449401368825LLU,2197756601505351647LLU,18446744056530607742LLU,18331818720327892991LLU,16211691582733124589LLU,18446744073709551615LLU,18446744073709551615LLU,18424226074502070271LLU,18430980959607193539LLU,63732863LLU},{18446743970628235295LLU,18144448744811134975LLU,4503589024169983LLU,9079256847738732528LLU,18446743661384286332LLU,16679116404321943551LLU,18014356096679935LLU,18428729671039320000LLU,18446743454999252977LLU,14987732973468493823LLU,32325623LLU},{18446744072643805175LLU,576456148081704959LLU,18446471137060716542LLU,18445618190981658623LLU,18446744069446565855LLU,2305816071111704575LLU,18445652327114211320LLU,18442240542797987583LLU,18446744040421194879LLU,9097267398712392703LLU,45342716LLU},{2305841908892045311LLU,18446744073709547320LLU,18446744073709511167LLU,18445756696152244239LLU,9223367635568181247LLU,18446744073709526496LLU,18446744073709389823LLU,18442803084695437375LLU,10376245142804889599LLU,4609715693590413277LLU,48233789LLU},{17239774839162532847LLU,18446744073709035519LLU,17866058997731229439LLU,1125899906842609LLU,11385081720345710524LLU,18446744073707487231LLU,18357789184972028927LLU,4503599627370439LLU,17834040153979409360LLU,15132094747964866111LLU,25162707LLU}};

uint_fast8_t X[18] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[18][11] = {{18446744073709551615LLU,18446744073709551615LLU,18304818013284597759LLU,4179339912794662911LLU,18437737011648920671LLU,540158726644957183LLU,17879079172031119119LLU,17582050779784007679LLU,18446743041197991529LLU,18446743188082078719LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU}};

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
        A[i][10] = A[i-1][10] & C[i][10];

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
        A[i][10] = A[i-1][10] & D[i][10];

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
    fputs("[[0,1],[0,2],[0,3],[0,4],[1,2],[1,5],[1,6],[2,7],[2,8],[3,4],[3,5],[3,6],[4,7],[4,8],[5,7],[5,8],[6,7],[6,8]]\n", fout);
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

