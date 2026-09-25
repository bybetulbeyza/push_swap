/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyalcin@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 10:40:21 by zeyalcin          #+#    #+#             */
/*   Updated: 2026/09/24 22:22:49 by zeyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **a, t_list **b, t_config *config)
{
	t_list	*node;

	if (!b || !*b)
		return ;
	node = *b;
	*b = (*b)->next;
	node->next = *a;
	*a = node;
	write(1, "pa\n", 3);
	config->stats.pa++;
	config->stats.total++;
}

void	pb(t_list **a, t_list **b, t_config *config)
{
	t_list	*node;

	if (!a || !*a)
		return ;
	node = *a;
	*a = (*a)->next;
	node->next = *b;
	*b = node;
	write(1, "pb\n", 3);
	config->stats.pb++;
	config->stats.total++;
}
