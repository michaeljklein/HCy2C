#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_632_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][5] = {{18446709027850158079LLU,18446744073709551615LLU,18428729675216846847LLU,144115119356379199LLU,4611684918932537216LLU},{18446744073709551615LLU,15LLU,18446744073709551360LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,255LLU,18446744004990074880LLU,4611686018427387903LLU},{18446744073172680704LLU,18446744073709551615LLU,18401556204573687295LLU,18302628919414085119LLU,4611686018427387903LLU},{536870911LLU,18446744073701163024LLU,18446744073709551615LLU,144115188075855871LLU,4611686018427371520LLU},{18446744073172680705LLU,8388607LLU,18446744073709551360LLU,18302628954353172479LLU,4611686018427387903LLU},{18446744073709551615LLU,13834459884315213823LLU,18428729675200069855LLU,18406032868984750079LLU,4611686018419015679LLU},{18446743937344339967LLU,18446744073709551615LLU,18014398509481983LLU,144115119356379136LLU,4611686014140809215LLU},{18446708889765405177LLU,16474152593463967647LLU,18446744073709551603LLU,144115188075855871LLU,4611684918932537216LLU},{35184372088831LLU,18446744073701163120LLU,72057594021151743LLU,18446744073709551552LLU,4611405642958110847LLU},{18014398509481951233LLU,18446462598741131263LLU,18433233273820807167LLU,18446603353401061631LLU,4607445736751890431LLU},{9222316505155272703LLU,281474975135870LLU,18446740775174668032LLU,18302769623109468159LLU,4544058287748759551LLU},{18446709026703797243LLU,17131683086879162303LLU,18428729675216846839LLU,18446744073709551615LLU,4611684923206532992LLU},{0LLU,18446744073709551600LLU,18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18374712281662488575LLU,2305843009213661311LLU,13906271211504993278LLU,13533316877027065855LLU,4368475145874717789LLU},{72053178811547527LLU,18446744056588435440LLU,4611633241852542975LLU,16140899002710228928LLU,3745886582247506927LLU},{17943466815325700223LLU,2305561551416723455LLU,14123288430628507646LLU,18433094736362337279LLU,4392104741643549951LLU},{5133892468967743463LLU,18158531288735260286LLU,18446744073708765183LLU,18444527045951094780LLU,3156907890064078847LLU},{18445897992534751743LLU,288228452006361599LLU,18446740501370502912LLU,17440180760885596159LLU,2179739899895185401LLU},{16140867950296039423LLU,18163017297185210367LLU,18428729950077190143LLU,1151232586028154876LLU,3157022303968032647LLU},{4610840489187344287LLU,18446744057595558384LLU,18446743815995784961LLU,17744180882571329475LLU,1692577170184949755LLU}};

static uint_fast64_t D[21][5] = {{7003167788877356551LLU,2301356726953181304LLU,18446744073709551374LLU,18324610459535147007LLU,4611405642958127103LLU},{11443576422916947966LLU,18446744073709551607LLU,12275235447905102335LLU,18446744033333515690LLU,4611686018427387903LLU},{7003167650792603649LLU,4943442119969734680LLU,18446744073709551523LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073701163023LLU,6194102560372381695LLU,144115177201958741LLU,4611686018427371520LLU},{18446744073709551615LLU,13503301953739816959LLU,18378962270005754972LLU,18302628901944541439LLU,4611686018427387903LLU},{11443576422916947967LLU,18446744073709551607LLU,67781803703796735LLU,144115171765010176LLU,4611686018427371520LLU},{16966607771452880045LLU,8564645201500089050LLU,18446744073709551547LLU,144115188075855871LLU,4611686014140809215LLU},{8483303816684063571LLU,10213256802784859453LLU,18446744073709551559LLU,18406032868984750079LLU,4611686018419015679LLU},{18446744073709551615LLU,13832067200447414271LLU,18014398492704862LLU,18324610459535146944LLU,4611405642958127103LLU},{18446744073600623097LLU,16145387346756370431LLU,18433005465534201841LLU,18424762516118946047LLU,4611684918932537343LLU},{2304739599903096831LLU,18446744073707976830LLU,18229722679068587007LLU,11817445418982981616LLU,4544058287748753233LLU},{17928807764478394367LLU,18446744073709453303LLU,271289099921133567LLU,6773413774939385871LLU,4607445736751880366LLU},{16966607908391272111LLU,9219783011047484154LLU,18014398509481790LLU,18365321664259948480LLU,4611405642953916415LLU},{18446744073709551615LLU,13503301953739816943LLU,6171508625804449372LLU,18446744045366110805LLU,4611686018427387903LLU},{18446739658382114689LLU,18415218859146477567LLU,18433167097770016753LLU,16122321533937122559LLU,3746149736357298159LLU},{18446734691320455679LLU,36011479710826495LLU,18445685227100569598LLU,13529912788209566719LLU,4368491267739353053LLU},{2305835282466471935LLU,18415218876316385278LLU,18446673722141310961LLU,14392941458854313968LLU,3706391883122993123LLU},{18442238542420638207LLU,18446742149564202999LLU,17582052670380691455LLU,17437928961084489743LLU,2232096500639325944LLU},{13844043178404978663LLU,18446480189911736319LLU,1135980229445042175LLU,6917422997582118908LLU,3167938738323059119LLU},{18005672784776132639LLU,2305840811257782769LLU,17582052945241820942LLU,18325129841340317647LLU,2231931638568869631LLU},{18383667187566479359LLU,18194263218623324159LLU,14970035529318350847LLU,4610436904767190015LLU,3303380694104669599LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][5] = {{7003167788877356551LLU,2301356726953181304LLU,18446744073709551374LLU,18324610459535147007LLU,4611405642958127103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU}};

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

    } else {
        A[i][0] = A[i-1][0] & D[i][0];
        A[i][1] = A[i-1][1] & D[i][1];
        A[i][2] = A[i-1][2] & D[i][2];
        A[i][3] = A[i-1][3] & D[i][3];
        A[i][4] = A[i-1][4] & D[i][4];

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,6],[3,7],[4,6],[4,8],[5,9],[5,10],[6,7],[7,11],[8,9],[8,12],[9,13],[10,11],[10,12],[11,13],[12,13]]\n", fout);
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
