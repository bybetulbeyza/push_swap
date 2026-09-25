/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyalcin@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 23:20:41 by zeyalcin          #+#    #+#             */
/*   Updated: 2026/09/24 09:06:23 by zeyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*new_node(int value)
{
	t_list	*n;

	n = malloc(sizeof(t_list));
	if (!n)
		return (NULL);
	n->index = -1;
	n->value = value;
	n->next = NULL;
	return (n);
}

void	add_back(t_list **stack, t_list *new)
{
	t_list	*temp;

	temp = *stack;
	if (!(*stack))
	{
		*stack = new;
		return ;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

void	free_stack(t_list **stack)
{
	t_list	*temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
	*stack = NULL;
}

int	stack_size(t_list *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}
