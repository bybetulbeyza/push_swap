/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyalcin@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 12:02:06 by zeyalcin          #+#    #+#             */
/*   Updated: 2026/09/25 12:22:06 by zeyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stack)
{
	if (!stack || !stack->next)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	find_min(t_list *stack)
{
	int min;

	min = stack->value;
	while(stack)
	{
		if(stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

int	find_max(t_list *stack)
{
	int max;

	max = stack->value;
	while(stack)
	{
		if(stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

int	find_position(t_list *stack, int index)
{
	int	i;

	if (!stack)
		return (-1);
	i = 0;
	while(stack)
	{
		if (stack->index == index)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}