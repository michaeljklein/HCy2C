#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_201_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][9] = {{0LLU,18446744073709551360LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,255LLU,18446744073709486080LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,65535LLU,18446744073692774400LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU,18446744069414584320LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4294967295LLU,18446742974197923840LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU,18446462598732840960LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU,18374686479671623680LLU,17179869183LLU},{18446744073709551615LLU,9077005048965218559LLU,17870283321401997279LLU,18446744072652054397LLU,18446743802990263799LLU,18446674769571870719LLU,18429002214463242239LLU,13904828106654351359LLU,17179869183LLU},{16104300521430450112LLU,18446744073709551607LLU,18437736874190569471LLU,16140900996849057531LLU,18446726756128717823LLU,18442310773016100831LLU,17311819096186150911LLU,4607110933362245631LLU,17179869168LLU},{13761874423898435647LLU,18158478513184718831LLU,18446744073709547454LLU,13835053725955129343LLU,18445635765443362799LLU,18163017157565214655LLU,1152885761887944703LLU,18437593937670569980LLU,17179868175LLU},{9079238981714710527LLU,18442170105271943135LLU,17275808153681780605LLU,18446744073707421183LLU,18375812379578466303LLU,288230096978304895LLU,18446672605317398527LLU,18428448165318360835LLU,17179804671LLU},{18444456539751448575LLU,17861135380435173310LLU,16104871185145118463LLU,9223094959920316407LLU,18446744072619030495LLU,18446744073709551615LLU,18446603318768631744LLU,18410710808834064639LLU,17175740415LLU},{18153938628617699327LLU,17275526425033572223LLU,13762931192011653115LLU,18429011150168390639LLU,13907115647172341694LLU,18446743523885563647LLU,18446744073709551615LLU,18446172188042084351LLU,16915628031LLU},{17861133117994041343LLU,16104292000215334909LLU,9074823617895726583LLU,17311836967612053471LLU,4611686018393300861LLU,18446744064983268848LLU,18446741839781163071LLU,18446744073709551615LLU,268435455LLU},{18446744073709551615LLU,18445635207506657279LLU,18162874325768601599LLU,1116320821955002367LLU,9076969314837331964LLU,17861135384663030799LLU,16104872267476635517LLU,13835058055216070135LLU,16907172847LLU},{18446739742200946559LLU,18446744073709551615LLU,287944433335140351LLU,18373542712667275263LLU,18153939720596356867LLU,17275805971569902590LLU,13834495105312227067LLU,18374686475443698671LLU,16634476511LLU},{18446466992416210941LLU,18375811262614339071LLU,18446744073709551615LLU,18300341897085845503LLU,17861275005459874047LLU,16140615191468507133LLU,18373560578707815927LLU,9079256578195847135LLU,16089083903LLU},{18429011141450530555LLU,13907113415400160255LLU,18446172190207115263LLU,18446744073709551552LLU,17293679598231355391LLU,18410143530379902971LLU,9077004981319498735LLU,18158496380249436159LLU,14998306750LLU},{17311836950163848695LLU,4611681551652878335LLU,18445600579435102192LLU,18154009539450499135LLU,18446744073708519423LLU,13761856969151348735LLU,18154005768603432959LLU,17869175013684805566LLU,12817784701LLU},{1152921470242847727LLU,18446735276525744124LLU,18444491994654833679LLU,17870211835701759999LLU,18428443733391310847LLU,18446744056798117879LLU,17861276122151387135LLU,17222890874971611005LLU,8588869371LLU},{18446744073164158943LLU,18446743934089027331LLU,18446708330855334911LLU,18437593903030075391LLU,16104300379763638271LLU,9076968782261387263LLU,18446466996779352031LLU,16140901064495857663LLU,17043521015LLU}};

static uint_fast64_t D[21][9] = {{18446744073709551615LLU,9076986898297093887LLU,17865636750362081247LLU,17257221886433550205LLU,9076969310406016503LLU,17861134250246273007LLU,16104581856786640765LLU,18444456531042729463LLU,17179869183LLU},{16104300450529402750LLU,18446744073709551607LLU,18149220555482333183LLU,16067699702378774267LLU,18153939445445753851LLU,17275735533015530462LLU,13816462835392962299LLU,18442168988577233903LLU,17179869183LLU},{13761870021488787389LLU,18157351496314764783LLU,18446744073709547454LLU,13688655809938980863LLU,17861257412728454895LLU,16136111452225204157LLU,17220603332422254071LLU,18437593933375469535LLU,17179869183LLU},{9078957498012004091LLU,18370110277379095519LLU,17275236286822342525LLU,18446744073707421182LLU,17292553698324512767LLU,18121912875314831227LLU,9076933579499338735LLU,18428447890440187899LLU,17179869183LLU},{18426442123809881591LLU,13249444899394025406LLU,16103728756022558463LLU,8930633104544956343LLU,18446744072619014111LLU,13761856969151348735LLU,18153869274270070782LLU,18410693216647511742LLU,17179869183LLU},{17001017090687040495LLU,17275517894137737087LLU,13760747282677858283LLU,17869930360716913647LLU,18356386137270644670LLU,18446743523617128183LLU,17861276122151387135LLU,18445046288136249213LLU,17179869183LLU},{17861133184020641759LLU,16104308903025041401LLU,9079150737180588535LLU,18419579504536713183LLU,11492614365462912893LLU,9076969838686993919LLU,18446737441734655903LLU,18446744073709551615LLU,17179869183LLU},{18446744004990074880LLU,18445653358174797823LLU,18167520896812580863LLU,2305843009213693951LLU,18446744073709551612LLU,18446744073709550623LLU,18446744073709297663LLU,13835058055217151999LLU,16907172847LLU},{18446739813101993983LLU,18446726481523507455LLU,576460752303423487LLU,18446744073709551615LLU,18446744073709551367LLU,18446744073709488127LLU,18446744073693298687LLU,18374686475510874111LLU,16634476511LLU},{18446471394825863167LLU,18376938279485308927LLU,18442240474082246655LLU,18446744073709551615LLU,18446744073709535743LLU,18446744073705488383LLU,18446744072669364223LLU,9079256582490947583LLU,16089083903LLU},{18429292625153490943LLU,13979173243358019583LLU,18446744073709551615LLU,17293822569119481793LLU,18446744073709551615LLU,18446744073449504767LLU,18446744007137558527LLU,18158496655127609343LLU,14998306750LLU},{17329851366121668607LLU,9223372036854775807LLU,18446744073709551600LLU,18446744073709547647LLU,4293951487LLU,18446744073709551600LLU,18446739813101993983LLU,17869192605871374335LLU,12817784701LLU},{2305843009213693951LLU,18446744073709551612LLU,18446744073709550623LLU,18446744073709297663LLU,18446744073644539903LLU,1082868629503LLU,18446744073709547520LLU,17224016774878461951LLU,8588869371LLU},{18446744073709551615LLU,18446744073709551367LLU,18446744073709488127LLU,18446744073693298687LLU,18446744069548802047LLU,18446743008557662207LLU,8796093022207LLU,16140901064494809088LLU,17043521015LLU},{68719476735LLU,18446744073709535488LLU,18446744073705488383LLU,18446744072669364223LLU,18446743807421579263LLU,18446675903988629503LLU,18429292625153490943LLU,13907115649320091647LLU,17179869183LLU},{18446744073709551553LLU,17592186044415LLU,18446744073449439232LLU,18446744007137558527LLU,18446727031279321087LLU,18442381211570536447LLU,17329851366121668607LLU,4611686018427387903LLU,17179869168LLU},{18446744073709547647LLU,18446744073708535807LLU,4503599627370495LLU,18446739813085216768LLU,18445653358174797823LLU,18167520896812580863LLU,2305843009213693951LLU,18446744073709551612LLU,17179868175LLU},{18446744073709297663LLU,18446744073644539903LLU,18446744057066553343LLU,1152921504606846975LLU,18376938275190341632LLU,576460752303423487LLU,18446744073709551615LLU,18446744073709551367LLU,17179804671LLU},{18446744073693298687LLU,18446744069548802047LLU,18446743008557662207LLU,18446471394825863167LLU,18446744073709551615LLU,18446742974197923855LLU,18446744073709551553LLU,18446744073709535743LLU,17175740415LLU},{18446744072669364223LLU,18446743807421579263LLU,18446675903988629503LLU,18429292625153490943LLU,13979173243358019583LLU,18446744073709551615LLU,18446462598732845055LLU,18446744073708535807LLU,16915628031LLU},{18446744007137558527LLU,18446727031279321087LLU,18442381211570536447LLU,17329851366121668607LLU,9223372036854775807LLU,18446744073709551600LLU,18446744073709547647LLU,18374686479672672255LLU,268435455LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][9] = {{18446744073709551615LLU,9076986898297093887LLU,17865636750362081247LLU,17257221886433550205LLU,9076969310406016503LLU,17861134250246273007LLU,16104581856786640765LLU,18444456531042729463LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU}};

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
    fputs("[[0,3],[0,4],[0,5],[0,6],[0,7],[0,8],[0,9],[1,3],[1,4],[1,5],[1,6],[1,7],[1,8],[1,9],[2,3],[2,4],[2,5],[2,6],[2,7],[2,8],[2,9]]\n", fout);
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

