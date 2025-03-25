# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/25 10:32:25 by alvera-v          #+#    #+#              #
#    Updated: 2025/03/25 12:36:30 by alvera-v         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SOURCES =	push_swap.c \
			push_swap_utils.c \
			main.c

MY_OBJECTS = $(SOURCES:.c=.o)

LIBFT_DIR = ./Libft-main
FT_PRINTF_DIR = ./Libft_printf-main

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	@make -C $(LIBFT_DIR)
	@make -C $(FT_PRINTF_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(MY_OBJECTS) L$(LIBFT_DIR) -lft L$(FT_PRINTF_DIR) -lftprintf

clean:
	rm -f $(MY_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY = all clean fclean re
