#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_14_1023_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 13;
static uint_fast32_t endhere = 0;
char str[24] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[14][4] = {{17365810893871382527LLU,17941149044806516687LLU,18446708906517327487LLU,63LLU},{1099511627775LLU,18446744073709518848LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18437736874454843391LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,9007199254740991LLU,18446744073692774400LLU,63LLU},{18446743865939719160LLU,9160320230100598783LLU,18446744056542150638LLU,63LLU},{18446742974197923840LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18445687694290800583LLU,14411518807585580351LLU,18410750461061757433LLU,63LLU},{10341390644269809215LLU,18446251479112089598LLU,36028797018963967LLU,63LLU},{18446462598732709888LLU,9223371900489563644LLU,17248540281049972728LLU,60LLU},{18424188691909050367LLU,18014398509481966559LLU,4395506508232654535LLU,51LLU},{18302060438390571007LLU,18446733216029081595LLU,18444772786397249535LLU,15LLU},{36028624146462461LLU,18392700878181105656LLU,16717343674337216510LLU,45LLU},{18446744073574809563LLU,18438299822260256775LLU,18415218790955483135LLU,51LLU},{17581709897589719551LLU,18446691176862973949LLU,18446498882549448703LLU,60LLU}};

static uint_fast64_t D[14][4] = {{18446743042917400064LLU,9223370921237014014LLU,14923768075155161080LLU,63LLU},{18446743441784937326LLU,6620287216170008575LLU,18446744073696427915LLU,63LLU},{18388089059336283893LLU,17708153734820770207LLU,18446744073707287796LLU,63LLU},{16859493485389544859LLU,18446084205632749552LLU,18446744073709551615LLU,63LLU},{18410716358921650175LLU,18446185521802641407LLU,8788057481994565759LLU,63LLU},{1645906234617888767LLU,12565707064505126511LLU,18446744073708161919LLU,63LLU},{9295429630876188671LLU,18446744073172713471LLU,13186519340037435375LLU,63LLU},{18446744065656472575LLU,13842939045392416527LLU,18441887323953037311LLU,63LLU},{13591855978822762495LLU,17936416746521206735LLU,4611684927489961599LLU,23LLU},{9222386874436288511LLU,17257791573597351800LLU,17291605953157454847LLU,45LLU},{15557632136193245183LLU,4609258296677628159LLU,18185528695031070656LLU,58LLU},{18446743519407103951LLU,15843665688112660479LLU,9045475350439002075LLU,51LLU},{18446744013569408639LLU,18446743446491234303LLU,16428400540292988991LLU,45LLU},{13808035426725789695LLU,18441957899325114367LLU,2286702697627271167LLU,23LLU}};

uint_fast8_t X[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[14][4] = {{18446743042917400064LLU,9223370921237014014LLU,14923768075155161080LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU}};

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
        A[i][3] = A[i-1][3] & C[i][3];

    } else {
        A[i][0] = A[i-1][0] & D[i][0];
        A[i][1] = A[i-1][1] & D[i][1];
        A[i][2] = A[i-1][2] & D[i][2];
        A[i][3] = A[i-1][3] & D[i][3];

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
    fputs("[[0,2],[0,3],[0,5],[0,6],[1,3],[1,4],[1,5],[1,6],[2,4],[2,5],[2,6],[3,5],[3,6],[4,6]]\n", fout);
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

