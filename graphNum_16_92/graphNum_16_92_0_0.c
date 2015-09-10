#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_16_92_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 15;
static uint_fast32_t endhere = 0;
char str[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[16][7] = {{13221855182758871039LLU,14843728032370262207LLU,18446744073706397639LLU,18446604435732824063LLU,10015989072054057018LLU,17293831364991254503LLU,17179869183LLU},{18446744073709551615LLU,511LLU,18446744073692774400LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,16777215LLU,18446744056529682432LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU,18446744004990074880LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,68719476735LLU,18446744073441116160LLU,17179869183LLU},{18417400305474469825LLU,18446744073709551580LLU,18014398475139022847LLU,7962363056703172557LLU,18407336528444391407LLU,18446735277867596031LLU,17179869183LLU},{0LLU,18446744073709551104LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{17077649786983151679LLU,18446744071563116531LLU,18446708923697100351LLU,18446744073506389311LLU,9209597355181998079LLU,1152921504606832636LLU,17179868160LLU},{18446740654915520511LLU,18424364616185282559LLU,12069682185725018111LLU,18005532047715598335LLU,18446744073709488127LLU,18446744073709551615LLU,17175675903LLU},{18446744073575333888LLU,9159757583735586815LLU,18446744073701159679LLU,13852509366399270911LLU,18429221705847136255LLU,10376288987160510397LLU,17149426543LLU},{18442240474216398847LLU,18446743919090591743LLU,71635377277620191LLU,18446744073680191480LLU,13276598507348688895LLU,18392426824907653119LLU,16676153343LLU},{4503599627370495LLU,17942323323207654912LLU,18446743661258473471LLU,4611672824287838215LLU,18446744073709551328LLU,9214646306134294527LLU,13421772796LLU},{11511200647550328819LLU,2199023255549LLU,18443366372948836348LLU,18446744072904047583LLU,18444491311823192063LLU,18301502917275810179LLU,12339593215LLU},{18446713285773360847LLU,18446744073709551615LLU,8935138328865406979LLU,18374685414519734271LLU,18446744073701228543LLU,18446700161963917311LLU,8489271239LLU},{18446743510934683647LLU,18410609723564916735LLU,18446744073709551615LLU,14411395645103423487LLU,18446744073709550079LLU,10385300739642621951LLU,17150509055LLU},{18442275658454268407LLU,576460750223044607LLU,18446713286578667516LLU,18446744073709551608LLU,18446744004998463487LLU,18446532907347476479LLU,12482247743LLU}};

static uint_fast64_t D[16][7] = {{18444492273895800833LLU,18428729675200069616LLU,18410715276707264511LLU,17906312118425092095LLU,18429855557390172143LLU,17293817427473187071LLU,17178720589LLU},{18002787485931629437LLU,18446744073709551446LLU,14824987131536998399LLU,5439143257142414953LLU,17679856616041611213LLU,18446744073658490623LLU,17179869183LLU},{3997337947635449854LLU,7627403377554488511LLU,18446744073700088566LLU,18425913413604474879LLU,16932899619905314738LLU,18446744073633005365LLU,17179869183LLU},{14897907567177211803LLU,18446741445188106217LLU,18368916195370035103LLU,18446744072295739807LLU,4586894092805341183LLU,18446744073709254139LLU,17179869183LLU},{18442199220384363751LLU,17743989015553462271LLU,3746954069126676475LLU,13042261758784290806LLU,18446744073701094655LLU,18446744073709551615LLU,17179869183LLU},{16716794743673061375LLU,18446741874686296319LLU,13835058055282163711LLU,18446744073508224511LLU,864691122012618811LLU,13145286032465330172LLU,17177497338LLU},{18446744073709551615LLU,11522098382832598015LLU,18399374825104407917LLU,18432913793011286015LLU,16140581892384844671LLU,18446744073569020878LLU,17179869183LLU},{13835057918078091263LLU,18442244872128692127LLU,16285016252568559615LLU,18437736889478803455LLU,18338657682652659711LLU,17992994041473990631LLU,17179195391LLU},{18167300994485059583LLU,14843864371813154815LLU,18446744073709551111LLU,8070450532245864205LLU,18446462667334483966LLU,6908134719762726911LLU,17179869111LLU},{18446744073709551615LLU,16138622669170902015LLU,36028797016473549LLU,18442224531163561984LLU,11529199614179376767LLU,18437744570899644399LLU,15770189823LLU},{18446744073709551615LLU,17874785271700520959LLU,18435484576210943615LLU,9007194288029695LLU,18446637695959564256LLU,1152917098477906844LLU,14469267452LLU},{18446744073709551615LLU,4610771194285457407LLU,18446240490404692479LLU,18445864258217443327LLU,17870564795441728511LLU,18392700448684376063LLU,17007895407LLU},{18302593838632369791LLU,18446744073709551223LLU,2287543287436804095LLU,18446744065101782911LLU,18005241776637476895LLU,17829698147966640127LLU,8486907843LLU},{9510757945111989247LLU,18446744073709551615LLU,17289864052364804095LLU,15851465622559914235LLU,576460744787230713LLU,13617055685819760512LLU,12339584766LLU},{9219974476131729407LLU,18155135755674976240LLU,18446744073709043708LLU,18439987849634775039LLU,18446744013573668839LLU,18446742385787142271LLU,15770123741LLU},{18446744073592061919LLU,18446742149563399695LLU,18415218850531901439LLU,18446744057603409919LLU,18446744073709551615LLU,17575290948475420671LLU,6422003711LLU}};

uint_fast8_t X[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[16][7] = {{18444492273895800833LLU,18428729675200069616LLU,18410715276707264511LLU,17906312118425092095LLU,18429855557390172143LLU,17293817427473187071LLU,17178720589LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU}};

#if UINTPTR_MAX == 0xffffffffffffffff // 64-bit. Hopefully this means the cpu has 'popcnt'.
int counter (uint64_t * buf){
    uint64_t cnt[16];
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


    return cnt[0] + cnt[1] + cnt[2] + cnt[3] + cnt[4] + cnt[5] + cnt[6] + cnt[7] + cnt[8] + cnt[9] + cnt[10] + cnt[11] + cnt[12] + cnt[13] + cnt[14] + cnt[15];
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
    sprintf(str, "[                ,%5d]\n", this);
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
    fputs("[[0,2],[0,3],[0,4],[0,5],[0,6],[1,3],[1,4],[1,5],[1,6],[2,4],[2,5],[2,6],[3,5],[3,6],[4,6],[5,6]]\n", fout);
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
