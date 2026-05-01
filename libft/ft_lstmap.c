/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:52:05 by mhuszar           #+#    #+#             */
/*   Updated: 2026/05/01 20:52:21 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//static void	*low_case(void *data);

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*node;
	void	*cont;

	res = NULL;
	while (lst)
	{
		cont = f(lst->content);
		if (!cont)
			return (ft_lstclear(&res, del), NULL);
		node = ft_lstnew(cont);
		if (!node)
			return (ft_lstclear(&res, del), del(cont), NULL);
		ft_lstadd_back(&res, node);
		lst = lst->next;
	}
	return (res);
}
/*
static void	*low_case(void *data)
{
	int		ctr;
	char	*str;
	char	*res;

	ctr = 0;
	str = (char *)data;
	res = malloc(ft_strlen(str) + 1);
	if (!res)
		return (NULL);
	while (str[ctr])
	{
		res[ctr] = ft_tolower(str[ctr]);
		ctr++;
	}
	res[ctr] = '\0';
	return ((void *)res);
}

#include <stdio.h>
int	main(void)
{
	char *str = ft_strdup("HeHe");
	char *str2 = ft_strdup("uBUNTusoFTware");
	t_list *node1 = ft_lstnew((void *)str);
	t_list **list = &node1;
	t_list *node2 = ft_lstnew((void *)str2);
	ft_lstadd_back(list, node2);
	t_list *new_list = ft_lstmap(*list, low_case, free);
	printf("Size: %d\n", ft_lstsize(new_list));
	printf("First node content: %s\n", (char*)new_list->content);
	printf("Second node content: %s\n", (char*)new_list->next->content);
	ft_lstclear(list, free);
	ft_lstclear(&new_list, free);
	//should be a 0 bytes leaks!
	return (0);
}*/
