#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_727_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][6] = {{18446744073575333889LLU,274877906943LLU,18446744073642442752LLU,4611686018427387903LLU,18446744073692774400LLU,17592186044415LLU},{18446744073709551615LLU,8191LLU,18446744073642442752LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,67108863LLU,13835058055282163712LLU,18446744073709551615LLU,17592186044415LLU},{18446744073575333888LLU,18446744073709551615LLU,15374714632883142655LLU,3881959246320891383LLU,18446744073692774400LLU,17592186044415LLU},{134217727LLU,18446743798831652864LLU,18446744073709551615LLU,18446744073709551615LLU,18445618173819486207LLU,17592186044415LLU},{0LLU,18446744073709543424LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18171954127695773695LLU,9079256848778919551LLU,67084095LLU,18446744073709550592LLU,910515886462719LLU,17592186044414LLU},{18446717681403953151LLU,18392692631843897343LLU,18446744073699065855LLU,1023LLU,18446744060566699836LLU,17592185978881LLU},{18437736874582610943LLU,15564440312125341695LLU,18446744073709354977LLU,18446678103010840575LLU,18302628610772566015LLU,17592169313265LLU},{9007199179243315LLU,18439935622899556352LLU,4611685949942267903LLU,14987135134958878716LLU,10367286617084788735LLU,17587907850239LLU},{16715954441915719681LLU,242237833155LLU,18446744073709551615LLU,4611684987572322303LLU,18444492273895862272LLU,17526905892039LLU},{18446740749270654975LLU,18446744073707880447LLU,17298322045494362112LLU,18217060492713656319LLU,16257994654790717439LLU,16561390534655LLU},{18392700878113996739LLU,9078139740670132087LLU,18445618173819475903LLU,14123288212377960447LLU,18303683592154044131LLU,16477222600703LLU},{13614310759335968767LLU,18446744073709058815LLU,1125899906826107LLU,18429842380162010112LLU,143680724484734975LLU,15049564422142LLU},{18446312995620387839LLU,17563896159980748799LLU,18230502022352502783LLU,4611686001247519683LLU,18446744034460827063LLU,13172658011905LLU},{288212780743655423LLU,18410708677607555070LLU,4557642818872406271LLU,13835058072462032895LLU,18446713278592614268LLU,8589682868479LLU},{18383694228677885903LLU,18445688538185334647LLU,18445618242522054631LLU,18446691297150435327LLU,18167449430704259047LLU,16479773784051LLU},{18446312995626680183LLU,18442203917459644417LLU,18446691232726908927LLU,5763763080925282252LLU,13827211901064445951LLU,13168638160655LLU},{17149706865630748735LLU,1125873868210127LLU,1152921504606830459LLU,18446743249025448960LLU,2303589008765857823LLU,15341051968990LLU},{18446741856836386679LLU,18442203949679173695LLU,17365876812999036927LLU,9223372019742015487LLU,12082102269022175231LLU,12366282358591LLU},{2305843006402723839LLU,18446738368382362110LLU,17528009694898286847LLU,4611756370058805247LLU,17292951755709906941LLU,16557971279679LLU}};

static uint_fast64_t D[21][6] = {{4047934856305311743LLU,18446744073709548157LLU,4608044161306722303LLU,14929648213441908492LLU,18445618173819486207LLU,17592186044415LLU},{4047934856305311742LLU,18446744073709548157LLU,10761814662082199551LLU,16544652014847174054LLU,18446744073709551615LLU,17592186044415LLU},{14398809217404239873LLU,10864247456019787138LLU,18446744073670027713LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446743798831652863LLU,9220944132107665407LLU,16102013500197789533LLU,18445618173819486207LLU,17592186044415LLU},{18446744073709551615LLU,7582496617689776127LLU,13838699912442353214LLU,3517095860267643123LLU,18446744073692774400LLU,17592186044415LLU},{18446744073709551615LLU,7582496617689767935LLU,7684929411666875966LLU,15737150114144541273LLU,18446744073709551615LLU,17592186044415LLU},{14410080642158252797LLU,15501381177257733610LLU,18446744073693624821LLU,4611686018427387903LLU,18446744060566699836LLU,17592185978881LLU},{18160656310636162307LLU,4388071685675318807LLU,18446744073675443979LLU,18446744073709551615LLU,910515886462719LLU,17592186044414LLU},{18446744073634053939LLU,9071308479221727231LLU,234187111919752767LLU,4898859819475140604LLU,10368412242103768793LLU,17587907850239LLU},{18446744073703134207LLU,14068820274661294079LLU,18216198750464671712LLU,13605305205052670195LLU,18302628885626874150LLU,17592169313265LLU},{4517036176468606975LLU,18446744073707876991LLU,17294944084921679871LLU,18159573622740275199LLU,16256911203773710335LLU,16561390534655LLU},{16246849797447745535LLU,18446744041069477825LLU,4611422121946513407LLU,14987134052560224012LLU,18444449825039581183LLU,17526905892039LLU},{10376292991820862207LLU,15501389839294020079LLU,18446744073706339833LLU,18429842380162011135LLU,18446453800507014975LLU,15049564395933LLU},{17868845160091582401LLU,18445618303563984882LLU,18446744073646502903LLU,288230157095796735LLU,18446744060812001248LLU,16477222561379LLU},{2250416757796763LLU,4608853674359488510LLU,4557642818838327327LLU,18446744073709551615LLU,14617523443604527103LLU,8589682933758LLU},{18446213988838455655LLU,17361130217060236823LLU,18230502022362959851LLU,18446744073709551555LLU,3830100324768677111LLU,13172658012159LLU},{10376293541436194367LLU,18375806803905608175LLU,234187180619316351LLU,9205427181398786044LLU,10376003270388432669LLU,15047854116255LLU},{18439987291287979999LLU,1116046083600121855LLU,18378344829735137280LLU,18216991223481105663LLU,17933333578750231406LLU,8589924545534LLU},{9205323000939249663LLU,18446743935193180030LLU,18446739689558635511LLU,13853019661127188479LLU,18419071274970972159LLU,15803194750843LLU},{16240525200674777055LLU,1116046083181248511LLU,4610630486459416575LLU,18446673722144406591LLU,18374679116956824430LLU,8753084100854LLU},{18257627558335914447LLU,71002041337118679LLU,18445622571849220075LLU,18446744073708715011LLU,8968915649820618983LLU,17527748165622LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][6] = {{4047934856305311743LLU,18446744073709548157LLU,4608044161306722303LLU,14929648213441908492LLU,18445618173819486207LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,6],[3,7],[4,8],[4,9],[5,10],[5,11],[6,8],[6,10],[7,9],[7,12],[8,13],[9,11],[10,13],[11,12],[12,13]]\n", fout);
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

