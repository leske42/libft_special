/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:43:52 by mhuszar           #+#    #+#             */
/*   Updated: 2026/02/19 18:14:29 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	int	result;

	__asm__ volatile (
		"or %%rcx, %%rdx;"
		: "=d" (result)
		: "c" (ft_isdigit(c)), "d" (ft_isalpha(c))
		:
	);
	return (result);
}

// #include<stdio.h>
// int main(void)
// {
// 	printf("%d\n", ft_isalnum('9'));
// 	printf("%d\n", ft_isalnum('X'));
// 	printf("%d\n", ft_isalnum('!'));
// 	return (0);
// }
