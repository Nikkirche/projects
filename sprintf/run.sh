
nasm -f elf32 -F dwarf $1.asm -o $1.o     
gcc -m32 -no-pie tmain.c $1.o -g
./a.out