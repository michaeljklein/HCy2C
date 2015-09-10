#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_542_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][6] = {{18446744073575333889LLU,1048575LLU,18446744073709551360LLU,18442240474149289983LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,15LLU,18446744073709551360LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,255LLU,18446744073642442752LLU,18446744073709551615LLU,255LLU},{18446744073575333888LLU,18446744073709551615LLU,15958458550343171583LLU,18442240474138762719LLU,18446744073709551615LLU,255LLU},{134217727LLU,18446744073708503056LLU,18446744073709551615LLU,4503599627370495LLU,18446744073709535232LLU,255LLU},{0LLU,18446744073709551600LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,9031395064670060543LLU,18446744004990075005LLU,18444035757459898367LLU,18446744073441132543LLU,255LLU},{18446741874954731519LLU,18446744073709551615LLU,68719476735LLU,4503599560261632LLU,18446739675931475966LLU,255LLU},{2199023255551LLU,18446744073708503088LLU,18446744004990075903LLU,18446744073709551615LLU,18446744073441116161LLU,255LLU},{18302598099308101633LLU,18446673704966143549LLU,18446744073709551615LLU,18446743524020834303LLU,18445622296899895295LLU,255LLU},{16140901064361656319LLU,70368744112127LLU,18446726756401413888LLU,18442241023834849231LLU,18159638427337752575LLU,255LLU},{18388126901487009791LLU,17582052945254416375LLU,17293822586266046463LLU,18307097300888977407LLU,13951025711595642651LLU,255LLU},{9223369846404677571LLU,18446744072640004095LLU,1152921501385621491LLU,143552236042059776LLU,4611615684042946558LLU,252LLU},{18437737943364796287LLU,18446744060824641599LLU,3746783783738672127LLU,17933333711844016124LLU,13546154778012172224LLU,243LLU},{9006924376340479LLU,18374964656112410608LLU,18446744004991123455LLU,13835041493888073727LLU,17276934070233710655LLU,206LLU},{18410688880357392447LLU,17581982577583980159LLU,17293840161276166143LLU,18311600352908005375LLU,14122232593180950399LLU,255LLU},{16131929032299642751LLU,72057581152952831LLU,18446727581034090240LLU,18154027685821546492LLU,13276611699858866115LLU,243LLU},{18446321728077422579LLU,1152868727985798143LLU,72054295502995443LLU,16212184327067270144LLU,4575080819080298487LLU,187LLU},{8142506063627746767LLU,18443366166823911423LLU,18442521945586008063LLU,2287826392823366655LLU,18444294632373220606LLU,108LLU},{1152498914180071415LLU,4544132023965514736LLU,18446744005258461183LLU,12105521866475371523LLU,9173823438450312183LLU,158LLU},{18410697609342338039LLU,18392630784263716592LLU,17298326104292982783LLU,17185726866288278591LLU,14978118976200953727LLU,159LLU}};

static uint_fast64_t D[21][6] = {{7650837312938442751LLU,18446744073709551606LLU,3732428285049570303LLU,4503599576052528LLU,18446744073709535232LLU,255LLU},{7650837312938442750LLU,18446744073709551606LLU,11053686620789844479LLU,18446744073681918362LLU,18446744073709551615LLU,255LLU},{10795906760771108865LLU,10856589195755913241LLU,18446744073709551510LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073708503055LLU,8637200214602897407LLU,4503599593158517LLU,18446744073709535232LLU,255LLU},{18446744073709551615LLU,7590154877953638399LLU,14714315788659981417LLU,18442240474133499087LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,7590154877953638383LLU,7393057452919707241LLU,18446744073670076005LLU,18446744073709551615LLU,255LLU},{18446741874767010179LLU,15564263700276707295LLU,18446744073709551575LLU,4503599627370495LLU,18446739675931475966LLU,255LLU},{10795906760958830205LLU,4323720560149266489LLU,18446744073709551420LLU,18444035757459898367LLU,18446744073441132543LLU,255LLU},{18446744073656048003LLU,14123023513560285183LLU,14714315788659982275LLU,18444948790383152335LLU,18446739675931475967LLU,255LLU},{14676456252972728319LLU,18446744073709486071LLU,18446726497692553215LLU,3742491290340753344LLU,18159638427337742723LLU,255LLU},{8971136150060138495LLU,18446744073709272636LLU,3732428543758431231LLU,14708756382941692735LLU,18445622296899888764LLU,255LLU},{3889698305088487361LLU,4594797518751609789LLU,18446744070488326128LLU,18445752312140922879LLU,4611620047615670271LLU,252LLU},{16070963328807298687LLU,17310975985582525555LLU,18446744022153416511LLU,18444429382689751039LLU,13951025745532575515LLU,255LLU},{18446743798831133159LLU,18374752518837108735LLU,18389322353826856959LLU,13835040891784150223LLU,17276932201920856063LLU,206LLU},{18446742943542796059LLU,14123235637951725567LLU,71777218572844995LLU,17931539030621540348LLU,13546152248815386622LLU,243LLU},{286118437623496703LLU,4594797519824516095LLU,18446744069481447408LLU,3746003130479869888LLU,4496843059638825447LLU,252LLU},{8971169973464461799LLU,18446739744130580476LLU,18374967938479292415LLU,10322250224868524095LLU,17293372993329686143LLU,206LLU},{17296065571682415871LLU,18442518392825909119LLU,18442521948790718271LLU,18426474482362220543LLU,16569728187203812383LLU,111LLU},{16140355702425374591LLU,17948414926321907LLU,17365876813066080255LLU,18374413384176107519LLU,15789057325739335667LLU,187LLU},{18439978776951520287LLU,17582052670644940671LLU,18442244872127905551LLU,18416309558503788543LLU,17437688985155502046LLU,119LLU},{17573607029379891167LLU,18443366373183678463LLU,18446730879367708416LLU,8930917335888560124LLU,13616594989364018638LLU,117LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][6] = {{7650837312938442751LLU,18446744073709551606LLU,3732428285049570303LLU,4503599576052528LLU,18446744073709535232LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,4],[3,6],[4,7],[5,8],[5,9],[6,8],[6,10],[7,9],[7,11],[8,12],[9,13],[10,11],[10,13],[11,12],[12,13]]\n", fout);
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

