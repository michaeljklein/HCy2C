#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_18_1584_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 17;
static uint_fast32_t endhere = 0;
char str[28] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[18][6] = {{0LLU,18446744073709551600LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,15LLU,18446744073709551360LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,255LLU,18446744073709547520LLU,18446744073709551615LLU,18014398509481983LLU},{18014185135481540475LLU,18429855571080183615LLU,18176528031639663615LLU,18446726481523511295LLU,18446744073709551615LLU,18014398509481983LLU},{7493976584093695231LLU,4341470040781225982LLU,14123288431370960892LLU,17592186044355LLU,18446744073709547520LLU,18014398509481983LLU},{18432388437579612135LLU,18446727516610621695LLU,18446479160126672895LLU,18446744073709551615LLU,18446726481523511295LLU,18014398509481983LLU},{6172957311137480703LLU,18446744073709551613LLU,3692050975377325311LLU,18446479639544045363LLU,17870300862052503539LLU,18014398509481983LLU},{18446744070847639549LLU,3689517699781623759LLU,18446744073709551603LLU,18226349143322427391LLU,576460752252108799LLU,18014398509480960LLU},{13835055924709949315LLU,14987979559888945215LLU,18446744073708504063LLU,18446740663505518588LLU,18446743041907621887LLU,18014398475928575LLU},{18444424104174809215LLU,18446743249008787455LLU,18446730878497325055LLU,14109777632499728383LLU,18446744073709551375LLU,18013299031408639LLU},{18446744056529682432LLU,18446744073709551615LLU,18446744071562067967LLU,18445893049461473279LLU,576456629134621759LLU,17997699133456383LLU},{17179869183LLU,18446744073575333872LLU,18446744073709551615LLU,1152868521350258687LLU,18446198711915630591LLU,17750509141946367LLU},{18014378711805066111LLU,18429855575094132729LLU,18176528095862849475LLU,18446744073441119295LLU,9115004170812784639LLU,17095205748473663LLU},{18392489153470123995LLU,18446480186892341055LLU,18442521884634182655LLU,18410697684772978687LLU,16137452996031152127LLU,14618007091250169LLU},{18446744073701167103LLU,18445618174071144447LLU,18446744073709551615LLU,18446738847808094207LLU,14970524748373311487LLU,12381437231627775LLU},{18446744056538071039LLU,1125899906842623LLU,18446744073709551360LLU,18445688542467145727LLU,4053239664633445616LLU,8712530133516271LLU},{18302699254377873407LLU,18446744073709551615LLU,18428729679495036927LLU,18446735118165868543LLU,18158394947029684223LLU,6701793954234336LLU},{144115188075855871LLU,18446744073709551600LLU,18014398509481983LLU,4392082759898288128LLU,18437314661989741567LLU,12736742670859295LLU}};

static uint_fast64_t D[18][6] = {{18446744073709551615LLU,6148914691303626079LLU,6148914692310259029LLU,18446744073709548885LLU,18446744073709551615LLU,18014398509481983LLU},{34359738366LLU,18446744073709551600LLU,12297829381399292671LLU,18446744073709550250LLU,18446744073709551615LLU,18014398509481983LLU},{18446744039349813249LLU,12297829382405925551LLU,18446744073709551530LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{9209852165390335471LLU,4611669525749822462LLU,18446480190868504572LLU,6166940817870028739LLU,18446732345589716309LLU,18014398509481983LLU},{18445688336388394995LLU,18446744005258509375LLU,18446742978492875775LLU,18446726482060374015LLU,18446738209643343871LLU,18014398509481983LLU},{16285009655376117375LLU,18159639597463699455LLU,13853072453775917055LLU,12279820847488704511LLU,18446744073709550250LLU,18014398509481983LLU},{18446744073709547521LLU,18446744073642442767LLU,18446744073709551615LLU,17365877912543428607LLU,17870282496520748863LLU,18013778337543795LLU},{18446673739325112319LLU,18446744073709551615LLU,18446744072635810047LLU,14987977841875877887LLU,18223798041465323459LLU,18014344418086911LLU},{8499418394028474367LLU,4554264092386263037LLU,17527993257051553779LLU,18428747267385859891LLU,7745311749775032319LLU,18013973274164670LLU},{11506345203806744575LLU,14123232342650650623LLU,4610788597895790591LLU,18446744057066553340LLU,11500856442160680959LLU,18014398496504781LLU},{18446744073709551615LLU,18446744073508225023LLU,6148914693384001023LLU,1152868521350255957LLU,18446198711915630591LLU,17750509141946367LLU},{18446744073709551615LLU,6148914691370734943LLU,18446744070488325973LLU,18445893049461473279LLU,576456629134621759LLU,17997699133456383LLU},{18379189254661341135LLU,18446463698244453375LLU,18442258066267979775LLU,18392700878181105663LLU,16137441267915513855LLU,14618007091250169LLU},{9223345640522643967LLU,4611686018411659256LLU,18446744073457893312LLU,6184955216379509763LLU,9115004170808587605LLU,17095205748473663LLU},{12321814495625215999LLU,18446744073709551610LLU,14758295978624942079LLU,72057594029800652LLU,18446744073709551612LLU,8619621203607399LLU},{18398716375016144895LLU,18446744073709551607LLU,18443141196638061567LLU,18446743541133603839LLU,18446744056546459647LLU,12226535998088443LLU},{18446744067984324671LLU,14757451553946222591LLU,18446744073709551564LLU,18446744073449504767LLU,18361175680789508099LLU,12941233841242111LLU},{18446744065116821443LLU,18446518893892583487LLU,18446744073709551423LLU,18446727031279321087LLU,18012129134662123519LLU,6744438683967487LLU}};

uint_fast8_t X[18] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[18][6] = {{18446744073709551615LLU,6148914691303626079LLU,6148914692310259029LLU,18446744073709548885LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU}};

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
    fputs("[[0,3],[0,5],[0,6],[1,4],[1,7],[1,8],[2,5],[2,6],[2,7],[2,8],[3,5],[3,6],[4,7],[4,8],[5,7],[5,8],[6,7],[6,8]]\n", fout);
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

