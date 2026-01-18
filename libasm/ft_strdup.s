global ft_strdup
extern ft_strlen
extern ft_strcpy
extern malloc

section .text
ft_strdup:
    push rdi ;should i align this now or not
    call ft_strlen
    mov rdi, rax
    call malloc
    pop rsi
    test rax, rax
    jz .done
    mov rdi, rax
    call ft_strcpy
.done:
    ret
