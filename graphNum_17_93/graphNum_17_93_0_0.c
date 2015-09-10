#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_17_93_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 16;
static uint_fast32_t endhere = 0;
char str[27] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[17][10] = {{13402708573205168065LLU,18446743504425056445LLU,18446744073709551615LLU,18014398475139022847LLU,17309576129031204813LLU,17829627779440109567LLU,2305840732075712606LLU,18446673704977821407LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,1099511627775LLU,0LLU,18446744073692774400LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU,18428729675200069632LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU,0LLU,18446744073709551488LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,127LLU,18446744073692774400LLU,18446744073709551615LLU,15LLU},{0LLU,18446742974197923840LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18427010039014227967LLU,18374687407375370219LLU,13975794443085676543LLU,18446744073708764927LLU,1152921504606846975LLU,14987979145486532600LLU,18392427512101609459LLU,70368742580223LLU,18446744073709551552LLU,15LLU},{18446744061898389567LLU,72057593229361151LLU,4611686018427387648LLU,18446708923697194968LLU,18446531043331669311LLU,18446744073709551615LLU,18438018346144235519LLU,18446744073709551608LLU,18446744073675997247LLU,15LLU},{16710360126747772927LLU,18446744073709551615LLU,18446717514688758015LLU,12069682185725018111LLU,18446744073506390015LLU,18445758844719046151LLU,18446744073709551615LLU,18446744073709551615LLU,18446726481557061631LLU,15LLU},{18446743798831644672LLU,17582052945254416383LLU,18437736389121405919LLU,18446744073707454350LLU,18302628885633695743LLU,9223370928752952287LLU,18301502951497137150LLU,18446726266674282495LLU,18445633558136471103LLU,15LLU},{274877906943LLU,18437723680315277184LLU,17870283321406050303LLU,71635377277877375LLU,18446713287383973880LLU,18446744073709551615LLU,18446704525650591743LLU,18444559618983067535LLU,18375812171540987900LLU,15LLU},{18446744073709551615LLU,14987644208842539135LLU,18446669856540459006LLU,18446743661258473471LLU,4611686018398011399LLU,18430981474712027135LLU,18446744073709551615LLU,17944592713781346303LLU,13907115649319694847LLU,15LLU},{18446744055992803315LLU,18446744073545972223LLU,18374686479688400895LLU,18443366372948836351LLU,18445899442620988383LLU,18446744073709551615LLU,3467771712538403071LLU,18437736840111849471LLU,4395231731272122359LLU,15LLU},{18095460004231118543LLU,18446744073709551615LLU,72057594037927935LLU,8935138328865406976LLU,17329851365316165631LLU,18446629793219735551LLU,18446744073709551615LLU,17293470759741554687LLU,18443331189616877567LLU,12LLU},{18446744073575399423LLU,18444562635123314687LLU,14987979559888615423LLU,18446744073709453247LLU,18446744056529698815LLU,18446744073709551615LLU,18446532937411330047LLU,9295425095407237247LLU,17870159351268769791LLU,10LLU},{2304690446284095487LLU,17800477527181885439LLU,18446321585561272313LLU,18446744073709551615LLU,18428729692379938815LLU,18176528094456479736LLU,18446744073709551615LLU,9223372034640183295LLU,13825065693607362112LLU,7LLU},{18446744073592109559LLU,18445046427756265344LLU,18375249429625044743LLU,18446713286578667519LLU,18446744057603424248LLU,288230376151711743LLU,18446744073709551488LLU,11527526166143434751LLU,9169258472550694911LLU,11LLU}};

static uint_fast64_t D[17][10] = {{18438299815814103039LLU,962068742127LLU,18446744073692774400LLU,13835058055282163711LLU,18446532967275691519LLU,18446744005052989439LLU,18437745120792018931LLU,12928567892783923199LLU,18446738985639996121LLU,15LLU},{3314279127108643709LLU,18446743431007788725LLU,18446744073709551615LLU,14824987131536998399LLU,9194035921957113449LLU,17676047995236562875LLU,16140894095634005852LLU,18446744073704958619LLU,18446744073709551615LLU,15LLU},{18315429400004263934LLU,11240983123667383243LLU,18274473609736985503LLU,18446744073702996204LLU,16861477004875137023LLU,8070438274330524511LLU,16840074323690509291LLU,18446744073706856447LLU,18446744073709551615LLU,15LLU},{18446743737091399579LLU,18347554920672505343LLU,12105675798354388991LLU,18368916195370678047LLU,18445261588437905823LLU,18446744073709551615LLU,13825663787667914495LLU,18446744073709549422LLU,18446744073709551615LLU,15LLU},{15263779956924347623LLU,16714239203776397182LLU,18373902663843577588LLU,3746954069126676479LLU,13799029239669522422LLU,18138071505701654518LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,9037455615714131967LLU,6586180149193702763LLU,18399374825100857331LLU,15487172539898527743LLU,11455674445859912941LLU,8533600014136225207LLU,18446744073700064757LLU,18446744073709551615LLU,15LLU},{16285016252571648001LLU,18446743522947104703LLU,18446717547991531519LLU,18410715276707358687LLU,18446744073709551615LLU,18445635765971945471LLU,2305840806163906526LLU,18446689552551510008LLU,18446733017335347135LLU,15LLU},{18446463079767212031LLU,18446744020014071807LLU,18446744039383367679LLU,16285016252570926847LLU,15753802600706047LLU,18446744073709551104LLU,18392700663432740863LLU,18347578707666767583LLU,18446742625970028518LLU,15LLU},{13817043652712595455LLU,18446744073709420793LLU,140736388843700223LLU,18446744073709551608LLU,18446741906890161933LLU,14370985998620753919LLU,18446744073642442879LLU,5617396068137304063LLU,18446744073706790271LLU,15LLU},{18446744073709551615LLU,9223303867133853695LLU,17543666777915817854LLU,36028797010026491LLU,1729382256910254080LLU,16124007858206408447LLU,17829698148167987127LLU,18374754648309350279LLU,15665771097649446911LLU,15LLU},{18446744073709551615LLU,13942722233873989631LLU,6917524663950901247LLU,18435484576220377086LLU,18441536099414179839LLU,18446744073675997695LLU,9005369667385817599LLU,18014380916792393213LLU,16644439998031982655LLU,15LLU},{18446744073709551615LLU,18432107374920597503LLU,18432934200685347275LLU,18446240490404707335LLU,18230538301280223231LLU,4539274917442486221LLU,18446739675730149374LLU,18446743034327465983LLU,18418350283315724284LLU,15LLU},{18374967815047183999LLU,18446743862719242239LLU,18446744073709551615LLU,2287543287436804095LLU,18437718181716942719LLU,18446735277650083839LLU,18446743229739499519LLU,16680910807313415099LLU,18443326103704506333LLU,12LLU},{8070362541184764927LLU,18446744073676128231LLU,18446744073709551615LLU,17289864052364804095LLU,9222281312712259835LLU,18293058736419094459LLU,17293826967149215729LLU,13532190980341497855LLU,4395231729114938099LLU,15LLU},{72057594037927935LLU,4611685193774726143LLU,18446185521790050296LLU,18446744073696968185LLU,18446744073709551615LLU,18158522493650862079LLU,17575294247228139519LLU,18446708335808872447LLU,11371580244761837567LLU,7LLU},{18406068740551606271LLU,16140901055939477407LLU,18392698653387538239LLU,18446744073709421567LLU,17582052945254416383LLU,18446737425075011199LLU,1152921504606846863LLU,18446736359679850496LLU,17543771283253065727LLU,10LLU},{18446743833191333855LLU,18392664602887323647LLU,18446744073693298687LLU,18415218850531508223LLU,18429855575106897919LLU,18446744073709551615LLU,18446744073709551615LLU,18392639305513175039LLU,14987400117261172687LLU,5LLU}};

uint_fast8_t X[17] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[17][10] = {{18438299815814103039LLU,962068742127LLU,18446744073692774400LLU,13835058055282163711LLU,18446532967275691519LLU,18446744005052989439LLU,18437745120792018931LLU,12928567892783923199LLU,18446738985639996121LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU}};

#if UINTPTR_MAX == 0xffffffffffffffff // 64-bit. Hopefully this means the cpu has 'popcnt'.
int counter (uint64_t * buf){
    uint64_t cnt[17];
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
           "popcnt %1, %1  \n\t"
           "add %1, %0     \n\t"
            : "+r" (cnt[16])
            : "r" (buf[16]));


    return cnt[0] + cnt[1] + cnt[2] + cnt[3] + cnt[4] + cnt[5] + cnt[6] + cnt[7] + cnt[8] + cnt[9] + cnt[10] + cnt[11] + cnt[12] + cnt[13] + cnt[14] + cnt[15] + cnt[16];
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
        A[i][7] = A[i-1][7] & C[i][7];
        A[i][8] = A[i-1][8] & C[i][8];
        A[i][9] = A[i-1][9] & C[i][9];

    } else {
        A[i][0] = A[i-1][0] & D[i][0];
        A[i][1] = A[i-1][1] & D[i][1];
        A[i][2] = A[i-1][2] & D[i][2];
        A[i][3] = A[i-1][3] & D[i][3];
        A[i][4] = A[i-1][4] & D[i][4];
        A[i][5] = A[i-1][5] & D[i][5];
        A[i][6] = A[i-1][6] & D[i][6];
        A[i][7] = A[i-1][7] & D[i][7];
        A[i][8] = A[i-1][8] & D[i][8];
        A[i][9] = A[i-1][9] & D[i][9];

    }
}

void printout(){
    sprintf(str, "[                 ,%5d]\n", this);
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
    fputs("[[0,2],[0,3],[0,4],[0,5],[0,6],[1,3],[1,4],[1,5],[1,6],[2,4],[2,5],[2,6],[3,5],[3,6],[4,5],[4,6],[5,6]]\n", fout);
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

