#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_693_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][6] = {{18446744073172680705LLU,67108863LLU,18446744073709289472LLU,4398046511103LLU,18446744073709551552LLU,16383LLU},{18446744073709551615LLU,511LLU,18446744073709289472LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,262143LLU,18446739675663040512LLU,18446744073709551615LLU,16383LLU},{18446744073172680704LLU,18446744073709551615LLU,9213658401378664447LLU,3667723812351LLU,18446744073709551552LLU,16383LLU},{536870911LLU,18446744073642443264LLU,18446744073709551615LLU,18446744073709551615LLU,18446744056529682495LLU,16383LLU},{0LLU,18446744073709551104LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18337742338819883007LLU,13835058055282412535LLU,13602828005356339199LLU,18446726498703376369LLU,16383LLU},{18379189805494829055LLU,18446744073709551615LLU,4611686018427387903LLU,18446739675663040512LLU,18428747267323183167LLU,16383LLU},{18444492274150784199LLU,3449750661661393919LLU,18446744073709420447LLU,18446744073709551615LLU,17882281192284225599LLU,16383LLU},{2251799813685247LLU,18446744073642507776LLU,18446744004991123455LLU,18446744073709551360LLU,576460202551803903LLU,16383LLU},{18446462598732808193LLU,18428729675254579151LLU,18446532967477018623LLU,18374690813293625343LLU,13759618226038243327LLU,16368LLU},{4611668425704505343LLU,18014398508691455LLU,18446743249075568640LLU,72057594022199295LLU,17275595930489323456LLU,16143LLU},{18444492548764859871LLU,9150747060188678143LLU,13835058124001632191LLU,18293612890285932543LLU,17888280677481201655LLU,16383LLU},{9223372020345774067LLU,16268127745871445853LLU,4611686018427142143LLU,17527956973167575040LLU,1152868728048712719LLU,15598LLU},{16217453754125910015LLU,18446744073709551615LLU,18442240542534270975LLU,18446739675663302655LLU,18158584065232208895LLU,13243LLU},{16143152864256062271LLU,18446611101521870847LLU,18446744073442162800LLU,11525414257495638015LLU,17858320616646508540LLU,13243LLU},{2303599989386903551LLU,18446744073642642944LLU,13853072385340604415LLU,18446744073709290240LLU,1152904480426294335LLU,15598LLU},{18446357042999328513LLU,18446742974249279432LLU,18230571288374282239LLU,18446185521802629107LLU,11529208240692264771LLU,12028LLU},{18149505364427768063LLU,2287829710215839743LLU,18446516474790019056LLU,10304798831895642111LLU,18334435557859358719LLU,7155LLU},{4609979567786954751LLU,140737437199935LLU,14987979508349403120LLU,9227875636481949503LLU,8070440318813601279LLU,7631LLU},{17257789236065599247LLU,18446742982787858431LLU,18442521124223582223LLU,9222875126302769151LLU,18270892581439004608LLU,10047LLU}};

static uint_fast64_t D[21][6] = {{13910264926573690879LLU,18446744073709551347LLU,13849628508496592895LLU,18446740771147088640LLU,18446744056529682495LLU,16383LLU},{13910264926573690878LLU,18446744073709551347LLU,7681286546307678207LLU,18446742242532698538LLU,18446744073709551615LLU,16383LLU},{4536479147135860737LLU,3286310112947340044LLU,18446744073709401370LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073642443263LLU,15382000363567579135LLU,18446741872001242965LLU,18446744056529682495LLU,16383LLU},{18446744073709551615LLU,15160433960762212351LLU,4597115565213108965LLU,3302562462975LLU,18446744073709551552LLU,16383LLU},{18446744073709551615LLU,15160433960762211839LLU,10765457527402023653LLU,18446741506839893589LLU,18446744073709551615LLU,16383LLU},{9153565967864339107LLU,12527877177545784157LLU,18446744073709403998LLU,18446744073709551615LLU,18428747267323183167LLU,16383LLU},{13762102984766350685LLU,9096175274221438894LLU,18446744073709535667LLU,13602828005356339199LLU,18446726498703376369LLU,16383LLU},{18446744073709551615LLU,18119862976415531007LLU,4611685949708135157LLU,11142586298936590080LLU,576460219727478760LLU,16383LLU},{18446744073427598535LLU,490321646008139775LLU,18432173620495966095LLU,7304161077335424255LLU,17882281192288419799LLU,16383LLU},{967116519613923327LLU,18446744073708760831LLU,14930557581298499583LLU,18446740775157953340LLU,17275595920181402047LLU,16143LLU},{17554535358224400383LLU,18446744073696952259LLU,17365603070041391103LLU,18446744005258448835LLU,13759618219166295679LLU,16368LLU},{9153566242478414779LLU,18010994213668716381LLU,4611686018427338364LLU,15833371183866183424LLU,564480473544261614LLU,16383LLU},{16212950137274103135LLU,9223261226698405887LLU,18442240542534269363LLU,13832524780491767807LLU,18176527528124760061LLU,13243LLU},{4610788816469102577LLU,16141041793394478860LLU,18446744073709291519LLU,17298260198032408575LLU,1152904496536354755LLU,15598LLU},{18444501053614178295LLU,16631230467214872575LLU,13839561654909329407LLU,17681088156591194367LLU,18158462020507401239LLU,15598LLU},{18446744073642700815LLU,2305702280315273215LLU,18445684419378280448LLU,1148487178239606783LLU,18158584066302017532LLU,13243LLU},{17999760101292113919LLU,2305843009213693695LLU,14987961984867106800LLU,10376293540387946303LLU,18391645338212446719LLU,7071LLU},{1116756227016097791LLU,18446744073705607160LLU,18173150392118675455LLU,18446740775174652912LLU,14987976154482335491LLU,11887LLU},{16663241447150976783LLU,18446742982787858427LLU,18226085280681558015LLU,18446247095527526387LLU,18213682789989273471LLU,10233LLU},{18147394289221472255LLU,18428870412625460743LLU,14123275172857249791LLU,18379190078493441807LLU,4611672398940304639LLU,7670LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][6] = {{13910264926573690879LLU,18446744073709551347LLU,13849628508496592895LLU,18446740771147088640LLU,18446744056529682495LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,6],[3,7],[4,6],[4,8],[5,9],[5,10],[6,11],[7,11],[7,12],[8,11],[8,13],[9,12],[9,13],[10,12],[10,13]]\n", fout);
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

