# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/25 10:32:25 by alvera-v          #+#    #+#              #
#    Updated: 2025/03/25 12:42:20 by alvera-v         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SOURCES =	push_swap.c \
		push_swap_utils.c \
		push_swap_sorting.c \
		push_swap_stack_utils.c \
		push_swap_operators.c \
		push_swap_appending.c \
		push_swap_operators_2.c

MY_OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(MY_OBJECTS)

clean:
	rm -f $(MY_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY = all clean fclean re
