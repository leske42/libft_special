/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:19:51 by mhuszar           #+#    #+#             */
/*   Updated: 2026/02/23 19:27:03 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	__asm__ volatile (
		"cld; xor %%rax, %%rax; mov $-1, %%rcx;"
		"repne scasb; neg %%rcx; dec %%rcx; sub %%rcx, %%rdi;"
		"movq $1, %%rax; mov %%rdi, %%rsi; mov %%edx, %%edi;"
		"lea -1(%%rcx), %%rdx; syscall;"
		: "+D" (s), "+d" (fd)
		:
		: "rax", "rcx", "rsi", "memory", "r11", "cc"
	);
}

// int main(void)
// {
// 	char buf[717012];

// 	int fd = open("input.txt", 0);
// 	read(fd, buf, 717011);
// 	buf[717011] = '\0';
// 	ft_putstr_fd(buf, 1);
// 	return(0);
// }
