#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_529_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][6] = {{18446744071562067969LLU,65535LLU,18446744073709547520LLU,18374686479738732543LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,63LLU,18446744073709547520LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,4095LLU,18446744073642442752LLU,18446744073709551615LLU,3LLU},{18446744071562067968LLU,18446744073709551615LLU,18446708889337454591LLU,18374686479736077685LLU,18446744073709551615LLU,3LLU},{2147483647LLU,18446744073709486144LLU,18446744073709551615LLU,72057594037927935LLU,18446744073705357312LLU,3LLU},{0LLU,18446744073709551552LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,15958467311396847615LLU,18446726481523510647LLU,18417073298710986751LLU,18446744072640004095LLU,3LLU},{18446603340516163583LLU,18446744073709551615LLU,17592186044415LLU,72057593970819072LLU,18446743799905386368LLU,3LLU},{140737488355327LLU,18446744073709486272LLU,18446726481523523583LLU,18446744073709551615LLU,18446744072635809919LLU,3LLU},{17293822569102671873LLU,18446726481523562494LLU,18446744073709551615LLU,18446742974264983551LLU,18446709129687859199LLU,3LLU},{18374686477524172799LLU,17592186043903LLU,18446744073709547520LLU,18374687579183251440LLU,18442275652003430399LLU,3LLU},{18446742977398095611LLU,3746770586378174463LLU,13835075647468205055LLU,35322352073965567LLU,18378907778614820863LLU,3LLU},{18410857113690570751LLU,18446744073709551615LLU,4611686018158968831LLU,18446744073642442752LLU,17364674825666150400LLU,3LLU},{36027701802303487LLU,18446744073709486528LLU,13835110832108732415LLU,72057594037927935LLU,18378907778619031551LLU,3LLU},{16861476994674098049LLU,18442258065999827962LLU,18445899645558190335LLU,18248569193202974719LLU,14965457438130536447LLU,3LLU},{18445048076923011199LLU,18446726481791942623LLU,14987966365748494320LLU,9219993241917534223LLU,4395482389856386297LLU,3LLU},{18442222744448827367LLU,17293840161273004025LLU,18230570466949464063LLU,16140620688224485372LLU,16987331432700966895LLU,2LLU},{11457157415531706495LLU,1152921436155801087LLU,18433233223287828480LLU,17798507137920401203LLU,13749771124378304511LLU,1LLU},{18124604750366900103LLU,18442521948791504895LLU,18445899645290807295LLU,18302615687400525823LLU,14123276096287753095LLU,3LLU},{9232273616958128127LLU,18446744073709543935LLU,18428799975241543935LLU,17311836967549272063LLU,16124854516796100511LLU,1LLU},{9222240708102955007LLU,17365863670466158528LLU,13853054930324291583LLU,1152709573740590079LLU,9169169960952659451LLU,2LLU}};

static uint_fast64_t D[21][6] = {{3675078037717647359LLU,18446744073709551565LLU,52776558149631LLU,72057593974801359LLU,18446744073705357312LLU,3LLU},{3675078037717647358LLU,18446744073709551565LLU,12297811790286987263LLU,18446744073685854565LLU,18446744073709551615LLU,3LLU},{14771666035991904257LLU,7393053072392847474LLU,18446744073709549209LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709486143LLU,6148949875608616959LLU,72057593995843551LLU,18446744073705357312LLU,3LLU},{18446744073709551615LLU,11053691001316704255LLU,18446691297151404390LLU,18374686479734750256LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,11053691001316704191LLU,6148932283422566758LLU,18446744073666139802LLU,18446744073709551615LLU,3LLU},{18446603337105454291LLU,8637191453549264767LLU,18446744073709549533LLU,72057594037927935LLU,18446743799905386368LLU,3LLU},{14771666039402613549LLU,14714328930240430322LLU,18446744073709550643LLU,18417073298710986751LLU,18446744072640004095LLU,3LLU},{18446744072446325971LLU,3732415143469121535LLU,18446691297151415244LLU,18404357254733315120LLU,18446743799905386495LLU,3LLU},{13713125063325122559LLU,18446744073709551085LLU,3517096027167342591LLU,10880696699714338800LLU,18442275652001703758LLU,3LLU},{7183717949457301503LLU,18446744073709541342LLU,14929700823100358655LLU,7638104967969965007LLU,18446709129685391537LLU,3LLU},{18410856013842082735LLU,18389322302073339647LLU,18446744073441132339LLU,18435440919692967935LLU,17364675098392379519LLU,3LLU},{14771806776133033593LLU,71777214545265138LLU,18446744073709547775LLU,18391641210763608063LLU,18378907778623209471LLU,3LLU},{18446744073204261255LLU,18374966859164286975LLU,18446744073709551360LLU,18429789342680693808LLU,17364674825666166783LLU,3LLU},{13833079174769672191LLU,18446744073709551567LLU,274703033054543856LLU,4031847566403432448LLU,4393613248005274744LLU,3LLU},{17892748391049887743LLU,18442258066268207609LLU,18229514931709931775LLU,15870668594166431743LLU,14962893102295492559LLU,3LLU},{9781182271632439423LLU,18446744005258504159LLU,14971077802520805375LLU,8358680843924799247LLU,13753986381348921021LLU,1LLU},{8927229360281223143LLU,18446744073693798392LLU,18175682637107298303LLU,14843864371006800895LLU,16987549653412311523LLU,2LLU},{11457156592904937087LLU,72041097336942023LLU,14109761088337739760LLU,4030791197722148863LLU,4565664859119550463LLU,3LLU},{18445613775647639527LLU,17298308645247778815LLU,18446744073708765168LLU,18443101459600060668LLU,8790788855709040123LLU,2LLU},{18419616920815401375LLU,18442521884382724095LLU,18446744073457889295LLU,18379176830332567347LLU,15489002669086855071LLU,1LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][6] = {{3675078037717647359LLU,18446744073709551565LLU,52776558149631LLU,72057593974801359LLU,18446744073705357312LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,4],[3,6],[4,7],[5,8],[5,9],[6,7],[6,10],[7,11],[8,10],[8,12],[9,12],[9,13],[10,13],[11,12],[11,13]]\n", fout);
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
