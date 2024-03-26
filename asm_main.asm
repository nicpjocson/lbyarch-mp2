;section .data
segment .text
    bits 64
    ;default rel
    ;extern printf
    global asm_main

asm_main:
    push rsi
    push rbp
    mov rbp, rsp
    add rbp, 16
    add rbp, 8

    ; delete, testing module 9 video
    xor rax, rax
    mov eax, ecx
    add eax, edx
    add eax, r8d
    add eax, r9d
    add esi, [rbp+32]
    add eax, esi
    add esi, [rbp+40]
    add eax, esi
    mov esi, [rbp+48]
    add eax, esi
    
    pop rbp
    pop rsi
    ret