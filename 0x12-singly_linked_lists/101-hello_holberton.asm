section .data
format db "Hello, Holberton", 0

section .text
global main
extern printf

main:
mov rdi, format   ; Load the address of the format string into rdi
xor eax, eax      ; Clear eax
call printf       ; Call the printf function

xor eax, eax      ; Set return value to 0
ret
