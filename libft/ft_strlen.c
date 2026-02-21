/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 21:34:12 by mhuszar           #+#    #+#             */
/*   Updated: 2026/02/20 17:54:22 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	result;

	__asm__ volatile (
		"cld; xor %%rax, %%rax; mov $-1, %%rcx;"
		"repne scasb;"
		"inc %%rcx; not %%rcx;"
		: "=c" (result)
		: "D" (str)
		: "rax", "cc", "flags"
	);
	return (result);
}

// int main(void)
// {
// 	printf("%zu\n", ft_strlen("123456789"));
// }
