global ft_strcmp

section .text
ft_strcmp:
    cld
.loop:
    cmpsb
    jnz .done
    cmp byte [-1 + rdi], 0
    jz .done
    cmp byte [-1 + rsi], 0
    jz .done
    jmp .loop
.done:
    movzx rax, byte [-1 + rdi]
    movzx rcx, byte [-1 + rsi]
    sub rax, rcx
    ret
