/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:43:52 by mhuszar           #+#    #+#             */
/*   Updated: 2024/02/17 16:42:15 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


int	ft_isalnum(int c)
{
	int result;

	__asm__ volatile (
		"xorq %%rdi, %%rdi;"
		"movl %1, %%edi;"
		"call *%2;"
		"cmp $0, %%rax;"
		"jg 1f;"
		"call *%3;"
		"1:"
		"movl %%eax, %0;"
		: "=r" (result)
		: "r" (c), "r" (ft_isdigit), "r" (ft_isalpha)
		: "cc", "rax", "rdi"
	);
	return (result);
}
/*
#include<stdio.h>
int main(void)
{
	printf("%d", ft_isalnum('X'));
	return (0);
}*/
