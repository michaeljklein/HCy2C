#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_395_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][3] = {{68719345665LLU,18428729950077976560LLU,1125899906842623LLU},{17179869183LLU,18446744073709551600LLU,1125899906842623LLU},{18446744073709551615LLU,18446743798831644687LLU,1125899906842623LLU},{18446744073709420544LLU,18428729950077976543LLU,1125899906842623LLU},{18446744022170075135LLU,18014398509481983LLU,1125899906842560LLU},{18446744056529682432LLU,18446744073709551615LLU,1125899906842623LLU},{18446744056529944575LLU,18014123631575103LLU,1125899906842560LLU},{18446462667452317569LLU,18446726756401414143LLU,1125899906777151LLU},{281474976579711LLU,18428747267386114032LLU,1125899839799295LLU},{18446744073693036543LLU,17311836967611924543LLU,1125897804054527LLU},{18446744056546459647LLU,1152921229729202175LLU,1125833334847488LLU},{18446462873594494851LLU,17329834323691176191LLU,1125897826404351LLU},{18442521937650384511LLU,9223319040397672447LLU,1124804689985493LLU},{4433505760969155LLU,18428791797607038960LLU,1109406158946303LLU},{3692951694393388031LLU,14976016873374875635LLU,1109405040377791LLU},{18446744056581062655LLU,3530821832984495103LLU,1124804690118720LLU},{17298322045561463283LLU,18445686893279444991LLU,1069824608567295LLU},{1152855533909057487LLU,18429848978037145584LLU,901598666555391LLU},{18446744072699772927LLU,4395513235244041215LLU,773837142609532LLU},{18446744057590841343LLU,17582052671450005503LLU,544481593997763LLU},{17365876863798339575LLU,18301783360185290751LLU,806895368527612LLU}};

static uint_fast64_t D[21][3] = {{18446744056529944575LLU,18014123631575103LLU,1125899906842560LLU},{18446744056529944574LLU,18446743982083582623LLU,1125899906842623LLU},{12297829371019526145LLU,18446744073709551610LLU,1125899906842623LLU},{18446744022169944063LLU,18014215257544063LLU,1125899906842560LLU},{6148914737049501695LLU,18428729950077976517LLU,1125899906842623LLU},{6148914719869632511LLU,18446743890457613669LLU,1125899906842623LLU},{68719345665LLU,18428729950077976560LLU,1125899906842623LLU},{18446744062284005375LLU,8052435913838690111LLU,1125899839799253LLU},{18446744067955490815LLU,10412322283502436607LLU,1125899906777130LLU},{3692107063355157373LLU,18434763520135397363LLU,1125833334847551LLU},{14754637079073739907LLU,18440710503652130812LLU,1125897804054527LLU},{3692107258088303487LLU,8058470033651924979LLU,1125833290219477LLU},{18446673979809202115LLU,16104864021136538879LLU,1109406225790911LLU},{18446744056581062655LLU,3530821832984495103LLU,1124804690118720LLU},{18443155267740761791LLU,17365836182675260415LLU,1124868040757247LLU},{4433505760969155LLU,18428791797607038960LLU,1109406158946303LLU},{18446744060613885951LLU,3963167414324884479LLU,914136544275279LLU},{18446744069676728319LLU,18014398492369162239LLU,1072685262019824LLU},{18379136478107040219LLU,18433017220792582128LLU,535461507629055LLU},{72041101363480551LLU,18442518650524008447LLU,767458697805823LLU},{18446691284258029535LLU,17856767866779271152LLU,412831669255119LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][3] = {{18446744056529944575LLU,18014123631575103LLU,1125899906842560LLU},{18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU}};

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

    } else {
        A[i][0] = A[i-1][0] & D[i][0];
        A[i][1] = A[i-1][1] & D[i][1];
        A[i][2] = A[i-1][2] & D[i][2];

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,3],[2,4],[3,5],[4,6],[4,7],[5,6],[5,8],[6,9],[7,9],[7,10],[8,9],[8,11],[10,12],[10,13],[11,12],[11,13],[12,13]]\n", fout);
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

