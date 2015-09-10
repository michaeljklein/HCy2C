#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_728_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][6] = {{18446744073675997185LLU,1073741823LLU,18446744073709486080LLU,4398046511103LLU,18446744073709551600LLU,262143LLU},{18446744073709551615LLU,255LLU,18446744073709486080LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,65535LLU,18446739675663040512LLU,18446744073709551615LLU,262143LLU},{18446744073675997184LLU,18446744073709551615LLU,17689952244851408895LLU,2153925440895LLU,18446744073709551600LLU,262143LLU},{33554431LLU,18446744072635810048LLU,18446744073709551615LLU,18446744073709551615LLU,18446744072635809807LLU,262143LLU},{0LLU,18446744073709551360LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{2297222838051930111LLU,17977806762509598718LLU,18158513697557905395LLU,14731274381128892415LLU,18446726482470387711LLU,262143LLU},{18446740774168035327LLU,18446532935264763903LLU,288230376151704831LLU,9219923968390070272LLU,18158531289743877896LLU,262143LLU},{18446462598766146559LLU,5753348523964760575LLU,1152921504606846974LLU,18446744073442164720LLU,272344632153538575LLU,262140LLU},{281474949971763LLU,18446717478199361280LLU,18442521948991995807LLU,18446744073709551615LLU,18446739946246045695LLU,261123LLU},{18392692082088075265LLU,18374686480537616371LLU,18446744073709551615LLU,18374690861612006463LLU,18383201097717121023LLU,258867LLU},{18446743654916694015LLU,72057594037875711LLU,18446674800450404352LLU,72057594037927935LLU,3746993846295199728LLU,249855LLU},{11527526196183039939LLU,18266032774974537727LLU,18446743798831652859LLU,17180736695452892991LLU,18446744006038454263LLU,244123LLU},{9072325459831685119LLU,18158513697557824478LLU,864691403333042167LLU,15996785670245830655LLU,14123270907595275519LLU,225279LLU},{18446742973996547071LLU,14408070182922616831LLU,234183829743466239LLU,8924854629913329664LLU,12391671966895962061LLU,196606LLU},{17302827568528883711LLU,18446603310419935231LLU,18445899648775482879LLU,18444435099291484159LLU,18160765497364180794LLU,131011LLU},{11527244789950808015LLU,16140896941326221311LLU,18446743798898753534LLU,18446321860992827376LLU,4598069601979073535LLU,244732LLU},{1152920404876066679LLU,18446726338749398784LLU,18443366373926076351LLU,18446735277616267279LLU,18444630259392313295LLU,195647LLU},{18406211616933666879LLU,18086460501427998710LLU,4323526011019853815LLU,15925291219438009599LLU,14951652795151285759LLU,227191LLU},{18446479720619442639LLU,277351807255551LLU,18176511341668335600LLU,13839139442444468223LLU,288216911429189631LLU,262140LLU},{17365880162436513791LLU,18446744051404242703LLU,18446691297097875471LLU,4611637657095373823LLU,18228881616290185040LLU,249039LLU}};

static uint_fast64_t D[21][6] = {{1855862298598440959LLU,18446744073709551516LLU,1135187743287279615LLU,18446743041844645824LLU,18446744072635809807LLU,262143LLU},{1855862298598440958LLU,18446744073709551516LLU,11919433468043984895LLU,18446741485633512810LLU,18446744073709551615LLU,262143LLU},{16590881775111110657LLU,5662930801583456611LLU,18446744073709501212LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744072635810047LLU,6905706520094703615LLU,18446743385799614421LLU,18446744072635809807LLU,262143LLU},{18446744073709551615LLU,12783813272126095359LLU,17311556330422322403LLU,1031864905791LLU,18446744073709551600LLU,262143LLU},{18446744073709551615LLU,12783813272126095103LLU,6527310605665617123LLU,18446742263739079317LLU,18446744073709551615LLU,262143LLU},{17744169886409306877LLU,5753102199036902755LLU,18446744073709543550LLU,9219928366436581375LLU,18158531289743877896LLU,262143LLU},{1143931427212217603LLU,17887424226611364862LLU,18446744073709502353LLU,14731274381128892415LLU,18446726482470387711LLU,262143LLU},{18446744073682812723LLU,17977775714191015935LLU,18442258066201124739LLU,10118907697357975615LLU,18446739947319721975LLU,261123LLU},{18446744073709302783LLU,559359487463391231LLU,17997644110488830LLU,8327837407949094896LLU,272344632153604088LLU,262140LLU},{6482192302562344959LLU,18446744073709499295LLU,14987909461741404159LLU,18446743042863861756LLU,3746993845441280607LLU,249855LLU},{13766361659364868095LLU,18446744073501802480LLU,4593953081996345343LLU,18446744056584207363LLU,18383201097497298351LLU,258867LLU},{18194542425888699135LLU,8058945242159628743LLU,1152921504606846079LLU,9219994130960076799LLU,14012088223176588302LLU,225279LLU},{17852256278483402689LLU,16140896666900037499LLU,18446744073709487102LLU,18446182220046335807LLU,18269731497730631665LLU,244123LLU},{17293892624305090459LLU,18392689814312278015LLU,18445899648775471057LLU,14951950762870046719LLU,18446733721756270591LLU,131011LLU},{1152868571264522599LLU,13902874970376875006LLU,18392697527301275583LLU,17928689379073589247LLU,12393898935230382079LLU,196606LLU},{18194542494573133375LLU,18158236598737567687LLU,18442258066268224519LLU,2157742920415822079LLU,18337809134283390974LLU,224871LLU},{18446532653943941087LLU,4543987979403089919LLU,18230557888076574192LLU,14354924744812527615LLU,6325296700160180218LLU,131069LLU},{15275642656059654143LLU,16140901063942094655LLU,18446744069428151294LLU,18446739950490370044LLU,4461906133010801489LLU,237023LLU},{17302826468815929343LLU,18446744051196624641LLU,18442521948992045055LLU,18446695695466102799LLU,18174417032795121423LLU,261123LLU},{13829151418688201167LLU,18374963831478800382LLU,4327958971320107007LLU,18378767866620018675LLU,14978888746126351871LLU,259068LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][6] = {{1855862298598440959LLU,18446744073709551516LLU,1135187743287279615LLU,18446743041844645824LLU,18446744072635809807LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,6],[3,7],[4,8],[4,9],[5,10],[5,11],[6,8],[6,10],[7,9],[7,12],[8,13],[9,12],[10,13],[11,12],[11,13]]\n", fout);
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
