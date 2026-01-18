# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 15:59:38 by mhuszar           #+#    #+#              #
#    Updated: 2026/01/18 14:32:15 by mhuszar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AS = nasm
ASFLAGS = -f elf64
NAME = libasm.a
SOURCE = hehe.s
OBJECTS = $(SOURCE:.s=.o)

$(NAME): $(OBJECTS)
	ar -rc libft.a $(OBJECTS)

%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
