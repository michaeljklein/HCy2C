#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_531_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][5] = {{68719476735LLU,18446744073709486083LLU,18446744072635809795LLU,281474976710655LLU,1125899906838528LLU},{18446744073709551615LLU,0LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,0LLU,18446744073709535232LLU,1125899906842623LLU},{18446744073675997184LLU,18446744073709551615LLU,6187802221351010301LLU,18446743798831658871LLU,1125899906842623LLU},{33554431LLU,18446744073709486081LLU,18446744073709551615LLU,13835058330160070655LLU,1125899906842623LLU},{18446744073675997185LLU,65535LLU,18446744073709551615LLU,18446743798831661055LLU,1125899906842623LLU},{18446744073709551615LLU,8608628314212270079LLU,18446744072635809792LLU,4611685835795841023LLU,1125899906838528LLU},{18446744005057183743LLU,18446744073709551615LLU,1073741823LLU,18446462873610731520LLU,1125899839737855LLU},{0LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{16140300731147083777LLU,18446742974197972655LLU,13907115649320091647LLU,18446744073642459135LLU,1125897822796778LLU},{18293621548906455039LLU,1099511622651LLU,18446742978492891135LLU,13835057780471365631LLU,1125833334787775LLU},{9220970701379223551LLU,18446466996779352063LLU,18428729675468295423LLU,16093604746253828095LLU,1124866966687743LLU},{17834253908059357123LLU,18446744073642704895LLU,18014398456004559LLU,17725332504492654592LLU,1109407098732543LLU},{18446462628780572671LLU,4608308318706859779LLU,18446744073709535235LLU,4593794625633767420LLU,1063189089353712LLU},{281474574057087LLU,18446744069682954495LLU,18446678101938159615LLU,13853070804521058303LLU,914587113222159LLU},{18446744071696162879LLU,18446465897334833151LLU,13889102350322237439LLU,18446735826366234623LLU,1124867097296895LLU},{18446744009251618755LLU,281474909863935LLU,4611684923210727423LLU,18446479917114212352LLU,1109342744940543LLU},{18446463696633750015LLU,18446479095702224655LLU,14105344401668554815LLU,18429848977168924671LLU,1072297100836848LLU},{18374951461302827903LLU,18446744021364633807LLU,18445886454635707455LLU,18173147647558287359LLU,773711917481740LLU},{72057585177984759LLU,18379190076074561535LLU,18446691244542263295LLU,14123252134663094211LLU,419867136086271LLU},{18379190027727929295LLU,72057593975010303LLU,18446743042913468415LLU,18230359927664787519LLU,760810456432447LLU}};

static uint_fast64_t D[21][5] = {{18446744073698291075LLU,14757173639245987839LLU,58331295171739647LLU,18446743981463204659LLU,1125899839737855LLU},{7378697602063138814LLU,18446744073709551615LLU,6168358456293763753LLU,18446744073709545062LLU,1125899906842623LLU},{11068046471646412801LLU,11067972570985136129LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709486080LLU,18407856543595058519LLU,13835058330160061917LLU,1125899906842623LLU},{18446744073709551615LLU,7378771502724415487LLU,58331295171739644LLU,18446743798831657779LLU,1125899906842623LLU},{7378697602063138815LLU,18446744073709551615LLU,18388412778537811971LLU,13835058330160057548LLU,1125899906842623LLU},{18446744005012368771LLU,15987030450733842429LLU,18446744073709551615LLU,18446462873610747903LLU,1125899839737855LLU},{11068046471691227773LLU,3689570434463563779LLU,18446744073709551615LLU,4611685835795841023LLU,1125899906838528LLU},{18446744073709551615LLU,7378771502724415486LLU,12278385617415787862LLU,18446744073709541785LLU,1125899906842623LLU},{8991286851813769215LLU,18446744073709546491LLU,18446742974452780275LLU,11121093647146142924LLU,1125833334787775LLU},{14374588956626911231LLU,18446744073709534895LLU,13848784358188462863LLU,16549022738296078335LLU,1125897822796778LLU},{15221565582507507649LLU,3689573994656208551LLU,18446744073656074191LLU,8502232963985457151LLU,1109407165315434LLU},{4454961493565117055LLU,18446463436519860571LLU,18446744072904035583LLU,11481927248946135039LLU,1124866967205525LLU},{18446744073304260135LLU,18217047294330535935LLU,18230501764665180159LLU,18446742402829188915LLU,914587087446015LLU},{18446744035029183963LLU,1148434659595780095LLU,274507633518444543LLU,18446585533812130812LLU,1063189048029183LLU},{17298325073491132415LLU,3689573994723263475LLU,18446744073642704835LLU,3529713617601547468LLU,1109342807915583LLU},{1148419002477834879LLU,18446743811984931855LLU,18442455977354330175LLU,14917039619392405503LLU,1124867101422528LLU},{17298326142952407015LLU,17298326168714331135LLU,18446743815944667135LLU,17365774545599659011LLU,908170809547839LLU},{18446744060822614003LLU,18374756023778148351LLU,1139410641300226047LLU,18446691280474767296LLU,524454146592767LLU},{18446727546113325535LLU,1152868663573872591LLU,17580996589458029631LLU,18443223231037686783LLU,817726841782268LLU},{1152657620473931519LLU,18446531933463592767LLU,14971038283721589759LLU,14974463262859460607LLU,527077042025459LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][5] = {{18446744073698291075LLU,14757173639245987839LLU,58331295171739647LLU,18446743981463204659LLU,1125899839737855LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125899906842623LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,4],[3,6],[4,7],[5,8],[5,9],[6,8],[6,9],[7,10],[7,11],[8,10],[9,12],[10,13],[11,12],[11,13],[12,13]]\n", fout);
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
