section .data
	hello_fmt db "Hello, Holberton", 0
	nl db 10, 0    ; New line character (ASCII value 10)

section .text
	global main

	extern printf

main:
	; Call printf function
	mov rdi, hello_fmt
	call printf

	; Exit the program
	mov eax, 60       ; System call number for exit
	xor edi, edi      ; Exit status 0
	syscall

