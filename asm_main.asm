section .data
ya dd 0.0
segment .text
    bits 64
    ;default rel
    ;extern printf
    global asm_main

asm_main:
    lea rax, [rsp+8]     ; Load pointer to X into eax
    lea rbx, [rsp+12]    ; Load pointer to Y into ebx
    mov rcx, [rsp+16]    ; Load n into ecx
    
    sub rcx, 6 
    add rax, 12
    
    movss xmm7, [ya]
    ; start loop in the 4th element
stencil_kernel:
    cmp ecx, 0
    jz fin
    movss xmm0, [rax - 12] ; Gte values [x-3]
    movss xmm1, [rax - 8] ; [x-2]
    movss xmm2, [rax - 4] ; [x-1]
    movss xmm3, [rax] ; [x]
    movss xmm4, [rax + 4] ; [x+1]
    movss xmm5, [rax + 8] ; [x+2]
    movss xmm6, [rax + 12] ; [x+3]
    
    ; Do the thing
    addss xmm7, xmm0
    addss xmm7, xmm1
    addss xmm7, xmm2
    addss xmm7, xmm3
    addss xmm7, xmm4
    addss xmm7, xmm5
    addss xmm7, xmm6
    movss [ebx], xmm7
    
    subss xmm7, xmm7
    add rax, 4
    add rbx, 4
    dec rcx
    jmp stencil_kernel
fin: NOP
    ret