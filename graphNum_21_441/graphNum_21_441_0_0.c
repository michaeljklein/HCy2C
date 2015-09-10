#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_441_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][5] = {{72057593903710209LLU,18446726481523507200LLU,17293822586282573823LLU,18446744073709551615LLU,1023LLU},{18014398509481983LLU,18446726481523507200LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,17592186044415LLU,18446744056529682432LLU,18446744073709551615LLU,1023LLU},{18446744073575333888LLU,18446708889337462783LLU,17293822586282573823LLU,18446744073709551615LLU,1023LLU},{18392700878315323391LLU,18446744073709551615LLU,1152921504606846975LLU,18446744073705357312LLU,1023LLU},{18428729675200069632LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18428729675468505087LLU,70368744177663LLU,1152921487426977792LLU,18446744073705357312LLU,1023LLU},{72057594037919745LLU,18446744073709486080LLU,18446673722145243135LLU,18446744056533876735LLU,1023LLU},{18446744073575342079LLU,18446726481523572735LLU,17293892937846882303LLU,18446673722145243135LLU,1023LLU},{18446742974466359295LLU,70368744177663LLU,1152921504606846912LLU,18437801708059885312LLU,1023LLU},{18428730774711697407LLU,18446744073709551615LLU,18446744056529682495LLU,17302811901259940095LLU,1023LLU},{72050996947132353LLU,18446743197532094460LLU,18266106974829539583LLU,495395958478076415LLU,1023LLU},{18443929320116183103LLU,18428997952815955971LLU,1720305237811527679LLU,18446251475856654335LLU,1008LLU},{17572904450165055451LLU,18230571291327397884LLU,18442310520700665807LLU,7416865378625617789LLU,975LLU},{18446691297017723967LLU,18446726481791941635LLU,17298317922392621055LLU,18392419678082289663LLU,828LLU},{288222683865235395LLU,18014398505549820LLU,18446321345848406208LLU,1144477251580983552LLU,1023LLU},{18446674546757992447LLU,288229499978383359LLU,18266600088614469692LLU,11466135788899516611LLU,831LLU},{18428800040722622463LLU,18429855574855192575LLU,4608255524969119743LLU,17365879944067956735LLU,963LLU},{18445882056585377599LLU,18446744005208166339LLU,18378044937875701759LLU,18284539926491754495LLU,698LLU},{14987944323851468023LLU,14123270907966520383LLU,17365732759862837247LLU,16103539659316912115LLU,381LLU},{4611680589582401359LLU,4611685953999732684LLU,18392417891375903680LLU,4604856949157133071LLU,703LLU}};

static uint_fast64_t D[21][5] = {{18428729675468505087LLU,70368744177663LLU,1152921487426977792LLU,18446744073705357312LLU,1023LLU},{18428729675468505086LLU,12297817654349004799LLU,18446744067982928554LLU,18446744073709551615LLU,1023LLU},{12285819783198277633LLU,18446738209647536810LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18392700878181105663LLU,6148961603732635647LLU,1152921493153600853LLU,18446744073705357312LLU,1023LLU},{6196953087261802495LLU,18446679569027388757LLU,17293822586282573823LLU,18446744073709551615LLU,1023LLU},{6178938688752320511LLU,6148932283422561621LLU,18446744062256305493LLU,18446744073709551615LLU,1023LLU},{72057593903710209LLU,18446726481523507200LLU,17293822586282573823LLU,18446744073709551615LLU,1023LLU},{18436134241499611135LLU,3530611001625935871LLU,17293822556000501519LLU,18446673722142772841LLU,1023LLU},{18439339507678445567LLU,14916203440827793407LLU,2305843005136027888LLU,18446744056532152726LLU,1023LLU},{18230571291540309437LLU,18446739897944116467LLU,17970360302830616575LLU,17302811901264134143LLU,1023LLU},{288230376072952387LLU,18446730657288942348LLU,17770206357161508863LLU,18437801708059885567LLU,1023LLU},{18442469168406069247LLU,18428786846583488511LLU,567453551978889215LLU,18446210020295102463LLU,1008LLU},{18437587796118937599LLU,3530821231681011711LLU,18266107494517436431LLU,495367079648524393LLU,1023LLU},{18443867578955725887LLU,14987135134958877699LLU,16140892817302753276LLU,18392489771205511127LLU,828LLU},{17568323602330157019LLU,18159639597464682492LLU,4611685693079679171LLU,7416865619889305916LLU,975LLU},{18442469172398122431LLU,18446727576756882675LLU,17565106721221525503LLU,17960301506602258431LLU,1008LLU},{17582052941964567515LLU,18429842377481847804LLU,4022215535306473471LLU,18441395792527753215LLU,963LLU},{1152921246877302375LLU,288229280931118863LLU,18176102378908942332LLU,11525609747239665603LLU,831LLU},{14109775366956498931LLU,13839561654908747775LLU,9223231180181077247LLU,14409829947941060080LLU,479LLU},{18445683318792779743LLU,18443366373938679804LLU,13833914288244519875LLU,9002695579674622783LLU,747LLU},{18429820388486409727LLU,18433216781951646975LLU,8356389509054398463LLU,17545971225627713535LLU,469LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,3],[2,4],[3,5],[4,6],[4,7],[5,8],[5,9],[6,8],[6,10],[7,10],[7,11],[8,12],[9,10],[9,13],[11,12],[11,13],[12,13]]\n", fout);
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
