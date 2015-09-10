#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_763_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][6] = {{18230566893549264895LLU,17870283321942867967LLU,18437807105759838207LLU,18410715276659130367LLU,288230374004293631LLU,1125899906842368LLU},{18446744073709551615LLU,1048575LLU,18446726481523507200LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU,0LLU,18446744073709551600LLU,1125899906842623LLU},{18446739675663040512LLU,18446744073709551615LLU,18437771921387749375LLU,18391293417331097599LLU,18446744071562067975LLU,1125899906842623LLU},{4398046511103LLU,18446744073173729280LLU,18446735274311412731LLU,16140897765960974335LLU,18158513699705323519LLU,1125899906842623LLU},{18230571291595767807LLU,17870283321407045631LLU,13817043656772681727LLU,18298054917229558766LLU,169574515108478973LLU,1125899906842368LLU},{13835058055282155521LLU,576460752303414767LLU,18446726481523507200LLU,9223345648575709183LLU,18446744073709486095LLU,1125899902648575LLU},{18446743523953688575LLU,1061704644503273471LLU,15384300224510LLU,18446744073709027328LLU,17582052944370361327LLU,1125899374162111LLU},{18410724036208230399LLU,18446744073709551615LLU,18446743523952164863LLU,524287LLU,16140892270550319088LLU,1125831723089898LLU},{0LLU,18446744073708503040LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{36028247263100927LLU,2305843008679968768LLU,9007197107257342LLU,16140897765960450048LLU,17293831365195726847LLU,1125899374162111LLU},{11817445283954950081LLU,549305151219029487LLU,17906312118425059328LLU,18446744073709158399LLU,18302576108778814991LLU,1124868774920447LLU},{18446477991895228479LLU,18014398477269729151LLU,18446726481523539967LLU,9223345098853449631LLU,18444492208397156863LLU,1109403470168063LLU},{16681614494220156867LLU,18446638520592760831LLU,17906311568667672577LLU,549755420671LLU,18302567381685239312LLU,1124804689006591LLU},{9151314442682636543LLU,18446735278010613758LLU,11528722262593044479LLU,18446744047933431807LLU,252060841636055039LLU,1066525062594558LLU},{18300935637861138419LLU,17870292117432038399LLU,18438299824408100743LLU,18401743261782768127LLU,18437736459998855071LLU,914574563868417LLU},{28146741750513663LLU,11502193035958026208LLU,6614661952698879LLU,15053280654974255096LLU,13545708650901798911LLU,826420397857951LLU},{18446691284266483327LLU,9221683186490146847LLU,18445618171120451582LLU,18446741872672505863LLU,17583178832209245183LLU,489282170647543LLU},{2301128303353520639LLU,11529215020273500000LLU,576443160654248447LLU,17582034805460041624LLU,18443435591681642495LLU,813635354483967LLU},{17260045571226860495LLU,18446629758860001279LLU,18013976245476229247LLU,9007173478645759LLU,2305799578479746672LLU,1072246101549054LLU},{18301357867371587575LLU,13260849077005844449LLU,9216599113947021215LLU,18438281716809334776LLU,18445899337528197055LLU,694743152459023LLU}};

static uint_fast64_t D[21][6] = {{9785776632508710911LLU,2305843009213156455LLU,16176916113733968376LLU,288195320762459673LLU,18277169560748556287LLU,1125899902648575LLU},{14339468246343630846LLU,18446744073708923442LLU,5386340338707202047LLU,10822951082065611955LLU,18446744073709551606LLU,1125899906842623LLU},{4107275827365920769LLU,17531584583078352333LLU,18446733723691428523LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,2305843008677871615LLU,13060425171593585144LLU,14551056038740407116LLU,18158513699705323517LLU,1125899906842623LLU},{18446744073709551615LLU,17056060555128733695LLU,18437752035416498007LLU,9158184062486052863LLU,18446744071562067971LLU,1125899906842623LLU},{9785776632508702720LLU,18446744073709014119LLU,16933499414540976127LLU,4015772339923578555LLU,18446744073709486087LLU,1125899902648575LLU},{18172576887003299839LLU,18446744073709321146LLU,2269884580938907647LLU,15881835234237749734LLU,169574515108478972LLU,1125899906842368LLU},{18410717420313506691LLU,18153653765966659583LLU,18446734417463585451LLU,18446744073709551615LLU,16140892270550319103LLU,1125831723089898LLU},{4107281893504781437LLU,439635461614966221LLU,18446740622294188030LLU,18446744073709551615LLU,17582052944370361327LLU,1125899374162111LLU},{18446744073709551615LLU,915159490631827455LLU,13060414085020472660LLU,7623792991643939660LLU,18446744073709551609LLU,1125899906842623LLU},{18446741819285959555LLU,18007108612098359295LLU,18446742991375703559LLU,9158184062486052863LLU,16140901063232429075LLU,1125831723089898LLU},{18446468051125207039LLU,18014398477269696314LLU,2300143140935303167LLU,18446743523954237318LLU,14948150783038324735LLU,1109403474329442LLU},{16154974056446115839LLU,18419588472624968703LLU,17876053558428696575LLU,15881835234270411263LLU,3521747975536639996LLU,1124868774952861LLU},{9007195118686964863LLU,17904623234548842264LLU,2300139689519939583LLU,18446744073709526918LLU,16389302729764791295LLU,1109407039487799LLU},{17868154666894753779LLU,4611686018359750887LLU,18338643938731622273LLU,18437737011490715769LLU,18288537024921075615LLU,914574560553471LLU},{1139305152608467199LLU,16140901064353189758LLU,9367487156243653118LLU,288230342328813471LLU,18390199463458097151LLU,1066525061715711LLU},{18446689081921240603LLU,18012280843644436479LLU,18445618173265846247LLU,9222941026170175487LLU,18446744059645915347LLU,489243482292210LLU},{18438862516118615015LLU,18412860982222127103LLU,18444350454075750431LLU,17294367798002188287LLU,11529213121501830975LLU,826391435141071LLU},{18428166708075134939LLU,18444492823315149823LLU,18444773748872552423LLU,18410185312072923647LLU,8421726767565242064LLU,491923743703024LLU},{18302466419905785727LLU,4069565213165219841LLU,9217726042467074047LLU,18446743660990035968LLU,18429011109844319231LLU,904897949989175LLU},{17266765786840530655LLU,18446735826968645631LLU,18014117034000877566LLU,1152919303968262143LLU,8376653516871038704LLU,524982039525374LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][6] = {{9785776632508710911LLU,2305843009213156455LLU,16176916113733968376LLU,288195320762459673LLU,18277169560748556287LLU,1125899902648575LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,4],[1,5],[2,4],[2,6],[3,5],[3,7],[4,8],[5,9],[6,7],[6,10],[7,11],[8,11],[8,12],[9,10],[9,13],[10,12],[11,13],[12,13]]\n", fout);
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
