#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_14_11_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 13;
static uint_fast32_t endhere = 0;
char str[24] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[14][3] = {{2147483647LLU,18446744073709551615LLU,16777215LLU},{18446744071562067968LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073692774400LLU,16777215LLU},{18446744073405332472LLU,18446743798847364600LLU,16777215LLU},{17293540958821941247LLU,18444492548773642055LLU,16777215LLU},{18439980015614418759LLU,2251799813685247LLU,16777215LLU},{18446744073151446575LLU,13755672491120901687LLU,16777152LLU},{16140762251052187647LLU,17843261689164460541LLU,16773183LLU},{18417611407177527805LLU,18446670403343482879LLU,16519167LLU},{18446744073708503040LLU,18194542425588834303LLU,15978479LLU},{18374668868159275007LLU,18446713283055452159LLU,13631293LLU},{17872535121219813375LLU,17289318953368682235LLU,11501560LLU},{576460752303390459LLU,18446602528767344639LLU,8125895LLU},{18014292853285519359LLU,18444773740215533567LLU,12055547LLU}};

static uint_fast64_t D[14][3] = {{18446744071563240334LLU,18446744073697891734LLU,16777215LLU},{804088439828905983LLU,18446744073704434281LLU,16777215LLU},{17642655636026956913LLU,18446744073709551615LLU,16777215LLU},{18446741876833771391LLU,4085263765426012031LLU,16777215LLU},{18439982076896739264LLU,14361978969269460479LLU,16777215LLU},{17293541094111181823LLU,18446245412739219392LLU,16777215LLU},{18444494472919105533LLU,17870212951604723709LLU,16619135LLU},{18419722468961808447LLU,13762996335926034423LLU,16674766LLU},{16140900789500248047LLU,18412395296098086975LLU,16775601LLU},{5655085968655384575LLU,18446713283050338921LLU,13631293LLU},{13523671341479231487LLU,18194542425588830207LLU,15978479LLU},{18446744072560250879LLU,9060996159656392671LLU,7986431LLU},{18446744073574807519LLU,16427985749530443775LLU,11483007LLU},{9222245035557257215LLU,2305842871222140927LLU,6094815LLU}};

uint_fast8_t X[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[14][3] = {{18446744071563240334LLU,18446744073697891734LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,16777215LLU}};

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
    fputs("[[0,3],[0,4],[0,6],[1,4],[1,5],[1,6],[2,4],[2,5],[2,6],[3,5],[3,6],[4,5],[4,6],[5,6]]\n", fout);
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

