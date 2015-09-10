#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_15_42_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 14;
static uint_fast32_t endhere = 0;
char str[25] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[15][5] = {{18302628885633695744LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{144115188075855871LLU,18446735277616529408LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,8796093022207LLU,18446744073172680704LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,536870911LLU,18446744073709289472LLU,1073741823LLU},{16285016252571713535LLU,13690808426139430783LLU,11502087878392414172LLU,18446744056529935611LLU,1073741823LLU},{18426462482223595264LLU,18444633011384221695LLU,18050426773918710003LLU,18446181140935930879LLU,1073741823LLU},{2305842854477365503LLU,18446743970600779774LLU,9221806882052636671LLU,562949953421278LLU,1073741823LLU},{18446339450335199231LLU,16935786397954996929LLU,18446744073709504511LLU,18446744073709551615LLU,1073676288LLU},{18409694929895668223LLU,9281918832010592255LLU,18442254759084683263LLU,14984038905517412351LLU,1072746488LLU},{18446743791045705657LLU,18446743111569760307LLU,17298326063503376383LLU,18446638400315850737LLU,1058012743LLU},{13250711545421228007LLU,9223055376421756927LLU,18446744073709485440LLU,18271098326506012671LLU,822083583LLU},{18446742974206312447LLU,18446620928407240703LLU,17852260123581104125LLU,17942340915377077759LLU,667910111LLU},{16285017352083341311LLU,18446744052503117823LLU,13832735598961491967LLU,18446728663434002367LLU,503118843LLU},{18446171296870955807LLU,11528009985619394559LLU,18446744073709419519LLU,18155716539649622015LLU,802422783LLU},{17158714575919456251LLU,18446744071545284606LLU,18446744073172942847LLU,576451872457490431LLU,524156927LLU}};

static uint_fast64_t D[15][5] = {{9079256848778919935LLU,13068866873566014807LLU,15914834669602340630LLU,18446744073709491938LLU,1073741823LLU},{18313639395060952574LLU,18352010151860371455LLU,16375060730406211305LLU,18446744073709349375LLU,1073741823LLU},{15852668573321002541LLU,18446742784745045931LLU,4603592747411046399LLU,18446744073709551389LLU,1073741823LLU},{12094667403967779795LLU,5472612410957222652LLU,18446744073709056511LLU,18446744073709551615LLU,1073741823LLU},{18446744073701163008LLU,17293822568838462463LLU,18157387797650981119LLU,6862006404857659359LLU,1073716461LLU},{143833712042180607LLU,18014398509481983936LLU,2305315243481333727LLU,12600508793336094718LLU,1073704862LLU},{18446605533096968191LLU,18374692801326087807LLU,18311636084888436735LLU,18446565660645912827LLU,1073738611LLU},{18426477720767561727LLU,13835057926432894975LLU,18446726482052513776LLU,17431151362289172479LLU,1073741823LLU},{18446739608016256993LLU,18446427414358655039LLU,18446743968482786815LLU,18302627803294072817LLU,913309311LLU},{13249730841174598143LLU,72057592955797503LLU,18446740766584733568LLU,18411273826584203263LLU,972476415LLU},{18410679817171746751LLU,18433232312687656947LLU,17293840161230024703LLU,14987874002460999679LLU,1067057088LLU},{18446744073709551615LLU,16671762866279284735LLU,18370743218351374263LLU,6898372236550322063LLU,503110137LLU},{9223372036854775807LLU,18446739057186568663LLU,17437643019342577791LLU,17905959690588422134LLU,667893455LLU},{18370112511298465791LLU,18392700878181105663LLU,1152921504137076623LLU,4584664410999488384LLU,478148671LLU},{18446743489050836847LLU,18446736376992104399LLU,18446744073709551615LLU,18446321036572754047LLU,603391999LLU}};

uint_fast8_t X[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[15][5] = {{9079256848778919935LLU,13068866873566014807LLU,15914834669602340630LLU,18446744073709491938LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU}};

#if UINTPTR_MAX == 0xffffffffffffffff // 64-bit. Hopefully this means the cpu has 'popcnt'.
int counter (uint64_t * buf){
    uint64_t cnt[15];
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
            "popcnt %2, %2  \n\t"
            "add %2, %0     \n\t"
            "popcnt %3, %3  \n\t"
            "add %3, %1     \n\t"
            : "+r" (cnt[12]), "+r" (cnt[13])
            : "r" (buf[12]), "r" (buf[13]));
    __asm__(
           "popcnt %1, %1  \n\t"
           "add %1, %0     \n\t"
            : "+r" (cnt[14])
            : "r" (buf[14]));


    return cnt[0] + cnt[1] + cnt[2] + cnt[3] + cnt[4] + cnt[5] + cnt[6] + cnt[7] + cnt[8] + cnt[9] + cnt[10] + cnt[11] + cnt[12] + cnt[13] + cnt[14];
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
    sprintf(str, "[               ,%5d]\n", this);
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
    fputs("[[0,3],[0,4],[0,5],[0,6],[1,3],[1,4],[1,5],[1,6],[2,4],[2,5],[2,6],[3,4],[3,5],[4,6],[5,6]]\n", fout);
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

