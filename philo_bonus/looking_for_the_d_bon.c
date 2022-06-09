#include "philo_bonus.h"

void ft_death_phil(t_phil *phil, long cur_time)
{
	phil->died = e_true;
	sem_wait(phil->storage->print_s);
	printf("%ld %d is died\n", cur_time, phil->id_phil);
	sem_post(phil->storage->print_s);
	sem_post(phil->storage->death_stop);
}

void *ft_checking_death(void *p)
{
	t_phil *phil;
	long cur_time;

	phil = (t_phil *)p;
	while (1)
	{
		sem_wait(phil->storage->died);
		cur_time = ft_get_time() - phil->storage->start_time;
		if (phil->last_eat + phil->storage->die < cur_time)
		{
			ft_death_phil(phil, cur_time);
			break;
		}
		sem_post(phil->storage->died);
		sem_wait(phil->storage->died);
		if (phil->num_eating == 0)
		{
			usleep(phil->storage->die * 1000);
			sem_post(phil->storage->death_stop);
			break;
		}
		sem_post(phil->storage->died);
	}
	return (NULL);
}