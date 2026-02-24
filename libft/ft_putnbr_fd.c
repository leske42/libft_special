/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:53:29 by mhuszar           #+#    #+#             */
/*   Updated: 2026/02/24 21:53:50 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//throws up everything on the stack in reverse order & prints
void	ft_putnbr_fd(int nb, int fd)
{
	__asm__ volatile ("xor %%r8, %%r8; xor %%r9, %%r9;"
		"movslq %%eax, %%rax; test %%rax, %%rax; jns 1f; neg %%rax; not %%r9;"
		"1: xor %%rdx, %%rdx; movq $10, %%rcx; divq %%rcx; addq $48, %%rdx;"
		"sub $1, %%rsp; movb %%dl, (%%rsp); inc %%r8; cmp $0, %%rax; jne 1b;"
		"test %%r9, %%r9; jz 2f; sub $1, %%rsp; movb $45, (%%rsp); inc %%r8;"
		"2: movq $1, %%rax; movq %%rsp, %%rsi; movq %%r8, %%rdx; syscall;"
		"add %%r8, %%rsp;"
		: "+a" (nb), "+D" (fd)
		:
		: "memory", "rsi", "rdx", "cc", "rcx", "r11", "r8", "r9"
	);
}

// int	main(void)
// {
// 	//ft_putnbr_fd(2147483647, 1);
// 	//ft_putchar_fd('\n', 1);
// 	ft_putnbr_fd(-200, 1);
// 	printf("\n");
// 	ft_putnbr_fd(2147483647, 1);
// 	printf("\n");
// 	ft_putnbr_fd(-2147483648, 1);
// 	//ft_putchar_fd('\n', 1);
// 	//ft_putnbr_fd(-220, 1);
// 	//ft_putchar_fd('\n', 1);
// 	//ft_putnbr_fd(0, 1);
// 	return (0);
// }
