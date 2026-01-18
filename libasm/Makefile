# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 15:59:38 by mhuszar           #+#    #+#              #
#    Updated: 2026/01/18 14:52:28 by mhuszar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AS = nasm
CC = cc
ASFLAGS = -f elf64
NAME = libasm.a
SOURCE = hehe.s ft_strlen.s
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

re: fclean all

test: all
	$(CC) -g main.c $(NAME)
