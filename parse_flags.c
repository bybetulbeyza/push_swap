/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: betdemir@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 14:13:37 by zeyalcin          #+#    #+#             */
/*   Updated: 2026/09/25 16:49:08 by betdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

static int	set_strategy(t_config *config, t_mode mode)
{
	if (config->strategy_set)
		return (0);
	config->mode = mode;
	config->strategy_set = 1;
	return (1);
}

int	parse_flag(char *arg, t_config *config)
{
	if (!ft_strcmp(arg, "--bench"))
	{
		config->bench = 1;
		return (1);
	}
	if (!ft_strcmp(arg, "--simple"))
		return (set_strategy(config, SIMPLE));
	if (!ft_strcmp(arg, "--medium"))
		return (set_strategy(config, MEDIUM));
	if (!ft_strcmp(arg, "--complex"))
		return (set_strategy(config, COMPLEX));
	if (!ft_strcmp(arg, "--adaptive"))
		return (set_strategy(config, ADAPTIVE));
	return (0);
}