
global ft_list_sort
extern ft_list_size


section .text
;void ft_list_sort(t_list **begin_list, int (*cmp)()); TODO: update r13 with list top, go through logic, add testing functions
ft_list_sort:
    push r12
    push r13
    push r14
    push rdi
    mov r12, rsi        ;save cmp function
    mov rdi, [rdi]
    push rdi
    call ft_list_size
    pop rdi
    push rax            ;save list size on stack
    mov rsi, rdi        ;set B and A to be initially same
    mov rbx, 1          ;init sublist len
    xor r13, r13        ;newly built list top
    xor r14, r14        ;newly built list end
    jmp .inner_loop
.outer_loop:
    mov rdi, r13        ;reset tmp head ptrs
    mov rsi, r13
.inner_loop:
    mov rcx, rbx        ;init temp counter to sublist len
.mark_head_A:
    mov rdi, rsi        ;A begins from previous B
    mov rdi, [rdi + 8]  ;travel along the list
    dec rcx             ;sublist len times to skip B nodes
    jnz .mark_head_A
    mov rcx, rbx
.mark_head_B:
    mov rsi, rdi        ;B begins from new A
    mov rsi, [rsi + 8]  ;and skips the A nodes
    dec rcx
    jnz .mark_head_B
.merge_A_B:
    push rdi
    mov rdi, [rdi]
    push rsi
    mov rsi, [rsi]
    call r12            ;perform compare
    pop rsi
    pop rdi
    cmp rax, 0          ;check compare result
    jg .smaller_B
.smaller_A:             ;append A top to Big List end
    mov [r14 + 8], rdi
    mov rax, [rdi + 8]
    mov qword [rdi + 8], 0
    mov r14, rdi
    mov rdi, rax        ;need to decide when to terminate the merge!
    jmp .merge_A_B
.smaller_B:
    mov [r14 + 8], rsi
    mov rax, [rsi + 8]
    mov qword [rsi + 8], 0
    mov r14, rsi
    mov rsi, rax
    jmp .merge_A_B
.all_merges_done:
    shl rbx, 1          ;double sublist len
    cmp rbx, [rsp]      ;check if sublist len is >= list len  
    jl .outer_loop      ;if no, continue
    pop rdi
    mov [rdi], r13      ;store result behind double ptr
    pop r14
    pop r13
    pop r12
    ret

