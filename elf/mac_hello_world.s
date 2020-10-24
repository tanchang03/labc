# Inter语法 需要使用nasm进行编译

SECTION .data

msg: db "hello xiaozi!", 0x0a
len: equ $-msg

SECTION .text
global _main

kernel:
    syscall
    ret

_main:
    mov rax,0x2000004
    mov rdi,1
    mov rsi,msg
    mov rdx,len
    call kernel

    mov rax,0x2000001
    mov rdi,0
    call kernel