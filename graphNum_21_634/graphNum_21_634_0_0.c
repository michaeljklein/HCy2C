#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_634_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][6] = {{18446744071562067969LLU,8388607LLU,18446744073709547520LLU,9223373136366403583LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,63LLU,18446744073709547520LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,4095LLU,18446742974197923840LLU,18446744073709551615LLU,3LLU},{18446744071562067968LLU,18446744073709551615LLU,17825069066272890879LLU,9223372963887708159LLU,18446744073709551615LLU,3LLU},{2147483647LLU,18446744073701163072LLU,18446744073709551615LLU,9223372036854775807LLU,18446744073705357312LLU,3LLU},{0LLU,18446744073709551552LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18370178204838133759LLU,18158513697557843899LLU,16982711355976974335LLU,18446744072640004095LLU,3LLU},{18446742978492891135LLU,18446744073709551615LLU,288230376151711743LLU,9223370937343148032LLU,18446743799905386368LLU,3LLU},{18446181124261420665LLU,5762707463811890815LLU,18446744073709548542LLU,9223372036854775807LLU,18446708891484913664LLU,3LLU},{562949953421311LLU,18446744073701163456LLU,1152921504338427903LLU,18446744073709550592LLU,18442275657917431807LLU,3LLU},{11529215046068436993LLU,18446462598740836351LLU,18433233068669009919LLU,18444493321867100159LLU,18378617710415183871LLU,3LLU},{18429855572959461375LLU,281474976702975LLU,18446691297151414272LLU,9225623836467134463LLU,17365772393808658431LLU,3LLU},{18446182222172962555LLU,16139634358347628287LLU,18158513697826273278LLU,18446744073709551615LLU,18446709163678466175LLU,3LLU},{18446182227562725375LLU,18446744073709551615LLU,18158513697826275327LLU,9223370937343149055LLU,18446708891484913664LLU,3LLU},{17294096884368539647LLU,18412967076504142335LLU,936748706385903615LLU,9209860413338882044LLU,14338933447903166014LLU,3LLU},{1152850998323052423LLU,18446744056588533696LLU,18445899648512032737LLU,17582019956684356611LLU,4594234569397628911LLU,3LLU},{10394303533334233215LLU,18412685618706915327LLU,4611686005541502975LLU,18431016659385794556LLU,14932951201824440062LLU,3LLU},{18334997958191249535LLU,13835337348415461887LLU,18176475319509188607LLU,18304633363849281535LLU,17077453919279366079LLU,2LLU},{9209843609287786471LLU,4611686017419175932LLU,18446739950528360448LLU,9367480627845136335LLU,12969169549931314171LLU,1LLU},{17870250270022148095LLU,18446497783104929791LLU,18446739675930685951LLU,4610560118503769084LLU,15528409575995603064LLU,1LLU},{18446215277329776639LLU,14411518807585587151LLU,18158518095352692735LLU,18374685380176772159LLU,9070216406474131335LLU,2LLU}};

static uint_fast64_t D[21][6] = {{7474850585334775807LLU,18446744073709551567LLU,932512511154995199LLU,9223371196061191168LLU,18446744073705357312LLU,3LLU},{7474850585334775806LLU,18446744073709551567LLU,11986991878754705407LLU,18446743620966327978LLU,18446744073709551615LLU,3LLU},{10971893488374775809LLU,5571292791624958064LLU,18446744073709548372LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073701163071LLU,6770589698673180671LLU,9223371476325719381LLU,18446744073705357312LLU,3LLU},{18446744073709551615LLU,12875451282084593663LLU,17514231562554559659LLU,9223372877648360447LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,12875451282084593599LLU,6459752194954849451LLU,18446743426941147477LLU,18446744073709551615LLU,3LLU},{13463509987775695661LLU,7916685441425386357LLU,18446744073709550455LLU,9223372036854775807LLU,18446743799905386368LLU,3LLU},{15955126479091971283LLU,16024785555037705466LLU,18446744073709549464LLU,16982711355976974335LLU,18446744072640004095LLU,3LLU},{18446744073709551615LLU,18063914729352462335LLU,288230375883280043LLU,14054645920511818752LLU,18442275657921593343LLU,3LLU},{18446744072067358329LLU,574244016544022527LLU,18378922691009704446LLU,13615471030846092287LLU,18446708891484946431LLU,3LLU},{9205583480610619391LLU,18446744073709543919LLU,14771739979159650303LLU,9223371211966238479LLU,17365772393807033139LLU,3LLU},{9781593652189986815LLU,18446744073709158367LLU,4593952824106221567LLU,18446744006062783728LLU,18378617710412614860LLU,3LLU},{13463511085687237551LLU,17987348860475452405LLU,288230376151711335LLU,15518678638244396032LLU,18442275657380528127LLU,3LLU},{10971894591676080519LLU,17872500057165529584LLU,18446744073709551105LLU,14054645920511819775LLU,18442275657921593343LLU,3LLU},{18446673567394299777LLU,576460735131942911LLU,18432174238971461600LLU,17365846022700662783LLU,4598160260174180335LLU,3LLU},{18446455437411229311LLU,18410750340803592191LLU,18176475302597751295LLU,4594761304459117567LLU,14339440990694129214LLU,3LLU},{9223248650902175743LLU,576460752303423471LLU,18445618448617701344LLU,17365880158846713615LLU,4179332697487303651LLU,3LLU},{576363806301618151LLU,18446744072700952572LLU,18445895267896262655LLU,18446737473401847744LLU,13792835146420972009LLU,1LLU},{18320215840407943295LLU,18446741891866140639LLU,4324581529096093695LLU,18446496687888219391LLU,17266633639393664670LLU,2LLU},{18335279982823602591LLU,13871084774604380611LLU,18446744073457893345LLU,17455714661176441919LLU,9067821927557496831LLU,2LLU},{10506897928641677287LLU,18412687799542114300LLU,18446744073708761119LLU,10360805820672770044LLU,15526370821348917247LLU,1LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][6] = {{7474850585334775807LLU,18446744073709551567LLU,932512511154995199LLU,9223371196061191168LLU,18446744073705357312LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,6],[3,7],[4,6],[4,8],[5,9],[5,10],[6,7],[7,11],[8,9],[8,12],[9,13],[10,12],[10,13],[11,12],[11,13]]\n", fout);
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

