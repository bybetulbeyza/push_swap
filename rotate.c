/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyalcin@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 10:41:15 by zeyalcin          #+#    #+#             */
/*   Updated: 2026/09/24 22:33:54 by zeyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	head = *stack;
	tail = *stack;
	while (tail->next)
		tail = tail->next;
	tail->next = head;
	tail = head;
	head = head->next;
	tail->next = NULL;
	*stack = head;
}

void	ra(t_list **a, t_config *config)
{
	if (!a || !*a || !(*a)->next)
		return ;
	rotate(a);
	write(1, "ra\n", 3);
	config->stats.ra++;
	config->stats.total++;
}

void	rb(t_list **b, t_config *config)
{
	if (!b || !*b || !(*b)->next)
		return ;
	rotate(b);
	write(1, "rb\n", 3);
	config->stats.rb++;
	config->stats.total++;
}

void	rr(t_list **a, t_list **b, t_config *config)
{
	if ((!a || !*a || !(*a)->next) && (!b || !*b || !(*b)->next))
		return ;
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
	config->stats.rr++;
	config->stats.total++;
}
