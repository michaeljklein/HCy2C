#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_535_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][5] = {{18446744073675997185LLU,17293822569102708735LLU,18446744073709551615LLU,18446744072635809855LLU,4398046511103LLU},{4611686018427387903LLU,17293822569102704640LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,1152921504606846975LLU,0LLU,18446744073709551552LLU,4398046511103LLU},{18446744073675997184LLU,16140901064495857663LLU,17716589176587026431LLU,18446744072635809845LLU,4398046511103LLU},{4611686018460942335LLU,18446744073709547520LLU,18446744073709551615LLU,18428729676273811455LLU,4398046511103LLU},{13835058055282163712LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,566747081755058175LLU,18446744073705357312LLU,18014397878601663LLU,4398046511100LLU},{18446743798898753535LLU,18446744073709551615LLU,4194303LLU,18446739676736782272LLU,4398046494723LLU},{13835058330160070655LLU,4611686018427383808LLU,18446744073705357312LLU,4398046511103LLU,4398046511100LLU},{17822995525318737409LLU,18446744073441118783LLU,18216216067783524351LLU,10376293541461606460LLU,4398042327294LLU},{18446735827338789375LLU,17293822569371140080LLU,18446744069431361535LLU,18176528094993596415LLU,4396976963523LLU},{15996222924380896255LLU,18389309981099819007LLU,18446739675663891711LLU,18435344303696871423LLU,4390089916291LLU},{18446479918188462051LLU,18446744073708519423LLU,4398046510848LLU,18446607768627444800LLU,4337916706943LLU},{18446462699647512575LLU,3746782907566391264LLU,14987926783330877184LLU,17888158596789043151LLU,4337287823359LLU},{13835339528245607999LLU,18446744073445306399LLU,18446739692838715647LLU,558587059070027775LLU,4390526386172LLU},{18230569642328195455LLU,18446726481741610492LLU,18446744073457696767LLU,9167077041508462591LLU,4189677682675LLU},{18446737442246623223LLU,17293840161288552435LLU,14123288427407343615LLU,18230570740770406143LLU,3555226286031LLU},{18446691282093860859LLU,17365880098716073983LLU,18428734069975023600LLU,18446717444106813311LLU,3220680162395LLU},{18429644210773688295LLU,18446744073708568383LLU,18014140811428623LLU,14987025452231556288LLU,1872604742655LLU},{13853019662737997439LLU,18446744073457889535LLU,18428795920771465200LLU,4594770899617435647LLU,3223369759996LLU},{18433091231400468463LLU,18446726550242197373LLU,4611685812067618623LLU,16104235645945511360LLU,2027173564407LLU}};

static uint_fast64_t D[21][5] = {{15684084219791802367LLU,4611686018427387903LLU,1095232345683787776LLU,18428729676273811407LLU,4398046511103LLU},{15684084219791802366LLU,11529215046068469759LLU,11932751933911771818LLU,18446744073709551589LLU,4398046511103LLU},{7374345872345137153LLU,17971216948730880000LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{4611686018427387903LLU,9223372036854771712LLU,6879069588359042389LLU,18428729676273811423LLU,4398046511103LLU},{18446744073709551615LLU,14310585180260835327LLU,17351511728025763839LLU,18446744072635809840LLU,4398046511103LLU},{13835058055282163711LLU,7393056152619753471LLU,6513992139797779797LLU,18446744073709551578LLU,4398046511103LLU},{9223371761996583875LLU,18264304160156778495LLU,18446744073709551615LLU,18446739676736782335LLU,4398046494723LLU},{16597717909247306813LLU,17567482439431864320LLU,18446744073709551615LLU,18014397878601663LLU,4398046511100LLU},{18446744073695712195LLU,18173084203380391935LLU,17351511728025763839LLU,18446744073266690160LLU,4398046494723LLU},{15996214231238180863LLU,4611686018427387888LLU,14987926779036761343LLU,18165121177251479503LLU,4396976963523LLU},{17510857267535151103LLU,18446744073709550143LLU,4323521630152360704LLU,10369686062841724924LLU,4398042327294LLU},{17822722846417989601LLU,17581840962847509039LLU,18446744073709551360LLU,10087931223368662079LLU,4337916723198LLU},{14770954106499921983LLU,18374951457683142096LLU,18446744073706208511LLU,8365295570097473535LLU,4390089916413LLU},{18446744071690975775LLU,18389309980832432127LLU,18216211674031980543LLU,18446744041327379452LLU,4390526380223LLU},{18446743899737786339LLU,17365615185132273663LLU,14123222456458018815LLU,18446741289751870531LLU,4337287812931LLU},{17578569631080120311LLU,18446744073709353919LLU,13836180605113725891LLU,17288983736540462847LLU,3556230459902LLU},{18162858893691060095LLU,18446744073659219071LLU,4610629456472313660LLU,2301822013586534396LLU,4189738872575LLU},{18429007851237572543LLU,18442505456371891993LLU,18446743816011497727LLU,14302447247614277631LLU,1922903048191LLU},{14771801829941436543LLU,17298326100027373046LLU,18446744070434652159LLU,9049983450194120703LLU,3222555066329LLU},{18446740603373887463LLU,18442240542800674809LLU,14123288430427242495LLU,18338654933806742723LLU,1872354072551LLU},{14123248839320141567LLU,17298326168528745463LLU,18429852273346871283LLU,18289100338940076031LLU,2743676665308LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][5] = {{15684084219791802367LLU,4611686018427387903LLU,1095232345683787776LLU,18428729676273811407LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,4],[3,6],[4,7],[5,8],[5,9],[6,8],[6,10],[7,8],[7,11],[9,12],[9,13],[10,11],[10,12],[11,13],[12,13]]\n", fout);
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

