#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_633_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][5] = {{18446744073172680705LLU,524287LLU,18446744073709551600LLU,18446181124024565759LLU,1125899906842623LLU},{18446744073709551615LLU,3LLU,18446744073709551600LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,15LLU,18446744073441116160LLU,1125899906842623LLU},{18446744073172680704LLU,18446744073709551615LLU,18446031553088716767LLU,18446181123881924055LLU,1125899906842623LLU},{536870911LLU,18446744073709027332LLU,18446744073709551615LLU,562949953421311LLU,1125899906842560LLU},{0LLU,18446744073709551612LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18158476311872405503LLU,18446462598732840973LLU,18446585045566095359LLU,1125899906826303LLU},{18446743937344339967LLU,18446744073709551615LLU,281474976710655LLU,18375249429356609536LLU,1125899902664703LLU},{18446708889765405177LLU,4488399050912038887LLU,18446744073709551615LLU,9223934986808197119LLU,1125899370004479LLU},{35184372088831LLU,18446744073709027356LLU,1125899905794111LLU,9223372036854775807LLU,1125831724228608LLU},{18446744073709518849LLU,18446726481524031487LLU,18446532967414104063LLU,18446743524020846531LLU,1124868831477759LLU},{11528159514368966655LLU,17592185945631LLU,18446744073709551600LLU,18446181673511944191LLU,1109388441941823LLU},{18446709026703797243LLU,9141180725177876463LLU,18446462598733889535LLU,9295429630892703743LLU,1125899374157823LLU},{18446709027850158079LLU,18446744073709551615LLU,18446462598733889535LLU,9223934986539761664LLU,1125899370004479LLU},{18374713937397547007LLU,18446744073709543455LLU,18375811335901409343LLU,7189996805096001535LLU,1063219690994748LLU},{72057594012761991LLU,16285016251501649916LLU,72057594036883455LLU,18446691289098354687LLU,914527386330051LLU},{18375807964352053375LLU,18446726482597241343LLU,18379189254614937855LLU,17284814828681297871LLU,1072292264082684LLU},{11522248540392814623LLU,18428747130013776284LLU,18446744073709551615LLU,18446735760800350207LLU,823479985235647LLU},{17869437240231329791LLU,18014398509481599LLU,17582052928141606896LLU,18010466655901040703LLU,479385945243511LLU},{18446710959509731839LLU,18429011029917695999LLU,18446462615912710143LLU,9732272163049717759LLU,823533735772159LLU},{1152895013246992287LLU,18430981474006630396LLU,1152641129140781055LLU,11475167445783674879LLU,701299034154959LLU}};

static uint_fast64_t D[21][5] = {{7168534476635504639LLU,18446744073709551615LLU,1068780931252287LLU,562949898948412LLU,1125899906842560LLU},{7168534476635504638LLU,18446744073709551615LLU,12297473122162616991LLU,18446744073548752278LLU,1125899906842623LLU},{11278209597074046977LLU,3767729646318649348LLU,18446744073709551610LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709027331LLU,6149627211857352063LLU,562949917106045LLU,1125899906842560LLU},{18446744073709551615LLU,14679014427390902271LLU,18445675292778299333LLU,18446181123810603203LLU,1125899906842623LLU},{18446744073709551615LLU,14679014427390902267LLU,6149270951546934629LLU,18446744073601915497LLU,1125899906842623LLU},{13667721044403991725LLU,13217426875769072309LLU,18446744073709551611LLU,18375249429625044991LLU,1125899902664703LLU},{16057232490014395219LLU,8708779082421982542LLU,18446744073709551612LLU,18446585045566095359LLU,1125899906826303LLU},{18446744073709551615LLU,17005405264523821055LLU,281474975662085LLU,18446266989279182847LLU,1125831724228671LLU},{18446744073600623097LLU,2162008213779120127LLU,18446519717708431359LLU,18446658208240971971LLU,1125899370004479LLU},{9798729379847602175LLU,18446744073709452831LLU,14119907213933559615LLU,5882827013249355583LLU,1109388441941799LLU},{8897964611693707263LLU,18446744073709551615LLU,4327694534411796735LLU,12564480010157817792LLU,1124868831477720LLU},{13667721181342383791LLU,16717137502686325437LLU,281474976710643LLU,18446426017422639103LLU,1125831724220415LLU},{11278209735158799879LLU,16284735859930431516LLU,18446744073709551600LLU,18446266989279182847LLU,1125831724228671LLU},{18446744073676521345LLU,16143152863236325375LLU,18446519772519596031LLU,18446678094476475635LLU,914587088945151LLU},{18446736346962321919LLU,2303871602044960767LLU,18446742975221334015LLU,16413296171104076751LLU,1063227634155519LLU},{9799823406769111039LLU,16143152864309444607LLU,14123271937752580095LLU,15977579607290281023LLU,908179272497127LLU},{17546022216573911039LLU,18446744073709551615LLU,17311836950433301503LLU,17938400265770090496LLU,491962670546929LLU},{9215468661374973983LLU,18446743936337312252LLU,4597910512120102143LLU,12637100487577174015LLU,826383649468126LLU},{17301985342999470055LLU,16284999759834351231LLU,17311836967612122096LLU,18446268670758879231LLU,491948775307633LLU},{18382848149686290431LLU,2305825554466596479LLU,18392700862024643568LLU,18155768835498558415LLU,518414321515901LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][5] = {{7168534476635504639LLU,18446744073709551615LLU,1068780931252287LLU,562949898948412LLU,1125899906842560LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,6],[3,7],[4,6],[4,8],[5,9],[5,10],[6,7],[7,11],[8,9],[8,12],[9,13],[10,11],[10,13],[11,12],[12,13]]\n", fout);
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
