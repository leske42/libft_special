/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:20:18 by mhuszar           #+#    #+#             */
/*   Updated: 2026/02/20 21:16:34 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
R8 will be the flag if we are currently in the iteration of looking fwd or
bckwd. Therefore we always set DF based on R8 content. Otherwise setup is
easy: we load one char from the string, try to find it in SET string with
REPNE SCASB, as long as we find it we keep going. RDX starts with storing
full S1 string len, while we keep going we keep subtracting it, at the end
will give us the len to malloc. As soon as we find one char not in the SET,
we first save RSI to RBX as the BEGIN PTR, then we add RDX content to RSI
and like this jump to end end of the string. We set R8 so now me move
backwards. Otherwise logic is same for both periods.
For clean setup I had no choice but to leave RBX clobbered, but compiler
knows it was used based on parameters and will make sure to save/restore
around the block. Also needed to add this unit to NOREDZONE because of stack
usage.
*/

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*begin;
	size_t	len;
	char	*res;

	__asm__ volatile (
		"push %%rdi; push %%rcx; cld; xor %%r8, %%r8;"
		"0: test %%r8, %%r8; jz 1f; std;"
		"1: test %%rdx, %%rdx; jz 2f; dec %%rdx; lodsb;"
		"movq (%%rsp), %%rcx; movq 8(%%rsp), %%rdi; cld; repne scasb; jz 0b;"
		"test %%r8, %%r8; jnz 2f; mov %%rsi, %%rbx; dec %%rbx;"
		"add %%rdx, %%rsi; sub $2, %%rsi; not %%r8; jmp 0b;"
		"2: add $16, %%rsp; add $2, %%rdx; cld;"
		: "=b" (begin), "=d" (len)
		: "c" (ft_strlen(set)), "d" (ft_strlen(s1) + 1), "S" (s1), "D" (set)
		: "rax", "cc", "flags", "r8"
	);
	res = malloc(len);
	if (res)
		ft_strlcpy(res, begin, len);
	return (res);
}

// int	main(void)
// {
// 	printf("%s\n", ft_strtrim("/?***ubuntu//software\t**\t", "\t"));
// 	printf("%s\n", ft_strtrim("ubuntu//software", "ubntsofwear"));
// 	printf("%s\n", ft_strtrim("ubuntusoftware", "ubntsofwear"));
// 	return (0);
// }