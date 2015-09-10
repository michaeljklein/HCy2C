#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_595_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][6] = {{18446744073172680705LLU,1073741823LLU,18446744073705357312LLU,1125899906842623LLU,18446744073709535232LLU,16777215LLU},{18446744073709551615LLU,2047LLU,18446744073705357312LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,4194303LLU,18445618173802708992LLU,18446744073709551615LLU,16777215LLU},{18446744073172680704LLU,18446744073709551615LLU,15411133206899982335LLU,949288156790743LLU,18446744073709535232LLU,16777215LLU},{536870911LLU,18446744072635811840LLU,18446744073709551615LLU,18446744073709551615LLU,18446739675663056895LLU,16777215LLU},{0LLU,18446744073709549568LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{17879290520660869119LLU,9187333859627237375LLU,3669879LLU,13740482463107383280LLU,18444496655030939563LLU,16777215LLU},{18446743799905386495LLU,17867890781956603903LLU,18446744073709516799LLU,17003340393137307663LLU,17296074368912210686LLU,16777215LLU},{18442240474345094831LLU,18302591364797304831LLU,18446744073707453917LLU,18446744073709289535LLU,1150669704524742655LLU,16777200LLU},{4503599543413755LLU,16131330905626114048LLU,18446742974214561791LLU,18446744073709551615LLU,18446735277884964863LLU,16773135LLU},{18446532967476985857LLU,18158513698547302382LLU,17365880163140632575LLU,1125692943106047LLU,18356249868697075711LLU,16748220LLU},{17293820919298424831LLU,288230375879057151LLU,18446678103007690752LLU,18446691297148272639LLU,14695219195830845440LLU,16546799LLU},{17874787195911405567LLU,18446744073707462655LLU,1099511627775LLU,18446744073709289520LLU,1150678483710509055LLU,16777200LLU},{576460478499258367LLU,18446744072640002048LLU,18446742974214701055LLU,18445618173802971135LLU,17298321787859255295LLU,16773135LLU},{11529214906356203393LLU,18446739676107635182LLU,18446743248874243071LLU,18374756641389150207LLU,17771201896218849535LLU,15984287LLU},{18392456786597740671LLU,4323460040321695743LLU,17347936133375328192LLU,72057594037924095LLU,4611158251210276803LLU,13606908LLU},{17293822526150959615LLU,270286345946005145LLU,18446744018948718528LLU,14123231515597864959LLU,17973865425640226752LLU,13597039LLU},{18010174735029108615LLU,18446739692841312255LLU,1152855533904986175LLU,18379190079298748400LLU,14986264308663435327LLU,15794163LLU},{431782598142853119LLU,18446744073646637048LLU,4611686014149182463LLU,18446744056529895423LLU,18379189817238633727LLU,12254991LLU},{18428725019455519231LLU,18445688541540251655LLU,18445898553562759167LLU,17580927062527442175LLU,17365876039422836735LLU,7327999LLU},{9187176101181884415LLU,18159639597414023160LLU,17565164442625245123LLU,1152921487494083583LLU,9168976790356295631LLU,10469181LLU}};

static uint_fast64_t D[21][6] = {{3466033936021323775LLU,18446744073709550387LLU,4553416300218548223LLU,18445883091427786812LLU,18446739675663056895LLU,16777215LLU},{3466033936021323774LLU,18446744073709550387LLU,10780023949069647871LLU,18446280467865578134LLU,18446744073709551615LLU,16777215LLU},{14980710137688227841LLU,11068046443796237516LLU,18446744073707035033LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744072635811839LLU,9184525558048882687LLU,18446170085521708413LLU,18446739675663056895LLU,16777215LLU},{18446744073709551615LLU,7378697629913317375LLU,13893327773493519974LLU,860982281764803LLU,18446744073709535232LLU,16777215LLU},{18446744073709551615LLU,7378697629913315327LLU,7666720124642420326LLU,18446081779646682473LLU,18446744073709551615LLU,16777215LLU},{14987979285232039085LLU,17434311426100423884LLU,18446744073707401693LLU,17004466293044150271LLU,17296074368912210686LLU,16777215LLU},{17872021099312892755LLU,2242215585570103295LLU,18446744073708625715LLU,13740482463107383295LLU,18444496655030939563LLU,16777215LLU},{18446744073625594875LLU,5714214109109551103LLU,18446742974201384823LLU,10855661984151502847LLU,18446739675663033769LLU,16773135LLU},{18446744073435594415LLU,17651661718591373311LLU,13893327773504599244LLU,7591943071839551491LLU,1150669704793152086LLU,16777200LLU},{16274318166568468479LLU,18446744073436896827LLU,4611616488225243135LLU,18446674791587921724LLU,14695217378584018943LLU,16546799LLU},{4485325583055585279LLU,18446744073625271270LLU,17307614004436271103LLU,18445899390024401151LLU,18356247287897423871LLU,16748220LLU},{14987979559763075577LLU,14105344384492895436LLU,18446744073709290495LLU,14119645814088269823LLU,17298326168730071292LLU,16773135LLU},{18443978251798945287LLU,4341399689218760703LLU,13893327773503847424LLU,4327959241903046643LLU,1150678500886171395LLU,16777200LLU},{18383658726480543743LLU,4611686018427264955LLU,18428730719950864320LLU,18446740762289762367LLU,1152788874107682755LLU,13598719LLU},{9365798165564882943LLU,18446744072891660415LLU,4611684987383317503LLU,18445622571782127612LLU,17568538783208386815LLU,15791055LLU},{13326186342174949255LLU,18446739692840942591LLU,18013573674434559LLU,18378345654318272496LLU,18444630762731831295LLU,15986672LLU},{9169315582762279423LLU,18428800043692588928LLU,18442521880607850495LLU,14123284033454469375LLU,18176527063638409215LLU,13605951LLU},{18426399809657763871LLU,4610560393397223423LLU,18229462983871037436LLU,17311836967612185843LLU,11527895631569866739LLU,7331830LLU},{18301625581240295399LLU,18176527838368423935LLU,274706383130050563LLU,4598175219545227263LLU,8069526938118519823LLU,12255225LLU},{18155134691663937439LLU,18446739949734574207LLU,18446690266355089407LLU,18391579376320577520LLU,15275063136685638655LLU,7730167LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][6] = {{3466033936021323775LLU,18446744073709550387LLU,4553416300218548223LLU,18445883091427786812LLU,18446739675663056895LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,6],[3,7],[4,6],[4,7],[5,8],[5,9],[6,10],[7,11],[8,10],[8,12],[9,10],[9,13],[11,12],[11,13],[12,13]]\n", fout);
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

