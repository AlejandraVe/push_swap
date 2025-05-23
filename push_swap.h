/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:05:05 by alvera-v          #+#    #+#             */
/*   Updated: 2025/05/23 10:44:34 by alvera-v         ###   ########.fr       */
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
	struct stack	*next;
	struct stack	*prev;
	struct stack	*target_node;
}					t_Stack;
int					main(int argc, char *argv[]);
int					first_filter(char *argv[]);
void				start_sorting(t_Stack *stack_a, t_Stack *stack_b);
bool				one_string(char *argv[]);
char				**set_string(char **string, char **argv);
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
void				sort_numbers(t_Stack **stack_a, t_Stack **stack_b);
t_Stack				*find_last(t_Stack *stack);
void				initialize_stack_a(t_Stack **stack_a, char *string[]);
bool				check_sorted(t_Stack *stack);
int					stack_len(t_Stack *stack);
t_Stack				*find_max(t_Stack *stack);
t_Stack				*find_min(t_Stack *stack);
void				sort_three_nodes(t_Stack **stack_a);
void				check_index(t_Stack *stack);
void				check_cost(t_Stack *pusher, t_Stack *receiver);
void				set_cheapest(t_Stack *stack);
t_Stack				*store_cheapest(t_Stack *stack);
void				check_rotation_both(t_Stack **a, t_Stack **b,
						t_Stack *cheapest);
void				check_rev_rotation_both(t_Stack **a, t_Stack **b,
						t_Stack *cheapest);
void				check_target_node_a(t_Stack *stack_a, t_Stack *stack_b);
void				check_properties(t_Stack *stack_a, t_Stack *stack_b);
void				check_rotation_a_above(t_Stack **a, t_Stack **b,
						t_Stack *cheapest);
void				check_rotation_b_above(t_Stack **a, t_Stack **b,
						t_Stack *cheapest);
void				b_to_a_both_above(t_Stack **a, t_Stack **b,
						t_Stack *cheapest);
void				b_to_a_both_below(t_Stack **a, t_Stack **b,
						t_Stack *cheapest);
void				b_below_to_a(t_Stack **a, t_Stack **b, t_Stack *cheapest);
void				b_above_to_a(t_Stack **a, t_Stack **b, t_Stack *cheapest);
void				begin_sort_b(t_Stack *a, t_Stack *b);
void				check_target_node_b(t_Stack *a, t_Stack *b);
void				rr(t_Stack **stack_a, t_Stack **stack_b);
void				rb(t_Stack **stack_b);
void				ra(t_Stack **stack_a);
void				rra(t_Stack **stack_a);
void				rrb(t_Stack **stack_b);
void				rrr(t_Stack **stack_a, t_Stack **stack_b);
void				sa(t_Stack **stack_a);
void				sb(t_Stack **stack_b);
void				ss(t_Stack **stack_a, t_Stack **stack_b);
void				pa(t_Stack **stack_a, t_Stack **stack_b);
void				pb(t_Stack **stack_b, t_Stack **stack_a);
void				min_at_top(t_Stack **stack_a);
void				before_push(t_Stack **stack, t_Stack *top_node,
						char letter);

#endif
