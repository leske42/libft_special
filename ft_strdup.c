/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:28:21 by mhuszar           #+#    #+#             */
/*   Updated: 2026/02/19 17:50:20 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*dst;

	len = ft_strlen(src) + 1;
	dst = malloc(len);
	if (dst)
		ft_strlcpy(dst, src, len);
	return (dst);
}

// #include<stdio.h>
// int	main(void)
// {
// 	printf("\e[2;40m%s", ft_strdup("Kalap kabat"));
// 	return (0);
// }
