/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:05:05 by alvera-v          #+#    #+#             */
/*   Updated: 2025/04/30 12:01:02 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h> // Includes int-max and int-min
# include <stdbool.h>
# include <stddef.h> // Includes typedef
# include <stdlib.h>
# include <unistd.h>

typedef struct stack
{
	int				value;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct stack *next;
	struct stack *prev;
	struct stack	*target_node;
}					Stack;
int					main(int argc, char *argv[]);
int					ft_atoi(const char *nptr);
int					ft_isdigit(int c);
char				**ft_split(char const *s, char c);
size_t				ft_strlen(char const *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);
bool				check_char(char c);
int					count_string(char **s);
bool				check_duplicates(char **s);
char				**many_strings(char *argv[]);
char				**handle_errors(int argc, char *argv[]);
void				sort_numbers(Stack **stack_a, Stack **stack_b);
Stack				*find_last(Stack *stack);
void				initialize_stack_a(Stack **stack_a, char *string[]);
bool				check_sorted(Stack *stack);
int					stack_len(Stack *stack);
Stack				*find_max(Stack *stack);
Stack				*find_min(Stack *stack);
void				sort_three_nodes(Stack **stack_a);
void				check_index(Stack *stack);
void				check_cost(Stack *pusher, Stack *receiver);
void				set_cheapest(Stack *stack);
Stack				*store_cheapest(Stack *stack);
void				check_rotation_both(Stack **a, Stack **b, Stack *cheapest);
void				check_rev_rotation_both(Stack **a, Stack **b,
						Stack *cheapest);
void				check_target_node_a(Stack *stack_a, Stack *stack_b);
void				check_properties(Stack *stack_a, Stack *stack_b);
void				check_rotation_a_above(Stack **a, Stack **b,
						Stack *cheapest);
void				check_rotation_b_above(Stack **a, Stack **b,
						Stack *cheapest);
void				b_to_a_both_above(Stack **a, Stack **b, Stack *cheapest);
void				b_to_a_both_below(Stack **a, Stack **b, Stack *cheapest);
void				b_below_to_a(Stack **a, Stack **b, Stack *cheapest);
void				b_above_to_a(Stack **a, Stack **b, Stack *cheapest);
void				begin_sort_b(Stack *a, Stack *b);
void				check_target_node_b(Stack *a, Stack *b);
void				rr(Stack **stack_a, Stack **stack_b, bool print);
void				rb(Stack **stack_b, bool print);
void				ra(Stack **stack_a, bool print);
void				rra(Stack **stack_a, bool print);
void				rrb(Stack **stack_b, bool print);
void				rrr(Stack **stack_a, Stack **stack_b, bool print);
void				sa(Stack **stack_a, bool print);
void				sb(Stack **stack_b, bool print);
void				ss(Stack **stack_a, Stack **stack_b, bool print);
void				pa(Stack **stack_a, Stack **stack_b, bool print);
void				pb(Stack **stack_b, Stack **stack_a, bool print);
void				min_at_top(Stack **stack_a);

#endif
