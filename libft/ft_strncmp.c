/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 14:22:15 by mhuszar           #+#    #+#             */
/*   Updated: 2026/02/24 21:14:10 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//the fun question is - does moulinette use valgrind?
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	result;

	__asm__ volatile ("xor %%rdx, %%rdx;"
		"cld; test %%rcx, %%rcx; jz 3f; 1: cmpsb; dec %%rcx;"
		"movb -1(%%rsi), %%al; movb -1(%%rdi), %%dl;"
		"cmp %%al, %%dl; jnz 2f; test %%rcx, %%rcx; jz 2f;"
		"cmp $0, %%al; jz 2f; cmp $0, %%dl; jz 2f; jmp 1b;"
		"2: sub %%edx, %%eax; 3:"
		: "=a" (result), "+S" (s1), "+D" (s2), "+c" (n)
		: "0" (0)
		: "cc", "memory", "rdx"
	);
	return (result);
}

// #include<unistd.h>
// #include<string.h>
// #include<stdio.h>
// int	main(void)
// {
// 	printf("%d\n", strncmp("apple", "apxle", 300));
// 	//write(1, "\n", 1);
// 	printf("%d\n", ft_strncmp("apple", "apxle", 300));
// 	return (0);
// }
