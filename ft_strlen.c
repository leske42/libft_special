/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 21:34:12 by mhuszar           #+#    #+#             */
/*   Updated: 2024/02/17 16:35:09 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t result;

	__asm__ volatile (
	"xorb %%al, %%al;"
	"xorq %%rcx, %%rcx;"
	"notq %%rcx;"
	"movq %1, %%rdi;"
	"repne scasb;"
	"notq %%rcx;"
	"subq $1, %%rcx;"
	"movq %%rcx, %0;"
		: "=r" ((uint64_t) result)
		: "r" (str)
		: "rcx", "al", "rdi"
	);
	return (result);
}
/*
int main(void)
{
	printf("%zu\n", ft_strlen("123456789"));
}*/
