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

#include "philo_bonus.h"

void ft_init_sem(t_val *storage)
{
	sem_unlink("forks");
	sem_unlink("died");
	sem_unlink("print_s");
	sem_unlink("death_stop");
	storage->forks = sem_open("forks", O_CREAT, 0700, storage->philo_count);
	if (storage->forks == SEM_FAILED)
		ft_exit("SEM error 1\n", 1);
	storage->died = sem_open("died", O_CREAT, 0700, 1);
	if (storage->died == SEM_FAILED)
		ft_exit("SEM error 2\n", 1);
	storage->print_s = sem_open("print_s", O_CREAT, 0700, 1);
	if (storage->print_s == SEM_FAILED)
		ft_exit("SEM error 3\n", 1);
	storage->death_stop = sem_open("death_stop", O_CREAT, 0700, 1);
	if (storage->death_stop == SEM_FAILED)
		ft_exit("SEM error 4\n", 1);
}

static int	ft_philo_init(t_val *storage)
{
	int		i;
	t_phil	*phil;

	phil = (t_phil *) malloc(sizeof(t_phil) * storage->philo_count);
	if (!phil)
		ft_exit("Malloc_error\n", 1);
	i = 0;
	while (i < storage->philo_count)
	{
		phil[i].id_phil = i;
		phil[i].last_eat = 0;
		phil[i].cur_time = 0;
		phil[i].died = e_false;
		phil[i].num_eating = storage->repeating;
		phil[i].storage = storage;
		phil[i].pid_id = -1;
		i++;
	}
	return (philo);
}
