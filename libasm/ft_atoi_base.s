
extern ft_strlen
global ft_atoi_base

find_position: ;D:str, A:char, C:len - not exposed so i won't keep the ABI
    push rdi
    repne scasb
    pop rdi

ft_atoi_base:
    push rbx
    push r12
    push r13
    push r14
    cld
    xor rbx, rbx
    mov r12, rdi
    mov r13, rsi
    mov rdi, rsi
    call ft_strlen
    mov r14, rax
    xor rax, rax
.loop:
    mov al, byte [r12]
    test al, al
    jz .done
    mov rdi, r13
    mov rcx, r14
    repne scasb
    inc rcx
    imul rbx, r14
    sub r14, rcx
    add rbx, r14
    add r14, rcx
    inc r12
    jmp .loop
.done:
    mov rax, rbx
.epilogue:
    pop r14
    pop r13
    pop r12
    pop rbx
    ret
