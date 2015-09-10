#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_561_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][6] = {{18446744073441116161LLU,4194303LLU,18446744073709547520LLU,17870283325701095423LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,63LLU,18446744073709547520LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,4095LLU,18446744069414584320LLU,18446744073709551615LLU,65535LLU},{18446744073441116160LLU,18446744073709551615LLU,6905531156758781951LLU,17870283323517425655LLU,18446744073709551615LLU,65535LLU},{268435455LLU,18446744073705357376LLU,18446744073709551615LLU,576460752303423487LLU,18446744073705357312LLU,65535LLU},{0LLU,18446744073709551552LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,15552607196247228415LLU,18446739675663043959LLU,18208925476762681343LLU,18446744004994269183LLU,65535LLU},{18446739676199911423LLU,18446744073709551615LLU,4398046511103LLU,576460748008456192LLU,18445618242522185472LLU,65535LLU},{4398046511103LLU,18446744073705357504LLU,18446739675663056895LLU,18446744073709551615LLU,18446744004990075135LLU,65535LLU},{17977806762509590529LLU,18446673704968402935LLU,18446744073709551615LLU,18446726485817684991LLU,18159551617441988607LLU,65535LLU},{18446717685162057727LLU,70368744176895LLU,18442258066268221440LLU,17870300910370947071LLU,287666395393556479LLU,65532LLU},{17282563553389051903LLU,4557642822898941948LLU,4137064333311LLU,571675677699342332LLU,12105667070997483519LLU,65474LLU},{18446528586476158915LLU,18446744069431361535LLU,18446744073708565503LLU,18158513564413853699LLU,18428738471293090048LLU,64575LLU},{18374690276414275583LLU,18442521949058859263LLU,18446744073441132531LLU,18428624122071219983LLU,8357555007960088796LLU,62143LLU},{72056491271519871LLU,18446743816007352256LLU,18176523698289246015LLU,14915921141016035327LLU,18383693610739597247LLU,53234LLU},{18158513681449476159LLU,4557572458449666045LLU,4503393468940287LLU,1148118975254885372LLU,18176432437481439231LLU,65475LLU},{18443357028139145711LLU,17293888813872967423LLU,14987715677085761535LLU,18444506529950334975LLU,14122582338739105759LLU,47855LLU},{9799815059265814391LLU,1152921452865519103LLU,18442521932952760320LLU,17872534829161975807LLU,4611650002970542071LLU,28536LLU},{18392630243002150899LLU,18446691296899743743LLU,4610841593295729648LLU,8908111241075949568LLU,9075812903214366192LLU,30527LLU},{18446599210904321999LLU,17365880159110954947LLU,18230356062193844223LLU,16139212107261476863LLU,16090305748450409231LLU,40191LLU},{18086737531251941887LLU,18443296280122656765LLU,288230169725894655LLU,4611599157008793404LLU,17652978040738121725LLU,62415LLU}};

static uint_fast64_t D[21][6] = {{14886147191507779583LLU,18446744073709551592LLU,17311819375426158591LLU,576460751283960844LLU,18446744073705357312LLU,65535LLU},{14886147191507779582LLU,18446744073709551592LLU,6527222923997650943LLU,18446744071186060966LLU,18446744073709551615LLU,65535LLU},{3560596882201772033LLU,7595983129966280791LLU,18446744073709549209LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073705357375LLU,17690127608187289599LLU,576460751623781725LLU,18446744073705357312LLU,65535LLU},{18446744073709551615LLU,10850760943743270911LLU,1134924698283395430LLU,17870283322425590771LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,10850760943743270847LLU,11919521149711903078LLU,18446744071938074969LLU,18446744073709551615LLU,65535LLU},{18446739675773783427LLU,9043051568701636479LLU,18446744073709549533LLU,576460752303423487LLU,18445618242522185472LLU,65535LLU},{3560596882627900029LLU,14105538757511872727LLU,18446744073709550643LLU,18208925476762681343LLU,18446744004994269183LLU,65535LLU},{18446744073551859075LLU,4341205316197679103LLU,1134924698283406284LLU,18108101919372461043LLU,18445618242522185727LLU,65535LLU},{14976686870560243711LLU,18446744073709550830LLU,18442241505885110271LLU,17870283317366964175LLU,287666395390987862LLU,65532LLU},{17887240695178067967LLU,18446744073708386289LLU,17311835935809273855LLU,1152921504404533308LLU,18159551617440362921LLU,65535LLU},{13654104829419044801LLU,17581208516030051287LLU,18446744073708564723LLU,17995222893549584383LLU,18429855518416697855LLU,64575LLU},{7188844516874154623LLU,1081973060102573308LLU,18446743812727373631LLU,18367431077317836799LLU,12105675786345959423LLU,65474LLU},{18446742970923875863LLU,4341469766779666431LLU,18159428491232149263LLU,14874544096050136063LLU,18383287271940947903LLU,53234LLU},{18446743472267267563LLU,18442257240778866687LLU,1152024303118578672LLU,18131359012700028675LLU,8356835584290848732LLU,62143LLU},{11528935065530122239LLU,17581208520321923279LLU,18446740762288730355LLU,17995223022654406607LLU,6628735662849652822LLU,64573LLU},{9241314751286345591LLU,18446744021968109567LLU,18392700861068148735LLU,8070450239988760828LLU,18273302703175908787LLU,28539LLU},{18442380346134624751LLU,18446739949734586353LLU,13907114618511425535LLU,11529211713157136191LLU,18332814860580545485LLU,47855LLU},{9219985538859203327LLU,17298322664033087168LLU,18230355804484009791LLU,16066729659353530367LLU,14951950565226311679LLU,40934LLU},{16361559845445265279LLU,1149477782648823295LLU,4610841590024372208LLU,9189511201887879164LLU,3891105401491333119LLU,30683LLU},{11529211609842188247LLU,17365880159715721167LLU,18443151956336701455LLU,17904623178387230719LLU,16131013530087194423LLU,52604LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][6] = {{14886147191507779583LLU,18446744073709551592LLU,17311819375426158591LLU,576460751283960844LLU,18446744073705357312LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,4],[3,6],[4,7],[5,8],[5,9],[6,8],[6,10],[7,11],[7,12],[8,11],[9,12],[9,13],[10,12],[10,13],[11,13]]\n", fout);
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
