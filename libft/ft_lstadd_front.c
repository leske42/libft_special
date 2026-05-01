/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:52:05 by mhuszar           #+#    #+#             */
/*   Updated: 2026/05/01 18:21:47 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	__asm__ volatile ("test %%rdi, %%rdi; jz 1f;"
		"movq (%%rdi), %%rcx; movq %%rcx, 8(%%rsi);"
		"movq %%rsi, (%%rdi); 1:"
		: "+D" (lst), "+S" (new)
		:
		: "rcx", "memory", "cc"
	);
}
/*
#include <stdio.h>
int	main(void)
{
	char *str = "hehe";
	char *str2 = "ubuntusoftware";
	t_list *old_head = ft_lstnew((void *)str);
	t_list *new_head = ft_lstnew((void *)str2);
	t_list **list = &old_head;
	ft_lstadd_front(list, new_head);
	printf("New head content: %s, old head content: %s\n", //put bckslash
		(char *)(*list)->content, (char *)(*list)->next->content);
	free(new_head->next);
	free(new_head);
	return (0);
}*/
