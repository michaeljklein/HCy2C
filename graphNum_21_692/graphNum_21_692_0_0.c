#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_692_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][6] = {{18446744073441116161LLU,137438953471LLU,18446744073441116160LLU,4611686018427387903LLU,18446744073642442752LLU,70368744177663LLU},{18446744073709551615LLU,16383LLU,18446744073441116160LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,268435455LLU,13835058055282163712LLU,18446744073709551615LLU,70368744177663LLU},{18446744073441116160LLU,18446744073709551615LLU,8635089334992633855LLU,3890397549379805149LLU,18446744073642442752LLU,70368744177663LLU},{268435455LLU,18446743936270614528LLU,18446744073709551615LLU,18446744073709551615LLU,18428729675267178495LLU,70368744177663LLU},{0LLU,18446744073709535232LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18439988674268495871LLU,16131891941095768047LLU,255582079LLU,4611686018427386880LLU,17448150007249854LLU,70368744177648LLU},{17582052877071810559LLU,18302628885633693695LLU,18446744073709551609LLU,13835058055282164735LLU,18442187689001209599LLU,70368743915535LLU},{18445618173996949275LLU,9219708464102670335LLU,18446744073675896319LLU,18446743042904817663LLU,18446742974265032703LLU,70368710682271LLU},{1125899906742271LLU,17870283183975546880LLU,18446673706039115727LLU,18429855575106912255LLU,16140902164007485439LLU,70364482764799LLU},{16140337702225559553LLU,111530540287LLU,18442521949058891775LLU,4395513236313604095LLU,10916725496746078208LLU,70303245074423LLU},{18428729674931650559LLU,18446744072082161657LLU,4611686018158952448LLU,18446730879568973823LLU,18302628885566590975LLU,69337645833999LLU},{18438862843076935551LLU,18444490624620101615LLU,70368735723519LLU,9223371006050040832LLU,2305275669795307518LLU,70368710885360LLU},{17446891076605181951LLU,18446744073659209727LLU,1098825516414139645LLU,18446744056529683440LLU,18433167080321642495LLU,66726498660367LLU},{18446744009083715523LLU,18302068113228692895LLU,17581205221537742843LLU,13835058072462032895LLU,18445618165699305185LLU,57160106512383LLU},{1123974662550783LLU,17802729326466695167LLU,18392700604374974447LLU,18446744073457106943LLU,4485304836078698303LLU,51384753847679LLU},{18445688529660870647LLU,18446717548522094592LLU,18446673979843268575LLU,18429575199641828415LLU,16267282502794346491LLU,30640565100531LLU},{17762161467877736511LLU,562949919735807LLU,18443366361104121085LLU,18230571274416947184LLU,13835013936975372319LLU,67018593595647LLU},{18356672081160045559LLU,72031101018686457LLU,18446691297151401984LLU,18446519757231296511LLU,17136196582144213243LLU,32776673792975LLU},{4607174137836732383LLU,18446321311219449855LLU,3463267907021062143LLU,4899915569944395775LLU,9151171450404077551LLU,43155823918910LLU},{18445626969889558399LLU,1150668535480963067LLU,1152868728040243263LLU,18446744060824599552LLU,17140699150971073534LLU,32779161040849LLU}};

static uint_fast64_t D[21][6] = {{11765245970789433343LLU,18446744073709541166LLU,14717482108343812095LLU,14916990758853537843LLU,18428729675267178495LLU,70368744177663LLU},{11765245970789433342LLU,18446744073709541166LLU,7392002013204054015LLU,16548871166376630937LLU,18446744073709551615LLU,70368744177663LLU},{6681498102920118273LLU,7395706359682984145LLU,18446744073606030734LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446743936270614527LLU,15960569430132391935LLU,16093575197138875767LLU,18428729675267178495LLU,70368744177663LLU},{18446744073709551615LLU,11051037714026594303LLU,3729261965469260401LLU,3529753314856013772LLU,18446744073642442752LLU,70368744177663LLU},{18446744073709551615LLU,11051037714026577919LLU,11054742060609018481LLU,15732930962615084390LLU,18446744073709551615LLU,70368744177663LLU},{17347865695959095683LLU,8987729046347411933LLU,18446744073608328696LLU,18446744073709551615LLU,18442187689001209599LLU,70368743915535LLU},{6908929884591777405LLU,14395754066355482339LLU,18446744073694400271LLU,4611686018427387903LLU,17448150007249854LLU,70368744177648LLU},{18446744073709451263LLU,15231085703958888447LLU,18446673705094078279LLU,13817100828104970239LLU,16158915462964132147LLU,70364482764799LLU},{18446744073635356443LLU,4463199721875308543LLU,3729261966380642553LLU,8142507031053221836LLU,18446744073683650252LLU,70368710682271LLU},{13515211183082176511LLU,18446744072082151416LLU,882651716393107455LLU,14984584542859297599LLU,18288671284994768895LLU,69337645833999LLU},{14372358091423350783LLU,18446744047801138223LLU,18442294285727432703LLU,18162964313449430259LLU,10912668698942636031LLU,70303245074423LLU},{17347865764480037351LLU,17311704969727963613LLU,18446744073506652096LLU,18428786846532358143LLU,18442187697488366707LLU,70364482705775LLU},{6916820804477845441LLU,18446181228573293703LLU,17581205221523050463LLU,4611686018427387903LLU,15166434695060389856LLU,57160106770418LLU},{18303691288731018879LLU,14395756139036397563LLU,1098825516413680687LLU,18446744073709551600LLU,3287611011966598079LLU,66726498664445LLU},{18445688529593294835LLU,4467536745484779519LLU,17581208520265548795LLU,18446462603027758095LLU,18446743247439648504LLU,30644572489683LLU},{18446742148458740767LLU,18374826667403771903LLU,4540754324294221053LLU,8142508126017486844LLU,4611686001109561103LLU,51384974375999LLU},{4606964676607016959LLU,18446744065385430912LLU,17365875833547247583LLU,14984584542860345151LLU,17940227339962810367LLU,56486602465274LLU},{1146157325178896351LLU,18446321311085035439LLU,17293889381613961215LLU,4629699385930809343LLU,2195853296822910959LLU,43954691178494LLU},{17761317310309581815LLU,72031076872077439LLU,18446678090126983167LLU,18432969375125339379LLU,16701554549101424891LLU,32943405773815LLU},{144115135311510991LLU,18392173090655174047LLU,18446740517273731071LLU,13835339530006429695LLU,18337267893342830439LLU,43952950246783LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][6] = {{11765245970789433343LLU,18446744073709541166LLU,14717482108343812095LLU,14916990758853537843LLU,18428729675267178495LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,6],[3,7],[4,6],[4,8],[5,9],[5,10],[6,11],[7,9],[7,12],[8,12],[8,13],[9,13],[10,11],[10,13],[11,12]]\n", fout);
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

