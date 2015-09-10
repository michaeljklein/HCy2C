#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_14_122_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 13;
static uint_fast32_t endhere = 0;
char str[24] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[14][3] = {{18446744069414584320LLU,18446744073709551615LLU,255LLU},{17293822573397671935LLU,18446744073709551615LLU,255LLU},{1152921504606846975LLU,18446744073692774400LLU,255LLU},{18446744073709549568LLU,18446744004997938639LLU,255LLU},{18266599787962828799LLU,18446462667452317695LLU,255LLU},{18446743966339563519LLU,18158795172534550335LLU,255LLU},{2305834217415639039LLU,14019491029078269951LLU,255LLU},{18445626969349881597LLU,4575094254023475199LLU,252LLU},{17294948468992638963LLU,18445617345142456312LLU,195LLU},{4611677359773317135LLU,14123286030546960351LLU,255LLU},{18430853931664932863LLU,4429853131077042183LLU,183LLU},{18445758911156821951LLU,17861259629258883071LLU,124LLU},{18433127704527142911LLU,4611422135066280191LLU,183LLU},{17310851805193682935LLU,18446730051497230328LLU,77LLU}};

static uint_fast64_t D[14][3] = {{1910664644561731583LLU,18446744073703807728LLU,255LLU},{17293822566478842654LLU,18446744073698518287LLU,255LLU},{17689000936378528993LLU,18446744073709551615LLU,255LLU},{15915369106262458367LLU,18342623002617666557LLU,255LLU},{8932304370947588095LLU,18262659376231612163LLU,255LLU},{13776334925949042687LLU,18446719466129784062LLU,255LLU},{18446744073679945712LLU,13833369201132697007LLU,229LLU},{1152921502390152159LLU,15775967726398341112LLU,219LLU},{18446744072769232447LLU,7430865700702130015LLU,254LLU},{18221212248590532607LLU,13833043200221115325LLU,229LLU},{17690137918737188743LLU,17568524622905737215LLU,95LLU},{18429848888896518651LLU,15923461609821831167LLU,179LLU},{8358116274584158087LLU,17566290335674269691LLU,95LLU},{18446737386709973119LLU,5494180387619852127LLU,191LLU}};

uint_fast8_t X[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[14][3] = {{1910664644561731583LLU,18446744073703807728LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,255LLU}};

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
    fputs("[[0,1],[0,2],[0,4],[1,3],[1,5],[1,7],[2,3],[2,4],[2,6],[3,7],[4,5],[4,6],[5,7],[6,7]]\n", fout);
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

