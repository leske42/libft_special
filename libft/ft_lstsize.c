/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:52:05 by mhuszar           #+#    #+#             */
/*   Updated: 2026/05/01 18:35:02 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	ctr;

	__asm__ volatile ("test %%rdi, %%rdi; jz 2f; 1: movq 8(%%rdi), %%rdi;"
		"inc %%rsi; test %%rdi, %%rdi; jnz 1b; 2:"
		: "+D" (lst), "=S" (ctr)
		: "1" (0)
		: "rcx", "memory", "cc"
	);
	return (ctr);
}
/*
#include <stdio.h>
int	main(void)
{
	char *str = "hehe";
	char *str2 = "ubuntusoftware";
	t_list *old_head = ft_lstnew((void *)str);
	t_list **list = &old_head;
	printf("List size: %d\n", ft_lstsize(*list));
	t_list *new_head = ft_lstnew((void *)str2);
	ft_lstadd_front(list, new_head);
	printf("List size: %d\n", ft_lstsize(*list));
	printf("List size: %d\n", ft_lstsize(NULL));
	free(new_head->next);
	free(new_head);
	return (0);
}*/
