global ft_list_push_front
global ft_free_list
global ft_list_size
global ft_list_remove_if
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

ft_free_list:
    push qword [rdi + 8]
    ;push rdi                   ;enable commented part if data is heap allocated
    ;mov rdi, [rdi]
    ;call free
    ;pop rdi
    call free
    pop rdi
    test rdi, rdi
    jnz ft_free_list

ft_list_size:
    xor rax, rax
.loop:
    test rdi, rdi
    jz .done
    mov rdi, [rdi + 8]
    inc rax
    jmp .loop
.done:
    ret

;void    ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));
ft_list_remove_if:
    push rbx
    push r12
    push r13
    push r14
    push r15
    push rdi
    mov rbx, [rdi]              ;will be list iterator
    mov r12, rsi                ;stores data ref
    mov r13, rdx                ;stores cmp function
    mov r14, rcx                ;is the 4th arg really rcx?
    xor r15, r15                ;will store prev node
    push r15                    ;will store new head
.check_loop:
    test rbx, rbx
    jz .finish
    mov rdi, [rbx]
    mov rsi, r12
    call r13
    test rax, rax
    jz .free
    mov r15, rbx
    mov rax, [rsp]
    test rax, rax
    cmovz rax, rbx              ;save new head on stack
    mov [rsp], rax
    mov rbx, [rbx + 8]
    jmp .check_loop
.finish:
    pop rax
    pop rdi
    mov [rdi], rax              ;set new head
    pop r15
    pop r14
    pop r13
    pop r12
    pop rbx
    ret
.free:
    mov rdi, [rbx]
    call r14
    push qword [rbx + 8]
    mov rdi, rbx
    call free
    pop rbx
    test r15, r15               ;check if previous node is set
    jz .check_loop
    mov qword [r15 + 8], rbx    ;if yes, restore link
    jmp .check_loop


