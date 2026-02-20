/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 16:53:13 by mhuszar           #+#    #+#             */
/*   Updated: 2026/02/20 22:15:04 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


static size_t	count_words(const char *str, char c)
{
	size_t	words;

	//count words
	return (words);
}

static size_t	reposition(const char **str, char c)
{
	size_t	word_len;

	//modify string ptr to skip all c. return the count of all not-c from there
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
	}
	arr[ctr] = NULL;
	return (arr);
}
/*
int main(void)
{
	char **arr = ft_split("kalap,kabat,labda", 'a');
	printf("%s\n", arr[0]);
	printf("%s\n", arr[1]);
	printf("%s\n", arr[2]);
	return (0);
}*/
