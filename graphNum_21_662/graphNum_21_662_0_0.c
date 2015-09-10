#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_662_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][6] = {{18446744073675997185LLU,1073741823LLU,18446744073709486080LLU,4398046511103LLU,18446744073709551600LLU,262143LLU},{18446744073709551615LLU,255LLU,18446744073709486080LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,65535LLU,18446739675663040512LLU,18446744073709551615LLU,262143LLU},{18446744073675997184LLU,18446744073709551615LLU,6906119943087849471LLU,3811605084117LLU,18446744073709551600LLU,262143LLU},{33554431LLU,18446744072635810048LLU,18446744073709551615LLU,18446744073709551615LLU,18446744072635809807LLU,262143LLU},{0LLU,18446744073709551360LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18419722475945328639LLU,18191727729777311743LLU,18158513697557903231LLU,9090485061521768447LLU,18446726482595676157LLU,262143LLU},{16717361812571422719LLU,18446744073709551423LLU,288230376151703549LLU,17293818171056193536LLU,18158531288925993995LLU,262143LLU},{18446462598763757095LLU,17870221061559943679LLU,18446744073709551071LLU,18446744073709550655LLU,177505157187895311LLU,262143LLU},{281474959671295LLU,18446744072636071680LLU,18446744072636039159LLU,18446740774369361919LLU,18446744004990337023LLU,262080LLU},{13835055718819946497LLU,18428729676106018811LLU,18446532142843297791LLU,18428734073180520447LLU,15548676317632266239LLU,261695LLU},{18442768231040032767LLU,18014398507580415LLU,1152921504606781440LLU,18014398509481968LLU,18446475723079155696LLU,258556LLU},{18419441005263584895LLU,18230518502152471551LLU,18158513698631581695LLU,18338631294373592127LLU,288212852683310079LLU,262143LLU},{17870273975087415295LLU,288230376151711662LLU,283991757970989053LLU,16285016252571451392LLU,12679902342607232907LLU,249343LLU},{17041480214363766723LLU,18446739692830326655LLU,18230571240053014527LLU,18446211910081970175LLU,18160765496824034431LLU,212915LLU},{18158531222075867135LLU,18446744073692836863LLU,18176528031638844215LLU,9223368518471254015LLU,18446730670186230013LLU,209904LLU},{288230375748952575LLU,1134977473784577792LLU,18446744072640004095LLU,17565164446588601343LLU,18431544359473119135LLU,249423LLU},{18227193588620591043LLU,18446739692828753919LLU,1152921504606781440LLU,1152389341046112240LLU,18176264213276654832LLU,209904LLU},{18437735778162835319LLU,18374668677032166399LLU,4611668427315085071LLU,4575578040465096511LLU,16393066428463825663LLU,179199LLU},{2287548235104910079LLU,18301749267640631294LLU,18158531289680969727LLU,18372417087671880959LLU,2305826503602749407LLU,126847LLU},{18437735843394152319LLU,4594779926699167489LLU,18446726549236350975LLU,17856772522473439039LLU,16707227840457199551LLU,188127LLU}};

static uint_fast64_t D[21][6] = {{14348018051188785151LLU,18446744073709551404LLU,17310936195932618751LLU,18446740555325180991LLU,18446744072635809807LLU,262143LLU},{14348018051188785150LLU,18446744073709551404LLU,6527517317162205183LLU,18446742314473334421LLU,18446744073709551615LLU,262143LLU},{4098726022520766465LLU,12081616677922406867LLU,18446744073709513110LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744072635810047LLU,17689538821858263039LLU,18446741728119971199LLU,18446744072635809807LLU,262143LLU},{18446744073709551615LLU,6365127395787145215LLU,1135807877776971369LLU,3518384370624LLU,18446744073709551600LLU,262143LLU},{18446744073709551615LLU,6365127395787144959LLU,11919226756547384937LLU,18446741434899257706LLU,18446744073709551615LLU,262143LLU},{16209580954540584323LLU,12101091229453253919LLU,18446744073709538780LLU,17293822569102704639LLU,18158531288925993995LLU,262143LLU},{4579485282787381885LLU,18172253178246464499LLU,18446744073709515575LLU,9090485061521768447LLU,18446726482595676157LLU,262143LLU},{18446744073692512255LLU,6869535308581437439LLU,14987979558815283059LLU,6017609820440163315LLU,18446744006063816693LLU,262080LLU},{18446744073706913319LLU,17365813148765913087LLU,4594572391597726925LLU,12429134472313568268LLU,177505157188157434LLU,262143LLU},{17865999058175262719LLU,18446744073707649966LLU,233339443416924159LLU,18446740555326029808LLU,18446475722638383343LLU,258556LLU},{10313098869197504511LLU,18446744073541758841LLU,18230306326256287743LLU,18446744073642642495LLU,15548676316999296799LLU,261695LLU},{16209580958787595739LLU,1139196248849907487LLU,14987979559888949232LLU,14112834548685140979LLU,18269256507889549299LLU,262080LLU},{13551117784501190593LLU,18446739676554176507LLU,18230571240052978487LLU,9222813484947865599LLU,18446733742161917949LLU,212915LLU},{9222759875165950591LLU,13739496964774886LLU,18442505455528837119LLU,17305081568171130879LLU,12682129290939031551LLU,249343LLU},{18446744073306775615LLU,270220375688740863LLU,18443141248983228413LLU,16267564803949330447LLU,9782099865625427867LLU,249471LLU},{18446480123265286119LLU,18230570247918515199LLU,4327959174257307663LLU,4503361859054731260LLU,8826936316231741692LLU,209919LLU},{2278803887580246655LLU,18442469171997380576LLU,18442240541732110335LLU,18439988674268433471LLU,9799828601311793055LLU,249471LLU},{141863388102752735LLU,14986920730064584702LLU,18446744073646575615LLU,18154850399679398899LLU,18297421585616732115LLU,126821LLU},{18373560578689003507LLU,4598174961305648927LLU,1152921504606846720LLU,567347982769127423LLU,18382515001656082175LLU,179162LLU},{18300113200850403279LLU,18302624753865523199LLU,18163017297185145087LLU,18374242294153871344LLU,9006974954368728560LLU,96245LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][6] = {{14348018051188785151LLU,18446744073709551404LLU,17310936195932618751LLU,18446740555325180991LLU,18446744072635809807LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,6],[3,7],[4,6],[4,8],[5,9],[5,10],[6,11],[7,9],[7,10],[8,9],[8,12],[10,13],[11,12],[11,13],[12,13]]\n", fout);
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

