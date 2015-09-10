#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_21_600_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 20;
static uint_fast32_t endhere = 0;
char str[31] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[21][6] = {{18446744065119617025LLU,67108863LLU,18446744073642442752LLU,1125899906842623LLU,18446744073709289472LLU,4194303LLU},{18446744073709551615LLU,8191LLU,18446744073642442752LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,67108863LLU,18445618173802708992LLU,18446744073709551615LLU,4194303LLU},{18446744065119617024LLU,18446744073709551615LLU,15996750691913695231LLU,525429085568861LLU,18446744073709289472LLU,4194303LLU},{8589934591LLU,18446744073642450944LLU,18446744073709551615LLU,18446744073709551615LLU,18445618173802971135LLU,4194303LLU},{0LLU,18446744073709543424LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{72057594037927935LLU,17867890234214055935LLU,66551679LLU,12608953056730546112LLU,18375807998711803643LLU,4194303LLU},{18446739692842909695LLU,9187334407235567615LLU,18446744073701160951LLU,18134869799514144831LLU,13907115649253178286LLU,4194303LLU},{18410715283921284859LLU,16131328715726536703LLU,18446744073707322879LLU,18446744073692774655LLU,4539628407209852927LLU,4194296LLU},{36028792651578287LLU,18302593555166650368LLU,18446726481758379997LLU,18446744073709551615LLU,18444492291075735551LLU,4194055LLU},{18442240474082050049LLU,18158513697607908351LLU,18446744073709551615LLU,1073123348709372LLU,17275808170593222652LLU,4190397LLU},{18446462590143037439LLU,288230376147451839LLU,18230571291528658944LLU,18446743867551121407LLU,8930638061075431427LLU,4132847LLU},{36033195065475071LLU,18446744073708535807LLU,17592186044415LLU,18446744073692774592LLU,4541875826223742975LLU,4194296LLU},{18446739692842909695LLU,18446744073644531712LLU,18446726481791942655LLU,18445618173819486207LLU,13978051741430841343LLU,4194055LLU},{18302610743188520449LLU,18446739675704982143LLU,18445898824145437695LLU,18159582697737942015LLU,16717221044808565759LLU,3996831LLU},{16134708580646388223LLU,4398046117883LLU,14123288428212649980LLU,288230375345618940LLU,18419713127948484544LLU,3404796LLU},{17870210753605263871LLU,287108874253625279LLU,18433220080687905792LLU,14122232694112731135LLU,15852107600381344771LLU,2871151LLU},{9196068818118508513LLU,18446744056596201455LLU,18230571239989052415LLU,18429855562209427395LLU,9182802248220804095LLU,1982459LLU},{17365743823270962815LLU,18445684419378249727LLU,18428747267385867327LLU,14771806777775161599LLU,13832805996763794687LLU,3005951LLU},{1117033187378200575LLU,18446744073708568545LLU,18014330058440703LLU,18446744056580079552LLU,9155747932467888127LLU,1538040LLU},{17365744098576695295LLU,18446744073646628895LLU,18428782520477679615LLU,18445618190982512895LLU,14122232641503625215LLU,3005711LLU}};

static uint_fast64_t D[21][6] = {{59958585265750015LLU,18446744073709548865LLU,3674990072760893439LLU,18446518880034619635LLU,18445618173802971135LLU,4194303LLU},{59958585265750014LLU,18446744073709548865LLU,11072832691597475839LLU,18446068538329967193LLU,18446744073709551615LLU,4194303LLU},{18386785488443801601LLU,11068046444198898366LLU,18446744073669286297LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073642450943LLU,8598908073077112831LLU,18446593944592930295LLU,18445618173802971135LLU,4194303LLU},{18446744073709551615LLU,7378697629510664191LLU,14771754000988923494LLU,225193674931980LLU,18446744073709289472LLU,4194303LLU},{18446744073709551615LLU,7378697629510655999LLU,7373911382152341094LLU,18446293709182293414LLU,18446744073709551615LLU,4194303LLU},{18446739680710044883LLU,2242214215951559358LLU,18446744073694736883LLU,18135995699420987391LLU,13907115649253178286LLU,4194303LLU},{12099020905042733LLU,17434312795987410943LLU,18446744073675153181LLU,12608953056730546175LLU,18375807998711803643LLU,4194303LLU},{18446744069342165935LLU,17651664456498806783LLU,18446726481539714892LLU,11986555601921507327LLU,18445618173802554969LLU,4194055LLU},{18446744072350314235LLU,5714211370262593535LLU,14771754001205359863LLU,6460413665446199308LLU,4539628424389351846LLU,4194296LLU},{7412420980829585407LLU,18446744073705289613LLU,18162792738309799935LLU,18446532696679922931LLU,8929962521131745279LLU,4132847LLU},{11089496603541635071LLU,18446744073692510579LLU,3742768626046861311LLU,18446677274347684860LLU,17275357810630590463LLU,4190397LLU},{18446744067158473095LLU,4341403796218309310LLU,18446744073646621632LLU,17513598244611948543LLU,13979173243357819660LLU,4194055LLU},{18422814300603778681LLU,14105340277492318207LLU,14771754001212914751LLU,933371022772535244LLU,4541880224203082995LLU,4194296LLU},{14409335125951250431LLU,288230376151513081LLU,13839548456743469052LLU,18446532966469353471LLU,9209284128014598083LLU,3371006LLU},{8998164704631193599LLU,18446744073696968207LLU,18445687460214866943LLU,18446739679945421043LLU,17581804395280974847LLU,3973071LLU},{4433775485045964769LLU,18446744056596004711LLU,4610840704439025663LLU,18429854734351332288LLU,18392504018209341439LLU,2029305LLU},{15275538100076405247LLU,18445622571798880763LLU,17565147950756134911LLU,14122166928767389695LLU,14987125579947966463LLU,2881855LLU},{18446743809567391719LLU,4341470024676933600LLU,18446744005195595772LLU,18433233257664348159LLU,18302562914931900364LLU,1538039LLU},{18446744073174769695LLU,18445618190919658175LLU,18446744073709289475LLU,13852171747610066943LLU,14123288431433859135LLU,3005711LLU},{18422818692633993185LLU,1125882793099263LLU,14771806777708380156LLU,4594797519824748492LLU,9155818042443972544LLU,1538040LLU}};

uint_fast8_t X[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[21][6] = {{59958585265750015LLU,18446744073709548865LLU,3674990072760893439LLU,18446518880034619635LLU,18445618173802971135LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,4194303LLU}};

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
    fputs("[[0,1],[0,2],[0,3],[1,2],[1,4],[2,5],[3,6],[3,7],[4,6],[4,7],[5,8],[5,9],[6,10],[7,11],[8,12],[8,13],[9,12],[9,13],[10,11],[10,12],[11,13]]\n", fout);
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

