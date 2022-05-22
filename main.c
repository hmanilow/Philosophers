/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:47:43 by hmanilow          #+#    #+#             */
/*   Updated: 2022/05/21 15:49:24 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_thr_create(t_val *values, t_phil *phil, t_death *philo_death)
{
	int			i;
	pthread_t	*thread_id;
	pthread_t	death_thread;

	thread_id = (pthread_t *) malloc(sizeof(pthread_t) * values->philo_count);
	i = -1;
	if (pthread_create(&death_thread, NULL, ft_check_death, philo_death))
		return (1);
	while (++i < values->philo_count)
	{
		if (pthread_create(&(thread_id[i]), NULL,
				ft_phil_routine, &(phil[i])) != 0)
			return (1);
	}
	i = -1;
	if (pthread_join(death_thread, NULL))
		return (1);
	while (++i < values->philo_count)
	{
		if (pthread_join(thread_id[i], NULL) != 0)
			return (1);
	}
	free(thread_id);
	return (0);
}

static void	ft_point_destroyer(t_phil *phil, t_val *values)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(phil->print_mut);
	while (i < values->philo_count)
		pthread_mutex_destroy(phil[i++].right_f->forks);
	free(phil->right_f->forks);
	free(phil->right_f);
	free(phil->print_mut);
	free(phil->died);
	free(phil);
}

int	main(int argc, char **argv)
{
	t_val	values;
	t_phil	*phil;
	t_death	sbs_death;

	if (ft_parse(argc, argv, &values))
	{
		//printf("Arg error! You can use 4 or 5 arg.\n");
		return (ft_exit("Arg error! You can use 4 or 5 arg.\n", 1));
	}
	if (ft_philo_forks_init(&values, &phil, &sbs_death))
	{
		//printf("Init error\n");
		return (ft_exit("Init error\n", 1));
	}
	if (ft_thr_create(&values, phil, &sbs_death))
	{
		//printf("Thread error\n");
		return (ft_exit("Thread error\n", 1));
	}
	ft_point_destroyer(phil, &values);
	return (0);
}
