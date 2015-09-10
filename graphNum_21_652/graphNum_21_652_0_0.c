#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_652_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][6] = {{18446744073675997185LLU,1073741823LLU,18446744073709486080LLU,4398046511103LLU,18446744073709551600LLU,262143LLU},{18446744073709551615LLU,255LLU,18446744073709486080LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,65535LLU,18446739675663040512LLU,18446744073709551615LLU,262143LLU},{18446744073675997184LLU,18446744073709551615LLU,17723203669593030655LLU,3710136573311LLU,18446744073709551600LLU,262143LLU},{33554431LLU,18446744072635810048LLU,18446744073709551615LLU,18446744073709551615LLU,18446744072635809807LLU,262143LLU},{0LLU,18446744073709551360LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{4609574956102057983LLU,6917520216515674111LLU,18158513697557895167LLU,17581459208975417343LLU,18446739676685467641LLU,262143LLU},{18446744069481693183LLU,18419124341619818455LLU,288230376151711719LLU,11469537952959299584LLU,18428734072843926543LLU,262143LLU},{18446673704979906523LLU,17870281088022872575LLU,1152921504606813693LLU,18446744057603424240LLU,13849408881047830543LLU,262143LLU},{70368742591231LLU,18228178753220247296LLU,18446744072636071743LLU,18446744073709551615LLU,4611686001247584255LLU,262080LLU},{18446740749404862465LLU,18442240474551890813LLU,18445688478122377215LLU,18428734073246580735LLU,17528008860667740159LLU,261183LLU},{16703851017883617279LLU,4503599600631807LLU,18446744073709486080LLU,18014398242094143LLU,4609548567822991344LLU,246771LLU},{4609504591652847615LLU,18446744060824388607LLU,864691129528877055LLU,18446717669324357616LLU,13853068072873624575LLU,262143LLU},{18446744073222881251LLU,18437137657797541887LLU,71833280780910580LLU,14964089371240431616LLU,15690404762316963719LLU,245567LLU},{18160756628800929791LLU,18428729675192205271LLU,18433232450177204207LLU,13799024860216950783LLU,4593812356996248703LLU,224252LLU},{288230375680892903LLU,18302627853776191232LLU,18446744072652586879LLU,18446532967476756495LLU,18446612116216479631LLU,245507LLU},{18176525876642969631LLU,18424227175078000639LLU,18445899597224083439LLU,13781291936952352767LLU,17818491341569522943LLU,228604LLU},{17829750924759533175LLU,4239510533046259LLU,18446744073709551612LLU,16155467188366462783LLU,13830088262590398463LLU,193514LLU},{17284533379441885183LLU,18446744069396746239LLU,4611668494960754691LLU,2305834212869012735LLU,9005492606536116208LLU,118775LLU},{9221613368005902335LLU,288230367561531391LLU,18158531289743884284LLU,16284998647488184304LLU,14123002833254162431LLU,193535LLU},{18176528092443441255LLU,18442257034463149824LLU,18446744072687190015LLU,18429640088007476223LLU,18433127707813346463LLU,261132LLU}};

static uint_fast64_t D[21][6] = {{4156936040835186687LLU,18446744073709551510LLU,1085310606174846975LLU,18446740707527947200LLU,18446744072635809807LLU,262143LLU},{4156936040835186686LLU,18446744073709551510LLU,11936059180414795775LLU,18446742263739079018LLU,18446744073709551615LLU,262143LLU},{14289808032874364929LLU,11882300834991571305LLU,18446744073709513017LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744072635810047LLU,6872455095353081855LLU,18446741829588482005LLU,18446744072635809807LLU,262143LLU},{18446744073709551615LLU,6564443238717980671LLU,17361433467534743238LLU,3366181604415LLU,18446744073709551600LLU,262143LLU},{18446744073709551615LLU,6564443238717980415LLU,6510684893294794438LLU,18446741485633513109LLU,18446744073709551615LLU,262143LLU},{16595764622579578179LLU,17837858345110207939LLU,18446744073709518305LLU,11469542351005810687LLU,18428734072843926543LLU,262143LLU},{2303618362168986301LLU,934342974307304317LLU,18446744073709536063LLU,17581459208975417343LLU,18446739676685467641LLU,262143LLU},{18446744073707965183LLU,6661729157119999999LLU,18446744072635864863LLU,8274584830215130175LLU,4611686002321260537LLU,262080LLU},{18446744073690529755LLU,17554429850205290495LLU,67610898432212196LLU,10172162593569898480LLU,13849408881047896054LLU,262143LLU},{16411934872026742783LLU,18446744073682812887LLU,4544127900797108223LLU,18446744073441377283LLU,4609548567410190191LLU,246771LLU},{4448848862420926463LLU,18446744073105519420LLU,14986871183500115967LLU,18446740707528733692LLU,17528008860006799519LLU,261183LLU},{16595764626858426471LLU,18158530258516049859LLU,18446744073709551363LLU,2162641583966456895LLU,4597339590305513471LLU,262080LLU},{18158568552875387583LLU,14913516234401277951LLU,18433232450177201087LLU,18157950747604418559LLU,4611684264998647805LLU,224252LLU},{2305806441835716577LLU,4467569731275955069LLU,18230346978338738044LLU,16717084739869081599LLU,15690538458156105715LLU,245567LLU},{18446728560281337759LLU,14105257527364970495LLU,18429010067845017839LLU,13365812863701090303LLU,16605614498698475516LLU,224255LLU},{286769812299636735LLU,4467570830292672511LLU,4341453548060348284LLU,16717361816799280131LLU,15996757149471829987LLU,235507LLU},{13690520106864476159LLU,18446744068877697855LLU,1152903912676655103LLU,18446731975860223999LLU,18176527829221302719LLU,130431LLU},{9168762041874251383LLU,18446479984556982256LLU,18445635765784281087LLU,18443295734661891068LLU,17577513332089020127LLU,196270LLU},{17068642585316424175LLU,18442521123597844239LLU,18446744072891662083LLU,2292187349624044799LLU,9213713917316955583LLU,130389LLU},{18445270212700553215LLU,288230363266600959LLU,4324564018715885820LLU,16284989864078737395LLU,14770395898197649392LLU,246783LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][6] = {{4156936040835186687LLU,18446744073709551510LLU,1085310606174846975LLU,18446740707527947200LLU,18446744072635809807LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,262143LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,6],[3,7],[4,6],[4,8],[5,9],[5,10],[6,11],[7,8],[7,9],[8,12],[9,12],[10,11],[10,13],[11,13],[12,13]]\n", fout);
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

