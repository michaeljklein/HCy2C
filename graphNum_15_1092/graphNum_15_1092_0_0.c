#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_15_1092_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 14;
static uint_fast32_t endhere = 0;
char str[25] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[15][3] = {{4611686018427387903LLU,18446743798831644672LLU,65535LLU},{13835058057429647359LLU,18446744073709551615LLU,65535LLU},{18446744071562067968LLU,18446744073709551615LLU,65535LLU},{9223372036854773760LLU,18446462701132045791LLU,65535LLU},{18446739677810526207LLU,18158795172534550527LLU,65535LLU},{13835062453328672769LLU,18446462873610747903LLU,65535LLU},{4539602036110393343LLU,9511566404000415744LLU,65535LLU},{18446744073705345023LLU,9204512938537517055LLU,65520LLU},{2296835663904783295LLU,18119107200818347968LLU,65295LLU},{18446664857330778111LLU,16703849643523698751LLU,63743LLU},{18067720425382608895LLU,11529084702136471551LLU,51199LLU},{4607463893776691175LLU,18445323500458606588LLU,49100LLU},{18446744073554026495LLU,18313324664165711619LLU,32563LLU},{573003887745694191LLU,18446592958774115535LLU,64853LLU},{18446740738934271999LLU,12527606785186264060LLU,39935LLU}};

static uint_fast64_t D[15][3] = {{14791747523228577793LLU,18446744073709551615LLU,65535LLU},{9223372036430254078LLU,18446743895844231578LLU,65535LLU},{12878368587760271359LLU,18446743976696964709LLU,65535LLU},{18446739677810524159LLU,18158795161761314677LLU,65535LLU},{3654996553052979199LLU,18446462614892694735LLU,65535LLU},{18446744073285029887LLU,18158795156374696752LLU,65535LLU},{17142632499296322755LLU,9204513213415161855LLU,65520LLU},{16023775115320605501LLU,9511566404000677887LLU,65535LLU},{18014149468957441787LLU,9223298369508868095LLU,51967LLU},{18414374245197938583LLU,18392678836207615999LLU,63402LLU},{14985727695648719343LLU,18429011150176780287LLU,64853LLU},{17906311276376227455LLU,15487773565410819903LLU,28415LLU},{18442241537622409185LLU,12682119233367179263LLU,39935LLU},{18446739742237130751LLU,11258999068375662591LLU,51199LLU},{13839561654909532191LLU,18446479933220847567LLU,32563LLU}};

uint_fast8_t X[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[15][3] = {{14791747523228577793LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,65535LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,7],[2,8],[3,4],[3,5],[4,5],[4,6],[4,7],[5,6],[5,8],[6,7],[6,8]]\n", fout);
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

