#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_15_948_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 14;
static uint_fast32_t endhere = 0;
char str[25] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[15][5] = {{2251799813685247LLU,18445618173802708992LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18444492273895866368LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,1125899906842623LLU,18446181123756130304LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,562949953421311LLU,18446462598732840960LLU,72057594037927935LLU},{18163017297185206272LLU,18304863024541859839LLU,18375803549125705727LLU,17294099628853035007LLU,72057594037927935LLU},{18446744073676001279LLU,13979173243358019583LLU,16212870693272936399LLU,1152877521976422375LLU,72057594037923840LLU},{9511602138162135039LLU,18446568143187853215LLU,2305843009213693951LLU,18446743901608836508LLU,72057593769496575LLU},{9221120511918997503LLU,4611685330024527472LLU,18446743729508121400LLU,18446744073709551615LLU,72040002120318975LLU},{17856770873055223800LLU,8928386261261976062LLU,13687565167485763839LLU,11527244721231487103LLU,71934447124979711LLU},{18445576249821626311LLU,18419722475945328639LLU,9209430228474544124LLU,18430765970264694782LLU,71063560229126143LLU},{18392322646163750463LLU,18445882054713311225LLU,17528009749725970431LLU,9097270401708589055LLU,64175031969642478LLU},{14771806731598688767LLU,16609272043423137791LLU,18446742382549925887LLU,17437937757178560511LLU,9007199235473113LLU},{18446303665548426110LLU,9149062643003162623LLU,13797901167910451323LLU,18122202330339212349LLU,51771861636997119LLU},{18296430938581358573LLU,18446739692817740022LLU,17138448381958422527LLU,15559093387146355695LLU,35696739138666043LLU},{13213561099850268379LLU,15829031188346146751LLU,18446183322778978271LLU,13752867362082652159LLU,66920675477991934LLU}};

static uint_fast64_t D[15][5] = {{18445421749580327798LLU,8995940255672565759LLU,4497732620265692776LLU,18446625319924256564LLU,72057594037927935LLU},{18444492273895866367LLU,18444973545866320879LLU,18445858809787936247LLU,18446582916725454587LLU,72057594037927935LLU},{17990951423966402477LLU,18446269058568371408LLU,13949899845780111359LLU,18446742509502233039LLU,72057594037927935LLU},{459366773686058203LLU,9453049361021396799LLU,18446740945294914463LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446532142608416271LLU,18446638108158983943LLU,17293769586327420803LLU,72052611531402103LLU},{2251799813685247LLU,18446744073709551600LLU,18446462477659961855LLU,18119810827723685119LLU,72048434343534591LLU},{18446744073709551615LLU,562707807663103LLU,18446744073709551608LLU,6317971381105846271LLU,72054144105445291LLU},{18446744073709551615LLU,18446680289143398399LLU,531057670344703LLU,13608752174006796284LLU,72057593985285340LLU},{16140795498493116415LLU,17293822551956389883LLU,17870283312832970749LLU,18446744069422972926LLU,61783516866150343LLU},{18446462564372586495LLU,17582052945220861967LLU,18014396447897681919LLU,1152920473814695935LLU,51772154236108792LLU},{16716235912660385791LLU,18446739950540947455LLU,4611686018410610695LLU,18446480190918885375LLU,35698943530110591LLU},{18446709301637545983LLU,9222316505692110844LLU,18446216308128219134LLU,18446744073701163011LLU,66920641420325887LLU},{18446739675093139407LLU,14968839261506240511LLU,16708354617544146911LLU,18433233274827243503LLU,71072427324403719LLU},{11493168386280455807LLU,18446744073708765119LLU,18410152326753943551LLU,18338657682646368188LLU,64176277242249214LLU},{18300412268044350463LLU,18374686479646457587LLU,18446744073696968569LLU,17581771470286094335LLU,8989641428172795LLU}};

uint_fast8_t X[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[15][5] = {{18445421749580327798LLU,8995940255672565759LLU,4497732620265692776LLU,18446625319924256564LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU}};

#if UINTPTR_MAX == 0xffffffffffffffff // 64-bit. Hopefully this means the cpu has 'popcnt'.
int counter (uint64_t * buf){
    uint64_t cnt[15];
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
            "popcnt %2, %2  \n\t"
            "add %2, %0     \n\t"
            "popcnt %3, %3  \n\t"
            "add %3, %1     \n\t"
            : "+r" (cnt[12]), "+r" (cnt[13])
            : "r" (buf[12]), "r" (buf[13]));
    __asm__(
           "popcnt %1, %1  \n\t"
           "add %1, %0     \n\t"
            : "+r" (cnt[14])
            : "r" (buf[14]));


    return cnt[0] + cnt[1] + cnt[2] + cnt[3] + cnt[4] + cnt[5] + cnt[6] + cnt[7] + cnt[8] + cnt[9] + cnt[10] + cnt[11] + cnt[12] + cnt[13] + cnt[14];
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
    sprintf(str, "[               ,%5d]\n", this);
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
    fputs("[[0,1],[0,4],[0,5],[0,6],[1,2],[1,4],[1,5],[1,6],[2,3],[2,4],[2,5],[2,6],[3,4],[3,5],[3,6]]\n", fout);
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
