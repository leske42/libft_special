/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 14:41:11 by mhuszar           #+#    #+#             */
/*   Updated: 2026/01/18 18:24:41 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

size_t  ft_strlen(const char *str);
int     ft_strcmp(const char *s1, const char *s2);
char    *ft_strcpy(char *dest, const char *src);
char    *ft_strdup(const char *s);

//TODO: Look into
//https://learn.microsoft.com/en-us/cpp/build/stack-usage?view=msvc-170

int main(void)
{
    /*STRLEN TEST*/
    char *str = "12345678";
    printf("Length of %s is: %zu\n\n", str, ft_strlen(str));

    /*STRCMP TEST*/
    char *str2 = "123traf";
    printf("Difference of %s and %s is: %d\n", str, str2, ft_strcmp(str, str2));
    printf("Difference per original strcmp function: %d\n", strcmp(str, str2));
    printf("Difference of %s and %s is: %d\n", str2, str2, ft_strcmp(str2, str2));
    printf("Difference per original strcmp function: %d\n\n", strcmp(str2, str2));

    /*STRCPY TEST*/
    char dst[9];
    printf("Dest after copying: %s\n\n", ft_strcpy(dst, str));

    /*STRDUP TEST*/
    char *new_str = ft_strdup(str);
    printf("New duped str: %s\n\n", new_str);
    free(new_str);
    return (0);
}