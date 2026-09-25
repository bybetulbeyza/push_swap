/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: betdemir@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 22:55:15 by zeyalcin          #+#    #+#             */
/*   Updated: 2026/09/25 16:49:31 by betdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef enum e_mode
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX
}	t_mode;

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}	t_list;

typedef struct s_stats
{
	int	total;
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_stats;

typedef struct s_config
{
	t_mode	mode;
	int		bench;
	int		strategy_set;
	double	disorder;
	t_stats	stats;
}	t_config;

int	parse_input(int argc, char **argv, t_list **a, t_config *config);
int	parse_flag(char *arg, t_config *config);
int	is_number(char *str);
int	parse_int(char *str, int *value);
int	has_duplicate(t_list *a, int value);

t_list	*new_node(int value);
void	add_back(t_list **stack, t_list *new);
void	free_stack(t_list **stack);
int		stack_size(t_list *stack);
int		is_sorted(t_list *stack);

void	assign_indexes(t_list *stack);

void	sa(t_list **a, t_config *config);
void	sb(t_list **b, t_config *config);
void	ss(t_list **a, t_list **b, t_config *config);

void	pa(t_list **a, t_list **b, t_config *config);
void	pb(t_list **a, t_list **b, t_config *config);

void	ra(t_list **a, t_config *config);
void	rb(t_list **b, t_config *config);
void	rr(t_list **a, t_list **b, t_config *config);

void	rra(t_list **a, t_config *config);
void	rrb(t_list **b, t_config *config);
void	rrr(t_list **a, t_list **b, t_config *config);

double	compute_disorder(t_list *stack);

void	simple_sort(t_list **a, t_list **b, t_config *config);
void	medium_sort(t_list **a, t_list **b, t_config *config);
void	radix_sort(t_list **a, t_list **b, t_config *config);
void	adaptive_sort(t_list **a, t_list **b, t_config *config);

void	init_stats(t_stats *stats);
void	print_benchmark(t_config *config);

#endif
