/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:20:18 by mhuszar           #+#    #+#             */
/*   Updated: 2026/02/20 21:00:22 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*begin;
	size_t	len;
	char	*res;

	__asm__ volatile (
		"push %%rdi; push %%rcx; cld; xor %%r8, %%r8;"
		"0: test %%r8, %%r8; jz 1f; std;"
		"1: test %%rdx, %%rdx; jz 2f; dec %%rdx; lodsb;"
		"movq (%%rsp), %%rcx; movq 8(%%rsp), %%rdi; cld; repne scasb; jz 0b;"
		"test %%r8, %%r8; jnz 2f; mov %%rsi, %%rbx; dec %%rbx;"
		"add %%rdx, %%rsi; sub $2, %%rsi; not %%r8; jmp 0b;"
		"2: add $16, %%rsp; add $2, %%rdx; cld;"
		: "=b" (begin), "=d" (len)
		: "c" (ft_strlen(set)), "d" (ft_strlen(s1) + 1), "S" (s1), "D" (set)
		: "rax", "cc", "flags"
	);
	printf("LEN IS: %zu, STARTING COPYING FROM: %s\n", len, begin);
	res = malloc(len);
	if (res)
		ft_strlcpy(res, begin, len);
	return (res);
}

// int	main(void)
// {
// 	printf("%s\n", ft_strtrim("/?***ubuntu//software\t**\t", "\t"));
// 	printf("%s\n", ft_strtrim("ubuntu//software", "ubntsofwear"));
// 	printf("%s\n", ft_strtrim("ubuntusoftware", "ubntsofwear"));
// 	return (0);
// }