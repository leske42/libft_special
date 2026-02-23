/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:10:11 by mhuszar           #+#    #+#             */
/*   Updated: 2026/02/23 18:44:33 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int	result;

	__asm__ volatile (
		"cld; repe cmpsb;"
		"movzbl -1(%%rsi), %%eax;"
		"movzbl -1(%%rdi), %%ecx;"
		"sub %%ecx, %%eax;"
		: "=a" (result), "+S" (s1), "+D" (s2), "+c" (n)
		:
		: "cc", "memory"
	);
	return (result);
}

// #include<unistd.h>
// #include<string.h>
// #include<stdio.h>
// int	main(void)
// {
// 	printf("%d\n", memcmp("apple", "apple", 5));
// 	printf("%d\n", ft_memcmp("apple", "apple", 5));
// 	printf("%d\n", memcmp("\xff\xaa\x12", "\xff\xaa\xde\x12MACOS", 4));
// 	printf("%d\n", ft_memcmp("\xff\xaa\x12", "\xff\xaa\xde\x12MACOS", 4));
// 	return (0);
// }
