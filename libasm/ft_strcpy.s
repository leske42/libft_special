global ft_strcpy

section .text
ft_strcpy:
    cld
    mov rax, rdi
.loop:
    cmp byte [rsi], 0
    jz .done
    movsb
    jmp .loop
.done:
    mov byte [rdi], 0
    ret