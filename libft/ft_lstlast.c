/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:52:05 by mhuszar           #+#    #+#             */
/*   Updated: 2026/05/01 18:47:42 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*res;

	__asm__ volatile ("test %%rdi, %%rdi; jz 2f; 1: mov %%rdi, %%rsi;"
		"movq 8(%%rdi), %%rdi; test %%rdi, %%rdi; jnz 1b; 2:"
		: "=S" (res), "+D" (lst)
		:
		: "memory", "cc"
	);
	return (res);
}
/*
#include <stdio.h>
int	main(void)
{
	char *str = "hehe";
	char *str2 = "ubuntusoftware";
	t_list *old_head = ft_lstnew((void *)str);
	t_list **list = &old_head;
	t_list *new_head = ft_lstnew((void *)str2);
	ft_lstadd_front(list, new_head);
	printf("Last element value: %s\n", (char*)ft_lstlast(*list)->content);
	free(new_head->next);
	free(new_head);
	return (0);
}*/
