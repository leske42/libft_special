global ft_write
extern __errno_location

section .text
ft_write:
    mov rax, 1
    syscall
    test rax, rax
    jz .done
    push rax
    call __errno_location
    pop rcx
    neg rcx
    mov [rax], rcx
    mov rax, -1
.done
    ret
    