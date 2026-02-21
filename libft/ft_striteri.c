/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:51:41 by mhuszar           #+#    #+#             */
/*   Updated: 2026/02/19 19:15:47 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	counter;

	counter = 0;
	while (s[counter])
	{
		(*f)(counter, &s[counter]);
		counter++;
	}
}
/*
void	letter_upcase(unsigned int index, char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c = (*c - 32);
    (void)index;
}

//Why the hell do we need index though??

int main()
{
    char string[100] = "Hello, World!";
    printf("Original String: %s\n", string);
    ft_striteri(string, letter_upcase);
    printf("Modified String: %s\n", string);
    return 0;
}
*/
/*
void custom_function(unsigned int index, char *c)
{
    printf("Character at index %u: %c\n", index, *c);
}

int main()
{
    //count_words("abcd abcd", ' ');
    char test_string[] = "Hello, World!";
    
    printf("Original String: %s\n", test_string);
    ft_striteri(test_string, custom_function);
    
    return 0;
}*/
