/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:52:05 by mhuszar           #+#    #+#             */
/*   Updated: 2026/05/01 20:52:18 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//static void up_case(void *data);

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*
static void up_case(void *data)
{
	char *str = (char *)data;
	while (*str)
	{
		*str = ft_toupper(*str);
		str++;
	}
}

#include <stdio.h>
int	main(void)
{
	char *str = ft_strdup("hehe");
	char *str2 = ft_strdup("ubuntusoftware");
	t_list *node1 = ft_lstnew((void *)str);
	t_list **list = &node1;
	t_list *node2 = ft_lstnew((void *)str2);
	ft_lstadd_back(list, node2);
	ft_lstiter(*list, up_case);
	printf("First node content: %s\n", (char*)(*list)->content);
	printf("Second node content: %s\n", (char*)(*list)->next->content);
	ft_lstclear(list, free);
	//should be a 0 bytes leaks!
	return (0);
}*/
