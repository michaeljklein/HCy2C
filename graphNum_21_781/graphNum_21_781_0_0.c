#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_781_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][6] = {{18446744073709486081LLU,2305843009213692383LLU,18444492273895866368LLU,18446741874686296063LLU,18446744071562131455LLU,18446744005006852095LLU},{18446744073709551615LLU,4194303LLU,18444492273895866368LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,2251799813685247LLU,0LLU,18446744073709486080LLU,18446744073709551615LLU},{18446735277616529408LLU,18446744073709551615LLU,17298308576543899647LLU,18320185844356349951LLU,18446673704965431167LLU,18446744073709551615LLU},{8796093022207LLU,18446744071566262272LLU,18446461498977940399LLU,18446743523953737727LLU,70368744177151LLU,18446744073709547520LLU},{18446744073709551615LLU,16140901064499986429LLU,16140901064495857663LLU,12681001853726848983LLU,14786373107819970547LLU,18446744073692777004LLU},{0LLU,18446744073705357312LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446742974193729535LLU,4299739996803301375LLU,1125476850458622LLU,18446744073642442752LLU,18446718455114039295LLU,18446735341986504703LLU},{17870300910303838207LLU,18446744073709551615LLU,18446673704964849663LLU,67108863LLU,16140971433239969792LLU,18445626952178565119LLU},{18446735277616594943LLU,16140901066643275773LLU,17302812176171270143LLU,18338376206870642687LLU,18446673707112857591LLU,18446744073692778495LLU},{576459652787601407LLU,9223372034719875072LLU,1152921229527611390LLU,18446743523886628864LLU,2305843009213693439LLU,18446735341986500608LLU},{18374686445309918977LLU,2299087061996531155LLU,18446744073692774400LLU,18446744073709551423LLU,18158511466314004239LLU,18429573410804727803LLU},{16122780700553183487LLU,18311636084351171583LLU,4609434218630479871LLU,9223369564024209407LLU,13762565052500541438LLU,18176499442193006079LLU},{1150687287223246847LLU,18446737476639768575LLU,1062770896978051071LLU,18437736874521722864LLU,2296906109715218431LLU,17491848985541164926LLU},{17872528522002298867LLU,16717361791026331647LLU,17870283269865995777LLU,9007199191826431LLU,16149873075015974912LLU,14983616697003144191LLU},{9218586961713889231LLU,18446603337965930495LLU,18383693678926172159LLU,16680985573837258739LLU,18427603227683323903LLU,13541161345956581182LLU},{18158504902001684727LLU,16141041801917103933LLU,17365862502503546495LLU,18374686466249847807LLU,17293752749988188151LLU,6862913811171639279LLU},{574770738505973119LLU,9214927375119154944LLU,936748719188998143LLU,18438299274652413952LLU,2299084294036914175LLU,8619889204654505952LLU},{18412896707353214975LLU,18446638518575825151LLU,18408603939353133030LLU,144114981850320895LLU,18311354333960076798LLU,12536887177599963167LLU},{4537517362045771535LLU,18446736961243709431LLU,18446665458611388927LLU,18437737149332717360LLU,8926697316636161807LLU,17568155090630475770LLU},{18446673292113678287LLU,18311495896350235647LLU,18390449147086704639LLU,18446688840161492991LLU,18446448887182393343LLU,13330598757499019135LLU}};

static uint_fast64_t D[21][6] = {{7731812947596345343LLU,18446744073708386236LLU,13844065254536904703LLU,9689762328348734403LLU,14786373107819953649LLU,18446744073692777004LLU},{576472749006847998LLU,18446744073706223270LLU,6922032627268452351LLU,15144578970099030377LLU,18446744073709525340LLU,18446744073709551615LLU},{17870271324702703617LLU,14759645401790466393LLU,18445841265433600683LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,9223372034711486463LLU,11528720540449108358LLU,3311261935343068822LLU,70368744144107LLU,18446744073709547520LLU},{18446744073709551615LLU,12910470708781383679LLU,17294919716080230269LLU,18311088462867988479LLU,18446673704965424951LLU,18446744073709551615LLU},{11291403875119988736LLU,18446744073707321543LLU,9218868437227405311LLU,18135816296453889405LLU,18446744071562122078LLU,18446744005006852095LLU},{18446744073709551615LLU,3687098671922413567LLU,11525614254717050196LLU,3302165103610521238LLU,18446744073709512355LLU,18446744073709551615LLU},{17870289639721637523LLU,17221461423947775999LLU,18446351513119062699LLU,18446744073709551615LLU,16140971433240035327LLU,18445626952178565119LLU},{17870281495769082221LLU,1837923974645991769LLU,18445037134316161022LLU,18446744073709551615LLU,18446718455114039295LLU,18446735341986504703LLU},{11291403875120054271LLU,9223372036852545735LLU,4611191512808026502LLU,8784266740584401980LLU,3660441334633722062LLU,18446744005006849491LLU},{18446741595932038803LLU,16608820099079471103LLU,18446605482898505337LLU,18311088462867988479LLU,18446699323560937271LLU,18445626952178565119LLU},{14672603949756841983LLU,18311636084351057855LLU,738590338888761343LLU,2233785140360836095LLU,10267701375055904254LLU,18176499508762123375LLU},{9109932069993119743LLU,18439988126491338736LLU,17717160934075531263LLU,16679348951035363075LLU,17993004180016463617LLU,18429573412921535416LLU},{18446735792743740401LLU,137254201993981273LLU,17868576814801092096LLU,18446744073646637055LLU,18446688815632941055LLU,14984596499785053183LLU},{576460601947049327LLU,18418024966608559103LLU,1062840781394266111LLU,18446744073709354992LLU,2305837390972321791LLU,17491977572567195518LLU},{15689380017479872759LLU,9223372036785438479LLU,4611685949711580703LLU,9216616621254111487LLU,12028973867092082942LLU,6862913807279191527LLU},{4532380443739160527LLU,18446744073306865911LLU,18446249568354894310LLU,16284945952546754352LLU,8906149738100293583LLU,13541161281163099930LLU},{18412894233355302875LLU,16609143458577252351LLU,18408472221430267873LLU,8951965706878975LLU,18311310211155886078LLU,12536701897039314943LLU},{18445055155648322615LLU,18437870499477323775LLU,18230564690482757247LLU,18437807229777215487LLU,18439984731188348727LLU,8618966095407218687LLU},{18131483372013188095LLU,16149802708952448829LLU,17544317641630416895LLU,2233785415108916223LLU,17185669931295784446LLU,14807828702831759599LLU},{17904617717319598071LLU,9216616637309910784LLU,17726168133317164575LLU,18438299274589499407LLU,16278258654107074561LLU,6905425189550158817LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][6] = {{7731812947596345343LLU,18446744073708386236LLU,13844065254536904703LLU,9689762328348734403LLU,14786373107819953649LLU,18446744073692777004LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,4],[1,5],[2,4],[2,6],[3,5],[3,7],[4,8],[5,9],[6,10],[6,11],[7,10],[7,12],[8,11],[8,13],[9,12],[9,13],[10,13],[11,12]]\n", fout);
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

