/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:36:42 by mhuszar           #+#    #+#             */
/*   Updated: 2026/02/23 20:09:29 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	__attribute__((noreturn))	ft_exit(int status)
{
	__asm__ volatile (
		"mov $60, %%rax; syscall;"
		:
		: "D" (status)
		: "rax", "rcx", "r11", "cc", "memory"
	);
	__builtin_unreachable();
}

// int main(void)
// {
//     ft_exit(-1);
//     while (1)
//         ;
// }