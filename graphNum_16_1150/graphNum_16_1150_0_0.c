#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_16_1150_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 15;
static uint_fast32_t endhere = 0;
char str[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[16][6] = {{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,524287LLU,18446744004990074880LLU,72057594037927935LLU},{18446744073709551615LLU,31LLU,18446744073709547520LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,4095LLU,18446744073709027328LLU,18446744073709551615LLU,72057594037927935LLU},{0LLU,18446744073709551584LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073707454464LLU,18446744073709551615LLU,18444912287336636415LLU,6845462628912850423LLU,18374686513812733694LLU,72057594037927935LLU},{18446739675665137663LLU,17293808258271666239LLU,18446744073709551563LLU,18437455124273037311LLU,72057588937586649LLU,72057594037923840LLU},{4398046511103LLU,18433233274609344480LLU,16717361788883042303LLU,18302065935680274431LLU,18446744073708498943LLU,72057589742964735LLU},{11528933545321953281LLU,18445618173819486207LLU,2305843008945143807LLU,18446742424440008702LLU,18446673773550510079LLU,72057460759592935LLU},{18433215682614134783LLU,1125899906842623LLU,18445617658388934656LLU,18429855573492105215LLU,17942411284188233726LLU,72053333428264959LLU},{18445618169511923711LLU,18176528096065223804LLU,18302628887781179359LLU,18446691297134641151LLU,71635381004533759LLU,71991485363912700LLU},{18338582920156938227LLU,18446735273589859327LLU,144115188075855871LLU,14123288379860189184LLU,18446743661392691195LLU,71002058571870211LLU},{18446744004922933215LLU,9763803862753345535LLU,13835041493888270335LLU,18446673704965898179LLU,16571415254668410879LLU,68604844058869655LLU},{18446611445119123455LLU,9223372036846370791LLU,18446744072633712248LLU,70368744127551LLU,18421974275759013376LLU,58122930202020479LLU},{17579941882257997503LLU,18446636459008425983LLU,18432969391965470719LLU,18446744073709551615LLU,11529190788093182463LLU,17987958639493118LLU},{17296071001660424191LLU,11520207846812741631LLU,17293822568976347647LLU,18446744005056724943LLU,18409589309136957439LLU,34267104447297471LLU},{1152921501318511071LLU,18445758808061902304LLU,18320630070810443775LLU,18301995635655573503LLU,17293786285218987527LLU,60758931013631997LLU}};

static uint_fast64_t D[16][6] = {{13609871139360574307LLU,17982283966938988665LLU,14336082628206147487LLU,18446744073709277180LLU,18446744073709551615LLU,72057594037927935LLU},{16965963932348973054LLU,18446744073709551606LLU,18279383007362015231LLU,6413029017744487847LLU,18446744037651643635LLU,72057594037927935LLU},{6317653075709555869LLU,5763300014703394735LLU,18446744073709550955LLU,18417749124483907583LLU,18446744060421785500LLU,72057594037927935LLU},{18446744073709551615LLU,13147904165776719839LLU,4278022511850941172LLU,12062710005190982235LLU,18446744054335748975LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073692774431LLU,16384051433843982335LLU,17869262527536136031LLU,14915921959404430287LLU,72057592333361976LLU},{18446744073709551615LLU,13818943269033213951LLU,18446744071562070782LLU,18192276387153313791LLU,18389196614362447487LLU,72057591447527423LLU},{18446744073709551615LLU,16609258355931742207LLU,4609501082664566721LLU,1139410705658142963LLU,3588369583318138872LLU,72057594037927111LLU},{18429827331372613631LLU,18446744073709551606LLU,18446743525000216575LLU,18428747265288716047LLU,17942340907383652351LLU,72053331816071999LLU},{10051541755204993023LLU,18446744073709551615LLU,76495222493675519LLU,17437935575301619710LLU,14987979559888880067LLU,72057460667219936LLU},{16014413246835621873LLU,2305843004926902255LLU,18446744073709549694LLU,13853070737950113791LLU,18389322637160452095LLU,71002056285831167LLU},{8640701242877658271LLU,18159111316483571708LLU,18446744073709551615LLU,18442735252699873279LLU,18446195417373867582LLU,71991485059555327LLU},{18444495829306302071LLU,18298002138489362175LLU,17854520439234854463LLU,18446744073709494270LLU,18428712083014025215LLU,49239394865908734LLU},{12826249530902048655LLU,18383691484195188605LLU,10376012615871084511LLU,18446744073709285375LLU,9799683805332635647LLU,34889677152452599LLU},{18365679037742726139LLU,287658629153028579LLU,18373560457878110200LLU,18446744073709550593LLU,18294184498893422591LLU,60586660882021919LLU},{18446744052503140479LLU,18229447590712179967LLU,9079538323755532281LLU,4611686018427387134LLU,9218525389574274560LLU,58493915518467820LLU},{18446739950522204151LLU,18446742421220878335LLU,18446532555159367687LLU,14974468761006375935LLU,13483772542736924671LLU,17166675044463103LLU}};

uint_fast8_t X[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[16][6] = {{13609871139360574307LLU,17982283966938988665LLU,14336082628206147487LLU,18446744073709277180LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[0,4],[1,2],[1,3],[1,5],[2,6],[2,7],[3,6],[3,7],[4,5],[4,6],[4,7],[5,6],[5,7]]\n", fout);
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
