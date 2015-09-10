#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_560_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][5] = {{18446744073675997185LLU,65535LLU,18446744073709551615LLU,18446743798831661055LLU,18014398509481983LLU},{18446744073709551615LLU,0LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,0LLU,18446744073709535232LLU,18014398509481983LLU},{18446744073675997184LLU,18446744073709551615LLU,15562012407445323773LLU,18446743798831652725LLU,18014398509481983LLU},{33554431LLU,18446744073709486081LLU,18446744073709551615LLU,13835058330160070655LLU,18014398509481983LLU},{0LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,6770587542107324415LLU,18446744073642442752LLU,4611685791629295615LLU,18014398509477888LLU},{18446743798898753535LLU,18446744073709551615LLU,67108863LLU,18445618448680599552LLU,18014398442377215LLU},{274877906943LLU,18446744073709486083LLU,18446744073642442755LLU,1125899906842623LLU,18014398509477888LLU},{17574593858371581953LLU,18446744004990127167LLU,18446744073709551615LLU,18446744073692778492LLU,18014381358972099LLU},{18446742424408557567LLU,68719476723LLU,14123288362982834175LLU,4611685743566258175LLU,18010017639632895LLU},{16122851479533355007LLU,18433180498269306879LLU,18445618173857037567LLU,17140691655993589759LLU,17981035203006463LLU},{18446730606839594979LLU,18446744073693036543LLU,1125899906842383LLU,18438871570454429696LLU,17768106831642623LLU},{18445618345576222719LLU,1152917381438242563LLU,18446744073709535235LLU,4540331905572142287LLU,16955517272326128LLU},{1125893061738303LLU,18446744072702853375LLU,18379185956063297535LLU,13907087611772010495LLU,14623501226864655LLU},{17865779719764932639LLU,18433180429566598655LLU,18445618242522185727LLU,18446735822792413180LLU,17983596039568863LLU},{18446743489593738743LLU,18445618229634138107LLU,17582000164669751295LLU,13834917315658842051LLU,13158697453604863LLU},{18311634985343516607LLU,1125899705512951LLU,14987979495463518207LLU,8791026199896260607LLU,7872778130636607LLU},{4503599612334768123LLU,18175472564903835647LLU,13836183939031760895LLU,15852609088312541183LLU,14600827017074559LLU},{18445675089098701287LLU,18446744009269313343LLU,4610564516567040783LLU,18384883350494822400LLU,16958853593300979LLU},{144114633756393343LLU,18445622571043852283LLU,18392697576358936575LLU,9799814095446212607LLU,11249994535260415LLU}};

static uint_fast64_t D[21][5] = {{11329529990636109823LLU,18446744073709551615LLU,4327097499396341763LLU,13835058330160066767LLU,18014398509481983LLU},{11329529990636109822LLU,18446744073709551615LLU,10855463549340920489LLU,18446744073709541989LLU,18014398509481983LLU},{7117214083073441793LLU,11986992957037608961LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709486080LLU,9033646357500745047LLU,13835058330160068063LLU,18014398509481983LLU},{18446744073709551615LLU,6459751116671942655LLU,14119646574313209852LLU,18446743798831648560LLU,18014398509481983LLU},{18446744073709551615LLU,6459751116671942654LLU,7591280524368631126LLU,18446744073709544858LLU,18014398509481983LLU},{18446743798859329987LLU,17825071222838788093LLU,18446744073709551615LLU,18445618448680615935LLU,18014398442377215LLU},{7117214083112865341LLU,932509276306145283LLU,18446744073709551615LLU,4611685791629295615LLU,18014398509477888LLU},{18446744073703682499LLU,17514234797403406335LLU,14119646574313209855LLU,18446744025629740848LLU,18014398442377215LLU},{11475134630286327807LLU,18446744073709551603LLU,13907115580603825395LLU,709985169502633167LLU,18010017639632895LLU},{17428987569453924351LLU,18446744073709538367LLU,4543270281775350543LLU,17736759179084809212LLU,18014381358972099LLU},{8860113186236264417LLU,14770961528194623023LLU,18446744073709551375LLU,18439988587261607935LLU,17768106898224738LLU},{14379939184350797375LLU,4594728246364314067LLU,18446744073696771327LLU,3305641982135107583LLU,17981035203525021LLU},{18446744066862776091LLU,18378926195450576895LLU,18375808034145304575LLU,18446716022470955004LLU,14623501188505599LLU},{18446743970600960487LLU,288225982384439295LLU,14123024496298295295LLU,18446321620596096003LLU,16955517243584511LLU},{4503582198382587903LLU,14770961528211339235LLU,13907115649268973315LLU,2009273849870286031LLU,17766304015447934LLU},{18302901423722987455LLU,18446744073508221055LLU,18432388025262542655LLU,17901231824948413439LLU,7876891000176391LLU},{17437722196259634679LLU,18446744060821491647LLU,4557573553663243215LLU,17849785126125240256LLU,13158948303404283LLU},{17864671412430559487LLU,4611682652246760735LLU,18445622571849203967LLU,18383686944335855615LLU,17150135125016017LLU},{1017811866514112319LLU,18158518094597665779LLU,18446744057539526655LLU,720575906152185855LLU,14622473857241919LLU},{18445890645424864239LLU,288230324599521151LLU,14986923977186725695LLU,18405362613559869503LLU,8300204098551799LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][5] = {{11329529990636109823LLU,18446744073709551615LLU,4327097499396341763LLU,13835058330160066767LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,4],[3,6],[4,7],[5,8],[5,9],[6,8],[6,10],[7,11],[7,12],[8,11],[9,12],[9,13],[10,11],[10,13],[12,13]]\n", fout);
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
