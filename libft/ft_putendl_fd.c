/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:32:03 by mhuszar           #+#    #+#             */
/*   Updated: 2026/02/23 19:24:08 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	__asm__ volatile (
		"cld; xor %%rax, %%rax; mov $-1, %%rcx;"
		"repne scasb; neg %%rcx; dec %%rcx; sub %%rcx, %%rdi; push %%rdx;"
		"movq $1, %%rax; mov %%rdi, %%rsi; mov %%edx, %%edi; mov %%rcx, %%rdx;"
		"syscall;"
		"pop %%rdi; pushq $10; mov %%rsp, %%rsi; movq $1, %%rdx;"
		"movq $1, %%rax; syscall; pop %%rax;"
		: "+D" (s), "+d" (fd)
		:
		: "rax", "rcx", "rsi", "memory", "cc", "r11"
	);
}

// int main(void)
// {
// 	ft_putendl_fd("lol", 2);
// 	ft_putendl_fd("aaaaa", 1);
// }
