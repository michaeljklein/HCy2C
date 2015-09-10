#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_642_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][6] = {{4398046511043LLU,18446739946246045440LLU,18446744056529944575LLU,18446744072702918655LLU,18446743798831710207LLU,4193283LLU},{18446744073709551615LLU,255LLU,18446744073709486080LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,65535LLU,18446673704965373952LLU,18446744073709551615LLU,4194303LLU},{18446744073675997184LLU,18446744073709551615LLU,6878533061055479807LLU,34494985663989LLU,18446744073709551552LLU,4194303LLU},{33554431LLU,18446744069414584576LLU,18446744073709551615LLU,18446744073709551615LLU,18446744072635809855LLU,4194303LLU},{18446744073675997185LLU,4294967295LLU,18446744073709486080LLU,70368744177663LLU,18446744073709551552LLU,4194303LLU},{18157317428906819583LLU,17399648364252889055LLU,18158513697557897151LLU,16246735655739064319LLU,18446726482319769581LLU,4194303LLU},{18374686475443765247LLU,18446743944860532734LLU,288230376151711743LLU,18445618173802708992LLU,18158531289672577087LLU,4194303LLU},{18446739675689809023LLU,9213625965786104319LLU,18446744073709548517LLU,18446740762289754063LLU,190593743605137471LLU,4194300LLU},{0LLU,18446744073709551360LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{17289292581196259329LLU,18374686483125436403LLU,1152921504606846975LLU,18158531083585454076LLU,18266476873519202303LLU,4186795LLU},{13817043596609593343LLU,72057593966617599LLU,18446726550242918400LLU,288230376135983103LLU,14116531064897798080LLU,4136959LLU},{18157313035150819327LLU,17582052945254351839LLU,18158513714737706991LLU,16717358505379483599LLU,288213058566033407LLU,4194300LLU},{16638548685411581567LLU,18446480165113430014LLU,287122068217004031LLU,18433022168594644992LLU,4609451810710609471LLU,3996591LLU},{18446321857486274559LLU,1152921399379623743LLU,18446743030029352956LLU,2304928215539646463LLU,17296074368379253247LLU,3399159LLU},{18302632457972743155LLU,18443365549338574847LLU,18433233274760593407LLU,18410715018791223295LLU,18410710862529608703LLU,2881475LLU},{144115170760196047LLU,18446740770896475904LLU,18446744056596790815LLU,18446744072904244287LLU,18446461790213635961LLU,2014271LLU},{18446722152192008255LLU,17509999748725940215LLU,4323473234461718511LLU,16431383240461254652LLU,4611565002355056639LLU,4187132LLU},{18446744021733867135LLU,18446480165149075455LLU,18445672049872404483LLU,18433022168578916355LLU,1144053393573019200LLU,3948543LLU},{18446739947319615999LLU,3675218667831771135LLU,4324580511390367740LLU,2611172991274319868LLU,17311718220356334591LLU,3401724LLU},{18303191800927485687LLU,18446532400525602815LLU,18445886454576906751LLU,18437596136953611263LLU,6911335465749053127LLU,2981839LLU}};

static uint_fast64_t D[21][6] = {{18446744073702765695LLU,3732375654520324095LLU,4553192068549177824LLU,2777661299634455488LLU,190593743605202934LLU,4194300LLU},{15191550418397167614LLU,18446744073709551516LLU,6513723876146020351LLU,18446702680582235557LLU,18446744073709551615LLU,4194303LLU},{3255193655312384001LLU,7969498038920020323LLU,18446744073709527877LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744069414584575LLU,17717125703890632703LLU,18446733034971946847LLU,18446744072635809855LLU,4194303LLU},{18446744073709551615LLU,10477246034789531647LLU,1094427554728402106LLU,16558106407152LLU,18446744073709551552LLU,4194303LLU},{15191550418397167615LLU,18446744073709551516LLU,17352316518981173247LLU,18446727515603144463LLU,18446744072635809855LLU,4194303LLU},{7957570266212349053LLU,8060704325440568698LLU,18446744073709534069LLU,18445688542546886655LLU,18158531289672577087LLU,4194303LLU},{13382883219741068163LLU,17308441948883321799LLU,18446744073709537167LLU,16246735655739064319LLU,18446726482319769581LLU,4194303LLU},{18446744073709551555LLU,15958492222886772735LLU,14987979542709165759LLU,15669096019755072767LLU,18446743799905386441LLU,4193283LLU},{18446744073709551615LLU,10477246034789531391LLU,11933020197563555002LLU,18446715098092690010LLU,18446744073709551615LLU,4194303LLU},{11212626000649125887LLU,18446744073638241183LLU,18446726484959690751LLU,18446740762273189647LLU,14116531064047529087LLU,4136959LLU},{16638516521877897215LLU,18446744072868397040LLU,58494015161761791LLU,18446677844307214332LLU,18266476873295729599LLU,4186795LLU},{7957570270476091329LLU,14987975163542699898LLU,14987979559888961151LLU,16138666649652624639LLU,18256167922219089883LLU,4193283LLU},{13816513133822217179LLU,14634221594426127LLU,18446743030029352956LLU,108086391056891903LLU,17582039292895166463LLU,3399159LLU},{16276554153372941863LLU,18446465346921416695LLU,18445635765774829455LLU,18430981475013754879LLU,4611682078841888749LLU,3996591LLU},{18446744056393430911LLU,17856719668656470015LLU,18392485648779968000LLU,7993251896713280512LLU,12030873273555222392LLU,2015229LLU},{18446743247995762943LLU,4319022359852859391LLU,4593939694596649471LLU,13195124421913723903LLU,6570149323961514999LLU,2881534LLU},{2170312806970146815LLU,14987979557527093054LLU,18446744059965816447LLU,16140901063422131263LLU,18429574056536439899LLU,4136279LLU},{18446181395412806619LLU,18389320700531851009LLU,18217060476603596799LLU,18266533859212394495LLU,18266586684155507711LLU,3400947LLU},{562897984421863LLU,18446742424174716926LLU,18446744072639942175LLU,18446744073709304895LLU,18445334985000353353LLU,3948303LLU},{18446740773027112927LLU,17802727055226273537LLU,18176527255327473660LLU,7853644705509146620LLU,17654031167357155327LLU,1567997LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][6] = {{18446744073702765695LLU,3732375654520324095LLU,4553192068549177824LLU,2777661299634455488LLU,190593743605202934LLU,4194300LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,6],[3,7],[4,6],[4,8],[5,9],[5,10],[6,9],[7,10],[7,11],[8,12],[8,13],[9,11],[10,12],[11,13],[12,13]]\n", fout);
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
