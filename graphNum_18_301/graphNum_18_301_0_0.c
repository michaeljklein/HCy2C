#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_18_301_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 17;
static uint_fast32_t endhere = 0;
char str[28] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[18][3] = {{18374686480745349121LLU,18446744065120665599LLU,4095LLU},{18374686479940059135LLU,18446744073709551615LLU,4095LLU},{72057594037927935LLU,18446744073708503040LLU,4095LLU},{18302628885633679360LLU,18446744065120665599LLU,4095LLU},{18446744072904261631LLU,18446673713555308543LLU,4095LLU},{18446744073441116160LLU,18446744073709551615LLU,4095LLU},{288230375883309055LLU,18446673713554259968LLU,4095LLU},{18446742975271665601LLU,18428800043911741439LLU,4095LLU},{18374687579183235135LLU,13853072445235265535LLU,4095LLU},{288230376150695935LLU,1855482780188671984LLU,4092LLU},{18446744073442164735LLU,18445618448679567375LLU,4035LLU},{1152920409389203395LLU,4594797262095253488LLU,4092LLU},{18446463492052483119LLU,18176519299462545407LLU,3886LLU},{18374967941761319931LLU,9511601855195512639LLU,3323LLU},{18443366373972768767LLU,17861060754237550595LLU,2803LLU},{4611672824036065151LLU,18407553046821212159LLU,1935LLU},{1098878244519469043LLU,2301867119326003199LLU,1535LLU},{18446531936675691983LLU,18288974943787938800LLU,2940LLU}};

static uint_fast64_t D[18][3] = {{288230375883309055LLU,18446673713554259968LLU,4095LLU},{12249790986179346430LLU,18446744073709202090LLU,4095LLU},{18422724875517919233LLU,18446744073709551615LLU,4095LLU},{6341068274532351999LLU,18446673713554609493LLU,4095LLU},{18182532896286310399LLU,18446744065120665599LLU,4095LLU},{6220972285721837567LLU,18446744073708852565LLU,4095LLU},{18374686480745349121LLU,18446744065120665599LLU,4095LLU},{17582052945147428863LLU,13853044407654956095LLU,4095LLU},{1152921504445431807LLU,18428757729925645248LLU,4095LLU},{18429789601188013693LLU,18445688539123286015LLU,4035LLU},{18391640953266887043LLU,1855483041311358975LLU,4092LLU},{18429789604302284415LLU,16609247384773082175LLU,4035LLU},{14987979546866155515LLU,13824255473795464963LLU,3323LLU},{4611685812209844207LLU,18439550965552972796LLU,3886LLU},{4557626072526348071LLU,6861233993530998783LLU,1982LLU},{18442310005307208155LLU,12817244400159555571LLU,2813LLU},{18443102491152217343LLU,17653957705699635455LLU,2919LLU},{18379176884956024703LLU,14951334480092135231LLU,1499LLU}};

uint_fast8_t X[18] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[18][3] = {{288230375883309055LLU,18446673713554259968LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,4095LLU},{18446744073709551615LLU,18446744073709551615LLU,4095LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,3],[2,4],[3,5],[4,6],[4,7],[5,6],[5,8],[6,9],[7,10],[7,11],[8,10],[8,11],[9,10],[9,11]]\n", fout);
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

