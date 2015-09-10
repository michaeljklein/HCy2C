#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_807_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][7] = {{13799029258263183361LLU,18446744073575333827LLU,18410715276690587679LLU,18446744039349813247LLU,18446742974265032691LLU,18446726482597249023LLU,1023LLU},{18446744073709551615LLU,268435455LLU,18410715276690587648LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,36028797018963967LLU,0LLU,18446744073642442752LLU,18446744073709551615LLU,1023LLU},{18446739675663040512LLU,18446744073709551615LLU,16212923473356390399LLU,16095724192756269055LLU,18437736874513504223LLU,18446744073709551615LLU,1023LLU},{4398046511103LLU,18446739675931475968LLU,18442240370935807999LLU,9223372028264841215LLU,9007199254740990LLU,18446744073709486080LLU,1023LLU},{18444492273895866367LLU,268337151LLU,18446744073709551584LLU,18446675354014699242LLU,7629097768762211711LLU,18446744072635853846LLU,1023LLU},{0LLU,18446744073441116160LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744072098938879LLU,18329509745909301119LLU,34339672280784955LLU,18446742974197923840LLU,18444366637042761727LLU,18442253652090420191LLU,1023LLU},{18445624736479084543LLU,13835058055269578751LLU,18446730877422534655LLU,1099511627775LLU,17302266749617438720LLU,17298324931173207935LLU,1023LLU},{18444487875849371647LLU,4398046412799LLU,16284981067394318304LLU,18446678102876610559LLU,18437737973964324863LLU,18446744072635875327LLU,1023LLU},{1095214571291LLU,18158452108263686142LLU,18424225956303323119LLU,9222527611924643839LLU,9007199254740799LLU,463870348764446704LLU,1023LLU},{18446743867014248447LLU,18446739692574474241LLU,2304506003070090878LLU,18230571283005831168LLU,18446744073709060094LLU,18446473556125483023LLU,1008LLU},{13785517772173475777LLU,18445669978488299506LLU,18446744073575333912LLU,18446744073709305759LLU,16138642659089580031LLU,17291183604830827519LLU,971LLU},{17293769779659653183LLU,11673330199784586703LLU,18410715276824805375LLU,13835128385640071167LLU,18391714624840925171LLU,13767486606124515325LLU,830LLU},{1125898831134591LLU,18374633687007100798LLU,18446743992105165311LLU,9222526512413018111LLU,1152851135460015935LLU,1148699092175813584LLU,1023LLU},{18436681343283691459LLU,18445899099013644279LLU,18446730877288325119LLU,4611686018427142047LLU,15060032679040778240LLU,16212957301323978751LLU,971LLU},{9223231299097993203LLU,18428734064656646142LLU,17987368115623751679LLU,14987965334822903807LLU,18302594180416778255LLU,7815997153293172727LLU,751LLU},{18228315094004004095LLU,18014138663845951LLU,7493811795694452704LLU,18433180498243092472LLU,9214399970432516095LLU,18437121146877902367LLU,444LLU},{9223231092404781047LLU,18428795911917289470LLU,18014398509481164542LLU,18446734444392871943LLU,18302595899210707198LLU,18300165977289982455LLU,739LLU},{18446708880495854583LLU,16700469985035681231LLU,18122487099561311999LLU,13853063657698621567LLU,18410406381568914423LLU,18248428457788641279LLU,630LLU},{288195191576711039LLU,18433195878295273438LLU,18122766293911201535LLU,14122442907025668223LLU,18410696859602386943LLU,4572125304439913456LLU,639LLU}};

static uint_fast64_t D[21][7] = {{8498984807287259135LLU,18446744073671681663LLU,7061644215716937727LLU,9223301934137460320LLU,7629097768761539646LLU,18446744072635853846LLU,1023LLU},{5014764400260448254LLU,18446744073595496061LLU,2377900603251621887LLU,6148960063402111797LLU,18446744073666860700LLU,18446744073709551615LLU,1023LLU},{13431979673449103361LLU,15252148223960963458LLU,18423765683178913740LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446739675931475967LLU,16132944867255849599LLU,4249987910530477258LLU,9007199236619646LLU,18446744073709486080LLU,1023LLU},{18446744073709551615LLU,3194595850131079167LLU,16167296764315364787LLU,14920148247088521215LLU,18437736874507207619LLU,18446744073709551615LLU,1023LLU},{10312557051422687232LLU,18446744073499049921LLU,13763000461244235775LLU,15372333448919612351LLU,18446742974223013841LLU,18446726482597249023LLU,1023LLU},{18446744073709551615LLU,3194595849862643711LLU,16091821860988567603LLU,12297784010307439818LLU,18446744073685133667LLU,18446744073709551615LLU,1023LLU},{18445619208830982531LLU,10663105993737433575LLU,18424210094450884591LLU,18446744073709551615LLU,17302266749684547583LLU,17298324931173207935LLU,1023LLU},{13431985199486592637LLU,18306865957692858138LLU,18444597341412384792LLU,18446744073709551615LLU,18444366637042761727LLU,18442253652090420191LLU,1023LLU},{10312557051422703615LLU,18446744073499049921LLU,11521258848828461695LLU,3526599915555731871LLU,10826653504148242416LLU,18446726482597204969LLU,1023LLU},{18446743867014248447LLU,8022459048718761983LLU,34074689971682874LLU,18162990908906141696LLU,18443016262146065399LLU,18446473556125548543LLU,1008LLU},{18446740770877611803LLU,13330588926319001599LLU,18419713662781287911LLU,14986884204848013311LLU,18441464686070202123LLU,463870348764446719LLU,1023LLU},{16573182807488036863LLU,11673330199746835711LLU,8358680908399640575LLU,13835059150506163838LLU,9159336479653101567LLU,13767504060227170108LLU,830LLU},{9206060293369167871LLU,18445669978622398334LLU,17149707381026848760LLU,9223371203630860161LLU,14553375598773910590LLU,17291183740766777559LLU,971LLU},{18446743807362855399LLU,572236875290309095LLU,18446463147943624702LLU,18162990908906143743LLU,18444760310993126391LLU,17987373578619703167LLU,1008LLU},{16210706841605760639LLU,16145367222695459871LLU,8356534176102481919LLU,18446744069421923966LLU,9222826387029622783LLU,13833206477637533596LLU,830LLU},{17023026049321006335LLU,18446743813864013825LLU,2304503821126073215LLU,18213682789740445688LLU,4017210816024444927LLU,18437113892669750797LLU,444LLU},{2296589519354322931LLU,18446744064909115390LLU,18412953871626274559LLU,287384856004671903LLU,15888698865008766976LLU,7815986817462653939LLU,751LLU},{17023022746491157535LLU,13330654894869184511LLU,18446741874694683111LLU,18428764821152595967LLU,4011933147179515899LLU,10938679509305524221LLU,447LLU},{18158791048291745759LLU,18374668746825387903LLU,17293822568976873953LLU,9223336852449134585LLU,281404603470708543LLU,14410639124446445279LLU,479LLU},{18445895267904323023LLU,2304997828368188407LLU,17293820919165222880LLU,18433180498269306873LLU,17573604257037291519LLU,17573010457541607039LLU,473LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][7] = {{8498984807287259135LLU,18446744073671681663LLU,7061644215716937727LLU,9223301934137460320LLU,7629097768761539646LLU,18446744072635853846LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,4],[1,5],[2,4],[2,6],[3,7],[3,8],[4,9],[5,7],[5,10],[6,8],[6,11],[7,12],[8,13],[9,10],[9,13],[10,11],[11,12],[12,13]]\n", fout);
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

