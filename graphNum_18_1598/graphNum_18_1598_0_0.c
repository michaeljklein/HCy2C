#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_18_1598_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 17;
static uint_fast32_t endhere = 0;
char str[28] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[18][9] = {{18446744073709551615LLU,4398046511103LLU,0LLU,18446744004990074880LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{0LLU,18446739675663040512LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,68719476735LLU,0LLU,18446744073709547520LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4095LLU,18446744004990074880LLU,18446744073709551615LLU,67108863LLU},{12356590398564941808LLU,18446740559872654959LLU,18446744073709551615LLU,18446603404940673023LLU,6733845353761587711LLU,10051426878964570981LLU,18410715326044886847LLU,18446744073709551615LLU,67108863LLU},{9211831434698817039LLU,17293826692035506651LLU,9218886029413449727LLU,18446744071293600508LLU,18446744073709551615LLU,18364200277256437759LLU,36028792312561663LLU,18446744073701163008LLU,67108863LLU},{18374651295299534847LLU,1152921504591056886LLU,13839561654909009920LLU,13835198775456432127LLU,18446669306918862847LLU,9203105838530624991LLU,18446744072097366008LLU,18446603336229584895LLU,67108863LLU},{17725534814615691775LLU,18446744073709551615LLU,18446726481524031487LLU,4611686018427387903LLU,13821547222039805440LLU,18446724282291585023LLU,18446744073709550791LLU,140737488355327LLU,67108860LLU},{18446611307678406651LLU,1152921399645425462LLU,17262294862473911743LLU,18446744069204639603LLU,18446744073709551615LLU,17994101524824854527LLU,18441500201521250303LLU,7708715046150340607LLU,67108739LLU},{14105414770412748799LLU,18337537967498723327LLU,18445503274837606399LLU,18446708854172417791LLU,17294948464714580351LLU,18446743798840033279LLU,13851935558499762239LLU,16129642065427423487LLU,67076221LLU},{18446744036667555743LLU,18429855559994522623LLU,18194120274582962160LLU,9219005601301129166LLU,18446181128051097587LLU,18446744073709551615LLU,4611615099927396351LLU,18302065927358775040LLU,66093055LLU},{18446739675663040512LLU,18446744073709551615LLU,9223369837815791615LLU,9223371755534417856LLU,2305825159329611775LLU,18446181673511944062LLU,4604929656850743295LLU,4610700856007794654LLU,63668183LLU},{4398046511103LLU,18446585744035151616LLU,14411448318464855839LLU,18131482753915419711LLU,18446744073433741278LLU,18446744073709551615LLU,18230132586456285183LLU,17565151123663224831LLU,54519423LLU},{18446744073709551615LLU,18446704491290951935LLU,18446744073709549823LLU,18338094732699238399LLU,18338655758448590847LLU,17870846263306354673LLU,17582052945254410238LLU,18446742011269151217LLU,16710127LLU},{18446744073709518833LLU,18446744073709551615LLU,17592186044415LLU,18446603404940673024LLU,18444492273895851007LLU,11529215046051643391LLU,18410715345410064255LLU,18446744073709551615LLU,67108863LLU},{18446744000693272191LLU,1170935901905737727LLU,18415781825463975935LLU,18446744073709330421LLU,562949953421311LLU,18446744073709547520LLU,18446744073709551615LLU,18446744073449505023LLU,67108739LLU},{14898993885366714367LLU,18373630948508958719LLU,18446744073709029375LLU,13979173243358019583LLU,8214565509937496063LLU,18446216041839460350LLU,5764607523034177529LLU,18446605535244396542LLU,63932415LLU},{4611686017922498239LLU,8345170109517528832LLU,18446744073709551607LLU,18425351975479541759LLU,18446183322773094399LLU,18446744073709547535LLU,18230571222876356607LLU,18446743963978694415LLU,53739423LLU}};

static uint_fast64_t D[18][9] = {{9252941743494970558LLU,18446740559872589421LLU,18446744073709551615LLU,17813425307391098879LLU,1466849683067305469LLU,16964291707293522528LLU,18446744054277227946LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,3478388597353086975LLU,13453050870878304229LLU,11379076542569492479LLU,16980457346267585127LLU,2305842699618104735LLU,18446744038004210261LLU,18446744073709551615LLU,67108863LLU},{9193806975224236003LLU,17293817307456171410LLU,5615964163578435899LLU,18446744058315372635LLU,18446744073709551615LLU,17623353740507475967LLU,18446744060127739903LLU,18446744073709551615LLU,67108863LLU},{18446739428699896669LLU,16121285756446807039LLU,17824473112962363102LLU,7700986312852690852LLU,18446181118084212634LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18437736753927290879LLU,4398029864947LLU,18446726481523507200LLU,18446744073709551615LLU,18446673704965373951LLU,18419440859234696703LLU,15420325122103312383LLU,18428711734414764986LLU,67108863LLU},{18194416600470011903LLU,18446742896351641471LLU,18446744073709551615LLU,51405389823LLU,18446744073709551104LLU,864664740167688191LLU,18432136219887402944LLU,6982992273839489023LLU,67108862LLU},{17581067782835920896LLU,18446741462117777359LLU,9223372036854775807LLU,18446744071293600508LLU,11512167066739671551LLU,18338653834101914487LLU,13777608428836879423LLU,11481786512487210583LLU,67108861LLU},{3455386805945761791LLU,18446744073709486334LLU,13835075647468208127LLU,18446744073709551615LLU,9043221111015211007LLU,18442697843538919373LLU,7710162493336770559LLU,18446741700387190253LLU,67108863LLU},{14123288394926653343LLU,18428736272202464255LLU,18446207512035196927LLU,18446744039349807102LLU,18446181123756130815LLU,18446744073709551615LLU,18005602147696703LLU,18437736874454810368LLU,66956029LLU},{18446744073172688895LLU,1152921487679622966LLU,18163015089690509296LLU,9219005597005938627LLU,18446744073709551603LLU,17994101524833239039LLU,18442134069974663167LLU,9006354821229314047LLU,66224007LLU},{18428737646659368955LLU,18338657167256584191LLU,17292695810168774079LLU,18446708888322440831LLU,17294948469009547135LLU,18446743798831648767LLU,18444911187826049023LLU,14696331343252414719LLU,67097979LLU},{18446744073709551615LLU,17825185752481267711LLU,14122047503712909327LLU,18307084054507290623LLU,18320287042309193551LLU,4611686010101462495LLU,17365457914972333022LLU,17582050754821093887LLU,41941119LLU},{18446744073709551615LLU,13688128117439201279LLU,18354135505152376829LLU,16139984064281423871LLU,1152919312025771767LLU,17870283596284035056LLU,4604930618986332159LLU,4611686017571233776LLU,31358951LLU},{18446744073709551615LLU,8858369360805232639LLU,4611686018293663735LLU,4178213592220302336LLU,18151731909435012094LLU,16140901030050905919LLU,18446726618897432181LLU,18428857218547843039LLU,61597663LLU},{15334088098857286847LLU,18446744073692839921LLU,18446744073709551615LLU,17813425376110575615LLU,13177426234457391101LLU,18414776659905740026LLU,15420325122036166122LLU,18428711734414764986LLU,67108863LLU},{13853069155227398135LLU,18446740212525531135LLU,15996772609190247291LLU,18446744013562183135LLU,18446744073709551615LLU,576460752303423487LLU,18419356888329027584LLU,17712014101892300799LLU,66956028LLU},{18446744073709551615LLU,17861276104988294927LLU,18446743936404815871LLU,18446727581001581567LLU,18446320761732857795LLU,13294626099993474039LLU,18446198649370181599LLU,17329851366117212023LLU,41353135LLU},{18446739813101822961LLU,18445860083540688895LLU,18446726618961967359LLU,14915798751862849535LLU,18446744070454365759LLU,18446744073709551615LLU,18411278226644008959LLU,1152814302223138815LLU,31431164LLU}};

uint_fast8_t X[18] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[18][9] = {{9252941743494970558LLU,18446740559872589421LLU,18446744073709551615LLU,17813425307391098879LLU,1466849683067305469LLU,16964291707293522528LLU,18446744054277227946LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU}};

#if UINTPTR_MAX == 0xffffffffffffffff // 64-bit. Hopefully this means the cpu has 'popcnt'.
int counter (uint64_t * buf){
    uint64_t cnt[18];
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
            "popcnt %2, %2  \n\t"
            "add %2, %0     \n\t"
            "popcnt %3, %3  \n\t"
            "add %3, %1     \n\t"
            : "+r" (cnt[16]), "+r" (cnt[17])
            : "r" (buf[16]), "r" (buf[17]));


    return cnt[0] + cnt[1] + cnt[2] + cnt[3] + cnt[4] + cnt[5] + cnt[6] + cnt[7] + cnt[8] + cnt[9] + cnt[10] + cnt[11] + cnt[12] + cnt[13] + cnt[14] + cnt[15] + cnt[16] + cnt[17];
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

    }
}

void printout(){
    sprintf(str, "[                  ,%5d]\n", this);
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
    fputs("[[0,3],[0,4],[0,5],[0,7],[1,4],[1,5],[1,6],[1,8],[2,5],[2,6],[2,7],[3,6],[3,7],[3,8],[4,8],[5,7],[6,8],[7,8]]\n", fout);
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

