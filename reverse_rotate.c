/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyalcin@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 10:41:19 by zeyalcin          #+#    #+#             */
/*   Updated: 2026/09/24 23:59:09 by zeyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_list **stack)
{
	t_list	*prev;
	t_list	*tail;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	prev = *stack;
	while (prev->next->next)
		prev = prev->next;
	tail = prev->next;
	prev->next = NULL;
	tail->next = *stack;
	*stack = tail;
}

void	rra(t_list **a, t_config *config)
{
	if (!a || !*a || !(*a)->next)
		return ;
	reverse_rotate(a);
	write(1, "rra\n", 4);
	config->stats.rra++;
	config->stats.total++;
}

void	rrb(t_list **b, t_config *config)
{
	if (!b || !*b || !(*b)->next)
		return ;
	reverse_rotate(b);
	write(1, "rrb\n", 4);
	config->stats.rrb++;
	config->stats.total++;
}

void	rrr(t_list **a, t_list **b, t_config *config)
{
	if ((!a || !*a || !(*a)->next) && (!b || !*b || !(*b)->next))
		return ;
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
	config->stats.rrr++;
	config->stats.total++;
}
