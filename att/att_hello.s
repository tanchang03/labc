// hello.s
.data       
    msg:
	.ascii   "Hello world!\n"    
	len = . - msg           
.text
    .global _start
_start:
    movl    $len,%edx # size of buffer
    movl    $msg,%ecx # content of buffer
    movl    $1,%ebx   # fd 0:stdin 1:stdout
    movl    $4,%eax   # sys_write
    int    $0x80

    movl    $0,%ebx     
    movl    $1,%eax 
    int    $0x80

