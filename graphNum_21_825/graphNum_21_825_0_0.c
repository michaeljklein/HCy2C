#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_825_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][7] = {{18446744073709518849LLU,18446744073709452543LLU,4539628424389459975LLU,18446744060824649724LLU,18446742974332108799LLU,18446673707112857599LLU,1023LLU},{18446744073709551615LLU,268435455LLU,18374686479671623680LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU,0LLU,18446744073441116160LLU,18446744073709551615LLU,1023LLU},{18446739675663040512LLU,18446744073709551615LLU,18446181020609806095LLU,6917466767794231287LLU,18428729675466276735LLU,18446744073709551615LLU,1023LLU},{4398046511103LLU,18446741874954731520LLU,16248974261409021951LLU,18446744072098938879LLU,18014398475919359LLU,18446744073709486080LLU,1023LLU},{14987847618493677567LLU,132120575LLU,18446744073709551608LLU,18184970111949962591LLU,3440750115302145991LLU,18446744071562093163LLU,1023LLU},{0LLU,18446744073441116160LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{17905467143739146239LLU,13835058055240220671LLU,69805778116116478LLU,18446739675663040512LLU,9684990971279835135LLU,18428780681694781439LLU,1023LLU},{18446744047938764799LLU,18014332538783530887LLU,18437701690082721279LLU,4398046511103LLU,18445882537361276928LLU,13853072451441849283LLU,1023LLU},{14987843220447199231LLU,2198886940671LLU,18446181020609806088LLU,18230518515036848127LLU,18428730774711697359LLU,18446744071562133503LLU,1023LLU},{3844247900159LLU,18392278631893172220LLU,17974846877207625727LLU,18446744071831551759LLU,18014398462550015LLU,4608079619697410044LLU,1020LLU},{18446742905478380001LLU,17293820404170752003LLU,16717350959117697275LLU,18428800043944247295LLU,18446744073709547775LLU,17528003120443817987LLU,963LLU},{18446743867517566721LLU,9509895352472270591LLU,4611686017890516999LLU,18446743863256151039LLU,18442763833161248831LLU,17577267323041996799LLU,939LLU},{18428870412149424383LLU,18428580137860529647LLU,18374686480208494591LLU,288230367549194236LLU,17906308828480143356LLU,4394247148674220023LLU,895LLU},{18329369008421208059LLU,18446743867509162109LLU,15762320327799807LLU,18445688542546821120LLU,16393102634250140924LLU,18445632686497177149LLU,755LLU},{18013817417319313407LLU,13826121224771600383LLU,18446532954573766622LLU,14915899975618592767LLU,11450278749446143983LLU,13818168387895820287LLU,510LLU},{18446740766450317823LLU,18298112091665194983LLU,17284778003632488441LLU,266287386622LLU,18437381079364009980LLU,18176521497848085235LLU,855LLU},{576460732966895423LLU,18158460895229378460LLU,8935141660168289791LLU,18446744072384151359LLU,9222795886050934787LLU,14123288016798873548LLU,956LLU},{16068733519563587579LLU,9006993096295423LLU,18446744002842326840LLU,18301749276330622979LLU,17275948898954772447LLU,18445688540416179839LLU,755LLU},{18013817967090793447LLU,18438297899994464255LLU,16717360158940794847LLU,18429833585142792191LLU,11457051898914272255LLU,17820738133444919807LLU,463LLU},{4594797519824193343LLU,18446700064253411244LLU,9151316641305329151LLU,288230375937802237LLU,18014386476862672892LLU,936686735377039316LLU,1020LLU}};

static uint_fast64_t D[21][7] = {{14051091686468157439LLU,18446744073504283607LLU,16285016252571713535LLU,18162116743957527567LLU,3440750115264126915LLU,18446744071562093163LLU,1023LLU},{12707180614070108158LLU,18446744073598638853LLU,13979173243358019583LLU,6315812884465161895LLU,18446744073602176377LLU,18446744073709551615LLU,1023LLU},{5739563459639443457LLU,5634702423615104250LLU,18404349962608350731LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446741874954731519LLU,16156647435455523327LLU,18111716247310663007LLU,18014398450223862LLU,18446744073709486080LLU,1023LLU},{18446744073709551615LLU,12812041650473795583LLU,4601728714306486020LLU,936681708117345264LLU,18428729675330912015LLU,18446744073709551615LLU,1023LLU},{13643936546095595520LLU,18446744073667492909LLU,2305843009213693951LLU,6338666239572695028LLU,18446742974262752637LLU,18446673707112857599LLU,1023LLU},{18446744073709551615LLU,12812041650205360127LLU,4509964941452732916LLU,12130931189244389720LLU,18446744073548491398LLU,18446744073709551615LLU,1023LLU},{5757806944831156533LLU,16789350902750379906LLU,18432607411979148459LLU,18446744073709551615LLU,18445882537629712383LLU,13853072451441849283LLU,1023LLU},{17887223632776646347LLU,2247998041178924287LLU,18407192424790112094LLU,18446744073709551615LLU,9684990971279835135LLU,18428780681694781439LLU,1023LLU},{13643936546095628287LLU,18446744073667492909LLU,15746370959665663LLU,17578464122176012284LLU,15024008356656251132LLU,18446673707112832404LLU,1023LLU},{18446742905478380001LLU,16279927712758366207LLU,13826013489811881985LLU,18428733029569512446LLU,18435654845705711679LLU,17528003120443883519LLU,963LLU},{18446743519910940671LLU,13771471098824622079LLU,9218938799410905086LLU,936748722224692993LLU,18439818903321378767LLU,4608079619697410047LLU,1020LLU},{18428731314934251519LLU,18428580137658998759LLU,17149707381026848767LLU,18011099421425615LLU,17888295520845422588LLU,4394316965957958387LLU,895LLU},{14051230577491378175LLU,9509895352468632543LLU,17582052945254416383LLU,18432335814516797503LLU,3454784281727987715LLU,17577267870207493999LLU,939LLU},{8068172343886767031LLU,18437738788799250431LLU,18445916107001814991LLU,14915904373665038335LLU,18446604227425927151LLU,11997589407298286591LLU,510LLU},{16127353882945764729LLU,16789419150991671296LLU,18379180801762783419LLU,18445688542546886655LLU,18157668722620235004LLU,15690503436841778689LLU,755LLU},{18014257803153183LLU,11491778225613272828LLU,8895590027891900415LLU,18446744072384151359LLU,574208944436674559LLU,18439548354185650172LLU,956LLU},{18445666826451941611LLU,9198460263676694015LLU,17293820370616268632LLU,18446739941950427134LLU,18325076454896828415LLU,18435969390714240767LLU,855LLU},{4463630180677575607LLU,18446743789166935983LLU,18446463139866201599LLU,14119910714588004351LLU,15924728074075112447LLU,11997574896767988182LLU,510LLU},{16127355047149805439LLU,17879246520868405244LLU,9151595846423019455LLU,4467570830351531777LLU,18157516701700194268LLU,6773149681644470269LLU,765LLU},{18086363778651193323LLU,568014647308829695LLU,16717361816799229784LLU,18432331692471681279LLU,12665142498956410879LLU,18432388830825680511LLU,963LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][7] = {{14051091686468157439LLU,18446744073504283607LLU,16285016252571713535LLU,18162116743957527567LLU,3440750115264126915LLU,18446744071562093163LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,4],[1,5],[2,4],[2,6],[3,7],[3,8],[4,9],[5,10],[5,11],[6,10],[6,12],[7,9],[7,11],[8,10],[8,12],[9,13],[11,13],[12,13]]\n", fout);
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
