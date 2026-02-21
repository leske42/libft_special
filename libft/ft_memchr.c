/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:41:59 by mhuszar           #+#    #+#             */
/*   Updated: 2026/01/11 15:54:19 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	void	*result;

	__asm__ volatile (
		"cld; repne scasb;"
		"xor %%rsi, %%rsi;"
		"cmpb -1(%%rdi), %%al; jne 1f;"
		"lea -1(%%rdi, %%rsi, 1), %%rsi; 1:"
		: "=S" (result)
		: "D" (s), "a" (c), "c" (n)
		: "cc", "flags"
	);
	return (result);
}

// #include<string.h>
// int	main(void)
// {
// 	char *alma;
// 	int a = 97;
// 	int l = 108;
// 	int n = 110;
// 	alma = "alma";
// 	printf("%s\n", (char*)ft_memchr(alma, l, 10));
// 	printf("%s\n", (char*)memchr(alma, l, 10));
// 	printf("%s\n", (unsigned char *)memchr("/|\x12\xff\42|", '\200', 10));
// 	printf("%s\n", (unsigned char *)ft_memchr("/|\x12\xff\42|", '\200', 10));
// 	char s[] = {0, 1, 2 ,3 ,4 ,5};
// 	printf("%s\n", (unsigned char *)ft_memchr(s, 2, 3));
// 	printf("%s\n", (unsigned char *)memchr(s, 2, 3));
// 	return (0);
// }
