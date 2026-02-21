/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:54:33 by mhuszar           #+#    #+#             */
/*   Updated: 2026/02/21 15:28:00 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
labels are numbered for O3 and thus lack description, but function as follows:
1 - skip whitespace
2 - compare negative sign
3 - compare positive sign
4 - load next char for number compare
5 - check for valid digit value and transform
6 - epilogue if we have no more digits. make negatives negative.
7 - end of function
*/
int	ft_atoi(const char *str)
{
	int	result;

	__asm__ volatile ("xor %%r9, %%r9;"
		"1: movb (%%rsi), %%cl; inc %%rsi; cmpb $32, %%cl; je 1b;"
		"cmpb $9, %%cl; jl 7f; cmpb $13, %%cl; jl 1b;"
		"2: cmpb $'-', %%cl; jne 3f; not %%r9; movb $'+', %%cl;"
		"3: cmpb $'+', %%cl; jne 5f;"
		"4: movb (%%rsi), %%cl; inc %%rsi;"
		"5: cmpb $'0', %%cl; jl 6f; cmpb $'9', %%cl; jg 6f;"
		"subb $'0', %%cl; movq $10, %%r8; mulq %%r8; addq %%rcx, %%rax; jmp 4b;"
		"6: test %%r9, %%r9; jz 7f; imulq $-1, %%rax; 7:"
		: "=a" (result)
		: "S" (str), "a" (0), "c" (0), "d" (0)
		: "r9", "r8", "cc", "flags"
	);
	return (result);
}

// #include<stdio.h>
// int	main(void)
// {
// 	printf("%d\n", ft_atoi("    -13f463f"));
// 	printf("%d\n", atoi("  	 --12345aaa6"));
// 	printf("%d\n", atoi("  	 aaaaaa"));
// 	printf("%d\n", atoi("  	 --aaa6"));
// 	        return (0);
// }
