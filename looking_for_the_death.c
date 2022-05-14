#include "philosophers.h"

static void ft_death_phil(t_phil *phil, long cur_time)
{
	*(phil->must_die) = e_true;
	pthread_mutex_unlock(phil->print_mutex);
	printf("%ld %d is dead\n", cur_time, phil->id_phil);
	pthread_mutex_unlock(phil->print_mutex);
	pthread_mutex_unlock(phil->right_fork->forks);
	pthread_mutex_unlock(phil->left_fork->forks);
}

void *ft_check_death(void *d) //wtf
{
	t_death *death;
	int i;
	long cur_time;
	int stop_eating;

	death = (t_death *)d;
	while (1)
	{
		i = -1;
		stop_eating = 0;
		cur_time = ft_get_time() - death->check_phil[0].start_time;
		while (++i < death->num_phil)
		{
			if (death->check_phil[i].count_eating == 0)
				stop_eating++;
			if (death->check_phil[i].last_eating_time + death->check_phil[i]
			.die < cur_time)
			{
				ft_death_phil(&(death->check_phil[i]), cur_time);
				return (NULL);
			}
		}
		if (stop_eating >= death->num_phil) //wtf
			return (NULL);
	}
}
