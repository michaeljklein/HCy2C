#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_664_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][6] = {{18446744073675997185LLU,1073741823LLU,18446744073709486080LLU,4398046511103LLU,18446744073709551600LLU,262143LLU},{18446744073709551615LLU,255LLU,18446744073709486080LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,65535LLU,18446739675663040512LLU,18446744073709551615LLU,262143LLU},{18446744073675997184LLU,18446744073709551615LLU,6908336423237976063LLU,3811605182421LLU,18446744073709551600LLU,262143LLU},{33554431LLU,18446744072635810048LLU,18446744073709551615LLU,18446744073709551615LLU,18446744072635809807LLU,262143LLU},{0LLU,18446744073709551360LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446462598732840959LLU,17399657145313525727LLU,18158513697557872383LLU,17897274132844773375LLU,18446726482328682486LLU,262143LLU},{16703851013689311231LLU,18446717685430484991LLU,288230376151711743LLU,18445050825802776576LLU,18158531289717144591LLU,262143LLU},{18446726481550276075LLU,9213801303530996223LLU,18446744073709548517LLU,18446743866745815039LLU,182870773931638799LLU,262143LLU},{17592186044031LLU,18446532966403342080LLU,18446744056529944575LLU,18446744073709550655LLU,18446743798831710207LLU,262080LLU},{18446636184131067905LLU,18374686480543821811LLU,18446744073709551615LLU,18374690877652074495LLU,18430975907662397439LLU,261678LLU},{13799029249639718911LLU,72057594019052543LLU,1152920473814630400LLU,72057594037927920LLU,17581788766111006704LLU,258559LLU},{18446445010837307391LLU,17582052932369449951LLU,18158513714737706991LLU,18014371914239180799LLU,288213058574943231LLU,262143LLU},{17864081525599780863LLU,1152921504069451583LLU,68679881429352444LLU,14411518807585325056LLU,18444509865535823759LLU,249309LLU},{17140700143654272963LLU,18446713304563843070LLU,18446674803621363711LLU,18444523060221706239LLU,14702000983461852287LLU,212927LLU},{18158530258817514367LLU,18443296005236510719LLU,18442521948992045055LLU,18437736874454798143LLU,18446740759060205535LLU,192376LLU},{288230375076396791LLU,18446603128997412608LLU,4611686001314627103LLU,9223301652004470015LLU,18410679833555107582LLU,113607LLU},{18445547804655755327LLU,1080868307943686007LLU,18446744073709551612LLU,14340024163434758159LLU,18429011150176780191LLU,249420LLU},{18446744070454902723LLU,18446713304563843071LLU,1152854503116963843LLU,4609465005006389232LLU,13852808571000978672LLU,209919LLU},{18446726549840224767LLU,3675218758026072063LLU,18158584066302017532LLU,14488053612908643327LLU,4596469877010534303LLU,249471LLU},{18160765495192584143LLU,18446722358347563007LLU,18446690472454717951LLU,18445191580471001072LLU,15348056410953350641LLU,161787LLU}};

static uint_fast64_t D[21][6] = {{14235005848039456767LLU,18446744073709551516LLU,17307611475707428863LLU,18446740555325033535LLU,18446744072635809807LLU,262143LLU},{14235005848039456766LLU,18446744073709551516LLU,6528625557237268479LLU,18446742314473383573LLU,18446744073709551615LLU,262143LLU},{4211738225670094849LLU,7969465231812329827LLU,18446744073709527877LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744072635810047LLU,17687322341708136447LLU,18446741728119872895LLU,18446744072635809807LLU,262143LLU},{18446744073709551615LLU,10477278841897222143LLU,1139132598002146490LLU,3518384518080LLU,18446744073709551600LLU,262143LLU},{18446744073709551615LLU,10477278841897221887LLU,11918118516472306874LLU,18446741434899208554LLU,18446744073709551615LLU,262143LLU},{16412172569028081027LLU,8060847843686350199LLU,18446744073709546453LLU,18445055223849287679LLU,18158531289717144591LLU,262143LLU},{4503135195354614397LLU,17308248145160438731LLU,18446744073709500015LLU,17897274132844773375LLU,18446726482328682486LLU,262143LLU},{18446744073709551231LLU,15958256650373038079LLU,4611686001247542975LLU,8527208824800541699LLU,18446743799905386482LLU,262080LLU},{18446744073702766059LLU,3732612388822712319LLU,14974190653284544992LLU,9919538560329790460LLU,182870773931704317LLU,262143LLU},{10893353711657025535LLU,18446744073690676127LLU,68678798883684351LLU,18446740555326029808LLU,17581788765260699887LLU,258559LLU},{17140573496477220863LLU,18446744073508007920LLU,18391853150638440447LLU,18446744073642495039LLU,18430975907438962463LLU,261678LLU},{16412172573291822615LLU,14987698977584316279LLU,4611686018427375519LLU,8642617963298421763LLU,18263890891937153019LLU,262080LLU},{9007161682344804289LLU,18446739676631836666LLU,18446674803621312111LLU,18446185521802641407LLU,14987973399760861174LLU,212927LLU},{13796904168574552703LLU,14425591731411727LLU,18227193578987192316LLU,13862079653046386687LLU,18446732641848352767LLU,249309LLU},{18446744072633776115LLU,17856763460143022079LLU,1139397305426771456LLU,1998912122133626879LLU,7717991084848054014LLU,113663LLU},{18446743042776857071LLU,4319215096510271487LLU,18442257241634501119LLU,17134920890945881084LLU,10875556482867253213LLU,192383LLU},{2035345488926736383LLU,18446744073652925406LLU,18446673721075644015LLU,18446740555326029823LLU,14123287542000120054LLU,209919LLU},{18444492342212684415LLU,18389112071220367105LLU,18172305955306602495LLU,18401708077435636799LLU,18446727370715434911LLU,249420LLU},{2251796565721047LLU,18446740568950177790LLU,4611686017357778463LLU,9223016053859155955LLU,18266424102196083954LLU,209907LLU},{18446727580766627583LLU,17802588579910598401LLU,18163017281079083004LLU,15798609900579077375LLU,9213225536455655359LLU,122575LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][6] = {{14235005848039456767LLU,18446744073709551516LLU,17307611475707428863LLU,18446740555325033535LLU,18446744072635809807LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,6],[3,7],[4,6],[4,8],[5,9],[5,10],[6,11],[7,9],[7,10],[8,12],[8,13],[9,11],[10,12],[11,13],[12,13]]\n", fout);
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

