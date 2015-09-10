#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_778_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][6] = {{17582048547207938047LLU,17870283321942867967LLU,18303719601165303807LLU,18439988674167832575LLU,18446741874753402879LLU,288230376151449663LLU},{18446744073709551615LLU,1048575LLU,18446462598732840960LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU,0LLU,18446744073709547520LLU,288230376151711743LLU},{18446739675663040512LLU,18446744073709551615LLU,18303156651211882495LLU,18438774795983126527LLU,18446741874686297071LLU,288230376151711743LLU},{4398046511103LLU,18446744073173729280LLU,18446735224734742763LLU,13835057849123733503LLU,2199023255551LLU,288230376151711680LLU},{17582052945254416383LLU,17870283321407045631LLU,18158513697557839871LLU,17275522297451233003LLU,12054761812936097723LLU,288230376151449637LLU},{18446744073709518849LLU,576460752303415293LLU,18446462598732840960LLU,18446742424442109951LLU,18446744073642446846LLU,288230375078232063LLU},{18446744039343521791LLU,10082415777236910079LLU,279134152343551LLU,18446744073701163008LLU,18446742757948846079LLU,288230239785696895LLU},{18302637129823420415LLU,18446744073709551615LLU,18446603336196030463LLU,8388607LLU,18410717475713839104LLU,288212920842514431LLU},{0LLU,18446744073708503040LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{144115153709826047LLU,11529215045534744576LLU,144115153716115967LLU,13835057849115344896LLU,36028797018963967LLU,288230239785696832LLU},{1079735810833514241LLU,143983246398709757LLU,9799832789157675008LLU,18338657682646368255LLU,18212274292827623039LLU,287966421412216799LLU},{18446691159711449343LLU,18419722339043245567LLU,18446462598733365247LLU,18446742390216587775LLU,9223358566764117990LLU,284003440072327167LLU},{18446189153197490175LLU,18419722475945324703LLU,18392546946142175231LLU,18446181123764486151LLU,1152782691263840255LLU,272184240047542268LLU},{15997348825710718963LLU,9223258237401300991LLU,16710605592707727232LLU,562949953421311LLU,18338798396510277632LLU,234119010882419199LLU},{18135995699286795263LLU,18446735278002225139LLU,18438826552753913855LLU,16715110016985202681LLU,17864653813334407137LLU,232493894061783095LLU},{8646484674173992719LLU,17870292117490759679LLU,18311636084885817343LLU,18441679723051327487LLU,18446636330159472639LLU,274506819621881853LLU},{135386130884329471LLU,15708555500205375360LLU,69805794224242169LLU,11537799964138667904LLU,13868904321719992319LLU,198000037822315903LLU},{18446726468634278367LLU,13833369198508638335LLU,18428729632283925503LLU,18446743934651596927LLU,4611681551523971071LLU,138767043158073024LLU},{18439953489895589887LLU,16140900935596506496LLU,9223090570467999225LLU,16285015120847829376LLU,4898218747757592575LLU,194780395180130303LLU},{16005775483383839735LLU,13835051457808699391LLU,16712858209102069639LLU,2305842870155771903LLU,18340905080122748928LLU,107474959426124483LLU}};

static uint_fast64_t D[21][6] = {{11444649407752962047LLU,11529215046067931580LLU,576306758507559009LLU,1765408881206256030LLU,6391984459796708990LLU,288230375078232026LLU},{11240991702734831614LLU,18446744073708937370LLU,12394469124477026303LLU,3657817396023184180LLU,18446744073709548237LLU,288230376151711743LLU},{7205752370974720001LLU,17632915035138908005LLU,18446627951442872490LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,11529215045532647423LLU,6052683905390082145LLU,10177849041611338955LLU,2199023255355LLU,288230376151711680LLU},{18446744073709551615LLU,7731358066213388287LLU,18302854968346195935LLU,18438166207472336895LLU,18446741874686296550LLU,288230376151711743LLU},{11444649407752929280LLU,18446744073709013436LLU,12681573600721895423LLU,8861868258861444030LLU,18446744073642445550LLU,288230375078232063LLU},{17378395240236285951LLU,18446744073709336283LLU,17871409221312970751LLU,12071469785345531489LLU,12054761812936095641LLU,288230376151449637LLU},{18302632317773327971LLU,18356314670087798783LLU,18446523603076509354LLU,18446744073709551615LLU,18410717475713843199LLU,288212920842514431LLU},{7205757148658782621LLU,9359016142288019301LLU,18446705343738026495LLU,18446744073709551615LLU,18446742757948846079LLU,288230239785696895LLU},{18446744073709551615LLU,813829038571257855LLU,6052391071499204437LLU,14788926677686367435LLU,18446744073709550898LLU,288230376151711743LLU},{18446743107802672739LLU,9087727931425292287LLU,18446479366251734942LLU,18438166207472336895LLU,18446743190447002086LLU,288212920842514431LLU},{18424163736268865535LLU,18419722339043228891LLU,18391574978274263039LLU,16715109982633850977LLU,2876658592935573473LLU,284003441137569719LLU},{33914400802865151LLU,18014266567804647423LLU,9279667032196907007LLU,13695017451132526591LLU,18166992005949816351LLU,287966421420191821LLU},{14699746983775560689LLU,143974587602395125LLU,16710570195750485888LLU,18446744073709551615LLU,18374685346859290623LLU,234134295613274239LLU},{8646911013968010655LLU,18411278194322698255LLU,18392684350641412607LLU,18446744073709518855LLU,1152921023149834239LLU,272186274259869692LLU},{4538009943273373455LLU,18446744073700635583LLU,11529061114029015167LLU,18338094767052654495LLU,15978366857631006335LLU,274506818770698204LLU},{16107071290732438527LLU,11529215045917412848LLU,7493988680952971233LLU,144115180022299128LLU,8278165870906179552LLU,232493893839749107LLU},{18446726327911119047LLU,18417604808497168383LLU,18428729666610628511LLU,18446717133627850751LLU,18446739293205836262LLU,138753282058211327LLU},{18438014225700335483LLU,8682832776107393023LLU,18372169972433158136LLU,16140935123519406079LLU,18444560973466165247LLU,197996479978995199LLU},{18338516928013795271LLU,18444494472649701375LLU,18415218876317927327LLU,18442207351252951039LLU,18419687158429134879LLU,139496620763890381LLU},{8646625428707188543LLU,17872534992328851343LLU,18338377307184987647LLU,18446215182779678599LLU,14987907128704499711LLU,204771659624497151LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][6] = {{11444649407752962047LLU,11529215046067931580LLU,576306758507559009LLU,1765408881206256030LLU,6391984459796708990LLU,288230375078232026LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,4],[1,5],[2,4],[2,6],[3,5],[3,7],[4,8],[5,9],[6,10],[6,11],[7,10],[7,12],[8,10],[8,13],[9,11],[9,12],[11,13],[12,13]]\n", fout);
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
