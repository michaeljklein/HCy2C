#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_18_328_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 17;
static uint_fast32_t endhere = 0;
char str[28] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[18][3] = {{281474976579585LLU,4611686018427322368LLU,18014398509465600LLU},{1099511627775LLU,18446744073709486080LLU,18014398509481983LLU},{18446744073709551615LLU,13835058055282229247LLU,18014398509481983LLU},{18446744073709420544LLU,2161015303243169791LLU,18014398509465600LLU},{18446463698244599807LLU,18446744073709551615LLU,18014397435756543LLU},{18446742974197923840LLU,18446744073709551615LLU,18014398509481983LLU},{9042665101806534655LLU,13835058038102326653LLU,18014330863737241LLU},{18446744073642704895LLU,13835058072462032895LLU,18010069178269695LLU},{18446465897334833151LLU,18446744056529944575LLU,18014329794199551LLU},{210968793579009LLU,4395513236313604095LLU,17982495492407232LLU},{18446735276542657023LLU,18446730879569952768LLU,17767968318406719LLU},{18443366322445467643LLU,9223090578051298303LLU,17099123597260799LLU},{17582052944788847551LLU,13835339530254942195LLU,14624054388719479LLU},{18392670083320053743LLU,18429855575040016383LLU,12244153907011581LLU},{4611438636900282111LLU,18446743025804640063LLU,8708070955761119LLU},{18374950321649614817LLU,4597911335898972159LLU,12943171540877308LLU},{71845800610619423LLU,14771806777775226624LLU,6725661087497219LLU},{18374941561000435681LLU,4611461718055256319LLU,12736323936830460LLU}};

static uint_fast64_t D[18][3] = {{18446743675418705919LLU,17511064128058556415LLU,18014397435756543LLU},{18446743675418705918LLU,15684180043308335103LLU,18014398509481983LLU},{10850861849998262273LLU,18446744073709524630LLU,18014398509481983LLU},{18446463698244468735LLU,17822957443275554815LLU,18014397435756543LLU},{7595883721513762815LLU,935679945651022185LLU,18014398509465600LLU},{7595882622002135039LLU,16597622085683407209LLU,18014398509481983LLU},{15553179114033722163LLU,18446744073709541335LLU,18010069178269695LLU},{4340347837704228045LLU,13835058055282113596LLU,18014330863737241LLU},{14106399932831183667LLU,5547365964078629827LLU,18010069182441062LLU},{18446734983640383487LLU,17578657915123793919LLU,17767967686819839LLU},{18446673462137978879LLU,18162964310390996991LLU,17982495050285055LLU},{17311620775668545935LLU,18446744073705570288LLU,14627850069991217LLU},{4607402255627292409LLU,4611686017420750911LLU,17099589601456607LLU},{1149543804885509755LLU,5548433658588689167LLU,8704764837573839LLU},{17514498950831176615LLU,18428786849804652531LLU,12243199413440372LLU},{18446602511284953599LLU,14123287593912106752LLU,6717981138582591LLU},{18446717625822085119LLU,18429575198572281855LLU,12736323684204543LLU},{18446531936231096319LLU,13853071406889435135LLU,6725660266414079LLU}};

uint_fast8_t X[18] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[18][3] = {{18446743675418705919LLU,17511064128058556415LLU,18014397435756543LLU},{18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,4],[3,6],[4,7],[5,8],[5,9],[6,10],[6,11],[7,10],[7,11],[8,9],[8,10],[9,11]]\n", fout);
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

