#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_15_88_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 14;
static uint_fast32_t endhere = 0;
char str[25] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[15][5] = {{36028797018963967LLU,18428729675200069632LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18410715276690587648LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18014398509481983LLU,18446708889337462784LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,35184372088831LLU,18446744073692774400LLU,1073741823LLU},{18443923792023613425LLU,13853072453791645695LLU,18086205263932456959LLU,18446743523969424639LLU,1073741823LLU},{13848348603536375807LLU,18443292679865401343LLU,6339097950500683775LLU,18374687029414658022LLU,1073741823LLU},{4610542526334492431LLU,4611391349311143680LLU,18286865135752445824LLU,72057594037924857LLU,1073741760LLU},{18446744072040216831LLU,18446744073542795519LLU,18446744073708093567LLU,18446744073709551615LLU,1073479743LLU},{9223372036854644736LLU,18437692824796249054LLU,18189898157461078015LLU,17942340630800236475LLU,1071839158LLU},{18302626686610571263LLU,18446673704965373951LLU,14122162119176650239LLU,18443349245659422719LLU,1042259583LLU},{18122487099562131455LLU,9151314439058620409LLU,18446744071595622398LLU,14410973449415557119LLU,838860799LLU},{18446603336221196283LLU,17906311568669310975LLU,18446530759863826431LLU,18437666501432442247LLU,771224575LLU},{18446744058676379607LLU,14393504958831919103LLU,18446744073707388915LLU,9223369292370673663LLU,530579452LLU},{14411518807310731263LLU,18446744073440329726LLU,18446708891484946431LLU,17942903865330368511LLU,1071906815LLU},{18302626703790309179LLU,18014397964021137159LLU,18446744073680191375LLU,18446730875811921919LLU,780140483LLU}};

static uint_fast64_t D[15][5] = {{18433737778777557357LLU,18428729675200069631LLU,12167542115809843644LLU,18446744073706346239LLU,1073741823LLU},{10304235947423694847LLU,10044410028193402223LLU,18425832367571576535LLU,18446744073700764108LLU,1073741823LLU},{9164322956915507198LLU,18436354570289361819LLU,6300113666226257919LLU,18446744073704767283LLU,1073741823LLU},{17437935538011895443LLU,8430737947445821172LLU,18446744071520976747LLU,18446744073709551615LLU,1073741823LLU},{17943752874131455LLU,18446744073709518848LLU,6917527928128405503LLU,12350795423097552888LLU,1073593583LLU},{18445054124337657857LLU,17732923398553599LLU,18230571291595751424LLU,16068843149106082047LLU,1073670036LLU},{18439847936713129983LLU,18443296005211324415LLU,17582048409231589375LLU,18418384696694824935LLU,1073699711LLU},{18446713180009779199LLU,18446727554191589375LLU,18428764794937933823LLU,8502208952233099263LLU,1073741819LLU},{17942340915444056063LLU,18443926832844435327LLU,18445055221701820415LLU,18446181604783919086LLU,985636863LLU},{2305843009213693951LLU,2183951145897009144LLU,18439765447638247422LLU,13907115373937031577LLU,904329215LLU},{17293822569102704639LLU,17005468944562649551LLU,13853071972755307735LLU,18443366347145478143LLU,1062993462LLU},{18418578966739606479LLU,18446744073709551615LLU,14833713370016243185LLU,4573120648068446207LLU,530431740LLU},{18446497370767080831LLU,18446744073709551615LLU,4611682169851212734LLU,16991967044859592576LLU,771224047LLU},{18444772089907380223LLU,18445758496801548091LLU,18446744073709551615LLU,16140900959000690815LLU,985632733LLU},{16107124067290479615LLU,16124012565893193727LLU,18446713285773348863LLU,18392278253382434815LLU,401375231LLU}};

uint_fast8_t X[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[15][5] = {{18433737778777557357LLU,18428729675200069631LLU,12167542115809843644LLU,18446744073706346239LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU}};

#if UINTPTR_MAX == 0xffffffffffffffff // 64-bit. Hopefully this means the cpu has 'popcnt'.
int counter (uint64_t * buf){
    uint64_t cnt[15];
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
    __asm__(
           "popcnt %1, %1  \n\t"
           "add %1, %0     \n\t"
            : "+r" (cnt[14])
            : "r" (buf[14]));


    return cnt[0] + cnt[1] + cnt[2] + cnt[3] + cnt[4] + cnt[5] + cnt[6] + cnt[7] + cnt[8] + cnt[9] + cnt[10] + cnt[11] + cnt[12] + cnt[13] + cnt[14];
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
        A[i][4] = A[i-1][4] & C[i][4];

    } else {
        A[i][0] = A[i-1][0] & D[i][0];
        A[i][1] = A[i-1][1] & D[i][1];
        A[i][2] = A[i-1][2] & D[i][2];
        A[i][3] = A[i-1][3] & D[i][3];
        A[i][4] = A[i-1][4] & D[i][4];

    }
}

void printout(){
    sprintf(str, "[               ,%5d]\n", this);
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
    fputs("[[0,2],[0,3],[0,4],[0,6],[1,3],[1,4],[1,5],[1,6],[2,4],[2,5],[2,6],[3,5],[3,6],[4,6],[5,6]]\n", fout);
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

