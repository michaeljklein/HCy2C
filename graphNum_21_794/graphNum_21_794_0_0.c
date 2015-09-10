#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_794_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][7] = {{274877906943LLU,18446739675797258240LLU,13862079651435773951LLU,18446744073709551615LLU,2251799813554171LLU,18446744073709535232LLU,255LLU},{18446744073709551615LLU,134217727LLU,18428729675200069632LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU,0LLU,18446744073692774400LLU,18446744073709551615LLU,255LLU},{18446743798831644672LLU,18446744073709551615LLU,18446594260938260451LLU,16672325577683230591LLU,18444492273910537983LLU,18446744073709551615LLU,255LLU},{0LLU,18446744073575333888LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{17726164285039575039LLU,133101535LLU,18446744073709551614LLU,13834061888618329599LLU,5330010158984590271LLU,18446744073441127002LLU,255LLU},{18446744073709518849LLU,18446744073642442739LLU,9205357638345293825LLU,18446744073709551552LLU,18446743936286851055LLU,18446739675931475967LLU,255LLU},{18430805553153310719LLU,18446744073705332095LLU,17448064121715455LLU,18446744056529682432LLU,17915319308989235199LLU,18445620985395672871LLU,255LLU},{9223372036846452735LLU,18445626969878953982LLU,18444492273694539775LLU,17179869183LLU,9223354511760818176LLU,18159639597462597630LLU,255LLU},{17726164010161700863LLU,4398045394911LLU,18446594260938260450LLU,17292977938014142463LLU,18444492411334817791LLU,18446744073441132543LLU,255LLU},{13835058123871084031LLU,18439988640177192959LLU,18184690844085256190LLU,2305842996328788223LLU,9225623836655747066LLU,14104696720458645503LLU,255LLU},{4611686014132219873LLU,18158509333736849408LLU,14123235653801992223LLU,18446673979843280895LLU,9223372036854726655LLU,4536179802142343168LLU,252LLU},{18446744059750907649LLU,16176506480745250619LLU,9223372036821221377LLU,18446744073645850620LLU,18446244894909861487LLU,13762754136548308983LLU,241LLU},{18445622571832410367LLU,18444438943554994167LLU,18428729675233624063LLU,8936267560609906627LLU,18379189117763190782LLU,17550518986129538559LLU,207LLU},{18433229701423038463LLU,1125899906826239LLU,18446741874686197734LLU,17292977920834273343LLU,18012164293163743231LLU,18445622571582881663LLU,255LLU},{9223372002226139135LLU,13816981534348440575LLU,16715043633903960063LLU,18158513713731014631LLU,9222772849725407231LLU,9206482988420705503LLU,206LLU},{13853072453716672319LLU,17292767012170235902LLU,18230571291428126719LLU,288230376101377020LLU,9799534820013899776LLU,14717763556470816766LLU,243LLU},{4340625615853891513LLU,18446603084965605376LLU,17493054076054142495LLU,18230567168427163647LLU,7457958715182759425LLU,4493463770034323392LLU,187LLU},{18442186591704054759LLU,18023401584897036287LLU,14987979043419185655LLU,18446678034291363831LLU,18293516128967720959LLU,18444368987908161599LLU,108LLU},{14987913589187147887LLU,18446160764679618559LLU,18446743523955828735LLU,9206430761694003185LLU,13821538177090912254LLU,15683785442471169535LLU,111LLU},{18445686085808785403LLU,2303555884367737079LLU,17852269472652394094LLU,18175965129001140175LLU,18391011349648900095LLU,8637051138413166543LLU,159LLU}};

static uint_fast64_t D[21][7] = {{18446744073709551615LLU,3258363126495576063LLU,9220893318659473377LLU,16360732760122576640LLU,18444492273908958831LLU,18446744073709551615LLU,255LLU},{6504701612836061182LLU,18446744073654180204LLU,9259400833873739775LLU,14220003975585241727LLU,18446744073702825170LLU,18446744073709551615LLU,255LLU},{11942042460873490433LLU,15188380947403564691LLU,18436161500261635394LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446739675797258239LLU,13838962333288737471LLU,4538332915684963839LLU,2251799805082553LLU,18446744073709535232LLU,255LLU},{18446744073709551615LLU,3258363126361358335LLU,9197925813283728061LLU,4226740098124309888LLU,18446744073699500845LLU,18446744073709551615LLU,255LLU},{16101872799756288000LLU,18446744073604423025LLU,4611686018427387903LLU,17678844566431063872LLU,18446743936284450534LLU,18446739675931475967LLU,255LLU},{8128993098119315455LLU,18446744073691083726LLU,13871086852301127679LLU,10375221297772507391LLU,5330010158980264347LLU,18446744073441127002LLU,255LLU},{2719887752144367149LLU,18445619760498276318LLU,18443198968794183643LLU,18446744073709551615LLU,9223354511777595391LLU,18159639597462597630LLU,255LLU},{18429588225019335123LLU,15188388156780022835LLU,18436888470774224998LLU,18446744073709551615LLU,17915319308989235199LLU,18445620985395672871LLU,255LLU},{16101872799756320767LLU,18446744073604423025LLU,3904278006573759LLU,9003767953828609984LLU,13118985714529222624LLU,18446739675931465125LLU,255LLU},{18446744069414383585LLU,13348238286968061951LLU,9221053853959446529LLU,18446673721930534887LLU,18445928007894240879LLU,4536179802142359551LLU,252LLU},{18446743867420564991LLU,8061883137644298239LLU,18445686311151501310LLU,219831940654559256LLU,18445308339711637502LLU,14104696720458645503LLU,255LLU},{9222246308448043007LLU,18444438943538115583LLU,16681333019780317183LLU,2017682988115901695LLU,9153565417984098298LLU,17550523349603249375LLU,207LLU},{17352369347545071615LLU,16176506480810770190LLU,15636497906230362111LLU,17293805870202811391LLU,14555134817382367263LLU,13762754170584249202LLU,241LLU},{1098020690008714797LLU,18446741262258798576LLU,18429802796426979231LLU,9003767953828610047LLU,3994692799146508256LLU,18159636786140139004LLU,255LLU},{13836183807985704223LLU,16640799424764706619LLU,18220719641070673918LLU,18446744073659216892LLU,9295148155412676607LLU,14987230693682051063LLU,243LLU},{18446476836129989619LLU,11211710308655038711LLU,16717291481341098087LLU,18446744072702857191LLU,18419124311555047423LLU,9222997239142546447LLU,206LLU},{18442186595869129215LLU,18303174242864201727LLU,18446741327052767223LLU,18432951731130204209LLU,18293489454755608575LLU,15852604511455543295LLU,111LLU},{18175683464977162175LLU,8070204230905888767LLU,18356742449770070014LLU,17451432399601630LLU,16679921692251782656LLU,16653745164803244031LLU,187LLU},{18221561620586233851LLU,143974244429049871LLU,17509995351216422510LLU,17293256165996625919LLU,17003478931535298079LLU,4610630486492692291LLU,187LLU},{14118784830122360687LLU,18337809941874081790LLU,15996785876388538367LLU,18446678034291422205LLU,11385016294823690751LLU,15922441278846354430LLU,117LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][7] = {{18446744073709551615LLU,3258363126495576063LLU,9220893318659473377LLU,16360732760122576640LLU,18444492273908958831LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU}};

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
        A[i][6] = A[i-1][6] & C[i][6];

    } else {
        A[i][0] = A[i-1][0] & D[i][0];
        A[i][1] = A[i-1][1] & D[i][1];
        A[i][2] = A[i-1][2] & D[i][2];
        A[i][3] = A[i-1][3] & D[i][3];
        A[i][4] = A[i-1][4] & D[i][4];
        A[i][5] = A[i-1][5] & D[i][5];
        A[i][6] = A[i-1][6] & D[i][6];

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
    fputs("[[0,1],[0,2],[0,3],[1,4],[1,5],[2,4],[2,6],[3,7],[3,8],[4,7],[5,9],[5,10],[6,9],[6,11],[7,12],[8,9],[8,13],[10,12],[10,13],[11,12],[11,13]]\n", fout);
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
