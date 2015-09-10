#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_576_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][6] = {{18446744072635809793LLU,4194303LLU,18446744073709486080LLU,68719476735LLU,18446744073709551614LLU,262143LLU},{18446744073709551615LLU,255LLU,18446744073709486080LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,65535LLU,18446744004990074880LLU,18446744073709551615LLU,262143LLU},{18446744072635809792LLU,18446744073709551615LLU,6916966077687529471LLU,32203200471LLU,18446744073709551614LLU,262143LLU},{1073741823LLU,18446744073705357568LLU,18446744073709551615LLU,18446744073709551615LLU,18446744072635809793LLU,262143LLU},{0LLU,18446744073709551360LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,15562010346389503999LLU,18446462598732896125LLU,3259015068171370495LLU,18446739676736782335LLU,262143LLU},{18446708891484946431LLU,18446744073709551615LLU,281474976710655LLU,18446744004990074880LLU,18428734073246547969LLU,262143LLU},{35184372088831LLU,18446744073705358080LLU,18446462598733103103LLU,18446744073709551615LLU,18446739675663073279LLU,262143LLU},{16140901064495824897LLU,18445618173805789151LLU,18446744073709551615LLU,18445618190982562815LLU,16149484883054428159LLU,262143LLU},{18439988673194786815LLU,1125899906574333LLU,1152921504606781440LLU,1125899906842623LLU,2305816339614269438LLU,262128LLU},{17582052671986908927LLU,18378345448210431871LLU,70304319619071LLU,18439416928222052096LLU,11529078706077171456LLU,261895LLU},{18445653633044316147LLU,18446744073457893367LLU,18446730879503171571LLU,18158513216521502975LLU,17798366464721813759LLU,258303LLU},{18302656373289643007LLU,17581996870161368063LLU,18446744069414843391LLU,13816867734657433599LLU,8646911251261187071LLU,248315LLU},{144115155830046623LLU,18446744057599262464LLU,18159358126782938943LLU,17293819270567821311LLU,15924723917625753569LLU,212943LLU},{6917529027575021441LLU,1152921487429402579LLU,18446730879570018048LLU,16176925477426754559LLU,18162311754183344127LLU,210687LLU},{17735170728379908223LLU,18391574995454107647LLU,18446744018143412223LLU,18441118972020510464LLU,16428744386773249855LLU,249663LLU},{18426477875382220863LLU,1121506152929085LLU,14987768453656477695LLU,18303686615819616243LLU,2305796543573131263LLU,192414LLU},{4607040026679705595LLU,18446744073659084799LLU,4598174394908344320LLU,144115050632724479LLU,18445037489895700986LLU,113905LLU},{18445866663418264055LLU,72053470667997183LLU,14987979559826096115LLU,18023352588585402355LLU,9171536660674480127LLU,189438LLU},{18445873234727403455LLU,1152921491718012672LLU,18176247720539324415LLU,18338655415178362879LLU,15947242156343271399LLU,161758LLU}};

static uint_fast64_t D[21][6] = {{11734164015633399807LLU,18446744073709551462LLU,17294666994033098751LLU,18446744059764489276LLU,18446744072635809793LLU,262143LLU},{11734164015633399806LLU,18446744073709551462LLU,6532940384462045183LLU,18446744032544921238LLU,18446744073709551615LLU,262143LLU},{6712580058076151809LLU,7591281554895143321LLU,18446744073709513110LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073705357567LLU,17678692687258583039LLU,18446744064412843389LLU,18446744072635809793LLU,262143LLU},{18446744073709551615LLU,10855462518814408703LLU,1152077079676491369LLU,13945062339LLU,18446744073709551614LLU,262143LLU},{18446744073709551615LLU,10855462518814408447LLU,11913803689247544937LLU,18446744046154705257LLU,18446744073709551615LLU,262143LLU},{18446708889779483875LLU,9033648418559360511LLU,18446744073709518295LLU,18446744073709551615LLU,18428734073246547969LLU,262143LLU},{6712580059781614365LLU,14119643482725286809LLU,18446744073709536060LLU,3259015068171370495LLU,18446739676736782335LLU,262143LLU},{18446744073077830883LLU,4327100590984265727LLU,1152077079676665027LLU,15187729019483243459LLU,18428734073246580734LLU,262143LLU},{13538511475689127935LLU,18446744073709283196LLU,220461139238060031LLU,18446744072850718719LLU,2305816338971808211LLU,262128LLU},{14329798204999073791LLU,18446744073708437447LLU,18227127359401885695LLU,18446744009083699260LLU,16149484882623147565LLU,262143LLU},{6916438311957949425LLU,14123232356074847187LLU,18446730879503168496LLU,13348492892629368831LLU,17816238269243359231LLU,258303LLU},{17377139161369943583LLU,18374756574609213245LLU,18446532903052447551LLU,8061708315295481855LLU,11529212505045860350LLU,261895LLU},{18446744040907914895LLU,4597330571545280511LLU,18158795172534501135LLU,16642476773849494527LLU,15910509398011674592LLU,212943LLU},{18446736376917516787LLU,17311766873494257663LLU,1152921504606843123LLU,11209195177149452227LLU,8643120168458773503LLU,248315LLU},{17439055719985709055LLU,18392700878181074815LLU,288019201266810879LLU,18442240473827376896LLU,4611554044266668831LLU,249651LLU},{4611254447162523647LLU,1152921504605929456LLU,18379172761975127808LLU,16176929857488044031LLU,16135833552607305203LLU,210684LLU},{1080650736309633019LLU,18446744073659023351LLU,18429841346950070271LLU,18446743936266403903LLU,16625178555581364345LLU,113919LLU},{17842676697556580415LLU,18446739679954853647LLU,18230307356409855999LLU,18446675839362793456LLU,17969324020896346031LLU,192415LLU},{31525052671303647LLU,18445688539325411327LLU,18429854476668964671LLU,8069605007806168895LLU,17221764713006759800LLU,114535LLU},{18334152845067913211LLU,18391579376270422015LLU,4611686015206097151LLU,2300283740980760335LLU,16715866459508571006LLU,122227LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][6] = {{11734164015633399807LLU,18446744073709551462LLU,17294666994033098751LLU,18446744059764489276LLU,18446744072635809793LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU}};

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
        A[i][5] = A[i-1][5] & C[i][5];

    } else {
        A[i][0] = A[i-1][0] & D[i][0];
        A[i][1] = A[i-1][1] & D[i][1];
        A[i][2] = A[i-1][2] & D[i][2];
        A[i][3] = A[i-1][3] & D[i][3];
        A[i][4] = A[i-1][4] & D[i][4];
        A[i][5] = A[i-1][5] & D[i][5];

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,4],[3,6],[4,7],[5,8],[5,9],[6,10],[6,11],[7,10],[7,12],[8,10],[8,13],[9,11],[9,13],[11,12],[12,13]]\n", fout);
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

