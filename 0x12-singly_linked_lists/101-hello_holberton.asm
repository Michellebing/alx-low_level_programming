section .data
format db 'Hello, Holberton', 0

section .text
global main
extern printf

main:
; Load the format string address into edi
mov edi, format

; Clear eax register
xor eax, eax

; Call printf
call printf

; Set return value to 0
mov eax, 0

; Return
ret
