#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_26_2015_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 25;
static uint_fast32_t endhere = 0;
char str[36] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[26][5] = {{0LLU,18446744073709518848LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,32767LLU,18446744072635809792LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18428729676273811455LLU,18446744073709551615LLU,288230376151711743LLU},{0LLU,18446744073709551608LLU,18014396361998335LLU,18446744073709551614LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709453319LLU,18446744073709551615LLU,18446744073709547521LLU,288230376151711743LLU},{18374686479671623680LLU,18446744073709551599LLU,18014387772063743LLU,18446744073705361407LLU,288230376151711743LLU},{72057594037927935LLU,18446744073709158392LLU,18446744073709551615LLU,18446744069418778622LLU,288230376151711743LLU},{18302558516889518080LLU,18446744073709551567LLU,9241386390267101183LLU,18446741878979170303LLU,288230376151711743LLU},{18374756848415801343LLU,18446744073705881599LLU,9223372036854775807LLU,18445620372823867391LLU,288230376151711743LLU},{18014257634554675200LLU,18446744073709551503LLU,13853072271255535615LLU,18159638502246977535LLU,288230376151711743LLU},{18446673842404327423LLU,18446744073646637055LLU,13835058055282163711LLU,288229276639035391LLU,288230376151711740LLU},{17437515269298716672LLU,18446744073709551375LLU,16158914730713415679LLU,18303754240079171583LLU,288230376151711235LLU},{18446743936807469055LLU,18446744071629176831LLU,16140901064495857663LLU,18302628335877357567LLU,288230376151646719LLU},{16284030264441569280LLU,18446744073709551119LLU,17311834036297007103LLU,18375812108995268607LLU,288230376147582723LLU},{18446744073176875007LLU,18446743938418081791LLU,17293822569102704639LLU,18374686204793454591LLU,288230375887470335LLU},{13977060253657661440LLU,18446744073709550607LLU,17888285992507408383LLU,18411841043453317119LLU,288230367828180867LLU},{18446744073705422847LLU,18446726618962460671LLU,17870283321406128127LLU,18410715139251503103LLU,288230109861642111LLU},{9363120232081520640LLU,18446744073709549583LLU,18176481184287031295LLU,18429855510682341375LLU,288226248955592643LLU},{18446744073709488127LLU,18442258066268225535LLU,18158513697557839871LLU,18428729606480527359LLU,288164401158029247LLU},{135240188929109888LLU,18446744073709547535LLU,18320455634874531839LLU,18438862744296853503LLU,287735868917612515LLU},{18446744073709549695LLU,16145404664123228159LLU,18302628885633695743LLU,18437736840095039487LLU,284287525306499039LLU},{126224176333836016LLU,18446744073709543438LLU,18391950278959038463LLU,18443366361104109567LLU,274507645597843443LLU},{18446744073709551503LLU,2305843009213693951LLU,18374686479671623552LLU,18442240456902295551LLU,233904605060923375LLU},{108192151143288028LLU,18446744073709535244LLU,18425727276164317183LLU,18445618169507737599LLU,211598538595827707LLU},{18446744073709551603LLU,18446744073709551615LLU,18410715276690325631LLU,18444492265305923583LLU,134966701039943671LLU},{18446744073709551613LLU,18446744073709551615LLU,18428729674126589951LLU,18445618169507737599LLU,211598538595827707LLU}};

static uint_fast64_t D[26][5] = {{18446744073709551615LLU,2310364340685602815LLU,18436235673863454848LLU,18446744073709551615LLU,288230376151711743LLU},{72128100762192022LLU,18446744073709518856LLU,18439238075046428671LLU,18446744073709551615LLU,288230376151711743LLU},{18374615972947359593LLU,16136379733023981559LLU,18446744073709289343LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,6931093022056546303LLU,18436235674937721216LLU,18446744073709547521LLU,288230376151711743LLU},{18446744073709551615LLU,13826015392338542591LLU,18014395287731967LLU,18446744073709551614LLU,288230376151711743LLU},{18446744073709551615LLU,16172550384797646847LLU,18436235679233737600LLU,18446744069418774531LLU,288230376151711743LLU},{18446744073709551615LLU,9205286710968057839LLU,18446744060823600639LLU,18446744073705361405LLU,288230376151711743LLU},{18446744073709551615LLU,16208721036563218431LLU,18436235696415704961LLU,18445620368539381767LLU,288230376151711743LLU},{18302628885633695743LLU,18410573421940309983LLU,18446744022167845886LLU,18446741878977069051LLU,288230376151711743LLU},{18446744073709551615LLU,16281062339971678207LLU,18436235765139378051LLU,287108870013186063LLU,288230376151711740LLU},{18158372960069484543LLU,18374402770238177215LLU,18446743867546925053LLU,18159637398433038327LLU,288230376151711743LLU},{18446744073709551615LLU,16425744942686568447LLU,18436236040025677703LLU,575343644228186143LLU,288230376151646716LLU},{17870001571551510527LLU,18302061468914286463LLU,18446743249067438075LLU,18158509299494551535LLU,288230376151711235LLU},{18446744073709551615LLU,16715109879546675199LLU,18436237139554090895LLU,1151813192658186303LLU,288230375887406076LLU},{17293259068319727615LLU,18157379001557974783LLU,18446740775157882871LLU,17870274525279551455LLU,288230376147582463LLU},{18446744073709551615LLU,17293804976916692991LLU,18436241537634172831LLU,2304752289518186623LLU,288230109603629052LLU},{16139774062921515007LLU,17868031521592442367LLU,18446730879536447471LLU,17293804976849551295LLU,288230367826017279LLU},{18446744073709551615LLU,18442240474082213887LLU,18436259129887358911LLU,4610630483238187263LLU,288164147504287740LLU},{13832804052133347327LLU,17293822569102703615LLU,18446691297084276703LLU,16140865879989550975LLU,288226244384782335LLU},{18446744073709551615LLU,16140901064495890431LLU,18436329498765819903LLU,9222386870678188543LLU,284227913073500156LLU},{9218864030557138943LLU,18446744073709549567LLU,18446532967342735295LLU,13834987686269550335LLU,287733379699306495LLU},{18446744073709551615LLU,32767LLU,18436610974011096960LLU,18445899645558191103LLU,230756497984798716LLU},{18437728061114277631LLU,18446744073709547518LLU,18445899648510853119LLU,9223231298829549055LLU,274147796829855743LLU},{18446744073709551615LLU,32767LLU,18437736874454548480LLU,18446181121608644607LLU,105799269297913853LLU},{18428712048519003615LLU,18446744073709543421LLU,18443366373452152831LLU,18446462597659098111LLU,197014822724812798LLU},{18410680023328455607LLU,18446744073709535227LLU,18433233274827440127LLU,18446181121608644607LLU,105799269297913853LLU}};

uint_fast8_t X[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[26][5] = {{18446744073709551615LLU,2310364340685602815LLU,18436235673863454848LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU}};

#if UINTPTR_MAX == 0xffffffffffffffff // 64-bit. Hopefully this means the cpu has 'popcnt'.
int counter (uint64_t * buf){
    uint64_t cnt[26];
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
    cnt[21] = 0;
    cnt[22] = 0;
    cnt[23] = 0;
    cnt[24] = 0;
    cnt[25] = 0;

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
            "popcnt %4, %4 \n\t"
            "add %4, %0    \n\t"
            "popcnt %5, %5 \n\t"
            "add %5, %1    \n\t"
            "popcnt %6, %6 \n\t"
            "add %6, %2    \n\t"
            "popcnt %7, %7 \n\t"
            "add %7, %3    \n\t"
            : "+r" (cnt[20]), "+r" (cnt[21]), "+r" (cnt[22]), "+r" (cnt[23])
            : "r" (buf[20]), "r" (buf[21]), "r" (buf[22]), "r" (buf[23]));
    __asm__(
            "popcnt %2, %2  \n\t"
            "add %2, %0     \n\t"
            "popcnt %3, %3  \n\t"
            "add %3, %1     \n\t"
            : "+r" (cnt[24]), "+r" (cnt[25])
            : "r" (buf[24]), "r" (buf[25]));


    return cnt[0] + cnt[1] + cnt[2] + cnt[3] + cnt[4] + cnt[5] + cnt[6] + cnt[7] + cnt[8] + cnt[9] + cnt[10] + cnt[11] + cnt[12] + cnt[13] + cnt[14] + cnt[15] + cnt[16] + cnt[17] + cnt[18] + cnt[19] + cnt[20] + cnt[21] + cnt[22] + cnt[23] + cnt[24] + cnt[25];
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
    sprintf(str, "[                          ,%5d]\n", this);
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
    str[22] = X[21] ^ 48;
    str[23] = X[22] ^ 48;
    str[24] = X[23] ^ 48;
    str[25] = X[24] ^ 48;
    str[26] = X[25] ^ 48;

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
    fputs("[[0,1],[0,12],[0,13],[1,2],[1,13],[2,3],[2,13],[3,4],[3,13],[4,5],[4,13],[5,6],[5,13],[6,7],[6,13],[7,8],[7,13],[8,9],[8,13],[9,10],[9,13],[10,11],[10,13],[11,12],[11,13],[12,13]]\n", fout);
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
