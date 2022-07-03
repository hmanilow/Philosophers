/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:20:24 by hmanilow          #+#    #+#             */
/*   Updated: 2022/07/01 13:23:49 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	ft_atoi(char *s)
{
	long int	i;
	long int	k;

	i = 0;
	k = 0;
	while (s[i] <= '9' && s[i] >= '0')
	{
		k = (k * 10) + s[i] - '0';
		if (k > 2147483647)
			return (1);
		i++;
	}
	return ((int)k);
}

static int	ft_check_arg(char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] > '9' || argv[i][j] < '0')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_parse(int argc, char **argv, t_val *v)
{
	if (ft_check_arg(argv, argc))
		ft_exit("Arg error!\n", 1);
	if (argc == 6 || argc == 5)
	{
		v->philo_count = ft_atoi(argv[1]);
		v->die = ft_atoi(argv[2]);
		v->eat = ft_atoi(argv[3]);
		v->sleep = ft_atoi(argv[4]);
		v->repeating = -1;
		if (argc == 6)
			v->repeating = ft_atoi(argv[5]);
	}
	else
		ft_exit("Arg error!\n", 1);
	if (v->die == 0 || v->philo_count == 0 || v->sleep == 0
		|| v->eat == 0 || v->repeating == 0)
		ft_exit("Arg error!\n", 1);
	return (0);
}
