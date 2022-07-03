/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_do_phil_do.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:47:58 by hmanilow          #+#    #+#             */
/*   Updated: 2022/05/21 15:49:18 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	ft_put_the_forks(t_phil *phil)
{
	pthread_mutex_unlock(phil->right_f->forks);
	pthread_mutex_unlock(phil->left_f->forks);
}

static void	ft_take_forks(t_phil *phil)
{
	pthread_mutex_lock(phil->right_f->forks);
	if (*(phil->died) == e_true)
	{
		ft_put_the_forks(phil);
		return ;
	}
	phil->right_f->exploit = e_true;
	phil->right_f->phil_id = phil->id_phil;
	ft_print_mes(phil, "has taken right fork");
	pthread_mutex_lock(phil->left_f->forks);
	if (*(phil->died) == e_true)
	{
		ft_put_the_forks(phil);
		return ;
	}
	phil->left_f->exploit = e_true;
	phil->left_f->phil_id = phil->id_phil;
	ft_print_mes(phil, "has taken left fork");
}

static void	ft_phil_eat(t_phil *phil)
{
	if (phil->left_f->phil_id != phil->id_phil
		&& phil->right_f->phil_id != phil->id_phil)
		return ;
	ft_print_mes(phil, "is eating");
	ft_checking_usleep(phil->eat);
	if (phil->num_eating != -1)
		phil->num_eating--;
	pthread_mutex_unlock(phil->right_f->forks);
	phil->right_f->exploit = e_false;
	phil->right_f->phil_id = -1;
	pthread_mutex_unlock(phil->left_f->forks);
	phil->left_f->exploit = e_false;
	phil->left_f->phil_id = -1;
	phil->last_eat = ft_get_time() - phil->start_time;
}

static void	ft_phil_sleep(t_phil *phil)
{
	ft_print_mes(phil, "is sleeping");
	ft_checking_usleep(phil->sleep);
}

void	*ft_phil_routine(void *p)
{
	t_phil	*philo_date;

	philo_date = (t_phil *)p;
	if (philo_date->id_phil % 2 == 1)
		usleep(2500);
	while (1)
	{
		ft_print_mes(philo_date, "is thinking");
		if (*(philo_date->died) == e_true)
			break ;
		ft_take_forks(philo_date);
		if (*(philo_date->died) == e_true)
			break ;
		ft_phil_eat(philo_date);
		if (*(philo_date->died) == e_true)
			break ;
		ft_phil_sleep(philo_date);
		if (philo_date->num_eating == 0)
			break ;
		if (*(philo_date->died) == e_true)
			break ;
	}
	return (NULL);
}
