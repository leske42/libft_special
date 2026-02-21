/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:10:34 by mhuszar           #+#    #+#             */
/*   Updated: 2023/09/06 17:10:37 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	counter_a;
	size_t	counter_b;

	counter_a = 0;
	counter_b = 0;
	if (little[0] == 0)
		return ((char *)big);
	while (big[counter_a] != 0 && little[counter_b] != 0)
	{
		while (big[counter_a] == little[counter_b])
		{
			counter_a++;
			counter_b++;
			if (counter_a > len)
				return (0);
			else if (little[counter_b] == '\0')
				return ((char *)big + counter_a - counter_b);
		}
		counter_a = (counter_a - counter_b) + 1;
		counter_b = 0;
	}
	return (0);
}
/*
int	main(void)
{
	char a[] = "12a45ababc90";
	char b[] = "abc";
	char *c = ft_strnstr(a, b, 12);
	printf("%s\n", c);
	c = ft_strnstr(a, b, 9);
	printf("%s", c);
	return (0);
}*/
