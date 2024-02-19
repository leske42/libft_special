/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:53:29 by mhuszar           #+#    #+#             */
/*   Updated: 2024/02/18 19:31:16 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	__asm__ volatile (
		"movl %0, %%eax; movsx %%eax, %%rax; pushq %%rbx; xorq %%rbx, %%rbx;"
		"cmp $-1, %%rax; jg 1f; imulq $-1, %%rax; movq $1, %%rdx;"
		"movl %1, %%edi; sub $1, %%rsp; movq $45, (%%rsp);"
		"movq %%rsp, %%rsi; pushq %%rax; movq $1, %%rax;"
		"syscall; popq %%rax; add $1, %%rsp;"
		"1:"
		"xorq %%rdx, %%rdx; movq $10, %%rcx; divq %%rcx; addq $48, %%rdx;"
		"pushq %%rdx; incq %%rbx; cmp $0, %%rax; jne 1b;"
		"2:"
		"movq $1, %%rax; movl %1, %%edi; movq %%rsp, %%rsi;"
		"movq $1, %%rdx; syscall; decq %%rbx; popq %%rcx;"
		"cmp $0, %%rbx; jne 2b; popq %%rbx;"
		:
		: "r" (nb), "r" (fd)
		: "memory", "rdi", "rsi", "rax", "rdx", "cc", "rcx"
	);
}

/*int	ft_putnbr_fd(int nb, int fd)
{
	__asm__ volatile (
		"movl %1, %%ebx;"
		//"cmp $-2147483648, %0; jg 1f;"
		"movq $45, %%rdi; movl %%ebx, %%esi; movq %3, %%rax; call *%%rax;"
		"movq $50, %%rdi; movl %%ebx, %%esi; movq %3, %%rax; call *%%rax;"
		"movq $97, %%rdi; movl %%ebx, %%esi; movq %3, %%rax; call *%%rax;"
		"movq $104, %%rdi; movl %%ebx, %%esi; movq %3, %%rax; call *%%rax;"
		"movq $10, %%rdi; movl %%ebx, %%esi; movq %3, %%rax; call *%%rax;"
		//"movq $147483648, %%rdi; movl %%ebx, %%esi; movq %2, %%rax; call *%%rax;"
		"1:"
		
		:
		: "r" (nb), "r" (fd), "r" (ft_putnbr_ft), "r" (ft_putchar_fd)
		: "memory", "rdi", "rsi", "rax", "rbx"
	);
	return (fd);
}*/
/*
int	main(void)
{
	//ft_putnbr_fd(2147483647, 1);
	//ft_putchar_fd('\n', 1);
	ft_putnbr_fd(-200, 1);
	printf("\n");
	ft_putnbr_fd(2147483647, 1);
	printf("\n");
	ft_putnbr_fd(-2147483648, 1);
	//ft_putchar_fd('\n', 1);
	//ft_putnbr_fd(-220, 1);
	//ft_putchar_fd('\n', 1);
	//ft_putnbr_fd(0, 1);
	return (0);
}*/
