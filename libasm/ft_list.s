global ft_list_push_front
global ft_free_list
extern malloc
extern free

section .text
ft_list_push_front:
    push rdi
    push qword [rdi]
    push rsi
    mov rdi, 16
    call malloc
    test rax, rax
    jz .done
    pop qword [rax]
    pop qword [rax + 8]
    pop rdi
    mov [rdi], rax
.done:
    ret

ft_free_list: ;enable commented part if data is heap allocated
    push qword [rdi + 8]
    ;push rdi
    ;mov rdi, [rdi]
    ;call free
    ;pop rdi
    call free
    pop rdi
    test rdi, rdi
    jnz ft_free_list