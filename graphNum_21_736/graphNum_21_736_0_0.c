#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_736_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][6] = {{18446744073709551615LLU,18446744073709551615LLU,68719476735LLU,0LLU,18446744073709486080LLU,4611686018427387903LLU},{18446744073709551615LLU,262143LLU,18446744004990074880LLU,18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{0LLU,18446744073709289472LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073441116160LLU,18446744073709551615LLU,8499981209269436415LLU,17858980158765365119LLU,18446735277616586077LLU,4611686018427387903LLU},{268435455LLU,18446673704965636096LLU,18446744073709551615LLU,18446744073709551615LLU,8796093022207LLU,4611686018427387840LLU},{18446744073441116161LLU,70368744177663LLU,18446744004990074880LLU,18446744073709551615LLU,18446735277616594943LLU,4611686018427387903LLU},{16140887870356324351LLU,18444633011384188927LLU,68693786559LLU,18446744073642442752LLU,17863527698088919039LLU,4611686018426339375LLU},{18442240466029117439LLU,14987979559889010589LLU,18446744065119584255LLU,67108863LLU,6845337288839200768LLU,4611686001248567294LLU},{18410715276950510063LLU,18374686477524664319LLU,18446744073441100775LLU,18446532967477018608LLU,18158522493650859007LLU,4611683830106791935LLU},{36028796968632187LLU,9218798070630449152LLU,18446673976622055423LLU,18176527271430455295LLU,288230376151711743LLU,4611406742067084288LLU},{17364191296100491265LLU,68137104964607LLU,18230571291595767296LLU,18446744073709551423LLU,18446744071562133263LLU,4607456743595653055LLU},{18446708614191128575LLU,18446730879532257279LLU,18445899580059943423LLU,18446744005258264575LLU,18446735279764013052LLU,4544061483457838847LLU},{17870283321405865599LLU,4323030114095822975LLU,13835058123925422012LLU,18446726547021758463LLU,18446743703595569103LLU,4389835358267760681LLU},{16140885679788769279LLU,18427040550446170099LLU,4611685966871001087LLU,288230324544995328LLU,13249726305724003324LLU,3710684497716453375LLU},{4606918465666613247LLU,18446744004889411293LLU,18428796736316104703LLU,18442240474149289212LLU,5665217444319330303LLU,3364179713102708733LLU},{18302627779678568387LLU,14413735418732019647LLU,18446691297148239871LLU,4503599560523583LLU,18445512581965611008LLU,1728394809703399390LLU},{17834256723410057983LLU,18446459280887347327LLU,13835128424026197996LLU,18446516474802601968LLU,18160765497237176319LLU,4389881675194926057LLU},{35883531561330559LLU,9222245589336457200LLU,18433229151658835487LLU,14929713415073034255LLU,9490896408421072895LLU,3167967877328174911LLU},{18412931887784919003LLU,18009825089221820431LLU,14987913585965940735LLU,18230571288374542335LLU,9007128821563854847LLU,2147970722786438336LLU},{8357343901173866559LLU,576460657478598655LLU,18213682783899868672LLU,18442240542801657855LLU,18428709057226342159LLU,3383315197815947263LLU},{1152921126383380351LLU,9222232427406020592LLU,18446740706459385375LLU,18443366309564313855LLU,9799542585196806143LLU,3116394185037119103LLU}};

static uint_fast64_t D[21][6] = {{6967522944645857281LLU,8417086966067530598LLU,18446744031524913862LLU,18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{11479221129063694334LLU,18446744073709384857LLU,7324447973159469055LLU,12003947425000941162LLU,18446744073709525337LLU,4611686018427387903LLU},{18446744073709551615LLU,10029657107642187775LLU,11122296142734720313LLU,6442796648708610453LLU,18446744073709512358LLU,4611686018427387903LLU},{18446744073709551615LLU,18446673704965636095LLU,16095677601489616895LLU,6736678606180703701LLU,8796092987383LLU,4611686018427387840LLU},{18446744073709551615LLU,10029657107642449919LLU,3526599750514539833LLU,17565098201293271871LLU,18446735277616581644LLU,4611686018427387903LLU},{11479221129063694335LLU,18446744073709384857LLU,14920144365379649535LLU,881645872416279744LLU,8796092969971LLU,4611686018427387840LLU},{8783039611743817091LLU,14181790476418867084LLU,18446744059446762231LLU,18446744073709551615LLU,6845337288839266303LLU,4611686001248567294LLU},{14320867595577930365LLU,9221164987212311415LLU,18446744037172045710LLU,18446744073709551615LLU,17863527698088919039LLU,4611686018426339375LLU},{18446744073659219835LLU,3162512100832575487LLU,18446673769849585471LLU,18159638550562272063LLU,18446742564471492559LLU,4611406742067084351LLU},{18446744073701038575LLU,16013955849999351807LLU,3526599957018558945LLU,17581775815928922096LLU,18446736786854637628LLU,4611683830106791935LLU},{11515642188667027455LLU,18446730879532254937LLU,14986907536051929087LLU,4395513167660977404LLU,345853581540144124LLU,4544061483457838837LLU},{17327734777247170559LLU,18446741842070174143LLU,18162963695993356287LLU,14932876710013566723LLU,18100899288262377219LLU,4607456743595653002LLU},{18302626686668082663LLU,18347620484814135280LLU,18446744009014506231LLU,288230324612104191LLU,11526965445275939836LLU,3710684490628071423LLU},{8350694055914044955LLU,139607644762535951LLU,18446744072534892540LLU,18446726547021758463LLU,9151314154793979855LLU,4389835348178370552LLU},{18211992276516192193LLU,17870298432030915575LLU,18446691260640262143LLU,18446744073642704703LLU,18445618122246389759LLU,1728394826748470671LLU},{576181098377802367LLU,9223366418913816191LLU,18428796744876543886LLU,18446744073709550844LLU,16683302313288269823LLU,3364179713235409533LLU},{18302628885380984819LLU,17258875274913570800LLU,18446744005523766911LLU,1125835478201151LLU,11529207309738180604LLU,3710453719515529215LLU},{18412931887835127759LLU,15600187632590520319LLU,14122444006499549693LLU,18446730875493105663LLU,18230500856099045628LLU,2148215669337747455LLU},{18446598808243528191LLU,18427040825336659967LLU,4378624711521730051LLU,14118802372452937728LLU,18426030784588807999LLU,3168000018816573439LLU},{16113868604589981695LLU,18446677827047393267LLU,14987913552680187903LLU,4395513236246499327LLU,13108219245131412476LLU,1684135051323894983LLU},{18410995645713219535LLU,15600185433198000575LLU,13853019677233512445LLU,18446516474739687411LLU,18193311041373143043LLU,2160037237184505802LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][6] = {{6967522944645857281LLU,8417086966067530598LLU,18446744031524913862LLU,18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,6],[3,7],[4,8],[4,9],[5,10],[5,11],[6,8],[6,12],[7,10],[7,13],[8,13],[9,11],[9,12],[10,12],[11,13]]\n", fout);
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
