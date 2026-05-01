/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:52:05 by mhuszar           #+#    #+#             */
/*   Updated: 2026/05/01 18:10:30 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_head;

	new_head = malloc(16);
	__asm__ volatile ("test %%rdi, %%rdi; jz 1f;"
		"movq %%rsi, (%%rdi); movq $0, 8(%%rdi); 1:"
		: "+S" (content), "+D" (new_head)
		:
		: "memory", "cc"
	);
	return (new_head);
}
/*
#include <stdio.h>
int	main(void)
{
	char *str = "hehe";
	t_list *new_head = ft_lstnew((void *)str);
	printf("New head content: %s, new head next: %p\n", //put backlash
		(char *)new_head->content, new_head->next);
	free(new_head);
	return (0);
}*/
