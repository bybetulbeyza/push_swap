/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: betdemir@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 15:02:10 by betdemir          #+#    #+#             */
/*   Updated: 2026/09/25 17:46:14 by betdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stats(t_stats *stats)
{
	stats->total = 0;
	stats->sa = 0;
	stats->sb = 0;
	stats->ss = 0;
	stats->pa = 0;
	stats->pb = 0;
	stats->ra = 0;
	stats->rb = 0;
	stats->rr = 0;
	stats->rra = 0;
	stats->rrb = 0;
	stats->rrr = 0;
}

static void	execute_sort(t_list **a, t_list **b, t_config *config)
{
	if (is_sorted(*a))
		return ;
	assign_indexes(*a);
	if (config->mode == ADAPTIVE)
		adaptive_sort(a, b, config);
	else if (config->mode == SIMPLE)
		simple_sort(a, b, config);
	else if (config->mode == MEDIUM)
		medium_sort(a, b, config);
	else if (config->mode == COMPLEX)
		radix_sort(a, b, config);
}

int	main(int argc, char **argv)
{
	t_list		*a;
	t_list		*b;
	t_config	config;

	if (argc == 1)
		return (0);
	a = NULL;
	b = NULL;
	config.mode = ADAPTIVE;
	config.bench = 0;
	config.strategy_set = 0;
	init_stats(&config.stats);
	if (!parse_input(argc, argv, &a, &config))
	{
		write(2, "Error\n", 6);
		free_stack(&a);
		return (1);
	}
	execute_sort(&a, &b, &config);
	if (config.bench)
		print_benchmark(&config);
	free_stack(&a);
	return (0);
}