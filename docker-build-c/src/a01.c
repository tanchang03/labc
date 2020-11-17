#include <stdio.h>
#include <stdlib.h>

int a = 3;


int cr0 = 100;


// static __inline__ void __set_bit(int nr, volatile void * addr)
// {
//     __asm__ __volatile__ ("movl %0,%%cr0"::"a"(cr0));
//     __asm__ ("btsl %1,%0":"=m" (addr):"Ir" (nr));
// }

// __asm__ __volatile__ ("nop \n\t");

void foo(void){
    char* x = getenv("ENV");
    
    printf("byte2 %s!\n",x);

}

struct example_struct {
    char a;
    int b;
    long c;
} __attribute__((packed));

int main(int argc, char* argv[]){
    // atexit(&foo);
    // int * p = (int *) malloc(sizeof(int));
    // scanf("%d",p);
    // printf("%d",a + *p);
    // free(p);
    const char* x = __FUNCTION__;
    struct example_struct x1;
    x1.c = 100;
    x1.a = 'a';
    x1.b = 300;
    printf("example struct size of is :%ld\n",sizeof(x1));


    printf("Hello:%s\n",x);


}