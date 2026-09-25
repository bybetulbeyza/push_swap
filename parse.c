/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: betdemir@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 14:04:38 by zeyalcin          #+#    #+#             */
/*   Updated: 2026/09/25 17:04:22 by betdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	process_number(char *arg, t_list **a)
{
	int		value;
	t_list	*new;

	if (!is_number(arg) || !parse_int(arg, &value))
		return (0);
	if (has_duplicate(*a, value))
		return (0);
	new = new_node(value);
	if (!new)
		return (0);
	add_back(a, new);
	return (1);
}

int	parse_input(int argc, char **argv, t_list **a, t_config *config)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			if (!parse_flag(argv[i], config))
				return (0);
		}
		else
		{
			if (!process_number(argv[i], a))
				return (0);
		}
		i++;
	}
	return (1);
}
