/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:36:23 by mhuszar           #+#    #+#             */
/*   Updated: 2026/02/19 18:56:24 by mhuszar          ###   ########.fr       */
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
		"xor %%rax, %%rax;"
		"1: xor %%rdx, %%rdx;"
		: "=a" (total_size), "=d" (result)
		: "D"(nmemb), "a"(size)
		: "memory", "cc", "flags"
	);
	if (total_size)
		result = malloc(total_size);
	if (result)
		ft_bzero(result, total_size);
	return (result);
}

// void	*ft_calloc(size_t nmemb, size_t size)
// {
// 	void	*result;

// 	__asm__ volatile (
// 		"xor %%rdx, %%rdx; mulq %%rdi; jno 1f;"
// 		"xor %%rax, %%rax; jmp 2f;"
// 		"1: push %%rax; push %%rcx; mov %%rax, %%rdi; call malloc;"
// 		"pop %%rcx; pop %%rsi; test %%rax, %%rax; jz 2f;"
// 		"push %%rax; mov %%rax, %%rdi; call *%%rcx; pop %%rax;"
// 		"2: "
// 		: "=a" (result)
// 		: "D"(nmemb), "a"(size), "c" (ft_bzero)
// 		: "memory", "cc", "flags", "rdx", "rsi"
// 	);
// 	return (result);
// }

#include <string.h>
int	main(void)
{
	char *ptr;
	ptr = ft_calloc(10, 1);
	if (!ptr)
		return (1);
	memset(ptr, 'a', 10);
	ptr[9] = 0;
	printf("%s\n", ptr);
	free(ptr);
	ptr = ft_calloc(2147483647, 2147483650);
	if (!ptr)
		return (42);
	return (0);
}
