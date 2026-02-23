/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:20:18 by mhuszar           #+#    #+#             */
/*   Updated: 2026/02/23 19:58:47 by mhuszar          ###   ########.fr       */
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

	__asm__ volatile (
		"push %%rsi; push %%rdi; push %%rcx; cld; xor %%r8, %%r8; inc %%rdx;"
		"0: test %%r8, %%r8; jz 1f; std;"
		"1: dec %%rdx; js 2f; lodsb;"
		"movq (%%rsp), %%rcx; movq 8(%%rsp), %%rdi; cld; repne scasb; jz 0b;"
		"test %%r8, %%r8; jnz 2f; mov %%rsi, %%rbx; dec %%rbx;"
		"lea -2(%%rsi, %%rdx, 1), %%rsi; not %%r8; jmp 0b;"
		"2: pop %%rcx; pop %%rdi; pop %%rsi; inc %%rdx; cld;"
		: "=b" (begin), "=d" (len), "+D" (set), "+S" (s1)
		: "c" (ft_strlen(set)), "1" (ft_strlen(s1))
		: "rax", "cc", "r8", "memory"
	);
	return (ft_substr(s1, begin - s1, len));
}

// int	main(void)
// {
// 	char *str = ft_strtrim("/?***ubuntu//software\t**\t", "\t");
// 	printf("%s\n", str);
// 	free(str);
// 	str = ft_strtrim("ubuntu//software", "ubntsofwear");
// 	printf("%s\n", str);
// 	free(str);
// 	str = ft_strtrim("ubuntusoftware", "ubntsofwear");
// 	printf("%s\n", str);
// 	free(str);
// 	str = ft_strtrim("", "lol");
// 	printf("%s\n", str);
// 	free(str);
// 	return (0);
// }