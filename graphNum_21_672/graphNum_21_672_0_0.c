#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_672_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][6] = {{18446744073575333889LLU,137438953471LLU,18446744073642442752LLU,1152921504606846975LLU,18446744073701163008LLU,17592186044415LLU},{18446744073709551615LLU,8191LLU,18446744073642442752LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,67108863LLU,17293822569102704640LLU,18446744073709551615LLU,17592186044415LLU},{18446744073575333888LLU,18446744073709551615LLU,18291193964570607615LLU,565164188905592285LLU,18446744073701163008LLU,17592186044415LLU},{134217727LLU,18446743936270606336LLU,18446744073709551615LLU,18446744073709551615LLU,18445618173811097599LLU,17592186044415LLU},{0LLU,18446744073709543424LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18230571291595767807LLU,18086454179374563263LLU,64999103LLU,10376293541461622720LLU,1054706527784863LLU,17592186044414LLU},{9223372002763472895LLU,4611686018427383806LLU,18446744073701163007LLU,17293822569102704703LLU,18446167928549145855LLU,17592185978881LLU},{18445618173925850663LLU,18438774813423058943LLU,18446744073708993519LLU,18446532967473086463LLU,18446743936278986751LLU,17592177682131LLU},{1125899839684607LLU,18446743936278978560LLU,18446739675897921529LLU,18392700053547384831LLU,18302629023072649215LLU,17591120691199LLU},{18446180917597691905LLU,16140901165423295483LLU,18446480190918885375LLU,288230311727202255LLU,17933333716189314816LLU,17576075492606LLU},{18412958280277041151LLU,2305842991907471103LLU,18446744073642442752LLU,18443366373988958463LLU,16137523364766941439LLU,17334194397153LLU},{18229445426048663167LLU,18439987024992698303LLU,4398046502911LLU,11529003939832004544LLU,144043858332680191LLU,17592177721342LLU},{9223230747724742655LLU,13835058038102290031LLU,4607462862975941119LLU,18446744072635809852LLU,18446000767280725759LLU,16664202313473LLU},{14123253214849531843LLU,9222811285119303678LLU,14987926767224750079LLU,8070450533321670655LLU,18446731960895143416LLU,14290329141503LLU},{13836114672987521023LLU,18446744072642363391LLU,14069245218957295517LLU,18388464734757191679LLU,10368407951037689855LLU,14138906501119LLU},{4611685879373586943LLU,16149908127385313280LLU,18446739692842713083LLU,18446744021100396543LLU,18022284206825799439LLU,16753727896895LLU},{17863527917669060595LLU,576427680761636607LLU,18446744073709549568LLU,9219976812862370047LLU,18445055223715037310LLU,12042241037177LLU},{18419709556550531967LLU,18336405328686612455LLU,18374967748422797311LLU,16140901064495796223LLU,14391217418439524319LLU,8315039121383LLU},{18297003779850043127LLU,18442212986266845183LLU,72057594037917703LLU,13835041562604598208LLU,2304716430567704574LLU,12043080955898LLU},{14969961836949012431LLU,9222843720913387519LLU,18379137289789112319LLU,14987997152074993663LLU,17293820364971310585LLU,6457398792167LLU}};

static uint_fast64_t D[21][6] = {{6411536456866594815LLU,18446744073709546796LLU,233325163775524863LLU,18175458542654586675LLU,18445618173811097599LLU,17592186044415LLU},{6411536456866594814LLU,18446744073709546796LLU,12220054327925932031LLU,17768558247656641945LLU,18446744073709551615LLU,17592186044415LLU},{12035207616842956801LLU,15367176656175248083LLU,18446744073670128457LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446743936270606335LLU,6304464800420200447LLU,18265887053006241655LLU,18445618173811097599LLU,17592186044415LLU},{18446744073709551615LLU,3079567417534316543LLU,18213418909973449910LLU,271285531054964940LLU,18446744073701163008LLU,17592186044415LLU},{18446744073709551615LLU,3079567417534308351LLU,6226689745823042742LLU,17972008395155614310LLU,18446744073709551615LLU,17592186044415LLU},{2862037528919592323LLU,1719018172452939518LLU,18446744073696345071LLU,18446744073709551615LLU,18446167928549145855LLU,17592185978881LLU},{18180369308573053565LLU,17899554607814704019LLU,18446744073672836633LLU,10376293541461622783LLU,1054706527784863LLU,17592186044414LLU},{18446744073642393599LLU,16915234052502454271LLU,18446739675677585080LLU,7999517754967145727LLU,18303754785534987019LLU,17591120691199LLU},{18446744073698475559LLU,4603108178463293439LLU,18213418910193228263LLU,10664256723398738892LLU,18446744073706714356LLU,17592177682131LLU},{9188313545693986815LLU,18446744056403324527LLU,3692106237916217343LLU,18388464734757126207LLU,16136779907672834047LLU,17334194397153LLU},{15635618035472007167LLU,18446744037198035384LLU,14987699116778192895LLU,17365668989006774211LLU,17932951273393356799LLU,17576075492606LLU},{2862037563089030619LLU,549010257150469886LLU,18446744073646440440LLU,9152439259573992703LLU,18446167929610041451LLU,17591120664877LLU},{13870468857962807233LLU,18446181223742798843LLU,14987926767188049821LLU,1152921504606846975LLU,12452448829329895416LLU,14290329206782LLU},{18433012410421047935LLU,17899556688866115079LLU,4607462862984315003LLU,18446744073709551612LLU,5995170676824612767LLU,16664202313727LLU},{18446743934653161535LLU,11529777996021825535LLU,18443155267747854847LLU,17582052879756230604LLU,18158513697505000967LLU,16754660703263LLU},{18446674791566737383LLU,9223238446190166015LLU,13839508878347460487LLU,11524712545952711679LLU,10376293510992553468LLU,14139030685683LLU},{16068839089054415743LLU,18336405326640218017LLU,18374690607135195135LLU,15059826047643287551LLU,16257869027534176223LLU,8514771648511LLU},{17437058140360142835LLU,16717328728098595326LLU,14987976258132901887LLU,9223354444732694467LLU,18373831523246800766LLU,12084389605502LLU},{1134907088275765727LLU,18311213864303198176LLU,18446743803063500799LLU,17298326117127503871LLU,18419654305664204747LLU,8514554510767LLU},{18297069616330139391LLU,16280512524072181791LLU,4611681895258781819LLU,18446744072699772864LLU,8824873185708056383LLU,12600622448510LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][6] = {{6411536456866594815LLU,18446744073709546796LLU,233325163775524863LLU,18175458542654586675LLU,18445618173811097599LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,6],[3,7],[4,6],[4,8],[5,9],[5,10],[6,11],[7,9],[7,12],[8,9],[8,13],[10,11],[10,12],[11,13],[12,13]]\n", fout);
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

