
extern ft_strlen
global ft_atoi_base

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
    sub rsp, 8
    call ft_strlen
    add rsp, 8
    mov r14, rax
    jmp .validate_base
.loop:
    cmp r8, r12
    jz .done
    mov al, byte [r12]
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

.validate_base:
    xor rax, rax
    test r14, r14
    jz .error
    sub rsp, 128
    mov rcx, 16
    mov rdi, rsp
    rep stosq
    mov rsi, r13
.val_loop:
    lodsb
    cmp al, 0
    jz .survey
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

.survey:
    mov rsi, r12
.whitespace:
    lodsb
    cmp al, 0
    jz .error
    cmp al, 43
    jz .was_pos
    cmp al, 45
    jz .was_neg
    cmp al, 32
    jz .whitespace
    cmp al, 9
    jl .error
    cmp al, 13
    jg .find_end
    jmp .whitespace
.was_neg:
    mov rbx, -1
    jmp .was_pos
.find_end:
    dec rsi
.was_pos:
    mov r12, rsi
.numbers:
    lodsb
    cmp al, 48
    jl .survey_done
    cmp al, 57
    jg .survey_done
    jmp .numbers
.survey_done:
    lea r8, [rsi - 1]
    jmp .loop
