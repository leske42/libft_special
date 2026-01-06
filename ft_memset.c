/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:30:44 by mhuszar           #+#    #+#             */
/*   Updated: 2026/01/06 13:27:24 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	__attribute__((noinline))
	*ft_memset(void *s, int c, size_t n)
{
	__asm__ volatile (
		"cld; rep stosb"
		: "+D" (s)
		: "a"(c), "c"(n)
		: "memory", "cc", "flags"
	);
	return (s - n);
}

// #include<stdio.h>
// int	main(void)
// {
// 	char alma[9] = "abcdefgh";
// 	ft_memset(alma, 48, 3);
// 	printf("%s", alma);
// 	return (0);
// }
