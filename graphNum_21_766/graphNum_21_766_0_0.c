#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_766_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][6] = {{18446744073642574335LLU,18446743523960024063LLU,18446741874686300159LLU,17996384110972502015LLU,18446744073642443775LLU,1083388134399LLU},{18446744073709551615LLU,65535LLU,18446741874686296064LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,2199023255551LLU,0LLU,18446744073709551612LLU,1099511627775LLU},{18446742974197923840LLU,18446744073709551615LLU,18446466996645134335LLU,14699634834526044159LLU,18446744056529682435LLU,1099511627775LLU},{1099511627775LLU,17365880163132309504LLU,18446743962036994047LLU,18442240474082181119LLU,17179869183LLU,1099511627772LLU},{18446744073709551615LLU,18410715276690653175LLU,15527848565220048895LLU,9150187696528807805LLU,6510615562500964351LLU,1099511627266LLU},{18446744073709420545LLU,36028797018962943LLU,18446741874686296064LLU,18428729675200069631LLU,18446744073709289475LLU,1099511562751LLU},{18446744073575333887LLU,16135200009715974143LLU,1921964285303LLU,18446744073709486080LLU,18446744066635487835LLU,1099509595127LLU},{18302631067477082111LLU,18446744073709551615LLU,18446744073172680703LLU,65535LLU,18445618190982578172LLU,1099446607807LLU},{18446742974198054911LLU,18410715276698976247LLU,18446471394691645439LLU,16140830145994031103LLU,18446744056529944575LLU,1099511627267LLU},{144115187941638143LLU,17437937757170368512LLU,281406255120383LLU,18442240474082115584LLU,1125899906842623LLU,1099509595124LLU},{17796813954438135297LLU,36028797018406861LLU,4608308318706855936LLU,18446727477930704883LLU,17723342354087148544LLU,1098500668925LLU},{0LLU,18446744073709486080LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446182772184120059LLU,4584657411175874559LLU,18446724832255570943LLU,18446743936270663679LLU,18446739684084545015LLU,1046829070319LLU},{144678052129931263LLU,18446744073709551612LLU,211092810760191LLU,137438953471LLU,18158518095604350972LLU,888726855487LLU},{18446742974265032193LLU,1116893257343172567LLU,18446480190784663552LLU,18446730329812631551LLU,18446744056596790275LLU,1098500668935LLU},{18446183322108297215LLU,17582052945246486531LLU,18446726481523097599LLU,18442240336645259264LLU,288225995285069823LLU,1046829200356LLU},{18446716860792823935LLU,18124736698210314815LLU,18446744073642443007LLU,18446744073206234895LLU,14987979340841730303LLU,804231832575LLU},{14981224153942466535LLU,18446611584705888255LLU,18379187880342847472LLU,17994149903344861183LLU,18433180497400840143LLU,468126212095LLU},{4476551641324054527LLU,18446744071696285308LLU,72057580549570559LLU,2251799310368527LLU,14716707844922527740LLU,680701956095LLU},{18338656591727814175LLU,18410856012165677052LLU,1152710398311395343LLU,576447008407027711LLU,18229726850556349500LLU,686351711807LLU}};

static uint_fast64_t D[21][6] = {{17471848669719298047LLU,18446744073708978112LLU,1148435497165520895LLU,4607164835170815984LLU,17361641494275948540LLU,1098500668932LLU},{144117162015850494LLU,18446744073709499496LLU,7608273018535542783LLU,10037562378054363542LLU,18446744073709551613LLU,1099511627775LLU},{18302626911693701121LLU,6968417951053630359LLU,18446742723584779929LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,17329851366113345535LLU,10838475319535583231LLU,9143290974905013865LLU,17179869182LLU,1099511627772LLU},{18446744073709551615LLU,11514354919675002879LLU,18446463970735774054LLU,13961021955648847871LLU,18446744056529682435LLU,1099511627775LLU},{12020903451870232576LLU,18446744073709517165LLU,9067993451663982591LLU,16978242870844423639LLU,18446744073709289473LLU,1099511562751LLU},{6569957783855038463LLU,18446744073709532914LLU,14068128132091609087LLU,2191492805229265724LLU,6510615562500964351LLU,1099511627266LLU},{18302629407164388051LLU,9132996299589550079LLU,18446742930433177565LLU,18446744073709551615LLU,18445618190982578175LLU,1099446607807LLU},{18302628571872177453LLU,13970621661180054423LLU,18446743589265312819LLU,18446744073709551615LLU,18446744066635487835LLU,1099509595127LLU},{12020903451870363647LLU,17329851366121634157LLU,4378624604026028031LLU,18412541460688616643LLU,11936128528388456444LLU,1099511562749LLU},{18446743495728616147LLU,4584208803586637823LLU,18446742423422792652LLU,13961021955648847871LLU,18446744063603746215LLU,1099446607807LLU},{6894923068507029503LLU,18446743523960022783LLU,17528000953632948223LLU,15598709883761587007LLU,6872316422245318655LLU,1083388198907LLU},{18446744073709551615LLU,11478326122655973375LLU,10838472405298780518LLU,8409181695655188073LLU,18446744073709551614LLU,1099511627775LLU},{144115080691167151LLU,18300834455276486652LLU,211021354499891LLU,18446744073709551615LLU,18159639594769801055LLU,888789712767LLU},{18446743248017979513LLU,254444617079442327LLU,18446724419804463359LLU,18446744073709551615LLU,18446744060572004595LLU,1046829200359LLU},{1119012566006235135LLU,18446744073707446399LLU,17298326035045138431LLU,17870424050338099215LLU,1085102596613472255LLU,1083388134399LLU},{18446743938402322311LLU,18444501035763367935LLU,18446673687789698816LLU,13961021955650879487LLU,18446744069667229455LLU,888726855487LLU},{14114421876251951079LLU,18446612132314169343LLU,18374862401532067824LLU,18444492282485215231LLU,18429786305069055951LLU,480621100828LLU},{18338623734560063103LLU,18124736700350987776LLU,1152763174932443391LLU,4607182418264194816LLU,13906270953807019260LLU,806849478375LLU},{18446321852671229921LLU,576320049170030551LLU,18446689235432898544LLU,18446743944859947007LLU,18446740774117507011LLU,515193569220LLU},{14980696394816192511LLU,17870282806003696127LLU,18379187897455198207LLU,18444632874482073855LLU,4598118319768010751LLU,505730790396LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][6] = {{17471848669719298047LLU,18446744073708978112LLU,1148435497165520895LLU,4607164835170815984LLU,17361641494275948540LLU,1098500668932LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,4],[1,5],[2,4],[2,6],[3,5],[3,7],[4,8],[5,9],[6,8],[6,10],[7,9],[7,11],[8,12],[9,13],[10,11],[10,13],[11,12],[12,13]]\n", fout);
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
