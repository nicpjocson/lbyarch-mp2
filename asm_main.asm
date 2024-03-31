section .data
section .text
bits 64
default rel
extern printf
global asm_main

asm_main:
    lea rdi, [rsp+8]     ; Load pointer to X into rdi
    lea rsi, [rsp+12]    ; Load pointer to Y into rsi
    mov rdx, [rsp+16]    ; Load n into rdx
    
    sub rdx, 6 
    add rdi, 12
stencil_kernel:
    cmp rdx, 6            
    jz fin                ; Exit loop if rdx = 0
    movss xmm0, [rdi - 12]; Load value X[i-3] into xmm0
    movss xmm1, [rdi - 8] ; Load value X[i-2] into xmm1
    movss xmm2, [rdi - 4] ; Load value X[i-1] into xmm2
    movss xmm3, [rdi]     ; Load value X[i] into xmm3
    movss xmm4, [rdi + 4] ; Load value X[i+1] into xmm4
    movss xmm5, [rdi + 8] ; Load value X[i+2] into xmm5
    movss xmm6, [rdi + 12]; Load value X[i+3] into xmm6
    
    addss xmm7, xmm0
    addss xmm7, xmm1
    addss xmm7, xmm2
    addss xmm7, xmm3
    addss xmm7, xmm4
    addss xmm7, xmm5
    addss xmm7, xmm6

    movss [rbx], xmm7
    subss xmm7, xmm7

    add rdi, 4
    add rsi, 4
    dec rdx
    jmp stencil_kernel
fin:
    ret