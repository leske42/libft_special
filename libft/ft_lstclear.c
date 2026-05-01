/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:52:05 by mhuszar           #+#    #+#             */
/*   Updated: 2026/05/01 19:51:36 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//passing NULL as lst is undefined
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*proxy;
	t_list	*tmp;

	proxy = *lst;
	while (proxy)
	{
		tmp = proxy->next;
		ft_lstdelone(proxy, del);
		proxy = tmp;
	}
}
/*
#include <stdio.h>
int	main(void)
{
	char *str = ft_strdup("hehe");
	char *str2 = ft_strdup("ubuntusoftware");
	t_list *node1 = ft_lstnew((void *)str);
	t_list **list = &node1;
	t_list *node2 = ft_lstnew((void *)str2);
	ft_lstadd_back(list, node2);
	ft_lstclear(list, free);
	//should be a 0 bytes leaks!
	return (0);
}*/
