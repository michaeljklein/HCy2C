#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_583_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][6] = {{18446744073575333889LLU,1048575LLU,18446744073709551360LLU,18442240474149289983LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,15LLU,18446744073709551360LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,255LLU,18446744073642442752LLU,18446744073709551615LLU,3LLU},{18446744073575333888LLU,18446744073709551615LLU,8466158170014744063LLU,18442240474147149663LLU,18446744073709551615LLU,3LLU},{134217727LLU,18446744073708503056LLU,18446744073709551615LLU,4503599627370495LLU,18446744073709535232LLU,3LLU},{0LLU,18446744073709551600LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,9186630712812371967LLU,18446743798831644765LLU,18442933564698787839LLU,18446744073441132543LLU,3LLU},{18446742974466359295LLU,18446744073709551615LLU,274877906943LLU,4503599560261632LLU,18446739675931475967LLU,3LLU},{1099511627775LLU,18446744073708503088LLU,18446743798831645695LLU,18446744073709551615LLU,18446744073441116160LLU,3LLU},{4611679421357588481LLU,18446462598733692735LLU,18176528096067321855LLU,18446742974265032703LLU,18446466983844069375LLU,3LLU},{18156261897609969663LLU,281474976692223LLU,18446727581035134720LLU,18442241573593808655LLU,18429010943208325119LLU,3LLU},{18337813240811092479LLU,18446743042917400575LLU,274625265663LLU,18163017245645602812LLU,18314978531785834087LLU,3LLU},{18446725399191551987LLU,18429855575043997693LLU,18446744022169931775LLU,288223778612183043LLU,17437638758735278077LLU,3LLU},{18428730568016392191LLU,18446730879570010175LLU,18446532967460242431LLU,14978972223194333183LLU,14699674416944529280LLU,3LLU},{18014394201931743LLU,4611686017621041136LLU,14987979285027880956LLU,18374264266132815871LLU,4572279521421541503LLU,3LLU},{12092162766031290113LLU,18446744056530628543LLU,18446744070475743036LLU,17867750038092890367LLU,13690911256220777407LLU,2LLU},{9223297268451606783LLU,17311555509814689143LLU,18172042088625995775LLU,18419659812372479999LLU,17275561863714537471LLU,1LLU},{18156129269151969279LLU,17293879743706543344LLU,18446743816011452415LLU,6917459071162646527LLU,16428287015511183353LLU,1LLU},{18446744060692527375LLU,1152920456701935615LLU,288213883477294848LLU,18226138001119888140LLU,13710082082485567487LLU,2LLU},{18446743041304987635LLU,17348711289009995775LLU,18172042088625995775LLU,1125839501952827391LLU,16428903825634492415LLU,1LLU},{18428870403981048639LLU,18446743232969696255LLU,4611672824271142659LLU,18298688195157544764LLU,16055331949482606471LLU,2LLU}};

static uint_fast64_t D[21][6] = {{14724745481351593983LLU,18446744073709551609LLU,14970878855542211583LLU,4503599563472112LLU,18446744073709535232LLU,3LLU},{14724745481351593982LLU,18446744073709551609LLU,7307536430625630719LLU,18446744073686111834LLU,18446744073709551615LLU,3LLU},{3721998592357957633LLU,10778971371684757526LLU,18446744073709551526LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073708503055LLU,16129500594931324927LLU,4503599584771573LLU,18446744073709535232LLU,3LLU},{18446744073709551615LLU,7667772702024794111LLU,3475865218167340121LLU,18442240474146079503LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,7667772702024794095LLU,11139207643083920985LLU,18446744073665882533LLU,18446744073709551615LLU,3LLU},{18446742974311485859LLU,15409028052134395871LLU,18446744073709551607LLU,4503599627370495LLU,18446739675931475967LLU,3LLU},{3721998592512831069LLU,4556574032362733622LLU,18446744073709551372LLU,18442933564698787839LLU,18446744073441132543LLU,3LLU},{18446744073688895907LLU,13890170041346818047LLU,3475865218167341043LLU,18446050983156843279LLU,18446739675931475967LLU,3LLU},{17974657043679674367LLU,18446744073709533177LLU,14987961984023793663LLU,6408622269697097472LLU,18429010943208312145LLU,3LLU},{1071285683064143871LLU,18446744073709354815LLU,18159428474911323135LLU,12042625403575926015LLU,18446466983844065966LLU,3LLU},{12963582940007903217LLU,18428786849738270396LLU,18446744022169931580LLU,18444202414673231871LLU,17437643087964188669LLU,3LLU},{9096211318041213023LLU,4557641726876309879LLU,18446744073456910287LLU,18445468574723080191LLU,18314978600066580071LLU,3LLU},{18446744069398715847LLU,274666593496072191LLU,13906267925855076348LLU,18374154022103806927LLU,4572276950881533951LLU,3LLU},{18446743866996876219LLU,18227176271333294079LLU,4557365745968742387LLU,14978389376670633791LLU,14699672589974896639LLU,3LLU},{18410327559521959935LLU,17311836967611661811LLU,18442240542751080447LLU,6885942257547214847LLU,17269615716944699251LLU,1LLU},{16268110097283022847LLU,18446744073709496317LLU,14987979504307130172LLU,17363346888350220288LLU,13679401362354858397LLU,2LLU},{17212194776464488719LLU,18446743025804640255LLU,4503596191449087LLU,17618081682680692988LLU,13726917998608906927LLU,2LLU},{2305702338834182143LLU,18446519773336501296LLU,18443154997173486591LLU,1125899219583959039LLU,16428907140023584760LLU,1LLU},{16141041788986064735LLU,4611686004737115135LLU,14987979555594108684LLU,18226771374041464828LLU,13710083165606115335LLU,2LLU},{2305842183505027063LLU,17568278263530323952LLU,18226348896362168319LLU,4593631212531089407LLU,8646759540957628415LLU,1LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][6] = {{14724745481351593983LLU,18446744073709551609LLU,14970878855542211583LLU,4503599563472112LLU,18446744073709535232LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,4],[3,6],[4,7],[5,8],[5,9],[6,10],[6,11],[7,12],[7,13],[8,10],[8,11],[9,10],[9,12],[11,13],[12,13]]\n", fout);
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

