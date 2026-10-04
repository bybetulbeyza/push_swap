/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: betdemir@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 14:11:21 by zeyalcin          #+#    #+#             */
/*   Updated: 2026/09/27 13:16:51 by betdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotator(t_list **a, t_config *config, int size, int position)
{
	if (position <= size / 2)
	{
		while (position > 0)
		{
			ra(a, config);
			position--;
		}
	}
	else
	{
		while (position < size)
		{
			rra(a, config);
			position++;
		}
	}
}

void	simple_sort(t_list **a, t_list **b, t_config *config)
{
	int		size;
	int		position;
	int		target;
	t_list	*temp;

	target = 0;
	size = stack_size(*a);
	while (target < size)
	{
		temp = *a;
		position = 0;
		while (temp && temp->index != target)
		{
			temp = temp->next;
			position++;
		}
		rotator(a, config, stack_size(*a), position);
		pb(a, b, config);
		target++;
	}
	while (*b)
		pa(a, b, config);
}
