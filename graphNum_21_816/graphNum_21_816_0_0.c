#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_816_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][7] = {{18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU,0LLU,18446744073642442752LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,33554431LLU,18442240474082181120LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{0LLU,18446744073675997184LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446735277616529408LLU,18446744073709551615LLU,18167309790580047841LLU,18140213356230864895LLU,18445618173835739121LLU,18446744073709551615LLU,3LLU},{8796093022207LLU,18446743798865199104LLU,18446742390048792575LLU,18445618173752311807LLU,1125899906818047LLU,18446744073709550592LLU,3LLU},{18446744073709551615LLU,31981552LLU,17870283321406128127LLU,4539626478765078999LLU,3196429835515721695LLU,18446744073692775198LLU,3LLU},{18014398509481951233LLU,18446744073709539327LLU,18442240474082181120LLU,18442240473679265791LLU,18446743798898556927LLU,18446743798848421887LLU,3LLU},{18446742974172758015LLU,16122851481610092511LLU,4486005424652287LLU,18446743936270598144LLU,18446425139370262527LLU,18446709157231804157LLU,3LLU},{18444509865007972351LLU,18446742424442077183LLU,18446181123756130111LLU,137438953471LLU,18303753960839708672LLU,18442275589684196319LLU,3LLU},{18446735277616562175LLU,274876334064LLU,18176316989834788833LLU,9223370387587333119LLU,18445618448680615923LLU,18446744073692775423LLU,3LLU},{9223380412376521713LLU,17574593857364951039LLU,18442520127959175199LLU,16717335428520214527LLU,1125899906842623LLU,18375495513818791935LLU,3LLU},{9223366539267538943LLU,18446730605732298752LLU,288230367293341695LLU,18337531782695419648LLU,18446744073709522959LLU,17365876029221964800LLU,3LLU},{18293586089622896385LLU,17437726101190213631LLU,18446744073642442752LLU,18441679619938289663LLU,18156116485200609279LLU,14945089808182018047LLU,3LLU},{17005592141410828543LLU,18311631670467348495LLU,1148417905046585343LLU,18446744073441116159LLU,18446638247862730559LLU,4395503342856437745LLU,3LLU},{9225623555348086771LLU,17865779720835039199LLU,18443365272864665855LLU,16717335291081261311LLU,144115183780888575LLU,18379159150500773629LLU,3LLU},{18378926190636105727LLU,18445686893279281151LLU,18392700878181105087LLU,137430565107LLU,16268113735195820031LLU,17279784004554388383LLU,2LLU},{18444767117443070335LLU,4503599487758884663LLU,14987416337142251375LLU,18446744073709551423LLU,18320009938534924288LLU,13182598963661897211LLU,1LLU},{18446744073172707279LLU,18445618384254286332LLU,18392456786599247865LLU,9087841285812781043LLU,18446726652919545855LLU,16861264249374901151LLU,2LLU},{9798135143741783031LLU,1125899101536243LLU,18230571084363593703LLU,18446742837295840255LLU,4502491298108014579LLU,13777610771737608191LLU,1LLU},{18293586501986942735LLU,18446735019884939263LLU,18446744064784076799LLU,18446216308094639872LLU,18156261895730868479LLU,14123214751538306063LLU,3LLU},{18392489771545757695LLU,18445898536382888191LLU,4571153896658959807LLU,562949676630015LLU,16703841431550033727LLU,9069826646701111287LLU,2LLU}};

static uint_fast64_t D[21][7] = {{12247527175012941825LLU,11764919003037206944LLU,18445112774157997761LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{6199216898696609790LLU,18446744073688151647LLU,6350075474592399359LLU,14641954236444487273LLU,18446744073670170977LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,6681825070693744639LLU,12098299898668706110LLU,3804789837265064342LLU,18446744073681823390LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446743798865199103LLU,12102859063472130367LLU,13184806582199672214LLU,1125899896325791LLU,18446744073709550592LLU,3LLU},{18446744073709551615LLU,6681825070727299071LLU,18162748942115864544LLU,8759070711339017215LLU,18445618173818503152LLU,18446744073709551615LLU,3LLU},{17914932289586823168LLU,18446744073688565343LLU,6908521828386340863LLU,16980448490782568317LLU,18446743798864444797LLU,18446743798848421887LLU,3LLU},{6298683118591737855LLU,18446744073707552752LLU,17311836967612186623LLU,2196628624396712131LLU,3196429835510453187LLU,18446744073692775198LLU,3LLU},{18444498697354760557LLU,13507841309573324214LLU,18445826357272207117LLU,18446744073709551615LLU,18303753960906817535LLU,18442275589684196319LLU,3LLU},{12247537243129360019LLU,14379927525806500809LLU,18445449946439202547LLU,18446744073709551615LLU,18446425139370262527LLU,18446709157231804157LLU,3LLU},{17914932289586855935LLU,18446744073688565343LLU,1150104769707084095LLU,16708785625573629756LLU,15251440138089925695LLU,18446743798848421089LLU,3LLU},{18446738576122314751LLU,6827406457558794239LLU,4481596097495039LLU,9087841285812780800LLU,18445790681298366464LLU,17365876029221965823LLU,3LLU},{18446743653138275313LLU,17428999277400555519LLU,18442275451222093824LLU,16280478462989558783LLU,18446571566229684223LLU,18375495513818791935LLU,3LLU},{7457251737518342143LLU,18311631670467360768LLU,180143985094819839LLU,2196630711784374271LLU,12636995001282191115LLU,4395503615573075952LLU,3LLU},{16126211102625169407LLU,17437726101188214783LLU,18284614487124213759LLU,18446181132312477891LLU,8715445768393044983LLU,14945089810309733151LLU,3LLU},{18446737442275882351LLU,4503582148992114102LLU,18446667092850540525LLU,9087841285812781055LLU,18446108786708967424LLU,17365106098356339679LLU,3LLU},{12249782688568309815LLU,1017800111429766915LLU,14987979285011625959LLU,18446744073709551423LLU,18445794061840285695LLU,13186510812925132025LLU,1LLU},{18376937997632253915LLU,17864671370972822525LLU,18391406752994802939LLU,18446744073701163251LLU,16285000790421012479LLU,17280305722838761407LLU,2LLU},{9293459306055728119LLU,18446744072883273567LLU,14985164550760821631LLU,16717335291089649471LLU,2179742198105378815LLU,13777610542342470905LLU,1LLU},{18419616922829055951LLU,18446744009284780287LLU,4611651100074315199LLU,18302664070005268464LLU,17575297442331491391LLU,16861264203925684103LLU,2LLU},{16680629263753124863LLU,18302909260830343167LLU,18334189060165206015LLU,144114080234863615LLU,12636967904332611579LLU,4583248043526191103LLU,3LLU},{11383965230692302647LLU,144106185254240243LLU,18302628885567109095LLU,18446743944826978063LLU,9150329278724813815LLU,15526139922525150335LLU,1LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][7] = {{12247527175012941825LLU,11764919003037206944LLU,18445112774157997761LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,4],[1,5],[2,4],[2,6],[3,7],[3,8],[4,9],[5,7],[5,10],[6,10],[6,11],[7,12],[8,11],[8,12],[9,12],[9,13],[10,13],[11,13]]\n", fout);
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

