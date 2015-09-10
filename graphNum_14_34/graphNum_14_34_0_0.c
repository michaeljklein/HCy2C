#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_14_34_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 13;
static uint_fast32_t endhere = 0;
char str[24] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[14][3] = {{18446742974197923840LLU,18446744073709551615LLU,288230376151711743LLU},{1099511627775LLU,18446744073709550592LLU,288230376151711743LLU},{18446744073709551615LLU,18446181123756131327LLU,288230376151711743LLU},{18446744073709551615LLU,562949953421311LLU,288230376151646208LLU},{14948565366568124415LLU,12537298291383059309LLU,288230376134958077LLU},{18446744056412241792LLU,9215490694556696575LLU,288230367578554311LLU},{18086394390342762623LLU,18095463302774652383LLU,288212792555599423LLU},{4597682638327676927LLU,18446737476430594047LLU,283744368710385663LLU},{18446744065924726015LLU,16194944257884155903LLU,274666740581531519LLU},{18429147154574737341LLU,2303591209400008511LLU,232850172313849836LLU},{17888244943357465579LLU,18446682228327874552LLU,72053813560737791LLU},{16138641568109166591LLU,18446742974164355071LLU,288230376135000063LLU},{576460198181208039LLU,16712858217171910648LLU,137324603314487263LLU},{18446744073709534623LLU,18446251490620865543LLU,243181126682673151LLU}};

static uint_fast64_t D[14][3] = {{7879855689131098111LLU,12536978315142691433LLU,288230376151669753LLU},{18446743951552997118LLU,9096144960820842495LLU,288230376151710838LLU},{17509277492288552757LLU,15260447337344925087LLU,288230376151689103LLU},{11504355088156006859LLU,18446661607820195830LLU,288230376151711743LLU},{18158513697549451264LLU,18446744039349812735LLU,287937729361083911LLU},{18446182083681320959LLU,18014390125454163967LLU,287508263296955389LLU},{1136032988824338431LLU,3458764513812153215LLU,284747121003028479LLU},{18338657681595695103LLU,18375091086528872397LLU,288224791318429695LLU},{17870845996445982713LLU,18444430701244612607LLU,197029185040928751LLU},{18446691296882979055LLU,18428729400330551288LLU,139611046477299583LLU},{18446598870527967167LLU,72057594036875071LLU,242930494937890812LLU},{8781702614023667711LLU,18446422963564248315LLU,287937729361083907LLU},{18446744038812389375LLU,18410152601615073279LLU,234029400703631100LLU},{18446743042910058495LLU,18446743867546918911LLU,68116669471326719LLU}};

uint_fast8_t X[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[14][3] = {{7879855689131098111LLU,12536978315142691433LLU,288230376151669753LLU},{18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU}};

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
    fputs("[[0,3],[0,4],[0,5],[0,6],[1,3],[1,4],[1,5],[1,6],[2,4],[2,5],[2,6],[3,6],[4,5],[4,6]]\n", fout);
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

