#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_14_66_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 13;
static uint_fast32_t endhere = 0;
char str[24] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[14][3] = {{18446744066642894847LLU,8664863232593228287LLU,18014397436787918LLU},{8589934591LLU,18446744073709551552LLU,18014398509481983LLU},{18446744073709551615LLU,18446742974197923903LLU,18014398509481983LLU},{18446744073709551615LLU,1099511627775LLU,18014398509480960LLU},{17870274533894647777LLU,18444484577314340413LLU,18014398508434431LLU},{18446744065119617024LLU,18446744073709551615LLU,18014398509481983LLU},{18445626969727958815LLU,14406522626748973043LLU,18013849827409919LLU},{14844990271719913727LLU,18446744073474379775LLU,17733473288585215LLU},{18446744073709549568LLU,16132733750256123647LLU,17925714950403963LLU},{283725677008521215LLU,18095428118402564095LLU,17166675011829759LLU},{18446708846391984127LLU,18446744073689102272LLU,14636691306311679LLU},{18419722208843660793LLU,4609426522032308205LLU,12358510561952760LLU},{13258377675530694567LLU,18446744065387920959LLU,8725672733212671LLU},{9222527405762543483LLU,18446742982787858431LLU,12947367867162623LLU}};

static uint_fast64_t D[14][3] = {{18302628894223628289LLU,18439988674268102655LLU,17925714950404095LLU},{18446744066642894846LLU,6790007234581413119LLU,18014398509481579LLU},{18108961996920582605LLU,12954497675503337409LLU,18014398509481975LLU},{574947446341545523LLU,18446744064799926206LLU,18014398509481983LLU},{16140901059997368319LLU,13871086027401068535LLU,17866775565696255LLU},{18209578711223631871LLU,17148983246243978111LLU,18014398509481372LLU},{16717361814114897919LLU,9205357638345261119LLU,17969318128647118LLU},{18446744073649520639LLU,18446182170116489209LLU,18014310416470015LLU},{144115188075855871LLU,18014345147709387712LLU,18014397436788190LLU},{18356614855017889791LLU,14987550750350016511LLU,14548730342008633LLU},{18439283200120324095LLU,18375249216822812287LLU,17165953489747967LLU},{11529003935540477887LLU,18410715268104847359LLU,8582727093714175LLU},{18419722474936598015LLU,72056769402109927LLU,12353833258713080LLU},{18338651078066699247LLU,18446744073709551583LLU,6509108030340103LLU}};

uint_fast8_t X[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[14][3] = {{18302628894223628289LLU,18439988674268102655LLU,17925714950404095LLU},{18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU}};

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
    fputs("[[0,2],[0,4],[0,5],[0,6],[1,3],[1,4],[1,5],[1,6],[2,4],[2,5],[2,6],[3,5],[3,6],[5,6]]\n", fout);
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

