# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/25 10:32:25 by alvera-v          #+#    #+#              #
#    Updated: 2025/05/07 13:34:15 by alvera-v         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SOURCES =	push_swap.c \
			handle_errors.c \
			push_swap_utils.c \
			push_swap_utils_2.c \
			sorting.c \
			stack_utils.c \
			push_swap_appendings.c \
			swap_command.c \
			rotate_command.c \
			reverse_rotate_command.c \
			push_command.c \
			check_reverse_rotation.c \
			check_rotation.c \
			push_swap_costs.c \
			sort_stack_b.c

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
