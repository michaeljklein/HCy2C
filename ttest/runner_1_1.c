#include <stdio.h>
static unsigned long long int ONES = 18446744073709551615LLU;
unsigned long long int y;
unsigned int best = 1;
unsigned int i;
unsigned int this;
static int maxpos = 14;
static unsigned int endhere = 2;
unsigned int starthere = 1;
char str[25] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
FILE * fout;

static unsigned long long int C[15][6] = {{0,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,0,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,0,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,0,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,0,1152921504606846975LLU},{18446744073709486080LLU,18446744073709551615LLU,16137488128863633345LLU,16137488128863633345LLU,16137488128863633345LLU,1152921504606814208LLU},{18446744069414649855LLU,16137488128863633345LLU,18446744073709551615LLU,18361175680251852863LLU,18361175680251852863LLU,1152921503533137919LLU},{18446462603027808255LLU,18361175680251852863LLU,18361175680251852863LLU,18446744073709551615LLU,18446742768019507199LLU,1152886321308499967LLU},{281474976710655LLU,18446742768019507199LLU,18446742768019507199LLU,18446742768019507199LLU,18446744073709551615LLU,35184372088831LLU},{16137488128863633345LLU,18446744069414649855LLU,18446744073709551615LLU,18012146709538267123LLU,18012146709538267123LLU,1008590805809496032LLU},{18361175680251852863LLU,18446462603027808255LLU,18012146709538267123LLU,18446744073709551615LLU,18446737438119296719LLU,1147573479914929183LLU},{18446742768019507199LLU,281474976710655LLU,18446737438119296719LLU,18446737438119296719LLU,18446744073709551615LLU,1152921341393077247LLU},{18012146709538267123LLU,18012146709538267123LLU,18446462603027808255LLU,18446744073709551615LLU,18446471394724674039LLU,1125759169321758713LLU},{18446737438119296719LLU,18446737438119296719LLU,281474976710655LLU,18446471394724674039LLU,18446744073709551615LLU,1152920674637971303LLU},{18446471394724674039LLU,18446471394724674039LLU,18446471394724674039LLU,281474976710655LLU,18446744073709551615LLU,1152887419721088251LLU}};

static unsigned long long int D[15][6] = {{18446744073709551615LLU,7745465120565624830LLU,7745465120565624830LLU,7745465120565624830LLU,7745465120565624830LLU,1152921504606846975LLU},{7745465120565624830LLU,18446744073709551615LLU,11500961565784304509LLU,11500961565784304509LLU,11500961565784304509LLU,1152921504606846975LLU},{11500961565784304509LLU,11500961565784304509LLU,18446744073709551615LLU,17647355133939130267LLU,17647355133939130267LLU,1152921504606846975LLU},{17647355133939130267LLU,17647355133939130267LLU,17647355133939130267LLU,18446744073709551615LLU,18446450400839595239LLU,1152921504606846975LLU},{18446450400839595239LLU,18446450400839595239LLU,18446450400839595239LLU,18446450400839595239LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709486080LLU,9115143259038023679LLU,9115143259038023679LLU,9115143259038023679LLU,484081364189020159LLU},{18446744073709551615LLU,9115143259038023679LLU,18446744073709486080LLU,14699748915276677119LLU,14699748915276677119LLU,718803473948194238LLU},{18446744073709551615LLU,14699748915276677119LLU,14699748915276677119LLU,18446744073709486080LLU,18429235449676431359LLU,1102959695836401613LLU},{18446744073709551615LLU,18429235449676431359LLU,18429235449676431359LLU,18429235449676431359LLU,18446744073709486080LLU,1152919979846924915LLU},{9115143259038023679LLU,18446744073709551615LLU,18446744069414649855LLU,4602670297957498495LLU,4602670297957498495LLU,569687554516877311LLU},{14699748915276677119LLU,18446744073709551615LLU,4602670297957498495LLU,18446744069414649855LLU,17888086476244110335LLU,918734290154422271LLU},{18429235449676431359LLU,18446744073709551615LLU,17888086476244110335LLU,17888086476244110335LLU,18446744069414649855LLU,1151823642028408831LLU},{4602670297957498495LLU,4602670297957498495LLU,18446744073709551615LLU,18446462603027808255LLU,576460749080051679LLU,287666361046384447LLU},{17888086476244110335LLU,17888086476244110335LLU,18446744073709551615LLU,576460749080051679LLU,18446462603027808255LLU,1117992202035783167LLU},{576460749080051679LLU,576460749080051679LLU,576460749080051679LLU,18446744073709551615LLU,281474976710655LLU,36028796213108719LLU}};

unsigned int X[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

unsigned long long int A[15][6] = {{18446744073709551615LLU,7745465120565624830LLU,7745465120565624830LLU,7745465120565624830LLU,7745465120565624830LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU}};

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

void f(int i, int y0){
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

void checkifbest(){
    this = 0;
    this += counter(A[maxpos][0]);
    this += counter(A[maxpos][1]);
    this += counter(A[maxpos][2]);
    this += counter(A[maxpos][3]);
    this += counter(A[maxpos][4]);
    this += counter(A[maxpos][5]);


    if(this == best){
        sprintf(str, "[%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d,%5d]\n", X[0],X[1],X[2],X[3],X[4],X[5],X[6],X[7],X[8],X[9],X[10],X[11],X[12],X[13],X[14],this );
        fwrite(str, 1, sizeof(str), fout);
    }

    if(this > best){
        sprintf(str, "[%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d,%5d]\n", X[0],X[1],X[2],X[3],X[4],X[5],X[6],X[7],X[8],X[9],X[10],X[11],X[12],X[13],X[14],this );
        fwrite(str, 1, sizeof(str), fout);
        best = this;
    }

    if(this < best){
        ;
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
        if(X[i]){
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
int main(int argc, const char * argv[]) {
    fout = fopen("runner_1_2_out.txt", "w");
    fputs("[[0,1],[0,2],[0,3],[0,4],[0,5],[1,2],[1,3],[1,4],[1,5],[2,3],[2,4],[2,5],[3,4],[3,5],[4,5]]\n", fout);
    if(endhere){
        unsigned int bitpos = 0;
        unsigned int thisbit;
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
        i = 1;
        r();
    }
    fwrite("FINISHED.", 1, 9, fout);
    fclose(fout);
    return 0;
}

