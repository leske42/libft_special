# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 15:59:38 by mhuszar           #+#    #+#              #
#    Updated: 2026/02/04 18:15:49 by mhuszar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --no-print-directory
AS = nasm
CC = cc
ASFLAGS = -f elf64 -g
NAME = libasm.a
SOURCE = hehe.s ft_strlen.s ft_strcmp.s ft_strcpy.s ft_strdup.s ft_write.s ft_read.s \
			ft_atoi_base.s ft_list.s ft_sort.s
OBJECTS = $(SOURCE:.s=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rc $(NAME) $(OBJECTS)

%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)
	-rm -f a.out

re: fclean all

bonus: all
	$(CC) -g -DBONUS=1 main.c $(NAME)
	./a.out
	@$(MAKE) clean > /dev/null

test: all
	$(CC) -g main.c $(NAME)
	./a.out
	@$(MAKE) clean > /dev/null

.PHONY: all clean fclean re bonus test
