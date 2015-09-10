#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_459_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][5] = {{4611686017353646081LLU,18374686479671623680LLU,4503599627370495LLU,18446744073709420544LLU,17179869183LLU},{1152921504606846975LLU,18374686479671623680LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,72057594037927935LLU,18442240474082181120LLU,18446744073709551615LLU,17179869183LLU},{18446744072635809792LLU,18302628885633695743LLU,4503599627370495LLU,18446744073709420544LLU,17179869183LLU},{14987979560962752511LLU,18446744073709551615LLU,18446744073709551615LLU,18446673704965505023LLU,17179869183LLU},{17293822569102704640LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{17293822571250188287LLU,288230376151711743LLU,18442240474082181120LLU,18446673704965505023LLU,17179869183LLU},{4611686018427355137LLU,18446744073642442752LLU,4503599627370495LLU,18158584066302017532LLU,17179869183LLU},{18446744072635842559LLU,18374686479738732543LLU,18446744073709551615LLU,288230376151580675LLU,17179869120LLU},{18446708891484946431LLU,288230376151711743LLU,18446744073705357312LLU,18295873484045287423LLU,17179861038LLU},{17293857753474793471LLU,18446744073709551615LLU,18442240474086375423LLU,16716869237737521151LLU,17178828795LLU},{4034996292278025985LLU,18392684385506684928LLU,17871409221058166015LLU,18444527444292467199LLU,17163591679LLU},{18437736861435166975LLU,1149543787706454015LLU,576459927669702655LLU,18160764947614908352LLU,16928208703LLU},{18302060438117966847LLU,18446742974260903935LLU,2305631899759726591LLU,9511593582218182147LLU,16273602559LLU},{4575657117259661281LLU,18374687579183251392LLU,18379176885159460803LLU,9223369837825098239LLU,13955488960LLU},{18375812244152778751LLU,284852676431183871LLU,18446726485818474432LLU,18219307963192033279LLU,13807647780LLU},{18446568289276522303LLU,18446729848774717695LLU,8791026472421687359LLU,11523022585851804287LLU,16361972735LLU},{18442273527613620223LLU,18392700878181105663LLU,18446744004994252815LLU,15563736351890145279LLU,12610052059LLU},{17298326164401486331LLU,14987768452850925564LLU,14974468829726375935LLU,17266449402495234039LLU,7464943613LLU},{18433513091946350591LLU,4611686002254413823LLU,4611685125342610431LLU,18193837999579987916LLU,12415041407LLU},{18443366304262496231LLU,18374967938479292355LLU,18392700813756596175LLU,18230571085433020364LLU,10601028931LLU}};

static uint_fast64_t D[21][5] = {{17293822571250188287LLU,288230376151711743LLU,18442240474082181120LLU,18446673704965505023LLU,17179869183LLU},{17293822571250188286LLU,12249790986447749119LLU,18445242873833761450LLU,18446744073709551615LLU,17179869183LLU},{11529215043920986113LLU,18422724875696908970LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{14987979559889010687LLU,6341068275337658367LLU,18443741673957971285LLU,18446673704965505023LLU,17179869183LLU},{9223372036854775807LLU,18182532895570482517LLU,4503599627370495LLU,18446744073709420544LLU,17179869183LLU},{8070450532247928831LLU,6220972285274445141LLU,18443741673957971285LLU,18446744073709551615LLU,17179869183LLU},{4611686017353646081LLU,18374686479671623680LLU,4503599627370495LLU,18446744073709420544LLU,17179869183LLU},{17972127542286483455LLU,17582052945254416383LLU,18445675126129217283LLU,288201407857557503LLU,17179869120LLU},{17768439102673256447LLU,1152921504606846975LLU,18443309421662515452LLU,18158542665852125183LLU,17179869183LLU},{18446744073067090387LLU,18391641992903802672LLU,10277214349659471871LLU,16716939604334136742LLU,17178828795LLU},{4611686017996107309LLU,18429788560477372623LLU,8174033323677450239LLU,18295873486192587353LLU,17179861038LLU},{18287423724166086655LLU,284852659318423551LLU,18446531920578531327LLU,18158503973415403459LLU,16928208676LLU},{17545750953406234623LLU,18392684385506689023LLU,18442508754651184131LLU,576405760047512063LLU,17163591643LLU},{3978841914714619873LLU,18446744073709551552LLU,18375795835310963904LLU,18219203298044411903LLU,13955489023LLU},{18220570670700422143LLU,1152921504602718207LLU,2305578297561187327LLU,18386072411699412991LLU,16273602559LLU},{18446603335668065055LLU,18392683303170797631LLU,1801439850746871807LLU,9797721718242867263LLU,16361144319LLU},{18375812379343379955LLU,18442310838787194864LLU,17266783383447404543LLU,18365674951089819622LLU,13807443953LLU},{4611686013945673849LLU,14984337151737201660LLU,14109777632551763967LLU,18412967076503987955LLU,7465854652LLU},{18446741942590746543LLU,18379176666062650575LLU,9043228051759939599LLU,15996222926336457565LLU,12610173263LLU},{3710939670249471865LLU,18446462873610744828LLU,18140767579881603059LLU,3458709536626434303LLU,7506226940LLU},{17365706436006378367LLU,14987978735255090175LLU,15848184680697315327LLU,12658145196353781503LLU,8010328063LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][5] = {{17293822571250188287LLU,288230376151711743LLU,18442240474082181120LLU,18446673704965505023LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,3],[2,4],[3,5],[4,6],[4,7],[5,8],[5,9],[6,10],[6,11],[7,10],[7,12],[8,10],[8,13],[9,11],[9,13],[11,12],[12,13]]\n", fout);
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

