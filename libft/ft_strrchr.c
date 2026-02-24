/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:17:53 by mhuszar           #+#    #+#             */
/*   Updated: 2026/02/24 23:17:40 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	void	*result;

	__asm__ volatile (
		"cld; mov $-1, %%rcx; repne scasb; sub $1, %%rdi;"
		"neg %%rcx; dec %%rcx; std; mov %%rdx, %%rax; repne scasb;"
		"test %%rcx, %%rcx; jnz 1f; cmpb 1(%%rdi), %%al; jz 1f;"
		"xor %%rax, %%rax; jmp 2f; 1: inc %%rdi; mov %%rdi, %%rax; 2: cld"
		: "=a" (result), "+D" (s)
		: "0" (0), "d" (c)
		: "cc", "rcx", "memory"
	);
	return (result);
}

// #include <string.h>
// int	main(void)
// {
// 	char *alma;
// 	int a = 97;
// 	int l = 108;
// 	int n = 110;
// 	alma = "alma";
// 	printf("%s\n", ft_strrchr(alma, n));

// 	char *src = "arrrrrrrr";
// 	char *d1 = strrchr(src, 'a');
// 	char *d2 = ft_strrchr(src, 'a');
// 	printf("ORIGINAL: %s, FT: %s\n", d1, d2);
// 	return (0);
// }
