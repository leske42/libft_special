/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:10:34 by mhuszar           #+#    #+#             */
/*   Updated: 2026/02/23 19:48:01 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*res;

	__asm__ volatile ("mov %%rdi, %%rdx; mov %%rsi, %%rax; inc %%rcx;"
		"mov %%rcx, %%r8; cmpb $0, (%%rdi); jz 3f; cld;"
		"1: repe cmpsb; cmpb $0, -1(%%rdi); jz 3f; cmpb $0, -1(%%rsi); jz 2f;"
		"test %%rcx, %%rcx; jz 2f; mov %%rdx, %%rdi; inc %%rax;"
		"mov %%rax, %%rsi; dec %%r8; mov %%r8, %%rcx; jmp 1b;"
		"2: xor %%rax, %%rax; 3:"
		: "=a" (res), "+S" (big), "+D" (little), "+c" (len)
		:
		: "rdx", "r8", "cc", "memory"
	);
	return (res);
}

// #include <string.h>
// //requires -lbsd
// char *strnstr(const char *big, const char *little, size_t len);
// int	main(void)
// {
// 	char a[] = "12a45ababc90";
// 	char b[] = "abc";
// 	char *c = ft_strnstr(a, b, 12);
// 	printf("%s\n", c);
// 	c = strnstr(a, b, 12);
// 	printf("%s\n", c);

// 	c = ft_strnstr(a, b, 9);
// 	printf("%s\n", c);
// 	c = strnstr(a, b, 9);
// 	printf("%s\n", c);

// 	c = ft_strnstr("hehiahehhehe", "hehe", 12);
// 	printf("%s\n", c);
// 	c = strnstr("hehiahehhehe", "hehe", 12);
// 	printf("%s\n", c);

// 	c = ft_strnstr("hehiahehhehe", "hehe", 11);
// 	printf("%s\n", c);
// 	c = strnstr("hehiahehhehe", "hehe", 11);
// 	printf("%s\n", c);

// 	c = ft_strnstr("abc", "a", 0);
// 	printf("%s\n", c);
// 	c = strnstr("abc", "a", 0);
// 	printf("%s\n", c);

// 	c = ft_strnstr("abc", "c", 2);
// 	printf("%s\n", c);
// 	c = strnstr("abc", "c", 2);
// 	printf("%s\n", c);

// 	c = ft_strnstr("abc", "", 2);
// 	printf("%s\n", c);
// 	c = strnstr("abc", "", 2);
// 	printf("%s\n", c);
// 	return (0);
// }
