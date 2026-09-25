/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyalcin@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 10:41:31 by zeyalcin          #+#    #+#             */
/*   Updated: 2026/09/25 16:59:40 by zeyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_indexes(t_list *stack)
{
	t_list	*temp;
	t_list	*min;
	int		index;
	int		size;

	index = 0;
	size = stack_size(stack);
	while (index < size)
	{
		temp = stack;
		min = NULL;
		while (temp)
		{
			if (temp->index == -1 && (!min || temp->value < min->value))
				min = temp;
			temp = temp->next;
		}
		min->index = index;
		index++;
	}
}
