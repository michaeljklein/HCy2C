#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_488_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][5] = {{4611686017890516993LLU,18428729675200069632LLU,1125899906842623LLU,18446744073709535232LLU,255LLU},{576460752303423487LLU,18428729675200069632LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18014398509481983LLU,18445618173802708992LLU,18446744073709551615LLU,255LLU},{18446744073172680704LLU,18410715276690587647LLU,1125899904745471LLU,18446744073709535232LLU,255LLU},{14411518808122458111LLU,18446744073709551615LLU,18446744073709551615LLU,18446739675663056895LLU,255LLU},{17870283321406128128LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{9223372036854775807LLU,15612478708217719LLU,12298204682440933376LLU,18446739675663035050LLU,255LLU},{18446726482597249023LLU,18446744073709551615LLU,18445618173803757567LLU,18446735277348110335LLU,255LLU},{15564457904378478591LLU,72057594037927935LLU,18446744073708503040LLU,18446735277884964863LLU,255LLU},{4611686018427355137LLU,18446744073642442752LLU,1125899906842623LLU,18444509866081910783LLU,255LLU},{18446744073172713471LLU,18428729675267178495LLU,18446744073709551615LLU,18160765497371508736LLU,255LLU},{17870300914665914367LLU,72057594037927935LLU,18445618173805854720LLU,18446739675663056895LLU,255LLU},{4318943108707385217LLU,18429851451938307072LLU,18374967748489117503LLU,14123163052612243263LLU,255LLU},{18446532961034043519LLU,14123288414254007295LLU,72057593786269695LLU,4609574954491346928LLU,252LLU},{18356669332380982911LLU,18446743798835823615LLU,4395457161220535295LLU,13819294769349656512LLU,241LLU},{4609997116492742625LLU,18428729950077976512LLU,18429855559000784880LLU,17311836954726481983LLU,207LLU},{18444527390622220287LLU,72057594037927935LLU,18446744056533876720LLU,9114441203955286015LLU,206LLU},{17872517597753245695LLU,18446744073709551615LLU,18445618190981529615LLU,14974358826756603903LLU,243LLU},{18419651280419846271LLU,17582052944247522303LLU,17365876039921692927LLU,4611228414882316284LLU,187LLU},{4611545276618475513LLU,14987913573018370044LLU,1149543804684992511LLU,18409026425756515571LLU,108LLU},{18445618138939554279LLU,18428800042937368515LLU,17568542133487402995LLU,8430457018870383612LLU,159LLU}};

static uint_fast64_t D[21][5] = {{17870300914665914367LLU,72057594037927935LLU,18445618173805854720LLU,18446739675663056895LLU,255LLU},{17870300914665914366LLU,12285819783466713087LLU,18446368773739555498LLU,18446744073709551615LLU,255LLU},{10376275948201836545LLU,18435935434603862425LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{14411518807585587199LLU,6196953087261802495LLU,18445993473773753685LLU,18446739675663056895LLU,255LLU},{9223372036854775807LLU,18385495118777312870LLU,1125899903696895LLU,18446744073709535232LLU,255LLU},{8646911284551352319LLU,6171732929348527718LLU,18445993473772705109LLU,18446744073709551615LLU,255LLU},{17293804977095617195LLU,18437136394504494557LLU,18446744073709551615LLU,18446735277348110335LLU,255LLU},{2305825416848692565LLU,18443141194007655219LLU,12298204682441981951LLU,18446739675663035050LLU,255LLU},{18446744073351637675LLU,18432332554901966028LLU,6149665291171266559LLU,18446735277616518485LLU,255LLU},{18208573790881841151LLU,18230571291595767807LLU,18446476824725435328LLU,18160763680221020159LLU,255LLU},{18108471197493624831LLU,288230376151711743LLU,18445885422789971007LLU,18444507285185921023LLU,255LLU},{4611686017890516993LLU,18428729675200069632LLU,1125899906842623LLU,18446744073709535232LLU,255LLU},{18356423034261766143LLU,13907115632207331327LLU,18446687998352241663LLU,4501347138440937456LLU,252LLU},{18005940807934148607LLU,18429851451938308095LLU,18445688268741738240LLU,13947644682801762111LLU,255LLU},{4316972724149813217LLU,4611686018427387840LLU,18429010927106129712LLU,17581188679585628159LLU,207LLU},{18311420849044823679LLU,14123288431370945535LLU,4395443142195609855LLU,13833684832304922623LLU,241LLU},{18446744073299009055LLU,18429851194177339455LLU,4341470040785158143LLU,14974363207890620175LLU,243LLU},{4611686018301059553LLU,18445622554732281792LLU,14106399932831236095LLU,9114441220867748080LLU,206LLU},{4178764292895539193LLU,18446673979843280892LLU,18442310839604150268LLU,15789616990529518655LLU,111LLU},{18411840111042887679LLU,18429855575106912255LLU,18446739679958003715LLU,16568707578419728383LLU,187LLU},{17906154883967328255LLU,14987979559826096127LLU,4610564516364685311LLU,16130693472096026623LLU,117LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][5] = {{17870300914665914367LLU,72057594037927935LLU,18445618173805854720LLU,18446739675663056895LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,4],[3,6],[4,6],[5,7],[5,8],[6,9],[7,10],[7,11],[8,10],[8,12],[9,10],[9,13],[11,12],[11,13],[12,13]]\n", fout);
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
