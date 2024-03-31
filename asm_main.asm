section .data
section .text
bits 64
default rel
extern printf
global asm_main

asm_main:
    push rbp
    mov rbp, rsp

    mov rdi, [rbp+8]
    mov rsi, [rbp+16] 
    ;mov r8d, [rbp+24]

    ;sub r8d, 6
    add rdi, 12
    mov r8d, 2
stencil_kernel:    
    movss xmm0, [rdi - 12]
    movss xmm1, [rdi - 8]
    movss xmm2, [rdi - 4]
    movss xmm3, [rdi]
    movss xmm4, [rdi + 4]
    movss xmm5, [rdi + 8]
    

    movss [rsi], xmm3
    dec r8d
    add rdi, 4
    add rsi, 4

    cmp r8d, 0
    jnz stencil_kernel

    pop rbp
    ret
