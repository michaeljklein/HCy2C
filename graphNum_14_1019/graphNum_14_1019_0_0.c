#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_14_1019_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 13;
static uint_fast32_t endhere = 0;
char str[24] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[14][3] = {{1152921504606846975LLU,18446743936270598144LLU,4294967295LLU},{17293822571250188287LLU,18446744073709551615LLU,4294967295LLU},{18446744071562067968LLU,18446744073709551615LLU,4294967295LLU},{18446744073709551615LLU,17293822706541658111LLU,4294967295LLU},{1134625495761809377LLU,1148408971447500798LLU,4294967280LLU},{18446744072079540223LLU,17364084908137318337LLU,4294950927LLU},{18264906978007424799LLU,18437577445268783103LLU,4290789375LLU},{18446678103011883263LLU,18446744073707518015LLU,4030726143LLU},{13835058055282032640LLU,13835027264627801855LLU,4021747709LLU},{18437877609795813375LLU,18446744073709543415LLU,3758095887LLU},{18137948416946957817LLU,1146438646610526207LLU,3204446143LLU},{1152920559714041767LLU,18446744073443213310LLU,2147254256LLU},{17302829768357316607LLU,18446744073709502415LLU,4026515967LLU},{18446740762289766267LLU,2305842872043175935LLU,3217293311LLU}};

static uint_fast64_t D[14][3] = {{17375115852024252877LLU,18396754640113762303LLU,4294967295LLU},{4611686016763822078LLU,18083601448569140477LLU,4294967295LLU},{16068761513891987455LLU,17706954628109527898LLU,4294967295LLU},{17284668838448592435LLU,18446744073438928807LLU,4294967295LLU},{18301502984646803455LLU,17581806628877895679LLU,4151286495LLU},{18446673706911528961LLU,4598148831266209791LLU,4254400505LLU},{1152921504053198847LLU,17075960937128654848LLU,4211074871LLU},{18391856453249126399LLU,16140899001288359935LLU,4294671854LLU},{18437807243198988287LLU,17706956829297200114LLU,3758095887LLU},{11457145864208777215LLU,13835025063440121439LLU,4021747709LLU},{18446743248002088895LLU,17582052944985982975LLU,2013011711LLU},{18011003217543904767LLU,18444527432498151423LLU,3195007903LLU},{9223372036619894783LLU,9189594936367380990LLU,3722313723LLU},{17865744466808077295LLU,17329851366121668607LLU,1946144375LLU}};

uint_fast8_t X[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[14][3] = {{17375115852024252877LLU,18396754640113762303LLU,4294967295LLU},{18446744073709551615LLU,18446744073709551615LLU,4294967295LLU},{18446744073709551615LLU,18446744073709551615LLU,4294967295LLU},{18446744073709551615LLU,18446744073709551615LLU,4294967295LLU},{18446744073709551615LLU,18446744073709551615LLU,4294967295LLU},{18446744073709551615LLU,18446744073709551615LLU,4294967295LLU},{18446744073709551615LLU,18446744073709551615LLU,4294967295LLU},{18446744073709551615LLU,18446744073709551615LLU,4294967295LLU},{18446744073709551615LLU,18446744073709551615LLU,4294967295LLU},{18446744073709551615LLU,18446744073709551615LLU,4294967295LLU},{18446744073709551615LLU,18446744073709551615LLU,4294967295LLU},{18446744073709551615LLU,18446744073709551615LLU,4294967295LLU},{18446744073709551615LLU,18446744073709551615LLU,4294967295LLU},{18446744073709551615LLU,18446744073709551615LLU,4294967295LLU}};

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
    fputs("[[0,2],[0,4],[0,5],[0,6],[1,3],[1,4],[1,5],[1,6],[2,4],[2,6],[3,5],[3,6],[4,6],[5,6]]\n", fout);
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

