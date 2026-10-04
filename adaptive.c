/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: betdemir@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:11:55 by betdemir          #+#    #+#             */
/*   Updated: 2026/09/27 12:55:54 by betdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_sort(t_list **a, t_list **b, t_config *config)
{
	config->disorder = compute_disorder(*a);
	if (config->disorder < 0.2)
		simple_sort(a, b, config);
	else if (config->disorder < 0.5)
		medium_sort(a, b, config);
	else
		radix_sort(a, b, config);
}
