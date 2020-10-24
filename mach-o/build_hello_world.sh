nasm -f macho64 -o HelloWorld.o ./HelloWorld.asm
ld -o HelloWorld -e _main HelloWorld.o -lSystem

as exit.s -o exit.o 
ld exit.o -o exit -lSystem