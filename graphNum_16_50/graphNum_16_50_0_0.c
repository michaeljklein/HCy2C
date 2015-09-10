#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_16_50_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 15;
static uint_fast32_t endhere = 0;
char str[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[16][7] = {{18446744073709551615LLU,16383LLU,18446743936270598144LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{0LLU,18446744073709535232LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,137438953471LLU,18444492273895866368LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,2251799813685247LLU,18428729675200069632LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,16717361816765743103LLU,18446709009461395255LLU,18376357325028711327LLU,16861003295743231LLU,18446744073709535232LLU,17592186044415LLU},{17148685784400789248LLU,18446744073709547388LLU,11520243031185817599LLU,16212882232804556795LLU,18441853445820563383LLU,18446742974197940223LLU,17592186044415LLU},{18446733078006006015LLU,18373841986055568851LLU,18446744072611689727LLU,2305843009213693951LLU,18446743876129518572LLU,1099511627775LLU,17592186044415LLU},{18420848324102914047LLU,11516689478324322303LLU,8079457731502669822LLU,18446744073516613246LLU,18446744073709551615LLU,18446744073709551615LLU,17592184995840LLU},{18446744073709551615LLU,18158618820976050175LLU,555983413327167487LLU,13401578894566359024LLU,18446250994284101507LLU,8935133686022029311LLU,17592119912444LLU},{16075598867755547135LLU,18446744073709543367LLU,18266590467887988735LLU,9182672221896699919LLU,18309929642559008893LLU,15524972242801778396LLU,17590105013691LLU},{18446743526099910585LLU,288224328829270845LLU,18446744071092043744LLU,16708354617544540159LLU,17437933906689396735LLU,18446744026448655871LLU,17456894549863LLU},{17941989621478975463LLU,18446744070755319807LLU,18445896350244470815LLU,18446744069948837887LLU,10376293541461622783LLU,18432740693098102771LLU,13331578486783LLU},{9223442405598953471LLU,18415209805343358975LLU,18446744069380501375LLU,18104470502029393919LLU,9223371757212138911LLU,18446744002775383936LLU,12918985846013LLU},{9223372036854775807LLU,17041620985511395328LLU,18446572549895618557LLU,18446744009285042097LLU,18446744073709551615LLU,18320636687070904447LLU,8783149400063LLU},{18410152316268182303LLU,18446744073709551615LLU,13827176068739563519LLU,18446744073436918271LLU,18338657682652659711LLU,18444438398362976253LLU,17590105669631LLU},{9799832308088250363LLU,18428166665114943487LLU,18446744073709551587LLU,18444492342615343103LLU,17582052945254416383LLU,144115188063207311LLU,13073874157567LLU}};

static uint_fast64_t D[16][7] = {{9928003508134817278LLU,18446744073709538918LLU,15672462656697008127LLU,9110275382718545890LLU,18432336072359460661LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,4034975486328160255LLU,16619900847460792743LLU,12534024500392710879LLU,18443143051795584762LLU,18446744073709551615LLU,17592186044415LLU},{18446645113750552109LLU,17935272430007447961LLU,18446744057484134015LLU,15249188338276499455LLU,18446738698464127439LLU,18446744073709551615LLU,17592186044415LLU},{8518839525533733843LLU,14923240231083507711LLU,4601124659486719960LLU,18446743999740898621LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073701163008LLU,18442521949058891775LLU,2305843008123172862LLU,18446669306852737022LLU,18441958861662519271LLU,7781479332982013951LLU,17592185698254LLU},{18428720878855389183LLU,18446603336221212127LLU,18446744073709551615LLU,18446163531435605535LLU,15545299946121982207LLU,10834240134430317206LLU,17592185387451LLU},{18437842363146567679LLU,9790825589903454079LLU,17293822689227554815LLU,18446744073709551615LLU,4395380195238846399LLU,18446743826546779647LLU,17592185998965LLU},{17149703944516141055LLU,18374686479671623664LLU,18446744073701293111LLU,2249728565681147LLU,16969563395932028924LLU,18277768927169544041LLU,17592186044415LLU},{18446673704973762559LLU,18446739673515065343LLU,18302624760317345791LLU,18433092258233319423LLU,9232361641713074173LLU,16124012531533479935LLU,15218008129343LLU},{18446462598731792353LLU,140737488354301LLU,17869227790243397632LLU,16283889253151145983LLU,18446669375637815295LLU,9223372036317919231LLU,16965099816959LLU},{17879290520656667135LLU,18446708888329773047LLU,1152921470245011455LLU,4575657221407899648LLU,18444632993933819903LLU,18446181948389842928LLU,16216956403199LLU},{16138649264681762751LLU,18446741994936991503LLU,18390440281745915903LLU,18446711071164071935LLU,18446744073709420547LLU,17546024132129324255LLU,17570633613280LLU},{18446744073709551615LLU,9223300561082777599LLU,18446744004717411836LLU,17293822500383752191LLU,18430979241630660604LLU,18303191276969787391LLU,6580962836463LLU},{18446744073709551615LLU,13835042627222765567LLU,18225504733961905135LLU,18446497783104829183LLU,18446744073172811775LLU,14987803517660430335LLU,12747060280351LLU},{13542310576124293119LLU,18446744073709549823LLU,17582033154045116415LLU,18444773712331407350LLU,15564435914682793983LLU,4530335352111494071LLU,16965099815935LLU},{18446691295937167215LLU,18300253940500645887LLU,18446743944860475391LLU,18446744073709551615LLU,13744990460781264895LLU,18446743111233949695LLU,5495912955903LLU}};

uint_fast8_t X[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[16][7] = {{9928003508134817278LLU,18446744073709538918LLU,15672462656697008127LLU,9110275382718545890LLU,18432336072359460661LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17592186044415LLU}};

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
        A[i][6] = A[i-1][6] & C[i][6];

    } else {
        A[i][0] = A[i-1][0] & D[i][0];
        A[i][1] = A[i-1][1] & D[i][1];
        A[i][2] = A[i-1][2] & D[i][2];
        A[i][3] = A[i-1][3] & D[i][3];
        A[i][4] = A[i-1][4] & D[i][4];
        A[i][5] = A[i-1][5] & D[i][5];
        A[i][6] = A[i-1][6] & D[i][6];

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
    fputs("[[0,3],[0,4],[0,5],[0,6],[1,3],[1,4],[1,5],[1,6],[2,3],[2,4],[2,5],[2,6],[3,5],[3,6],[4,6],[5,6]]\n", fout);
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

