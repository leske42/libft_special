/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:27:00 by mhuszar           #+#    #+#             */
/*   Updated: 2024/02/17 14:30:19 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	int	result;

	__asm__ volatile (
		"cmp $65, %1;"
		"jl 1f;"
		"cmp $91, %1;"
		"jl 2f;"
		"cmp $97, %1;"
		"jl 1f;"
		"cmp $123, %1;"
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
	printf("%d", ft_isalpha('A'));
	return (0);
}*/
