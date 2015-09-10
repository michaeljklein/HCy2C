#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_966_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][7] = {{0LLU,18446743936270598144LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,137438953471LLU,0LLU,18446744073709550592LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1023LLU,18446726481523507200LLU,18446744073709551615LLU,67108863LLU},{17873555167345803136LLU,18446743996253339367LLU,18379190041718030335LLU,423320360465728487LLU,10967198856188LLU,18446744073709551104LLU,67108863LLU},{576449653906604031LLU,18444492409187320828LLU,18445897586851180303LLU,18374156446351752863LLU,18446735140030775295LLU,18446744004990075391LLU,67108863LLU},{18446317460239925375LLU,9225623814604996607LLU,1801336483432579066LLU,18446744073709551615LLU,18446743695164685827LLU,13835058124001640447LLU,67108863LLU},{18442240474082181120LLU,18014398509481983999LLU,18446515375290974192LLU,9223336989921443839LLU,14050384213442559975LLU,4575793560749604607LLU,67108832LLU},{4503599627370495LLU,18446461636660166656LLU,14951950486983397375LLU,18446744065094451199LLU,18437684091454211071LLU,18446726054174196153LLU,67104799LLU},{16682141952149123576LLU,18446743996249275605LLU,18446744073709551615LLU,14254432517586125823LLU,18158524059166272407LLU,18226067691968258047LLU,67046653LLU},{17906215361399684999LLU,9223372036854775791LLU,18379190041684475904LLU,4611685740055658471LLU,288230357964158972LLU,9223358839491919360LLU,66125751LLU},{18329650483330809856LLU,17149707379956514559LLU,18446515238925516796LLU,18419720414360436735LLU,17364822303568822271LLU,3672777855097372390LLU,63696894LLU},{9795329189597937663LLU,18149490005628646303LLU,4611686018427387859LLU,9223268682258300860LLU,14969965161369059303LLU,18412965427119456255LLU,54444001LLU},{17266800947716159481LLU,18446744073697230847LLU,33554431LLU,14984601860168451072LLU,18158531289743884223LLU,18226067691968258047LLU,67046653LLU},{9106267348079230975LLU,17147473170244554748LLU,18446021024219459389LLU,18428303546261110783LLU,17869579633964351487LLU,4033536347561000943LLU,63696894LLU},{18443366373988532223LLU,18446629655646568447LLU,18446742871093411839LLU,17870283321406128135LLU,15311535045617909759LLU,13835058054749314671LLU,49246189LLU},{18446743248538959087LLU,18379190079265340423LLU,18444487875849353727LLU,576460752303423487LLU,9221067460482957312LLU,18446462667451790330LLU,29163295LLU},{18444210798918747135LLU,9295315281683415039LLU,8790998907509637119LLU,17870283390125603967LLU,18230570913050902019LLU,9223653511319781119LLU,49246189LLU},{18444210798918747135LLU,9799761733219255295LLU,15852670687538839551LLU,17870318497163115775LLU,18302628812585684511LLU,13871068838797185023LLU,49242367LLU},{17906312118424752031LLU,9799761733223448559LLU,18104470501995841535LLU,17874786643987398127LLU,18302628884794824316LLU,14123279358046977537LLU,48493503LLU},{11092366981724819359LLU,11240970789656163247LLU,18446744073676259283LLU,8682843049246457855LLU,14987979559887165165LLU,14960956587383930399LLU,41351143LLU},{12371423337136510907LLU,11240970797160855551LLU,4503599594078163LLU,18012129117480131584LLU,14704252783364669439LLU,15974267878270393887LLU,41891309LLU}};

static uint_fast64_t D[21][7] = {{18446744073709551615LLU,6200637413287526399LLU,8189464719130980719LLU,10007807501637714950LLU,18446733712103488826LLU,18446744073709551615LLU,67108863LLU},{15340067568156174542LLU,18446743994885756932LLU,18446744073709551615LLU,8438936572071836671LLU,18446736843129569989LLU,18446744073709551615LLU,67108863LLU},{3106676505553377073LLU,12246106739245819899LLU,10257279354578570896LLU,18446744073709551609LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446737475627909119LLU,9223372167314277375LLU,2305807961475252223LLU,18374156515067035391LLU,18446743661329235967LLU,16668292922493805567LLU,67108863LLU},{18446216031102812160LLU,18446744047875522279LLU,17874716536182358010LLU,423320360469921791LLU,7558902618039254528LLU,15613509248397344466LLU,67108863LLU},{3368774761611263LLU,18446744004855857148LLU,18445899614344179471LLU,18446744004990075783LLU,10887843523025826815LLU,18446744031810116909LLU,67108863LLU},{18446744073709551615LLU,15541428770773663743LLU,14066707149699924335LLU,16925336625152251087LLU,18437675156408090942LLU,18446726054174196153LLU,67104799LLU},{18446744073709551615LLU,8673324852385415167LLU,9074479357995876336LLU,2305807857791807286LLU,14050382786882617315LLU,4575793560749604607LLU,67108832LLU},{18446711088357572607LLU,130459631615LLU,18446744073675997184LLU,18374686476181962751LLU,18446744072638431231LLU,7484402859086691327LLU,66125751LLU},{16714828533473341951LLU,18446744073705357789LLU,2305807961475252223LLU,18442267936061128447LLU,18446743038622379927LLU,18186572521157740543LLU,67046653LLU},{9799832789158199295LLU,16127372810866619295LLU,573922667138121167LLU,18084098750055161500LLU,18419713542264455679LLU,18446742012108472767LLU,54441439LLU},{18329650483397918719LLU,16698854836010221311LLU,18104470364623733631LLU,17260889981794383343LLU,18302364865638956862LLU,17509933763532947424LLU,63695423LLU},{15924693578371231439LLU,18446744065354390318LLU,18446744073709551615LLU,9097048317126574079LLU,18446744072636061421LLU,7484402859086691327LLU,66125751LLU},{18446216031102828543LLU,16127390239842860935LLU,2247401763241467LLU,141845796074004476LLU,8036638350668464128LLU,15974265747979370395LLU,54441439LLU},{18446510012178103397LLU,18375528408637127683LLU,10255745003621685498LLU,18446744073709551613LLU,9221085052669001727LLU,18446462667451790330LLU,29163295LLU},{3103532042193213371LLU,12249653991811049471LLU,18446021024190099349LLU,18446744073709550595LLU,15311535045617909759LLU,13835058054749314671LLU,49246189LLU},{4405751630004197LLU,18445334224924834816LLU,17244564170949511183LLU,18446744073709551613LLU,4581220747963134975LLU,18446744031830733240LLU,29163295LLU},{18446646225712185317LLU,9176643892185923583LLU,18428764821991192576LLU,2305842973444419508LLU,265977342926323711LLU,9223226865883545598LLU,29163506LLU},{16717360717291847165LLU,18400015929040698845LLU,4607182556238970879LLU,16140893316274171836LLU,18424490095793684471LLU,18438651066799159295LLU,29335544LLU},{18437736874391895549LLU,18390589815854988541LLU,18442240474115734399LLU,14986571021069314047LLU,18442240475155922879LLU,18373296632549603326LLU,31444606LLU},{18374685860458659055LLU,18390589815016840316LLU,18446744073709550463LLU,18428303546261110783LLU,18446726481525604351LLU,8644943090554500094LLU,31063870LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][7] = {{18446744073709551615LLU,6200637413287526399LLU,8189464719130980719LLU,10007807501637714950LLU,18446733712103488826LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU}};

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
    fputs("[[0,2],[0,5],[0,7],[1,3],[1,6],[1,8],[2,4],[2,9],[3,5],[3,10],[4,6],[4,11],[5,12],[6,13],[7,8],[7,13],[8,9],[9,10],[10,11],[11,12],[12,13]]\n", fout);
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

