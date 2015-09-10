#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_18_320_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 17;
static uint_fast32_t endhere = 0;
char str[28] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[18][3] = {{17592185913345LLU,18014398509477888LLU,4398046511040LLU},{274877906943LLU,18446744073709547520LLU,4398046511103LLU},{18446744073709551615LLU,18428729675200073727LLU,4398046511103LLU},{18446744073709420544LLU,17301912827191295LLU,4398046511040LLU},{18446726756401545215LLU,18446744073709551615LLU,4398042316863LLU},{18446743798831644672LLU,18446744073709551615LLU,4398046511103LLU},{15554729425495916543LLU,11132898277786127735LLU,4397983596517LLU},{18446744073642704895LLU,18428729676273811455LLU,4397039861823LLU},{18446727306224336895LLU,18446744072635826175LLU,4397979418623LLU},{17293837957970525697LLU,13853072453791645695LLU,4390521929727LLU},{1152921504606716415LLU,4611672824287850496LLU,4337782751168LLU},{4554265123174415279LLU,8502794998037607423LLU,4189673487391LLU},{18446744071633371135LLU,18428730774707519487LLU,3555293135871LLU},{18446728407812407295LLU,18446742977423343615LLU,4189677943871LLU},{18442257928550350817LLU,18176263387837431807LLU,3022312666623LLU},{4496981082759199LLU,288230376151711728LLU,2123836162044LLU},{18442258066268102625LLU,18176303795695251471LLU,2971714715587LLU},{17365880161479681663LLU,14970246636352307184LLU,1644435394556LLU}};

static uint_fast64_t D[18][3] = {{18446743854733590527LLU,18429798403723509759LLU,4398042316863LLU},{18446743854733590526LLU,18440383031365246975LLU,4398046511103LLU},{7594916645135187969LLU,18446744073709549209LLU,4398046511103LLU},{18446726756401414143LLU,18435446960385523711LLU,4398042316863LLU},{10851827922428231679LLU,16945669986044262LLU,4398046511040LLU},{10851827647550324735LLU,18435090717544376678LLU,4398046511103LLU},{9040940517751313197LLU,18446744073709549533LLU,4397039861823LLU},{14108705552812944595LLU,11132898278859865139LLU,4397983596517LLU},{4338039564506420013LLU,7330791464835740620LLU,4397039878106LLU},{18446743995152859135LLU,18433216524200132607LLU,4337781021311LLU},{18446741729972060159LLU,18443312759093395455LLU,4390519465407LLU},{17581840737429860091LLU,16104872267472715571LLU,3556228481013LLU},{1081129936548166023LLU,3530822107858465023LLU,4189681876943LLU},{17365616280349935225LLU,14932867639058366208LLU,3555293396976LLU},{1152917079682703871LLU,4598175167952191472LLU,2121696403324LLU},{18446743867132739583LLU,18446462666445438975LLU,2971711516927LLU},{18446737442765799423LLU,18429855510615556095LLU,2123835166527LLU},{18442512912444456935LLU,18230570259796979967LLU,3126699490511LLU}};

uint_fast8_t X[18] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[18][3] = {{18446743854733590527LLU,18429798403723509759LLU,4398042316863LLU},{18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,4],[3,6],[4,7],[5,8],[5,9],[6,7],[6,10],[7,11],[8,9],[8,10],[9,11],[10,11]]\n", fout);
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

