/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyalcin@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:11:59 by betdemir          #+#    #+#             */
/*   Updated: 2026/09/27 14:27:07 by zeyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_putstr_err(const char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

static void	ft_putnbr_err(long number)
{
	char	c;

	if (number < 0)
	{
		write(2, "-", 1);
		number *= -1;
	}
	if (number >= 10)
	{
		ft_putnbr_err(number / 10);
		ft_putnbr_err(number % 10);
	}
	else
	{
		c = number + '0';
		write(2, &c, 1);
	}
}

static void	print_disorder(double disorder)
{
	long	number;
	long	whole;
	long	frac;

	number = (long)(disorder * 10000 + 0.5);
	whole = number / 100;
	frac = number % 100;
	ft_putstr_err("[bench] disorder: ");
	ft_putnbr_err(whole);
	ft_putstr_err(".");
	if (frac < 10)
		ft_putstr_err("0");
	ft_putnbr_err(frac);
	ft_putstr_err("%\n");
}

static void	print_bench_infos(t_config *config)
{
	print_disorder(config->disorder);
	ft_putstr_err("[bench] strategy: ");
	if (config->mode == SIMPLE)
		ft_putstr_err("Simple / O(n^2)\n");
	else if (config->mode == MEDIUM)
		ft_putstr_err("Medium / O(n*sqrt(n))\n");
	else if (config->mode == COMPLEX)
		ft_putstr_err("Complex / O(n log n)\n");
	else
	{
		ft_putstr_err("Adaptive / ");
		if (config->disorder < 0.2)
			ft_putstr_err("O(n^2)\n");
		else if (config->disorder < 0.5)
			ft_putstr_err("O(n*sqrt(n))\n");
		else
			ft_putstr_err("O(n log n)\n");
	}
	ft_putstr_err("[bench] Total operations: ");
	ft_putnbr_err(config->stats.total);
	ft_putstr_err("\n");
}

void	print_benchmark(t_config *config)
{
	print_bench_infos(config);
	ft_putstr_err("[bench] sa: ");
	ft_putnbr_err(config->stats.sa);
	ft_putstr_err("\n[bench] sb: ");
	ft_putnbr_err(config->stats.sb);
	ft_putstr_err("\n[bench] ss: ");
	ft_putnbr_err(config->stats.ss);
	ft_putstr_err("\n[bench] pa: ");
	ft_putnbr_err(config->stats.pa);
	ft_putstr_err("\n[bench] pb: ");
	ft_putnbr_err(config->stats.pb);
	ft_putstr_err("\n[bench] ra: ");
	ft_putnbr_err(config->stats.ra);
	ft_putstr_err("\n[bench] rb: ");
	ft_putnbr_err(config->stats.rb);
	ft_putstr_err("\n[bench] rr: ");
	ft_putnbr_err(config->stats.rr);
	ft_putstr_err("\n[bench] rra: ");
	ft_putnbr_err(config->stats.rra);
	ft_putstr_err("\n[bench] rrb: ");
	ft_putnbr_err(config->stats.rrb);
	ft_putstr_err("\n[bench] rrr: ");
	ft_putnbr_err(config->stats.rrr);
	ft_putstr_err("\n");
}
