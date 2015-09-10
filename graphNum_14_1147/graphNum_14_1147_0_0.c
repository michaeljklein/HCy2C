#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_14_1147_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 13;
static uint_fast32_t endhere = 0;
char str[24] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[14][4] = {{549755813887LLU,18446744073709289472LLU,18446744073709551615LLU,16777215LLU},{18446743523953737728LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,16140901064496119807LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,2305843009213693951LLU,18446742974197923840LLU,16777215LLU},{18446744073709543424LLU,3454243253271396351LLU,18442241021682089976LLU,16777215LLU},{18302594800706134015LLU,18446744073709420029LLU,4503530839735047LLU,16777215LLU},{13829463190431334399LLU,18302485946454491119LLU,18446744073709551615LLU,16773120LLU},{1125882724876161LLU,9222527611921498108LLU,17870214051770925054LLU,16748415LLU},{18446744073441075327LLU,18446744060811804675LLU,18433303643571611641LLU,16547837LLU},{18446737407919275775LLU,18446708889874333599LLU,18162876546811953103LLU,15957503LLU},{18419696086526459899LLU,16140936248867946495LLU,288228177128259391LLU,13627383LLU},{18446532959012912127LLU,18419722475844662271LLU,16140338114525659391LLU,11468736LLU},{17581207979158274031LLU,18446743660990038015LLU,18410705381102714879LLU,8114239LLU},{1152776362628743071LLU,18446709439024070652LLU,18230518515021119454LLU,12042191LLU}};

static uint_fast64_t D[14][4] = {{18446743855579119614LLU,12632543421261152255LLU,18446743500305890831LLU,16777215LLU},{15472115970075525119LLU,15471472986627430070LLU,18446743754501369343LLU,16777215LLU},{16859294142776202061LLU,9223372036854639097LLU,18446743866809766896LLU,16777215LLU},{4562078252697808051LLU,18012843776385433423LLU,18446744073709551615LLU,16777215LLU},{18445618723558522879LLU,18212342210219737087LLU,11128394567460977151LLU,16775590LLU},{10945998894323990527LLU,18446744073172916199LLU,18444956539178397695LLU,16774745LLU},{18212556893086285823LLU,569115902960532668LLU,7320137200383819520LLU,16777215LLU},{18446743867123253247LLU,18167520879867592703LLU,11515704114042364015LLU,16546300LLU},{18446744044714983423LLU,18445649097365913599LLU,17473966553675399071LLU,16748327LLU},{18411207564231439353LLU,9223372036854744063LLU,18445050962838822907LLU,13625203LLU},{9511180092898803279LLU,18446744073709551491LLU,18446506562540267516LLU,15957213LLU},{17329831574876516071LLU,16428286483131826079LLU,8590462357581332479LLU,8118271LLU},{9196337244937877947LLU,18411810377380655228LLU,14833975364232937471LLU,11468799LLU},{18446163119202887679LLU,16176929861237739519LLU,4608307236375101307LLU,6157311LLU}};

uint_fast8_t X[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[14][4] = {{18446743855579119614LLU,12632543421261152255LLU,18446743500305890831LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU}};

#if UINTPTR_MAX == 0xffffffffffffffff // 64-bit. Hopefully this means the cpu has 'popcnt'.
int counter (uint64_t * buf){
    uint64_t cnt[14];
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
            "popcnt %2, %2  \n\t"
            "add %2, %0     \n\t"
            "popcnt %3, %3  \n\t"
            "add %3, %1     \n\t"
            : "+r" (cnt[12]), "+r" (cnt[13])
            : "r" (buf[12]), "r" (buf[13]));


    return cnt[0] + cnt[1] + cnt[2] + cnt[3] + cnt[4] + cnt[5] + cnt[6] + cnt[7] + cnt[8] + cnt[9] + cnt[10] + cnt[11] + cnt[12] + cnt[13];
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
    sprintf(str, "[              ,%5d]\n", this);
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
    fputs("[[0,1],[0,2],[0,3],[0,4],[1,2],[1,3],[1,4],[2,5],[2,6],[3,5],[3,6],[4,5],[4,6],[5,6]]\n", fout);
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

