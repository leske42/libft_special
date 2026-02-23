/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:52:05 by mhuszar           #+#    #+#             */
/*   Updated: 2026/02/23 17:31:07 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;

	new_str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	__asm__ volatile ("test %%rdi, %%rdi; jz 7f;"
		"mov %%rdi, %%r8; mov %4, %%rcx; rep movsb;"
		"mov %%rax, %%rsi; mov %%rdx, %%rcx; rep movsb; movb $0, (%%rdi);"
		"mov %%r8, %%rdi; mov %%r9, %%rcx; 7:"
		: "+S" (s1), "+D" (new_str)
		: "a" (s2), "d" (ft_strlen(s2)), "r" (ft_strlen(s1))
		: "r8", "rcx"
	);
	return (new_str);
}

// int	main(void)
// {
// 	char *str = ft_strjoin("ubuntu ", "software");
// 	printf("%s", str);
// 	free(str);
// 	return (0);
// }
