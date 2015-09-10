#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_719_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][6] = {{134217727LLU,18446726481523638272LLU,18446744073709551615LLU,18446744073709551615LLU,274877906943LLU,1152921504606846972LLU},{18446744073709551615LLU,131071LLU,18446744056529682432LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,17179869183LLU,0LLU,18446744073709550592LLU,1152921504606846975LLU},{18446744073575333888LLU,18446744073709551615LLU,8637200363495096319LLU,17678737228922052437LLU,18446743798831645173LLU,1152921504606846975LLU},{0LLU,18446744073709420544LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073575333889LLU,17592186044415LLU,18446744056529682432LLU,18446744073709551615LLU,18446743798831645695LLU,1152921504606846975LLU},{17906162584843714559LLU,17293822569102639103LLU,16642994415LLU,18446744073705357312LLU,18378838200962252799LLU,1152921504606781441LLU},{18437736870428278783LLU,18446216308128218047LLU,18446744071553679355LLU,4194303LLU,12679880554676469760LLU,1152921503533170687LLU},{18428729675325792063LLU,18014398507334762495LLU,18446744073575309247LLU,18446744069431360767LLU,18442240748960088015LLU,1152921230517006335LLU},{18014398440799219LLU,18443348783950331904LLU,18446726541649903614LLU,14987979559888814079LLU,4503599627370495LLU,1152851410673449952LLU},{14987413311400689665LLU,13180961013759LLU,18446532967477018496LLU,18159428491232149503LLU,18446744073692775423LLU,1151829947195457503LLU},{18444492247991861247LLU,18446741667989417959LLU,3746994872792383615LLU,18446744022169944000LLU,18446743798848421887LLU,1136028467296989431LLU},{18338657682585550787LLU,17222327375262383743LLU,17293822572860734703LLU,18429643438082228223LLU,16127390093223279871LLU,1098620748479593987LLU},{8790876393580789759LLU,18446741874678360063LLU,1152921504556512255LLU,4611672824032002048LLU,9024831014412746700LLU,929993306945815037LLU},{18446691296345612287LLU,18437631321271435263LLU,3742772763165200283LLU,18446462598733889532LLU,18446602436683461631LLU,843298848754434047LLU},{566609056177847807LLU,11528792768910457788LLU,18392699847388954623LLU,281474976498687LLU,12174906548014271488LLU,503976821566472191LLU},{18320643833898925903LLU,18090959151252373119LLU,17293840161288732159LLU,18433232446167186687LLU,16122921850324811775LLU,1098666945147432479LLU},{18446691296344670199LLU,18444404381617881091LLU,18443349881312018431LLU,14987698089207267324LLU,576319188570732543LLU,843233059452485604LLU},{15852667973920604223LLU,72057585424924671LLU,18446532967426683776LLU,18176528095861801023LLU,18410688879603613692LLU,935903717691953119LLU},{4611685998966341119LLU,11528792644623794156LLU,18446743231896485887LLU,288230324612091843LLU,18014396037727767552LLU,490884659647345663LLU},{18356742430453071839LLU,18392419366830342140LLU,17298325326983577087LLU,18433233271606214607LLU,18145281916897516547LLU,531281610406622847LLU}};

static uint_fast64_t D[21][6] = {{18446744073709551615LLU,5664437615697330175LLU,3732428501315543243LLU,17294733806528302848LLU,18446743798831644912LLU,1152921504606846975LLU},{8095896865125433342LLU,18446744073709474618LLU,7393057533092429823LLU,11913825960079284821LLU,18446744073709551013LLU,1152921504606846975LLU},{10350847208584118273LLU,12782306458012429509LLU,18446744063602007860LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446726481523638271LLU,15958458412904218623LLU,6916921536024016383LLU,274877906783LLU,1152921504606846972LLU},{18446744073709551615LLU,5664437615697199103LLU,11053686550724665547LLU,6532918113630266794LLU,18446744073709551194LLU,1152921504606846975LLU},{8095896865125433343LLU,18446744073709474618LLU,14714315582501552127LLU,1152010267181248767LLU,274877906703LLU,1152921504606846972LLU},{10362183504536032701LLU,13690391533721467277LLU,18446744070339108793LLU,18446744073709551615LLU,12679880554676470783LLU,1152921503533170687LLU},{17885819085610527299LLU,16385209727812267767LLU,18446744064279703654LLU,18446744073709551615LLU,18378838200962252799LLU,1152921504606781441LLU},{18446744073640868851LLU,5760455767127752703LLU,18446726485277734638LLU,13903523287133851632LLU,18446743897995715839LLU,1152851410673449955LLU},{18446744073701056319LLU,17915002658331033599LLU,3732428557553469851LLU,18379190075005074447LLU,18446743974545480640LLU,1152921230517006335LLU},{9003654396772351999LLU,18446741667989350370LLU,68675771148795903LLU,1152908242771247040LLU,8185918769495801615LLU,1136028467296989429LLU},{14077403954170298367LLU,18446739662484511551LLU,18392423595092475903LLU,18158530464102543615LLU,10260825579091656703LLU,1151829947195457502LLU},{2305842459577111999LLU,13690939405454533103LLU,18446744073512148921LLU,4611672824036196351LLU,4467535907970351052LLU,929993306490208255LLU},{17279712536281546689LLU,18374698809105038877LLU,18446744057601212415LLU,18429643438082228223LLU,14985727553379893503LLU,1098620747861590015LLU},{16956547975870683LLU,9762678025237823484LLU,18392699837959110654LLU,18446744073709339647LLU,17873933665649819647LLU,503976822631797595LLU},{18444426019729837927LLU,18142739484628119287LLU,3742772765321068551LLU,18446744073706405884LLU,18446532965333696511LLU,843298848762719397LLU},{2305843009205563903LLU,2305628441237512687LLU,18446744073642571768LLU,72041049823645680LLU,4467570814107510780LLU,929969683314490367LLU},{18445686223235185695LLU,9241104959964971007LLU,18378978972009495039LLU,18379190079298977807LLU,18445890792455200704LLU,503980853173405535LLU},{18357745201993023487LLU,18446743006879940096LLU,17362498324143161343LLU,14987978461451124735LLU,14110760114373786687LLU,1088729678709260023LLU},{18122414668696768359LLU,18142737354836549247LLU,18442244872128692103LLU,18446479365274598655LLU,16100104235290427391LLU,846008166742060940LLU},{15852670275490137079LLU,9221033367028236799LLU,18446730879569622912LLU,18230290915925180412LLU,4575639078242875391LLU,717707855668396012LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][6] = {{18446744073709551615LLU,5664437615697330175LLU,3732428501315543243LLU,17294733806528302848LLU,18446743798831644912LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,6],[3,7],[4,8],[4,9],[5,10],[5,11],[6,8],[6,10],[7,9],[7,11],[8,12],[9,13],[10,13],[11,12],[12,13]]\n", fout);
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
