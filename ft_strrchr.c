/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:17:53 by mhuszar           #+#    #+#             */
/*   Updated: 2026/02/16 21:59:22 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	void	*result;

	__asm__ volatile (
		"cld; mov $-1, %%rcx; repne scasb; sub $1, %%rdi;"
		"neg %%rcx; dec %%rcx; std; mov %%rdx, %%rax; repne scasb;"
		"xor %%rax, %%rax; test %%rcx, %%rcx; jz 1f;"
		"inc %%rdi; mov %%rdi, %%rax; 1: cld"
		: "=a" (result)
		: "D" (s), "d" (c), "a" (0)
		: "cc", "flags", "rcx"
	);
	return (result);
}

// int	main(void)
// {
// 	char *alma;
// 	int a = 97;
// 	int l = 108;
// 	int n = 110;
// 	alma = "alma";
// 	printf("%s\n", ft_strrchr(alma, a));
// 	return (0);
// }
