/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:24:32 by mhuszar           #+#    #+#             */
/*   Updated: 2026/02/23 20:05:08 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	dest_size;
	char	*sub_str;

	__asm__ volatile ("mov %2, %%rcx;"
		"mov %%rdx, %%rax; add %%rsi, %%rdx; cmp %%rcx, %%rdx; jb 1f;"
		"sub %%rsi, %%rcx; mov %%rcx, %%rax; 1: inc %%rax;"
		"test %%rax, %%rax; jns 2f; xor %%rax, %%rax; 2:"
		: "=a" (dest_size), "+d" (len)
		: "r" (ft_strlen(s)), "S" (start)
		: "rcx", "cc"
	);
	if (!dest_size)
		return (ft_strdup(""));
	sub_str = malloc(dest_size);
	if (sub_str)
		ft_strlcpy(sub_str, s + start, dest_size);
	return (sub_str);
}

/*
#include <stdio.h>
int	main(void)
{
	char *str;
	str = ft_substr("ubuntusoftware", 6, 4);
	printf("%s\n", str);
	free(str);
	str = ft_substr("soup", 4294967295, 0);
	printf("%s\n", str);
	free(str);
	str = ft_substr("soup", 2, 30);
	printf("%s\n", str);
	free(str);
	return (0);
}*/
