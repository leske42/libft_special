
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
    mov rcx, rbx
    xor r13, r13        ;newly built list top
    xor r14, r14        ;newly built list end
    jmp .mark_head_B
.outer_loop:
    mov rdi, r13        ;reset tmp head ptrs
    mov rsi, r13
    xor r13, r13
    xor r14, r14
.inner_loop:
    mov rcx, rbx        ;init temp counter to sublist len
    mov rdi, rsi        ;A begins from previous B
.mark_head_A:
    mov rdi, [rdi + 8]  ;travel along the list,
    dec rcx             ;sublist len times to skip B nodes ;HERE should NEVER be zero (B nodes checked already)
    jnz .mark_head_A
    mov rsi, rdi        ;B head begins from new A
    mov rcx, rbx
.mark_head_B:
    mov rsi, [rsi + 8]  ;B head skips the A nodes
    test rsi, rsi       ;check if early end (means we have only an A list)
    jz  .merge_A_B
    dec rcx
    jnz .mark_head_B
.setup_len:
    ;lea rcx, [rbx - rcx]
    neg rcx
    lea rcx, [rbx + rcx]
.merge_A_B:
    ;test rdi, rdi
    test rcx, rcx
    jz .sublist_A_over
    test rsi, rsi       ;if only sublist B is over, keep merging As
    jz .smaller_A
    push rdi
    push rsi
    push rcx
    mov rdi, [rdi]
    mov rsi, [rsi]
    call r12            ;perform compare
    pop rcx
    pop rsi
    pop rdi
    cmp rax, 0          ;check compare result
    jg .smaller_B
.smaller_A:             ;append A top to Big List end
    test r14, r14
    jnz .old_head_A
    mov r13, rdi
    mov r14, rdi
    jmp .new_head_A
    .old_head_A:
    mov [r14 + 8], rdi
    .new_head_A:
    mov rax, [rdi + 8]
    mov qword [rdi + 8], 0
    mov r14, rdi
    mov rdi, rax
    dec rcx             
    jmp .merge_A_B
.smaller_B:             ;append B top to Big List end
    test r14, r14
    jnz .old_head_B
    mov r13, rsi
    mov r14, rsi
    jmp .new_head_B
    .old_head_B:
    mov [r14 + 8], rsi
    .new_head_B:
    mov rax, [rsi + 8]
    mov qword [rsi + 8], 0
    mov r14, rsi
    mov rsi, rax
    jmp .merge_A_B
.sublist_A_over:
    test rsi, rsi       ;if there is no B left, mark new sublists
    jz .mark_head_A
    jmp .smaller_B      ;if there is any B left, merge it
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

