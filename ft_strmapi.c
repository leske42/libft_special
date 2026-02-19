/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:43:44 by mhuszar           #+#    #+#             */
/*   Updated: 2026/02/19 19:16:04 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		counter;
	int		size;
	char	*result;

	counter = 0;
	size = ft_strlen((char *)s);
	result = ft_strdup((char *)s);
	if (result)
	{
		while (counter < size)
		{
			result[counter] = (*f)(counter, result[counter]);
			counter++;
		}
	}
	return (result);
}
/*
char letter_upcase(unsigned int index, char c)
{
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return (c);
}
//Why the hell do we need index though??

int main()
{
    const char *original_string = "Hello, World!";
    char *result_string = ft_strmapi(original_string, letter_upcase);
   
    printf("Original String: %s\n", original_string);
    if (result_string)
        printf("Modified String: %s\n", result_string);
    else
        return (0);
    return 0;
}*/
