# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 15:59:38 by mhuszar           #+#    #+#              #
#    Updated: 2026/01/18 22:51:19 by mhuszar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AS = nasm
CC = cc
ASFLAGS = -f elf64 -g
NAME = libasm.a
SOURCE = hehe.s ft_strlen.s ft_strcmp.s ft_strcpy.s ft_strdup.s ft_write.s ft_read.s \
			ft_atoi_base.s
OBJECTS = $(SOURCE:.s=.o)

$(NAME): $(OBJECTS)
	ar -rc $(NAME) $(OBJECTS)

%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)
	-rm -f a.out

re: fclean all

test: all
	$(CC) -g main.c $(NAME)
