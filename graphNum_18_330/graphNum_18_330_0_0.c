#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_18_330_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 17;
static uint_fast32_t endhere = 0;
char str[28] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[18][3] = {{17906312118424600575LLU,68719476735LLU,1152851410738609920LLU},{1099511627775LLU,18446744073709486080LLU,1152921504606846975LLU},{18446744073709551615LLU,65535LLU,1152921504606846960LLU},{18446744073709535232LLU,8637191418688700415LLU,1152921504606715917LLU},{18428730774711713791LLU,18446744073709551615LLU,1152921503533236223LLU},{18014398509465601LLU,18446744073709486080LLU,1152921504606715919LLU},{18446743513182765055LLU,18446744004990107005LLU,1152921230160875007LLU},{18446742974197923840LLU,18446744073709551615LLU,1152921504606846975LLU},{18446675903971862143LLU,18389322353826846679LLU,1151823917120356339LLU},{1134976375346692035LLU,18446744073642704895LLU,1136032988828532735LLU},{10836614133579713LLU,3746770589600186367LLU,1136004968457698831LLU},{18446678102996140095LLU,18446744005258444800LLU,1151865715746013695LLU},{18336405831299266559LLU,18442240529904169983LLU,1094089111171088335LLU},{18014257771791908735LLU,4503598821277683LLU,935486483134413616LLU},{14986888840067538931LLU,17365880163136651263LLU,789246897879973887LLU},{4594787628512935375LLU,18446727580972220223LLU,544934956904607743LLU},{8926120442671922207LLU,18446744069683019520LLU,432099212956524912LLU},{16068227740712551415LLU,18442521884634317055LLU,827815499143192543LLU}};

static uint_fast64_t D[18][3] = {{1142088275244079491LLU,18446744073709501500LLU,1152921230160875007LLU},{18446743426946859006LLU,7393053054962630655LLU,1152921504606846969LLU},{1116894453862203393LLU,18446744073709524630LLU,1152921504606846975LLU},{18428730774711697407LLU,15958467346257412095LLU,1152921503533236215LLU},{17329851366121668607LLU,3732415091178236265LLU,1152921504606715916LLU},{18446743426946859007LLU,14714328982531342335LLU,1152921503533236211LLU},{17881117736515937917LLU,18446744073709541335LLU,1152851410738609935LLU},{17329850266610040831LLU,11053691018746947945LLU,1152921504606846966LLU},{576460752303423427LLU,3746770589533109629LLU,1136032989898001663LLU},{17906312118425085567LLU,18374966855405126595LLU,1151823917124367104LLU},{18446677542468845567LLU,18389322285174489087LLU,1151865715102318579LLU},{18439566203098267647LLU,71777218505998335LLU,1136004968027914239LLU},{8061191819447230235LLU,18446744072903409648LLU,935552289010022911LLU},{11525247940463423975LLU,18446744060812062783LLU,1094093124717744127LLU},{18122476104443720959LLU,18446726534136853263LLU,557988097963173728LLU},{18230536107215146879LLU,17294103991734439923LLU,791984685117242271LLU},{16065747190147776503LLU,17361394155683577855LLU,821894835034390495LLU},{8921489093338824671LLU,1152905011881312255LLU,422159129347227504LLU}};

uint_fast8_t X[18] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[18][3] = {{1142088275244079491LLU,18446744073709501500LLU,1152921230160875007LLU},{18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,6],[3,7],[4,6],[4,8],[5,6],[5,9],[7,10],[7,11],[8,10],[8,11],[9,10],[9,11]]\n", fout);
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

