#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_15_1059_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 14;
static uint_fast32_t endhere = 0;
char str[25] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[15][3] = {{4611686018427387903LLU,18446743798831644672LLU,65535LLU},{13835058055819034623LLU,18446744073709551615LLU,65535LLU},{18446744073172680704LLU,18446744073709551615LLU,65535LLU},{9223372036854775296LLU,18446462733988623735LLU,65535LLU},{18446744006063292927LLU,18302910360597811199LLU,65535LLU},{18419714847547064319LLU,144115188075855871LLU,65520LLU},{13835059154793790977LLU,18446462873610747903LLU,65535LLU},{4611686018424176639LLU,16248987455551700992LLU,65423LLU},{18374264267206557695LLU,18441638766344929279LLU,64639LLU},{4611616749059571705LLU,18014397668742135792LLU,62444LLU},{18446744073434496511LLU,11997307674434530319LLU,53203LLU},{17901878459076940679LLU,18431422379176493055LLU,15999LLU},{18446743785761116159LLU,8919379048307875836LLU,31485LLU},{14411457183394332281LLU,18320501996899007731LLU,55247LLU},{18010457849070598063LLU,18436527411663209471LLU,16319LLU}};

static uint_fast64_t D[15][3] = {{14635442048127537665LLU,18446744073709551615LLU,65535LLU},{9223372036427673086LLU,18446743912264123750LLU,65535LLU},{13034674062863892479LLU,18446743960277072537LLU,65535LLU},{18446742974734794751LLU,3636375180503547869LLU,65529LLU},{4577619849664004095LLU,14843835300202889023LLU,65526LLU},{17653398055757545471LLU,18413277688523374835LLU,65535LLU},{18446744073282448895LLU,3636375158680244172LLU,65529LLU},{16014267109391325907LLU,18441639041221787647LLU,64639LLU},{16995439205939558189LLU,16248987455552749567LLU,65423LLU},{17906311977752326559LLU,13832982177123201023LLU,44927LLU},{18442241285797421025LLU,18433215957519302655LLU,31487LLU},{4611686018021261311LLU,16176929587710655488LLU,55232LLU},{13839561654909533727LLU,17293558480153607231LLU,53207LLU},{18444210386539380735LLU,2305832013039419391LLU,15999LLU},{16122846498982067963LLU,18374686205867458559LLU,54768LLU}};

uint_fast8_t X[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[15][3] = {{14635442048127537665LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,65535LLU}};

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

    } else {
        A[i][0] = A[i-1][0] & D[i][0];
        A[i][1] = A[i-1][1] & D[i][1];
        A[i][2] = A[i-1][2] & D[i][2];

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,5],[1,8],[2,6],[3,7],[3,8],[4,5],[4,6],[4,7],[5,6],[5,8],[7,8]]\n", fout);
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

