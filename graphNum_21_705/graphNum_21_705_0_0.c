#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_705_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][6] = {{18446744073709551615LLU,18446744073709551615LLU,16777215LLU,0LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,4095LLU,18446744073692774400LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{0LLU,18446744073709547520LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073172680704LLU,18446744073709551615LLU,18435438749090316287LLU,9033622545676359637LLU,18446744073701163008LLU,67108863LLU},{536870911LLU,18446743936270602240LLU,18446744073709551615LLU,18446744073709551615LLU,18446673704973762559LLU,67108863LLU},{18446744073172680705LLU,137438953471LLU,18446744073692774400LLU,18446744073709551615LLU,18446744073701163008LLU,67108863LLU},{18439988674268495871LLU,9146810843189476863LLU,16760830LLU,18446744073709547520LLU,18428782400218326719LLU,67108863LLU},{18446744057603424255LLU,18446717685430484987LLU,18446744073707454463LLU,4095LLU,13853070254640463865LLU,67108863LLU},{18445618174332870271LLU,14986290710020366335LLU,18446532966470379423LLU,17582048822085812223LLU,2846274947326672895LLU,67108832LLU},{1125899806179297LLU,18446739813110378496LLU,13853072453790859263LLU,18446744073705373695LLU,18445688559726755839LLU,67104799LLU},{18014398509481951233LLU,13835058166850649919LLU,18446727374876704767LLU,18378345654368862207LLU,8214565720323782656LLU,67046335LLU},{9223355543643521023LLU,4611686016816283646LLU,18446744073692774400LLU,18446744073457893360LLU,18443084899003926527LLU,66125561LLU},{15852670155494244031LLU,16139528852173995879LLU,18442240474086370751LLU,18446744073709551615LLU,4611611249619238887LLU,63950846LLU},{18385945478740049919LLU,8840566068528281087LLU,4503599627288562LLU,18446744004990074880LLU,18428817378431435839LLU,54195935LLU},{18446743542207348735LLU,18446506579197951979LLU,18442240474088472575LLU,68719476735LLU,36022197803810785LLU,63950846LLU},{18384820128589021183LLU,18446744073701193215LLU,4611474911188221942LLU,17582048753370525696LLU,18429802525818335231LLU,54198241LLU},{13836047615621331449LLU,18412966251340103679LLU,18176528096066412543LLU,18446744070488080191LLU,18439846850152628031LLU,45858591LLU},{4611685912125374439LLU,18446740638272581632LLU,14123288157629709439LLU,18445622571845287935LLU,18229657597005201407LLU,32366847LLU},{18405103369342386303LLU,13835339530251010047LLU,18446730878764711926LLU,18392697511195176975LLU,8633400300985624607LLU,54476775LLU},{9222524313387665383LLU,36025393787859198LLU,18446744073709550592LLU,18446744022119609340LLU,18435713773059571967LLU,24966893LLU},{14411505329443438591LLU,18446585743632105471LLU,18226085284137665535LLU,72057593836404723LLU,14985727209170403307LLU,47447930LLU}};

static uint_fast64_t D[21][6] = {{5321215147228790785LLU,10183157864411961908LLU,18446744073703474333LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{13125528926480760830LLU,18446744073709549003LLU,12292176720169009151LLU,7591268618456438421LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,8263586209297592319LLU,6154567353546619746LLU,10855475455253113194LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446743936270602239LLU,6160220015866937343LLU,15562036219269709183LLU,18446673704973762559LLU,67108863LLU},{18446744073709551615LLU,8263586209297596415LLU,18429786086769998690LLU,4327061781659763648LLU,18446744073701163008LLU,67108863LLU},{13125528926480760831LLU,18446744073709549003LLU,16957986945630207LLU,14119682292049787967LLU,18446673704973762559LLU,67108863LLU},{17140091035466386251LLU,17140103615993273272LLU,18446744073705846493LLU,18446744073709551615LLU,13853070254640463865LLU,67108863LLU},{6621112769924773045LLU,2189838703329098871LLU,18446744073705065918LLU,18446744073709551615LLU,18428782400218326719LLU,67108863LLU},{18446744073608888289LLU,8840561807920726015LLU,13836180437609791355LLU,4597278018052820991LLU,18445758911289152574LLU,67104799LLU},{18446744073702841983LLU,14409310988237012991LLU,18446466995711894406LLU,17311832585688576960LLU,2846274964491676609LLU,67108832LLU},{4014941706469244927LLU,18446744072098444798LLU,3529766573273251839LLU,14123274412395397104LLU,18443030383856451583LLU,66125561LLU},{17901597199964307455LLU,18446744047839084299LLU,14933918788549083135LLU,18374753533771594815LLU,8214549866743857151LLU,67046335LLU},{18383084549400620011LLU,17987374093123122174LLU,18446744073708929009LLU,18446744004990078975LLU,18428694284669001087LLU,54195935LLU},{14555633446031564319LLU,14986013600382951201LLU,18446744073693815967LLU,18446744073709551615LLU,36022197803810785LLU,63950846LLU},{9151526648435073505LLU,4037472838045692158LLU,18446744073708642288LLU,18446744073709551615LLU,18428817378431435839LLU,54195935LLU},{14555633995156553601LLU,18446462703456223009LLU,18443362856394161279LLU,4597278018057011199LLU,15636491309153189856LLU,63949119LLU},{18446743967407120383LLU,14411439642748387327LLU,18446743798837935119LLU,18445618190932243452LLU,13582856475715206133LLU,32370669LLU},{18446607734236248191LLU,18410838421990932479LLU,18446466996779222006LLU,17311836963384327939LLU,7487234376207544075LLU,45858802LLU},{576460432897212415LLU,18446744065253834720LLU,17361658022367198335LLU,1152855533908197375LLU,16068553747853148159LLU,63306879LLU},{13907044855374151679LLU,18446585743531835371LLU,18172024771317858303LLU,1125896685371199LLU,4899908966869368811LLU,48209726LLU},{18405226443777738727LLU,13871083424910929951LLU,14987979301385666559LLU,18445685179584344319LLU,18292996983100537087LLU,25125871LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][6] = {{5321215147228790785LLU,10183157864411961908LLU,18446744073703474333LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,6],[3,7],[4,8],[4,9],[5,10],[5,11],[6,7],[6,8],[7,12],[8,10],[9,12],[9,13],[10,13],[11,12],[11,13]]\n", fout);
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

