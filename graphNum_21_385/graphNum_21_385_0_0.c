#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_385_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][4] = {{18158518095069576195LLU,17872535116924911615LLU,18446463696105365535LLU,15LLU},{274877906943LLU,18446744073709547520LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18445618173802713087LLU,18446744073709551615LLU,15LLU},{18446744073709027328LLU,1125899906834431LLU,18446744073709551600LLU,15LLU},{18446743249076355071LLU,18446744073709551615LLU,18446744073705357327LLU,15LLU},{1099511103489LLU,1125899906838528LLU,18446744073709551600LLU,15LLU},{18446743798832693247LLU,18445618173802725375LLU,18446744073705357327LLU,15LLU},{18158514797069466625LLU,17871409221312970751LLU,18446744071566262271LLU,15LLU},{288230376151188479LLU,576460752303419392LLU,18446742976345407472LLU,15LLU},{18446744073173729279LLU,18446744069414600703LLU,18446463696096976911LLU,15LLU},{18446743799368515583LLU,18445618178097676287LLU,18374967954639953919LLU,15LLU},{18446743798831644672LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{1152921230802159615LLU,1151795621879869440LLU,18374966859427495920LLU,15LLU},{18445622571817762755LLU,18412967076487561215LLU,17942324422643809823LLU,15LLU},{18159639596961365055LLU,17906312114146902015LLU,14411254922781647359LLU,15LLU},{1152921488500688895LLU,1152917123740205040LLU,3454542324745125887LLU,15LLU},{18446743816011022335LLU,18445622571849216015LLU,18235073860427055088LLU,12LLU},{4611619908136726515LLU,16133301033965253631LLU,13726404857363922839LLU,11LLU},{18428800043818417935LLU,18311636084621049855LLU,18014332538280999039LLU,6LLU},{18176462124960709875LLU,18007643106013413375LLU,10376079135058421663LLU,11LLU},{18432388836928495455LLU,4521609902497464304LLU,8931719928642075391LLU,7LLU}};

static uint_fast64_t D[21][4] = {{1152921230802159615LLU,1151795621879869440LLU,18374966859427495920LLU,15LLU},{18446743798832693246LLU,18446368773740601343LLU,18446744073709551615LLU,15LLU},{12297829199220047873LLU,18446744073709550250LLU,18446744073709551615LLU,15LLU},{18446743249075830783LLU,18445993473771667455LLU,18446744073705357327LLU,15LLU},{6148915424244269055LLU,1125899906827605LLU,18446744073709551600LLU,15LLU},{18446743798832693247LLU,18445618173802725375LLU,18446744073705357327LLU,15LLU},{1099511103489LLU,1125899906838528LLU,18446744073709551600LLU,15LLU},{18446743799904337919LLU,18445618190982529023LLU,18446742976341229551LLU,15LLU},{18446744072637906943LLU,18446744056529747967LLU,18446744071566245919LLU,15LLU},{1152918206071441405LLU,1151795604700000256LLU,18374967954644140016LLU,15LLU},{17293826967149213699LLU,17296074368916389887LLU,18446463696096985087LLU,15LLU},{6148915149366362111LLU,18445993473771660629LLU,18446744073709551615LLU,15LLU},{18158518095069576195LLU,17872535116924911615LLU,18446463696105365535LLU,15LLU},{14987979447145904127LLU,8070183299382770739LLU,14381963484057681913LLU,15LLU},{4611685857365807103LLU,11528356396206650316LLU,17900119024689905654LLU,15LLU},{18226929708770000295LLU,18108974098381275135LLU,18302463957631233343LLU,12LLU},{18378332460009127515LLU,18210305092253188095LLU,3458649064218817247LLU,15LLU},{18429855532056493887LLU,9115229570453208883LLU,17858971373577566717LLU,6LLU},{1152921295226791935LLU,14986923771028304127LLU,10321405083481227251LLU,11LLU},{18446744009284919295LLU,4611615924561116928LLU,17997509753180323836LLU,6LLU},{18230518308606180855LLU,18152954563545788671LLU,16086714106728411059LLU,9LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][4] = {{1152921230802159615LLU,1151795621879869440LLU,18374966859427495920LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,15LLU}};

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

    } else {
        A[i][0] = A[i-1][0] & D[i][0];
        A[i][1] = A[i-1][1] & D[i][1];
        A[i][2] = A[i-1][2] & D[i][2];
        A[i][3] = A[i-1][3] & D[i][3];

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,3],[2,4],[3,5],[4,6],[4,7],[5,6],[5,7],[6,8],[7,9],[8,10],[8,11],[9,12],[9,13],[10,11],[10,12],[11,13],[12,13]]\n", fout);
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

