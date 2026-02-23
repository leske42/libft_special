/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:30:44 by mhuszar           #+#    #+#             */
/*   Updated: 2026/02/23 18:57:18 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	__asm__ volatile (
		"mov %%rdi, %%rdx;"
		"cld; rep stosb;"
		"mov %%rdx, %%rdi;"
		: "+D" (s), "+c"(n)
		: "a"(c)
		: "memory", "cc", "rdx"
	);
	return (s);
}

// #include<stdio.h>
// int	main(void)
// {
// 	char alma[9] = "abcdefgh";
// 	ft_memset(alma, 48, 3);
// 	printf("%s", alma);
// 	return (0);
// }
