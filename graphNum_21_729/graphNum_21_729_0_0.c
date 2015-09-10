#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_729_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][6] = {{18446744073575333889LLU,2199023255551LLU,18446744069414584320LLU,18446744073709551615LLU,18446744065119617039LLU,1125899906842623LLU},{18446744073709551615LLU,65535LLU,18446744069414584320LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,4294967295LLU,0LLU,18446744073709551600LLU,1125899906842623LLU},{18446744073575333888LLU,18446744073709551615LLU,6329800471586275327LLU,15417888022099484533LLU,18446744065119617037LLU,1125899906842623LLU},{134217727LLU,18446741874686361600LLU,18446744073709551615LLU,18446744073709551615LLU,13835058063872098303LLU,1125899906842623LLU},{0LLU,18446744073709486080LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18175398897625595903LLU,18392700878181097471LLU,3758096279LLU,18446744073709486080LLU,3456614966438914047LLU,1125899906841600LLU},{18446744069683019775LLU,9223306066157109223LLU,18446744073705345023LLU,65535LLU,18338657553509973760LLU,1125899902649343LLU},{18437736874563843967LLU,18302628885096955903LLU,18446744073508224765LLU,18446744073642704847LLU,18446603344811130867LLU,1125899371930623LLU},{9007199253036531LLU,16140476653544341504LLU,18446739692841304063LLU,18445899648779419647LLU,140737488355327LLU,1125831724236510LLU},{9222914640017612801LLU,1782293984255LLU,18443366373989023728LLU,17365880111601025023LLU,9223372036854251535LLU,1124849652578299LLU},{17870283295502114815LLU,18446744038275284927LLU,288230371856744463LLU,18446678103011885052LLU,18446744065120141311LLU,1109406682775439LLU},{16086857868967018435LLU,18383764047670542335LLU,18374686481281990551LLU,17347935257201999871LLU,4606760199789994239LLU,1072862429446128LLU},{18229441547672223743LLU,18446743970626395677LLU,72057593878544383LLU,4611686014396858368LLU,16841734310988873715LLU,909296053255183LLU},{18446744004184718975LLU,8137991332518952959LLU,14106399932810250367LLU,18446742974197988355LLU,18446743772224986063LLU,772681372730367LLU},{288164402164662271LLU,18446691281020125156LLU,18446479929998573567LLU,1099511627775LLU,18304867383933665072LLU,536484897685503LLU},{16077851219468222415LLU,18402271026856591359LLU,18374690877717938111LLU,17565164446588862415LLU,18441678623572224511LLU,1072916720510961LLU},{18446744004184735479LLU,17581760492341231619LLU,14987975436720396799LLU,18445898549334899775LLU,4647714514777653215LLU,772621666820094LLU},{18302344696216674367LLU,9006855587100287LLU,18443366373829640176LLU,18446744070485114883LLU,8934012736601851903LLU,913968856038523LLU},{18402271018261946327LLU,18439705515261628351LLU,14055731138488172559LLU,18446743042867068927LLU,14987592514482469887LLU,805907390754790LLU},{17870283029214650879LLU,1152868718382415868LLU,4611686014132682736LLU,1152855533909118972LLU,18428729666743861040LLU,409013448408223LLU}};

static uint_fast64_t D[21][6] = {{10967295120562454527LLU,18446744073709526213LLU,18175415407479881727LLU,4543284077415100623LLU,13835058063872098291LLU,1125899906842623LLU},{10967295120562454526LLU,18446744073709526213LLU,6239357582843052031LLU,10783401356668000869LLU,18446744073709551609LLU,1125899906842623LLU},{7479448953147097089LLU,10795827596202435386LLU,18446744072153821929LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446741874686361599LLU,18265858296223105023LLU,9177770742846584287LLU,13835058063872098295LLU,1125899906842623LLU},{18446744073709551615LLU,7650916477507207167LLU,271328667785399574LLU,13903459996294450992LLU,18446744065119617036LLU,1125899906842623LLU},{18446744073709551615LLU,7650916477507141631LLU,12207386492422229270LLU,7663342717041550746LLU,18446744073709551606LLU,1125899906842623LLU},{7489301458124157565LLU,3891040637763288034LLU,18446744072561345277LLU,18446744073709551615LLU,18338657553509973775LLU,1125899902649343LLU},{18165546388622003587LLU,16074049829067802431LLU,18446744072760950659LLU,18446744073709551615LLU,3456614966438914047LLU,1125899906841600LLU},{18446744073707847155LLU,14681215815739506687LLU,1152917108169055703LLU,14770737176098361151LLU,4611686011795355295LLU,1125831724236510LLU},{18446744073684367231LLU,8966064325722636287LLU,17565151252256321084LLU,17578622468908662720LLU,18446744071751649632LLU,1125899371930623LLU},{17470583325243473919LLU,18446744038275260309LLU,17958271876857855LLU,4611616542179983356LLU,14786613711887925235LLU,1109406682775439LLU},{2143165657263374335LLU,18446743656980279535LLU,18442309812034207743LLU,17297481676138475727LLU,8271816388838948863LLU,1124849652578299LLU},{17870282771753022079LLU,3891109948121284096LLU,18446744073476766461LLU,4611686014396923903LLU,17888296628188545011LLU,909296049904639LLU},{5759919205384781761LLU,18437737829757844479LLU,18446744070487017471LLU,17347935257201999871LLU,18442240469661382671LLU,1072862428604415LLU},{8937088105967083LLU,16139634410425679868LLU,18446479929192579059LLU,18446744073709551615LLU,13799153496634425343LLU,536484901813405LLU},{18444773637182397975LLU,17295791966024091455LLU,14106399932671850511LLU,18446744073709550595LLU,8070415072453166079LLU,772681372794722LLU},{17870283321398229247LLU,288203857949883904LLU,1152921504573544959LLU,1152908306239442751LLU,17888297718954999711LLU,909282693275359LLU},{18446673962537314287LLU,18408991242426253311LLU,18446466992517742512LLU,17578622468975706108LLU,18446727573450386800LLU,536492843597245LLU},{14080491039155093503LLU,18446742970699825143LLU,18392644748325947391LLU,18428729743869214719LLU,16097760570308034559LLU,1062092261584895LLU},{4467515440305791487LLU,1152868715144937196LLU,18446532761318588400LLU,18014395285046271LLU,18058296992256786224LLU,421587510099199LLU},{16077920968932065239LLU,18439705137204101631LLU,18374963831479730175LLU,18432387754617732303LLU,5183097512688352255LLU,808776298866674LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][6] = {{10967295120562454527LLU,18446744073709526213LLU,18175415407479881727LLU,4543284077415100623LLU,13835058063872098291LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,6],[3,7],[4,8],[4,9],[5,10],[5,11],[6,8],[6,10],[7,9],[7,12],[8,13],[9,13],[10,12],[11,12],[11,13]]\n", fout);
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
