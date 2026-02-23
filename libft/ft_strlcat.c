/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 20:56:38 by mhuszar           #+#    #+#             */
/*   Updated: 2026/02/23 17:07:28 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//now i remember the main issue with these functions was not to make them work,
//but to provide always the stupid return value specified
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	res;

	__asm__ volatile (
		"cmp %%rcx, %%rdx; jg 6f; add %%rdx, %%rax; dec %%rcx;"
		"sub %%rdx, %%rcx; add %%rdx, %%rdi; rep movsb; jmp 7f;"
		"6: add %%rcx, %%rax; 7:"
		: "=a" (res)
		: "D" (dst), "S" (src), "c" (size), "a" (ft_strlen(src)), \
"d" (ft_strlen(dst))
		:
	);
	return (res);
}

// #include<stdio.h>
// #include <bsd/string.h>
// //link with -lbsd here also
// int	main(void)
// {
// 	char dst[15] = "apple";
// 	char dst2[15] = "apple";
// 	char src[4] = "hehe";
// 	printf("%zu\n", strlcat(dst2, src, 2));
// 	printf("%zu\n", ft_strlcat(dst, src, 2));
// 	printf("STRLCAT COPIED: %s\n", dst2);
// 	printf("FT_STRLCAT COPIED: %s\n", dst);

// 	//if i change the order of these 2 the result is different??
// 	printf("%zu\n", strlcat(dst2, src, 9));
// 	printf("%zu\n", ft_strlcat(dst, src, 9));
// 	printf("STRLCAT COPIED: %s\n", dst2);
// 	printf("FT_STRLCAT COPIED: %s\n", dst);
// 	return (0);
// }
