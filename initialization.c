/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:47:28 by hmanilow          #+#    #+#             */
/*   Updated: 2022/05/23 15:58:54 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_fork_init(t_forks **forkss, t_val *value)
{
	int				i;
	pthread_mutex_t	*fork_mutex;
	t_forks			*forks;

	forks = (t_forks *) malloc(sizeof(t_forks) * value->philo_count);
	fork_mutex = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t)
			* value->philo_count);
	if (!forks || !fork_mutex)
		return (1);
	i = 0;
	while (i < value->philo_count)
	{
		forks[i].fork_id = i;
		forks[i].exploit = e_false;
		forks[i].phil_id = -1;
		pthread_mutex_init(fork_mutex + i, NULL);
		forks[i].forks = fork_mutex + i;
		i++;
	}
	*forkss = forks;
	return (0);
}

static int	ft_philo_init(t_phil **phils, t_val *values, t_forks *forks)
{
	int		i;
	long	cur_time;
	t_phil	*phil;

	i = -1;
	phil = (t_phil *) malloc(sizeof(t_phil) * values->philo_count);
	if (!phil)
		return (1);
	cur_time = ft_get_time();
	while (++i < values->philo_count)
	{
		phil[i].die = values->die;
		phil[i].eat = values->eat;
		phil[i].sleep = values->sleep;
		phil[i].id_phil = i;
		phil[i].last_eat = 0;
		phil[i].right_f = forks + i;
		phil[i].left_f = forks + (i + 1) % values->philo_count;
		phil[i].start_time = cur_time;
		phil[i].num_eating = values->repeating;
	}
	*phils = phil;
	return (0);
}

int	ft_philo_forks_init(t_val *values, t_phil **phils, t_death *sbs_death)
{
	t_phil			*phil;
	t_bool			*f_death;
	t_forks			*forks;
	int				i;
	pthread_mutex_t	*print_mut;

	print_mut = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t));
	f_death = (t_bool *)malloc(sizeof(t_bool));
	if (ft_fork_init(&forks, values) || ft_philo_init(&phil, values, forks)
		|| !print_mut || !f_death)
		return (1);
	i = -1;
	pthread_mutex_init(print_mut, NULL);
	*f_death = e_false;
	while (++i < values->philo_count)
	{
		phil[i].died = f_death;
		phil[i].print_mut = print_mut;
		phil[i].cur_time = 0;
	}
	*phils = phil;
	sbs_death->this_phil = phil;
	sbs_death->death = f_death;
	sbs_death->phil_number = values->philo_count;
	return (0);
}
