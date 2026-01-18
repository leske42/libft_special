global ft_strcmp

section .text
ft_strcmp:
    xor rax, rax
    mov rcx, -1
    cld
    repe cmpsb
    movzx rax, byte [-1 + rdi]
    movzx rcx, byte [-1 + rsi]
    sub rax, rcx
    ret