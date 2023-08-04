section .data
hello_fmt db "Hello, Holberton", 0
nl db 10, 0    ; New line character (ASCII value 10)

section .text
global _start

_start:
; Call printf function
mov rdi, hello_fmt
call printf

; Exit the program
mov rax, 60       ; System call number for exit
xor rdi, rdi      ; Exit status 0
syscall

