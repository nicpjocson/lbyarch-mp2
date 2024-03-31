section .text
bits 64
default rel
extern printf
global asm_main

asm_main:
    push rbp
    mov rbp, rsp

    mov ebx, ecx
    mov rdi, rdx
    mov rsi, r8

    sub ebx, 6
    add rdi, 12
stencil_kernel:    
    movss xmm0, [rdi - 12]
    movss xmm1, [rdi - 8]
    movss xmm2, [rdi - 4]
    movss xmm3, [rdi]
    movss xmm4, [rdi + 4]
    movss xmm5, [rdi + 8]

    addss xmm0, xmm1

    movss xmm1, [rdi + 12]
    addss xmm0, xmm1

    addss xmm0, xmm2
    addss xmm0, xmm3
    addss xmm0, xmm4
    addss xmm0, xmm5
    
    movss [rsi], xmm0
    dec ebx
    add rdi, 4
    add rsi, 4

    cmp ebx, 0
    jnz stencil_kernel

    pop rbp
    ret
