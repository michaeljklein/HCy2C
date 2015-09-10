#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_630_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][5] = {{18446744073172680705LLU,65535LLU,18446744073709551612LLU,18446726481527701503LLU,1099511627775LLU},{18446744073709551615LLU,1LLU,18446744073709551612LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,3LLU,18446744073705357312LLU,1099511627775LLU},{18446744073172680704LLU,18446744073709551615LLU,17870247440678780919LLU,18446726481527535479LLU,1099511627775LLU},{536870911LLU,18446744073709486082LLU,18446744073709551615LLU,17592186044415LLU,1099511627772LLU},{0LLU,18446744073709551614LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,9213766428110356479LLU,18446726481523507203LLU,18446739312562143231LLU,1099511627267LLU},{18446743799905386495LLU,18446744073709551615LLU,17592186044415LLU,18442258066264031232LLU,1099511562751LLU},{18446603336632132089LLU,14555620685557399539LLU,18446744073709551615LLU,17293840161288749055LLU,1099507434495LLU},{140737488355327LLU,18446744073709486094LLU,18158584066301952015LLU,1152921504606846975LLU,1099247386368LLU},{18446744073709518849LLU,18446741874686361599LLU,18446744060774318079LLU,18446744065123808243LLU,1097631913983LLU},{18442521948522053631LLU,2199023255311LLU,18446744073709551612LLU,18446726490113441791LLU,1084466659315LLU},{18446603611015146491LLU,15852661814941450231LLU,18446726481523572735LLU,17298326168730075135LLU,1099507498751LLU},{18446603612172845055LLU,18446744073709551615LLU,288212783965732863LLU,17293840161284554752LLU,1099507434495LLU},{18302662211358687231LLU,18446744073709547535LLU,1151849480765832975LLU,14106347156269170687LLU,1035024203715LLU},{144115188073889671LLU,18442258066134470654LLU,18159639597464617215LLU,4611685760603521023LLU,892346564412LLU},{18307060877418791039LLU,18446741874820509951LLU,4610828399354576703LLU,15553146120293056511LLU,1046847946703LLU},{18307413959702970495LLU,4501400738328591LLU,18446744073709551612LLU,18446726747945697279LLU,1035024203715LLU},{18446735811241048575LLU,17942340900411670527LLU,288230375078035455LLU,18378925096459828992LLU,803158418431LLU},{16717229617705910271LLU,18446744073709551615LLU,18429837983994605823LLU,3526599983203614975LLU,480764174335LLU},{2305836399257452447LLU,18442521948933013502LLU,18176528094997712895LLU,18392489565689478912LLU,686523279228LLU}};

static uint_fast64_t D[21][5] = {{9795047990505766911LLU,18446744073709551615LLU,864744949546156047LLU,17592182099148LLU,1099511627772LLU},{9795047990505766910LLU,18446744073709551615LLU,12009581065957649063LLU,18446744073708070502LLU,1099511627775LLU},{8651696083203784705LLU,9919920645268897794LLU,18446744073709551614LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709486081LLU,6725411324267287903LLU,17592183414237LLU,1099511627772LLU},{18446744073709551615LLU,8526823428440653823LLU,17581999124163395569LLU,18446726481527452467LLU,1099511627775LLU},{18446744073709551615LLU,8526823428440653821LLU,6437163007751902553LLU,18446744073706838425LLU,1099511627775LLU},{18065626680586351789LLU,17130491726836618586LLU,18446744073709551614LLU,18442258066268225535LLU,1099511562751LLU},{9032813202522819411LLU,2003195346542635687LLU,18446744073709551615LLU,18446739312562143231LLU,1099511627267LLU},{18446744073709551615LLU,9175343993132679167LLU,18158531289743818753LLU,18446729790267326463LLU,1099247386371LLU},{18446744073583616505LLU,13907100120865374207LLU,17582051900721528831LLU,18446740764969677619LLU,1099507434495LLU},{12677715851432951807LLU,18446744073709551375LLU,14758081522383926223LLU,7595725391838564303LLU,1084466659313LLU},{15559854088131706879LLU,18446744073709551615LLU,4553407487936547903LLU,10851036274053083376LLU,1097631913982LLU},{18065626954969366191LLU,18389110421242991966LLU,18158531289743884284LLU,18446734551414734847LLU,1099247386111LLU},{8651696358744497671LLU,4539643952844177422LLU,18446744073709551612LLU,18446729790267326463LLU,1099247386371LLU},{18446744073707487105LLU,18442242672971284479LLU,18446743853810581503LLU,18446743807291503411LLU,892545894399LLU},{18446636661820350975LLU,13907115514028621823LLU,288213058839445503LLU,17565108369944018943LLU,1035084921855LLU},{12682114517491023871LLU,18442242673105436671LLU,18217060234008933375LLU,9042524098030145295LLU,891204382717LLU},{9799799739384856575LLU,18446744073709551615LLU,18159639322590904575LLU,4340414509622427648LLU,892545894396LLU},{16173552161391222759LLU,4611420074044539711LLU,18429855575106908412LLU,4611672766280630271LLU,480658849687LLU},{9195506014127388703LLU,17870564779211308238LLU,18446744073709551615LLU,18446741942365585407LLU,803003694955LLU},{18335174223154087935LLU,576458570460033855LLU,18446726756401414140LLU,17578659844850778111LLU,506762067927LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][5] = {{9795047990505766911LLU,18446744073709551615LLU,864744949546156047LLU,17592182099148LLU,1099511627772LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,6],[3,7],[4,6],[4,8],[5,9],[5,10],[6,7],[7,11],[8,9],[8,12],[9,10],[10,13],[11,12],[11,13],[12,13]]\n", fout);
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
