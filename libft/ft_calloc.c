/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:36:23 by mhuszar           #+#    #+#             */
/*   Updated: 2026/02/23 18:05:40 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//OF is set if RDX is non-zero
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;
	size_t	total_size;

	__asm__ volatile (
		"xor %%rdx, %%rdx; mulq %%rdi; jno 1f;"
		"xor %%rax, %%rax; not %%rax;"
		"1: xor %%rdx, %%rdx;"
		: "=a" (total_size), "=d" (result)
		: "D" (nmemb), "0" (size)
		: "cc"
	);
	if (total_size != SIZE_MAX)
		result = malloc(total_size);
	if (result)
		ft_bzero(result, total_size);
	return (result);
}

// #include <string.h>
// int	main(void)
// {
// 	char *ptr;
// 	ptr = ft_calloc(10, 1);
// 	if (!ptr)
// 		return (1);
// 	memset(ptr, 'a', 10);
// 	ptr[9] = 0;
// 	printf("%s\n", ptr);
// 	free(ptr);
// 	ptr = ft_calloc(2, 0); //freeable ptr on zero
// 	free(ptr);
// 	ptr = ft_calloc(2147483647, 2147483650);
// 	if (!ptr)
// 		return (42);
// 	return (0);
// }
