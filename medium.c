/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyalcin@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 10:41:28 by zeyalcin          #+#    #+#             */
/*   Updated: 2026/09/27 11:20:10 by zeyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_sqrt(int n)
{
	int	i;

	i = 1;
	while (i * i < n)
		i++;
	if (i * i == n)
		return (i);
	return (i - 1);
}

static void	fill_stack_b(t_list **a, t_list **b,
		t_config *config, int size)
{
	int	chunk_range;
	int	c_beg;
	int	c_end;
	int	i;

	i = 0;
	chunk_range = get_sqrt(size);
	c_beg = 0;
	c_end = chunk_range;
	while (i < size)
	{
		if ((*a)->index >= c_beg && (*a)->index < c_end)
		{
			pb(a, b, config);
			i++;
		}
		else
			ra(a, config);
		if (i == c_end)
		{
			c_beg += chunk_range;
			c_end += chunk_range;
		}
	}
}

void	medium_sort(t_list **a, t_list **b, t_config *config)
{
	int	size;
	int	pos;
	int	i;

	i = 0;
	size = stack_size(*a);
	fill_stack_b(a, b, config, size);
	while (i < size)
	{
		pos = find_position(*b, size - 1 - i);
		if (pos == 0)
		{
			pa(a, b, config);
			i++;
		}
		else if (pos <= stack_size(*b) / 2)
			rb(b, config);
		else
			rrb(b, config);
	}
}
