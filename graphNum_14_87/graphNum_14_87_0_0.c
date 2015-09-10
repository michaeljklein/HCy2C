#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_14_87_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 13;
static uint_fast32_t endhere = 0;
char str[24] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[14][4] = {{18446744073441118207LLU,16134143482137665535LLU,17582026032939007519LLU,204LLU},{274877906943LLU,18446744073709420544LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18374686479671754751LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,72057594037927935LLU,18446744073642442752LLU,255LLU},{18446744004453189369LLU,17939873559807655935LLU,18446744005038833623LLU,255LLU},{18167512348680404991LLU,14411518807585578607LLU,18446603404940620479LLU,255LLU},{18446471255239425511LLU,4592818398630476287LLU,18302769623115747310LLU,255LLU},{9502876688702373791LLU,18446743309473808381LLU,144115188075855871LLU,252LLU},{17292643892637726720LLU,8935141660703058936LLU,13653928903071096803LLU,243LLU},{18446743798831644672LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18410502796336955391LLU,18446711088335028167LLU,18438858924460343295LLU,63LLU},{9007182074871807LLU,17978228970678910912LLU,11529142476219367423LLU,183LLU},{18446744073474658283LLU,18446742939633582143LLU,18320642942693277695LLU,207LLU},{18230529510149617791LLU,18374721664043712507LLU,18445763309069139967LLU,243LLU}};

static uint_fast64_t D[14][4] = {{9223099357971087359LLU,4124875041881160128LLU,13826191591499157503LLU,183LLU},{18446743860570419381LLU,16052416333970538495LLU,18446744073654500678LLU,255LLU},{14975435994937401342LLU,8358680908399610702LLU,18446744073709132475LLU,255LLU},{18050036979558346571LLU,18446704937622044593LLU,18446744073709551615LLU,255LLU},{18437737140711325695LLU,18428729125444255743LLU,16705485854268703487LLU,253LLU},{18446743867551121281LLU,18446744065119715325LLU,4354840079488253927LLU,255LLU},{9232379218928601087LLU,18444492016197820415LLU,15852589212730605471LLU,254LLU},{18446744069884345599LLU,70988868735727727LLU,18427317074683494398LLU,255LLU},{13776509610858905599LLU,14987944384106790655LLU,18446739709964023807LLU,92LLU},{3868015386062487551LLU,12482430041136461055LLU,18446744073697912829LLU,255LLU},{16571553380816650239LLU,18438862772614711295LLU,17401882558995627521LLU,235LLU},{18446743933855727079LLU,16135823793368072191LLU,17735157328044359278LLU,205LLU},{18446744043644451775LLU,18383675942842138623LLU,10373369940043104767LLU,183LLU},{11522318668469362687LLU,18446744073709436895LLU,9146810790509281279LLU,92LLU}};

uint_fast8_t X[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[14][4] = {{9223099357971087359LLU,4124875041881160128LLU,13826191591499157503LLU,183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU}};

#if UINTPTR_MAX == 0xffffffffffffffff // 64-bit. Hopefully this means the cpu has 'popcnt'.
int counter (uint64_t * buf){
    uint64_t cnt[14];
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
            "popcnt %2, %2  \n\t"
            "add %2, %0     \n\t"
            "popcnt %3, %3  \n\t"
            "add %3, %1     \n\t"
            : "+r" (cnt[12]), "+r" (cnt[13])
            : "r" (buf[12]), "r" (buf[13]));


    return cnt[0] + cnt[1] + cnt[2] + cnt[3] + cnt[4] + cnt[5] + cnt[6] + cnt[7] + cnt[8] + cnt[9] + cnt[10] + cnt[11] + cnt[12] + cnt[13];
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
    sprintf(str, "[              ,%5d]\n", this);
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
    fputs("[[0,2],[0,3],[0,4],[0,6],[1,3],[1,4],[1,5],[1,6],[2,4],[2,5],[2,6],[3,5],[3,6],[4,6]]\n", fout);
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

