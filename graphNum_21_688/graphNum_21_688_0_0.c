#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_688_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][6] = {{18446744073575333889LLU,4294967295LLU,18446744073708503040LLU,1125899906842623LLU,18446744073709547520LLU,67108863LLU},{18446744073709551615LLU,1023LLU,18446744073708503040LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,1048575LLU,18445618173802708992LLU,18446744073709551615LLU,67108863LLU},{18446744073575333888LLU,18446744073709551615LLU,17689530206867423231LLU,949829859013981LLU,18446744073709547520LLU,67108863LLU},{134217727LLU,18446744069414585344LLU,18446744073709551615LLU,18446744073709551615LLU,18446743798831648767LLU,67108863LLU},{0LLU,18446744073709550592LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446321861244485631LLU,18401708017306304463LLU,1031165LLU,11521333746720571388LLU,18445618397090676087LLU,67108863LLU},{18302628868722262015LLU,16717256263683014654LLU,18446744073709551615LLU,18013272609575141379LLU,13836183950356910076LLU,67108863LLU},{18446673704996957675LLU,18300374749357541375LLU,18446744073708764759LLU,18446739950289289215LLU,3902369077099761663LLU,67108800LLU},{70368744128127LLU,4610841589202549760LLU,18446743798835838975LLU,18446744073709490175LLU,18446726481540284415LLU,67092543LLU},{11475169651516760065LLU,18158513701745819647LLU,18176528096067321855LLU,1073120127483903LLU,17149563894759423999LLU,66992883LLU},{18445618070589284351LLU,288230375077433215LLU,18446727581034086400LLU,18446744073709550607LLU,4603751942521352192LLU,66187199LLU},{18446251509612019711LLU,18446744022169685967LLU,274877382399LLU,18439984550848233468LLU,4610577659100135423LLU,67108800LLU},{18294140655040987135LLU,18446744070486752318LLU,1152921246845790207LLU,18446744073705357315LLU,18375812168374274815LLU,63164223LLU},{18446743232969310147LLU,16717238740216446975LLU,18172042088625995715LLU,17878164620758220799LLU,13907115649318272972LLU,54476784LLU},{17293879709341301631LLU,13821265781389979647LLU,14987979558819455487LLU,16140901064495845375LLU,18446443080266546815LLU,49019967LLU},{1152921226507681527LLU,9222808258006219776LLU,18446532693672853503LLU,18428729606748979199LLU,18014382843588198399LLU,29328383LLU},{13792273858264293439LLU,18158531287524048127LLU,18446743867500685311LLU,144062408292303871LLU,17086656848670481151LLU,63887999LLU},{8141382215641079767LLU,288216355876372344LLU,18446744060019343296LLU,18355616485574967247LLU,15851539276383485888LLU,54388159LLU},{18446677999798968831LLU,18159639545924866047LLU,288213883476246591LLU,1146166105161858108LLU,4549990221957034047LLU,63176655LLU},{17302829205716467663LLU,17293735707652653055LLU,18226349165938474959LLU,18049301475313569791LLU,14411517156437852125LLU,41909493LLU}};

static uint_fast64_t D[21][6] = {{16846935104872775679LLU,18446744073709550988LLU,1135820800264241151LLU,18445882278874451955LLU,18446743798831648767LLU,67108863LLU},{16846935104872775678LLU,18446744073709550988LLU,11919222449052319743LLU,18446280738716689753LLU,18446744073709551615LLU,67108863LLU},{1599808968836775937LLU,4153701621156546163LLU,18446744073708721238LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744069414585343LLU,6906128558079344639LLU,18446169543819485175LLU,18446743798831648767LLU,67108863LLU},{18446744073709551615LLU,14293042452553007103LLU,17310923273446140841LLU,861794835099660LLU,18446744073709547520LLU,67108863LLU},{18446744073709551615LLU,14293042452553006079LLU,6527521624658062249LLU,18446081508795570854LLU,18446744073709551615LLU,67108863LLU},{4356106722473004419LLU,16282634294632380030LLU,18446744073709254487LLU,18014398509481983999LLU,13836183950356910076LLU,67108863LLU},{15545908902620967549LLU,4543287533803933635LLU,18446744073709000956LLU,11521333746720571391LLU,18445618397090676087LLU,67108863LLU},{18446744073709502079LLU,2259812496082731007LLU,18446743798832606205LLU,10861292502413935567LLU,18446726756401412211LLU,67092543LLU},{18446744073606917611LLU,16497702225615781887LLU,17310923273448586755LLU,7586309242710391868LLU,3902369077116532620LLU,67108800LLU},{18012524810403315711LLU,18446744072635273004LLU,1152904122056310783LLU,18445898772555758595LLU,4603751842029596671LLU,66187199LLU},{10308453943000170495LLU,18446744073602563551LLU,18159428281600835583LLU,18446674800248885247LLU,17149563720373280767LLU,66992883LLU},{4356106739553082903LLU,287108046220951166LLU,18446744073709447167LLU,17347601865734292431LLU,14545500891668019960LLU,67092543LLU},{15546422752518406081LLU,18446726485497561083LLU,18172042088625471168LLU,18303754785540538367LLU,18446524721138237383LLU,54476784LLU},{18437741169390596735LLU,4543287595326557191LLU,1152921246845764095LLU,11529215046068469759LLU,18445837543288076415LLU,63164223LLU},{18446743795509620723LLU,17654074289768366079LLU,18392423801249988595LLU,9047731582668897532LLU,8678436481942370286LLU,29343706LLU},{18446730845202151919LLU,17276860386041065471LLU,13906267925855068175LLU,14661464257576828735LLU,13238032037488623133LLU,49020901LLU},{17581911114628268031LLU,18446744073424310249LLU,18442240735269355200LLU,18445898772555759615LLU,4611557348704616391LLU,54394876LLU},{18441889729336041983LLU,18159639545924845023LLU,4503393418608639LLU,1146162806425452540LLU,18391715543781466111LLU,63897539LLU},{9006358514892759LLU,18446730054401523704LLU,18443155250643730431LLU,18355550510850707455LLU,14555625732410982399LLU,54472959LLU},{18446691228306073343LLU,8952593071141149703LLU,4611672566588776447LLU,4607182418796870908LLU,9182232452083479039LLU,30920671LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][6] = {{16846935104872775679LLU,18446744073709550988LLU,1135820800264241151LLU,18445882278874451955LLU,18446743798831648767LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,6],[3,7],[4,6],[4,8],[5,9],[5,10],[6,11],[7,9],[7,12],[8,12],[8,13],[9,11],[10,11],[10,13],[12,13]]\n", fout);
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

