#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_13_36_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 12;
static uint_fast32_t endhere = 0;
char str[23] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[13][3] = {{18415214512631164909LLU,2875122284675727359LLU,3LLU},{18410715276959023103LLU,18446744073709551615LLU,3LLU},{36028797018963967LLU,18446744073709518848LLU,3LLU},{18446744073709551615LLU,18446739675663073279LLU,3LLU},{9177464950614917119LLU,18446606530502229867LLU,3LLU},{17942340915376488416LLU,18437877601203909087LLU,3LLU},{18443260805840370719LLU,18167520484078387199LLU,3LLU},{14411515938535343103LLU,288230376151683070LLU,3LLU},{3458764513790129983LLU,18131465710990123000LLU,2LLU},{18446744073441116160LLU,18446744073709551615LLU,3LLU},{18302492540588129531LLU,18337989179582970631LLU,1LLU},{18446163529691070463LLU,18446607665480925183LLU,3LLU},{18122625638010191719LLU,18420830783666124793LLU,2LLU}};

static uint_fast64_t D[13][3] = {{4611686012794436671LLU,18311504143488777984LLU,3LLU},{10304235947214951870LLU,18446744045770874271LLU,3LLU},{18440498673180684237LLU,18446743317054423039LLU,3LLU},{17437789850256407155LLU,18446744073709544436LLU,3LLU},{18446741874686263296LLU,7921550260978024959LLU,3LLU},{9223371899675869183LLU,15771526214314884990LLU,3LLU},{13862078828408537087LLU,13256199264897335295LLU,3LLU},{18442390007596449791LLU,18390959251745963979LLU,3LLU},{18302488285584146425LLU,4610697007716629503LLU,1LLU},{9157707750476611583LLU,18446740460256853611LLU,3LLU},{17262297268630841327LLU,16422376024043413503LLU,2LLU},{18426404130797912063LLU,7921547782504022271LLU,3LLU},{16140901064359517695LLU,2233710665564929855LLU,1LLU}};

uint_fast8_t X[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[13][3] = {{4611686012794436671LLU,18311504143488777984LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,3LLU}};

#if UINTPTR_MAX == 0xffffffffffffffff // 64-bit. Hopefully this means the cpu has 'popcnt'.
int counter (uint64_t * buf){
    uint64_t cnt[13];
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
           "popcnt %1, %1  \n\t"
           "add %1, %0     \n\t"
            : "+r" (cnt[12])
            : "r" (buf[12]));


    return cnt[0] + cnt[1] + cnt[2] + cnt[3] + cnt[4] + cnt[5] + cnt[6] + cnt[7] + cnt[8] + cnt[9] + cnt[10] + cnt[11] + cnt[12];
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
    sprintf(str, "[             ,%5d]\n", this);
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
    fputs("[[0,3],[0,4],[0,5],[0,6],[1,3],[1,4],[1,5],[1,6],[2,4],[2,5],[2,6],[3,5],[4,6]]\n", fout);
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

