#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_18_1982_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 17;
static uint_fast32_t endhere = 0;
char str[28] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[18][3] = {{18446744073709551615LLU,18158513697557840895LLU,1099511627775LLU},{137438953471LLU,18446744073709550592LLU,1099511627775LLU},{18446743936270598144LLU,18446744073709551615LLU,1099511627775LLU},{18375812379072527743LLU,288229293555711999LLU,1099511627744LLU},{18446744073704303358LLU,18432319563753115647LLU,1099511562271LLU},{71789580025470945LLU,18446744073709551600LLU,1095216726015LLU},{18445618448663838720LLU,18446744073709551615LLU,1086626661345LLU},{18446743936287375359LLU,15708403593136568319LLU,1044687683583LLU},{18375812250226130943LLU,288213621689809935LLU,1047972019263LLU},{18446529668939283783LLU,18389322353624694783LLU,1085953015776LLU},{18446726756401410048LLU,18442521949058830335LLU,1026295063545LLU},{18438880340660457471LLU,16717361816799281055LLU,953482682151LLU},{18383680381304959039LLU,2305829605644172415LLU,996432405753LLU},{18385087730301530175LLU,2882303761517116575LLU,1099511571489LLU},{18137872245088017973LLU,13258597302978739934LLU,824633702069LLU},{18405639844767199743LLU,8070450515072253375LLU,549755776363LLU},{1125762501443583LLU,15852670688344144896LLU,1044687683583LLU},{18446744073707978367LLU,12970366944006897663LLU,824633702069LLU}};

static uint_fast64_t D[18][3] = {{17520128587841804193LLU,18446744073709550748LLU,1099511627775LLU},{18446744073684772958LLU,18278533734055192575LLU,1099511627775LLU},{926615485892526079LLU,18326724037212199779LLU,1099511627775LLU},{4611632410793054200LLU,18432388849897099248LLU,1096985205727LLU},{13835969548307562471LLU,15852670688344145919LLU,1097743138814LLU},{18446744073701685375LLU,2882233392777134079LLU,1099511571489LLU},{926615623331479551LLU,15636270045532779363LLU,1044687683583LLU},{18445618311241662463LLU,18398857584815988735LLU,1086626661345LLU},{18446476067750023104LLU,18374967954647289855LLU,1085616151551LLU},{4611685883135918079LLU,18446727577008602112LLU,1045782461471LLU},{6765532514346860543LLU,16212955307638259591LLU,941658996543LLU},{12601071757382647807LLU,16136454430043079547LLU,996179771391LLU},{6773149956774301695LLU,18163017297181081591LLU,949440471039LLU},{936748722493063167LLU,18158584066297824243LLU,1095216726015LLU},{14987979559889010687LLU,18446744056529683443LLU,545477623807LLU},{4107193522157740021LLU,18158584066302017534LLU,824617009151LLU},{18446744073701550174LLU,18374914340369207295LLU,1086626661345LLU},{14370235902641223659LLU,18446744073709551025LLU,545477623807LLU}};

uint_fast8_t X[18] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[18][3] = {{17520128587841804193LLU,18446744073709550748LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU}};

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
    fputs("[[0,2],[0,8],[0,10],[1,3],[1,9],[1,11],[2,4],[2,8],[3,5],[3,9],[4,5],[4,6],[5,6],[6,7],[7,10],[7,11],[8,9],[10,11]]\n", fout);
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

