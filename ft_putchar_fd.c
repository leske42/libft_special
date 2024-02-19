/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:18:12 by mhuszar           #+#    #+#             */
/*   Updated: 2024/02/18 12:36:38 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*__asm__ ("movq $31, %%rdx;"
			"mulq %%rdx;"
			"addq %%rbx, %%rax;"
			"divq %%rcx;"
			: "=d" (hash2)
			: "a" (hash), "b" (keyvalue[counter]), "c" (hashsize)
			:
			);*/

void	ft_putchar_fd(char c, int fd)
{
	//printf("function called\n");
	__asm__ volatile (
	"movq $1, %%rax;"
	"movl %1, %%edi;"
	"movq %0, %%rsi;"
	"movq $1, %%rdx;"
	"syscall;"
		:
		: "r" (&c), "r" (fd)
		: "rax", "rdi", "rsi", "rdx", "memory"
	);
}
/*
int main(void)
{
	ft_putchar_fd('A', 1);
	return (0);
}*/
