/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:54:33 by mhuszar           #+#    #+#             */
/*   Updated: 2026/02/16 22:29:52 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//survey will return 0 for invalid string, 1 for positive and -1 for negative
//will turn into conversion result to correct output by mul 
static int	survey(const char *str)
{
	int res;
	__asm__ volatile (
		""
		: "=a" (res)
		: "D" (str)
		:
	);
	return res;
}

static int	convert(const char *str, int survey)
{
	int res;
	__asm__ volatile (
		"xor %%rax, %%rax; test %%rdx, %%rdx; jz 1f;" //if survey ended badly, do not even try to convert
		"1: imul %%rdx, %%rax;"
		: "=a" (res)
		: "D" (str), "d" (survey)
		:
	);
	return (res);
}

int	ft_atoi(const char *str)
{
	return (convert(str, survey(str)));
}

#include<stdio.h>
int	main(void)
{
	printf("%d\n", ft_atoi("  	-123456"));
	// printf("%d", atoi("  	 --12345aaa6"));
	return (0);
}
