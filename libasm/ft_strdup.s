global ft_strdup
extern ft_strlen
extern ft_strcpy
extern malloc

section .text
ft_strdup:
    push rdi
    call ft_strlen
    lea rdi, [rax + 1]
    call malloc
    pop rsi
    test rax, rax
    jz .done
    mov rdi, rax
    sub rsp, 8
    call ft_strcpy
    add rsp, 8
.done:
    ret
