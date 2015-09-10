#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_14_1580_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 13;
static uint_fast32_t endhere = 0;
char str[24] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[14][3] = {{536870911LLU,18446744073709551614LLU,1023LLU},{18446744073172680704LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744072635809793LLU,1023LLU},{8353728568978571263LLU,18446742975269453793LLU,1023LLU},{18410715001812619136LLU,18442241573467975711LLU,1023LLU},{14914125340118874239LLU,13839561654909534207LLU,1023LLU},{18446744073507614454LLU,4598171918149848459LLU,1022LLU},{18444632943192047103LLU,16663318531076030463LLU,1009LLU},{4559893591633166253LLU,18443141352062451710LLU,911LLU},{18446604435732552699LLU,18230518506427252351LLU,127LLU},{17725864632687003647LLU,9222771687399882751LLU,891LLU},{18446744073173204991LLU,14411517724314238947LLU,911LLU},{140737488355327LLU,4598171918862884798LLU,1022LLU},{18446743738701921671LLU,18406282045706334719LLU,1009LLU}};

static uint_fast64_t D[14][3] = {{18446744073502984402LLU,18446744072642815171LLU,1023LLU},{6596425576859303935LLU,18446744073702546236LLU,1023LLU},{11850318497056814893LLU,18446744073709551615LLU,1023LLU},{18338655466449532928LLU,18043222206678302719LLU,1023LLU},{14121045419550048255LLU,14240381645933658111LLU,1023LLU},{9218868024910483455LLU,18444942351035002881LLU,1023LLU},{18446603336732901311LLU,17290444663223746559LLU,727LLU},{4575657221005758456LLU,18446674254159150606LLU,446LLU},{18446744073641982207LLU,8939645245293858815LLU,891LLU},{18428870412684738535LLU,13258386145038827003LLU,1005LLU},{16130697042539315199LLU,14120887096969265150LLU,911LLU},{18176520064478478335LLU,9109881546146700095LLU,891LLU},{18446744073679755675LLU,17290444662870046455LLU,727LLU},{288098434253062143LLU,15987777841255137262LLU,446LLU}};

uint_fast8_t X[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[14][3] = {{18446744073502984402LLU,18446744072642815171LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,1023LLU}};

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
    fputs("[[0,3],[0,4],[0,6],[1,3],[1,5],[1,6],[2,4],[2,5],[2,6],[2,7],[3,6],[3,7],[4,7],[5,7]]\n", fout);
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

