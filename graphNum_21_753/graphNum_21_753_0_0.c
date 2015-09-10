#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_753_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][6] = {{72057594037895169LLU,18446744039350861824LLU,18446742974197927935LLU,18446744073709551615LLU,18445618242522185727LLU,17592186028032LLU},{18446744073709551615LLU,1048575LLU,18446742974197923840LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU,0LLU,18446744073708503040LLU,17592186044415LLU},{18446739675663040512LLU,9223372036854775807LLU,15987180542839746560LLU,15996220727407672831LLU,18446744039350853119LLU,17592186044415LLU},{4398046511103LLU,18446744039350861824LLU,18446741874686296063LLU,18437701543516823517LLU,18445618208162316253LLU,17592186044415LLU},{18374695275764645887LLU,13835058055283212287LLU,8608489950230347775LLU,8644650688502036479LLU,1125865547069439LLU,17592186044415LLU},{18446744073709518849LLU,4611686018427387903LLU,18446734178104901632LLU,18410573952938639223LLU,18446744073707978615LLU,17592186028032LLU},{9223372002226601983LLU,18410433801713745503LLU,961635942399LLU,18446744073692774400LLU,17149394567552827391LLU,17592181861943LLU},{18014397959725187071LLU,17870282290613977087LLU,18446744073709527039LLU,16777215LLU,13818169341898653696LLU,17591116496892LLU},{18374690877718167551LLU,4611686052787126271LLU,18446744073709547520LLU,18446744073709551615LLU,1125865549201407LLU,17592186044415LLU},{0LLU,18446744073708503040LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{5188146770730811379LLU,18446744073696312159LLU,17293822980177297407LLU,17298062281912877055LLU,18445850445633093631LLU,17576079658291LLU},{18446480156157538303LLU,18410294159442149119LLU,1152921469978673136LLU,18446727581018357760LLU,17023588996623626495LLU,17334484074239LLU},{18293620930447736799LLU,17654092740914315260LLU,18379190079295839743LLU,18442240474098893055LLU,11489807368139571199LLU,16694474964974LLU},{18157950745993017855LLU,18445054397604946431LLU,18446480182865805279LLU,4503599627370480LLU,18144897207557423104LLU,14274390915581LLU},{14916199042915500019LLU,13835198792757936127LLU,17293840161288548367LLU,17365880163140632575LLU,144115153984552959LLU,17576079671295LLU},{59672544738803457LLU,18289118086485245888LLU,18446744073642446143LLU,18446744005258510335LLU,18446735346335023103LLU,12912269688704LLU},{18410660301102874879LLU,16140894433333739583LLU,18446742974265030652LLU,18446744073709551360LLU,18445626969895731184LLU,7644906635391LLU},{4609223103665401615LLU,18437604928512818880LLU,18446744039014530931LLU,18446744009268265215LLU,18338631843928080383LLU,12713091628679LLU},{18302593701257250783LLU,18446739505977237500LLU,18446742982784704509LLU,18442240542801596175LLU,18443505943242080240LLU,8143072905198LLU},{18158372959968295743LLU,18446637969562396355LLU,18446744066935734263LLU,18446744009268330480LLU,18365584584825896975LLU,10839681661597LLU}};

static uint_fast64_t D[21][6] = {{18446742317787316223LLU,16605526159811149823LLU,17592186044415LLU,67818976445460735LLU,1125865549136127LLU,17592186044415LLU},{8214559566355038206LLU,18446744073708884570LLU,11068046884030382079LLU,11068046444225730969LLU,18446744073709132185LLU,17592186044415LLU},{10232184507354513409LLU,6452903932327505317LLU,18446743673645883392LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744039350861823LLU,8608485952247504895LLU,8631086893212944332LLU,18445618208162215884LLU,17592186044415LLU},{18446744073709551615LLU,2770468104528986111LLU,14757389981311823872LLU,14734788933485821047LLU,18446744039350324343LLU,17592186044415LLU},{8214565720323751936LLU,18446744073708884570LLU,15987167348700217343LLU,15941965546251304243LLU,18446744073707707699LLU,17592186028032LLU},{18374689121795899391LLU,18446744073709551615LLU,3689360689467490303LLU,3734561465705550813LLU,1125865546920925LLU,17592186044415LLU},{17913620704820998557LLU,8209498084550094325LLU,18446743776809421215LLU,18446744073709551615LLU,13818169341899702271LLU,17591116496892LLU},{1109589690775752291LLU,16077377866395581967LLU,18446743832670303840LLU,18446744073709551615LLU,17149394567552827391LLU,17592181861943LLU},{8214565720323784703LLU,18446744073708884570LLU,18446726881587175423LLU,18378925097264090880LLU,18445618242521202432LLU,17592186028032LLU},{18446744073709551615LLU,11993840141382713343LLU,7378697589742837759LLU,7378697629483820646LLU,18446744073708922470LLU,17592186044415LLU},{18446471394691670943LLU,9223231326109249525LLU,18446744017864490992LLU,18446727581035134975LLU,18303754785274196223LLU,17334060187647LLU},{13878404234791075313LLU,17432871189865560575LLU,18446743247464958367LLU,17298062281912877055LLU,13834459431329398783LLU,17575438179832LLU},{17256788816407033979LLU,16138752616757714959LLU,18446480182345660358LLU,18446744073709551600LLU,18014262169234833407LLU,14275395041343LLU},{2289974591084285895LLU,18167490097543151612LLU,18379189838776761465LLU,18446744073709486335LLU,14951667632116334591LLU,16694536204263LLU},{18014398509481976735LLU,18446744066092631792LLU,18446744006853369855LLU,18446726485817429760LLU,18446511870597656576LLU,17334060184268LLU},{18410659165887922175LLU,14950535279088238591LLU,71793711247259644LLU,1148682887281770240LLU,7613335149891023088LLU,7644906651647LLU},{18434358403703177215LLU,17638259361191034879LLU,18374967954648333631LLU,17365880094422200575LLU,10834534789366681599LLU,12912269688831LLU},{18392133803448057343LLU,14121599151539223039LLU,17365615454105629663LLU,17592186044415LLU,4316102082189852656LLU,7686682697215LLU},{17289459689816850299LLU,18428764309677932495LLU,18442258066217828103LLU,17365880163124903935LLU,17356868563808292863LLU,10991356035007LLU},{16073307504842219511LLU,13853067892527005695LLU,17298325137937789181LLU,18442258066268225535LLU,1149825247646580735LLU,8233418018815LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][6] = {{18446742317787316223LLU,16605526159811149823LLU,17592186044415LLU,67818976445460735LLU,1125865549136127LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,4],[1,5],[2,4],[2,5],[3,6],[3,7],[4,8],[5,9],[6,8],[6,10],[7,11],[7,12],[8,13],[9,10],[9,11],[10,12],[11,13],[12,13]]\n", fout);
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
