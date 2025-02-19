/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:54:33 by mhuszar           #+#    #+#             */
/*   Updated: 2025/02/19 01:01:45 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**/
int ft_atoi(const char *str)
{
    int result;

    result = 0;
    __asm__ volatile (
        "xor %%rax, %%rax; xor %%rcx, %%rcx; xor %%r9, %%r9; movb (%%rsi), %%cl;"
        "1: cmpb $32, %%cl; je 2f; cmpb $9, %%cl; je 2f; cmpb $9, %%cl; je 2f;" //skip whitespace
        "jmp 3f; 2: inc %%rsi; movb (%%rsi), %%cl; jmp 1b;" //load next char
        "3: cmpb $'-', %%cl; jne 4f; movq $1, %%r9; movb $'+', %%cl;" //compare neg sign
        "4: cmpb $'+', %%cl; jne 5f;" //compare pos sign
        "inc %%rsi; movb (%%rsi), %%cl; 5:" //load next char
        "cmpb $'0', %%cl; jl 6f; cmpb $'9', %%cl; jg 6f;" //check for digit
        "subb $'0', %%cl; movq $10, %%r8; mulq %%r8; addq %%rcx, %%rax;"
        "inc %%rsi; movb (%%rsi), %%cl; jmp 5b;"
        "6: cmpq $0, %%r9; je 7f; imulq $-1, %%rax; 7:" //end of function
        : "=a" (result)
        : "S" (str)
        : "rcx", "r9", "r8"
    );
    return result;
}

#include<stdio.h>
int	main(void)
{
	printf("%d\n", ft_atoi("    -13f463f"));
	printf("%d\n", atoi("  	 --12345aaa6"));
	return (0);
}
