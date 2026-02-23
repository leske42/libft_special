/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:22:38 by mhuszar           #+#    #+#             */
/*   Updated: 2024/02/17 14:44:14 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	int	result;

	__asm__ volatile (
		"cmp $32, %1;"
		"jl 1f;"
		"cmp $127, %1;"
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
	printf("%d", ft_isprint(' '));
	return (0);
}*/
