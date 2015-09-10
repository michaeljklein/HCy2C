#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_824_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][7] = {{18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU,0LLU,18446744069414584320LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,536870911LLU,18158513697557839872LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{0LLU,18446744073172680704LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446739675663040512LLU,18446744073709551615LLU,18442240336643225855LLU,17870219515368267255LLU,17870283325495507963LLU,18446744073709551615LLU,65535LLU},{4398046511103LLU,18446726482060378112LLU,14411411055345401855LLU,18410715276690587647LLU,576460752303161343LLU,18446744073705357312LLU,65535LLU},{18446682501058396159LLU,528482047LLU,18446744073709551488LLU,6908381075320207199LLU,17870283320852479550LLU,18446744004991693977LLU,65535LLU},{14987979559888977921LLU,18446744073709350911LLU,8935141660703064191LLU,18302628885633695740LLU,18446708893631381503LLU,18445618242522185727LLU,65535LLU},{18437595582915674111LLU,17293822568700051335LLU,72057529613152239LLU,18446739675663040512LLU,7917310140414427135LLU,18159049621426403455LLU,65535LLU},{17906312117350367231LLU,18446216308127694847LLU,18446462598717112315LLU,4398046511103LLU,18374156485002264576LLU,288227076480106480LLU,65532LLU},{18446678103011917823LLU,17592177655551LLU,18442240336643225728LLU,18446691284263370751LLU,17870318505643998846LLU,18446744004994269183LLU,65535LLU},{1097497763327LLU,18014398373116772348LLU,17843223515612839871LLU,18392771246925086671LLU,576460748276629503LLU,17580610349990674304LLU,65473LLU},{18446744004974342113LLU,18443348918705061891LLU,14986783256777066494LLU,18446744072640004095LLU,18446744073709545471LLU,13776492636942631039LLU,64575LLU},{18446743850371251969LLU,2305627230006340095LLU,9223372034707292280LLU,18302628885633682687LLU,18320432044765479393LLU,2301330682212249599LLU,61887LLU},{14970035529754575103LLU,18235072676091527103LLU,18158513699705323519LLU,18445895267912777724LLU,1149508757953183743LLU,17940097911723391999LLU,53235LLU},{567312815560326975LLU,18446743970462563300LLU,198157818832613375LLU,18429855575106650112LLU,8070450288508411879LLU,18428962153188290063LLU,62415LLU},{18446743519525597183LLU,17222325725723344799LLU,18300931188140802031LLU,14123266441201582079LLU,18289657671917240190LLU,18176510484081916415LLU,52863LLU},{18337809959187446271LLU,18437631319191060479LLU,18446445074189385627LLU,4131758292990LLU,15779377715683000288LLU,14123181744433659900LLU,45019LLU},{8791026445780779003LLU,11528792008969126015LLU,17293822569090097151LLU,18446744073645587519LLU,18428307441260167199LLU,4611683676478932947LLU,31548LLU},{4611628843956961087LLU,72057490958712812LLU,18446744063106349440LLU,18433198077567041539LLU,17874786680515231487LLU,18429855506924306079LLU,62415LLU},{18337813257709812711LLU,18444405409792950271LLU,16140884537392005119LLU,18014191344418815LLU,16140829596240046048LLU,10340174859220320252LLU,44287LLU},{15835782189673842683LLU,18392418840563648447LLU,18158531289731276799LLU,18445895525560483837LLU,4609119736813453311LLU,18013411010567707639LLU,24436LLU}};

static uint_fast64_t D[21][7] = {{10350826151859912705LLU,12782306458991119609LLU,18395825274856190132LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{8095917921849638910LLU,18446744073267524358LLU,9799832789158199295LLU,11990136194429508007LLU,18446744071078849483LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,5664437615160459263LLU,8697830083404713803LLU,6456607879280043608LLU,18446744072045286452LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446726482060378111LLU,14033089406514712575LLU,6852930174111840095LLU,576460750675630007LLU,18446744073705357312LLU,65535LLU},{18446744073709551615LLU,5664437615697330175LLU,9071647995169077323LLU,17437868423517506800LLU,17870283325458774136LLU,18446744073709551615LLU,65535LLU},{14076704322788229120LLU,18446744073541542839LLU,4611686018427387903LLU,17651284072686116340LLU,18446708891411983339LLU,18445618242522185727LLU,65535LLU},{9007131586299232255LLU,18446744073426943566LLU,14411518807585587199LLU,1103118008987742991LLU,17870283320441175582LLU,18446744004991693977LLU,65535LLU},{17885471818801762771LLU,13546275975522864383LLU,18432768868587323065LLU,18446744073709551615LLU,18374156489297231871LLU,288227076480106480LLU,65532LLU},{10362517959614639661LLU,16529325286586449793LLU,18193346158447419878LLU,18446744073709551615LLU,7917310140414427135LLU,18159049621426403455LLU,65535LLU},{14076704322788261887LLU,18446744073541542839LLU,198031351232548863LLU,18172304940372852732LLU,1152921501383624679LLU,18445618242520566630LLU,65535LLU},{18446744004974342113LLU,5760455767127752703LLU,9077559151285502062LLU,17437937756105067775LLU,18238781065740149112LLU,13776492636946825215LLU,64575LLU},{18446740773160803839LLU,17915002658331033599LLU,18412684560928079771LLU,18428730710286942144LLU,18078246329401638655LLU,17580610349990674431LLU,65473LLU},{18428732419163488255LLU,18235072675822157727LLU,17870283321406128127LLU,14950873242548371407LLU,573083051617943551LLU,17941214961004820991LLU,53235LLU},{9007198987372593151LLU,2305627229993302126LLU,14987979559889010680LLU,4598140034352136255LLU,18320432177910513664LLU,2301339395400328857LLU,61887LLU},{18443920527715230707LLU,18374700217112174335LLU,18440116080178282239LLU,14123270839247831039LLU,18442267961707200382LLU,12393906173990715391LLU,52862LLU},{18012043256782111LLU,13546822885896546812LLU,18419684265769303993LLU,18429855575106912255LLU,18374686347601256423LLU,6340743918333194112LLU,62413LLU},{2292314517143531449LLU,9762677087210012675LLU,17040424721016915454LLU,18446744073645587519LLU,9196332846904508415LLU,18277295925061714015LLU,31551LLU},{17292727730088966255LLU,18286855219408928765LLU,18446726481992874887LLU,18446743807421333502LLU,14554505965450821631LLU,18328392040797175807LLU,45019LLU},{18118262775888208883LLU,18446740218972211135LLU,18444493339041341439LLU,13852226997817704447LLU,11529207349453645823LLU,12393673765253028854LLU,52862LLU},{2292314583852359615LLU,9241104917437874175LLU,18160765488370548223LLU,18446740770878651393LLU,9189286983153647359LLU,18298406752896417759LLU,31717LLU},{18374646931600047983LLU,9221036604905226220LLU,16140901062817741696LLU,4598140025775588351LLU,17906241680961437664LLU,16091360858562887357LLU,46559LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][7] = {{10350826151859912705LLU,12782306458991119609LLU,18395825274856190132LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,4],[1,5],[2,4],[2,6],[3,7],[3,8],[4,9],[5,10],[5,11],[6,10],[6,12],[7,9],[7,10],[8,11],[8,12],[9,13],[11,13],[12,13]]\n", fout);
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

