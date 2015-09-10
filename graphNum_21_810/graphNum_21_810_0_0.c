#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_810_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][7] = {{18439984276222017535LLU,2198989701058LLU,1116892294197280272LLU,18446744073709355007LLU,18302633283680204783LLU,18446744039350861823LLU,16383LLU},{18446744073709551615LLU,268435455LLU,18158513697557839872LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU,0LLU,18446744072635809792LLU,18446744073709551615LLU,16383LLU},{18446739675663040512LLU,18446744073709551615LLU,540431541893856799LLU,17825247187156074495LLU,18302628886539657189LLU,18446744073709551615LLU,16383LLU},{4398046511103LLU,18446741874954731520LLU,18437684097878851583LLU,18446711079737229311LLU,144115188075462655LLU,18446744073708503040LLU,16383LLU},{18439988674268495871LLU,234880962LLU,18446744073709551600LLU,6771161487848005117LLU,7205759403247530943LLU,18446744039350431534LLU,16383LLU},{18158513697557807105LLU,18446744073707323391LLU,18158513697557839887LLU,18445688508052930559LLU,18446739676733636607LLU,18445618208162447359LLU,16383LLU},{18446743867550138367LLU,4539597638055444479LLU,285837838782169087LLU,18446742974197923840LLU,18418564404585955327LLU,18159639041250545663LLU,16383LLU},{18445626965600763903LLU,18158513697423621759LLU,18302628820940747775LLU,1099511627775LLU,141863284109213696LLU,287636536256101631LLU,16380LLU},{0LLU,18446744073441116160LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{3572839198705LLU,18427533389906051070LLU,18220983550183670269LLU,14987972962819244031LLU,144115188075724319LLU,12393342700567396224LLU,16354LLU},{18446743979085855231LLU,17293820386990882817LLU,18446700643000254463LLU,18230544894693195776LLU,18446744072903983103LLU,18429750018631008383LLU,16159LLU},{18023405707092557569LLU,9086566398859149311LLU,18446744071562067983LLU,18433022134084435967LLU,18426891258421051391LLU,18104461740296110073LLU,15610LLU},{18446601137189519615LLU,18446321740983164991LLU,18158513699705323507LLU,18445899648779419587LLU,16068768738024820732LLU,6913034224106729727LLU,13279LLU},{1125212709191667LLU,9223345632461144062LLU,18446744073709228031LLU,14987971863307632639LLU,18428703286920871455LLU,18176527121080242048LLU,16355LLU},{13816982084121526239LLU,18446743798696439679LLU,18289116974078721023LLU,1035083971599LLU,17437937718523854844LLU,14122394219242272477LLU,11967LLU},{17292767033377681407LLU,18149541682675187447LLU,14987135083419269055LLU,18446744069682954239LLU,1150141319662796803LLU,4611668356733337071LLU,7156LLU},{18442183299745972191LLU,9006924376047567LLU,4611685734953254512LLU,1125899906710783LLU,17438500668477274092LLU,14123288397342539775LLU,11967LLU},{18023405690482981135LLU,17185734112971857919LLU,18446700640852836351LLU,18446585744019406911LLU,18445618141590454271LLU,18379076279842377721LLU,15423LLU},{143974450586945523LLU,18446726365559349758LLU,18158522493650538495LLU,18446175626214768579LLU,16140879349141159551LLU,18226207467375678343LLU,13287LLU},{18337813257470737215LLU,18438298172725919479LLU,16140894430927255487LLU,18446585744022553599LLU,4611263779118841855LLU,18401613450511973883LLU,7548LLU}};

static uint_fast64_t D[21][7] = {{13348238286968061951LLU,18446744073571953791LLU,18289053176615363583LLU,18445619208622437123LLU,11385099857988435583LLU,18445618208161829073LLU,16383LLU},{3258361257758097406LLU,18446744073548737661LLU,576460752303423487LLU,11987387698623522390LLU,18446744073268190405LLU,18446744073709551615LLU,16383LLU},{15188382815951454209LLU,14786227972714386306LLU,18327833124707146777LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446741874954731519LLU,18289053176615363583LLU,6771127390047263145LLU,144115187530119999LLU,18446744073708503040LLU,16383LLU},{18446744073709551615LLU,3660516101424414719LLU,231512659856326150LLU,17513443178222518271LLU,18302628886452619232LLU,18446744073709551615LLU,16383LLU},{13348238286968029184LLU,18446744073571953791LLU,17870283321406128127LLU,17824156419869898583LLU,18446739676565298933LLU,18445618208162447359LLU,16383LLU},{8061881268906819583LLU,18446744073650552768LLU,1152921504606846975LLU,933337200945007868LLU,7205759402974507407LLU,18446744039350431534LLU,16383LLU},{18445620090858614365LLU,17992793912709086759LLU,18220983483206988089LLU,18446744073709551615LLU,141863285182955519LLU,287636536256101631LLU,16380LLU},{15188389484534190499LLU,1044801321774814170LLU,18407085925071363807LLU,18446744073709551615LLU,18418564404585955327LLU,18159639041250545663LLU,16383LLU},{18446744073709551615LLU,3660516101155979263LLU,17989194270408532966LLU,6459356375086029225LLU,18446744073077171002LLU,18446744073709551615LLU,16383LLU},{18446743979085855231LLU,12028828731683373055LLU,285829109794078711LLU,18176105883602239488LLU,18359691994065782780LLU,18429750018632056831LLU,16159LLU},{18446743248502239217LLU,8906299271683244031LLU,18175683645367320588LLU,14109144072395489279LLU,18389680965291081219LLU,12393342700567396351LLU,16354LLU},{8070200861356654591LLU,18446321740985393152LLU,8070450532247928819LLU,4395499205695635392LLU,14339390843997848060LLU,6914151306805375023LLU,13279LLU},{18303173554274435071LLU,9086566398800150527LLU,11529215046068469759LLU,14971071270060297471LLU,8915288878688894863LLU,18104470488785448952LLU,15610LLU},{18446741842264324191LLU,16277837248892108327LLU,18446735277744455475LLU,18176105883602255871LLU,18367578973507930108LLU,6340931934150458623LLU,16157LLU},{16643052422679258043LLU,18437738482873924594LLU,14950890695047503775LLU,18446744069682954239LLU,18446184688578985983LLU,18328524583223558127LLU,7159LLU},{11209459213753376199LLU,1044834622848894943LLU,18429818466581102335LLU,18446744009281895439LLU,18418595470084407295LLU,18277540497746495453LLU,11967LLU},{16176507649049748411LLU,18446743483135785215LLU,18445620338340120575LLU,18446744069418775539LLU,11529214212840636031LLU,18328292930134792675LLU,7159LLU},{8070200114163462143LLU,18157968339790462974LLU,7799390103905763312LLU,287661993332899839LLU,14301054619554349056LLU,1152358528288030639LLU,13287LLU},{18446163497226993503LLU,16141462639807299559LLU,11529215044048912191LLU,18159481267790269695LLU,8926275176392292335LLU,17582048545124614143LLU,15420LLU},{2301299861526913015LLU,2305825339718232030LLU,8936267277142015728LLU,287661932934987727LLU,17735154407504347132LLU,14840767839970785183LLU,10223LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][7] = {{13348238286968061951LLU,18446744073571953791LLU,18289053176615363583LLU,18445619208622437123LLU,11385099857988435583LLU,18445618208161829073LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,4],[1,5],[2,4],[2,6],[3,7],[3,8],[4,9],[5,7],[5,10],[6,10],[6,11],[7,11],[8,9],[8,12],[9,13],[10,12],[11,13],[12,13]]\n", fout);
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

