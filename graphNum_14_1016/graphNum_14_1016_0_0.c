#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_14_1016_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 13;
static uint_fast32_t endhere = 0;
char str[24] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[14][3] = {{18446744072094351359LLU,18392700328958229745LLU,68719443983LLU},{17293822573397671935LLU,18446744073709551615LLU,68719476735LLU},{1152921504606846975LLU,18446744073692774400LLU,68719476735LLU},{18446744073709551615LLU,18158513697574617087LLU,68719476735LLU},{13781014589137215457LLU,288124822515343359LLU,68719476720LLU},{18446744069414584320LLU,18446744073709551615LLU,68719476735LLU},{9222202431292046623LLU,18446744073709535119LLU,68702732287LLU},{2305843009213628416LLU,17573043546909310974LLU,68599873531LLU},{18446480186623983615LLU,18446462527865880575LLU,67779428111LLU},{18176526416735084473LLU,288107780085121023LLU,65464500223LLU},{13832735646157896679LLU,18446744073709539455LLU,55700356560LLU},{18438018349431517439LLU,18445054798647525375LLU,47226810623LLU},{17302829768222904319LLU,15564440312192368630LLU,33185304575LLU},{18442099715387422715LLU,4611686018410741759LLU,48855249727LLU}};

static uint_fast64_t D[14][3] = {{4611677226528669441LLU,7782114602979926015LLU,68708532209LLU},{16140901060707221502LLU,18347640674728012509LLU,68719476735LLU},{18068139816054038061LLU,18443611902220173311LLU,68719476735LLU},{4594550902296404435LLU,18446744073709330278LLU,68719476735LLU},{18445582988354911743LLU,18392700345602015105LLU,68713649775LLU},{16536640442070990847LLU,18260749268028978619LLU,68719476735LLU},{18392700877640032255LLU,10952754276601167103LLU,68719471006LLU},{18446471394825863167LLU,18266168973476722107LLU,67779428111LLU},{395748173668155391LLU,17567342295617896446LLU,68599873531LLU},{18443260820856109567LLU,18392700878181101569LLU,55694572751LLU},{18230569641254567871LLU,18446726498700230655LLU,65464457087LLU},{18446744073457893375LLU,14771793583232913407LLU,33009041399LLU},{18446744071552630783LLU,9221137829214548895LLU,46571716605LLU},{17582046142026186607LLU,18160765497371525119LLU,25687998451LLU}};

uint_fast8_t X[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[14][3] = {{4611677226528669441LLU,7782114602979926015LLU,68708532209LLU},{18446744073709551615LLU,18446744073709551615LLU,68719476735LLU},{18446744073709551615LLU,18446744073709551615LLU,68719476735LLU},{18446744073709551615LLU,18446744073709551615LLU,68719476735LLU},{18446744073709551615LLU,18446744073709551615LLU,68719476735LLU},{18446744073709551615LLU,18446744073709551615LLU,68719476735LLU},{18446744073709551615LLU,18446744073709551615LLU,68719476735LLU},{18446744073709551615LLU,18446744073709551615LLU,68719476735LLU},{18446744073709551615LLU,18446744073709551615LLU,68719476735LLU},{18446744073709551615LLU,18446744073709551615LLU,68719476735LLU},{18446744073709551615LLU,18446744073709551615LLU,68719476735LLU},{18446744073709551615LLU,18446744073709551615LLU,68719476735LLU},{18446744073709551615LLU,18446744073709551615LLU,68719476735LLU},{18446744073709551615LLU,18446744073709551615LLU,68719476735LLU}};

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
    fputs("[[0,2],[0,4],[0,5],[0,6],[1,3],[1,4],[1,6],[2,4],[2,5],[3,5],[3,6],[4,5],[4,6],[5,6]]\n", fout);
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

