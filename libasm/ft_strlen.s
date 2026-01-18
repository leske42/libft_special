global ft_strlen

section .text
ft_strlen:
    xor rax, rax
    cld
    mov rcx, -1
    repne scasb
    not rcx
    dec rcx
    mov rax, rcx
    ret