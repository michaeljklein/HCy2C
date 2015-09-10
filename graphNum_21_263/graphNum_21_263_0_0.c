#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_263_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][7] = {{0LLU,18446743798831644672LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,274877906943LLU,0LLU,18446744073709547520LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4095LLU,18446673704965373952LLU,18446744073709551615LLU,1073741823LLU},{18442240474082181120LLU,18446673704965373951LLU,18446735827372064767LLU,4611122930934349817LLU,68719476735936LLU,18446744073709551104LLU,1073741823LLU},{4503599627370495LLU,4610558194375196672LLU,18151758285198323708LLU,18446742424441987071LLU,18446744073434824703LLU,18446744004990075391LLU,1073741823LLU},{18445609376703053823LLU,18437737117119930351LLU,16284699593210265599LLU,18446743798831647999LLU,17582039749101338619LLU,18445618238619762541LLU,1073741823LLU},{18376900621178109824LLU,18446743833182945019LLU,18446180573748658175LLU,2305843284091597815LLU,18445687941224070191LLU,1125835446679807LLU,1073741822LLU},{16212588579450216575LLU,11538222244462000542LLU,2276478294456252898LLU,18446744073709551529LLU,10278340249566314495LLU,18446744073709512667LLU,1073676289LLU},{576460752303423487LLU,17834219608349859816LLU,8790709540542670847LLU,17265639887042776735LLU,18446739464806704127LLU,18158504943649398783LLU,1072750579LLU},{18445609376635949055LLU,18149541622544728063LLU,16609275425734000159LLU,18157917487394452991LLU,17302785786181058552LLU,13827185548806061933LLU,1058012671LLU},{571957152743161855LLU,18446640713073418216LLU,18446737218941747199LLU,18428729537643806651LLU,288229139201124291LLU,18158504970184293888LLU,1072750579LLU},{18433233274825211888LLU,2305842905597607743LLU,18446180573731880960LLU,13830554716574053367LLU,18410451376720019263LLU,18303614033789251071LLU,1017085919LLU},{11328766938047043983LLU,18446743916861396731LLU,18446744073709551615LLU,6922032455166803967LLU,4608587957557130469LLU,144114724202609404LLU,872216574LLU},{9205357913220972528LLU,18446640646602096488LLU,18446738919530693119LLU,13812575232844627967LLU,18410504170458050383LLU,18023256716321095171LLU,1022623735LLU},{18446731944520060894LLU,17005057830299893759LLU,16608149800704941967LLU,18050350338554983935LLU,6613138295285088255LLU,12085347340202802789LLU,735051775LLU},{18445195958318267643LLU,9142869583629221895LLU,18446744073709551231LLU,18443902113168728063LLU,17600067342349377528LLU,18441182740670857215LLU,490732815LLU},{18446731944520060894LLU,18445190188901629951LLU,16927913882553315260LLU,18374680980100120575LLU,18446744073709551615LLU,12085347271487520767LLU,735051775LLU},{13799029000565161887LLU,18446744073705357311LLU,16777215LLU,16149908263749808128LLU,4608589780781891071LLU,144114724202609404LLU,872216574LLU},{13799029051504983487LLU,9142869626579812607LLU,1125899906842239LLU,16284998402687086592LLU,17653547589337939453LLU,2300494673267129340LLU,394133310LLU},{13785553437005447091LLU,9216519330634633065LLU,18446738919530823295LLU,16695107486691618816LLU,17689435648869531647LLU,8821841110626074172LLU,502661118LLU},{16861476998432682239LLU,16158915463005339647LLU,4593671583947553767LLU,2305843009213693951LLU,10278269880822136832LLU,18446744073709512667LLU,1073676289LLU}};

static uint_fast64_t D[21][7] = {{18446744073709551615LLU,13850070512169910271LLU,3835052195404632903LLU,13842532160434856150LLU,18446677728626883007LLU,18446744073709551615LLU,1073741823LLU},{5306183451730350313LLU,18446743800766600947LLU,18446744073709551615LLU,4604211913274695679LLU,18446740050048042560LLU,18446744073709551615LLU,1073741823LLU},{13140560621979201302LLU,4596673834482592012LLU,14611691878304918712LLU,18446744073709551401LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,1475349166283554815LLU,8782256751722293244LLU,17067479556626975447LLU,18446721992872311231LLU,18446744004990075391LLU,1073741823LLU},{18446744073709551615LLU,16985209446395281407LLU,13204545482543176519LLU,1386173885474665976LLU,24454956580800LLU,18446744073709551104LLU,1073741823LLU},{17874680457384161280LLU,13835058054715833535LLU,18417451432546646498LLU,4611686018427387877LLU,13826120623448783919LLU,6150791191047692795LLU,1073702557LLU},{16717053945015398399LLU,16140901339069938638LLU,144007380101758975LLU,18446744073709551547LLU,14033203242733387771LLU,18446362474312056783LLU,1073715555LLU},{18443364174931820543LLU,18446743800979103739LLU,18445899648766771199LLU,16140901064495857919LLU,18446744073709551615LLU,12296334482416205437LLU,1073741822LLU},{18446744073642442752LLU,18158513662660738239LLU,18311616843434671619LLU,4322859706973419517LLU,18158548332048154620LLU,10944872994417147903LLU,1057979551LLU},{4397135978037247LLU,13222568505829752824LLU,9221119962178380286LLU,17265639887059550087LLU,13835057793287053359LLU,8745990450466243067LLU,1072744433LLU},{18446744073709551615LLU,1799610228702477503LLU,18303165446183976448LLU,17942305983267075063LLU,18446691279838150079LLU,10944872952232567295LLU,1057979551LLU},{9655717326258948607LLU,18446744054273659903LLU,144007380101758975LLU,18446743901607903163LLU,213919728303077361LLU,18446453321577791484LLU,872207227LLU},{18446436210450595839LLU,274072338190LLU,18446744073692774400LLU,18446744059750907903LLU,18392634907483389951LLU,18446512075279445967LLU,1017068999LLU},{18302628885621099007LLU,17940511310907207935LLU,993953142800383LLU,17942340863501746175LLU,18372434662678134269LLU,10952463986157908991LLU,862974015LLU},{3975763179076859LLU,4503599077614649344LLU,9221120237039517695LLU,17290444319617949575LLU,18446744073433776191LLU,9187341040808362495LLU,502660865LLU},{18446739899001339870LLU,16717355219599491071LLU,18445618173819355630LLU,18311530531770859519LLU,2298733571306684399LLU,16257993941725478643LLU,737855487LLU},{18446216237261257979LLU,18318382688236470271LLU,4593671516232743799LLU,554206422195765120LLU,11833630233379995648LLU,9187341040812556186LLU,502660865LLU},{7776137650989512441LLU,18446743956804992774LLU,18446744073709551615LLU,13832087707899060223LLU,18392632707046641498LLU,18446512075279445967LLU,1017068999LLU},{7777681642612406268LLU,16717355145649717246LLU,18446744073709421038LLU,13834806265438470143LLU,16136256744559996751LLU,18419703225398587331LLU,786108407LLU},{16861477000512996351LLU,16284875514009649151LLU,18446612126945509358LLU,18374680980100120575LLU,16134075296311672831LLU,17870256932594345983LLU,734986495LLU},{13786069142183935894LLU,9217366780295483241LLU,16928040742853439165LLU,18446744073709547647LLU,18446744073709551615LLU,12296334482416205437LLU,1073741822LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][7] = {{18446744073709551615LLU,13850070512169910271LLU,3835052195404632903LLU,13842532160434856150LLU,18446677728626883007LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU}};

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
    fputs("[[0,1],[0,9],[0,12],[1,4],[1,8],[2,3],[2,5],[2,12],[3,4],[3,7],[4,6],[5,6],[5,9],[6,11],[7,8],[7,10],[8,13],[9,10],[10,11],[11,13],[12,13]]\n", fout);
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
