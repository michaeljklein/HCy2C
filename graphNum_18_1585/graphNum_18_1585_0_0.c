#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_18_1585_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 17;
static uint_fast32_t endhere = 0;
char str[28] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[18][7] = {{18446744073709551615LLU,18446744073709551615LLU,8388607LLU,18158513697557839872LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,262143LLU,18446744073701163008LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{0LLU,18446744073709289472LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446743798806478719LLU,18446743520727790591LLU,13835053657242992369LLU,288228211488190719LLU,18446744072635809792LLU,18446744073709551615LLU,17179869183LLU},{18229473926746381547LLU,15797967721246752595LLU,18446744073709492111LLU,18446744073709551615LLU,1073741823LLU,18446744073709551600LLU,17179869183LLU},{18375811829822259191LLU,16716939604266045439LLU,17870287719452639231LLU,18446744073206235123LLU,18446744073709551615LLU,18446744069414584335LLU,17179869183LLU},{8753519803131494399LLU,18446744073709464575LLU,574741101060030463LLU,17581193022369431551LLU,11529003872188596223LLU,18446603339710856975LLU,17179869183LLU},{15553179250389282813LLU,13248319068265775037LLU,18446744073709485181LLU,14987979559889010687LLU,18446744073531289180LLU,16141041801964887295LLU,17179869183LLU},{18446744073306898307LLU,18446744072652587007LLU,18374157906634318815LLU,18410451393899921152LLU,9223367707506769919LLU,2305843008138376189LLU,17179868672LLU},{18446570350872301695LLU,18320579513542475747LLU,18446744073608888319LLU,4611686018420572415LLU,18226283196247374323LLU,18446744073709551615LLU,17175675391LLU},{18446744065119617024LLU,18446744073709551615LLU,18442170070709829631LLU,18444456814629084669LLU,18429855368948481920LLU,2232940990245617663LLU,17149459455LLU},{8589934591LLU,18437741272501059584LLU,18446744073709551615LLU,18446744073709551615LLU,16140883468987400191LLU,17870283187979026379LLU,16944939007LLU},{18446744070463159167LLU,18446743314559926271LLU,4576220169221242609LLU,270495287955357951LLU,18446744073709289472LLU,18194516106297614335LLU,16366166527LLU},{72057319156350927LLU,2301902359137088511LLU,18446739677810524159LLU,18446744065656487887LLU,18410714715123875839LLU,18443365523585499135LLU,13925089272LLU},{18446744073701167103LLU,9007199254740991LLU,15852650888544911358LLU,18302620089540411391LLU,13835022857621471231LLU,17293818307840835383LLU,11806769151LLU},{18446743944868921343LLU,18446744073709551135LLU,4611686018418999297LLU,17582052945254416383LLU,17568327483906803599LLU,4601979529777381375LLU,8296333263LLU},{18446744073709551615LLU,18446742931246153727LLU,18446744073705323967LLU,18446744039350337535LLU,17293892937846882303LLU,18428800041796500991LLU,6422003711LLU},{18445898549267791871LLU,18446744073696772095LLU,18446744073709551615LLU,15852670722703884287LLU,1152921504606715645LLU,16158913195262607344LLU,12213812863LLU}};

static uint_fast64_t D[18][7] = {{10851363662233337857LLU,144119149142735873LLU,18446744073708685156LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{7595380411476213758LLU,18446744073709290494LLU,17819964890320732159LLU,18421584178187770281LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18302624924567076863LLU,626779183389685915LLU,18183673593079621206LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18374717230965898739LLU,16392592418593046391LLU,18446744073709492223LLU,18446744073206235123LLU,1555225760095010815LLU,18446744069644478880LLU,17179869183LLU},{18446743249075830783LLU,18446743523952149503LLU,17870283321413467903LLU,7493989779944505343LLU,18446744072636304150LLU,18446744073479657055LLU,17179869183LLU},{18230569075333389935LLU,16122314903695392731LLU,13835058055282163585LLU,11240982505253236991LLU,16891518314687788265LLU,18446744073709551615LLU,17179869183LLU},{16131893865241112577LLU,18446741874686558177LLU,18374685929915809791LLU,18410715276690587647LLU,18227193591850072176LLU,15629461031810580477LLU,17176711925LLU},{9043016945527422975LLU,18446744073709502463LLU,576460752301309919LLU,18446744073709027328LLU,18446673706039017471LLU,9223317557610545151LLU,17179439003LLU},{18446708896845205503LLU,18311570114190770175LLU,18445055223723393021LLU,287385848134500351LLU,18445688542379114495LLU,16681112975701958655LLU,17179262463LLU},{17578393770086236159LLU,13257330665583471551LLU,18446185249072210047LLU,18446464796044820479LLU,2305843009205825503LLU,13806340658400587791LLU,17179869038LLU},{18446744073709551615LLU,18437739073478066175LLU,17130275569137614847LLU,18364970003807958871LLU,16140883468987400191LLU,17870283187979026379LLU,16944939007LLU},{18446744073709551615LLU,18302627123590332415LLU,1938673684961900699LLU,18263160403900747004LLU,18429855368948481920LLU,2232940990245617663LLU,17149459455LLU},{35184233742275LLU,283797144765202431LLU,18446744073709549567LLU,18446744065153171395LLU,2251746196387266559LLU,18443365519520430497LLU,13925089272LLU},{18446739637545187839LLU,18410697426797068151LLU,9187906189788717055LLU,18429011150176718847LLU,17714194279905099775LLU,18194516106297610238LLU,16366166527LLU},{18446744073709551615LLU,18446744073709551104LLU,18419300055711219711LLU,18433020493557609279LLU,17365876864605732991LLU,18289118086751551487LLU,8252291015LLU},{14973754353326751743LLU,18446744073709377535LLU,17906307995155824639LLU,18176528089215467459LLU,18446691296622936063LLU,16426879640699797489LLU,11643133693LLU},{18446744071272659775LLU,18442240333958611455LLU,18446744073709285366LLU,18446744073709551615LLU,18446744073351217151LLU,18446723079832794975LLU,12213644863LLU},{4557625157696059351LLU,7995822554566622959LLU,18446744073701687295LLU,8646911284551352319LLU,18446744073172671415LLU,9223265912642076671LLU,6421741531LLU}};

uint_fast8_t X[18] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[18][7] = {{10851363662233337857LLU,144119149142735873LLU,18446744073708685156LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17179869183LLU}};

#if UINTPTR_MAX == 0xffffffffffffffff // 64-bit. Hopefully this means the cpu has 'popcnt'.
int counter (uint64_t * buf){
    uint64_t cnt[18];
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
            "popcnt %2, %2  \n\t"
            "add %2, %0     \n\t"
            "popcnt %3, %3  \n\t"
            "add %3, %1     \n\t"
            : "+r" (cnt[16]), "+r" (cnt[17])
            : "r" (buf[16]), "r" (buf[17]));


    return cnt[0] + cnt[1] + cnt[2] + cnt[3] + cnt[4] + cnt[5] + cnt[6] + cnt[7] + cnt[8] + cnt[9] + cnt[10] + cnt[11] + cnt[12] + cnt[13] + cnt[14] + cnt[15] + cnt[16] + cnt[17];
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
    sprintf(str, "[                  ,%5d]\n", this);
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
    fputs("[[0,3],[0,5],[0,6],[1,4],[1,6],[1,8],[2,5],[2,6],[2,7],[2,8],[3,5],[3,7],[4,7],[4,8],[5,7],[5,8],[6,7],[6,8]]\n", fout);
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

