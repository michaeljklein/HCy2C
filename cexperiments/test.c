#include <stdio.h>
#include <x86intrin.h>


static unsigned long long int ONES = 18446744073709551615LLU;
unsigned long long int y;
unsigned int best = 1;
unsigned int i;
unsigned int this;
static int maxpos = 5;
static unsigned int endhere = 1;
unsigned int starthere = 0;
char str[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
FILE * fout;

static unsigned long long int C[6][1] = {{16368LLU},{16143LLU},{12543LLU},{11772LLU},{8147LLU},{12093LLU}};

static unsigned long long int D[6][1] = {{13935LLU},{14838LLU},{16281LLU},{6095LLU},{11391LLU},{5111LLU}};

unsigned int X[6] = {0,0,0,0,0,0};

unsigned long long int A[6][1] = {{13935LLU},{16383LLU},{16383LLU},{16383LLU},{16383LLU},{16383LLU}};

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
    if(y0 == 0){
    y = 0;
    } else {
    y = ONES;
    }
    A[i][0] = A[i-1][0] & (~y | C[i][0]) & (y | D[i][0]);
    }


void checkifbest(){
    this = 0;
    this += counter(A[maxpos][0]);


//    if(this == best){
//        sprintf(str, "[%d%d%d%d%d%d,%5d]\n", X[0],X[1],X[2],X[3],X[4],X[5],this );
//        fwrite(str, 1, sizeof(str), fout);
//    }
//
    if(this > best){
//        sprintf(str, "[%d%d%d%d%d%d,%5d]\n", X[0],X[1],X[2],X[3],X[4],X[5],this );
//        fwrite(str, 1, sizeof(str), fout);
        best = this;
    }

//    if(this < best){
//        ;
//    }
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
    unsigned long long c0 = __rdtsc();
//    fout = fopen("test_0_1_out.txt", "w");
//    fputs("[[0,1],[0,2],[0,3],[1,2],[1,3],[2,3]]\n", fout);
//    if(endhere > 0){
//        unsigned int bitpos = 0;
//        unsigned int thisbit;
//        while(starthere){
//            thisbit = starthere & 1;
//            X[bitpos] = thisbit;
//            f(bitpos, thisbit);
//            bitpos++;
//            starthere >>= 1;
//        }
//        i = endhere;
//        r();
//    }else{
        i = 1;
        r();
//    }
//    fwrite("FINISHED", 1, 9, fout);
//    fclose(fout);
    
    unsigned long long c1 =  __rdtsc();
    printf("%llu\n", c1-c0);
    return 0;
}

