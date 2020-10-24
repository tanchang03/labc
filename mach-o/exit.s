# exit.s    
    .data 
    .quad 0x114514
    .section    __TEXT,__text
    .globl  _main
    .equ maxCount,0x114514

_main:
    movq    $maxCount, %rax
    retq