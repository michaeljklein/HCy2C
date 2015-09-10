#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_592_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][5] = {{18446744073172680705LLU,4194303LLU,18446744073709535232LLU,13835058072462032895LLU,18446744073709551615LLU},{18446744073709551615LLU,127LLU,18446744073709535232LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,16383LLU,18446744056529682432LLU,18446744073709551615LLU},{18446744073172680704LLU,18446744073709551615LLU,18266553737327640575LLU,13835058063333088767LLU,18446744073709551615LLU},{536870911LLU,18446744073705357440LLU,18446744073709551615LLU,4611686018427387903LLU,18446744073642442752LLU},{0LLU,18446744073709551488LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18304880685447380991LLU,8610732919582883839LLU,18374686479671638015LLU,17270089593437290495LLU,18446744065186467839LLU},{18446743799905386495LLU,18444491721858351103LLU,72057594037927799LLU,4251111814437273600LLU,18446742982787858368LLU},{18445618174065618683LLU,15996187604621951231LLU,288230376151703549LLU,4611686018427387840LLU,18446674795887063040LLU},{1125899822889903LLU,18437734666300587904LLU,18446744069414649311LLU,18446744073709551615LLU,18442310842692145151LLU},{18158513697557807105LLU,18445618173805789167LLU,18446744073709551615LLU,18446462615107403007LLU,18414022315609161727LLU},{18446742423905271807LLU,1125899906841087LLU,18446743816011497472LLU,13835339530258874367LLU,18194539195639267327LLU},{18303755060418445311LLU,18446744073709519359LLU,216172786408751103LLU,18446744073709551552LLU,18446674796021022783LLU},{144114914271690751LLU,18446744073705422720LLU,18446744069414649855LLU,4611686001247518783LLU,18442309760427753408LLU},{9218853001114942977LLU,18446743798835832827LLU,14987962242366963711LLU,18446739692791791615LLU,17577536149866405749LLU},{17005592192948896255LLU,13835058330156728239LLU,18446744073709551615LLU,18428734059556359423LLU,14957368279998398463LLU},{18446729229767802369LLU,4611685743553667583LLU,18446727323337080832LLU,13853068072925003775LLU,17365863668452950015LLU},{18310527777165641727LLU,13851950951931289599LLU,4539646016575504383LLU,18429591692316245952LLU,14960905179123953919LLU},{116988021089239039LLU,18446744073709092863LLU,4610630487248011263LLU,4611686018426339388LLU,12672636649948265724LLU},{18446743815986348007LLU,18446744072699248512LLU,18446744069431361475LLU,18230571068258516991LLU,8859142454855598019LLU},{2305833100220825119LLU,18446743799905119231LLU,18446730673395843135LLU,14123284308264239103LLU,13114189574745096188LLU}};

static uint_fast64_t D[21][5] = {{3748716176499277823LLU,18446744073709551569LLU,270285504572882943LLU,4611686014940934912LLU,18446744073642442752LLU},{3748716176499277822LLU,18446744073709551569LLU,12207734214282084351LLU,18446744063418456490LLU,18446744073709551615LLU},{14698027897210273793LLU,11068046444224053422LLU,18446744073709541785LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073705357439LLU,6329105027618439167LLU,4611686016103085909LLU,18446744073642442752LLU},{18446744073709551615LLU,7378697629485498367LLU,18176458569136678502LLU,13835058058768616703LLU,18446744073709551615LLU},{18446744073709551615LLU,7378697629485498239LLU,6239009859427477094LLU,18446744066820777557LLU,18446744073709551615LLU},{14699748909080325331LLU,15992809076841053870LLU,18446744073709543217LLU,4251111831617142783LLU,18446742982787858368LLU},{18303159399773164333LLU,3683717935114682879LLU,18446744073709547999LLU,17270089593437290495LLU,18446744065186467839LLU},{18446744073625598895LLU,8597218808475680767LLU,18446744069414597839LLU,16548941206123384063LLU,18442310842759249919LLU},{18446744073435590395LLU,14768657018226999295LLU,17944871578881908LLU,15732860926354784192LLU,18446674795887067135LLU},{13165919581690134527LLU,18446744073709550045LLU,17567697447583743999LLU,9223372033620767692LLU,18194539195599775130LLU},{8741308643099541503LLU,18446744073708437475LLU,1149331873000652799LLU,13835058054224411699LLU,18414022315581545061LLU},{14699749183611369863LLU,18429851434821418926LLU,18446744073709550595LLU,17365021499585400063LLU,18442309760494600191LLU},{18446148687752169081LLU,16892638888165887LLU,18392631351250502652LLU,14916780632892768255LLU,18446674796021284863LLU},{16626937840942481407LLU,13836183955186778015LLU,18432388846675296255LLU,9205639097215861708LLU,14949557641418208735LLU},{4604913237253685247LLU,18446744073709543929LLU,14123270843275411455LLU,18446744073645654015LLU,17365863668437208880LLU},{16149380288789610495LLU,18446744073706209159LLU,4593741984634568703LLU,4611686001314611200LLU,14957368279947030735LLU},{2305842944663355271LLU,18446744056596004856LLU,18446744073442163715LLU,17365879132281389055LLU,17365035532036341744LLU},{18446176175920750561LLU,287174843919480319LLU,18392697528106614720LLU,18162805933254639615LLU,8863043379768852479LLU},{18419589434635314815LLU,18176461867671604223LLU,4610564310408610815LLU,14984545785075466236LLU,12673100760628542719LLU},{18337672314074144767LLU,14122232900268048263LLU,18375812375551934463LLU,18433022151482146755LLU,6896100916059763663LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][5] = {{3748716176499277823LLU,18446744073709551569LLU,270285504572882943LLU,4611686014940934912LLU,18446744073642442752LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,6],[3,7],[4,6],[4,7],[5,8],[5,9],[6,10],[7,11],[8,9],[8,10],[9,12],[10,13],[11,12],[11,13],[12,13]]\n", fout);
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
