#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_491_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][4] = {{18014398475927553LLU,18446743798831644672LLU,18445618173869817855LLU,1099511627775LLU},{2251799813685247LLU,18446743798831644672LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,274877906943LLU,18446744073642442752LLU,1099511627775LLU},{18446744073675997184LLU,18446743523953737727LLU,18445618173869817853LLU,1099511627775LLU},{18430981475047309311LLU,18446744073709551615LLU,1125899906842623LLU,1099511626752LLU},{18444492273895866368LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{8610882487532388351LLU,238227519351LLU,18446368773762973695LLU,1099511626751LLU},{18446743798898753535LLU,18446744073709551615LLU,13836183955121897472LLU,1099511625727LLU},{18435485349519032319LLU,1099511627775LLU,4611686018427387903LLU,1099511625728LLU},{18014398509473793LLU,18446744073709535232LLU,18446743798898753535LLU,1099510583295LLU},{18446744073676005375LLU,18446743798831661055LLU,18445618448680615935LLU,1099244240895LLU},{18444492548840882175LLU,1099511627775LLU,1125899839733763LLU,1099511626752LLU},{18014398507810689LLU,18446744072698986492LLU,18446687994388676607LLU,1097632518143LLU},{18446740774772007039LLU,18446678103011868675LLU,9216616366830780175LLU,1084478259198LLU},{14123288431433357799LLU,18446744073642458175LLU,18446726704056500223LLU,1043661324287LLU},{18446532941674184703LLU,18176527821256523775LLU,18013290201760202751LLU,892833103775LLU},{18446709434865418239LLU,18442241573593808895LLU,4540754324296286211LLU,794364477424LLU},{18444527187685015551LLU,4503599627370495LLU,13907115649252999167LLU,480230820879LLU},{288199586068037511LLU,18442310842826358780LLU,18383693674899816703LLU,806243745777LLU},{288200685713875335LLU,18442455978361208892LLU,9162573180160688911LLU,794568114162LLU},{18444773508353916927LLU,288230376084865023LLU,14411502314845110271LLU,514846481535LLU}};

static uint_fast64_t D[21][4] = {{18444492548840882175LLU,1099511627775LLU,1125899839733763LLU,1099511626752LLU},{18444492548840882174LLU,12297829199221096447LLU,18446744073687181993LLU,1099511627775LLU},{11065344009504292865LLU,18446743908782807449LLU,18446744073709551615LLU,1099511627775LLU},{18430981475013754879LLU,6148915424244269055LLU,1125899862103383LLU,1099511626752LLU},{7385903388887613439LLU,18446743139124668006LLU,18445618173869817852LLU,1099511627775LLU},{7383651589073928191LLU,6148915039415199334LLU,18446744073664812374LLU,1099511627775LLU},{15992282001925909163LLU,18446743927108001245LLU,13836183955189006335LLU,1099511625727LLU},{3683944220299973973LLU,18446744018733970227LLU,18446368773762973695LLU,1099511626751LLU},{14771806777752857259LLU,18446743853807226060LLU,18445993473816395772LLU,1099511625727LLU},{18444838937282215935LLU,882491122197200895LLU,9933814878008573171LLU,1099244240029LLU},{18446397685268217855LLU,17564254051023978495LLU,8514055095540712207LLU,1099510583138LLU},{18014398475927553LLU,18446743798831644672LLU,18445618173869817855LLU,1099511627775LLU},{18445473432935071743LLU,4395443967081054207LLU,2009731333662965507LLU,1084369141182LLU},{18446106279117488127LLU,14933725257117466623LLU,17140644106666310911LLU,1097475292893LLU},{18446477959414939647LLU,18159586820906549247LLU,17901808518796676927LLU,893084135302LLU},{14122997025284815335LLU,17581195326184750143LLU,8626645033880122319LLU,1043676635003LLU},{18176528096058965625LLU,18446744056529944515LLU,18446463685158240255LLU,480230821887LLU},{288230376126513543LLU,18446743816011251772LLU,18445898562421129215LLU,794364477439LLU},{18445477281688845951LLU,4395513220144562115LLU,15852446375036059647LLU,478846713279LLU},{18444843885680164863LLU,882705509785010175LLU,14555353620132462591LLU,480168115359LLU},{4611666224776996767LLU,18443313339732837372LLU,18405367042753417023LLU,678402949110LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][4] = {{18444492548840882175LLU,1099511627775LLU,1125899839733763LLU,1099511626752LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU}};

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
        A[i][3] = A[i-1][3] & C[i][3];

    } else {
        A[i][0] = A[i-1][0] & D[i][0];
        A[i][1] = A[i-1][1] & D[i][1];
        A[i][2] = A[i-1][2] & D[i][2];
        A[i][3] = A[i-1][3] & D[i][3];

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,4],[3,6],[4,6],[5,7],[5,8],[6,9],[7,10],[7,11],[8,12],[8,13],[9,10],[9,12],[10,11],[11,13],[12,13]]\n", fout);
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
