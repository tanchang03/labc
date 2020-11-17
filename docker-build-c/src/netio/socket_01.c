#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#define SERVPORT 3333//定义端口号
#define BACKLOG 10//请求队列中允许的最大请求数
#define MAXDATASIZE 5//数据长度


/**
 * 
 * 

ubuntu上运行的结果
root@041a49a309c2:/app/netio# gcc -o socket_01_ubuntu ./socket_01.c
root@041a49a309c2:/app/netio# ls
socket_01  socket_01.c  socket_01_ubuntu
root@041a49a309c2:/app/netio# ./socket_01_ubuntu 
sizeof(int)=32
sizeof(int*)=64
__GNUC__ is defined
__x86_64__  is defined
__linux__ is defined
__LP64__ is defined
__amd64 is defined
hello world
创建socket 3
root@041a49a309c2:/app/netio# 


mac 上运行的结果：
sizeof(int)=32
sizeof(int*)=64
__GNUC__ is defined
__x86_64__  is defined
__LP64__ is defined
__amd64 is defined
hello world
创建socket 3


 * */
void test()
{
	int len=sizeof(int)*8;
	printf("sizeof(int)=%d\n",len);
 
	len=sizeof(int *)*8;
	printf("sizeof(int*)=%d\n",len);
 
#ifdef _MSC_VER
	printf("_MSC_VER is defined\n");
#endif
 
#ifdef __GNUC__
	printf("__GNUC__ is defined\n");
#endif
 
#ifdef __INTEL__ 
	printf("__INTEL__  is defined\n");
#endif
 
#ifdef __i386__ 
	printf("__i386__  is defined\n");
#endif
 
#ifdef __x86_64__ 
	printf("__x86_64__  is defined\n");
#endif
 
#ifdef _WIN32 
	printf("_WIN32 is defined\n");
#endif
 
#ifdef _WIN64 
	printf("_WIN64 is defined\n");
#endif
 
 
#ifdef __linux__ 
	printf("__linux__ is defined\n");
#endif
 
#ifdef __LP64__ 
	printf("__LP64__ is defined\n");
#endif
 
 
#ifdef __amd64 
	printf("__amd64 is defined\n");
#endif
}



int main(){

    test();

    printf("hello world\n");

    struct sockaddr_in server_sockaddr,client_sockaddr;

    int sin_size,recvbytes;
    int sockfd,client_fd;//socket描述符

    char buf[MAXDATASIZE];//传输的数据

    if((sockfd = socket(AF_INET,SOCK_STREAM,0)) == -1) {//建立socket链接
        perror("Socket");
        exit(1);
    }else
    {
        printf("创建socket %d\n",sockfd);
    }
    
    return 0;
}