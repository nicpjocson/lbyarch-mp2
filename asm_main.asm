section .text
bits 64
default rel
global asm_main
extern printf

asm_main:
    push rbp
    mov rbp, rsp

    mov ebx, ecx
    mov rdi, rdx
    mov rax, r8

    push rbx
    push rdi

    sub ebx, 6
    add rdi, 12
    mov r9, 0
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
    
    movss [rax + r9], xmm0
    dec ebx
    add rdi, 4
    add r9, 4

    cmp ebx, 0
    jnz stencil_kernel

    pop rdi
    pop rbx
    pop rbp
    ret
