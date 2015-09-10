#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_15_76_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 14;
static uint_fast32_t endhere = 0;
char str[25] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[15][5] = {{14244321287089421147LLU,18446744073654996575LLU,4547720263017693183LLU,18442244811126194160LLU,4194303LLU},{4398046511103LLU,18446744073441116160LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,268435455LLU,18446744073709289472LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,13835058055282425855LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,4611686018427387903LLU,18446739675663040512LLU,4194303LLU},{18446739675663040512LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18410662448592719615LLU,18446726481790664703LLU,18446744073709539323LLU,13839561654892558351LLU,4194303LLU},{4610349012233617399LLU,8070468124433973238LLU,18446726273234370463LLU,4611686018427387903LLU,4194048LLU},{18446744073709549568LLU,2161514512660824063LLU,18266600058479706096LLU,13830488313158406076LLU,4190463LLU},{18446471394821670911LLU,18446744073573628914LLU,15850392258525265919LLU,5431338674534775679LLU,4194093LLU},{18438018345140748287LLU,18441396049145741311LLU,18446744073709549583LLU,18446251492397809651LLU,4132858LLU},{15861673493847343103LLU,18446743992105172943LLU,18446636596435093503LLU,18352731431488192511LLU,3211263LLU},{288229963834326977LLU,4584523683174807552LLU,18446744073709518846LLU,13833918957075013629LLU,3013863LLU},{18446744073306880063LLU,18446743658976774143LLU,18442381185798635249LLU,18009701395808124927LLU,2085887LLU},{18439953486138212303LLU,18446727031279319103LLU,13839561654909532670LLU,14411228536515854335LLU,3096063LLU}};

static uint_fast64_t D[15][5] = {{18446480190914695167LLU,17293822569370091511LLU,18446726275365076991LLU,5431341150591844351LLU,4194093LLU},{18446741769356500990LLU,15706789657750536191LLU,17690135895697365823LLU,18446743352151764662LLU,4194303LLU},{17703077004816937819LLU,18446744073553701722LLU,11229364428530778111LLU,18446741588726463359LLU,4194303LLU},{18049986797469428989LLU,13785096246636003327LLU,18446744073709449187LLU,18446744069229699049LLU,4194303LLU},{11516724588993920935LLU,9223353682312034215LLU,18442046607825302748LLU,18446744073709551615LLU,4194303LLU},{8070446134201417727LLU,16624992634585931005LLU,7978685289075310591LLU,18446742886683768287LLU,4194303LLU},{430655339919047667LLU,9223372036800249854LLU,18446744071562330015LLU,13831570343396360191LLU,4194258LLU},{18388197217082015327LLU,18446744073709293151LLU,4547720263034195963LLU,17630580990457935872LLU,4194303LLU},{18158518095604350975LLU,17863519022792835071LLU,14987843218836553727LLU,16032811374774057471LLU,3567481LLU},{14987979559889010687LLU,1152921504573267711LLU,9168765891356393472LLU,18442244820052213744LLU,4194303LLU},{18446744073709551615LLU,18212556876241764289LLU,18446741876833779711LLU,18415218392060395295LLU,3798703LLU},{9223372036854775807LLU,18445649784753879550LLU,17938963215488647167LLU,3170534137666734079LLU,4168190LLU},{18446741839854673919LLU,17581489462725050367LLU,18442242673105297023LLU,17906167532644858103LLU,1560447LLU},{18446743590491324415LLU,18411827973867962367LLU,14411517568747518911LLU,16139775160296144895LLU,2916321LLU},{18230426705813567999LLU,17329851365861621759LLU,18446744073709354999LLU,18444452695772233727LLU,1308447LLU}};

uint_fast8_t X[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[15][5] = {{18446480190914695167LLU,17293822569370091511LLU,18446726275365076991LLU,5431341150591844351LLU,4194093LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU}};

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
    fputs("[[0,2],[0,3],[0,4],[0,5],[0,6],[1,4],[1,5],[1,6],[2,3],[2,4],[2,5],[2,6],[3,5],[3,6],[5,6]]\n", fout);
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

