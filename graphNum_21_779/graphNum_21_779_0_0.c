#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_779_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][6] = {{18302635481898156031LLU,18446744073709551615LLU,18446603336196030463LLU,2097151LLU,18428730774711693312LLU,1152851410191055359LLU},{18446744073709551615LLU,2097151LLU,18446462598732840960LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU,0LLU,18446744073709547520LLU,1152921504606846975LLU},{18446739675663040512LLU,18446744073709551615LLU,18303156651211882495LLU,18329579010780037119LLU,18446742974197927727LLU,1152921504606846975LLU},{4398046511103LLU,18446744071564165120LLU,18446741732885264619LLU,13835058003742556159LLU,1099511627775LLU,1152921504606846960LLU},{17582052945254416383LLU,17870283321407963135LLU,18158513697557839871LLU,17292956153910373310LLU,3289192333026786811LLU,1152921504606715914LLU},{18446744073709518849LLU,576460752303422703LLU,18446462598732840960LLU,18446743661392691199LLU,18446744073642446846LLU,1152921503533236223LLU},{18446744039343521791LLU,10298323787501797375LLU,272626001821695LLU,18446744073707454464LLU,18446743677071847423LLU,1152921230735171487LLU},{0LLU,18446744073707454464LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{17582048547207938047LLU,17870283323553349631LLU,18303719601165303807LLU,18374123529693036543LLU,18446742974265032575LLU,1152921504606715919LLU},{144115153709826047LLU,11529215043927277568LLU,144115153716115967LLU,13835058003740459008LLU,18014398509481983LLU,1152921230735171472LLU},{1079737458758778625LLU,467952147680984815LLU,9799832789157675008LLU,18429855575105339391LLU,18329509453851263999LLU,1151861434733428727LLU},{18446691159711449343LLU,18419721928202778111LLU,18446462598733365247LLU,18446743652836311039LLU,18446737338127613926LLU,1136014570935025663LLU},{18446187505809092607LLU,18419722475945230329LLU,9169187066594983935LLU,18446603336223170552LLU,18014329102802092031LLU,1092118785759817212LLU},{15997348825710723059LLU,9223339051505934335LLU,16710606417341448064LLU,140737488349183LLU,9169399203628027904LLU,936471645552900735LLU},{18135995699286793727LLU,18446708891014906783LLU,18438814395446329343LLU,16645304222761345439LLU,3455949755512782689LLU,926597971015892495LLU},{8646484674173988623LLU,17870318505761439743LLU,18311635260252096511LLU,18432530137116311551LLU,18446690206220845055LLU,1098026185419260415LLU},{35888008995536863LLU,16138790002044698496LLU,112589990684237311LLU,13835051441032527744LLU,16145387020397506815LLU,846254501374314207LLU},{18439971082078124543LLU,13835058027496996991LLU,18446744030793432057LLU,16285016217807224959LLU,2304996385122942975LLU,501025200728702896LLU},{18446708876451743711LLU,16139211699004634496LLU,9205076171958492671LLU,18446743790778580864LLU,16285011819297177599LLU,833165350236188671LLU},{16005757891201441783LLU,16140874263832821639LLU,16712577841690050439LLU,2305842726282723207LLU,16664440118248976384LLU,711374667917426431LLU}};

static uint_fast64_t D[21][6] = {{7205758796047176093LLU,9682878156078556334LLU,18446695633051851263LLU,18446744073709551615LLU,18446743677071847423LLU,1152921230735171487LLU},{11240990878478598142LLU,18446744073708264273LLU,3171097087622250495LLU,3627426173019804875LLU,18446744073709549101LLU,1152921504606846975LLU},{7205753195230953473LLU,17524961029471315118LLU,18446631222698002602LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,11529215043923083263LLU,15276065652931033185LLU,10230748927463992116LLU,1099511626235LLU,1152921504606846960LLU},{18446744073709551615LLU,7839312071882702847LLU,18302848494555412447LLU,18306461914038796287LLU,18446742974197927686LLU,1152921504606846975LLU},{11444649407752929280LLU,18446744073708436579LLU,12681573600721895423LLU,8887781909618163435LLU,18446744073642444718LLU,1152921503533236223LLU},{17378394415980052479LLU,18446744073709116381LLU,8648037184458194943LLU,12032600004995154334LLU,3289192333026786425LLU,1152921504606715914LLU},{18302629846715903587LLU,18140406660894556159LLU,18446530076867292842LLU,18446744073709551615LLU,18428730774711697407LLU,1152851410191055359LLU},{18446744073709551615LLU,921783044239523839LLU,15275759837098850133LLU,14819317900689746740LLU,18446744073709550034LLU,1152921504606846975LLU},{11444649407752962047LLU,11529215046067354723LLU,9799688506048510049LLU,1870119202084781665LLU,15157552840194388990LLU,1152921503533236213LLU},{18446740636745248355LLU,8763865917638574079LLU,18446479366251734942LLU,18306461914038796287LLU,18446743370835631878LLU,1152851410191055359LLU},{18424162088880472063LLU,18419721928202744797LLU,9168202941419487231LLU,16645304214173489566LLU,12535198777805373281LLU,1136014572004486638LLU},{33916871860289535LLU,18338235469086711807LLU,9279667032196907007LLU,13817151357370623999LLU,9083496273557844223LLU,1151861434737447443LLU},{14699748631700823537LLU,467917512746716847LLU,16710558038442901376LLU,18446744073709545471LLU,9187342940243988479LLU,936537434796195359LLU},{8646911013968012191LLU,18411278097073452536LLU,9169327742349351423LLU,18446744073709428728LLU,18014398268546285567LLU,1092122817060638716LLU},{4538009943273369359LLU,18446744073691660283LLU,11529073271336599679LLU,18429714846206820345LLU,18077246594116776959LLU,1098026184708456437LLU},{16107071290732436991LLU,11529215045598691335LLU,16717345289245032417LLU,144115186062581767LLU,536203233546207200LLU,926597970653216767LLU},{18439967646091638907LLU,8763998245580963839LLU,18446744065119748088LLU,16158809771930025983LLU,18445896760208646118LLU,500996596301234175LLU},{18338516928017444807LLU,18444500657672028159LLU,18414954168893540255LLU,18432661797208063999LLU,18433215617637953567LLU,846213285257666815LLU},{18438014225696685947LLU,8682933483424833535LLU,18372434679857545208LLU,16140909826210392063LLU,9222280494538547199LLU,503754308965530419LLU},{8646625428703673151LLU,17872535093820538879LLU,18338657674597006335LLU,18446612097935613951LLU,18446707858408603647LLU,537614798154506160LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][6] = {{7205758796047176093LLU,9682878156078556334LLU,18446695633051851263LLU,18446744073709551615LLU,18446743677071847423LLU,1152921230735171487LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,4],[1,5],[2,4],[2,6],[3,5],[3,7],[4,8],[5,9],[6,10],[6,11],[7,10],[7,12],[8,10],[8,13],[9,11],[9,13],[11,12],[12,13]]\n", fout);
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

