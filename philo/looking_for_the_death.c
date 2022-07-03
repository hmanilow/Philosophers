/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   looking_for_the_death.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:47:36 by hmanilow          #+#    #+#             */
/*   Updated: 2022/05/23 15:59:06 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	ft_death_phil(t_phil *phil, long cur_time)
{
	*(phil->died) = e_true;
	pthread_mutex_unlock(phil->print_mut);
	printf("%ld %d is dead\n", cur_time, phil->id_phil);
	pthread_mutex_unlock(phil->print_mut);
	pthread_mutex_unlock(phil->right_f->forks);
	pthread_mutex_unlock(phil->left_f->forks);
}

void	*ft_check_death(void *d)
{
	t_death	*f_death;
	int		iu;
	long	cur_time;
	int		stop_eat;

	f_death = (t_death *)d;
	while (1)
	{
		iu = -1;
		stop_eat = 0;
		cur_time = ft_get_time() - f_death->this_phil[0].start_time;
		while (++iu < f_death->phil_number)
		{
			if (f_death->this_phil[iu].num_eating == 0)
				stop_eat++;
			if (f_death->this_phil[iu].last_eat
				+ f_death->this_phil[iu].die < cur_time)
			{
				ft_death_phil(&(f_death->this_phil[iu]), cur_time);
				return (NULL);
			}
		}
		if (stop_eat >= f_death->phil_number)
			return (NULL);
	}
}
