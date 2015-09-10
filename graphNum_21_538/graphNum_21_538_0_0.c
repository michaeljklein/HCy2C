#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_538_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][5] = {{18446744065404827715LLU,18446744072638959615LLU,1152939028074463231LLU,4071254063013167042LLU,67107840LLU},{288230376151711743LLU,18442240474082181120LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,4503599627370495LLU,17293822569102704640LLU,18446744073709551615LLU,67108863LLU},{18446744073705357312LLU,18437736874454810623LLU,970478979579740159LLU,18446744073709420544LLU,67108863LLU},{288230376155906047LLU,18446744073709550592LLU,18446744073709551615LLU,18446743798831775743LLU,67108863LLU},{18446744073705357313LLU,18442240474082182143LLU,1152921504606846975LLU,18446744073709420544LLU,67108863LLU},{18446744073709551615LLU,3755201573943295LLU,17293822569102700544LLU,18442240748960024701LLU,67108863LLU},{18446744065128005631LLU,18446744073709551615LLU,17293822569102708735LLU,4503599493283839LLU,67108860LLU},{864691137045069823LLU,18014398509480960LLU,18446744073709547520LLU,18442240474216398847LLU,67108863LLU},{14771701173119350785LLU,18446744072635810035LLU,1152921504606846975LLU,18443312772797169600LLU,67107843LLU},{18446744073705359359LLU,18442240475155922943LLU,18446726756400381951LLU,14379993610193862719LLU,66847743LLU},{18441956662383214591LLU,14771806777775226879LLU,18446744004990078771LLU,17874786876737585151LLU,66759679LLU},{18446744065388052419LLU,18446744073708507135LLU,1152921573326323711LLU,576460752173400062LLU,66584512LLU},{1152903916027903999LLU,18014398509481980LLU,17581841787469692927LLU,18446726752162807807LLU,63962523LLU},{18158531289743822847LLU,18446742978492890115LLU,18446744073709547520LLU,18442257795685283967LLU,54510591LLU},{15996715473064425535LLU,18446744072636857847LLU,18446744004991123455LLU,17904024584479571905LLU,66845759LLU},{4611668494956691455LLU,67555093922185212LLU,18446727581034151935LLU,14960941465423710207LLU,63717375LLU},{18158513697557839872LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18444509864974601975LLU,18446744009234661315LLU,13830835930379845568LLU,9151050529944108663LLU,46134135LLU},{4325706411296767999LLU,17365813161650814015LLU,18446744073709547583LLU,18442518409200519679LLU,25104383LLU},{18444616518706122751LLU,1148488209299144652LLU,18446730879569231811LLU,16122662336623165055LLU,48034815LLU}};

static uint_fast64_t D[21][5] = {{4575780435428184063LLU,70934996960935692LLU,18446744073709550595LLU,18445671916996855935LLU,66847743LLU},{18396335434134192126LLU,12294826982721454079LLU,17971215642993715882LLU,18446744073709551615LLU,67108863LLU},{338639015727071233LLU,18444115872984684544LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{288230376151711743LLU,6160924290242837504LLU,17860572262332093781LLU,18446743798831775743LLU,67108863LLU},{18446744073709551615LLU,18431357875924936703LLU,879257717066186751LLU,18446744073709420544LLU,67108863LLU},{18396335434134192127LLU,18014398509481983LLU,17567486356643364864LLU,18446743798831775743LLU,67108863LLU},{17870283312818221123LLU,18444490072011399167LLU,18446744073709551615LLU,4503599493283839LLU,67108860LLU},{915099768036855741LLU,18445621476629409792LLU,17293822569102704639LLU,18442240748960024701LLU,67108863LLU},{18446744073707384899LLU,18443363071162322943LLU,2032179221673033727LLU,4503599627302786LLU,67108860LLU},{18432381840233857023LLU,72057594037927935LLU,18446726550241938435LLU,14379993477314117631LLU,66847743LLU},{14735654767019687935LLU,18392700878181104883LLU,17567486562801808380LLU,18443312630799269887LLU,67107843LLU},{7979208092391530433LLU,18445845996046910041LLU,1152921504606846975LLU,18444885624180660990LLU,66584515LLU},{11377848338288586687LLU,14771582258356682150LLU,18446744073709551411LLU,18444099154197065085LLU,66759679LLU},{18446744073709487335LLU,18446742975019761663LLU,4554264295122092031LLU,8426234902810196007LLU,54510590LLU},{18446744068724554587LLU,18443363074635452415LLU,15059756714020634623LLU,10025012770448799706LLU,63962521LLU},{9194647570187247615LLU,3746096812310658909LLU,18446726550242983119LLU,14410804036439595775LLU,66410495LLU},{18194419345952603367LLU,18446744073457646835LLU,4539909895087977468LLU,9003768636676505575LLU,54525542LLU},{18158513697557839871LLU,6154545291712964607LLU,17769350999818540373LLU,18446744073709551615LLU,67108863LLU},{4611684983205592031LLU,17365810893101989887LLU,17365876800181043199LLU,16996581694286841822LLU,32456157LLU},{18446744072046509683LLU,18443366373926047743LLU,11524715844219437055LLU,2179742219621302259LLU,48234291LLU},{18194542487933024719LLU,18446744072701934847LLU,8074954063424254975LLU,18011020672218693582LLU,25165004LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][5] = {{4575780435428184063LLU,70934996960935692LLU,18446744073709550595LLU,18445671916996855935LLU,66847743LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,4],[3,6],[4,7],[5,8],[5,9],[6,8],[6,10],[7,9],[7,11],[8,10],[9,12],[10,13],[11,12],[11,13],[12,13]]\n", fout);
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
