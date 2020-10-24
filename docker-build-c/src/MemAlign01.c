#include <stdio.h>
struct S {
    char a;
    int b;
};

int main(){
 struct S s;
 printf("%zu",sizeof(s));
 return 0;
}