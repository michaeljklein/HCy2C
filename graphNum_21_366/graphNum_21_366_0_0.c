#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_366_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][2] = {{18411278222350089987LLU,17179868175LLU},{18446744069414649855LLU,17179869183LLU},{18446462603027808255LLU,17179869183LLU},{18410996743077363456LLU,17179869183LLU},{13871086852300931327LLU,17179869183LLU},{18410996747372592897LLU,17179869183LLU},{13870805394504221183LLU,17179869183LLU},{4611404543449890813LLU,17179869168LLU},{18446744073709486080LLU,17179869183LLU},{71776187780629503LLU,17179869168LLU},{18446181123752984571LLU,17179837423LLU},{18411841172306657031LLU,17178852383LLU},{4755520006404376575LLU,17179837424LLU},{18445618173790126071LLU,17164107743LLU},{18412967072226082575LLU,16927226943LLU},{14123008055968731135LLU,17164109808LLU},{18439988674016837583LLU,16324034367LLU},{18419722471918796607LLU,13756529919LLU},{17582036452579987455LLU,11808008188LLU},{14987715677098295295LLU,8308891635LLU},{17865766527437889503LLU,12312244093LLU}};

static uint_fast64_t D[21][2] = {{71776187780629503LLU,17179869168LLU},{18446650245853938174LLU,17179869183LLU},{18446744072277851649LLU,17179869183LLU},{13870899213769703423LLU,17179869183LLU},{18410996735919259647LLU,17179869183LLU},{13870805394504221183LLU,17179869183LLU},{18410996747372592897LLU,17179869183LLU},{18410715225150979583LLU,17179868175LLU},{18446556428020154367LLU,17179869183LLU},{18411278222350089987LLU,17179868175LLU},{13763000255085804543LLU,17178853375LLU},{4755520006404376575LLU,17179837424LLU},{18411841172306657031LLU,17178852383LLU},{9079256024145197055LLU,16928209919LLU},{14123008055968731135LLU,17164109808LLU},{18412967072226082575LLU,16927226943LLU},{15852456283576692735LLU,13949188086LLU},{16717295846101590015LLU,16368259065LLU},{18426477872114827119LLU,8169913791LLU},{18433233273820807071LLU,11710103167LLU},{16122675556532584319LLU,6299303415LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][2] = {{71776187780629503LLU,17179869168LLU},{18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,17179869183LLU}};

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

    } else {
        A[i][0] = A[i-1][0] & D[i][0];
        A[i][1] = A[i-1][1] & D[i][1];

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,3],[2,4],[3,5],[4,5],[4,6],[5,7],[6,7],[6,8],[7,9],[8,9],[8,10],[9,11],[10,12],[10,13],[11,12],[11,13],[12,13]]\n", fout);
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

