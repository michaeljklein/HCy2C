#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_547_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][5] = {{18446744073575333889LLU,65535LLU,18446744073709551600LLU,18446726481523769343LLU,288230376151711743LLU},{18446744073709551615LLU,3LLU,18446744073709551600LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,15LLU,18446744073709289472LLU,288230376151711743LLU},{18446744073575333888LLU,18446744073709551615LLU,17831287354820657119LLU,18446726481523630047LLU,288230376151711743LLU},{134217727LLU,18446744073709486084LLU,18446744073709551615LLU,17592186044415LLU,288230376151711680LLU},{0LLU,18446744073709551612LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,16102435190692773887LLU,18446744056529682439LLU,18446733990644416511LLU,288230376151449663LLU},{18446742974466359295LLU,18446744073709551615LLU,17179869183LLU,18374704071857405952LLU,288230375078232063LLU},{1099511627775LLU,18446744073709486092LLU,18446744056529682495LLU,72057594037927935LLU,288230376151449600LLU},{18417435491759546369LLU,18446742974197954781LLU,18446744073709551615LLU,18446744072636071935LLU,288230239786361727LLU},{18446744073575342079LLU,1099511627775LLU,18446726550242983920LLU,18446726482597236735LLU,288212921132253183LLU},{14699733786547978239LLU,18446744073709551615LLU,18158513713680740415LLU,17942077032653389823LLU,287952611959898097LLU},{18446742978486075363LLU,17352369364242006015LLU,288230376151711743LLU,18374967061291204608LLU,284008234388291583LLU},{18442241573526646719LLU,18446677278176837135LLU,18446744073708503091LLU,9295420827811971071LLU,274552039185315903LLU},{4503534129119231LLU,18446744073709486588LLU,1139410688545914879LLU,9219079543459938288LLU,233342718111909824LLU},{16122873468088737823LLU,18446742974214700031LLU,18158531288938574079LLU,18014152217807814655LLU,287966373039042551LLU},{18446744073708510735LLU,18428730770420924415LLU,18445687511754735615LLU,18446743937279119359LLU,207110743897931775LLU},{17906100866030501887LLU,18014398509475775LLU,4611669525690007536LLU,17284234965147450623LLU,124678021516861180LLU},{18442257035471847399LLU,17582000168680554015LLU,18446744073708507135LLU,9732278240693452815LLU,271341588846737535LLU},{576460700762832511LLU,18428800039917658108LLU,18445898807032938495LLU,18443366245089673200LLU,179544199345242051LLU},{17996375311532417535LLU,1152920409390181375LLU,18159623104739931120LLU,18158286097644257279LLU,125876386061594621LLU}};

static uint_fast64_t D[21][5] = {{10046018940443820031LLU,18446744073709551614LLU,923185078333341759LLU,17592185991216LLU,288230376151711680LLU},{10046018940443820030LLU,18446744073709551614LLU,11990101023028587167LLU,18446744073709394586LLU,288230376151711743LLU},{8400725133265731585LLU,7321069132744884229LLU,18446744073709551609LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709486083LLU,6764371410125411711LLU,17592186008949LLU,288230376151711680LLU},{18446744073709551615LLU,11125674940964667391LLU,17523558995376209862LLU,18446726481523560399LLU,288230376151711743LLU},{18446744073709551615LLU,11125674940964667387LLU,6456643050680964454LLU,18446744073709446501LLU,288230376151711743LLU},{18446742974274851523LLU,8493223574253338615LLU,18446744073709551613LLU,18374704071857668095LLU,288230375078232063LLU},{8400725133457239357LLU,14930280749184319501LLU,18446744073709551603LLU,18446733990644416511LLU,288230376151449663LLU},{18446744073652261571LLU,3516463324525232127LLU,17523558995376209916LLU,18446736564588695503LLU,288230375078232063LLU},{12357522896405397503LLU,18446744073709551615LLU,4611668439935500095LLU,14887193926040535292LLU,288212921132253160LLU},{16105931535797977087LLU,18446744073709517020LLU,14758243188640825599LLU,3559567739854995251LLU,288230239786361687LLU},{9139316571926396897LLU,17294895692434650141LLU,18446744073709551615LLU,18446743004258762751LLU,284008235394715775LLU},{13961142352098536767LLU,14987754420991675375LLU,18446744072652582963LLU,17942331008472842239LLU,287952612026691505LLU},{18446744008191769339LLU,4381157957739741183LLU,270493329450336255LLU,18442449020345909232LLU,233342718018322431LLU},{18446744073604630407LLU,17581982644962328575LLU,18392476371650609136LLU,18446730321476767695LLU,274552038205685759LLU},{4502543658113007615LLU,17294895692451395391LLU,4611686015193333759LLU,14959268042817650940LLU,284004677819751662LLU},{17874514019885252607LLU,18446744073709543839LLU,923237923544826879LLU,7191193073748016191LLU,124693306234865276LLU},{16137518382076395023LLU,18446744069418745596LLU,18445635752297757951LLU,13652627085936312307LLU,207112777834036183LLU},{13961158843749431423LLU,1151865904993127423LLU,18429007025951211519LLU,18446670380409028607LLU,234076645318143985LLU},{18446471186415085559LLU,17582051914459119519LLU,18176514901927724016LLU,16415466159575399439LLU,138336081775951487LLU},{4607463017602580463LLU,18429802798536146556LLU,18446744057602441215LLU,11471794043442955248LLU,204349447159478735LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][5] = {{10046018940443820031LLU,18446744073709551614LLU,923185078333341759LLU,17592185991216LLU,288230376151711680LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,4],[3,6],[4,7],[5,8],[5,9],[6,8],[6,10],[7,10],[7,11],[8,12],[9,11],[9,12],[10,13],[11,13],[12,13]]\n", fout);
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

