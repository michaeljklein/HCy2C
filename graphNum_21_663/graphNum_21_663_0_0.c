#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_663_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][6] = {{18446744073675997185LLU,8589934591LLU,18446744073705357312LLU,281474976710655LLU,18446744073709543424LLU,1073741823LLU},{18446744073709551615LLU,2047LLU,18446744073705357312LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,4194303LLU,18446462598732840960LLU,18446744073709551615LLU,1073741823LLU},{18446744073675997184LLU,18446744073709551615LLU,17717158735043887103LLU,236898977019223LLU,18446744073709543424LLU,1073741823LLU},{33554431LLU,18446744065119619072LLU,18446744073709551615LLU,18446744073709551615LLU,18446739675663048703LLU,1073741823LLU},{0LLU,18446744073709549568LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,10347020023624630269LLU,1032191LLU,3600909377059422207LLU,18158518026884867838LLU,1073741823LLU},{18438299820180373503LLU,18446744073709550079LLU,18446744073709551359LLU,18446462598732840960LLU,288227075603046367LLU,1073740800LLU},{18446462598761000743LLU,18158297093765074943LLU,18446744073709481918LLU,18446744073709539327LLU,12105675798237683711LLU,1073726041LLU},{281474976186367LLU,18446744065121712128LLU,18446742974214700031LLU,18446743867551121407LLU,18445618173936926719LLU,1073496063LLU},{18428727338737852417LLU,17870283328917962719LLU,18433233274827440127LLU,13835339513146114047LLU,18423940202549477375LLU,1071904707LLU},{4323420449280106495LLU,576460752084787199LLU,18446744073705357312LLU,4611686018427386883LLU,14050016976558874624LLU,1059028991LLU},{18446462603027808127LLU,11511059806989328381LLU,1099509530623LLU,8645222434691076095LLU,18159639528611508222LLU,1073726463LLU},{18372988283492515839LLU,9223372036854775167LLU,18175682846302142080LLU,18446744073692774400LLU,288228722165620673LLU,1021308924LLU},{17286926394055458755LLU,18446709026239544307LLU,4611633187108421631LLU,18412685601544339455LLU,18446741718388244479LLU,872086531LLU},{16141182539329928415LLU,18442495560714813439LLU,18446744069430968313LLU,18212504115722599679LLU,6917463022717877243LLU,787987959LLU},{2305841912920670207LLU,18446744065186600960LLU,18445621476632534015LLU,18446740569016238079LLU,18428795680249478911LLU,465338367LLU},{18445618173399801919LLU,8646946468923441151LLU,18217060492713655936LLU,13871086835171591167LLU,4611686018158903233LLU,1021831104LLU},{9218868433972887491LLU,18446709026105327607LLU,18446744073705357439LLU,18412685618707430403LLU,14123288430359732255LLU,859733055LLU},{16149627888151297407LLU,13831539549288923133LLU,1125895628652543LLU,18301502985726644223LLU,18176462024312078334LLU,787990527LLU},{18445617142741918719LLU,17874786913517205519LLU,18445687511754735495LLU,14123288415311233023LLU,18432384726453944295LLU,502136780LLU}};

static uint_fast64_t D[21][6] = {{14754186442582261759LLU,18446744073709549929LLU,1094378008002691071LLU,18446529462732378108LLU,18446739675663048703LLU,1073741823LLU},{14754186442582261758LLU,18446744073709549929LLU,11933036713141600255LLU,18446627960717469014LLU,18446744073709551615LLU,1073741823LLU},{3692557631127289857LLU,17539887619222015638LLU,18446744073708817204LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744065119619071LLU,6878500029904977919LLU,18446600999724769277LLU,18446739675663048703LLU,1073741823LLU},{18446744073709551615LLU,906856454487539711LLU,17352366065707594955LLU,214610977173507LLU,18446744073709543424LLU,1073741823LLU},{18446744073709551615LLU,906856454487537663LLU,6513707360568685771LLU,18446578711724923561LLU,18446744073709551615LLU,1073741823LLU},{9214646308301186691LLU,18122118620759714039LLU,18446744073709350452LLU,18446744073709551615LLU,288227075603046367LLU,1073740800LLU},{12916211143006476669LLU,9764789022086930332LLU,18446744073705855999LLU,3600909377059422207LLU,18158518026884867838LLU,1073741823LLU},{18446744073709027327LLU,17209925141799108607LLU,18446742974200789483LLU,12157132680824044787LLU,18445622571849216691LLU,1073496063LLU},{18446744073704156967LLU,1855228406455599103LLU,17352366065721435806LLU,6289825797704237839LLU,12105675798371888460LLU,1073726041LLU},{1796311162787201023LLU,18446744073490914687LLU,14933077906765643775LLU,18446529462783704064LLU,14050015278783389695LLU,1059028991LLU},{17263278994137022463LLU,18446744072631450569LLU,4594533376064487423LLU,18446744056545464319LLU,18423937502278467583LLU,1071904707LLU},{9214646312567469787LLU,18337786452158445815LLU,18446744073709156449LLU,17201445738455710963LLU,6629295350941219731LLU,1073495462LLU},{16699133924036050881LLU,18446708896009371600LLU,4611633187104726015LLU,18410996751667298303LLU,18277397069393028863LLU,872087551LLU},{13438692076338026879LLU,541417115462328127LLU,18175682846302142336LLU,3602879701896396799LLU,18327864322442657760LLU,1021308927LLU},{18446742977415868407LLU,15690539418131505151LLU,18445619273312208799LLU,6335997589690777551LLU,17853394822795488879LLU,465566557LLU},{18446744073562700815LLU,4607184549103796223LLU,17352369364258029304LLU,18166329025201176639LLU,1152921504606829016LLU,787989747LLU},{139347637992685567LLU,18446744072650989552LLU,1152855465454443519LLU,18446529462783705087LLU,18226929441620223743LLU,859734015LLU},{18310492661112371583LLU,18411700435874774797LLU,18158583035258208255LLU,17437937757177565183LLU,18378331560133738495LLU,1021831167LLU},{9223372035776899059LLU,17906310051874732279LLU,18446744073709518855LLU,14981219763459456963LLU,17582049646719401479LLU,465338124LLU},{16280248767976832975LLU,13835025001161949183LLU,288230372121018367LLU,18418319499108285503LLU,14771753974272614910LLU,662691071LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][6] = {{14754186442582261759LLU,18446744073709549929LLU,1094378008002691071LLU,18446529462732378108LLU,18446739675663048703LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,6],[3,7],[4,6],[4,8],[5,9],[5,10],[6,11],[7,9],[7,10],[8,11],[8,12],[9,12],[10,13],[11,13],[12,13]]\n", fout);
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
