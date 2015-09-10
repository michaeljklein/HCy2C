#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_717_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][6] = {{33554431LLU,18446742974197956608LLU,18446744073709551615LLU,18446744073709551615LLU,18158513697826275327LLU,70368744177663LLU},{18446744073709551615LLU,32767LLU,18446744072635809792LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,1073741823LLU,13835058055282163712LLU,18446744073709551615LLU,70368744177663LLU},{18446744073675997184LLU,18446744073709551615LLU,6187380736882900991LLU,3987750406997374807LLU,18446744073441116160LLU,70368744177663LLU},{0LLU,18446744073709518848LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073675997185LLU,1099511627775LLU,18446744072635809792LLU,4611686018427387903LLU,18446744073441116160LLU,70368744177663LLU},{18309383460441030655LLU,18419722475945312255LLU,536870667LLU,18446744073709535232LLU,143978745420451743LLU,70368744177600LLU},{18446603335214563327LLU,13835025069933329401LLU,18446744073675800575LLU,16383LLU,18407336473395198972LLU,70368743915583LLU},{18442240474107295615LLU,18374686479403253759LLU,18446744073575332350LLU,14987979559872299007LLU,18446735277884964863LLU,70368710737471LLU},{4503599624748531LLU,17293610363626946560LLU,18446742978483978239LLU,18446744073709550847LLU,16140909860588879871LLU,70364482764781LLU},{17581487796277731329LLU,822951800831LLU,18446744073709551608LLU,4611405436803874815LLU,18446744073709543424LLU,70302071490303LLU},{18446708882861465599LLU,18446743987793034991LLU,71213168034054151LLU,18446744073709551615LLU,13258597302710312959LLU,69337942851576LLU},{18419722475943755715LLU,18415254060690046975LLU,18428729675732991947LLU,18429838863389163519LLU,288203987725291395LLU,67053935394815LLU},{9113032884985266175LLU,18446744022167961479LLU,18014398509481791LLU,14771806776767594496LLU,18288445052491300863LLU,56556125421504LLU},{18446744073507978879LLU,13292367703114252287LLU,17351524939294605567LLU,4611685743549497283LLU,18446744072866626159LLU,48172326711359LLU},{143957888388300799LLU,18446717677364837369LLU,18446678038587375615LLU,13835058330160057599LLU,18406350882321989628LLU,34045702180863LLU},{18415219013755830223LLU,18424507550283071487LLU,18428730774708550623LLU,18433220080672178175LLU,2305807859192938407LLU,67057295031935LLU},{18446744073508028151LLU,18014252283025391616LLU,17582051914462103551LLU,9223371761993646031LLU,16430257339746221823LLU,48168595091967LLU},{17798225048763359295LLU,4503564192317343LLU,18446744073709551416LLU,18446480190112776192LLU,18437666411221245983LLU,57122994757575LLU},{1152908305602183167LLU,18446717678979383291LLU,1152868675435397119LLU,13835339530258874367LLU,18443647571672956924LLU,33259823333369LLU},{18415236468302512087LLU,18443224605456826495LLU,18428799013152070655LLU,18446743799889657855LLU,2612053148452782063LLU,50428259594879LLU}};

static uint_fast64_t D[21][6] = {{18446744073709551615LLU,3825458238753603583LLU,57699067826320907LLU,3675782601282368259LLU,18446744073441116160LLU,70368744177663LLU},{7788529349304516606LLU,18446744073709531985LLU,6168147714417623039LLU,16597547595185415766LLU,18446744073709551615LLU,70368744177663LLU},{10658214724405035009LLU,14621285834956000430LLU,18446744073279064564LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446742974197956607LLU,18408278028778995711LLU,15996222339521306109LLU,18158513697826275327LLU,70368744177663LLU},{18446744073709551615LLU,3825458238753570815LLU,12278596359722415627LLU,15684254533806299561LLU,18446744073709551615LLU,70368744177663LLU},{7788529349304516607LLU,18446744073709531985LLU,18389045006313717759LLU,14770961472427183356LLU,18158513697826275327LLU,70368744177663LLU},{10663738865257820797LLU,11168892561945192952LLU,18446744073524759038LLU,4611686018427387903LLU,18407336473395198972LLU,70368743915583LLU},{18303718581093256579LLU,17260396745179897519LLU,18446744072893234945LLU,18446744073709551615LLU,143978745420451743LLU,70368744177600LLU},{18446744073706929651LLU,16563979944724529151LLU,14123287332445599659LLU,9165894847419120655LLU,16429131440489450714LLU,70364482764781LLU},{18446744073701111679LLU,4483032162861318143LLU,4381154713730480222LLU,9497867313735545843LLU,18446744073599234853LLU,70368710737471LLU},{8023105278557814783LLU,18446743987793018467LLU,16905833090646015LLU,14770962349419200511LLU,13088818647806246911LLU,69337942851576LLU},{17346876676209901567LLU,18446743797149721565LLU,18443352342330867711LLU,18446462615094021372LLU,18328292352998768639LLU,70302071490303LLU},{4035225128705897087LLU,11168927010378547072LLU,18446744073524997630LLU,14771806776767610879LLU,18429292591028632575LLU,56556125199807LLU},{15851885637039914945LLU,18442241158479342079LLU,18446744073705364479LLU,4594780808106999807LLU,18410714177162706912LLU,67053935354495LLU},{4486037485645291LLU,17293189242067615743LLU,18446678037771059193LLU,18446744073709538559LLU,15851553051820158975LLU,34045702438857LLU},{18443331170289327639LLU,17871267813658042031LLU,17351524939328356359LLU,18446744073709551555LLU,2738184175393709583LLU,48172326715382LLU},{4035225266117605631LLU,9367473965292846976LLU,14123288431370823615LLU,8953103281597447183LLU,18429292625100765438LLU,56555256864237LLU},{18446726511562057711LLU,9204495621213126655LLU,4611616748185059160LLU,14109553332179682303LLU,16140900531710109621LLU,34046198792155LLU},{14978695283098091519LLU,18446743865344915579LLU,18445635508286528511LLU,18429011134067507199LLU,13202010109989355519LLU,66656676051839LLU},{18352449380851645975LLU,17871267624629274527LLU,18429854750473191423LLU,18446743815192838080LLU,7845175915033132559LLU,48350576506615LLU},{4035225158718317055LLU,576434358654337023LLU,1152921503537299256LLU,13852808571000963135LLU,18446181106324496892LLU,25803825127369LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][6] = {{18446744073709551615LLU,3825458238753603583LLU,57699067826320907LLU,3675782601282368259LLU,18446744073441116160LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,6],[3,7],[4,8],[4,9],[5,10],[5,11],[6,8],[6,10],[7,9],[7,11],[8,12],[9,12],[10,13],[11,13],[12,13]]\n", fout);
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
