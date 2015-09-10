#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_549_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][6] = {{18446744073441116161LLU,1048575LLU,18446744073709550592LLU,18410715276959023103LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,31LLU,18446744073709550592LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,1023LLU,18446744073441116160LLU,18446744073709551615LLU,1023LLU},{18446744073441116160LLU,18446744073709551615LLU,6770414371844651007LLU,18410715276916916215LLU,18446744073709551615LLU,1023LLU},{268435455LLU,18446744073708503072LLU,18446744073709551615LLU,36028797018963967LLU,18446744073709289472LLU,1023LLU},{0LLU,18446744073709551584LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,17831296277613117439LLU,18446742974197924341LLU,18425160222101209087LLU,18446744071562330111LLU,1023LLU},{18446739676199911423LLU,18446744073709551615LLU,1099511627775LLU,36028796750528512LLU,18446726483670990832LLU,1023LLU},{4398046511103LLU,18446744073708503136LLU,18446742974197927935LLU,18446744073709551615LLU,18446744071562067983LLU,1023LLU},{18329509745909555201LLU,18446726481524279035LLU,18446744073709551615LLU,18446742974466310143LLU,18442256966189842431LLU,1023LLU},{13835058055013736447LLU,17592185978879LLU,18445622571849219072LLU,18410716376189632511LLU,17298321738337091583LLU,1023LLU},{18158452108261588991LLU,14987979559889010671LLU,274072342527LLU,17329569891144957948LLU,463870214010695567LLU,1023LLU},{18446739692809224163LLU,18433233274563198974LLU,18446744022169944015LLU,1148400308766900227LLU,18446463148488622064LLU,1008LLU},{18428734072038570943LLU,18445687714691936383LLU,18433233274760334591LLU,18356665338063486975LLU,12091883524504942607LLU,975LLU},{18014132213121023LLU,18446744073708507104LLU,18446742974265032700LLU,575334852396576780LLU,18300324307122522111LLU,828LLU},{18374633687005257759LLU,14987961967971393535LLU,1125899906596863LLU,17365597592947212284LLU,1148697765031706527LLU,1023LLU},{18445899099022563831LLU,18158530258901401087LLU,14987913589188198399LLU,18446604228487086079LLU,13767497319919386365LLU,747LLU},{11673330199517199999LLU,288230311727087615LLU,18229515756406569984LLU,16105012953425641279LLU,15060037059202764799LLU,446LLU},{18428795919701868519LLU,18445899648527757566LLU,18433233223220985855LLU,18374682078135455743LLU,18437227800563251312LLU,963LLU},{2304997828359946239LLU,18159639597463698912LLU,18446690201931612156LLU,4610428177124421887LLU,18248550499423633149LLU,633LLU},{18374651144974885375LLU,18176510572599959521LLU,288176568801230847LLU,8358574324491219964LLU,4572243919076392895LLU,639LLU}};

static uint_fast64_t D[21][6] = {{15252148224115343359LLU,18446744073709551596LLU,17514494552797351935LLU,36028796813688844LLU,18446744073709289472LLU,1023LLU},{15252148224115343358LLU,18446744073709551596LLU,6459664531540584447LLU,18446744073599019686LLU,18446744073709551615LLU,1023LLU},{3194595849594208257LLU,6456638589284384819LLU,18446744073709551194LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073708503071LLU,17825244393101418495LLU,36028796882113885LLU,18446744073709289472LLU,1023LLU},{18446744073709551615LLU,11990105484425166847LLU,932249520912200101LLU,18410715276895862771LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,11990105484425166815LLU,11987079542168967589LLU,18446744073551648089LLU,18446744073709551615LLU,1023LLU},{18446739675823852739LLU,6764362487333650367LLU,18446744073709551455LLU,36028797018963967LLU,18446726483670990832LLU,1023LLU},{3194595849970266941LLU,17523572379563851891LLU,18446744073709550832LLU,18425160222101209087LLU,18446744071562330111LLU,1023LLU},{18446744073601928387LLU,923171694145699839LLU,932249520912203535LLU,18432299128504205299LLU,18446726483670990847LLU,1023LLU},{10663105993753231359LLU,18446744073709486063LLU,18445618431753441279LLU,11493186249032989759LLU,17298321738336931049LLU,1023LLU},{18306865957844287487LLU,18446744073709274872LLU,17514498692893130751LLU,6989586621477618636LLU,18442256966189740822LLU,1023LLU},{8022459048659812321LLU,18429011149908959482LLU,18446744022169944000LLU,18438831984009543679LLU,18446480190030184447LLU,1008LLU},{13330588926181356351LLU,14069029990397550439LLU,18446743248270265599LLU,18428269641252995071LLU,463870760360472463LLU,1023LLU},{18446743807374782203LLU,4381989191739768831LLU,4395249353522937804LLU,570179757233139712LLU,18300323403023777791LLU,828LLU},{18446744072432327047LLU,14986870217097871359LLU,14970233442216705087LLU,18347375488021577727LLU,12091866840712609791LLU,975LLU},{572236875247157247LLU,18429011150176549374LLU,18446744006048088000LLU,11521302960378477631LLU,17987372513198284025LLU,1008LLU},{16145384810636902015LLU,18446744009284978687LLU,18176528091789082623LLU,14267403567768796940LLU,16137927916204835799LLU,446LLU},{18445652390733412855LLU,18446743042866806008LLU,14109777374849597439LLU,8863083859431916543LLU,13833541690769964604LLU,747LLU},{13330654888410211967LLU,17997841409941479LLU,4395248528083910652LLU,17868065829791203324LLU,6663075290953936895LLU,831LLU},{18433213480193490447LLU,14987979491236640767LLU,18158795172484168767LLU,18203268152031133695LLU,14410523629299170263LLU,479LLU},{16700469985050329071LLU,18445899648578057215LLU,18445899645495278595LLU,16107119666829197119LLU,17572891797118507507LLU,470LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][6] = {{15252148224115343359LLU,18446744073709551596LLU,17514494552797351935LLU,36028796813688844LLU,18446744073709289472LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,4],[3,6],[4,7],[5,8],[5,9],[6,8],[6,10],[7,10],[7,11],[8,12],[9,11],[9,13],[10,13],[11,12],[12,13]]\n", fout);
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

