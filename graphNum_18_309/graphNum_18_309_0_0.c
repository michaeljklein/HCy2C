#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_18_309_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 17;
static uint_fast32_t endhere = 0;
char str[28] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[18][3] = {{17293822573397639169LLU,18446742974265032703LLU,1048575LLU},{17293822570176446463LLU,18446744073709551615LLU,1048575LLU},{1152921504606846975LLU,18446744073642442752LLU,1048575LLU},{16140901064495824896LLU,18446742974265032703LLU,1048575LLU},{18446744070488358911LLU,18428730774711697407LLU,1048575LLU},{18446744072635809792LLU,18446744073709551615LLU,1048575LLU},{4611686017353711615LLU,18428730774644588544LLU,1048575LLU},{18446673709260340993LLU,13853072445268819967LLU,1048575LLU},{17293892937846849791LLU,4611684927505694719LLU,1048512LLU},{4611686018419064831LLU,4323316004298944512LLU,1047583LLU},{18446744072644198399LLU,16068984207879180287LLU,1033211LLU},{18229726595948469745LLU,18174276003722952703LLU,993279LLU},{18392630784314437391LLU,14123281688872091632LLU,851775LLU},{18442297597146167483LLU,4611668363830099775LLU,769660LLU},{17298322870144829407LLU,18445898616913281023LLU,455619LLU},{18446743815869431795LLU,8716585136974458895LLU,998655LLU},{18442521948051208703LLU,18393809134295449407LLU,757752LLU},{18443300402485787455LLU,14938435525076320243LLU,647037LLU}};

static uint_fast64_t D[18][3] = {{4611686017353711615LLU,18428730774644588544LLU,1048575LLU},{11529215044994793470LLU,18446744073687181994LLU,1048575LLU},{18062436904791375873LLU,18446744073709551615LLU,1048575LLU},{9223372033633550335LLU,18428730774666958165LLU,1048575LLU},{14219365226347757567LLU,18446742974265032703LLU,1048575LLU},{7301836197632933887LLU,18446744073664812373LLU,1048575LLU},{17293822573397639169LLU,18446742974265032703LLU,1048575LLU},{4611686017769865215LLU,4600654618214546495LLU,1048512LLU},{18446744073293398015LLU,13846090554939524032LLU,1048575LLU},{18212782280085066077LLU,16086857468394602495LLU,1033211LLU},{17527784367022124707LLU,4323454943403966463LLU,1047583LLU},{4557642822344830975LLU,13825761546979983344LLU,851733LLU},{18229726866427600383LLU,9219378318560787519LLU,993258LLU},{18446740775111622623LLU,15401252994347172860LLU,455679LLU},{18446730827625922491LLU,16890719613830037251LLU,769663LLU},{18375756303931794271LLU,16131612144327147519LLU,842737LLU},{17528005420394590151LLU,17437864500337308668LLU,458143LLU},{17365879956942331895LLU,9078587520806875391LLU,488911LLU}};

uint_fast8_t X[18] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[18][3] = {{4611686017353711615LLU,18428730774644588544LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,1048575LLU},{18446744073709551615LLU,18446744073709551615LLU,1048575LLU}};

#if UINTPTR_MAX == 0xffffffffffffffff // 64-bit. Hopefully this means the cpu has 'popcnt'.
int counter (uint64_t * buf){
    uint64_t cnt[18];
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
            "popcnt %2, %2  \n\t"
            "add %2, %0     \n\t"
            "popcnt %3, %3  \n\t"
            "add %3, %1     \n\t"
            : "+r" (cnt[16]), "+r" (cnt[17])
            : "r" (buf[16]), "r" (buf[17]));


    return cnt[0] + cnt[1] + cnt[2] + cnt[3] + cnt[4] + cnt[5] + cnt[6] + cnt[7] + cnt[8] + cnt[9] + cnt[10] + cnt[11] + cnt[12] + cnt[13] + cnt[14] + cnt[15] + cnt[16] + cnt[17];
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
    sprintf(str, "[                  ,%5d]\n", this);
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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,3],[2,4],[3,5],[4,6],[4,7],[5,8],[5,9],[6,8],[6,10],[7,9],[7,11],[8,11],[9,10],[10,11]]\n", fout);
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

