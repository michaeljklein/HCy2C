#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_596_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][6] = {{18446744073172680705LLU,67108863LLU,18446744073709289472LLU,4398046511103LLU,18446744073709551552LLU,16383LLU},{18446744073709551615LLU,511LLU,18446744073709289472LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,262143LLU,18446739675663040512LLU,18446744073709551615LLU,16383LLU},{18446744073172680704LLU,18446744073709551615LLU,6772806221951401983LLU,2061004832767LLU,18446744073709551552LLU,16383LLU},{536870911LLU,18446744073642443264LLU,18446744073709551615LLU,18446744073709551615LLU,18446744056529682495LLU,16383LLU},{0LLU,18446744073709551104LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{17874786921033498623LLU,18408462890613866495LLU,13835058055282392959LLU,18356302645255208959LLU,18446739692709740526LLU,16383LLU},{18446743937344339967LLU,8646761750835757055LLU,4611686018427385847LLU,12388267878896369664LLU,18445622571849211963LLU,16383LLU},{18444492274147442351LLU,18293619341326550015LLU,18446744073709420031LLU,18446744073709535232LLU,18303750387492978751LLU,16383LLU},{2251799741066235LLU,16140302929566629376LLU,18446744056530722781LLU,18446744073709551615LLU,144115153717166079LLU,16383LLU},{14987979559888977921LLU,18428729675232050943LLU,18446744073709551615LLU,18374687579182268415LLU,8790437134394720255LLU,16368LLU},{18446461773562281983LLU,18014398509410303LLU,18230570260803354624LLU,72057594037927935LLU,18407336374379216832LLU,16143LLU},{17872535258658766847LLU,18446744073709291519LLU,13835058072462032895LLU,18446744073709535232LLU,18303750421719556095LLU,16383LLU},{576460615938211839LLU,18446744073642966528LLU,18446744056530731007LLU,18446739675663056895LLU,142998067216375871LLU,16383LLU},{8070450532214898561LLU,4611685743563636415LLU,18446744073709550592LLU,1152640922970554367LLU,3890221672652865532LLU,15612LLU},{16113862956877316223LLU,18428729950076903407LLU,18446463697439162367LLU,18374967941762645955LLU,18144984892018998271LLU,13299LLU},{18445334224922769439LLU,17944046944966655LLU,14771793377477263356LLU,13902682418436898815LLU,18333024712784871423LLU,11215LLU},{4539557498912243711LLU,18446744073703256060LLU,18433232450130542595LLU,4611686018160000255LLU,16715004394327637568LLU,7743LLU},{17904077910772285319LLU,18446743799905157119LLU,13835339530258873407LLU,18446480190918869055LLU,18320639435725668348LLU,15612LLU},{18446743944858565119LLU,288164405395324419LLU,18446744056596791292LLU,14119906333935271935LLU,2304857830689071615LLU,11215LLU},{16122872917292713983LLU,18428800043938983932LLU,18446479366234571775LLU,18379190079046549455LLU,16994244888813862595LLU,6007LLU}};

static uint_fast64_t D[21][6] = {{12685820740335828991LLU,18446744073709551429LLU,17510906777637486591LLU,18446743181225558016LLU,18446744056529682495LLU,16383LLU},{12685820740335828990LLU,18446744073709551429LLU,6460860456594046975LLU,18446741439173208746LLU,18446744073709551615LLU,16383LLU},{5760923333373722625LLU,11068046444198888122LLU,18446744073709394329LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073642443263LLU,17822852542994841599LLU,18446743478720222549LLU,18446744056529682495LLU,16383LLU},{18446744073709551615LLU,7378697629510664191LLU,935837296072222310LLU,892483993599LLU,18446744073709551552LLU,16383LLU},{18446744073709551615LLU,7378697629510663679LLU,11985883617115661926LLU,18446742310199383381LLU,18446744073709551615LLU,16383LLU},{5764607385810547885LLU,3593645856949533370LLU,18446744073709416947LLU,12388272276942880767LLU,18445622571849211963LLU,16383LLU},{17871102732231461715LLU,16082881154989426687LLU,18446744073709494045LLU,18356302645255208959LLU,18446739692709740526LLU,16383LLU},{18446744073636932603LLU,14948801174499753983LLU,18446744056529899340LLU,6239355546159349759LLU,144115170895986662LLU,16383LLU},{18446744073424256687LLU,8417074652261646335LLU,935837296072914167LLU,12207389420034179072LLU,18303750387494027225LLU,16383LLU},{13613888080866967551LLU,18446744073709479893LLU,18163016211367985151LLU,18446744018744242428LLU,18407336368153416831LLU,16143LLU},{14059629919747440639LLU,18446744073674423919LLU,17578460827073118207LLU,18446739937655000835LLU,8790437123440651199LLU,16368LLU},{5764607522925306361LLU,287108873218162362LLU,18446744073709536192LLU,271325177847021567LLU,142998084262035443LLU,16383LLU},{18445311684508524039LLU,18159635200491653119LLU,14770895351355030591LLU,18175419788346523647LLU,18303750421853765580LLU,16383LLU},{18415201391506096127LLU,18446744073709520869LLU,18446462614855745535LLU,18446744057402097600LLU,18429855055945341183LLU,13167LLU},{4395020618564108287LLU,4611686018408447903LLU,18163017293951400960LLU,1152921246893076735LLU,13222250742485219196LLU,15519LLU},{450245606011568127LLU,18446744073701687292LLU,18429644468808318975LLU,18446744073441131535LLU,16284884310207266367LLU,7926LLU},{18147814264008603679LLU,18446673722111549039LLU,14123271925069250559LLU,18442306706772840435LLU,9146245545966676991LLU,11257LLU},{16140901034330022399LLU,14122166929559912416LLU,18446744072652571647LLU,17565164429487898623LLU,14699520481560623347LLU,13167LLU},{18320506394517676007LLU,18429855559000731647LLU,18428746442752146495LLU,18392648101622971407LLU,18417469782748856268LLU,7926LLU},{18012287344075866015LLU,4611685760678821407LLU,13853072437685518332LLU,14987764072789820415LLU,4502751890919122943LLU,11741LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][6] = {{12685820740335828991LLU,18446744073709551429LLU,17510906777637486591LLU,18446743181225558016LLU,18446744056529682495LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,6],[3,7],[4,6],[4,7],[5,8],[5,9],[6,10],[7,11],[8,10],[8,12],[9,11],[9,12],[10,13],[11,13],[12,13]]\n", fout);
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

