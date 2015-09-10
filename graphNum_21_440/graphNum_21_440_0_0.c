#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_440_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][5] = {{72057593903710209LLU,18446726481523507200LLU,17293822586282573823LLU,18446744073709551615LLU,1023LLU},{18014398509481983LLU,18446726481523507200LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,17592186044415LLU,18446744056529682432LLU,18446744073709551615LLU,1023LLU},{18446744073575333888LLU,18446708889337462783LLU,17293822586282573823LLU,18446744073709551615LLU,1023LLU},{18392700878315323391LLU,18446744073709551615LLU,1152921504606846975LLU,18446744073705357312LLU,1023LLU},{18428729675200069632LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18428729675468505087LLU,70368744177663LLU,1152921487426977792LLU,18446744073705357312LLU,1023LLU},{72057594037919745LLU,18446744073709486080LLU,18446673722145243135LLU,18446744056533876735LLU,1023LLU},{18446744073575342079LLU,18446726481523572735LLU,17293892937846882303LLU,18446673722145243135LLU,1023LLU},{18446743799100080127LLU,70368744177663LLU,1152921504606846972LLU,18428777876544290752LLU,1023LLU},{18428729950077976575LLU,18446744073709551615LLU,18446744056529682435LLU,13853070804457095231LLU,1023LLU},{69805244384485313LLU,18446730054932168700LLU,17725675018739777487LLU,3080462144588218239LLU,1022LLU},{18446145935619645503LLU,18429011085752205315LLU,2251729994646355967LLU,18445688525903749119LLU,1009LLU},{14123138889261522931LLU,18230571290522091519LLU,18437807140116615167LLU,13471391852796016637LLU,975LLU},{18437734675298385471LLU,18446726482597248771LLU,17302825907181845759LLU,16104591342253899263LLU,829LLU},{285977755999223747LLU,18014398505549820LLU,18446321345043103692LLU,4594797513985752896LLU,1022LLU},{18446673928286896127LLU,14123287606800154623LLU,18302628885633433603LLU,8953146713216892979LLU,703LLU},{18428800042870373375LLU,18443366373938689023LLU,13833923342102691839LLU,14123287261000777727LLU,491LLU},{14123288428205367795LLU,18429855509612790015LLU,4549132499820740607LLU,18442521417556688895LLU,963LLU},{4611685760603471439LLU,288212852681211660LLU,17365454239823822844LLU,9209584160639811523LLU,830LLU},{14987913587038873591LLU,18433233222281138175LLU,9180534995116884991LLU,18227756116618494975LLU,727LLU}};

static uint_fast64_t D[21][5] = {{18428729675468505087LLU,70368744177663LLU,1152921487426977792LLU,18446744073705357312LLU,1023LLU},{18428729675468505086LLU,12297817654349004799LLU,18446744067982928554LLU,18446744073709551615LLU,1023LLU},{12285819783198277633LLU,18446738209647536810LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18392700878181105663LLU,6148961603732635647LLU,1152921493153600853LLU,18446744073705357312LLU,1023LLU},{6196953087261802495LLU,18446679569027388757LLU,17293822586282573823LLU,18446744073709551615LLU,1023LLU},{6178938688752320511LLU,6148932283422561621LLU,18446744062256305493LLU,18446744073709551615LLU,1023LLU},{72057593903710209LLU,18446726481523507200LLU,17293822586282573823LLU,18446744073709551615LLU,1023LLU},{18436159805144956927LLU,3530611001625935871LLU,17293822556000685299LLU,18446673722142778793LLU,1023LLU},{18439313944033099775LLU,14916203440827793407LLU,2305843005135844108LLU,18446744056532146774LLU,1023LLU},{18230571291510164413LLU,18446730050859185139LLU,17711416518396346367LLU,13853070804461289471LLU,1023LLU},{288230376103097411LLU,18446740504373873676LLU,18029150141595779071LLU,18428777876544290815LLU,1023LLU},{18436837469910466559LLU,18428799979519737855LLU,1098878296130338047LLU,18445663837892693503LLU,1009LLU},{18443215921200701439LLU,3530808089081085951LLU,17725675551111237571LLU,3080416498208175913LLU,1022LLU},{18432631669631483455LLU,14987135134958878467LLU,16140897200048503868LLU,16104661160263802071LLU,829LLU},{14120811765386182643LLU,18159639597464682495LLU,4611685914538918863LLU,13471392369173017468LLU,975LLU},{18436837473935289279LLU,18446744005208126451LLU,18378019636223163647LLU,15384292135207226879LLU,1009LLU},{17582052944144791771LLU,18443363062503174204LLU,13526827253383561215LLU,18436171063596417023LLU,491LLU},{1152921453037598567LLU,14123287348899991503LLU,18192131059418660863LLU,9215969982708449267LLU,703LLU},{18429851194156384255LLU,288216357378457599LLU,17726168116217510912LLU,5710518697328901123LLU,830LLU},{18445622568627334143LLU,18429855574251222015LLU,4606012538360955903LLU,17365879808780403711LLU,963LLU},{18429855368847785695LLU,4611669525749825340LLU,17581768979263782908LLU,14978777746770231247LLU,382LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][5] = {{18428729675468505087LLU,70368744177663LLU,1152921487426977792LLU,18446744073705357312LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,3],[2,4],[3,5],[4,6],[4,7],[5,8],[5,9],[6,8],[6,10],[7,10],[7,11],[8,11],[9,12],[9,13],[10,12],[11,13],[12,13]]\n", fout);
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

