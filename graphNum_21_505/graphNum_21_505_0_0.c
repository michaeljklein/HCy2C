#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_505_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][5] = {{3458764514088976383LLU,288230376151695360LLU,18446744073642442752LLU,13835058056355905535LLU,17179869183LLU},{1152921504606846975LLU,18374686479671623680LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,72057594037927935LLU,0LLU,18446744073709551600LLU,17179869183LLU},{18446744073705357312LLU,18302628885633695743LLU,17822280109931888639LLU,18446744073675997189LLU,17179869183LLU},{1152921504611041279LLU,18446744073709535232LLU,18446744073709551615LLU,18446673704998928383LLU,17179869183LLU},{18446744073705357313LLU,18374686479671640063LLU,18446744073709551615LLU,18446744073675997199LLU,17179869183LLU},{18446744073709551615LLU,69207651308765183LLU,18446744073642442752LLU,13835128424019517423LLU,17179869183LLU},{18446744073449504767LLU,18446744073709551615LLU,67108863LLU,4611686017387200496LLU,17179852800LLU},{17293822569102704640LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{9040932123304786945LLU,18446744069414593946LLU,18446744073709551615LLU,16544676918587285519LLU,17179623423LLU},{18446744073705358335LLU,18374686483966590975LLU,18446726481791942655LLU,4611686018393841663LLU,17175936960LLU},{18446744073457892355LLU,18446744069414649855LLU,17592186044415LLU,18446744072702910480LLU,17179607103LLU},{4611668426476224511LLU,288230376151711680LLU,18230571291595766784LLU,18428799770005864447LLU,17150476287LLU},{17293840161288683519LLU,18446691297151402047LLU,18446744073642443775LLU,13853002359924850687LLU,16944463871LLU},{17581840962848523263LLU,18446739679957999477LLU,18446744005208166348LLU,2266963685349793791LLU,16365912060LLU},{18446744073705390019LLU,18374690877701423103LLU,18428782520477679615LLU,18446744073676258847LLU,13887863811LLU},{18446744073474638911LLU,18446739688564719615LLU,18014330058440703LLU,4611686017487610352LLU,16365929468LLU},{4611685949975936503LLU,287171543232151548LLU,18445898772606091260LLU,18445688526437478323LLU,11805908853LLU},{18442240542700994559LLU,18446744073709550595LLU,14771806777774964739LLU,18159635216195387391LLU,8296235007LLU},{3463268044996542463LLU,287333174663431164LLU,18446744073642704892LLU,14122166913464795135LLU,11608260607LLU},{18442505456380805071LLU,18375812379562736847LLU,18429839082432248895LLU,18217056987990982271LLU,6423575759LLU}};

static uint_fast64_t D[21][5] = {{18446744073706210307LLU,18378961393765384191LLU,17510048128043057151LLU,4611686018400657424LLU,17179852800LLU},{17769349693998891006LLU,12249790986447749119LLU,11985597400584202922LLU,18446744073709551605LLU,17179869183LLU},{1830315884317507585LLU,18400130649048842240LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{1152921504606846975LLU,6341068275337641984LLU,6773378655014180181LLU,18446673704998928383LLU,17179869183LLU},{18446744073709551615LLU,18205127122218549247LLU,17510048128043057151LLU,18446744073675997184LLU,17179869183LLU},{17769349693998891007LLU,288230376151711743LLU,936695945666494464LLU,18446673704998928383LLU,17179869183LLU},{16140901064228275203LLU,18401555620413439999LLU,18446744073709551615LLU,4611686017387200511LLU,17179852800LLU},{4136158893538737149LLU,18442469159615791104LLU,18446744073709551615LLU,13835128424019517423LLU,17179869183LLU},{17293822569102704639LLU,6243566511922511871LLU,6461146673125348693LLU,18446744073709551610LLU,17179869183LLU},{17860569651025543167LLU,17582052945254416383LLU,18446726481539436300LLU,4611644673964900351LLU,17175936960LLU},{8949712166278135807LLU,1152921504606840218LLU,936695945919000819LLU,16544647894339158015LLU,17179623423LLU},{12955796421267880959LLU,17577778031160711781LLU,18446744073658371852LLU,15737154234712842239LLU,17175937023LLU},{18446744073707343451LLU,18392633875671875583LLU,17568317623735681023LLU,9223372036837110492LLU,16944457114LLU},{18446744073674798503LLU,18433018815244926975LLU,18172301795903143935LLU,13835058055138356531LLU,17150466661LLU},{9165937944228265923LLU,14987979559872296415LLU,18428747267382770943LLU,17717009061817351711LLU,13891517503LLU},{17365615184898424831LLU,4611686018427375408LLU,936748722430133184LLU,14929660573154017279LLU,16365944831LLU},{4539893402664370175LLU,14119013530225078479LLU,18446744073705372735LLU,17352141555965100031LLU,13887864831LLU},{18442258066199015263LLU,18392700671808764991LLU,14109764435190744063LLU,8953151935758695167LLU,8287876575LLU},{18446744073709034739LLU,18445618444653101055LLU,18445687447330226175LLU,18446744073705416592LLU,11608248112LLU},{18446744073605736207LLU,18379189821333569535LLU,13836167458488057855LLU,4611686017999517823LLU,8296231119LLU},{17365880098581880063LLU,4611681891232239612LLU,4611685953939963900LLU,14987082344978769904LLU,12213669884LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][5] = {{18446744073706210307LLU,18378961393765384191LLU,17510048128043057151LLU,4611686018400657424LLU,17179852800LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,4],[3,6],[4,7],[5,6],[5,8],[6,9],[7,10],[7,11],[8,9],[8,12],[9,13],[10,11],[10,12],[11,13],[12,13]]\n", fout);
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

