/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:38:49 by mhuszar           #+#    #+#             */
/*   Updated: 2026/02/15 17:51:26 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//i remember he main issue with these functions not to make them work,
//but to provide always the stupid return value specified
size_t	__attribute__((noinline))
	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	res;

	__asm__ volatile (
		"test %%rcx, %%rcx; jz 2f;"
		"dec %%rcx; cld; push %%rsi;"
		"0: cmpb $0, (%%rsi); jz 1f; cmpq $0, %%rcx; jz 1f; movsb;"
		"dec %%rcx; jmp 0b;"
		"1: movq $0, (%%rdi); pop %%rsi;"
		"2: mov %%rsi, %%rdi; mov $-1, %%rcx; xor %%rax, %%rax;"
		"repne scasb; neg %%rcx; sub $2, %%rcx;"
		: "=c" (res)
		: "D" (dst), "S"(src), "c"(size)
		: "memory", "cc", "flags"
	);
	return (res);
}
//TODO: after repne scasb, why do i seem to have to sub 2 instead of 1?

// #include<stdio.h>
// #include<string.h>
// int	main(void)
// {
// 	char	src[] = "hilalala";
// 	char	dest[] = "ubuntusoftware";
// 	unsigned int n = 6;

// 	//printf("%d\n", ft_strlcpy(dest, src, n));
// 	ft_strlcpy(dest, src, n);
// 	printf("%s\n", dest);
// 	printf("%zu\n", ft_strlcpy(dest, src, n));
// 	return (0);
// }
