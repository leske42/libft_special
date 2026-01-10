/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:57:24 by mhuszar           #+#    #+#             */
/*   Updated: 2026/01/10 16:04:42 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//a C version in general would need to cast dst and src to integer type
//in order not to violate provenance.
void	__attribute__((noinline))
	*ft_memmove(void *dest, const void *src, size_t n)
{
	__asm__ volatile (
		"mov %%rdi, %%rax;"
		"cld; cmp %%rsi, %%rdi; jl 1f; std;"
		"lea -1(%%rsi, %%rcx, 1), %%rsi;"
		"lea -1(%%rdi, %%rcx, 1), %%rdi;"
		"1: rep movsb"
		: "=a" (dest)
		: "S"(src), "D"(dest), "c"(n)
		: "memory", "cc", "flags"
	);
	return (dest);
}
//Saving dst to a tmp ONLY covers for the O3 edge case

// #include <string.h>
// #include<stdio.h>
// int	main(void)
// {
// 	// char source[5] = "hehe";
// 	// char dest[5] = "haha";
// 	char source[12] = "Almateria";
// 	char *dest = source + 2;
// 	printf("SOURCE: %s, DEST: %s\n", source, dest);
// 	printf("NEW DST (should be src): %s\n", (char*)ft_memmove(dest, source, 9));
// 	//only use one or the other!
// 	// printf("NEW DST (should be src): %s\n", (char*)memcpy(dest, source, 9));
// 	return (0);
// }
