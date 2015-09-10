#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_743_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][6] = {{70368744046593LLU,1152921502459379712LLU,18446744073441116160LLU,18446744073709551615LLU,18428729950073782335LLU,16383LLU},{18446744073709551615LLU,16383LLU,18446744073441116160LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,268435455LLU,18442240474082181120LLU,18446744073709551615LLU,16383LLU},{18446743523953737728LLU,17311836967612186623LLU,15987178197787607039LLU,3940503642824159LLU,18446744073709551584LLU,16383LLU},{549755813887LLU,18446744071562084352LLU,18446744073172680703LLU,18446706689743781885LLU,18446744073705357343LLU,16383LLU},{18446674804477001727LLU,18437736874454827007LLU,8608480570021773311LLU,18444491689771366271LLU,18446743798835838943LLU,16383LLU},{18446744073709420545LLU,9007199254740991LLU,18446744071293632512LLU,18442090938219102199LLU,18428729950077976575LLU,16383LLU},{8493648159732400127LLU,16140901064495855071LLU,225959287LLU,18446744073709551615LLU,17880880139594999231LLU,16383LLU},{18446744073642704895LLU,18446742978492891135LLU,18446744073709551615LLU,16145404664123228160LLU,576460751233875967LLU,16383LLU},{18446674254721318911LLU,17302829770504929279LLU,18446744073709551615LLU,9007199254740991LLU,18446743798835838944LLU,16383LLU},{0LLU,18446744073709535232LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446675354299924479LLU,17320845266378555391LLU,4294967295LLU,2305843009213693951LLU,17888297446111444960LLU,16383LLU},{14987135134954879739LLU,4611685952908087292LLU,18446744073508172799LLU,18311636084887388160LLU,17861099650470076287LLU,16368LLU},{18446744071633371135LLU,18446710057568567295LLU,18446462603027808255LLU,139611588449533951LLU,1152921487494086654LLU,16143LLU},{13835110763120819713LLU,863565228539936767LLU,18446744073709547520LLU,18446727581035134975LLU,13690872773340020799LLU,15547LLU},{4611681616085778943LLU,18374616108788334592LLU,18446744073441120255LLU,18446744073457893375LLU,17239849742314258431LLU,13294LLU},{18446677555399622655LLU,17356908083833470975LLU,281474976710655LLU,18311636084887388175LLU,17906311860664139745LLU,16368LLU},{18446743798414305279LLU,18442233636393582531LLU,1152920409389203455LLU,11024811819083563007LLU,14987134994063622127LLU,11215LLU},{18429855556265574375LLU,18446435377229725695LLU,18378909703833911280LLU,7471471850527125759LLU,4611682671834168570LLU,7743LLU},{13853072453514815007LLU,18446739538115559363LLU,18446743042916413455LLU,13546811118004994047LLU,11528304648158757887LLU,11679LLU},{18429855573999493095LLU,18446725929754017855LLU,18446480190651498480LLU,17289336561409720319LLU,8053558725979667710LLU,5999LLU}};

static uint_fast64_t D[21][6] = {{18446743743064440831LLU,18441326784214466559LLU,4294967295LLU,4783979370643471LLU,18446743798835838944LLU,16383LLU},{6148960723331710974LLU,18446744073709540693LLU,11068046444333105151LLU,18444942633858603417LLU,18446744073709551615LLU,16383LLU},{12297783350377840641LLU,11543639534818323114LLU,18446744073620073130LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,6917529025493614591LLU,8608480569037509973LLU,18444435613822711676LLU,18446744073705357343LLU,16383LLU},{18446744073709551615LLU,17297412478862360575LLU,14757395257679151103LLU,3509419787472071LLU,18446744073709551584LLU,16383LLU},{6148961603732504576LLU,18446744073709540693LLU,15987178194566381567LLU,18441453074303016403LLU,18428729950077976575LLU,16383LLU},{18446673924076077055LLU,18446744073709551615LLU,3689348817641013247LLU,18443328113836503869LLU,18446743798835838943LLU,16383LLU},{17274399696130986707LLU,13817042558145327034LLU,18446744073641311214LLU,16149908263750598655LLU,576460751233875967LLU,16383LLU},{3517031813912407341LLU,13867496945952190671LLU,18446744073645837363LLU,18446744073709551615LLU,17880880139594999231LLU,16383LLU},{6148961603732635647LLU,6917529027641070933LLU,18446744069504062805LLU,18446463693966278640LLU,18428729950073782335LLU,16383LLU},{18446744073709551615LLU,6903104538891239423LLU,7378697629465924949LLU,18444041913933129318LLU,18446744073709551615LLU,16383LLU},{14929714239709827795LLU,4611686017164169008LLU,18446744073504830412LLU,18446463693966278640LLU,565864208988265087LLU,16383LLU},{18217058291610005423LLU,18410681191493270735LLU,18446462603014438707LLU,2305843009213693951LLU,18425903914209900030LLU,16143LLU},{287108655247947897LLU,68468786442683388LLU,18446744073457828095LLU,18446744073709551615LLU,17892536612115386175LLU,16368LLU},{18446739393094615039LLU,18370056878588690431LLU,1148435432741011455LLU,14758577453601455887LLU,17257793607159513068LLU,13294LLU},{18446726360432377855LLU,18156529740494667775LLU,17298308645263507455LLU,3692934106552664319LLU,13690942757256822771LLU,15547LLU},{18159639597464651655LLU,18446744073204268035LLU,18446744073692839680LLU,18446463693966278655LLU,1148682887280783615LLU,16143LLU},{18428773561175277537LLU,719027817806316543LLU,18379190079047335920LLU,18428729675200065791LLU,18217056335173778491LLU,7929LLU},{288190377119178879LLU,17791399924691107776LLU,1152921504605798655LLU,18374686479670640639LLU,18121376455345311727LLU,11254LLU},{18446730846249582591LLU,18230025369577047039LLU,18374704071606009855LLU,17262578846687817743LLU,18325146823088406520LLU,6140LLU},{14123235139199696511LLU,17573604108921733119LLU,72056563245773055LLU,13438741223648006143LLU,18014345524433375207LLU,11763LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][6] = {{18446743743064440831LLU,18441326784214466559LLU,4294967295LLU,4783979370643471LLU,18446743798835838944LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,4],[1,5],[2,4],[2,5],[3,6],[3,7],[4,6],[5,8],[6,9],[7,9],[7,10],[8,11],[8,12],[9,13],[10,11],[10,12],[11,13],[12,13]]\n", fout);
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

