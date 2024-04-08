/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:36:42 by mhuszar           #+#    #+#             */
/*   Updated: 2024/04/08 21:52:52 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_exit(int status)
{
    __asm__ volatile (
        "xorq %%rax, %%rax; xorq %%rdi, %%rdi;"
        "movl %0, %%edi; movl $60, %%eax; movsx %%eax, %%rax;"
        "syscall;"
        :
        : "r" (status)
        : "rax", "rdi", "memory"
    );
}

int main(void)
{
    ft_exit(-1);
    while (1)
        ;
}