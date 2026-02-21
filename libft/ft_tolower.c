/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:10:21 by mhuszar           #+#    #+#             */
/*   Updated: 2024/02/17 16:01:31 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	int	result;

	__asm__ volatile (
		"mov %1, %0;"
		"cmp $65, %1;"
		"jl 1f;"
		"cmp $90, %1;"
		"jg 1f;"
		"add $32, %0;"
		"1:"
		: "=r" (result)
		: "r" (c)
		: "cc"
	);
	return (result);
}
/*
#include<stdio.h>
int	main(void)
{
	int a = ft_tolower('.');
	write(1, &a, 1);
}*/
