/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 14:41:11 by mhuszar           #+#    #+#             */
/*   Updated: 2026/01/18 16:02:48 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include <string.h>

size_t  ft_strlen(const char *str);
int     ft_strcmp(const char *s1, const char *s2);

int main(void)
{
    char *str = "tralalalala";
    printf("Length of %s is: %zu\n", str, ft_strlen(str));
    char *str2 = "traf";
    printf("Difference of %s and %s is: %d\n", str, str2, ft_strcmp(str2, str2));
    // printf("Difference per original strcmp function: %d\n", strcmp(str, str2));
    return (0);
}