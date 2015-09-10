#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_369_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][3] = {{18446726481791940615LLU,18374966859431669775LLU,63LLU},{18446726481527701503LLU,18446744073709551615LLU,63LLU},{17592186044415LLU,18446744073709551612LLU,63LLU},{18446708889337460736LLU,18446744073709547523LLU,63LLU},{18446744073696970751LLU,18446744073705361407LLU,63LLU},{18446726481540282369LLU,18446744073709547523LLU,63LLU},{70368739987455LLU,18446744073705361404LLU,63LLU},{18446744073659219965LLU,18446744071566262267LLU,63LLU},{18446726481590614019LLU,18446742976345403399LLU,63LLU},{281474972524543LLU,18446744071562076156LLU,63LLU},{18446744073508225019LLU,18446463696096985079LLU,63LLU},{18446744073705357312LLU,18446744073709551615LLU,63LLU},{1125899902664703LLU,18446463696101195772LLU,63LLU},{18446744005258510215LLU,17361657974065463055LLU,63LLU},{18446726550242982015LLU,1085366479404134655LLU,63LLU},{18159639597464436735LLU,13546811186329960447LLU,60LLU},{288230376147779583LLU,17221501090256912380LLU,51LLU},{14987966361722420199LLU,18193662322364905423LLU,43LLU},{18433232385769176735LLU,17569665658260520255LLU,30LLU},{18446742991375695423LLU,14972075982110850172LLU,23LLU},{18230554795699993071LLU,4557070243561599967LLU,45LLU}};

static uint_fast64_t D[21][3] = {{1125899902664703LLU,18446463696101195772LLU,63LLU},{12297817654344814590LLU,18446744073709551614LLU,63LLU},{18446738209644736513LLU,18446744073709551615LLU,63LLU},{6148961603720052735LLU,18446744073705361405LLU,63LLU},{18446679569038573567LLU,18446744073709547523LLU,63LLU},{70368739987455LLU,18446744073705361404LLU,63LLU},{18446726481540282369LLU,18446744073709547523LLU,63LLU},{18446532967477014527LLU,18446742976345403391LLU,63LLU},{281474972524543LLU,18446744071562076156LLU,63LLU},{18446726481590614019LLU,18446742976345403399LLU,63LLU},{18445899648779411455LLU,18374967954644131839LLU,63LLU},{6148932283429552127LLU,18446744073709551613LLU,63LLU},{18446726481791940615LLU,18374966859431669775LLU,63LLU},{17362502463417597951LLU,1152753278041833468LLU,63LLU},{1085367510194618367LLU,17365768012097290239LLU,63LLU},{18446730621066672951LLU,17178698646498047599LLU,51LLU},{18446739934434819279LLU,13518116793419299231LLU,60LLU},{18429854750471044863LLU,11520063672250482172LLU,30LLU},{13907102455179639807LLU,8034359612351313919LLU,43LLU},{14717763579024834543LLU,18013787172057186271LLU,45LLU},{4598175168002490303LLU,17795760586308419452LLU,23LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][3] = {{1125899902664703LLU,18446463696101195772LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,63LLU}};

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
        A[i][2] = A[i-1][2] & C[i][2];

    } else {
        A[i][0] = A[i-1][0] & D[i][0];
        A[i][1] = A[i-1][1] & D[i][1];
        A[i][2] = A[i-1][2] & D[i][2];

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,3],[2,4],[3,5],[4,5],[4,6],[5,7],[6,7],[6,8],[7,9],[8,10],[8,11],[9,12],[9,13],[10,12],[10,13],[11,12],[11,13]]\n", fout);
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

