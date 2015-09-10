#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_485_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][4] = {{18014398475927553LLU,18446743798831644672LLU,18445618173869817855LLU,1099511627775LLU},{2251799813685247LLU,18446743798831644672LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,274877906943LLU,18446744073642442752LLU,1099511627775LLU},{18446744073675997184LLU,18446743523953737727LLU,18445618173869817853LLU,1099511627775LLU},{18430981475047309311LLU,18446744073709551615LLU,1125899906842623LLU,1099511626752LLU},{18444492273895866368LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{8610882487532388351LLU,238227519351LLU,18446368773762973695LLU,1099511626751LLU},{18446743798898753535LLU,18446744073709551615LLU,13836183955121897472LLU,1099511625727LLU},{18435485349519032319LLU,1099511627775LLU,4611686018427387903LLU,1099511625728LLU},{18014398509479937LLU,18446744073709550592LLU,18446744005057183743LLU,1099511107583LLU},{18446744073675999231LLU,18446743798831645695LLU,18445618242522185727LLU,1099445043199LLU},{18444492548840882175LLU,1099511627775LLU,1125899839733763LLU,1099511626752LLU},{18176528096059451385LLU,18446744056596775935LLU,18446479984559128575LLU,1098504933375LLU},{288222678630791175LLU,18446466996779351040LLU,9207609369707936783LLU,1083405041660LLU},{18445600442030098431LLU,4608308318702666751LLU,16104867938099515391LLU,1047364369911LLU},{288230376118288263LLU,18446743798835838972LLU,18445622567822688255LLU,890069057535LLU},{18444500796184723455LLU,281474976710655LLU,13853072453724537855LLU,1098504932355LLU},{18446737475834353791LLU,18446480190914706435LLU,18433229087234325567LLU,1035083579388LLU},{14123288431431884391LLU,18446744072639758275LLU,18446677264687955967LLU,750531903487LLU},{4611580452394762143LLU,18379189805494829052LLU,18229515757211631615LLU,409984819151LLU},{18444632753684611071LLU,72057593031294975LLU,14123235654808895487LLU,755100499007LLU}};

static uint_fast64_t D[21][4] = {{18444492548840882175LLU,1099511627775LLU,1125899839733763LLU,1099511626752LLU},{18444492548840882174LLU,12297829199221096447LLU,18446744073687181993LLU,1099511627775LLU},{11065344009504292865LLU,18446743908782807449LLU,18446744073709551615LLU,1099511627775LLU},{18430981475013754879LLU,6148915424244269055LLU,1125899862103383LLU,1099511626752LLU},{7385903388887613439LLU,18446743139124668006LLU,18445618173869817852LLU,1099511627775LLU},{7383651589073928191LLU,6148915039415199334LLU,18446744073664812374LLU,1099511627775LLU},{15992282001925909163LLU,18446743927108001245LLU,13836183955189006335LLU,1099511625727LLU},{3683944220299973973LLU,18446744018733970227LLU,18446368773762973695LLU,1099511626751LLU},{14771806777752857259LLU,18446743853807226060LLU,18445993473816395772LLU,1099511625727LLU},{18445423948872024063LLU,4378621439176081407LLU,11131772378901843955LLU,1099445042599LLU},{18445812673678409727LLU,14068123734045097983LLU,7316097594647441423LLU,1099511107160LLU},{18014398475927553LLU,18446743798831644672LLU,18445618173869817855LLU,1099511627775LLU},{18446735826365710335LLU,18446463698244468735LLU,4594797519824747523LLU,1083364605948LLU},{18445424498687076351LLU,4378624720598189055LLU,15744320208286978047LLU,1098479304103LLU},{287877389835304839LLU,17527996555586437116LLU,8500544292631936975LLU,890131881823LLU},{18445022028315492351LLU,1148435497165520895LLU,14920425565415522367LLU,1047367609584LLU},{288230376126027783LLU,18446743815944420352LLU,18445882263020240895LLU,1083364605951LLU},{18446216243695845375LLU,17298326151617314815LLU,17365616280345788415LLU,892925353743LLU},{18446607717624709119LLU,18374756848415801343LLU,18167520896812318975LLU,515194474433LLU},{18445052818399141503LLU,1152868728048467907LLU,14983475122680102719LLU,802620800254LLU},{4611681619818740127LLU,18446532709775047740LLU,18436889096228961535LLU,504622743549LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,4],[3,6],[4,6],[5,7],[5,8],[6,9],[7,9],[7,10],[8,10],[8,11],[9,12],[10,13],[11,12],[11,13],[12,13]]\n", fout);
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

