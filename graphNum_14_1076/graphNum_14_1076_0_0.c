#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_14_1076_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 13;
static uint_fast32_t endhere = 0;
char str[24] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[14][3] = {{1073741823LLU,18446744073709551615LLU,4095LLU},{18446744072635809792LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744072635809792LLU,4095LLU},{17842804117425094655LLU,18446741875590430565LLU,4095LLU},{11520767773110112192LLU,18437739073478027263LLU,4095LLU},{18446673691862364223LLU,9007199240036255LLU,4095LLU},{18446744073365516206LLU,18446314679938996216LLU,4088LLU},{18311636017224743807LLU,14672727506516180871LLU,4039LLU},{18446735345765580765LLU,18445027597680110719LLU,3647LLU},{15130273956706899707LLU,4503494052779393023LLU,511LLU},{18446744073705361407LLU,18442170072050204655LLU,2511LLU},{9205071616076152831LLU,17582050780590899199LLU,3897LLU},{140737488355327LLU,18446314679958503417LLU,4088LLU},{13720213189586402119LLU,16114020204219990015LLU,4039LLU}};

static uint_fast64_t D[14][3] = {{18446744072643571084LLU,18446744073143584174LLU,4095LLU},{16342171507314655231LLU,18446744073201777233LLU,4095LLU},{2104572567460876915LLU,18446744073709551615LLU,4095LLU},{11529212847045210112LLU,11327340313162254335LLU,4095LLU},{17843156154201407487LLU,7124694234673971079LLU,4095LLU},{18437876581150953471LLU,18441453600472268669LLU,4095LLU},{18446603337291789311LLU,1152921478837043199LLU,2783LLU},{16139212213830275064LLU,18446603884920006655LLU,1915LLU},{17302829768289877567LLU,18311636078443290623LLU,3566LLU},{18446744073650798543LLU,18156402394714340352LLU,4021LLU},{1152843426396372991LLU,17436508391722712795LLU,3897LLU},{18080808427684102143LLU,11468310897982440447LLU,2511LLU},{18446744072984457693LLU,1152921478290582959LLU,2783LLU},{17870177767283228671LLU,8574851743819759615LLU,1915LLU}};

uint_fast8_t X[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[14][3] = {{18446744072643571084LLU,18446744073143584174LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,4095LLU}};

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
    fputs("[[0,3],[0,4],[0,7],[1,3],[1,5],[1,6],[2,4],[2,5],[2,6],[2,7],[3,6],[3,7],[4,6],[5,7]]\n", fout);
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

