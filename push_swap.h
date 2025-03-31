/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:05:05 by alvera-v          #+#    #+#             */
/*   Updated: 2025/03/25 12:44:45 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h> // Includes int-max and int-min
# include <stddef.h> // Includes typedef

typedef struct stack {
	int             value;
    int             index;
    int             push_cost;
    bool            above_median;
    bool            cheapest;
    struct stack    *next; // el último del stack, su next debe apuntar a nulo o void.
    struct stack    *prev; // tengo que comprobar p¡con prev, que el prev del valor al que estoy apuntando sea NULL
    struct stack    *target_node;
} Stack;
int     main(int argc, char *argv[]);
int     ft_atoi(const char *nptr);
int     ft_isdigit(int c);
void	swap(Stack stack);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(char const *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
bool	check_char(char c);
int     count_string(char **s);
//char	*ft_strtrim(char const *s1, char const *set);
//void	*ft_calloc(size_t nmeb, size_t size);
//char	*ft_strdup(const char *s);
void	ft_bzero(void *s, size_t n);
//size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
//void	sort_numbers(Stack stack_a, Stack stack_b);

#endif
