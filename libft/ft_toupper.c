/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:10:06 by mhuszar           #+#    #+#             */
/*   Updated: 2024/02/17 16:03:08 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	int	result;

	__asm__ volatile (
		"mov %1, %0;"
		"cmp $97, %1;"
		"jl 1f;"
		"cmp $122, %1;"
		"jg 1f;"
		"sub $32, %0;"
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
	printf("%d", ft_toupper('z'));
}*/
