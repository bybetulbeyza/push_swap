/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyalcin@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 14:11:33 by zeyalcin          #+#    #+#             */
/*   Updated: 2026/09/27 14:35:01 by zeyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	nb_bits(int size)
{
	int	bits;

	bits = 0;
	while ((1 << bits) < size)
		bits++;
	return (bits);
}

void	radix_sort(t_list **a, t_list **b, t_config *config)
{
	int	bits;
	int	bit;
	int	i;
	int	count;

	bits = nb_bits(stack_size(*a));
	bit = 0;
	while (bit < bits)
	{
		count = stack_size(*a);
		i = 0;
		while (i < count)
		{
			if (((*a)->index >> bit) & 1)
				ra(a, config);
			else
				pb(a, b, config);
			i++;
		}
		while (*b)
			pa(a, b, config);
		bit++;
	}
}