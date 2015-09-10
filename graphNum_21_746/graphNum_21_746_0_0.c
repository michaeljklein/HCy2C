#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_746_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][6] = {{281474976677889LLU,1152921504472633344LLU,18446744073692774400LLU,18446744073709551615LLU,18446673709260079119LLU,4095LLU},{18446744073709551615LLU,4095LLU,18446744073692774400LLU,18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,16777215LLU,18442240474082181120LLU,18446744073709551615LLU,4095LLU},{18446743798831644672LLU,17296074368916389887LLU,18293021206464430079LLU,4466207639985663LLU,18446744073709551608LLU,4095LLU},{274877906943LLU,18446744073575337984LLU,16140901064462303231LLU,18446180985746620381LLU,18446744073709289479LLU,4095LLU},{18446463148488654847LLU,18445618173802713087LLU,17831852604729065471LLU,18446594505760012287LLU,18446744069414846455LLU,4095LLU},{18446744073709518849LLU,1125899906842623LLU,9223372036703780864LLU,18439988122230456183LLU,18446673709260341247LLU,4095LLU},{17725605183376850943LLU,16140901064495855573LLU,18374686479679840095LLU,18446744073709551615LLU,18428756952537205999LLU,4095LLU},{18446744073701228543LLU,18446744039618248703LLU,72057594037927935LLU,17298326168730075136LLU,13853072453758353407LLU,4095LLU},{18446462873610780671LLU,17294948469143764991LLU,18446744073709551615LLU,9007199254740991LLU,18446744069414846456LLU,4095LLU},{0LLU,18446744073709547520LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446463423374950399LLU,17297200303182970879LLU,18374686479940059135LLU,1152921504606846975LLU,18428800039682834424LLU,4095LLU},{18446744039215132671LLU,18446602784569556799LLU,67835404961972223LLU,16077850669711622144LLU,4341461243549417469LLU,4092LLU},{18429855572951564275LLU,4611677190122061823LLU,18446727581035134972LLU,8138004526659534847LLU,14123288405364178847LLU,4035LLU},{13835195356746350337LLU,562386797308420095LLU,18446744073709550592LLU,18446744073457893375LLU,18149294846609717263LLU,3883LLU},{4611650825465331967LLU,18302593701128433664LLU,1152921504590070783LLU,18442521949058891760LLU,2249478194882938879LLU,3327LLU},{18230554797853769695LLU,18379185706485284863LLU,18446742974466359247LLU,10070032274126008575LLU,18445688473583615743LLU,2990LLU},{18446479917113670143LLU,17364758656979042288LLU,18374687579183190015LLU,9079256784354410495LLU,13818166254113902584LLU,1783LLU},{13853070254734438159LLU,18437736735387483967LLU,18446744073708764163LLU,18392700877928398863LLU,17942190866464995455LLU,3900LLU},{14984460914372378491LLU,4034372037584076799LLU,18379173586624576767LLU,8971170389002555391LLU,17428930272032717787LLU,1907LLU},{18433224477922795511LLU,18410711952285200639LLU,18446743042901671932LLU,12965863395919134704LLU,14951335019019042751LLU,2511LLU}};

static uint_fast64_t D[21][6] = {{18446743963500085247LLU,18446292655735308287LLU,17293822569371140095LLU,8726759349354751LLU,18446744069414846456LLU,4095LLU},{6149101956133617662LLU,18446744073709548885LLU,11068046444232441855LLU,18444942633858603417LLU,18446744073709551615LLU,4095LLU},{12297642117575933953LLU,11530792363949562538LLU,18446744073703959210LLU,18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,6917529027506868223LLU,14373088090847008085LLU,18445749873815615436LLU,18446744073709289479LLU,4095LLU},{18446744073709551615LLU,17294497051035303935LLU,8992787735852875775LLU,2195159794568311LLU,18446744073709551608LLU,4095LLU},{6149102341220958208LLU,18446744073709548885LLU,4457963150980939775LLU,18438824554317208883LLU,18446673709260341247LLU,4095LLU},{18446462763401281535LLU,18446744073709551615LLU,15218563860991574015LLU,18445956633822311389LLU,18446744069414846455LLU,4095LLU},{12658492102867439203LLU,13832806221190938303LLU,18446744073708239610LLU,17302829768357445631LLU,13853072453758353407LLU,4095LLU},{17364755198077022621LLU,13838887173163176896LLU,18446744073696710415LLU,18446744073709551615LLU,18428756952537205999LLU,4095LLU},{6149102341220990975LLU,6917529027641079125LLU,1152921504344003925LLU,18442520913987567360LLU,18446673709260079119LLU,4095LLU},{18446744073709551615LLU,6915951709759991807LLU,7378697629482702165LLU,18444041913933129318LLU,18446744073709551615LLU,4095LLU},{1081989810475748963LLU,4611686018375367743LLU,1152921504602910960LLU,18442520913987567360LLU,13853045180749214495LLU,4095LLU},{18428842783952322033LLU,463293449225835516LLU,18446727581022539772LLU,9223372036854775807LLU,18435941341633310607LLU,4035LLU},{17365767952590168991LLU,17987129659010711299LLU,18442521884633349903LLU,16140901064495857663LLU,4604492806059138301LLU,4092LLU},{18446708841416425471LLU,18302432601064865791LLU,67570491379941375LLU,10795145834568613872LLU,2249548012038389756LLU,3327LLU},{18446599829318664191LLU,17855919048634662911LLU,18379173582598045695LLU,7656102873587974399LLU,18149295389609033723LLU,3883LLU},{1149543804885268603LLU,4611686014124539888LLU,1152921504606781695LLU,18298406692531011583LLU,10790620575416959967LLU,1783LLU},{18163017297182969799LLU,18446744064532184127LLU,18446744073705619392LLU,18140481775330127872LLU,16897479293346938431LLU,2990LLU},{18446682484141702655LLU,18194473203800208380LLU,18446462667439722495LLU,3886624006182273023LLU,16136924129977561086LLU,3287LLU},{18230522903487547359LLU,18248546382438592527LLU,18446742978476179407LLU,11529215046068469744LLU,9184180975473278719LLU,2558LLU},{14123074868446231359LLU,17571990076319334387LLU,18374967954648284223LLU,18410715276689543167LLU,13677288716273441273LLU,1917LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][6] = {{18446743963500085247LLU,18446292655735308287LLU,17293822569371140095LLU,8726759349354751LLU,18446744069414846456LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4095LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,4],[1,5],[2,4],[2,5],[3,6],[3,7],[4,6],[5,8],[6,9],[7,10],[7,11],[8,10],[8,12],[9,12],[9,13],[10,13],[11,12],[11,13]]\n", fout);
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

