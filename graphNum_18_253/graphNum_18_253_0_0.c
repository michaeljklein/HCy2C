#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_18_253_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 17;
static uint_fast32_t endhere = 0;
char str[28] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[18][8] = {{0LLU,18446603336221196288LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,140737488355327LLU,0LLU,18446744072635809792LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1073741823LLU,18158513697557839872LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18428729675200069632LLU,18446744073709551615LLU,18446744073709551615LLU,18446726483670990847LLU,279223176895004671LLU,18446744065119617024LLU,18446744073709551615LLU,281474976710655LLU},{18014398509481983LLU,18445899648242548736LLU,18374686479671619583LLU,18410732868876632031LLU,18446744073709551615LLU,8589934591LLU,18446744073709551614LLU,281474976710655LLU},{18446744073709551615LLU,16999821956465295359LLU,8502796095768190955LLU,18446744073704025789LLU,18446744073709551615LLU,18446744073709551615LLU,18446673704965373953LLU,281474976710655LLU},{18446744073709551615LLU,140737488355327LLU,18446743936270598144LLU,72057594037927935LLU,18446739946245980128LLU,18281236787403685887LLU,13835128391545634816LLU,281474976710655LLU},{13507843046416154589LLU,18446744073621460846LLU,18410715414129541119LLU,18446744073709551615LLU,16429131440647569407LLU,14699515172869835257LLU,4611686018427387903LLU,281474976694272LLU},{18374686478597881843LLU,18446744073709551583LLU,36028797018963967LLU,18446744072635809792LLU,2305843009213628447LLU,18433224444370485246LLU,18446744073676013567LLU,281474909618175LLU},{18014398241046528LLU,18446708857125208056LLU,18446744073709551615LLU,18446480055627415551LLU,243194379813126143LLU,18446741891865116672LLU,4611686018427387903LLU,281472878505980LLU},{18428729675468505087LLU,18304880685447380991LLU,14122690297108119551LLU,9079239394031827071LLU,18446171777907293119LLU,18446744065120665599LLU,18157456993868545787LLU,281408404439039LLU},{16158053411797859328LLU,18446628515441277959LLU,18446744073709551615LLU,18436834856160722943LLU,99061582020607999LLU,17293756339601801088LLU,4611686018427387903LLU,280993685523315LLU},{18446744073708504063LLU,144115188075855871LLU,4608097212457811966LLU,17582052919484483568LLU,18443257522337867388LLU,18446744073709547647LLU,17853387787643714023LLU,273228370477055LLU},{2305840844282789887LLU,18446743635622822904LLU,18446744073709549569LLU,14984389001589293055LLU,18446744072047034367LLU,18446249568119033855LLU,18320643284143177631LLU,219900714942412LLU},{16285016220359457807LLU,18446744000695106623LLU,18446743936270600191LLU,4611087604929003519LLU,18446744073432465376LLU,18444439291154136961LLU,4755801206503227519LLU,280993739046903LLU},{18446675903938282299LLU,11501911973325504511LLU,14915921962617073567LLU,18446744073684285907LLU,13835058055282163711LLU,18303191835318550255LLU,16389513837675544575LLU,209444075126783LLU},{18428800043943215103LLU,9114718847018991615LLU,18446730879570018302LLU,18415203457385365503LLU,18446743938418081791LLU,144115180022788607LLU,18432388848018259966LLU,134088878980671LLU},{18446682501058383871LLU,18446607734265872383LLU,18410732868876632063LLU,18446744073709551615LLU,17005592330389946367LLU,18320643284143177727LLU,18444281169810817023LLU,209444080173567LLU}};

static uint_fast64_t D[18][8] = {{18446744073709551615LLU,13022017585053433855LLU,11168927219398062260LLU,72057591937946470LLU,18347823404785991680LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{5591925731789014382LLU,18446603336980457907LLU,18446744073709551615LLU,18374686481819107327LLU,18257434366481399807LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{12854818341920537233LLU,5424867225385211468LLU,7277816854311489355LLU,18446744073662049433LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,16715250754473951231LLU,18164812695584359399LLU,10880696698913922956LLU,18354061484006255813LLU,12971490619120680959LLU,18446686018676034348LLU,281474976710655LLU},{18446744073709551615LLU,18007643110040928255LLU,3740696320381500921LLU,7638104967885743743LLU,14396273529108615994LLU,18446744073707872050LLU,18446731759998891219LLU,281474976710655LLU},{18446744073709551615LLU,13744986062734753791LLU,16140900778872012478LLU,18410715277680376823LLU,4323455642275676159LLU,5475253454590550221LLU,18446744073709551615LLU,281474976710655LLU},{9092995931870912496LLU,18446608505086922694LLU,18446744073709551615LLU,18417016352343588863LLU,98920809341255679LLU,14987825023671024638LLU,13835058055282163711LLU,281474923053657LLU},{17284809854941656447LLU,18446744072367209979LLU,18446744073709551615LLU,36028797018963967LLU,18446744073709486080LLU,18429855575106912255LLU,14004435622484246528LLU,281474963259391LLU},{11096649469990481871LLU,18446738906857337663LLU,18446744073709551615LLU,18440443000204034047LLU,18446739805828284415LLU,17996295805866069497LLU,9054064805882626047LLU,281474976710054LLU},{18446744073709551615LLU,18302769623122051071LLU,13852159789615548415LLU,4395513235770439695LLU,18373827954296715663LLU,12971490627710615551LLU,18157421221203091064LLU,281408404439039LLU},{18014398509481983LLU,16717326600214937592LLU,18435343203076930535LLU,15564176429131735036LLU,18390376510534954741LLU,18446741883276230655LLU,4611663736059325359LLU,281472878505980LLU},{18446744073709551615LLU,140737488355327LLU,18442513152965867520LLU,13907115649319960591LLU,18442517752875835903LLU,13590737775497314303LLU,18302690974482300800LLU,267138375090175LLU},{18446741874954731519LLU,18446673189569232903LLU,18428727406652030975LLU,18442519886931427327LLU,18230571289515360239LLU,18446183322513047551LLU,18446708889186459647LLU,228283918573507LLU},{18445882056593375231LLU,18446734178079211519LLU,35760516165011455LLU,4602674421126135792LLU,18446607708497903132LLU,16674577619265519615LLU,17582052429321222271LLU,278636003212159LLU},{9219958740432510975LLU,18446723990340751358LLU,18442513152965869567LLU,18426327156393902095LLU,18442381107382968831LLU,11448008963316988927LLU,18446735826294669311LLU,267138374956765LLU},{18446744073709551615LLU,18446739677810524159LLU,18446726911020235263LLU,18446744072770027519LLU,17870283183967240191LLU,18446744073708986298LLU,4611686016313458687LLU,105276980067840LLU},{18446744073659219771LLU,18446638520593285119LLU,18415218872039767937LLU,14987979559855587327LLU,10092566764937224163LLU,18446744073709354983LLU,17257732199403210655LLU,193375996203007LLU},{16631791747566140663LLU,9114722695441759449LLU,18446743940565563518LLU,18446744072669364223LLU,9223372036854775807LLU,9223045305651689374LLU,16059273321249767422LLU,105276971679743LLU}};

uint_fast8_t X[18] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[18][8] = {{18446744073709551615LLU,13022017585053433855LLU,11168927219398062260LLU,72057591937946470LLU,18347823404785991680LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,281474976710655LLU}};

#if UINTPTR_MAX == 0xffffffffffffffff // 64-bit. Hopefully this means the cpu has 'popcnt'.
int counter (uint64_t * buf){
    uint64_t cnt[18];
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
            "popcnt %2, %2  \n\t"
            "add %2, %0     \n\t"
            "popcnt %3, %3  \n\t"
            "add %3, %1     \n\t"
            : "+r" (cnt[16]), "+r" (cnt[17])
            : "r" (buf[16]), "r" (buf[17]));


    return cnt[0] + cnt[1] + cnt[2] + cnt[3] + cnt[4] + cnt[5] + cnt[6] + cnt[7] + cnt[8] + cnt[9] + cnt[10] + cnt[11] + cnt[12] + cnt[13] + cnt[14] + cnt[15] + cnt[16] + cnt[17];
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
        A[i][7] = A[i-1][7] & C[i][7];

    } else {
        A[i][0] = A[i-1][0] & D[i][0];
        A[i][1] = A[i-1][1] & D[i][1];
        A[i][2] = A[i-1][2] & D[i][2];
        A[i][3] = A[i-1][3] & D[i][3];
        A[i][4] = A[i-1][4] & D[i][4];
        A[i][5] = A[i-1][5] & D[i][5];
        A[i][6] = A[i-1][6] & D[i][6];
        A[i][7] = A[i-1][7] & D[i][7];

    }
}

void printout(){
    sprintf(str, "[                  ,%5d]\n", this);
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
    fputs("[[0,1],[0,2],[0,7],[1,3],[1,6],[1,7],[2,5],[2,7],[2,8],[3,4],[3,6],[4,5],[4,6],[4,8],[5,8],[6,7],[6,8],[7,8]]\n", fout);
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

