#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_750_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][6] = {{36028797018898433LLU,18446744004991123456LLU,18446742974197925887LLU,18446744073709551615LLU,18445618242522185727LLU,4398046494720LLU},{18446744073709551615LLU,1048575LLU,18446742974197923840LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,1099511627775LLU,0LLU,18446744073708503040LLU,4398046511103LLU},{18446739675663040512LLU,9223372036854775807LLU,15987180542839748608LLU,18293619341293247999LLU,18446744039350853119LLU,4398046511103LLU},{4398046511103LLU,18446744004991123456LLU,18446741874686296063LLU,16140302929631248349LLU,18445618208162316253LLU,4398046511103LLU},{18410724072783609855LLU,13835058055283212287LLU,8608489950230347775LLU,17834245144044337151LLU,1125865547069439LLU,4398046511103LLU},{18446744073709486081LLU,4611686018427387903LLU,18446734178104901632LLU,9220979497396338551LLU,18446744073707978615LLU,4398046494720LLU},{18230571291058896895LLU,18446181123755998191LLU,960982142975LLU,18446744073441116160LLU,18158192433467228159LLU,4398044425660LLU},{18446743523951771647LLU,17870281259821825983LLU,18446744073642442751LLU,268435455LLU,13818160751964061696LLU,4397780172671LLU},{18410719674737164287LLU,4611686087146864639LLU,18446744073709549568LLU,18446744073709551615LLU,1125865549201407LLU,4398046511103LLU},{0LLU,18446744073708503040LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{17798225727368199679LLU,18446744073172023915LLU,17293822979922161663LLU,1152920405363654655LLU,18445839931553153023LLU,4394019720346LLU},{18302505739528167391LLU,18445901839179153406LLU,1152921470246051832LLU,18446744073441116160LLU,17888297581436465407LLU,4333620166653LLU},{14118503216169189363LLU,18299250739223199743LLU,18446479366284918511LLU,18374686479940059135LLU,17866341846018424831LLU,4190531215347LLU},{18446741324916324351LLU,15564425466637969343LLU,72057587528368127LLU,72057594037923840LLU,4544052833282949120LLU,3560276228991LLU},{18410851616400866815LLU,13835339529722003199LLU,17293840161020311559LLU,18446742978492891135LLU,288230342328844287LLU,4394019733503LLU},{29238007013834497LLU,18230536106957340640LLU,18446744073675998845LLU,18446480190917902335LLU,18446735346336006143LLU,3211557011328LLU},{18445055198079418623LLU,18419722407493238815LLU,18446742974231478175LLU,1152921504606846960LLU,18445626969895731184LLU,1919263129727LLU},{14843758815760482295LLU,18443665028826529791LLU,18446480190918680569LLU,18374687578914820095LLU,17362501774205776127LLU,4140334317557LLU},{4611686018417948431LLU,18446734175705753504LLU,18446744067166699519LLU,18446480190917898255LLU,18401621215932317711LLU,2722803743503LLU},{18412962712808062783LLU,13871076956495151073LLU,17298326168698615935LLU,18446743042917396735LLU,2260800385720520703LLU,2745423429535LLU}};

static uint_fast64_t D[21][6] = {{18446741283425878015LLU,15520919580380758015LLU,17592186044415LLU,17298308580587274495LLU,1125865549136127LLU,4398046511103LLU},{11889495827927924734LLU,18446744073708884779LLU,11068046884030382079LLU,11068046444225730969LLU,18446744073709132185LLU,4398046511103LLU},{6557248245781626881LLU,7537510511757896916LLU,18446743673426522112LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744004991123455LLU,8608485952466866175LLU,14374583427926882252LLU,18445618208162215884LLU,4398046511103LLU},{18446744073709551615LLU,1685861525098594303LLU,14757389981311825920LLU,8991292398771883127LLU,18446744039350324343LLU,4398046511103LLU},{11889503016258043904LLU,18446744073708884779LLU,15987167348700217343LLU,4454972476823428403LLU,18446744073707707699LLU,4398046494720LLU},{18410716884453425151LLU,18446744073709551615LLU,3689360689467490303LLU,15221554535133426653LLU,1125865546920925LLU,4398046511103LLU},{6614933659845682851LLU,8204430449691045789LLU,18446743777253375183LLU,18446744073709551615LLU,13818160751965110271LLU,4397780172671LLU},{18172885327237060957LLU,17202798371935123686LLU,18446743831286104880LLU,18446744073709551615LLU,18158192433467228159LLU,4398044425660LLU},{11889503016258109439LLU,18446744073708884779LLU,18446726881806536703LLU,1148435493122277120LLU,18445618242521202432LLU,4398046494720LLU},{18446744073709551615LLU,10909233561952321535LLU,7378697589962199039LLU,7378697629483820646LLU,18446744073708922470LLU,4398046511103LLU},{6917397085977364423LLU,9223090615506382846LLU,18446744017873272824LLU,18446744073709551615LLU,18159639596929904895LLU,4333508755455LLU},{17567696749705788603LLU,17427804622779842073LLU,18446743248566172879LLU,1152920405363654655LLU,13834466234557595647LLU,4393866878555LLU},{18427582867377738591LLU,14969949756237767142LLU,72057551598910398LLU,18446744073709547520LLU,9169218872883019775LLU,3560527460799LLU},{13863803476993064433LLU,18226243561736699647LLU,18446479159858038369LLU,18446744073709551615LLU,17581207487921520639LLU,4190544236528LLU},{1008806316530976711LLU,18446744058618382270LLU,18446744007068409855LLU,18442258066251513600LLU,18446522384677597184LLU,4333508752229LLU},{18445052444866248703LLU,15532769154632253439LLU,67835469387267999LLU,4503534951202800LLU,3289879499562287088LLU,1919263145983LLU},{18439953246633983999LLU,18191664935207960575LLU,18378926196508327549LLU,18446462667451269375LLU,15157990439696400639LLU,3211557011455LLU},{18418029477146652735LLU,14096266829441785857LLU,17365880154552793503LLU,1152921504606846975LLU,4611547454191501311LLU,3570577274911LLU},{18444562608347102719LLU,18410785318479396607LLU,18442257035207638915LLU,18379190014622826495LLU,16281920023797170175LLU,2060777885695LLU},{14843794002867326967LLU,18446532628165173247LLU,18446742982787653627LLU,18374967954380947440LLU,18299391235934126064LLU,2022886590453LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][6] = {{18446741283425878015LLU,15520919580380758015LLU,17592186044415LLU,17298308580587274495LLU,1125865549136127LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,4],[1,5],[2,4],[2,5],[3,6],[3,7],[4,8],[5,9],[6,8],[6,10],[7,10],[7,11],[8,12],[9,11],[9,13],[10,13],[11,12],[12,13]]\n", fout);
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
