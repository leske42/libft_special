/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:35:29 by mhuszar           #+#    #+#             */
/*   Updated: 2024/02/17 14:38:07 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	int	result;

	__asm__ volatile (
		"cmp $48, %1;"
		"jl 1f;"
		"cmp $58, %1;"
		"jl 2f;"
		"1:"
		"mov $0, %0;"
		"jmp 3f;"
		"2:"
		"mov $1, %0;"
		"3:"
		: "=r" (result)
		: "r" (c)
		: "cc"
	);
	return (result);
}
/*
#include<stdio.h>
int main(void)
{
	printf("%d", ft_isdigit('0'));
	return (0);
}*/
