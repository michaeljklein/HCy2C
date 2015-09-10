#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_13_2_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 12;
static uint_fast32_t endhere = 0;
char str[23] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[13][3] = {{18446744065119617024LLU,18446744073709551615LLU,4398046511103LLU},{8589934591LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744071562067968LLU,4398046511103LLU},{18446744073709551615LLU,13835058057429647359LLU,4398046511103LLU},{18446744071535841279LLU,4395442800896737248LLU,4398046510848LLU},{17581771203620634105LLU,18445044297452486655LLU,4398046249215LLU},{18439944968681111463LLU,18446744073708760095LLU,4397778337791LLU},{18446744073709549568LLU,17870252259934193535LLU,4393952017663LLU},{16140776819677726719LLU,4606936119605460991LLU,4333610467263LLU},{18427744469836103679LLU,18446744073707339771LLU,3367254348788LLU},{18303754784986890015LLU,18419704832219676671LLU,3160273321955LLU},{144115188075583743LLU,18446744073696960487LLU,2187212078367LLU},{18338587107746381691LLU,9223372034724069375LLU,3246458175471LLU}};

static uint_fast64_t D[13][3] = {{7408407488510296063LLU,15687159926124706221LLU,4398046511103LLU},{18446744067054137342LLU,16644806415885301374LLU,4398046511103LLU},{11238993443839537613LLU,18396579860714618879LLU,4398046511103LLU},{18246087221724683827LLU,18446744073686192083LLU,4398046511103LLU},{18446735285937897441LLU,18445046427755474943LLU,4397838427903LLU},{18439953487748861887LLU,13618814904424201216LLU,4397986217785LLU},{17581771470150827519LLU,9223369839878307839LLU,4398046452166LLU},{18445626969895731199LLU,2154971308156255737LLU,3740908118012LLU},{8619885237201010687LLU,17562912200161362943LLU,3983246618871LLU},{14911416579517317119LLU,18446464797344530223LLU,4370662096831LLU},{18446744069347016703LLU,14987837173116567551LLU,1636246196223LLU},{18446744072767897599LLU,18410996750056619263LLU,3057987221503LLU},{4611116463888006127LLU,13871086852301127679LLU,1372007169917LLU}};

uint_fast8_t X[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[13][3] = {{7408407488510296063LLU,15687159926124706221LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU}};

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
    fputs("[[0,2],[0,3],[0,4],[0,5],[1,3],[1,4],[1,5],[2,3],[2,4],[2,5],[3,4],[3,5],[4,5]]\n", fout);
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

