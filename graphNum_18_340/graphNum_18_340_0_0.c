#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_18_340_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 17;
static uint_fast32_t endhere = 0;
char str[28] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[18][4] = {{72057594037895169LLU,18446744073708503040LLU,18446744073692775423LLU,15LLU},{4398046511103LLU,18446744073708503040LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,1048575LLU,18446744073709550592LLU,15LLU},{18446744073709518848LLU,17723209854343970815LLU,18446744073692775261LLU,15LLU},{18374690877718167551LLU,18446744073709551615LLU,18446743798848421887LLU,15LLU},{18446739675663040512LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{9223372000347553791LLU,18446726481524424287LLU,18446673958363783167LLU,15LLU},{18014396310457745407LLU,17592186044415LLU,18428799906253631488LLU,15LLU},{18446471394691671455LLU,14974468761006849013LLU,18170476381937336319LLU,15LLU},{14916199042915500019LLU,18446744072640004095LLU,14123284035534847231LLU,15LLU},{62205831608794881LLU,18445688542546886592LLU,3168070956744573948LLU,15LLU},{18428676348879798527LLU,18446744009283993663LLU,18388181885374300111LLU,12LLU},{18446480154278490111LLU,14974451169894563583LLU,18176462102015508479LLU,15LLU},{18293619281180295135LLU,18158530258750406652LLU,12609023253088812031LLU,11LLU},{18156261884858464767LLU,288230363216470527LLU,17835380415501169664LLU,6LLU},{17289459689817112443LLU,4611672824224939983LLU,8356393083406843132LLU,7LLU},{16073307504842219511LLU,18176528095059705855LLU,14987404257563508735LLU,9LLU},{4610911961578729231LLU,18445882125312818880LLU,4395319445778210815LLU,15LLU}};

static uint_fast64_t D[18][4] = {{18446741490100142079LLU,1085301329049419775LLU,18446743798848421107LLU,15LLU},{18446741490100142078LLU,11936062272790593535LLU,18446744073709551193LLU,15LLU},{10232185335041687553LLU,18446744073709171621LLU,18446744073709551615LLU,15LLU},{18374690877718134783LLU,6872448910602797055LLU,18446743798848421367LLU,15LLU},{8214565720323784703LLU,17361442744660511834LLU,18446744073692775180LLU,15LLU},{8214561322277273599LLU,6510681800919338074LLU,18446744073709551014LLU,15LLU},{17894759403453690269LLU,18446744073709270005LLU,18428799906253632511LLU,15LLU},{1128450168683744867LLU,18446744073709321743LLU,18446673958363783167LLU,15LLU},{5188146770730811379LLU,18230360184289881951LLU,14123284308251429948LLU,15LLU},{18014398509481977247LLU,14105551320307931376LLU,18170476384065106895LLU,15LLU},{18428676033198030847LLU,14920425496977080319LLU,18388181786170490819LLU,12LLU},{18436890043352809471LLU,4610564310194716671LLU,3168070781104028924LLU,15LLU},{13859542933423766513LLU,18230360185362442239LLU,14111395976219451452LLU,15LLU},{17272271575267145851LLU,18446744060774309903LLU,17852226578812043263LLU,6LLU},{2291663448997613511LLU,18446743042715844604LLU,12610051141888090111LLU,11LLU},{18302593701257250783LLU,18159638721290313724LLU,18333300861953883087LLU,9LLU},{18158372959968558399LLU,287369445662259395LLU,9057688827546728444LLU,7LLU},{18390444942313241599LLU,18176528095210891263LLU,15550364149408070659LLU,12LLU}};

uint_fast8_t X[18] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[18][4] = {{18446741490100142079LLU,1085301329049419775LLU,18446743798848421107LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU}};

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

    } else {
        A[i][0] = A[i-1][0] & D[i][0];
        A[i][1] = A[i-1][1] & D[i][1];
        A[i][2] = A[i-1][2] & D[i][2];
        A[i][3] = A[i-1][3] & D[i][3];

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,6],[3,7],[4,6],[4,8],[5,9],[5,10],[6,9],[7,10],[7,11],[8,10],[8,11],[9,11]]\n", fout);
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
