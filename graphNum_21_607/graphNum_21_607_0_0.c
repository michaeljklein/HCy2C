#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_607_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][4] = {{985162426875903LLU,18446462603027808252LLU,1125625033129983LLU,4397779124220LLU},{140737488355327LLU,18446744072635809792LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,1073741823LLU,18446743798831644672LLU,4398046511103LLU},{18446744073709027328LLU,6149665289026928639LLU,18446462873607951709LLU,4398046511103LLU},{140737488879615LLU,18446744073709551612LLU,18158795172534550527LLU,4398046511103LLU},{18446744073709027329LLU,18446744072635809795LLU,18446462873610747903LLU,4398046511103LLU},{18446744073709551615LLU,1073741815LLU,288230101273804796LLU,4398046511096LLU},{18446744073708503039LLU,18446744073709551615LLU,18446462323854934019LLU,4398046507015LLU},{18445899648771031047LLU,18446744072789201535LLU,18445899648779419647LLU,4398045464583LLU},{18446603336221196288LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{1005267781156857LLU,18446744073709551552LLU,288229551517990911LLU,4397779124220LLU},{18446744073709027335LLU,1125898833100863LLU,18446463698243420172LLU,4398045464583LLU},{18446181123749489327LLU,281474363143935LLU,18446181123756130300LLU,4398045466619LLU},{18159639563113332735LLU,18446742978492891135LLU,14106399931761688575LLU,4394004250623LLU},{288089673023094783LLU,18446463698244468732LLU,4341469766980993023LLU,4333370343420LLU},{18446744073709549575LLU,18159639597464420415LLU,18446727581035130895LLU,4173634408327LLU},{18446744073709029375LLU,288230375078232063LLU,18446480190917840892LLU,3568848402559LLU},{18429732429276094463LLU,14987768389217288188LLU,17434524666864549887LLU,3022714175229LLU},{14717761624278564767LLU,18433219049895752191LLU,5715065714218368831LLU,2127036407791LLU},{13907113454591410175LLU,18446726755461890047LLU,2242651860029931516LLU,1636323294207LLU},{4598036680610413055LLU,18230307357265264636LLU,17651849685637264383LLU,3109352865724LLU}};

static uint_fast64_t D[21][4] = {{18446744073709027335LLU,1125898833100863LLU,18446463698243420172LLU,4398045464583LLU},{18446723968350027774LLU,6149289990489636863LLU,18446743982082184537LLU,4398046511103LLU},{160842847879169LLU,18446744072789201512LLU,18446744073709551615LLU,4398046511103LLU},{140737488355327LLU,18445993476634968060LLU,18158794989285408759LLU,4398046511103LLU},{18446744073709551615LLU,1125896532225431LLU,18446462873606553612LLU,4398046511103LLU},{18446723968350027775LLU,18445618178097676287LLU,18158794897660837875LLU,4398046511103LLU},{6149303394778830163LLU,18446744073402768237LLU,18446462598732840959LLU,4398046507015LLU},{12297601521777552045LLU,18446744073095984882LLU,288230101273804799LLU,4398046511096LLU},{18446744073709551615LLU,18446462599806582743LLU,288229276641132543LLU,4397779124220LLU},{18446603336221196287LLU,12297454084140264855LLU,18446743890459011750LLU,4398046511103LLU},{18446744073704308735LLU,281474976710655LLU,18445899648778371072LLU,4398045464583LLU},{985162426875903LLU,18446462603027808252LLU,1125625033129983LLU,4397779124220LLU},{6149584869757288443LLU,18446744073709551565LLU,18446743249076879359LLU,4397779122175LLU},{18446744073709150695LLU,17362502462478515775LLU,18446575848429700044LLU,4333621373751LLU},{18446744073709428255LLU,1085367510064136703LLU,18446631923523271743LLU,4394019560655LLU},{17362379047476133887LLU,18446528831423512572LLU,11068721773972291583LLU,3568688955389LLU},{1085350188660293631LLU,18446677845313847295LLU,7379147924770390015LLU,4173527515134LLU},{14987977635743268743LLU,18429842380027850815LLU,9187199190926884620LLU,2104499882983LLU},{18446620928407208447LLU,13906904543070814204LLU,18302567106824045567LLU,2984867823165LLU},{18433233274357651583LLU,14717763530692235263LLU,17867983143030436095LLU,3159483039391LLU},{18230571261530505119LLU,4598174393854587391LLU,16131680559179038524LLU,1646842337775LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][4] = {{18446744073709027335LLU,1125898833100863LLU,18446463698243420172LLU,4398045464583LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,6],[3,7],[4,6],[4,8],[5,7],[5,9],[6,7],[8,10],[8,11],[9,12],[9,13],[10,12],[10,13],[11,12],[11,13]]\n", fout);
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
