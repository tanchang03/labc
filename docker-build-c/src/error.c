#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

extern int errno;

int main(){
    // char buf[10];
    // read(10,buf,10);

    for (int i=0;i<100;i++){
        printf("error no(%d) is :%s\n",i,strerror(i));
    }

    
}