#include "philo_bonus.h"

void	ft_take_forks(t_phil *phil)
{
	sem_wait(phil->storage->forks);
	ft_print_mes(phil, "has taken right fork");
	sem_wait(phil->storage->forks);
	ft_print_mes(phil, "has taken left fork");
}

void	ft_phil_eat(t_phil *phil)
{
	ft_print_mes(phil, "is eating");
	ft_checking_usleep(phil->storage->eat);
	if (phil->num_eating != -1)
		phil->num_eating--;
	phil->last_eat = ft_get_time() - phil->storage->start_time;
	sem_post(phil->storage->forks);
	sem_post(phil->storage->forks);
}

void	ft_phil_sleep(t_phil *phil)
{
	ft_print_mes(phil, "is sleeping");
	ft_checking_usleep(phil->storage->sleep);
}

void	ft_phil_routine(t_phil *phil)
{
	pthread_t deaths_thread;

	if (pthread_create(&deaths_thread, NULL, ft_checking_death, phil))
		ft_exit("Trhead error", 1);
	if (phil->id_phil % 2 == 1)
		usleep(100);
	while (1)
	{
		ft_print_mes(phil, "is thinking");
		ft_take_forks(phil);
		if (phil->died == e_true)
			break ;
		ft_phil_eat(phil);
		if (phil->died == e_true)
			break ;
		ft_phil_sleep(phil);
		if (phil->num_eating == 0)
			break ;
		if (phil->died == e_true)
			break ;
	}
	if (pthread_join(deaths_thread, NULL))
		ft_exit("Thread error", 1);
	waitpid(phil->pid_id, NULL, 0);
	exit(0);
}
