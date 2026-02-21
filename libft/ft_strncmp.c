/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 14:22:15 by mhuszar           #+#    #+#             */
/*   Updated: 2024/02/18 10:51:02 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	result;

	__asm__ volatile ("xorq %%rax, %%rax;"
		"xorq %%rbx, %%rbx;"
		"1:"
		"dec %3;"
		"js 2f;"
		"movb (%1), %%al;"
		"movb (%2), %%bl;"
		"cmpb  %%al, %%bl; jne 2f;"
		"testb %%al, %%al; jz 2f;"
		"testb %%bl, %%bl; jz 2f;"
		"inc %1;"
		"inc %2;"
		"jmp 1b;"
		"2:"
		"subb %%bl, %%al;"
		"movsx %%al, %%eax;"
		"movl %%eax, %0;"
		: "=r" (result)
		: "r" (s1), "r" (s2), "r" (n)
		: "rax", "rbx", "cc"
	);
	return (result);
}

/*
#include<unistd.h>
#include<string.h>
#include<stdio.h>
int	main(void)
{
	printf("%d\n", strncmp("apple", "apxle", 0));
	//write(1, "\n", 1);
	printf("%d\n", ft_strncmp("apple", "apxle", 0));
	return (0);
}*/
