global ft_strlen

section .text
ft_strlen:
    xor rcx, rcx
    xor rax, rax
    cld
    not rcx
    repne scasb
    not rcx
    dec rcx
    mov rax, rcx
    ret