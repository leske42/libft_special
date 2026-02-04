/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 14:41:11 by mhuszar           #+#    #+#             */
/*   Updated: 2026/02/04 19:55:49 by mhuszar          ###   ########.fr       */
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
#ifdef BONUS
int     ft_atoi_base(char *str, char *base);
void    ft_list_push_front(t_list **begin_list, void *data);
void    ft_free_list(t_list *list);
int     ft_list_size(t_list *list);
void    ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));
void    ft_list_sort(t_list **begin_list, int (*cmp)());

void    ft_free_function(void *data)
{
    (void)data;
    printf("\n\"Freeing\" content: %s\n", (char *)data);
    return ;
}

void    ft_print_list(t_list *proxy)
{
    int counter = 1;
    while (proxy)
    {
        printf("Node number %d content: %s\n", counter++, (char*)proxy->data);
        proxy = proxy->next;
    }
}
#endif

//TODO: Look into
//https://learn.microsoft.com/en-us/cpp/build/stack-usage?view=msvc-170

int main(void)
{
    /*STRLEN TEST*/
    char *str = "12345678";
    printf("Length of %s is: %zu\n\n", str, ft_strlen(str));

    /*STRCMP TEST*/
    char *str2 = "123traf";
    if (!RUNNING_ON_VALGRIND) /*have to do this cause repne cmpsb is not supported before our patch is in release*/
    {
        printf("Difference of %s and %s is: %d\n", str, str2, ft_strcmp(str, str2));
        printf("Difference per original strcmp function: %d\n", strcmp(str, str2));
        printf("Difference of %s and %s is: %d\n", str2, str2, ft_strcmp(str2, str2));
        printf("Difference per original strcmp function: %d\n\n", strcmp(str2, str2));
    }

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

#ifdef BONUS
    /*ATOI BASE TEST*/
    char *test_str = "  \n      \t         +17321ll";
    printf("The int value for %s is: %d\n\n", test_str, ft_atoi_base(test_str, "0123456789"));
    char array[100] = "-10";
    printf("The int value for %s is: %d\n\n", array, ft_atoi_base(array, "01"));

    /*LIST TESTS*/
    t_list *first = malloc(sizeof(t_list));
    if (!first)
        return (1);
    char *init = "data6";
    first->data = (void*)init;
    first->next = NULL;
    char *strings[10] = {"data0", "data4", "data7", "data7", "data2", "data0", "data5", "data1", "data9", "data3"};
    t_list **list = &first;
    int ctr = 0;
    while (ctr < 10)
        ft_list_push_front(list, (void *)strings[ctr++]);
    printf("List size after push is: %d\n", ft_list_size(*list));
    ft_print_list(*list);
    if (!RUNNING_ON_VALGRIND)
    {
        ft_list_remove_if(list, (void *)strings[0], ft_strcmp, ft_free_function);
        printf("\nPrinting list after removing data:\n");
        ft_print_list(*list);
    }
    #include <string.h>
    ft_list_sort(list, strcmp);
    printf("\nPrinting sorted list:\n");
    ft_print_list(*list);
    ft_free_list(*list);
#endif
    return (0);
}