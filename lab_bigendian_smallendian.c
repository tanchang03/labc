#include <stdio.h>

/**
 * big endian or small endian
 * 判断是否小端法还是大端法
 * 
 **/
int main(int argc,char* argv[]){
    // union 联合 元素中占用内存起始地址相同
    union w {
        unsigned int a;
        unsigned char b;
    } c;

    c.a = 0x00ff;
    if(c.b == 1){
        printf("small endian \n");
    }else if(c.b == 0){
        printf("big endian \n");
    }else {
        printf("error \n");
    }

    printf("OK");
}