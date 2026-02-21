/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:45:48 by mhuszar           #+#    #+#             */
/*   Updated: 2026/01/11 16:38:22 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	__attribute__((noinline))
	ft_bzero(void *s, size_t n)
{
	__asm__ volatile (
		"cld; xor %%rax, %%rax;"
		"test $0b111, %%rcx; jz 8f;"
		"test $0b11, %%rcx; jz 4f;"
		"test $0b1, %%rcx; jz 2f;"
		"rep stosb; jmp 1f;"
		"8: shr $3, %%rcx; rep stosq; jmp 1f;"
		"4: shr $2, %%rcx; rep stosl; jmp 1f;"
		"2: shr $1, %%rcx; rep stosw;"
		"1:"
		:
		: "D"(s), "c"(n)
		: "memory", "cc", "flags", "rax"
	);
}

// #include<stdio.h>
// int	main(void)
// {
// 	char alma[9] = "abcdefgh";
// 	ft_bzero((alma + 3), 3);
// 	printf("%s\n", alma);
// 	int hehe[3] = {1, 2, 3};
// 	ft_bzero((hehe + 1), 2 * 4);
// 	printf("%d, %d", hehe[0], hehe[1]);
// 	return (0);
// }
