section .data
section .text
bits 64
default rel
extern printf
global asm_main

asm_main:
    push rbp
    mov rbp, rsp

    mov rsi, [rbp + 8]  ; X array
    mov rdi, [rbp + 12] ; Y array
    mov ecx, [rbp + 16] ; size
    sub ecx, 6

    add rsi, 12
    mov ebx, 0
stencil_kernel:    
    movss xmm0, [rsi + ebx - 12]
    movss xmm1, [rsi + ebx - 8]
    movss xmm2, [rsi + ebx - 4]
    movss xmm3, [rsi + ebx]
    movss xmm4, [rsi + ebx + 4]
    movss xmm5, [rsi + ebx + 8]
    movss xmm6, [rsi + ebx + 12]
    
    addss xmm6, xmm0
    addss xmm6, xmm1
    addss xmm6, xmm2
    addss xmm6, xmm3
    addss xmm6, xmm4
    addss xmm6, xmm5

    movss [rdi + ebx], xmm6
    add ebx, 4
    dec ecx

    cmp ecx, 0
    jnz stencil_kernel

    pop rbp
    ret
