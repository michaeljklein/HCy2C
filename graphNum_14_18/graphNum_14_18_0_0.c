#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_14_18_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 13;
static uint_fast32_t endhere = 0;
char str[24] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[14][3] = {{18446744056529682432LLU,18446744073709551615LLU,17592186044415LLU},{17179869183LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744072635809792LLU,17592186044415LLU},{18446744073709551615LLU,1073741823LLU,17592186044415LLU},{18446744071291797503LLU,17581841805685506032LLU,17592186043392LLU},{17581208262626228209LLU,18439981012046839807LLU,17592184996863LLU},{18428703561750675087LLU,18446744073708501519LLU,17591113351167LLU},{18446744069292949503LLU,14987945268668785055LLU,17575808070655LLU},{14987845969226202207LLU,18418631753968123903LLU,17334441869052LLU},{18406352379251778555LLU,18446744073707200509LLU,13469017395155LLU},{18446744073709420544LLU,9222808537137676287LLU,10943031295999LLU},{18311636067708698623LLU,18374668870305710079LLU,8243046776719LLU},{144115188007575551LLU,18446744073705353207LLU,13146894824575LLU},{18374615957382364663LLU,18446744072644198399LLU,8587786190781LLU}};

static uint_fast64_t D[14][3] = {{6333709175293476863LLU,10893771666097796795LLU,17592186044415LLU},{18446744057842237438LLU,7780459218078186846LLU,17592186044415LLU},{12383480038333097757LLU,18219257263258861567LLU,17592186044415LLU},{18176298949659842787LLU,18446744073693809637LLU,17592186044415LLU},{18446735294762844033LLU,18439982077197679615LLU,17591353711615LLU},{18428712082997509887LLU,17581841839021882880LLU,17591944871142LLU},{17581208517908346879LLU,18446742975221284863LLU,17592185808665LLU},{18442249270174670975LLU,18419722469500780541LLU,14963632472048LLU},{18410715241273884667LLU,14987979353730318847LLU,15932986475487LLU},{14987977906322374623LLU,18445619273113010079LLU,17482648387327LLU},{18307132485261066239LLU,15456186631454553787LLU,8243046776719LLU},{6338212774920847359LLU,4588318368377077759LLU,10943031295999LLU},{18446744064574357503LLU,18303754784735035007LLU,7833902374911LLU},{4608301721637023679LLU,144115188075855871LLU,9886075190775LLU}};

uint_fast8_t X[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[14][3] = {{6333709175293476863LLU,10893771666097796795LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU}};

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
    fputs("[[0,3],[0,4],[0,5],[0,6],[1,4],[1,5],[1,6],[2,4],[2,5],[2,6],[3,4],[3,5],[4,6],[5,6]]\n", fout);
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

