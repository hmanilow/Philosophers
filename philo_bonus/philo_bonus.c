/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:21:13 by hmanilow          #+#    #+#             */
/*   Updated: 2022/07/01 13:23:53 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_point_destroyer(t_phil *phil, t_val *storage)
{
	int	i;

	i = 0;
	while (i < storage->philo_count)
	{
		kill(phil[i].pid_id, SIGKILL);
		i++;
	}
	sem_close(storage->forks);
	sem_close(storage->died);
	sem_close(storage->print_s);
	sem_close(storage->death_stop);
	sem_unlink("forks");
	sem_unlink("died");
	sem_unlink("print_s");
	sem_unlink("death_stop");
	free(phil);
}

void	ft_create_proc(t_val *storage, t_phil *phil)
{
	int	i;

	i = 0;
	while (i < storage->philo_count)
	{
		phil[i].pid_id = fork();
		if (phil[i].pid_id == 0)
		{
			ft_phil_routine(phil + i);
			exit(0);
		}
		i++;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	t_val	storage;
	t_phil	*phil;

	ft_parse(argc, argv, &storage);
	ft_init_sem(&storage);
	phil = ft_philo_init(&storage);
	storage.start_time = ft_get_time();
	sem_wait(storage.death_stop);
	ft_create_proc(&storage, phil);
	sem_wait(storage.death_stop);
	ft_point_destroyer(phil, &storage);
	exit(0);
}
