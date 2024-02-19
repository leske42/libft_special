/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:19:51 by mhuszar           #+#    #+#             */
/*   Updated: 2024/02/17 15:46:52 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	__asm__ volatile (
	"movq $1, %%rax;"
	"movq %1, %%rdi;"
	"movq %0, %%rsi;"
	"movq $1, %%rdx;"
	"1:"
	"syscall;"
	"addq $1, %%rsi;"
	"movb (%%rsi), %%bl;"
	"testb %%bl, %%bl;"
	"jnz 1b;"
		:
		: "r" (s), "r" ((uint64_t) fd)
		: "rax", "rdi", "rsi", "rdx", "bl"
	);
}
/*
int main(void)
{
	char buf[717012];

	int fd = open("input.txt", 0);
	read(fd, buf, 717011);
	buf[717011] = '\0';
	ft_putstr_fd(buf, 1);
	return(0);
}*/
