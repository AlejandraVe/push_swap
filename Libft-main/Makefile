# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/10 12:07:00 by alvera-v          #+#    #+#              #
#    Updated: 2024/11/05 10:58:35 by alvera-v         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCES =	ft_isalnum.c \
			ft_isdigit.c \
			ft_isalpha.c \
			ft_strlen.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \

MY_OBJECTS = $(SOURCES:.c=.o)

B_SOURCES =	ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c

B_OBJECTS = $(B_SOURCES:.c=.o)

CFLAGS += -Wall -Wextra -Werror

CC = cc

all: $(NAME)

$(NAME):
		cc -c $(CFLAGS) $(SOURCES)
		ar rcs $(NAME) $(MY_OBJECTS)

bonus:
		cc -c $(CFLAGS) $(B_SOURCES) $(SOURCES)
		ar rcs $(NAME) $(B_OBJECTS) $(MY_OBJECTS)

clean:
	rm -f $(MY_OBJECTS) $(B_OBJECTS)

fclean: clean
	 rm -f $(NAME)

re: fclean all

.PHONY =	all clean fclean re bonus
