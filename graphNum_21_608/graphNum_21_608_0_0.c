#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_608_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][5] = {{1108307989233663LLU,18446744073707458572LLU,18446742974210506815LLU,4468133780304953343LLU,18014398505287680LLU},{18446744073709551615LLU,3LLU,18446744073709551600LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,15LLU,18446744073709289472LLU,18014398509481983LLU},{18446744073705357312LLU,18446744073709551615LLU,6725378375562559455LLU,18446726481523725813LLU,18014398509481983LLU},{4194303LLU,18446744073707454468LLU,18446744073709551615LLU,17592186044415LLU,18014398509481920LLU},{18446744073705357313LLU,2097151LLU,18446744073709551600LLU,18446726481523769343LLU,18014398509481983LLU},{18446744073709551615LLU,18325140286688198655LLU,18446742974197923843LLU,18446730621065887743LLU,18014398505287743LLU},{18445653357914750975LLU,18446744073709551615LLU,1099511627775LLU,13978627885590380544LLU,18014123635769343LLU},{18446726481527035563LLU,13546528465368379399LLU,18446744073709551615LLU,18302646477819740159LLU,18014032007004159LLU},{17592186044415LLU,18446744073707458556LLU,18446744073705357375LLU,144115188075855871LLU,18013848753651712LLU},{17723907365088001025LLU,18446742974198765165LLU,18446744073709551615LLU,18446744073441378303LLU,17997905832548799LLU},{18446744073705358335LLU,1099511627775LLU,18158518095604350960LLU,18446726481791942655LLU,17750514649268223LLU},{18446726481791942655LLU,18365674882361978895LLU,18446742974202118135LLU,18303182867158007807LLU,18014123627397119LLU},{18445688542295227395LLU,18446742974214701055LLU,288230376151711743LLU,14122760665584893952LLU,17997632030900223LLU},{0LLU,18446744073709551612LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{14987978735255225151LLU,18428730710286925311LLU,18445622520309415935LLU,18428729606698692863LLU,17117145418168311LLU},{18433233271602085875LLU,18014398257807327LLU,865817028160650480LLU,9222228613478219775LLU,14425588328529791LLU},{18446519773286760387LLU,16285016248292472828LLU,271341052912205823LLU,17509888973450772416LLU,12381584130826207LLU},{18229726814924694591LLU,18446611037097492351LLU,18446678099790647295LLU,14983053744323428415LLU,8712272427744765LLU},{18159076578923905023LLU,18446744073709428495LLU,18446744069431345201LLU,2297104090795933695LLU,6605865859431484LLU},{288072115163201535LLU,18430981475011784956LLU,18446742978488713215LLU,17735104912301227983LLU,12910465529398211LLU}};

static uint_fast64_t D[21][5] = {{18446744073707553795LLU,141871084860342271LLU,864695526501646334LLU,18446739934167367920LLU,18014123635769343LLU},{6509981201745313790LLU,18446744073709551614LLU,6437146533399538335LLU,18446744073709442469LLU,18014398509481983LLU},{11936762871964237825LLU,3725829950847057925LLU,18446744073709551613LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073707454467LLU,17870280389383509375LLU,17592185913183LLU,18014398509481920LLU},{18446744073709551615LLU,14720914122862493695LLU,864695526489063362LLU,18446726481523704048LLU,18014398509481983LLU},{6509981201745313791LLU,18446744073709551614LLU,17582048547220488255LLU,17592185847567LLU,18014398509481920LLU},{18445635765722514435LLU,3746097248686043127LLU,18446744073709551615LLU,13978627885590642687LLU,18014123635769343LLU},{11936780464156474365LLU,18304872988849213453LLU,18446744073709551601LLU,18446730621065887743LLU,18014398505287743LLU},{18446744073709551615LLU,17252091118380646399LLU,4381105235939033098LLU,18446736829800199155LLU,18013848753651775LLU},{18446744073708885675LLU,11015351469850230783LLU,14930334364255387639LLU,18446733725433056508LLU,18014032007004159LLU},{6872455087470411775LLU,18446744073709551615LLU,18158514538363810047LLU,9021818361343901695LLU,17750514649268198LLU},{17361433479362904063LLU,18446744073708295788LLU,17582052104461029183LLU,9424943304551497487LLU,17997905832548761LLU},{18445635765987421527LLU,7492194497372090367LLU,4381105235943227390LLU,13979170483663221747LLU,18013665504526335LLU},{1085363370919361535LLU,18304872988865149343LLU,18446743815003894001LLU,9165937688962924543LLU,17750515717138022LLU},{18446744073709551615LLU,14720914122862493691LLU,12009597540310013282LLU,18446744073709398618LLU,18014398509481983LLU},{18429209058092253171LLU,18446744073456818124LLU,288229551263185983LLU,1943549529811648511LLU,14626799960923935LLU},{13906692354422603583LLU,18446744009284582527LLU,18446744006063558655LLU,16685625513124818959LLU,17163324969054705LLU},{14717762693186446335LLU,18446604435732462911LLU,18446678047445533681LLU,18421961077592948735LLU,8567394590323956LLU},{4598158723649142783LLU,16143152864307950556LLU,18429854544109501695LLU,9114158663559282687LLU,12279345654484815LLU},{18446603336187191055LLU,16267142523099545599LLU,18428800043944247295LLU,17870212063540801728LLU,12910400857178111LLU},{18446181123618235635LLU,2305710036774551551LLU,882639556266950640LLU,16140603093418774527LLU,6605655662133247LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][5] = {{18446744073707553795LLU,141871084860342271LLU,864695526501646334LLU,18446739934167367920LLU,18014123635769343LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU}};

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

    } else {
        A[i][0] = A[i-1][0] & D[i][0];
        A[i][1] = A[i-1][1] & D[i][1];
        A[i][2] = A[i-1][2] & D[i][2];
        A[i][3] = A[i-1][3] & D[i][3];
        A[i][4] = A[i-1][4] & D[i][4];

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,6],[3,7],[4,6],[4,8],[5,7],[5,9],[6,8],[7,10],[8,11],[9,12],[9,13],[10,12],[10,13],[11,12],[11,13]]\n", fout);
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
