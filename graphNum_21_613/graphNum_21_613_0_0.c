#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_613_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][5] = {{67571586592638975LLU,67571586592638975LLU,18378134548136313615LLU,4764806279749173247LLU,1059710165788658LLU},{18446744073709551615LLU,0LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,0LLU,18446744073708503040LLU,1125899906842623LLU},{18446744073705357312LLU,18446744073709551615LLU,9031227936620281853LLU,18446741874686811999LLU,1125899906842623LLU},{4194303LLU,18446744073705357313LLU,18446744073709551615LLU,13835060254305419263LLU,1125899906842623LLU},{18446744073705357313LLU,4194303LLU,18446744073709551615LLU,18446741874687344639LLU,1125899906842623LLU},{18446744073709551615LLU,15563736624490610687LLU,18446739675663040512LLU,4611685167991357439LLU,1125899906841600LLU},{9076969864333099007LLU,18446744073709551615LLU,4398046511103LLU,15771537725329506304LLU,1125899902649343LLU},{18446742974201886759LLU,18383677587831389953LLU,18446744073709551615LLU,18442242673105436671LLU,1125898833746943LLU},{1099511627775LLU,18446744073705357567LLU,14123288431433859075LLU,4503599627366655LLU,1125626102677488LLU},{18383677587831389953LLU,18446742974201886759LLU,18446744073709551615LLU,13835058053135728639LLU,1121721977404573LLU},{18446744073705357567LLU,1099511627775LLU,18374704055750557695LLU,18446741876833779711LLU,1059928995202047LLU},{18446742974466161151LLU,18392687683789913859LLU,18446739675663056895LLU,18442310842794901503LLU,1125898837294095LLU},{18392687683789913859LLU,18446742974466161151LLU,72057594037927935LLU,18446678100896907264LLU,1121721973276671LLU},{18442241364130267135LLU,18446744073709519031LLU,17582052739083403011LLU,4470785802351099132LLU,1054140667002590LLU},{4503599627339775LLU,18442258066264063999LLU,14986924028726329599LLU,13979173178933507071LLU,971710580910065LLU},{18442258066264063999LLU,4503599627339775LLU,18375812366692777743LLU,9088261917729882111LLU,1002741576966142LLU},{17581841822109855231LLU,17563823042415030243LLU,18446744073441129423LLU,8628404021358493695LLU,822434634661771LLU},{18446742991327329255LLU,18410706464290111263LLU,4611681620649312255LLU,18442790229669576640LLU,562124312673407LLU},{18410706464290111263LLU,18446742991327329255LLU,18446744073442164735LLU,18446269082799964223LLU,841089834024863LLU},{0LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU}};

static uint_fast64_t D[21][5] = {{18446743026559614759LLU,18446743026559614759LLU,4611681637293359103LLU,18442878188981850048LLU,1121775879060639LLU},{6189457332372504574LLU,18446744073709551615LLU,7590071313928399529LLU,18446744073708935770LLU,1125899906842623LLU},{12257286741337047041LLU,12257286741337047041LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073705357312LLU,15564430828325786967LLU,13835060254305252853LLU,1125899906842623LLU},{18446744073709551615LLU,6189457332372504575LLU,4323469868075646972LLU,18446741874686545679LLU,1125899906842623LLU},{6189457332372504575LLU,18446744073709551615LLU,14123274205633904643LLU,13835060254305169648LLU,1125899906842623LLU},{4338026370100311555LLU,13752846855490286077LLU,18446744073709551615LLU,15771537725330554879LLU,1125899902649343LLU},{16996230235569834493LLU,14068176510337371651LLU,18446744073709551615LLU,4611685167991357439LLU,1125899906841600LLU},{18446744073709551615LLU,6193962380729253887LLU,13838506123746852864LLU,4611683892115533887LLU,1125626102677488LLU},{18446744073709320231LLU,18379172539474640895LLU,4608252175762653183LLU,18446744000998395855LLU,1125898833746943LLU},{6193962380729253887LLU,18446744073709551615LLU,18374690860805653263LLU,13987544924891906047LLU,1059928995202047LLU},{18379172539474640895LLU,18446744073709320231LLU,14123287400578809075LLU,13682573384695427312LLU,1121721977404573LLU},{4338026370364585947LLU,4392082707687453183LLU,13838506123746869247LLU,15771604619144196159LLU,1125626102032383LLU},{14122232847924513279LLU,14068176510601646043LLU,18446744056797070095LLU,7439312415314935807LLU,1059928995266402LLU},{18446744073709518959LLU,18442240735907414015LLU,18445632464031121407LLU,18446744005907840975LLU,971967634859007LLU},{18446743864245780407LLU,18379189869835452343LLU,4608308048107405311LLU,18445455376747794428LLU,1054156344123103LLU},{18379189241612599151LLU,18446743236022927215LLU,14987975436468747519LLU,18300051629148271555LLU,982361527025085LLU},{4590289522098421731LLU,4608308301793246719LLU,17169973579350015LLU,16068829142212149184LLU,561961036705791LLU},{17329578687237187551LLU,17365616228809434111LLU,18433022168594904015LLU,8331658885165215807LLU,822325175367675LLU},{1148699328413277183LLU,1112661786841030623LLU,18391856436339527487LLU,14879328518071648255LLU,518823258058614LLU},{18446744073709551615LLU,6189457332372504574LLU,10856672759781152086LLU,18446744073709118885LLU,1125899906842623LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][5] = {{18446743026559614759LLU,18446743026559614759LLU,4611681637293359103LLU,18442878188981850048LLU,1121775879060639LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU}};

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

    } else {
        A[i][0] = A[i-1][0] & D[i][0];
        A[i][1] = A[i-1][1] & D[i][1];
        A[i][2] = A[i-1][2] & D[i][2];
        A[i][3] = A[i-1][3] & D[i][3];
        A[i][4] = A[i-1][4] & D[i][4];

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,6],[3,7],[4,6],[4,8],[5,7],[5,9],[6,10],[7,11],[8,9],[8,12],[9,12],[10,11],[10,13],[11,13],[12,13]]\n", fout);
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
