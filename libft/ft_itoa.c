/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:16:13 by mhuszar           #+#    #+#             */
/*   Updated: 2026/02/21 19:44:58 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_counter(long int n)
{
	int	res;

	__asm__ volatile (
		"test %%rax, %%rax; jns 1f; inc %%rcx; neg %%rax;"
		"1: xor %%rdx, %%rdx; inc %%rcx; div %%rsi; test %%rax, %%rax; jnz 1b;"
		: "=c" (res)
		: "a" (n), "S" (10), "c" (0)
		: "cc", "flags", "rdx"
	);
	return (res);
}

static char	*fill_number(char *str, long int n)
{
	__asm__ volatile ("test %%rdi, %%rdi; jz 3f;"
		"test %%rsi, %%rsi; jns 1f; neg %%rsi; stosb; dec %%rcx;"
		"1: mov $10, %%r8; add %%rcx, %%rdi; xor %%rax, %%rax; std;"
		"2: stosb; xchg %%rsi, %%rax; xor %%rdx, %%rdx; div %%r8;"
		"xchg %%rsi, %%rax; lea 48(%%rdx), %%rax; dec %%rcx; jns 2b;"
		"3: cld;"
		:
		: "D" (str), "a" (45), "S" (n), "c" (digit_counter(n))
		: "r8", "cc", "flags", "memory"
	);
	return (str);
}

char	*ft_itoa(int n)
{
	return (fill_number(malloc(digit_counter(n) + 1), n));
}

// int	main(void)
// {
// 	printf("%d\n", digit_counter(-123456789));
// 	char *str = ft_itoa(-2147483648);
// 	printf("%s\n", str);
// 	ft_bzero(str, 11);
// 	free(str);
// 	str = ft_itoa(999999999);
// 	printf("%s\n", str);
// 	free(str);
// 	return (0);
// }
