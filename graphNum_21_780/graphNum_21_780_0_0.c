#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_780_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][6] = {{18446744073709486081LLU,144115188075855479LLU,18446603336221196288LLU,18446743249075830783LLU,18446744073675998207LLU,72057593769558015LLU},{18446744073709551615LLU,1048575LLU,18446603336221196288LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,140737488355327LLU,0LLU,18446744073709550592LLU,72057594037927935LLU},{18446739675663040512LLU,18446744073709551615LLU,18374966855103152127LLU,18442660478799839231LLU,18446743523953737979LLU,72057594037927935LLU},{4398046511103LLU,18446744073173729280LLU,18446673678656601658LLU,18446743970630336511LLU,549755813887LLU,72057594037927920LLU},{9223372036854775807LLU,18302628885634727935LLU,9079256848778919935LLU,11349027080449251197LLU,3228279938603810751LLU,72057594037862410LLU},{0LLU,18446744073708503040LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073696968703LLU,16409638953839230975LLU,123074434543615LLU,18446744073705357312LLU,18446743875282091007LLU,72057559944331167LLU},{18302635481092849663LLU,18446744073709551615LLU,18446739675528822783LLU,4194303LLU,18437737424210623488LLU,72053230275623423LLU},{9223367638808330239LLU,18302628886170550271LLU,18375248330079862783LLU,13831680355511304191LLU,18446743523987291647LLU,72057594037862415LLU},{144115188063272959LLU,16717361816265555968LLU,72057576857534079LLU,18446743970626142208LLU,9007199254740991LLU,72057559944331152LLU},{18424225852234399489LLU,135248726166765428LLU,18446744073709420544LLU,8358680908399443955LLU,18157106202415072248LLU,71990514699796477LLU},{17870230544845963519LLU,18446743936773913343LLU,17581912207766192127LLU,18446743231963070463LLU,18428726376128446463LLU,71001957382225919LLU},{14122731523962568191LLU,18446744073708765183LLU,31415246078869503LLU,18446462598733103103LLU,18311601450271899647LLU,68046060009764339LLU},{18303191696822755315LLU,2299079363435425791LLU,18443365961672163296LLU,281474976698367LLU,9214399950027219968LLU,58529752724798079LLU},{9150188542641620991LLU,18446735278035935695LLU,18442801805873119231LLU,18391574978274247487LLU,3454190541180239263LLU,58124575174557199LLU},{16140474454252715279LLU,18302637681726717951LLU,4544132024004116991LLU,13832525879953063935LLU,18374659545931325433LLU,68625605930713599LLU},{143974418369970143LLU,17869755452716220352LLU,58414836580607871LLU,18446730845210279680LLU,16149899441602543615LLU,52336751468799967LLU},{18438282232180242431LLU,8070450531743563839LLU,18445618169775652606LLU,17298326099201097983LLU,2305314144119685119LLU,31380029625204528LLU},{18446722358354505791LLU,18311636076532464383LLU,18410715272395628287LLU,18446532691554992127LLU,18446742561778335743LLU,33565562376241139LLU},{17762161745841295351LLU,17870276595470565315LLU,17581912212061028321LLU,18446743507847610127LLU,16692589817243888647LLU,44189302291628031LLU}};

static uint_fast64_t D[21][6] = {{1932736333743063039LLU,18446744073709260271LLU,4324018592229097471LLU,10102633790258217788LLU,3228279938603810207LLU,72057594037862410LLU},{9367493223276019710LLU,18446744073708686761LLU,10808920580665901055LLU,16614176796645632406LLU,18446744073709550794LLU,72057594037927935LLU},{9079250850433531905LLU,13604612318382862934LLU,18446661273608049194LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,7493989779408683007LLU,7637994985849617944LLU,6444606964690736745LLU,549755813815LLU,72057594037927920LLU},{18446744073709551615LLU,15794886049093648383LLU,18374807767345737207LLU,13830620688093806591LLU,18446743523953737849LLU,72057594037927935LLU},{16658128926387666944LLU,18446744073708961329LLU,15564158837215723519LLU,17860569262202944983LLU,18446744073675997930LLU,72057593769558015LLU},{18446744073709551615LLU,4842131755327553535LLU,7637906293145152981LLU,1832567277063919209LLU,18446744073709551413LLU,72057594037927935LLU},{18302629845675514211LLU,13758473750395748351LLU,18446666823679015850LLU,18446744073709551615LLU,18437737424210624511LLU,72053230275623423LLU},{9079256485838284445LLU,16255777521826345558LLU,18446716462404044415LLU,18446744073709551615LLU,18446743875282091007LLU,72057559944331167LLU},{16658128926387732479LLU,7493989779943915057LLU,14123178449263132184LLU,8345169023155895491LLU,15218464684861554662LLU,72057593769558005LLU},{18446740635704858979LLU,11414338588741992447LLU,18446735414791141863LLU,13830620688093806591LLU,18446743722381198457LLU,72053230275623423LLU},{17508805125045551103LLU,18446743936773650927LLU,17324784816540876799LLU,18391574961097798463LLU,12650537135745531295LLU,71001957648512491LLU},{2271643532068388863LLU,18437877611800432636LLU,4581286720942637055LLU,69739720447102960LLU,8716831307725799416LLU,71990514701814300LLU},{9223371813250123761LLU,135240067428853590LLU,18443364755826540512LLU,18446744073709539327LLU,9223371912830247935LLU,58533586519784991LLU},{13979172412280634527LLU,18419616817832131327LLU,31393238799713919LLU,18446744073705619455LLU,18311635938540339199LLU,68046555883485171LLU},{14964968980542913807LLU,18446744073708961789LLU,1152811553293991967LLU,8358399450599456755LLU,18048989145291431928LLU,68625605715820533LLU},{17760455303930824703LLU,7493989779827056643LLU,17582052395766513656LLU,18379190075272445967LLU,551582102694395783LLU,58124575121145855LLU},{18438278796197745531LLU,2190999563005853695LLU,18445617757207560190LLU,17293892661928787967LLU,18446214863872522239LLU,31379202837806975LLU},{18446603301994053063LLU,18446183193930366975LLU,18433093087082308071LLU,13835040999950254079LLU,18446735244976163961LLU,52333248587489791LLU},{4476437265068851191LLU,17869854511846125504LLU,18435485074641125345LLU,1152908276107562752LLU,7053191150995237888LLU,45006307848547039LLU},{16133859826349375295LLU,18303191835183423487LLU,4556516922991976191LLU,17363364411779071999LLU,18374246159624339455LLU,33737114138910512LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][6] = {{1932736333743063039LLU,18446744073709260271LLU,4324018592229097471LLU,10102633790258217788LLU,3228279938603810207LLU,72057594037862410LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,4],[1,5],[2,4],[2,6],[3,5],[3,7],[4,8],[5,9],[6,10],[6,11],[7,10],[7,12],[8,10],[8,13],[9,12],[9,13],[11,12],[11,13]]\n", fout);
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
