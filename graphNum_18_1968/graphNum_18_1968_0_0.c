#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_18_1968_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 17;
static uint_fast32_t endhere = 0;
char str[28] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[18][8] = {{3977804370874990591LLU,18446744073708633529LLU,17328760650586914815LLU,16582253724089555443LLU,287794728902313759LLU,34359738367LLU,18446744073709551600LLU,67108863LLU},{18446744073709551615LLU,2097151LLU,18446744039349813248LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,34359738367LLU,9223372036854775808LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,9223372036854775807LLU,0LLU,18446744073709551612LLU,18446744073709551615LLU,67108863LLU},{18445688439417337857LLU,18230571222878375935LLU,18446708923646869383LLU,9223306066157109247LLU,18433233268384989152LLU,18446744039349813251LLU,18446744073709551615LLU,67108863LLU},{0LLU,18446744073707454464LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18217057881373411327LLU,12970226258058133479LLU,18446744071360741375LLU,18446744073709551615LLU,18428727742464669951LLU,18446744073709551615LLU,18446744071562067983LLU,67108863LLU},{18446744072426225663LLU,18428870412688424959LLU,1118018607494625407LLU,18446532967346995198LLU,18446744073709551615LLU,18446744073709551615LLU,18428729677347553279LLU,67108863LLU},{16158914637968699391LLU,16717079929505447935LLU,36028796616303103LLU,18338657682652659456LLU,14987979559884818431LLU,17545584137425911807LLU,13850538614059958027LLU,67108863LLU},{2305626371061710329LLU,6842656675231428382LLU,18446744068860936191LLU,9223372036854775807LLU,18442172301681098748LLU,5764604498974604803LLU,4611672704028770303LLU,67108800LLU},{18446744071008395175LLU,18446735826449596415LLU,18446743008557244391LLU,18446730862524236031LLU,18446744073709551615LLU,18440551624220934655LLU,18446744073709490431LLU,67092543LLU},{18446708889337462784LLU,18446744073709551615LLU,13830549920169328639LLU,18158513420515667935LLU,18446744040423555071LLU,18446744072081896319LLU,17870281259553242559LLU,66993983LLU},{35184372088831LLU,36028797016866816LLU,18302488148145340412LLU,18446181123755606015LLU,18446744073709551615LLU,18446673739323015151LLU,18410715276683247615LLU,66191356LLU},{16428277601146765087LLU,17144922302262008063LLU,18446744064817627134LLU,18446744073709551615LLU,18435555439086272483LLU,17870278785853620223LLU,18176475306624286718LLU,63831551LLU},{18446744069112555775LLU,18446717208689115135LLU,18446709988847511455LLU,18446689115308031745LLU,18446744073709551615LLU,18437455365185470463LLU,4899916394578640671LLU,54509567LLU},{18408463459705421823LLU,18446744073709518843LLU,18446744073701163011LLU,18446744073709551615LLU,18374686325052792703LLU,18302699249009154047LLU,16716374730235445247LLU,46084927LLU},{18446708906517331967LLU,18446744073709551615LLU,17581208485972934655LLU,18443366373985878015LLU,18446744073709551615LLU,144115188071661535LLU,18374686479612903408LLU,32440307LLU},{18446744065119551355LLU,18446638517359476735LLU,18446744073703260159LLU,9227875636482146303LLU,18446744073709551615LLU,18320643284084457023LLU,18302628883553320959LLU,48201679LLU}};

static uint_fast64_t D[18][8] = {{18446744073701163009LLU,18428729675202138111LLU,18446744073709551615LLU,18446466996779352063LLU,18415218861285572607LLU,18446744053524687479LLU,18437622309154010431LLU,67108863LLU},{2709337388328419326LLU,18446744073707581740LLU,4562097631697829887LLU,15231170874988907931LLU,12390928111668786646LLU,18446744073709551614LLU,18446744073709551615LLU,67108863LLU},{15737441904096440781LLU,55450458539298515LLU,18446744040440332280LLU,9223372036854775807LLU,18198973081903275643LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446708854994243123LLU,18410527666860982271LLU,16859927758620677463LLU,18440459247925329661LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{8953153584103423999LLU,13258597302977953761LLU,36028794737162751LLU,16609275425608278014LLU,1152919339842537471LLU,11129325347105931263LLU,18439140363812727779LLU,67108863LLU},{18446744073709551615LLU,18427510022020792319LLU,15471462790369815215LLU,12445230061359641446LLU,6303586953847040941LLU,18446744073709551613LLU,18446744073709551615LLU,67108863LLU},{13258597302861299711LLU,18446744073709419967LLU,18410715311050325511LLU,18446744073709551615LLU,17581617538623864831LLU,7493903591627724795LLU,18445455149729054716LLU,67108863LLU},{18428799803426078719LLU,17942340915444056063LLU,18446744073592111103LLU,9196350335206029811LLU,18446744073709549568LLU,18270259228870311311LLU,18446744073632931551LLU,67108863LLU},{18446528532905443297LLU,9149056045801271071LLU,18446743004245524455LLU,9223358825669591039LLU,18442172302213775356LLU,9218866238204084227LLU,13835044861142573055LLU,67098197LLU},{18446744072770015167LLU,18446742011319681023LLU,36028797018931711LLU,18446744073709420544LLU,14987979559889010687LLU,18444615419197259775LLU,14390970584529891339LLU,67103167LLU},{18012474363346431LLU,14410674374065520638LLU,18446744072770027519LLU,18338657682652659711LLU,18446744073172682751LLU,14087258603220107263LLU,8682939946125754367LLU,67108842LLU},{18446744073709551615LLU,18014398509481983LLU,18212327644911894524LLU,12591218955771886454LLU,6303586954383911853LLU,18446673739323015149LLU,18410715276683247615LLU,66191356LLU},{18446744073709551615LLU,18445524420530274303LLU,10945429140063038127LLU,18011961576149477327LLU,18446744039886684159LLU,18446744072081896319LLU,17870281259553242559LLU,66993983LLU},{9223372029338533887LLU,18446711088360194047LLU,18446744073707487231LLU,18446741874686427135LLU,4611686018326724607LLU,16125102731672158207LLU,4606618334974709751LLU,54499199LLU},{18446728680543617023LLU,4604930618986330113LLU,18446744058677166078LLU,16717361816799256575LLU,18444492308255604735LLU,4538494827901222911LLU,18446675903414008830LLU,63831253LLU},{17139996494330331135LLU,18446744073708501870LLU,18446744073709551615LLU,18442242673105436671LLU,18445000797617813988LLU,18446744056253874116LLU,18329606425556811775LLU,31850480LLU},{18446744073709551615LLU,18446744073709488127LLU,9196323226177765375LLU,11529213383815364414LLU,18304880685447380991LLU,18446744067233009407LLU,17292767036866000767LLU,45872127LLU},{18446726481519311855LLU,18437736840025931775LLU,18446744056529682429LLU,18446744073709551615LLU,144115188075855871LLU,18446682475288543228LLU,16124012565893218289LLU,24629247LLU}};

uint_fast8_t X[18] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[18][8] = {{18446744073701163009LLU,18428729675202138111LLU,18446744073709551615LLU,18446466996779352063LLU,18415218861285572607LLU,18446744053524687479LLU,18437622309154010431LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU}};

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
        A[i][7] = A[i-1][7] & C[i][7];

    } else {
        A[i][0] = A[i-1][0] & D[i][0];
        A[i][1] = A[i-1][1] & D[i][1];
        A[i][2] = A[i-1][2] & D[i][2];
        A[i][3] = A[i-1][3] & D[i][3];
        A[i][4] = A[i-1][4] & D[i][4];
        A[i][5] = A[i-1][5] & D[i][5];
        A[i][6] = A[i-1][6] & D[i][6];
        A[i][7] = A[i-1][7] & D[i][7];

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
    fputs("[[0,3],[0,5],[0,6],[0,7],[1,4],[1,5],[1,6],[1,7],[2,4],[2,6],[2,7],[3,5],[3,7],[4,6],[4,7],[5,6],[5,7],[6,7]]\n", fout);
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
