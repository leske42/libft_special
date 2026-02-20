/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:20:18 by mhuszar           #+#    #+#             */
/*   Updated: 2026/02/20 20:50:39 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char *begin;
	size_t len;
	char *res;
	
	__asm__ volatile (
		"push %%rdi; push %%rcx; cld;"
		"0: test %%rdx, %%rdx; jz 2f; dec %%rdx; lodsb; movq (%%rsp), %%rcx; movq 8(%%rsp), %%rdi; repne scasb; jz 0b;" //run until first marker point
		"mov %%rsi, %%rbx; dec %%rbx; add %%rdx, %%rsi; dec %%rsi; dec %%rsi;"
		"1: test %%rdx, %%rdx; jz 2f; dec %%rdx; std; lodsb; movq (%%rsp), %%rcx; movq 8(%%rsp), %%rdi; cld; repne scasb; jz 1b;"
		"2: add $16, %%rsp; inc %%rdx; inc %%rdx;"
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

int	main(void)
{
	printf("%s\n", ft_strtrim("/?***ubuntu//software\t**\t", "\t"));
	printf("%s\n", ft_strtrim("ubuntu//software", "ubntsofwear"));
	printf("%s\n", ft_strtrim("ubuntusoftware", "ubntsofwear"));
	return (0);
}