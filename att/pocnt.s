# pocnt.s
# count '1' in uint64_t of Binary-Format
.bss
    .lcomm buf,10

.data
    str:
	.ascii "test luhao!\n"

.text
    .globl _start

_start:
    mov $0x1111ffff1111ffff, %rax # number HEX
    mov $0, %edx   # count '1'
    mov $64, %ecx  # loop variable
    # 16 for int32
    # 32 for int64

_loop1:
    ror $1, %rax   # shift left 1
    jnc _loop2     # if CF=0, jump to loop2
    inc %edx       # else: count '1' += 1

_loop2:
    dec %ecx       # ecx -= 1
    jne _loop1     # if ecx!=0, go back to loop

    add $0x30, %edx
    mov $0, %rax
    mov %edx,buf(,%rax,1)
    mov $0xa, %edx
    inc %rax
    mov %edx,buf(,%rax,1)

    mov $1, %ebx   # fd: stdout
    mov $4, %rax   # sys_write
    mov $buf, %ecx # buf
    mov $2, %edx   # size
    int $0x80
    #mov $0, %ebx
    mov $1, %rax
    int $0x80