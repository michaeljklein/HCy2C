#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_18_986_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 17;
static uint_fast32_t endhere = 0;
char str[28] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[18][5] = {{18446744073709551615LLU,288230376151711743LLU,0LLU,18446744073709550592LLU,281474976710655LLU},{2305843009213693951LLU,18158513697557839872LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{16140901064495857664LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073707454464LLU,17870283321406128127LLU,8601725021724335615LLU,18446744072635810271LLU,281474976710655LLU},{2305843009215791103LLU,18446744073709289472LLU,18446744073709551615LLU,18445618174876450815LLU,281474976710655LLU},{18446744073707454465LLU,18158513697558102015LLU,18446744073709551615LLU,18446744072635810815LLU,281474976710655LLU},{18446744073709551615LLU,143549914478018559LLU,18446744073692774400LLU,1125899334072319LLU,281474976710652LLU},{18424138114076246015LLU,18446744073709551615LLU,18428729675216846847LLU,18446631847287848959LLU,281474976448515LLU},{18446744073474670591LLU,18446743111636877311LLU,18014398509481983LLU,18446744013578173440LLU,281474708537343LLU},{18446744073709551615LLU,141289283943137279LLU,18176523959208509184LLU,16142026963758557183LLU,281470949654527LLU},{9223371968403734515LLU,18446743970627190776LLU,18446744073692774655LLU,2305841978421346303LLU,281410552201204LLU},{18444492342615343103LLU,1152921504606838791LLU,14771750702682207228LLU,13692034682252689407LLU,280992058703871LLU},{16143152864309542799LLU,18446744073679937535LLU,18446744073709551363LLU,16283925537036959743LLU,277624538529743LLU},{18338648952015945727LLU,14987979559888977414LLU,14770906277752026099LLU,4306425158496681980LLU,268073862430719LLU},{18444501069988886655LLU,4611686009871000063LLU,18446744069683019772LLU,18320610298794313727LLU,228422466928191LLU},{18086173655733045247LLU,18446462607322675140LLU,18446744073709551615LLU,3707588393199239167LLU,206639153545214LLU},{18446736377126125567LLU,18158795172534550079LLU,18446743803126611967LLU,18433233273787252735LLU,131803419501055LLU},{18446743249050603519LLU,18446463698244468687LLU,18428729950077976575LLU,18444492267421958143LLU,206639197855743LLU}};

static uint_fast64_t D[18][5] = {{3662781204626669569LLU,18328061677083557888LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{17089805878296575998LLU,12105675798371893247LLU,7375319856480426410LLU,18446744073709551002LLU,281474976710655LLU},{16140901064495857663LLU,6459750671963652095LLU,11071424217229125205LLU,18446744073709551205LLU,281474976710655LLU},{2305843009213693951LLU,6917529027640819712LLU,15993933743221733205LLU,18445618174876450677LLU,281474976710655LLU},{18446744073709551615LLU,17412504965728698367LLU,3679215495731727615LLU,18446744072635809999LLU,281474976710655LLU},{17089805878296575999LLU,1152921504606846975LLU,14767528577977824000LLU,18445618174876450608LLU,281474976710655LLU},{13807928155355290845LLU,18400401856405158751LLU,18446744073709551615LLU,18446669239273127935LLU,281474819957339LLU},{17509146362882552759LLU,18230570194212513520LLU,18446744073709551615LLU,2475853894607978495LLU,281474865037308LLU},{9216588873939742571LLU,18445896350138621359LLU,18446744073709551615LLU,15971978626318989311LLU,281474976701863LLU},{4611685949709172209LLU,18401532154497990648LLU,18446744073709551615LLU,18446742975271665663LLU,281410395727603LLU},{18419614174049853151LLU,18443353041999477599LLU,18176523959208509439LLU,18446669306847293439LLU,281470949374815LLU},{18446744073708994433LLU,18392489153439989759LLU,4597963906939604991LLU,18446744073423157455LLU,277566401081283LLU},{18446744073709272575LLU,18433180187421048831LLU,14123222405975372031LLU,13835058055138959359LLU,280989642225407LLU},{18446744073709549569LLU,18446744065119879167LLU,18433233270586212351LLU,18446744073709519055LLU,225348192960003LLU},{18338657679388934143LLU,18392489153473249278LLU,4610630281106231283LLU,8935000774751944700LLU,267722478776319LLU},{17270090675093766143LLU,18446744073709551615LLU,18446743798832693052LLU,18446050727475280959LLU,103319599046659LLU},{18013976284048130047LLU,4611686018427320317LLU,18429855575105929167LLU,17833963956964687811LLU,192397304528894LLU},{16715668517217631159LLU,18230571285134307067LLU,18446744073693822780LLU,17212176649018129471LLU,103319531945981LLU}};

uint_fast8_t X[18] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[18][5] = {{3662781204626669569LLU,18328061677083557888LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,5],[2,7],[3,4],[3,8],[3,9],[4,5],[4,9],[5,6],[5,9],[6,7],[6,9],[7,8],[7,9],[8,9]]\n", fout);
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

