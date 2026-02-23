/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:38:49 by mhuszar           #+#    #+#             */
/*   Updated: 2026/02/23 19:42:34 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	res;

	__asm__ volatile (
		"test %%rcx, %%rcx; jz 2f;"
		"dec %%rcx; cld; push %%rsi;"
		"0: cmpb $0, (%%rsi); jz 1f; cmpq $0, %%rcx; jz 1f; movsb;"
		"dec %%rcx; jmp 0b;"
		"1: movb $0, (%%rdi); pop %%rsi;"
		"2: mov %%rsi, %%rdi; mov $-1, %%rcx; xor %%rax, %%rax;"
		"repne scasb; neg %%rcx; sub $2, %%rcx;"
		: "=c" (res), "+D" (dst), "+S"(src)
		: "0" (size)
		: "memory", "cc", "rax"
	);
	return (res);
}
//TODO: after repne scasb, why do i seem to have to sub 2 instead of 1?

// #include<stdio.h>
// #include<string.h>
// //requires lbsd
// size_t strlcpy(char *dst, const char *src, size_t size);
// int	main(void)
// {
// 	char	src[] = "hilalala";
// 	char	dest[] = "ubuntusoftware";
// 	char	dest2[] = "ubuntusoftware";
// 	unsigned int n = 6;

// 	//printf("%d\n", ft_strlcpy(dest, src, n));
// 	// ft_strlcpy(dest, src, n);
// 	printf("%zu\n", ft_strlcpy(dest, src, n));
// 	printf("%s\n", dest);
// 	printf("%zu\n", strlcpy(dest2, src, n));
// 	printf("%s\n", dest2);
// 	return (0);
// }
