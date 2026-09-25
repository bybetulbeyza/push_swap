/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyalcin@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 09:11:01 by zeyalcin          #+#    #+#             */
/*   Updated: 2026/09/24 10:56:53 by zeyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_list **a, t_config *config)
{
	if (!a || !*a || !(*a)->next)
		return ;
	swap(a);
	write(1, "sa\n", 3);
	config->stats.sa++;
	config->stats.total++;
}

void	sb(t_list **b, t_config *config)
{
	if (!b || !*b || !(*b)->next)
		return ;
	swap(b);
	write(1, "sb\n", 3);
	config->stats.sb++;
	config->stats.total++;
}

void	ss(t_list **a, t_list **b, t_config *config)
{
	if ((!a || !*a || !(*a)->next) && (!b || !*b || !(*b)->next))
		return ;
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
	config->stats.ss++;
	config->stats.total++;
}
