/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:24:32 by mhuszar           #+#    #+#             */
/*   Updated: 2026/02/19 19:57:15 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	source_size;
	size_t	dest_size;
	char	*sub_str;

	source_size = ft_strlen(s);
	if (source_size < (start + len))
		dest_size = source_size - start;
	else
		dest_size = len;
	sub_str = malloc(dest_size + 1);
	if (sub_str)
		ft_strlcpy(sub_str, s + start, dest_size + 1);
	return (sub_str);
}

int	main(void)
{
	printf("%s\n", ft_substr("ubuntusoftware", 6, 4));
	printf("%s\n", ft_substr("hola", 4294967295, 0));
	printf("%s\n", ft_substr("hola", 2, 30));
	return (0);
}
