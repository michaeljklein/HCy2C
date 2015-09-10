#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_16_1103_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 15;
static uint_fast32_t endhere = 0;
char str[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[16][3] = {{18446744039886680064LLU,18446743798832693247LLU,4398046511103LLU},{18374686479940059135LLU,18446744073709551615LLU,4398046511103LLU},{72057594037927935LLU,18446744073708503040LLU,4398046511103LLU},{18446744073441116160LLU,18446744073709551615LLU,4398046511103LLU},{6196953087261790207LLU,18444492548773074389LLU,4398046511103LLU},{18446744039349764095LLU,2251799813685247LLU,4398046511103LLU},{18446739744114147327LLU,18446744073709551615LLU,4398046248960LLU},{1152815949879967728LLU,18433229976226496511LLU,4398029996031LLU},{18446740291735060431LLU,18446744073239789567LLU,4397526195785LLU},{18446603331926228799LLU,18428725273395462140LLU,4381403512831LLU},{18445899623009612031LLU,18338631023790653379LLU,3315714752511LLU},{14987662891413404924LLU,18406201751386456051LLU,3195453833215LLU},{4602608174473674739LLU,16131610191182381055LLU,2197867724351LLU},{18374690877718126591LLU,18444492548773773311LLU,4398046511103LLU},{18375812379578466303LLU,286013760440631551LLU,4397526417407LLU},{18392697579394564095LLU,4609997168566140927LLU,3285246021631LLU}};

static uint_fast64_t D[16][3] = {{17512229558844129279LLU,572026971663369215LLU,4398046473142LLU},{6196953087082849621LLU,18446744073708852629LLU,4398046511103LLU},{18446735278063917738LLU,18446744073709551615LLU,4398046511103LLU},{12249799782272335871LLU,18446744073709202026LLU,4398046511103LLU},{18446739675931475967LLU,18302628728695422847LLU,4398046361307LLU},{18230562495502745599LLU,18446743720362508287LLU,4398046436717LLU},{1150704889165250559LLU,18018832800407354560LLU,4398046511103LLU},{18406209340398895103LLU,8069183894851932159LLU,4096559710151LLU},{287122068430913535LLU,18304846050831105984LLU,3777414822911LLU},{18444492205176193023LLU,17870212952661947391LLU,4226226585592LLU},{18419721101502316543LLU,11528370621138092031LLU,4392473300543LLU},{18433232862506647551LLU,14987557347423883263LLU,1922434072071LLU},{18410431593899359487LLU,9186208513770389491LLU,3169417199615LLU},{18446744073530602837LLU,18302628728695422783LLU,4398046361307LLU},{18446743492265766960LLU,18446743838503469055LLU,3777414820351LLU},{4611052681476174835LLU,18365659248630693839LLU,1236937998335LLU}};

uint_fast8_t X[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[16][3] = {{17512229558844129279LLU,572026971663369215LLU,4398046473142LLU},{18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU},{18446744073709551615LLU,18446744073709551615LLU,4398046511103LLU}};

#if UINTPTR_MAX == 0xffffffffffffffff // 64-bit. Hopefully this means the cpu has 'popcnt'.
int counter (uint64_t * buf){
    uint64_t cnt[16];
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


    return cnt[0] + cnt[1] + cnt[2] + cnt[3] + cnt[4] + cnt[5] + cnt[6] + cnt[7] + cnt[8] + cnt[9] + cnt[10] + cnt[11] + cnt[12] + cnt[13] + cnt[14] + cnt[15];
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

    } else {
        A[i][0] = A[i-1][0] & D[i][0];
        A[i][1] = A[i-1][1] & D[i][1];
        A[i][2] = A[i-1][2] & D[i][2];

    }
}

void printout(){
    sprintf(str, "[                ,%5d]\n", this);
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
    fputs("[[0,1],[0,4],[0,5],[1,2],[1,4],[1,5],[1,6],[2,3],[2,5],[2,6],[2,7],[3,6],[3,7],[4,5],[5,6],[6,7]]\n", fout);
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

