void exit(){
    asm(
        "movl $42 , %ebx \n\t"
        "movl $1,%eax \n\t"
        "int $0x80 \n\t"
        );
}

void nomain(){
    exit();
}