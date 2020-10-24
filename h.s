.section .data

msg:
    .ascii "Hello, World!\n"

.section .text
.globl _start

_start:
    # write 的第 3个参数 count: 14
    movl $14,  %edx
    # write 的第 2 个参数 buffer: "Hello, World!\n"
    movl $msg, %ecx
    # write 的第 1 个参数 fd: 1
    movl $1,   %ebx
    #  write 系统调用本身的数字标识：4
    movl $4,   %eax
    #  执行系统调用: write(fd, buffer, count)
    int $0x80

    # status: 0
    movl $0,   %ebx
    # 函数: exit
    movl $1,   %eax
    # system call: exit(status)
    int $0x80