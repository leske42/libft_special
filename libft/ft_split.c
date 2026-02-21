/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 16:53:13 by mhuszar           #+#    #+#             */
/*   Updated: 2026/02/21 13:59:43 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *str, char c)
{
	size_t	words;

	__asm__ volatile (
		"1: lodsb; test %%al, %%al; jz 3f; cmp %%al, %%dl; jz 1b; inc %%rcx;"
		"2: lodsb; test %%al, %%al; jz 3f; cmp %%al, %%dl; jnz 2b; jmp 1b; 3:"
		: "=c" (words)
		: "S" (str), "d" (c), "c" (0)
		: "rax", "cc", "flags"
	);
	return (words);
}

//modify string ptr to skip all c. return the count of all not-c from there
static size_t	reposition(const char **str, char c)
{
	size_t	word_len;

	__asm__ volatile (
		"mov (%%rdi), %%rsi;"
		"1: lodsb; test %%al, %%al; jz 3f; cmp %%al, %%dl; jz 1b;"
		"dec %%rsi; mov %%rsi, (%%rdi);"
		"2: inc %%rcx; lodsb; test %%al, %%al; jz 3f; cmp %%al, %%dl; jnz 2b;"
		"3: xor %%rax, %%rax; dec %%rcx; cmovs %%rax, %%rcx;"
		: "=c" (word_len), "+D" (str)
		: "d" (c), "c" (0)
		: "rsi", "rax", "cc", "flags"
	);
	return (word_len);
}

static char	**free_everything(char **arr, int words)
{
	int	ctr;

	ctr = 0;
	while (ctr < words)
	{
		free(arr[ctr]);
		ctr++;
	}
	free(arr);
	return (0);
}

char	**ft_split(char const *str, char c)
{
	char	**arr;
	size_t	words;
	size_t	ctr;
	size_t	wordsize;

	words = count_words(str, c);
	arr = (char **)malloc(sizeof(char *) * (count_words(str, c) + 1));
	if (!arr)
		return (arr);
	ctr = 0;
	while (ctr < words)
	{
		wordsize = reposition(&str, c);
		arr[ctr] = ft_substr(str, 0, wordsize);
		if (!arr[ctr++])
			return (free_everything(arr, --ctr));
		str += wordsize;
	}
	arr[ctr] = NULL;
	return (arr);
}

// int main(void)
// {
// 	const char *str = ",,,kalap,,ka,bat,labda,,,";
// 	// printf("%zu\n", count_words(str, ','));
// 	// size_t wordsize, i;
// 	// wordsize = i = 1;
// 	// while (wordsize)
// 	// {
// 	// 	wordsize = reposition(&str, ',');
// 	// 	printf("Size of str nbr %zu: %zu, we are at: %s\n", i++, wordsize, str);
// 	// 	str += wordsize;
// 	// }
// 	char **arr = ft_split("kalap,kabat,labda", ',');
// 	printf("%s\n", arr[0]);
// 	printf("%s\n", arr[1]);
// 	printf("%s\n\n", arr[2]);
// 	free_everything(arr, 3);

// 	arr = ft_split("kalap,kabat,labda", 'a');
// 	printf("%s\n", arr[0]);
// 	printf("%s\n", arr[1]);
// 	printf("%s\n", arr[2]);
// 	free_everything(arr, 6);
// 	return (0);
// }
