
extern ft_strlen
global ft_atoi_base

.validate_base:
    xor rax, rax
    test r14, r14
    jz .error
    sub rsp, 128
    mov rcx, 16
    mov rdi, rsp
    rep stosq
    mov rdi, r13
.val_loop:
    lodsb
    cmp al, 0
    jz .loop
    cmp al, 48
    jl .error
    cmp al, 126
    jg .error
    test al, byte [rsp + rax]
    jnz .error
    mov byte [rsp + rax], al
    jmp .val_loop
.error:
    xor rax, rax
    jmp .epilogue

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
    jmp .validate_base
.loop:
    mov al, byte [r12]
    test al, al
    jz .done
    mov rdi, r13
    mov rcx, r14
    inc rcx
    repne scasb
    test rcx, rcx
    jz .error
    imul rbx, r14
    sub r14, rcx
    add rbx, r14
    add r14, rcx
    inc r12
    jmp .loop
.done:
    mov rax, rbx
.epilogue:
    add rsp, 128
    pop r14
    pop r13
    pop r12
    pop rbx
    ret
