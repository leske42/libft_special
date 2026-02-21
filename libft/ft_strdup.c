/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:28:21 by mhuszar           #+#    #+#             */
/*   Updated: 2026/02/20 22:43:51 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	return (ft_substr(src, 0, ft_strlen(src)));
}

// #include<stdio.h>
// int	main(void)
// {
// 	char *str = ft_strdup("Kalap kabat");
// 	printf("\e[2;40m%s\n", str);
// 	free(str);
// 	return (0);
// }
