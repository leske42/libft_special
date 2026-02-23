/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:18:12 by mhuszar           #+#    #+#             */
/*   Updated: 2026/02/23 19:22:03 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	__asm__	volatile	(
			"movq $1, %%rax;"
			"movl %1, %%edi;"
			"movq %0, %%rsi;"
			"movq $1, %%rdx;"
			"syscall;"
			:
			: "r" (&c), "r" (fd)
			: "rax", "rdi", "rsi", "rdx", "memory", "cc", "rcx", "r11"
			);
}

// int main(void)
// {
// 	ft_putchar_fd('A', 1);
// 	ft_putchar_fd('\n', 1);
// 	return (0);
// }
