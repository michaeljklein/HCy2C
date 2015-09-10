#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_880_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][6] = {{18446744073709551615LLU,4095LLU,18446743523953737728LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{0LLU,18446744073709547520LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,549755813887LLU,17293822569102704640LLU,18446744073709551615LLU,16777215LLU},{18446741874686296064LLU,18446744073709551615LLU,18445619273314336767LLU,71916856545411071LLU,18446744073692774400LLU,16777215LLU},{2199023255551LLU,10347020023624503296LLU,18446744044382976255LLU,18446744073709551615LLU,18442240474098958335LLU,16777215LLU},{18446744073709551615LLU,17870283321406132223LLU,9216616637413720063LLU,18428727610126105791LLU,17297322445140656127LLU,16777215LLU},{18446744073646636545LLU,576460752303423453LLU,18446743523953737728LLU,1152921504606846975LLU,1152921504606785520LLU,16777200LLU},{18446744073709551615LLU,18158297092407951359LLU,274870484971LLU,11529215046068453376LLU,4611686018420467350LLU,16776975LLU},{18374690864833231871LLU,18446744073709551615LLU,18446744073709551615LLU,17293822569102721023LLU,18365679005555752959LLU,16773375LLU},{18446744073709551615LLU,576460743713492991LLU,6897262798846295936LLU,18424212459117082287LLU,18377543617846706175LLU,16748031LLU},{16131885069145997823LLU,17870283329996062707LLU,17865764328615968767LLU,18301501334294953467LLU,17365316658867990543LLU,16547807LLU},{18446741874688393215LLU,9223372028264972287LLU,18445635765988753280LLU,17582043874279555071LLU,18379190079282221055LLU,16748031LLU},{72057594037927935LLU,11511059806991298560LLU,1125880573196799LLU,18446744073709535232LLU,4607182693677924351LLU,16776975LLU},{17867750046615667169LLU,18446708897927396351LLU,18334147485954998399LLU,1152655918861569535LLU,15633680384867172111LLU,15956991LLU},{6872449048819859455LLU,17870318505744760627LLU,4035181285658853375LLU,17698020635239120795LLU,17865621254597308671LLU,13434783LLU},{18446741876833714657LLU,9223336981365260287LLU,18445681945476597632LLU,1152700227888545791LLU,17879290520645140239LLU,15964671LLU},{72057472670492411LLU,15690539417703792639LLU,912163006815737LLU,16140901064495857663LLU,18284579577627375575LLU,12312559LLU},{18446185521802641407LLU,13831539549353701376LLU,18446744073199942655LLU,18446744004994252800LLU,4607217601041399807LLU,7274268LLU},{18446744071631404575LLU,17870318505744760661LLU,18446743523954262015LLU,18446744073709551615LLU,4611686018426339568LLU,13434768LLU},{72620428027227135LLU,18446744073709551615LLU,912594651054079LLU,17293822637822181375LLU,18203514511606939647LLU,12308991LLU},{18446249430915948519LLU,13835024993160720639LLU,18445895250732415879LLU,4611685950241554559LLU,18118262773862367039LLU,7847807LLU}};

static uint_fast64_t D[21][6] = {{72061463734176766LLU,18446744073709549738LLU,11734129928625455103LLU,17352754085220080465LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,8316515587414290431LLU,6712614380586710859LLU,18387812557592175790LLU,18446744073709551615LLU,16777215LLU},{18374682609975374849LLU,10130228486295263061LLU,18446743838206937268LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,9764789025708576767LLU,6712615210263246975LLU,18423921893837890734LLU,18442240474098958335LLU,16777215LLU},{18446744073709551615LLU,8898746585330221055LLU,18445618414311225291LLU,35807520299696127LLU,18446744073692774400LLU,16777215LLU},{11791105169412849152LLU,18446744073709550028LLU,16923805020518875135LLU,789640625067351029LLU,1152921504606785520LLU,16777200LLU},{6727700367967964159LLU,18446744073709551291LLU,4026941545520300031LLU,17698018501176130587LLU,17297322445140656127LLU,16777215LLU},{18374687563319572781LLU,17209925137431781375LLU,18446743994973810366LLU,18446744073709551615LLU,18365679005555752959LLU,16773375LLU},{18374685911489033939LLU,11078600441271433045LLU,18446743642057349601LLU,11529215046068469759LLU,4611686018420467350LLU,16776975LLU},{14395461539771449344LLU,18446744073709550576LLU,17509978858542071807LLU,934883916387213305LLU,11529215046068465664LLU,16547802LLU},{13527528698787397631LLU,576460752303422927LLU,14960236652025347968LLU,18151742891966067687LLU,8069244290112360447LLU,16748021LLU},{14395461539773546495LLU,18411700310260055024LLU,17325347762633439359LLU,18444720368842165752LLU,11526357907910164479LLU,16547802LLU},{18446742958334245165LLU,9114414413720846335LLU,18446743970604771230LLU,6953336547940777983LLU,18365679280407026025LLU,16773375LLU},{4557590044195422207LLU,18446744073676095247LLU,1152868697577095167LLU,17548275947545034631LLU,9218630736455667711LLU,13627317LLU},{17578252680881504225LLU,576460752303421951LLU,18310932397446135808LLU,1152642164226769919LLU,14984598534253182975LLU,15964671LLU},{1085301539498622975LLU,18411700439109041920LLU,144115153743380479LLU,18410996751134621568LLU,4611408700861579263LLU,13434768LLU},{18446184422013894575LLU,18442495554335801343LLU,18446744073180675999LLU,9223371968135315455LLU,18446744071570316669LLU,7274236LLU},{18446743936755556473LLU,8682938019451240447LLU,18446530253057656824LLU,13870865575586037759LLU,18203549693827560387LLU,12308991LLU},{17433503998014376959LLU,18446744073709549823LLU,18302692657308106751LLU,18446462599266484351LLU,17875064238616084479LLU,15964671LLU},{18446742424026431367LLU,13830556577903441749LLU,18446744073172712327LLU,4611686018427387903LLU,4611686018414595132LLU,7274268LLU},{1085367508533771903LLU,17874786921002041343LLU,144114638856912895LLU,17294104044079415295LLU,18446713046864966643LLU,10352627LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][6] = {{72061463734176766LLU,18446744073709549738LLU,11734129928625455103LLU,17352754085220080465LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,5],[1,6],[2,4],[2,10],[3,6],[3,11],[4,5],[4,7],[5,8],[6,9],[7,8],[7,10],[8,12],[9,11],[9,12],[10,13],[11,13],[12,13]]\n", fout);
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

