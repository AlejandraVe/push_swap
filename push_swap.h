/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:05:05 by alvera-v          #+#    #+#             */
/*   Updated: 2025/04/14 12:14:37 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h> // Includes int-max and int-min
# include <stdbool.h>
# include <stddef.h> // Includes typedef
# include <stdlib.h>
# include <unistd.h>

typedef struct stack {
	int             value;
    int             index;
    int             push_cost;
    bool            above_median;
    bool            cheapest;
    struct stack    *next; // el último del stack, su next debe apuntar a nulo o void.
    struct stack    *prev; // tengo que comprobar con prev, que el prev del valor al que estoy apuntando sea NULL
    struct stack    *target_node;
} Stack;
int     main(int argc, char *argv[]);
int     ft_atoi(const char *nptr);
int     ft_isdigit(int c);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(char const *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
bool	check_char(char c);
int     count_string(char **s);
bool    check_duplicates(char **s);
char	**many_strings(char *argv[]);
char	**handle_errors(int argc, char *argv[]);
//char	*ft_strtrim(char const *s1, char const *set);
//void	*ft_calloc(size_t nmeb, size_t size);
//char	*ft_strdup(const char *s);
//void	ft_bzero(void *s, size_t n);
//size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	sort_numbers(Stack **stack_a, Stack **stack_b);
Stack	*find_last(Stack *stack);
void    initialize_stack_a(Stack **stack_a, char *string[]);
bool    check_sorted(Stack *stack);
int     stack_len(Stack *stack);
Stack   *find_max(Stack *stack);
Stack	*find_min(Stack *stack);
void    sort_three_nodes(Stack **stack_a);
void    check_index(Stack *stack);
void    check_cost(Stack *stack_a, Stack *stack_b);
void    set_cheapest(Stack *stack);
Stack   *store_cheapest(Stack *stack);
void    check_rotation_both(Stack *a, Stack *b, Stack *cheapest);
void    check_rev_rotation_both(Stack *a, Stack *b, Stack *cheapest);
void	check_target_node_a(Stack *stack_a, Stack *stack_b);
Stack  *check_properties(Stack *stack_a, Stack *stack_b);
void	rr(Stack **stack_a, Stack **stack_b, bool print);
void	rb(Stack **stack_b, bool print);
void	ra(Stack **stack_a, bool print);
void	rra(Stack **stack_a, bool print);
void	rrb(Stack **stack_b, bool print);
void	rrr(Stack **stack_a, Stack **stack_b, bool print);
void    sa(Stack **stack_a, bool print);
void	sb(Stack **stack_b, bool print);
void	ss(Stack **stack_a, Stack **stack_b, bool print);
void	pa(Stack **stack_a, Stack **stack_b, bool print);
void	pb(Stack **stack_b, Stack **stack_a, bool print);


#endif
