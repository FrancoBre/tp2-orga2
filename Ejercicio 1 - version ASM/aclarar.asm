extern malloc
extern free
global aclarar

SECTION .DATA

SECTION .TEXT

aclarar:
    push    rbp
    mov     rbp, rsp
    sub     rsp, 32
    mov     QWORD  [rbp-8], rdi
    mov     QWORD  [rbp-16], rsi
    mov     QWORD  [rbp-24], rdx
    mov     DWORD  [rbp-28], ecx
    mov     edx, DWORD  [rbp-28]
    mov     rax, QWORD  [rbp-8]
    mov     esi, edx
    mov     rdi, rax
    call    add
    mov     edx, DWORD  [rbp-28]
    mov     rax, QWORD  [rbp-16]
    mov     esi, edx
    mov     rdi, rax
    call    add
    mov     edx, DWORD  [rbp-28]
    mov     rax, QWORD  [rbp-24]
    mov     esi, edx
    mov     rdi, rax
    call    add
    nop
    leave
    ret
add:
    push    rbp
    mov     rbp, rsp
    sub     rsp, 32
    mov     QWORD  [rbp-24], rdi
    mov     DWORD  [rbp-28], esi
    mov     DWORD  [rbp-4], 0
    jmp     .L3
.L6:
    mov     DWORD  [rbp-8], 0
    jmp     .L4
.L5:
    mov     eax, DWORD  [rbp-4]
    cdqe
    lea     rdx, [0+rax*8]
    mov     rax, QWORD  [rbp-24]
    add     rax, rdx
    mov     rdx, QWORD  [rax]
    mov     eax, DWORD  [rbp-8]
    cdqe
    add     rdx, rax
    mov     eax, DWORD  [rbp-28]
    mov     esi, eax
    mov     rdi, rdx
    call    addWithSaturation
    add     DWORD  [rbp-8], 1
.L4:
    cmp     DWORD  [rbp-8], 9
    jle     .L5
    add     DWORD  [rbp-4], 1
.L3:
    cmp     DWORD  [rbp-4], 9
    jle     .L6
    nop
    nop
    leave
    ret
addWithSaturation:
    push    rbp
    mov     rbp, rsp
    mov     QWORD  [rbp-8], rdi
    mov     DWORD  [rbp-12], esi
    mov     rax, QWORD  [rbp-8]
    movzx   eax, BYTE  [rax]
    movzx   edx, al
    mov     eax, DWORD  [rbp-12]
    add     eax, edx
    cmp     eax, 255
    jle     .L8
    mov     rax, QWORD  [rbp-8]
    mov     BYTE  [rax], -1
    jmp     .L10
.L8:
    mov     rax, QWORD  [rbp-8]
    movzx   eax, BYTE  [rax]
    mov     edx, DWORD  [rbp-12]
    add     edx, eax
    mov     rax, QWORD  [rbp-8]
    mov     BYTE  [rax], dl
.L10:
    nop
    pop     rbp
    ret
generateMatrix:
        push    rbp
        mov     rbp, rsp
        push    rbx
        sub     rsp, 24
        mov     edi, 4096
        call    malloc
        mov     QWORD  [rbp-32], rax
        mov     DWORD  [rbp-20], 0
        jmp     .L12
.L13:
        mov     eax, DWORD  [rbp-20]
        cdqe
        lea     rdx, [0+rax*8]
        mov     rax, QWORD  [rbp-32]
        lea     rbx, [rdx+rax]
        mov     edi, 512
        call    malloc
        mov     QWORD  [rbx], rax
        add     DWORD  [rbp-20], 1
.L12:
        cmp     DWORD  [rbp-20], 511
        jle     .L13
        mov     rax, QWORD  [rbp-32]
        mov     rbx, QWORD  [rbp-8]
        leave
        ret