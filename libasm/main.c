/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 14:41:11 by mhuszar           #+#    #+#             */
/*   Updated: 2026/01/24 21:22:01 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <valgrind/valgrind.h>

typedef struct t_list {
    void *data;
    struct t_list *next;
} t_list;

size_t  ft_strlen(const char *str);
int     ft_strcmp(const char *s1, const char *s2);
char    *ft_strcpy(char *dest, const char *src);
char    *ft_strdup(const char *s);
ssize_t ft_write(int fd, const void *buf, size_t count);
ssize_t ft_read(int fd, void *buf, size_t count);
//bonus functions
int     ft_atoi_base(char *str, char *base);
void    ft_list_push_front(t_list **begin_list, void *data);
void    ft_free_list(t_list *list);

//TODO: Look into
//https://learn.microsoft.com/en-us/cpp/build/stack-usage?view=msvc-170

int main(void)
{
    /*STRLEN TEST*/
    char *str = "12345678";
    printf("Length of %s is: %zu\n\n", str, ft_strlen(str));

    /*STRCMP TEST*/
    char *str2 = "123traf";
    // printf("Difference of %s and %s is: %d\n", str, str2, ft_strcmp(str, str2));
    // printf("Difference per original strcmp function: %d\n", strcmp(str, str2));
    // printf("Difference of %s and %s is: %d\n", str2, str2, ft_strcmp(str2, str2));
    // printf("Difference per original strcmp function: %d\n\n", strcmp(str2, str2));

    /*STRCPY TEST*/
    char dst[9];
    printf("Dest after copying: %s\n\n", ft_strcpy(dst, str));

    /*STRDUP TEST*/
    char *new_str = ft_strdup(str);
    printf("New duped str: %s\n\n", new_str);
    free(new_str);

    /*WRITE TEST*/
    ft_write(1, str, 8);
    ft_write(1, "\n", 1);
    close(2);
    int ret = ft_write(2, "fail", 4);
    printf("return value for FAIL_TEST is: %d, errno is set to: %s\n\n", ret, strerror(errno));

    /*READ TEST*/
    char buf[15];
    int fd = open("ft_read.s", O_RDONLY);
    ft_read(fd, buf, 14);
    buf[14] = 0;
    printf("The buffer after reading contains: %s\n", buf);
    printf("That's right ft_read was reading itself!!\n");
    char *hehe = NULL;
    VALGRIND_DISABLE_ERROR_REPORTING;
    ret = ft_read(fd, hehe, 14);
    VALGRIND_ENABLE_ERROR_REPORTING;
    printf("return value for FAIL_TEST is: %d, errno is set to: %s\n\n", ret, strerror(errno));
    close(fd);

    /*ATOI BASE TEST*/
    char *test_str = "  \n      \t         +17321ll";
    printf("The int value for %s is: %d\n\n", test_str, ft_atoi_base(test_str, "0123456789"));
    char array[100] = "-10";
    printf("The int value for %s is: %d\n\n", array, ft_atoi_base(array, "01"));

    /*LIST TESTS*/
    t_list *first = malloc(sizeof(t_list));
    if (!first)
        return (1);
    char *data1 = "data1";
    first->data = (void*)data1;
    first->next = NULL;
    char *data2 = "data2";
    t_list **list = &first;
    ft_list_push_front(list, (void *)data2);

    t_list *proxy = *list;
    int counter = 1;
    while (proxy)
    {
        printf("Node number %d content: %s\n", counter++, (char*)proxy->data);
        proxy = proxy->next;
    }
    ft_free_list(*list);
    return (0);
}