#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_18_1582_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 17;
static uint_fast32_t endhere = 0;
char str[28] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[18][8] = {{18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU,0LLU,18446744073708503040LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,16777215LLU,18446462598732840960LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{0LLU,18446744073692774400LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446743936287375359LLU,18158751118481946349LLU,13798745309112663807LLU,16140901064496758767LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446567996022317056LLU,18446744073709383389LLU,288230376151711743LLU,17867996300679051216LLU,2305843009213691773LLU,18446743798831644672LLU,18446744073709551615LLU,67108863LLU},{18443926570801307647LLU,18443366511425354743LLU,18446602769142865855LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU,18446744072635809792LLU,67108863LLU},{18158513697549336447LLU,18158371033776644080LLU,18428729537509457919LLU,18446744073692774414LLU,18428305263711748032LLU,18442240746762272751LLU,18446739676735799295LLU,67108863LLU},{11993028426454791373LLU,11993085759599885839LLU,18446729771736036344LLU,18446744073709551615LLU,13218578616026136575LLU,18446744030287426201LLU,18428734073246580735LLU,67108863LLU},{18437736832040042491LLU,18437703889038868479LLU,17293259619149282695LLU,18445618173819486207LLU,9223371968089161727LLU,4503599627325439LLU,18014398509481920LLU,67108860LLU},{17293822569095233023LLU,17293697216187201599LLU,18410715243404591103LLU,17591129079805LLU,18438853978268631039LLU,18379190078359470015LLU,18428452598269804547LLU,67108739LLU},{6457941901583575859LLU,6458161776318793724LLU,18446688857556384871LLU,18446744073709551615LLU,7971139131910651903LLU,18446743984566906214LLU,6160921360001400831LLU,67108861LLU},{18410714245571264495LLU,18409729839125757951LLU,16139775164588999675LLU,18446744073709550607LLU,18446743798627172352LLU,18446739950540748797LLU,18429011146955620351LLU,67104895LLU},{18445618173869817855LLU,18163017295071281151LLU,18438296525873348607LLU,18446744069414584319LLU,4611686001248567039LLU,18302628859863891952LLU,4390446686730715135LLU,67046271LLU},{1125899906842623LLU,18446744073709551615LLU,18437736874454810623LLU,17289248523353583551LLU,18446603353401060859LLU,16996012697893994495LLU,17580918236348538743LLU,66125563LLU},{18446744073709551615LLU,288230240843464704LLU,18176528096067125247LLU,18437736874454802431LLU,16141041801984212991LLU,18446726481521933327LLU,18446691039453380351LLU,51380199LLU},{18446727581007446015LLU,18446744073708755379LLU,18318391484329492479LLU,18176527128759910399LLU,18278703510734184135LLU,11330810371859546111LLU,18446637489697583615LLU,48222159LLU},{18229462983870709663LLU,18230499821729349631LLU,9218868437210890239LLU,288230376135196671LLU,18446742409409724415LLU,18442521949044211699LLU,18446600037686251519LLU,33374143LLU},{288217182012170367LLU,18446744073709551615LLU,18446462598749618175LLU,18302628885633564656LLU,18446605533633839103LLU,18446603061360066559LLU,18446664071353726975LLU,49536987LLU}};

static uint_fast64_t D[18][8] = {{1584863803064321LLU,2251524954043238LLU,18446577443581483830LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18445159209906487294LLU,18446744073708063897LLU,17870846271359549439LLU,14377494164474922783LLU,18446744073709470833LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18444492548756996095LLU,576064432478069961LLU,4069249909234628832LLU,18446744073708583822LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073642442752LLU,18444492273895866367LLU,18446602769142865855LLU,17867996300679051231LLU,16140901064495855485LLU,13143255914729003007LLU,18446744072827069336LLU,67108863LLU},{18443926570868408319LLU,18445618173816863735LLU,18446744073709551615LLU,13798745309112663807LLU,17990473110244933615LLU,5303488289263583231LLU,18446744073518292071LLU,67108863LLU},{18446567996022325247LLU,18446744073709383389LLU,237420924106477LLU,18446744073709551600LLU,2762113972679213055LLU,18446743943426516992LLU,18446744073709551615LLU,67108863LLU},{12668625743269328377LLU,12668608116552580735LLU,17293245319055671168LLU,18445635765988753407LLU,3996900585731260415LLU,18446744030491427519LLU,12286378335373623235LLU,67108862LLU},{18446744039348781055LLU,18446726756401405951LLU,18446743936270597631LLU,18446726481523507215LLU,18428729675166515199LLU,272730390527LLU,6160921360001400828LLU,67108861LLU},{17473909173426060879LLU,17473825809461411712LLU,18428729673068508159LLU,18446744073709551614LLU,18444625586929270720LLU,18446744073455206345LLU,18446188453116837887LLU,67108863LLU},{8881097374252904295LLU,8881098119018512380LLU,16139720188957278335LLU,18446744073709550607LLU,17221551257240469503LLU,18446739864624578028LLU,6196953084040577023LLU,67104893LLU},{18446744073375055871LLU,18445635765988753343LLU,18446744072635809787LLU,17592186044415LLU,18445618173799563264LLU,18446744073575331839LLU,18428734072172838915LLU,67108863LLU},{14834637268622113211LLU,14834854946624487551LLU,18410715003956887527LLU,18446744072652587005LLU,9189567477766422527LLU,18379190075267215159LLU,18392697949013409791LLU,67108739LLU},{18446744073709551615LLU,18445993657023594495LLU,13834846784565559295LLU,18429846658637349876LLU,18446744073709020152LLU,16703820091298676735LLU,18446717620443741757LLU,57081843LLU},{18446744073709551615LLU,1125899906842623LLU,17870283321406128127LLU,9150746544515775999LLU,2305843009213399007LLU,13796704890682080256LLU,4607147027933395934LLU,60779503LLU},{18446744073709551615LLU,18446368865366573055LLU,5764603399853034907LLU,16284893091161309067LLU,18446744073709550655LLU,17941354898318514175LLU,17364191313273014259LLU,66690687LLU},{18163017297185210241LLU,18446744073696968703LLU,1152921504590069760LLU,18446735277616529407LLU,16717359652135239679LLU,18446744073692775423LLU,17571919845555961853LLU,24966908LLU},{4611686018410342399LLU,4611114169300697087LLU,18374409402741424127LLU,18446742991377793015LLU,18194436941460472831LLU,9799832548640029951LLU,14985727759949496319LLU,46661119LLU},{18445898783035670527LLU,18446744073693822975LLU,18296436436146061311LLU,2295834154851359871LLU,16429131431878393855LLU,9219973446413320191LLU,4598175218605702860LLU,20935676LLU}};

uint_fast8_t X[18] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[18][8] = {{1584863803064321LLU,2251524954043238LLU,18446577443581483830LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU}};

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

    } else {
        A[i][0] = A[i-1][0] & D[i][0];
        A[i][1] = A[i-1][1] & D[i][1];
        A[i][2] = A[i-1][2] & D[i][2];
        A[i][3] = A[i-1][3] & D[i][3];
        A[i][4] = A[i-1][4] & D[i][4];
        A[i][5] = A[i-1][5] & D[i][5];
        A[i][6] = A[i-1][6] & D[i][6];
        A[i][7] = A[i-1][7] & D[i][7];

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
    fputs("[[0,4],[0,6],[0,7],[1,4],[1,6],[1,7],[2,5],[2,7],[2,8],[3,5],[3,7],[3,8],[4,5],[4,6],[4,8],[5,6],[5,8],[6,8]]\n", fout);
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
