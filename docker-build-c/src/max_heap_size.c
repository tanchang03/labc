#include <stdio.h>
#include <stdlib.h>

long long maximum = 0;
int main(int argc,char *argv[]){

   unsigned blocksize[] = {1024*1024,1024,1};
    unsigned i,count;
    for (i=0; i<3; i++) {
        for (count=1; ; count++){
            long long x = maximum + (long long)blocksize[i] * (long long)count;
            void *block = malloc(x);
            if(block) {
                // unsigned x1 = maximum + blocksize[i] * count;
                printf("(%lld = %lld + %d * %d ) maximum mallock size =%lld bytes (%X)\n",x,maximum,blocksize[i],count,x,block);
                maximum = x;
                free(block);
            } else {
                break;
            }
        }
    }
    printf("maximum mallock size =%u bytes \n", maximum);


    // long long x = 1658847232 + (long long)1048576 * (long long)1585613;
    // printf("%lld",x);
}