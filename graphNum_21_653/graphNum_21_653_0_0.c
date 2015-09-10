#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_653_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][6] = {{18446744073441116161LLU,137438953471LLU,18446744073441116160LLU,4611686018427387903LLU,18446744073642442752LLU,70368744177663LLU},{18446744073709551615LLU,16383LLU,18446744073441116160LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,268435455LLU,13835058055282163712LLU,18446744073709551615LLU,70368744177663LLU},{18446744073441116160LLU,18446744073709551615LLU,6770458351772893183LLU,2260619535428089335LLU,18446744073642442752LLU,70368744177663LLU},{268435455LLU,18446743936270614528LLU,18446744073709551615LLU,18446744073709551615LLU,18428729675267178495LLU,70368744177663LLU},{0LLU,18446744073709535232LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18379190079298994175LLU,18140497374903008767LLU,266203071LLU,4611686018427386880LLU,15746106015841662LLU,70368744177656LLU},{18446744005526945791LLU,17293541094125991927LLU,18446744073675997180LLU,13835058055282164735LLU,18441958990565854191LLU,70368744112135LLU},{18444492274127207803LLU,18370178481980997631LLU,18446744073701112575LLU,18230571291594723327LLU,18446742974265032703LLU,70368727439863LLU},{2251799679414207LLU,13833932017953128448LLU,18446726482463031271LLU,18445899648779419647LLU,17870284420917755903LLU,70364465987583LLU},{18445617761485840385LLU,9223372103955046396LLU,18445688542546886655LLU,4611686018414804223LLU,16393102643628601344LLU,70304042647531LLU},{18014380917027512319LLU,9223372028163129215LLU,14987979559620575232LLU,18446673976622055423LLU,9223372036787671039LLU,69336826900671LLU},{18376938348202688511LLU,18446742424425397759LLU,17592186011647LLU,9007199254739946496LLU,574191368893628414LLU,70368727465976LLU},{18446673696878624739LLU,17293402555660894207LLU,4395302130034933374LLU,18446744004990075132LLU,18446743935238728673LLU,67057313316615LLU},{9295146996266434559LLU,18446744073206233079LLU,18433233207180918781LLU,13835058124001640399LLU,18441835554227085311LLU,56762036060415LLU},{9223301660057501671LLU,18446611995412119552LLU,18446726550242983919LLU,18445899580060991484LLU,17888438318958378995LLU,67053297860367LLU},{9799832462732288031LLU,9223512772866605053LLU,18445899584354123773LLU,13835128424013758463LLU,17293717009541877775LLU,57122595082223LLU},{13690942866131519479LLU,576434348689981251LLU,18446743249075822592LLU,14987975433247522815LLU,18373842054606750715LLU,51469126433951LLU},{18149480659512458879LLU,18412966526679515135LLU,14700875083375714303LLU,9209795267274948607LLU,2305840758584246079LLU,29961656456191LLU},{18390457873383620607LLU,18446742969887227855LLU,288229551517949983LLU,18446740774972357632LLU,9150737267797032958LLU,51470872346104LLU},{18149499894539190255LLU,18446638391676616767LLU,18176511603125518319LLU,18446691228700327935LLU,13385821758200741879LLU,32423747778367LLU}};

static uint_fast64_t D[21][6] = {{5624068909381451775LLU,18446744073709544871LLU,17514428583173423103LLU,17361657779781111564LLU,18428729675267178495LLU,70368744177663LLU},{5624068909381451774LLU,18446744073709544871LLU,6459686521594183679LLU,15733982159400773030LLU,18446744073709551615LLU,70368744177663LLU},{12822675164328099841LLU,3804226394343365208LLU,18446744073548739271LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446743936270614527LLU,17825200413352132607LLU,17723353211090591581LLU,18428729675267178495LLU,70368744177663LLU},{18446744073709551615LLU,14642517679366209535LLU,932315490696940856LLU,1085086293928440051LLU,18446744073642442752LLU,70368744177663LLU},{18446744073709551615LLU,14642517679366193151LLU,11987057552276180280LLU,16547819969590942297LLU,18446744073709551615LLU,70368744177663LLU},{12826251670189626691LLU,7416957948628267889LLU,18446744073650551548LLU,18446744073709551615LLU,18441958990565854191LLU,70368744112135LLU},{18375613505254861501LLU,13374562841034546398LLU,18446744073571952519LLU,4611686018427387903LLU,15746106015841662LLU,70368744177656LLU},{18446744073575280575LLU,11221193185738883071LLU,18446726481587859363LLU,10375184392938061823LLU,17888297719874401619LLU,70364465987583LLU},{18446744073672457595LLU,17178691057290838015LLU,932315491563673724LLU,8939628767654969587LLU,18446744073683651244LLU,70368727439863LLU},{17915008144078012415LLU,18446744065017902887LLU,14055730310633488383LLU,18446673769456746447LLU,9216873526521233407LLU,69336826900671LLU},{5722315370375675903LLU,18446744003370864124LLU,18445622301266280447LLU,17361657986933836860LLU,16381586755519774719LLU,70304042647531LLU},{12826251738541393799LLU,574217701908542321LLU,18446744073457106912LLU,14986870411365449727LLU,18441958999053009859LLU,70364465948175LLU},{9225182107724655295LLU,13374564992857800703LLU,18433233207046498295LLU,18446744073709551567LLU,5746453194486840703LLU,56762036125693LLU},{18445508085148319713LLU,18446603382917881054LLU,4395302130065309199LLU,4611686018427387132LLU,12715913410428960752LLU,67057313316858LLU},{18446302344896575615LLU,17872533471946735615LLU,14970246636355191293LLU,8939628767656017859LLU,5764607230972386366LLU,56762282121725LLU},{18419583934206345215LLU,18446744043641109519LLU,18010275325115919LLU,18446744069481447420LLU,4391565748636385279LLU,66450656591806LLU},{17280303021372210815LLU,18412966458027986431LLU,18158518082719449087LLU,8990310704598683647LLU,9500304868217192255LLU,30760554782719LLU},{2268054957619931127LLU,9799806392549244864LLU,18446742991377793023LLU,14122444006235569212LLU,18337592663705908219LLU,51637443854283LLU},{16429131418963017231LLU,18410750356708377597LLU,18446730866432671743LLU,18428747202949021695LLU,18144967711566855943LLU,30758039177071LLU},{11491074877485736447LLU,9259399734080962559LLU,18445899597239804413LLU,13853069155255974915LLU,17293742575336411390LLU,43808519437817LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][6] = {{5624068909381451775LLU,18446744073709544871LLU,17514428583173423103LLU,17361657779781111564LLU,18428729675267178495LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,70368744177663LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,6],[3,7],[4,6],[4,8],[5,9],[5,10],[6,11],[7,8],[7,9],[8,12],[9,13],[10,11],[10,12],[11,13],[12,13]]\n", fout);
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

