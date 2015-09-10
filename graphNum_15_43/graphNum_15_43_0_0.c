#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_15_43_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 14;
static uint_fast32_t endhere = 0;
char str[25] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[15][5] = {{9148636032420786157LLU,18446743832646121478LLU,288223641642991615LLU,18439421532123168236LLU,270848149503LLU},{4503599627370495LLU,18446741874686296064LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,2199023255551LLU,18446744039349813248LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,34359738367LLU,18446744073692774400LLU,274877906943LLU},{18307132485261066239LLU,9223092685739380687LLU,16710605352206070654LLU,18446743523969941503LLU,274877906943LLU},{18446455724906119136LLU,18410996751667298303LLU,11529180956898316287LLU,18410715826446399462LLU,274877906943LLU},{13977950586385792031LLU,18446743497912172543LLU,18346574166372646911LLU,36028797014572703LLU,274877906688LLU},{4611685969032348671LLU,13871086852254989624LLU,18446744073323675625LLU,18446744073709551615LLU,274861129983LLU},{18446620803853186879LLU,4395442867569426431LLU,18159427932852846080LLU,17329851328540700607LLU,274625984703LLU},{18442240474082181120LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{17564037584122674427LLU,18445046427686537215LLU,18446744073167438335LLU,1152749967840903167LLU,210453397494LLU},{18446744073575366655LLU,17870252535080550399LLU,17293259410977519615LLU,13835058054762069117LLU,201058050019LLU},{18419721376567918591LLU,18446742969785245691LLU,18298106869186559999LLU,18428500960130065407LLU,231768456191LLU},{16028312173323223039LLU,18441994182538034143LLU,18446744041497296862LLU,18301781729104363519LLU,134184173343LLU},{18446744003798892391LLU,18419702685809770495LLU,18446744072627420735LLU,17547150045592158207LLU,205420232687LLU}};

static uint_fast64_t D[15][5] = {{17564019872226999359LLU,4611686018358181887LLU,18446532417720156160LLU,35888043424477119LLU,231776976894LLU},{18445843818231059902LLU,12033121225078210559LLU,14986218592995665919LLU,18446744073709537076LLU,274877906943LLU},{8994590055148728269LLU,18446742376365531123LLU,17928774728663695359LLU,18446744073696606415LLU,274877906943LLU},{11186940130576956019LLU,18396579953888981407LLU,18446744069653659020LLU,18446744073709551615LLU,274877906943LLU},{18446744073709518848LLU,18446743523937877503LLU,18374686479539470319LLU,15478826839291461510LLU,274871594492LLU},{3307296615628799LLU,9223372036854775800LLU,18412967076235575288LLU,4575657039929032447LLU,274877079099LLU},{18446462581819310079LLU,13835060185552387855LLU,9799832789158199295LLU,18425826070310156287LLU,274868270079LLU},{18446710813440868351LLU,18446744041228799999LLU,18445618203867464575LLU,16859922271609815039LLU,274877906887LLU},{18444487875296739321LLU,18445046427755741191LLU,18446737338659766271LLU,18446709164112870895LLU,250983940087LLU},{16712858217171910655LLU,6463788665795931756LLU,3978494829815634547LLU,18446744073705734139LLU,274877906943LLU},{9150786672872908783LLU,18230500681788162046LLU,1125891283353599LLU,18439425620967423996LLU,273166614719LLU},{18446744073709551615LLU,15990030475905728511LLU,13582689350381461447LLU,18229480576046333951LLU,103016299006LLU},{14987979559889010687LLU,18446743919090694398LLU,9204508781009960959LLU,18442237175546118140LLU,270849265409LLU},{17870283321406128127LLU,17562910722692284281LLU,18446744073709436667LLU,10925706307721748483LLU,193138802687LLU},{18442802865689828863LLU,14987838822400655359LLU,18446744056461656063LLU,9223371615931211775LLU,83735609214LLU}};

uint_fast8_t X[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[15][5] = {{17564019872226999359LLU,4611686018358181887LLU,18446532417720156160LLU,35888043424477119LLU,231776976894LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU}};

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
    fputs("[[0,3],[0,4],[0,5],[0,6],[1,3],[1,4],[1,5],[1,6],[2,4],[2,5],[2,6],[3,4],[3,5],[3,6],[4,6]]\n", fout);
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
