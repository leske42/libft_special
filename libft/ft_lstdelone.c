/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:52:05 by mhuszar           #+#    #+#             */
/*   Updated: 2026/05/01 19:46:14 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	del(lst->content);
	free(lst);
}
/*
#include <stdio.h>
int	main(void)
{
	char *str = ft_strdup("hehe");
	t_list *node = ft_lstnew((void *)str);
	ft_lstdelone(node, free);
	//should be a zero byte leaks!
	return (0);
}*/
