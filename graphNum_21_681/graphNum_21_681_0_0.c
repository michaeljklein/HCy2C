#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_681_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][6] = {{18446744073675997185LLU,2147483647LLU,18446744073708503040LLU,17592186044415LLU,18446744073709551104LLU,67108863LLU},{18446744073709551615LLU,1023LLU,18446744073708503040LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,1048575LLU,18446726481523507200LLU,18446744073709551615LLU,67108863LLU},{18446744073675997184LLU,18446744073709551615LLU,8608067600324231167LLU,6425134618069LLU,18446744073709551104LLU,67108863LLU},{33554431LLU,18446744071562068992LLU,18446744073709551615LLU,18446744073709551615LLU,18446743798831645183LLU,67108863LLU},{0LLU,18446744073709550592LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{14987979559889010687LLU,18432107344855826399LLU,17293822569103703639LLU,9097148101986091007LLU,18442240711379124120LLU,67108863LLU},{18442521940536066047LLU,16717344224613236223LLU,1152921504606846975LLU,16715092424799551488LLU,4503462062522879LLU,67108860LLU},{18446603336245245659LLU,18410429334947366911LLU,18446744073709419517LLU,18446744073646587903LLU,7611083370247750143LLU,67108737LLU},{140737488306047LLU,4611615647536249856LLU,18446744004994269183LLU,18446744073709551615LLU,18446708889345851391LLU,67104895LLU},{18419715329119739905LLU,18158513699165192063LLU,18442521949058891775LLU,17870300913592172543LLU,18445740494471299071LLU,67047399LLU},{9223372036821229567LLU,288230375983939575LLU,4611686018426339328LLU,576460494605385664LLU,4544132024016829952LLU,66124543LLU},{14987838830990589951LLU,18437736848684486623LLU,17293822637822148351LLU,18374580926492393471LLU,18442275620864982971LLU,67108739LLU},{4322540796591996927LLU,17870283321305464316LLU,936744595096600575LLU,17870283321405079552LLU,17298326017839788543LLU,63372543LLU},{18443366365932814275LLU,17293796215183376383LLU,18391856453250966015LLU,17289442114778693631LLU,1152921504506122215LLU,54513620LLU},{17870424056996556791LLU,18230570879262654463LLU,18446744073444517887LLU,18158232218352287695LLU,15528407390939498223LLU,46100351LLU},{576459661381287295LLU,4609926797692210176LLU,18446673911392239555LLU,9205357638345293823LLU,18446466722974203902LLU,32305407LLU},{18428162292437737535LLU,17582061741278167036LLU,18443363072232914943LLU,17296074368915341375LLU,17365316654824551423LLU,63913455LLU},{9223372036854258703LLU,285979124785216757LLU,4611686018427387840LLU,540978154865422588LLU,4382002299992539134LLU,32305404LLU},{15600337166709293055LLU,18446744056516706303LLU,17298326168477368383LLU,18446673701693816771LLU,18389319876966604289LLU,45350815LLU},{18443365336754126799LLU,9223363788504275971LLU,18446678038587375567LLU,18445037635958210559LLU,4611448266116251646LLU,25023484LLU}};

static uint_fast64_t D[21][6] = {{10043227976004272127LLU,18446744073709551002LLU,14758014710079029247LLU,18446743232100646719LLU,18446743798831645183LLU,67108863LLU},{10043227976004272126LLU,18446744073709551002LLU,7378491145780723711LLU,18446732626121823637LLU,18446744073709551615LLU,67108863LLU},{8403516097705279489LLU,4212188703382046309LLU,18446744073709147049LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744071562068991LLU,15987591164622536703LLU,18446743512636948351LLU,18446743798831645183LLU,67108863LLU},{18446744073709551615LLU,14234555370327506943LLU,3688729363630926934LLU,841608904896LLU,18446744073709551104LLU,67108863LLU},{18446744073709551615LLU,14234555370327505919LLU,11068252927929232470LLU,18446737929111235178LLU,18446744073709551615LLU,67108863LLU},{9219009166130988675LLU,16320732031064995061LLU,18446744073709155325LLU,16715110016985595903LLU,4503462062522879LLU,67108860LLU},{14168264358289815933LLU,4594164168076562255LLU,18446744073709493763LLU,9097148101986091007LLU,18442240711379124120LLU,67108863LLU},{18446744073709502335LLU,2155991389802856447LLU,4611685949708414807LLU,6569886488941362383LLU,18446709164215369420LLU,67104895LLU},{18446744073700046555LLU,16653864891446198271LLU,17523787418916649212LLU,11876858426314130416LLU,7611083370256138035LLU,67108737LLU},{1980097207134584831LLU,18446744073541778931LLU,923223890895831039LLU,18446743799855054784LLU,4544131862101663231LLU,66124543LLU},{17259474061134659583LLU,18446744073169420062LLU,18442254712959926271LLU,18446743248257105727LLU,18445740381508559871LLU,67047399LLU},{9219009174696824615LLU,71923589749144821LLU,4611686018426595327LLU,14115685256786672847LLU,10840164165516001007LLU,67104894LLU},{18365658802008850369LLU,9223363242098499407LLU,18391856453250965519LLU,18444509866081910783LLU,18445097795565125600LLU,54513623LLU},{125990778269710719LLU,13817536237853667324LLU,18230567164199247859LLU,9097271247288401919LLU,18443886976097386399LLU,63372543LLU},{18446742982787398879LLU,18435619206469750783LLU,18446673773684817600LLU,4511432342048338940LLU,9070003358918574010LLU,32309241LLU},{18446744071802185715LLU,16447127714395062271LLU,17523787625074319871LLU,16282271867253821379LLU,14069245235905414759LLU,46100359LLU},{16031662175869435903LLU,9223372036447788995LLU,18379176872224219151LLU,18446743799855054847LLU,4610479800180252640LLU,54131679LLU},{14415882767357181951LLU,18446744056513462239LLU,17293892937582641151LLU,18446673700875091967LLU,18442517787362445311LLU,46100359LLU},{18443928460519799823LLU,18444492821973941308LLU,18446687943855702015LLU,18411260909335867455LLU,18230412747088428031LLU,32478716LLU},{17996274159511921663LLU,17584304727877419007LLU,17362502463217737727LLU,17329780997376446403LLU,17525192250638726687LLU,47677359LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][6] = {{10043227976004272127LLU,18446744073709551002LLU,14758014710079029247LLU,18446743232100646719LLU,18446743798831645183LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,6],[3,7],[4,6],[4,8],[5,9],[5,10],[6,11],[7,9],[7,12],[8,11],[8,12],[9,13],[10,11],[10,13],[12,13]]\n", fout);
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
