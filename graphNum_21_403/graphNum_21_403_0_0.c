#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_403_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][4] = {{281474968322049LLU,18446744073441116160LLU,18446744069414585343LLU,70368744177663LLU},{70368744177663LLU,18446744073441116160LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,268435455LLU,18446744073709550592LLU,70368744177663LLU},{18446744073701163008LLU,18446744073172680703LLU,18446744069414585343LLU,70368744177663LLU},{18446532967485407231LLU,18446744073709551615LLU,18428729679495036927LLU,70368744177663LLU},{18446673704965373952LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446673704982151167LLU,1073741823LLU,18428729679495035904LLU,70368744177663LLU},{281474976710145LLU,18446744073709551615LLU,18014398509220863LLU,70368744177648LLU},{18446744073701163519LLU,18446744073441116160LLU,18446744069414846463LLU,70368743915535LLU},{18446744069431361535LLU,18446673706039115775LLU,18446742978492891135LLU,70368710790383LLU},{18446673709260341247LLU,70368744177663LLU,16140902164007484416LLU,70364482764799LLU},{1125895645429251LLU,18446673709260341247LLU,2305841918291740671LLU,70368710885360LLU},{4594797519824683251LLU,18446744073709535232LLU,18446744073676122111LLU,70304302102543LLU},{18446735251838402559LLU,18442521948790472703LLU,18444485672564686799LLU,69336777361407LLU},{18446743527309180927LLU,17293888608519847935LLU,9097131368793505791LLU,66451230687228LLU},{18446674254720136191LLU,1152921504594264003LLU,16267142591012142080LLU,57157961613215LLU},{18159636023817011139LLU,3746994619389313023LLU,1800524997144315900LLU,48339852984319LLU},{288230372124778047LLU,18446673979842297087LLU,18446743042711650303LLU,33878672658160LLU},{18433232758894432247LLU,17298322870195175487LLU,18338525603786911743LLU,67018266507389LLU},{18176525879655006159LLU,18443366116023599103LLU,4322888238709579772LLU,47553807400959LLU},{1152855530687690367LLU,18446678103011098575LLU,16700472493427457027LLU,26239003778995LLU}};

static uint_fast64_t D[21][4] = {{18446673704982151167LLU,1073741823LLU,18428729679495035904LLU,70368744177663LLU},{18446673704982151166LLU,12297829382294077439LLU,18446744073709551274LLU,70368744177663LLU},{12297782469960138753LLU,18446744073620073130LLU,18446744073709551615LLU,70368744177663LLU},{18446532967477018623LLU,6148914691952345087LLU,18428729679495036245LLU,70368744177663LLU},{6149102341220990975LLU,18446744072725288277LLU,18446744069414585343LLU,70368744177663LLU},{6149031972476813311LLU,6148914691504952661LLU,18446744073709550933LLU,70368744177663LLU},{281474968322049LLU,18446744073441116160LLU,18446744069414585343LLU,70368744177663LLU},{18446699311543615487LLU,14713541454374895615LLU,18435284959229902031LLU,70368743915535LLU},{18446718467148087295LLU,3733202620408397823LLU,11459118774615856LLU,70368744177648LLU},{18445899648774071293LLU,18446744073495580419LLU,16158915460266982399LLU,70364482764799LLU},{1125899903802371LLU,18446744073655087356LLU,18446744072152942591LLU,70368710790383LLU},{18446699311555044351LLU,14713541457382149891LLU,18435284960786513103LLU,70364482597663LLU},{18446728648938487807LLU,18442296566355066879LLU,3725031750070435776LLU,69336777621498LLU},{4594778516171521779LLU,3733428003112222719LLU,14730913045530142527LLU,70304302104565LLU},{1095500609356034155LLU,18446744073693036480LLU,18446744072767985663LLU,57161693208463LLU},{17352369363316744087LLU,18446739744331985151LLU,9223371795183120383LLU,66451727117564LLU},{18446700015934556159LLU,18391856453249940495LLU,18435465283189603535LLU,33875313018431LLU},{18446739795916848127LLU,68679894103478259LLU,17941245799161135100LLU,48338984336351LLU},{14933920970055090031LLU,18446730828013895679LLU,12966425984155705280LLU,56761204547579LLU},{4611633136105670399LLU,18379134004205976591LLU,17244255897720323135LLU,34056792178229LLU},{18217060063076368343LLU,17362502257010000895LLU,9151204454047920127LLU,49993080961535LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][4] = {{18446673704982151167LLU,1073741823LLU,18428729679495035904LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU}};

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

    } else {
        A[i][0] = A[i-1][0] & D[i][0];
        A[i][1] = A[i-1][1] & D[i][1];
        A[i][2] = A[i-1][2] & D[i][2];
        A[i][3] = A[i-1][3] & D[i][3];

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,3],[2,4],[3,5],[4,6],[4,7],[5,6],[5,8],[6,9],[7,10],[7,11],[8,10],[8,12],[9,11],[9,12],[10,13],[11,13],[12,13]]\n", fout);
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

