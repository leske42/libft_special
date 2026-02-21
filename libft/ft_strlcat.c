/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 20:56:38 by mhuszar           #+#    #+#             */
/*   Updated: 2025/10/02 23:03:28 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	counter;
	size_t	dest_proxy;

	counter = 0;
	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	dest_proxy = ft_strlen(dst);
	if (size <= dest_len)
		return (src_len + size);
	while (size > 0)
	{
		while (src[counter] && dest_proxy < size - 1)
		{
			dst[dest_proxy] = src[counter];
			counter++;
			dest_proxy++;
		}
		break ;
	}
	dst[dest_proxy] = '\0';
	return (src_len + dest_len);
}

// apple
// hehe
// 8

// happlehee

// applehe


#include<stdio.h>
#include <bsd/string.h>
int	main(void)
{
	char dst[15] = "apple";
	char src[4] = "hehe";
	// printf("%zu\n", ft_strlcat(dst, src, 2));
	// printf("%d", strlcat(dst, src, 2));
	strlcat(dst, src, 7);
	printf("%s", dst);
	//ft_strlcat(dst, src, 6);
	//printf("%s", dst);
	return (0);
}
