/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:02:25 by mhuszar           #+#    #+#             */
/*   Updated: 2026/02/23 19:32:36 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	void	*result;

	__asm__ volatile (
		"mov %3, %%rcx; cld; repne scasb;"
		"xor %%rsi, %%rsi;"
		"cmpb -1(%%rdi), %%al; jne 1f;"
		"lea -1(%%rdi, %%rsi, 1), %%rsi; 1:"
		: "=S" (result), "+D" (s)
		: "a" (c), "r" (ft_strlen(s))
		: "cc", "rcx", "memory"
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
// 	printf("%s\n", ft_strchr(alma, l));
// 	char s[] = "tripouille";
// 	printf("%s\n", ft_strchr(s, 'i' + 256));
// 	printf("%s", strchr(s, 'i' + 256));
// 	return (0);
// }
