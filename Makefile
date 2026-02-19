# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 15:59:38 by mhuszar           #+#    #+#              #
#    Updated: 2026/02/19 19:15:28 by mhuszar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#hi, this is my first makefile, i hope it works
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SOURCE_STD = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c \
	ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
	ft_putstr_fd.c ft_strchr.c ft_strlen.c ft_strncmp.c ft_strrchr.c \
	ft_tolower.c ft_toupper.c ft_strdup.c ft_strmapi.c ft_striteri.c
SOURCE_RZ = ft_putendl_fd.c ft_putnbr_fd.c ft_strlcpy.c 
SOURCE = $(SOURCE_STD) $(SOURCE_RZ)
OBJECTS = $(SOURCE:.c=.o)

$(NAME): $(OBJECTS)
	ar -rc libft.a $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(SOURCE_RZ:.c=.o): CFLAGS += -mno-red-zone

all: $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
