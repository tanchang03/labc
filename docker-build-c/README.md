## 运行虚拟机
``` shell
$ docker build -t busybox .
$ docker run -it --rm busybox
```


## 编译
``` shell
$ gcc -c SimpleSection.c
```

## 观察目标文件段结构
``` shell
$ objdump -h SimpleSection.o

SimpleSection.o:     file format elf64-x86-64

Sections:
Idx Name          Size      VMA               LMA               File off  Algn
  0 .text         00000057  0000000000000000  0000000000000000  00000040  2**0
                  CONTENTS, ALLOC, LOAD, RELOC, READONLY, CODE
  1 .data         00000008  0000000000000000  0000000000000000  00000098  2**2
                  CONTENTS, ALLOC, LOAD, DATA
  2 .bss          00000004  0000000000000000  0000000000000000  000000a0  2**2
                  ALLOC
  3 .rodata       00000004  0000000000000000  0000000000000000  000000a0  2**0
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  4 .comment      0000001b  0000000000000000  0000000000000000  000000a4  2**0
                  CONTENTS, READONLY
  5 .note.GNU-stack 00000000  0000000000000000  0000000000000000  000000bf  2**0
                  CONTENTS, READONLY
  6 .eh_frame     00000058  0000000000000000  0000000000000000  000000c0  2**3
                  CONTENTS, ALLOC, LOAD, RELOC, READONLY, DATA
$ objdump -x -s -d SimpleSection.o

SimpleSection.o:     file format elf64-x86-64
SimpleSection.o
architecture: i386:x86-64, flags 0x00000011:
HAS_RELOC, HAS_SYMS
start address 0x0000000000000000

Sections:
Idx Name          Size      VMA               LMA               File off  Algn
  0 .text         00000057  0000000000000000  0000000000000000  00000040  2**0
                  CONTENTS, ALLOC, LOAD, RELOC, READONLY, CODE
  1 .data         00000008  0000000000000000  0000000000000000  00000098  2**2
                  CONTENTS, ALLOC, LOAD, DATA
  2 .bss          00000004  0000000000000000  0000000000000000  000000a0  2**2
                  ALLOC
  3 .rodata       00000004  0000000000000000  0000000000000000  000000a0  2**0
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  4 .comment      0000001b  0000000000000000  0000000000000000  000000a4  2**0
                  CONTENTS, READONLY
  5 .note.GNU-stack 00000000  0000000000000000  0000000000000000  000000bf  2**0
                  CONTENTS, READONLY
  6 .eh_frame     00000058  0000000000000000  0000000000000000  000000c0  2**3
                  CONTENTS, ALLOC, LOAD, RELOC, READONLY, DATA
SYMBOL TABLE:
0000000000000000 l    df *ABS*  0000000000000000 SimpleSection.c
0000000000000000 l    d  .text  0000000000000000 .text
0000000000000000 l    d  .data  0000000000000000 .data
0000000000000000 l    d  .bss   0000000000000000 .bss
0000000000000000 l    d  .rodata        0000000000000000 .rodata
0000000000000004 l     O .data  0000000000000004 static_var.1915
0000000000000000 l     O .bss   0000000000000004 static_var2.1916
0000000000000000 l    d  .note.GNU-stack        0000000000000000 .note.GNU-stack
0000000000000000 l    d  .eh_frame      0000000000000000 .eh_frame
0000000000000000 l    d  .comment       0000000000000000 .comment
0000000000000000 g     O .data  0000000000000004 global_int_var
0000000000000004       O *COM*  0000000000000004 global_uint_var
0000000000000000 g     F .text  0000000000000024 func1
0000000000000000         *UND*  0000000000000000 _GLOBAL_OFFSET_TABLE_
0000000000000000         *UND*  0000000000000000 printf
0000000000000024 g     F .text  0000000000000033 main


Contents of section .text:
 0000 554889e5 4883ec10 897dfc8b 45fc89c6  UH..H....}..E...
 0010 488d3d00 000000b8 00000000 e8000000  H.=.............
 0020 0090c9c3 554889e5 4883ec10 c745f801  ....UH..H....E..
 0030 0000008b 15000000 008b0500 00000001  ................
 0040 c28b45f8 01c28b45 fc01d089 c7e80000  ..E....E........
 0050 00008b45 f8c9c3                      ...E...         
Contents of section .data:
 0000 54000000 55000000                    T...U...        
Contents of section .rodata:
 0000 25640a00                             %d..            
Contents of section .comment:
 0000 00474343 3a202841 6c70696e 6520392e  .GCC: (Alpine 9.
 0010 332e3029 20392e33 2e3000             3.0) 9.3.0.     
Contents of section .eh_frame:
 0000 14000000 00000000 017a5200 01781001  .........zR..x..
 0010 1b0c0708 90010000 1c000000 1c000000  ................
 0020 00000000 24000000 00410e10 8602430d  ....$....A....C.
 0030 065f0c07 08000000 1c000000 3c000000  ._..........<...
 0040 00000000 33000000 00410e10 8602430d  ....3....A....C.
 0050 066e0c07 08000000                    .n......        

Disassembly of section .text:

0000000000000000 <func1>:
   0:   55                      push   %rbp
   1:   48 89 e5                mov    %rsp,%rbp
   4:   48 83 ec 10             sub    $0x10,%rsp
   8:   89 7d fc                mov    %edi,-0x4(%rbp)
   b:   8b 45 fc                mov    -0x4(%rbp),%eax
   e:   89 c6                   mov    %eax,%esi
  10:   48 8d 3d 00 00 00 00    lea    0x0(%rip),%rdi        # 17 <func1+0x17>
                        13: R_X86_64_PC32       .rodata-0x4
  17:   b8 00 00 00 00          mov    $0x0,%eax
  1c:   e8 00 00 00 00          callq  21 <func1+0x21>
                        1d: R_X86_64_PLT32      printf-0x4
  21:   90                      nop
  22:   c9                      leaveq 
  23:   c3                      retq   

0000000000000024 <main>:
  24:   55                      push   %rbp
  25:   48 89 e5                mov    %rsp,%rbp
  28:   48 83 ec 10             sub    $0x10,%rsp
  2c:   c7 45 f8 01 00 00 00    movl   $0x1,-0x8(%rbp)
  33:   8b 15 00 00 00 00       mov    0x0(%rip),%edx        # 39 <main+0x15>
                        35: R_X86_64_PC32       .data
  39:   8b 05 00 00 00 00       mov    0x0(%rip),%eax        # 3f <main+0x1b>
                        3b: R_X86_64_PC32       .bss-0x4
  3f:   01 c2                   add    %eax,%edx
  41:   8b 45 f8                mov    -0x8(%rbp),%eax
  44:   01 c2                   add    %eax,%edx
  46:   8b 45 fc                mov    -0x4(%rbp),%eax
  49:   01 d0                   add    %edx,%eax
  4b:   89 c7                   mov    %eax,%edi
  4d:   e8 00 00 00 00          callq  52 <main+0x2e>
                        4e: R_X86_64_PLT32      func1-0x4
  52:   8b 45 f8                mov    -0x8(%rbp),%eax
  55:   c9                      leaveq 
  56:   c3                      retq   
```

```
# mac 的 mac-o 文件结构
SimpleSection.o:        file format Mach-O 64-bit x86-64


Disassembly of section __TEXT,__text:

0000000000000000 _func1:
       0: 55                            pushq   %rbp
       1: 48 89 e5                      movq    %rsp, %rbp
       4: 48 83 ec 10                   subq    $16, %rsp
       8: 89 7d fc                      movl    %edi, -4(%rbp)
       b: 8b 75 fc                      movl    -4(%rbp), %esi
       e: 48 8d 3d 5b 00 00 00          leaq    91(%rip), %rdi
      15: b0 00                         movb    $0, %al
      17: e8 00 00 00 00                callq   0 <_func1+0x1c>
      1c: 48 83 c4 10                   addq    $16, %rsp
      20: 5d                            popq    %rbp
      21: c3                            retq
      22: 66 2e 0f 1f 84 00 00 00 00 00 nopw    %cs:(%rax,%rax)
      2c: 0f 1f 40 00                   nopl    (%rax)

0000000000000030 _main:
      30: 55                            pushq   %rbp
      31: 48 89 e5                      movq    %rsp, %rbp
      34: 48 83 ec 10                   subq    $16, %rsp
      38: c7 45 fc 00 00 00 00          movl    $0, -4(%rbp)
      3f: c7 45 f8 01 00 00 00          movl    $1, -8(%rbp)
      46: 8b 05 00 00 00 00             movl    (%rip), %eax
      4c: 03 05 00 00 00 00             addl    (%rip), %eax
      52: 03 45 f8                      addl    -8(%rbp), %eax
      55: 03 45 f4                      addl    -12(%rbp), %eax
      58: 89 c7                         movl    %eax, %edi
      5a: e8 00 00 00 00                callq   0 <_main+0x2f>
      5f: 8b 45 f8                      movl    -8(%rbp), %eax
      62: 48 83 c4 10                   addq    $16, %rsp
      66: 5d                            popq    %rbp
      67: c3                            retq
Contents of section __text:
 0000 554889e5 4883ec10 897dfc8b 75fc488d  UH..H....}..u.H.
 0010 3d5b0000 00b000e8 00000000 4883c410  =[..........H...
 0020 5dc3662e 0f1f8400 00000000 0f1f4000  ].f...........@.
 0030 554889e5 4883ec10 c745fc00 000000c7  UH..H....E......
 0040 45f80100 00008b05 00000000 03050000  E...............
 0050 00000345 f80345f4 89c7e800 0000008b  ...E..E.........
 0060 45f84883 c4105dc3                    E.H...].
Contents of section __data:
 0068 54000000 55000000                    T...U...
Contents of section __cstring:
 0070 25640a00                             %d..
Contents of section __bss:
<skipping contents of bss section at [0120, 0124)>
Contents of section __compact_unwind:
 0078 00000000 00000000 22000000 00000001  ........".......
 0088 00000000 00000000 00000000 00000000  ................
 0098 30000000 00000000 38000000 00000001  0.......8.......
 00a8 00000000 00000000 00000000 00000000  ................
Contents of section __eh_frame:
 00b8 14000000 00000000 017a5200 01781001  .........zR..x..
 00c8 100c0708 90010000 24000000 1c000000  ........$.......
 00d8 28ffffff ffffffff 22000000 00000000  (.......".......
 00e8 00410e10 8602430d 06000000 00000000  .A....C.........
 00f8 24000000 44000000 30ffffff ffffffff  $...D...0.......
 0108 38000000 00000000 00410e10 8602430d  8........A....C.
 0118 06000000 00000000                    ........
```

## 观察ELF文件结构
``` shell
$ readelf -h SimpleSection.o
```

```
ELF Header:
  Magic:   7f 45 4c 46 02 01 01 00 00 00 00 00 00 00 00 00 
  Class:                             ELF64
  Data:                              2's complement, little endian
  Version:                           1 (current)
  OS/ABI:                            UNIX - System V
  ABI Version:                       0
  Type:                              REL (Relocatable file)
  Machine:                           Advanced Micro Devices X86-64
  Version:                           0x1
  Entry point address:               0x0
  Start of program headers:          0 (bytes into file)
  Start of section headers:          1088 (bytes into file)
  Flags:                             0x0
  Size of this header:               64 (bytes)
  Size of program headers:           0 (bytes)
  Number of program headers:         0
  Size of section headers:           64 (bytes)
  Number of section headers:         13
  Section header string table index: 12
```


## 查看ELF文件段表
```
/app # readelf -S SimpleSection.o
There are 13 section headers, starting at offset 0x440:

Section Headers:
  [Nr] Name              Type             Address           Offset
       Size              EntSize          Flags  Link  Info  Align
  [ 0]                   NULL             0000000000000000  00000000
       0000000000000000  0000000000000000           0     0     0
  [ 1] .text             PROGBITS         0000000000000000  00000040
       0000000000000057  0000000000000000  AX       0     0     1
  [ 2] .rela.text        RELA             0000000000000000  00000330
       0000000000000078  0000000000000018   I      10     1     8
  [ 3] .data             PROGBITS         0000000000000000  00000098
       0000000000000008  0000000000000000  WA       0     0     4
  [ 4] .bss              NOBITS           0000000000000000  000000a0
       0000000000000004  0000000000000000  WA       0     0     4
  [ 5] .rodata           PROGBITS         0000000000000000  000000a0
       0000000000000004  0000000000000000   A       0     0     1
  [ 6] .comment          PROGBITS         0000000000000000  000000a4
       000000000000001b  0000000000000001  MS       0     0     1
  [ 7] .note.GNU-stack   PROGBITS         0000000000000000  000000bf
       0000000000000000  0000000000000000           0     0     1
  [ 8] .eh_frame         PROGBITS         0000000000000000  000000c0
       0000000000000058  0000000000000000   A       0     0     8
  [ 9] .rela.eh_frame    RELA             0000000000000000  000003a8
       0000000000000030  0000000000000018   I      10     8     8
  [10] .symtab           SYMTAB           0000000000000000  00000118
       0000000000000198  0000000000000018          11    11     8
  [11] .strtab           STRTAB           0000000000000000  000002b0
       0000000000000079  0000000000000000           0     0     1
  [12] .shstrtab         STRTAB           0000000000000000  000003d8
       0000000000000061  0000000000000000           0     0     1
Key to Flags:
  W (write), A (alloc), X (execute), M (merge), S (strings), I (info),
  L (link order), O (extra OS processing required), G (group), T (TLS),
  C (compressed), x (unknown), o (OS specific), E (exclude),
  l (large), p (processor specific)
```


## ELF Header 大小 
根据32bit 64位不一样
32位->52字节
64位->64字节

## 查看符号表
```
$ readelf -s SimpleSection.o
Symbol table '.symtab' contains 17 entries:
   Num:    Value          Size Type    Bind   Vis      Ndx Name
     0: 0000000000000000     0 NOTYPE  LOCAL  DEFAULT  UND 
     1: 0000000000000000     0 FILE    LOCAL  DEFAULT  ABS SimpleSection.c
     2: 0000000000000000     0 SECTION LOCAL  DEFAULT    1 
     3: 0000000000000000     0 SECTION LOCAL  DEFAULT    3 
     4: 0000000000000000     0 SECTION LOCAL  DEFAULT    4 
     5: 0000000000000000     0 SECTION LOCAL  DEFAULT    5 
     6: 0000000000000004     4 OBJECT  LOCAL  DEFAULT    3 static_var.1915
     7: 0000000000000000     4 OBJECT  LOCAL  DEFAULT    4 static_var2.1916
     8: 0000000000000000     0 SECTION LOCAL  DEFAULT    7 
     9: 0000000000000000     0 SECTION LOCAL  DEFAULT    8 
    10: 0000000000000000     0 SECTION LOCAL  DEFAULT    6 
    11: 0000000000000000     4 OBJECT  GLOBAL DEFAULT    3 global_int_var
    12: 0000000000000004     4 OBJECT  GLOBAL DEFAULT  COM global_uint_var
    13: 0000000000000000    36 FUNC    GLOBAL DEFAULT    1 func1
    14: 0000000000000000     0 NOTYPE  GLOBAL DEFAULT  UND _GLOBAL_OFFSET_TABLE_
    15: 0000000000000000     0 NOTYPE  GLOBAL DEFAULT  UND printf
    16: 0000000000000024    51 FUNC    GLOBAL DEFAULT    1 main
```