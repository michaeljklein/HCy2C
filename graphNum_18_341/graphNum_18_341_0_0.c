#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_18_341_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 17;
static uint_fast32_t endhere = 0;
char str[28] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[18][4] = {{72057594037862401LLU,18446744073705357312LLU,18446744073575337983LLU,63LLU},{8796093022207LLU,18446744073705357312LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,4194303LLU,18446744073709547520LLU,63LLU},{18446744073709486080LLU,17725561031104659455LLU,18446744073575335893LLU,63LLU},{18374695275764711423LLU,18446744073709551615LLU,18446739675797258239LLU,63LLU},{18446735277616529408LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18014398506260758527LLU,18446462598736508863LLU,18446185418687238143LLU,63LLU},{18446742974195957759LLU,281474976677886LLU,18375248328091693056LLU,63LLU},{17293277210798488763LLU,18429855575104814319LLU,17324784782315356159LLU,63LLU},{18375240634068885471LLU,18446744069431230459LLU,1152886354594496319LLU,63LLU},{58405645283491585LLU,18230558097456234368LLU,13545552245641187327LLU,60LLU},{18445582980836425983LLU,18446744022165749887LLU,17208218991677407216LLU,51LLU},{18157985928220507647LLU,18429574104425168383LLU,17365352262267822079LLU,63LLU},{9799832789140996083LLU,13835325305324011518LLU,18010457855034802175LLU,46LLU},{18443365209782876159LLU,4611474911943184383LLU,14920424034855284736LLU,27LLU},{11461652324267196407LLU,13853071625131393023LLU,4608278077439442751LLU,46LLU},{9212112711367784207LLU,18230571291394428800LLU,11474045674676350991LLU,29LLU},{11474037695705714679LLU,14123288428208472063LLU,8059170642064277491LLU,39LLU}};

static uint_fast64_t D[18][4] = {{18446740664256430079LLU,1081774563911532543LLU,18446739675797257279LLU,63LLU},{18446740664256430078LLU,11937237861171986431LLU,18446744073709549205LLU,63LLU},{5620504540504522753LLU,18446744073707038923LLU,18446744073709551615LLU,63LLU},{18374695275764645887LLU,6870097733844205567LLU,18446739675797257599LLU,63LLU},{12826251738751172607LLU,17364969509800531764LLU,18446744073575334848LLU,63LLU},{12826242942658150399LLU,6509506212540077876LLU,18446744073709549930LLU,63LLU},{5734188683446216355LLU,18446744073707400942LLU,18375248328091697151LLU,63LLU},{17900713263805471069LLU,18446744073708630427LLU,18446185418687238143LLU,63LLU},{13690942867206299615LLU,17365880158849128377LLU,1152890718223953667LLU,63LLU},{16429131440647535803LLU,18428944921777896550LLU,17324784816463975420LLU,63LLU},{18445579676661579775LLU,1149332630957719551LLU,17208215501344342000LLU,51LLU},{18433092019676905471LLU,18162999978870439935LLU,13545551338196171839LLU,60LLU},{2275441761813776327LLU,17365880163140374520LLU,1122521107580878595LLU,63LLU},{18442486696097338207LLU,18446532967225213851LLU,14987657969910939647LLU,27LLU},{9254681592436047345LLU,18446729848773934591LLU,18014161010574692351LLU,46LLU},{18158197037802188863LLU,18446480139379261447LLU,17757376654185059324LLU,27LLU},{18410603125399043583LLU,14984600761726664191LLU,18230445906098913279LLU,39LLU},{18158091448081186623LLU,18432952899161030535LLU,17545601565328658687LLU,29LLU}};

uint_fast8_t X[18] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[18][4] = {{18446740664256430079LLU,1081774563911532543LLU,18446739675797257279LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU}};

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
        A[i][3] = A[i-1][3] & C[i][3];

    } else {
        A[i][0] = A[i-1][0] & D[i][0];
        A[i][1] = A[i-1][1] & D[i][1];
        A[i][2] = A[i-1][2] & D[i][2];
        A[i][3] = A[i-1][3] & D[i][3];

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,6],[3,7],[4,6],[4,8],[5,9],[5,10],[6,11],[7,8],[7,9],[8,10],[9,11],[10,11]]\n", fout);
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
