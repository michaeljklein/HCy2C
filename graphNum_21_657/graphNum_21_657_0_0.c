#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_657_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][6] = {{18446744073172680705LLU,4294967295LLU,18446744073692774400LLU,18014398509481983LLU,18446744073709289472LLU,67108863LLU},{18446744073709551615LLU,4095LLU,18446744073692774400LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,16777215LLU,18428729675200069632LLU,18446744073709551615LLU,67108863LLU},{18446744073172680704LLU,18446744073709551615LLU,8491361175513071615LLU,15188653047119861LLU,18446744073709289472LLU,67108863LLU},{536870911LLU,18446744069414588416LLU,18446744073709551615LLU,18446744073709551615LLU,18446673704965636095LLU,67108863LLU},{0LLU,18446744073709547520LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18412967076504272895LLU,17861240388023484400LLU,8257015LLU,17149707381026848764LLU,18374752709140921206LLU,67108863LLU},{18446743799905386495LLU,11528792807833599999LLU,18446744073709545471LLU,11457157452030541827LLU,72057593971075023LLU,67108860LLU},{18445618174136668063LLU,18266589093494267903LLU,18446744073706930015LLU,18446743799905382415LLU,16068843469384450047LLU,67107843LLU},{1125899881478643LLU,18443366163539816448LLU,18446739675730100220LLU,18446744073709551615LLU,18446462599806582783LLU,66847743LLU},{17293717015986405377LLU,17293822572289588735LLU,17365880163140632575LLU,17169973566767103LLU,17856772522524016624LLU,66252606LLU},{18374684829867343871LLU,1152921504329973727LLU,18446480190902108160LLU,18446740775174619135LLU,13690098442275913743LLU,63945715LLU},{18411841451475337215LLU,18446744073705373680LLU,4398046511103LLU,18446743799905382412LLU,18374963814366969855LLU,67107843LLU},{18446744057535786975LLU,16086713824354238463LLU,4392082760034154447LLU,15834656289566228483LLU,16212958658529818349LLU,62914219LLU},{9259400576175702015LLU,13834776562999754751LLU,18446744056596787199LLU,13781014860022153215LLU,2305842751452737503LLU,58704892LLU},{9223372020731739127LLU,18444492132296159232LLU,18446739692842876925LLU,18446744073441120255LLU,16284805421213155327LLU,62668799LLU},{16861476968338554625LLU,18446673707599396159LLU,18446743866745750527LLU,16158005067363975167LLU,8358672077937952767LLU,49965054LLU},{18442119527799161087LLU,17293892937845899261LLU,17348147239607860227LLU,2305842996328791871LLU,18429855023069395056LLU,33029903LLU},{11457157305997490431LLU,1148488271232234463LLU,18446740762289765376LLU,2288951211824463871LLU,12537986040752764943LLU,32349181LLU},{18427742862981463823LLU,18446673979840086007LLU,1152657621799404543LLU,16285016046413280252LLU,18391854245100652543LLU,48233715LLU},{9259400560069574655LLU,18446744069557186575LLU,18446739675730149375LLU,18428729949809545215LLU,2449891968826998783LLU,66847740LLU}};

static uint_fast64_t D[21][6] = {{12900400055223058431LLU,18446744073709549152LLU,14933074347311497215LLU,18432968293393612815LLU,18446673704965636095LLU,67108863LLU},{12900400055223058430LLU,18446744073709549152LLU,7320137933380386815LLU,18439326401475209893LLU,18446744073709551615LLU,67108863LLU},{5546344018486493185LLU,16817467462835509663LLU,18446744073702619736LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744069414588415LLU,16104297589444182015LLU,18437560220165592415LLU,18446673704965636095LLU,67108863LLU},{18446744073709551615LLU,1629276610874048511LLU,3513669726404986279LLU,13775780315938800LLU,18446744073709289472LLU,67108863LLU},{18446744073709551615LLU,1629276610874044415LLU,11126606140336096679LLU,18436147347434411354LLU,18446744073709551615LLU,67108863LLU},{14771806503227051677LLU,10195645945824139679LLU,18446744073706922847LLU,11475171850540023807LLU,72057593971075023LLU,67108860LLU},{9187504317959549283LLU,17565110639158902768LLU,18446744073696722160LLU,17149707381026848767LLU,18374752709140921206LLU,67108863LLU},{18446744073684187635LLU,8633927460976590847LLU,18446739675671240180LLU,7850039132745908223LLU,18446532967476861750LLU,66847743LLU},{18446744073506639775LLU,11258560337516953599LLU,3513669726461224719LLU,10610480447475412992LLU,16068843470457824457LLU,67107843LLU},{13706562639985901567LLU,18446744073432676294LLU,14987699119798091775LLU,18433228942077789135LLU,13690056221029826559LLU,63945715LLU},{16415495187918225407LLU,18446744072601468025LLU,17310991507863371775LLU,18445635701547727935LLU,17856744375026450431LLU,66252606LLU},{14771806777745635569LLU,1148487998988351903LLU,18446744073709487100LLU,2175503602259083263LLU,2449958197289535375LLU,66847740LLU},{9223854722180365691LLU,17580874199937155071LLU,18446744056584191230LLU,17293822569102704639LLU,18398822685120265207LLU,58704895LLU},{9223050429585286087LLU,18376934018742140912LLU,4392082760033927105LLU,18014398509481983999LLU,18422673840032136828LLU,62914219LLU},{18446100859001478975LLU,12753846681856212991LLU,17568331040124038207LLU,12069646726743457788LLU,16093050318454843859LLU,58719575LLU},{13828285192500150271LLU,18446744073709303804LLU,18428730761826794499LLU,18433233258519985935LLU,18442485799155923071LLU,32505795LLU},{17888156927637061631LLU,18446744072879079175LLU,14987979301184275455LLU,18446673773683803135LLU,4179325000357234687LLU,48182271LLU},{18130383755565596431LLU,18446673979839348595LLU,18014191545745407LLU,16284963218314752252LLU,18379177936612229119LLU,50068543LLU},{9795326771464239359LLU,18442310839504466173LLU,18445895509504688127LLU,2287898966296100671LLU,16717308281991725055LLU,32821244LLU},{18445779251748898575LLU,17298256074859626495LLU,3513669726448450563LLU,16285016252571713532LLU,18374967954648086640LLU,67107843LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][6] = {{12900400055223058431LLU,18446744073709549152LLU,14933074347311497215LLU,18432968293393612815LLU,18446673704965636095LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,6],[3,7],[4,6],[4,8],[5,9],[5,10],[6,11],[7,8],[7,12],[8,12],[9,11],[9,13],[10,11],[10,13],[12,13]]\n", fout);
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
