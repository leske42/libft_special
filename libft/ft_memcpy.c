/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:43:05 by mhuszar           #+#    #+#             */
/*   Updated: 2026/02/23 18:48:28 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	__asm__ volatile (
		"mov %%rax, %%rcx; cld; rep movsb"
		: "+D" (dest), "+S"(src)
		: "a" (n)
		: "memory", "cc", "rcx"
	);
	return (dest - n);
}
/*arguably the issue of not saving to tmp ONLY arises with O3 AND using
a main in separate file. BUT it cannot be solved with (dest - n) for any
case when the issue is not present UNLESS moving D to + section.
now does n not aguably have the same issue??*/

// #include<string.h>
// int	main(void)
// {
// 	char source[5] = "Alma";
// 	char destination[6] = "korte";
// 	// memcpy(source, destination, 2);
// 	volatile char *lol = ft_memcpy(destination, source, 2);
// 	return printf("%s", lol/*(char*)ft_memcpy(destination, source, 2)*/);
// 	// printf("%s\n", (char*)memcpy(NULL, NULL, 3));
// 	// printf("%s\n", (char*)ft_memcpy(NULL, NULL, 3));
// 	// return (0);
// }
