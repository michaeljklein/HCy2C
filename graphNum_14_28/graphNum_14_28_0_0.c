#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_14_28_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 13;
static uint_fast32_t endhere = 0;
char str[24] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[14][3] = {{17861273926349219199LLU,576320014815068145LLU,1136018300023453935LLU},{8589934591LLU,18446744073709551488LLU,1152921504606846975LLU},{18446744073709551615LLU,18446708889337462911LLU,1152921504606846975LLU},{18446744073709551615LLU,35184372088831LLU,1152921504606830592LLU},{11529201800389328895LLU,14986888842676519035LLU,1152921504590085631LLU},{8931570446533312480LLU,18267725988521574366LLU,1152921470263881721LLU},{18397203721890556959LLU,18446743592662745087LLU,1152851170222407679LLU},{18446744072890613689LLU,17898984835232198655LLU,1151865870112784315LLU},{18446744065119617024LLU,18446744073709551615LLU,1152921504606846975LLU},{18371873928877416423LLU,18446742940106620415LLU,882705520789520383LLU},{18446744073709290495LLU,6899299669239396607LLU,843297917828349927LLU},{13708666994579210239LLU,18157669272627707839LLU,972106748697763743LLU},{17437936614784368639LLU,18446713287367182335LLU,562809198704852991LLU},{1152921504598228987LLU,18446741874451413888LLU,861594894919335935LLU}};

static uint_fast64_t D[14][3] = {{18372434679526588385LLU,18439425689957433343LLU,972144198682148795LLU},{18446744070715865773LLU,6860573349288038143LLU,1152921504606846771LLU},{3718398777463715198LLU,17436389644806651805LLU,1152921504606834381LLU},{17034861639066144723LLU,18446736308081504767LLU,1152921504606846975LLU},{18429714287862742016LLU,18302628404588969951LLU,1152894253425225721LLU},{18410715018988875775LLU,14987979559886913659LLU,1152878417481940479LLU},{2017546661961580543LLU,18410750459384954878LLU,1152921474169208831LLU},{18446181128051066367LLU,18446602236709567999LLU,1052702114943285487LLU},{16140227733882929151LLU,12596532918952460130LLU,1152921504606843390LLU},{17861276120539594559LLU,36019863486885873LLU,1145743377300324351LLU},{17294385519056125951LLU,17937837298606342143LLU,432081577233598463LLU},{18446706965192114175LLU,4584629270650814454LLU,1136023902821022719LLU},{18446251355061354495LLU,18446744067132489615LLU,810081134011481984LLU},{18446744067231448303LLU,18446726180874215423LLU,351214799155085439LLU}};

uint_fast8_t X[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[14][3] = {{18372434679526588385LLU,18439425689957433343LLU,972144198682148795LLU},{18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU}};

#if UINTPTR_MAX == 0xffffffffffffffff // 64-bit. Hopefully this means the cpu has 'popcnt'.
int counter (uint64_t * buf){
    uint64_t cnt[14];
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


    return cnt[0] + cnt[1] + cnt[2] + cnt[3] + cnt[4] + cnt[5] + cnt[6] + cnt[7] + cnt[8] + cnt[9] + cnt[10] + cnt[11] + cnt[12] + cnt[13];
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

    } else {
        A[i][0] = A[i-1][0] & D[i][0];
        A[i][1] = A[i-1][1] & D[i][1];
        A[i][2] = A[i-1][2] & D[i][2];

    }
}

void printout(){
    sprintf(str, "[              ,%5d]\n", this);
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
    fputs("[[0,3],[0,4],[0,5],[0,6],[1,3],[1,5],[1,6],[2,4],[2,5],[2,6],[3,4],[3,5],[3,6],[4,6]]\n", fout);
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

