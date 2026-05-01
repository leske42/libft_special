/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:52:05 by mhuszar           #+#    #+#             */
/*   Updated: 2026/05/01 19:17:33 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//treats lst being NULL as UB
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	__asm__	volatile ("test %%rdi, %%rdi; jz 2f;"
			"movq %%rsi, 8(%%rdi); 2:"
			: "=D" (lst), "+S" (new)
			: "D" (ft_lstlast(*lst))
			: "memory", "cc"
			);
}
/*
#include <stdio.h>
int	main(void)
{
	char *str = "hehe";
	char *str2 = "ubuntusoftware";
	t_list *old_tail = ft_lstnew((void *)str);
	t_list **list = &old_tail;
	t_list *new_tail = ft_lstnew((void *)str2);
	ft_lstadd_back(list, new_tail);
	printf("Head value: %s, tail value: %s\n", //put backslash
		(char*)(*list)->content,  (char*)((*list)->next->content));
	free(old_tail);
	free(new_tail);
	return (0);
}*/
