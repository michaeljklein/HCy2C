#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_699_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][6] = {{18446744073709551615LLU,18446744073709551615LLU,262143LLU,18158513697557839872LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,511LLU,18446744073709289472LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{0LLU,18446744073709551104LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073575333888LLU,18446744073709551615LLU,8502751943496564735LLU,141288719454306143LLU,18446744073709535232LLU,262143LLU},{134217727LLU,18446744004990075392LLU,18446744073709551615LLU,18446744073709551615LLU,18446744056529698815LLU,262143LLU},{18446744073575333889LLU,68719476735LLU,18446744073709289472LLU,288230376151711743LLU,18446744073709535232LLU,262143LLU},{9223372036854775807LLU,13835057093209489407LLU,229375LLU,16429131440647569344LLU,18446735294259523551LLU,262143LLU},{18437736872575762431LLU,18446744073709551607LLU,18446744073709551359LLU,18158513697557839935LLU,18442249267994050047LLU,262143LLU},{18446603336330215911LLU,16230867503925953535LLU,18446744070488313855LLU,18446691297151418367LLU,17295634564248518655LLU,262143LLU},{140737486782463LLU,18446744004991122944LLU,18428799219310526367LLU,18433233274827374847LLU,1152920972047679487LLU,262128LLU},{18442508548760926209LLU,18374686496835554943LLU,18230571291595767807LLU,288230376150925311LLU,14915918907834367984LLU,261895LLU},{14987979559754795007LLU,72057593232621567LLU,18446744073441902592LLU,18446739689621684175LLU,17856508639733334031LLU,258302LLU},{16084606036920232623LLU,18117347973045155791LLU,18446726481523759607LLU,18446744073709551615LLU,18379190057756130303LLU,248319LLU},{9223372036854775807LLU,13835041700046700541LLU,17592185880574LLU,288230371856744448LLU,8070441768904019871LLU,212933LLU},{18401708045492027391LLU,18446744073709551575LLU,18446726481523768063LLU,18158513701852807167LLU,18374704065313520127LLU,248319LLU},{9223231333726134271LLU,16717347798024982525LLU,18014395288256511LLU,2882250980664082368LLU,17365871915177082879LLU,212943LLU},{17870408656604888991LLU,18445758911023480831LLU,18445687653488656383LLU,18432177743463444732LLU,1152356252294807549LLU,192415LLU},{576458828156010495LLU,2305842940762603008LLU,14971091061273788304LLU,18446743867538477055LLU,18446707360595443487LLU,113904LLU},{18443366346608605191LLU,18374704071845085183LLU,18230553699678157567LLU,18158518095603564543LLU,16010578150277937648LLU,249663LLU},{14416022407079264159LLU,18445758910234099711LLU,18445899596987891727LLU,18445895525610812415LLU,4601904694032318717LLU,189438LLU},{17942202376853102591LLU,16717352470748135423LLU,4610841593295669247LLU,8070447229434852288LLU,8349526305720485887LLU,161759LLU}};

static uint_fast64_t D[21][6] = {{9917087249348952065LLU,4694051396536762986LLU,18446744073709456659LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{8529656824360599550LLU,18446744073709551509LLU,7325833317366628351LLU,18277196453310278234LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,13752692677172788735LLU,11120910756343018220LLU,18328061317957113253LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744004990075391LLU,16092906821449678847LLU,18401532146305816053LLU,18446744056529698815LLU,262143LLU},{18446744073709551615LLU,13752692677172789247LLU,3530755878389904108LLU,67817891105603343LLU,18446744073709535232LLU,262143LLU},{8529656824360599551LLU,18446744073709551509LLU,14915988195319742463LLU,18378926182603948272LLU,18446744056529698815LLU,262143LLU},{16990312140328711507LLU,7905751345759869682LLU,18446744073709481531LLU,18446744073709551615LLU,18442249267994050047LLU,262143LLU},{2141139944741227181LLU,10623357143986382703LLU,18446744073709493719LLU,16429131440647569407LLU,18446735294259523551LLU,262143LLU},{18446744073707978751LLU,13833789081424756735LLU,18428746184991276940LLU,15834936734019158079LLU,1152920989210758681LLU,262128LLU},{18446744073684353511LLU,16149771099675033599LLU,3530808909487915775LLU,2666061655355686863LLU,17295634564265275878LLU,262143LLU},{14294407345646600191LLU,18446744072904245207LLU,14983757434970177535LLU,18446739675918877635LLU,17856508632776949759LLU,258302LLU},{9218993513654386687LLU,18446744022154006077LLU,18162802051677945855LLU,18378926196305968380LLU,14915918897610915839LLU,261895LLU},{18157870345748398075LLU,8070434002929278716LLU,18446744073709354942LLU,2305843004918726719LLU,8070441735081156543LLU,212933LLU},{14917047831500546055LLU,17952649922712957891LLU,18446744073709537395LLU,18446744073709551615LLU,18374704065313520127LLU,248319LLU},{4178375426485657593LLU,576443173870505596LLU,18446744073709305758LLU,288230376151711743LLU,8070441768904019871LLU,212933LLU},{14917047865749667359LLU,18437877598190043075LLU,18446742991314876417LLU,18429010119384629247LLU,11527420636548823161LLU,248314LLU},{18446742149563679231LLU,9002526330273791LLU,14123275237278613488LLU,13042424259929964495LLU,17683330060798394119LLU,113919LLU},{18446728671394791303LLU,18445626420139720703LLU,4395513167661220607LLU,8069325731600269308LLU,18058447144309453308LLU,192415LLU},{71932524487909375LLU,576460748074729468LLU,14983757435238104990LLU,18446744069670421443LLU,8646905578811019167LLU,210684LLU},{9223369853937646079LLU,18383688954462277181LLU,13839545159013892095LLU,12988328548761616383LLU,18192288760413487095LLU,114535LLU},{18443366355735017599LLU,18375812315141373443LLU,18433215751348289521LLU,18159639391306203135LLU,16101459093473394547LLU,122227LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][6] = {{9917087249348952065LLU,4694051396536762986LLU,18446744073709456659LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,6],[3,7],[4,8],[4,9],[5,10],[5,11],[6,7],[6,8],[7,10],[8,12],[9,11],[9,13],[10,13],[11,12],[12,13]]\n", fout);
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

