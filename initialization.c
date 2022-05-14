#include "philosophers.h"
#include <sys/time.h>

static int ft_fork_init(t_forks **forks_out, t_val *value)
{
	int				i;
	pthread_mutex_t	*fork_mutex;
	t_forks			*forks;

	forks = (t_forks *) malloc(sizeof(t_forks) * value->philo_count);
	fork_mutex = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t) *
			value->philo_count);
	if (!forks || !fork_mutex)
		return (1);
	i = 0;
	while (i < value->philo_count)
	{
		forks[i].fork_id = i;
		forks[i].use = e_false;
		forks[i].phil_id = -1;
		pthread_mutex_init(fork_mutex + i, NULL);
		forks[i].forks = fork_mutex + i;
		i++;
	}
	*forks_out = forks;
	return (0);
}

static int ft_philo_init(t_phil **phil_out, t_val *values, t_forks *forks)
{
	int i;
	long current_time;
	t_phil *phil;

	i = -1; //???
	phil = (t_phil *) malloc(sizeof(t_phil) * values->philo_count);
	if (!phil)
		return(1);
	current_time = ft_get_time();
	while (++i < values->philo_count)
	{
		phil[i].die = values->die;
		phil[i].eat = values->eat;
		phil[i].sleep = values->sleep;
		phil[i].id_phil = i;
		phil[i].last_eating_time = 0;
		phil[i].right_fork = forks + i;
		phil[i].left_fork = forks + (i + 1) % values->philo_count;
		phil[i].start_time =  current_time;
		phil[i].count_eating = values->eat;
	}
	*phil_out = phil;
	return (0);
}

int	ft_philo_forks_init(t_val *values, t_phil **phil_out, t_death *sbs_death)
{
	t_phil	*phil;
	t_bool	*death;
	t_forks *forks;
	int i;
	pthread_mutex_t *print_m;

	print_m = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t));
	death = (t_bool *)malloc(sizeof(t_bool));
	if (ft_fork_init(&forks, values) || ft_philo_init(&phil, values, forks)
		|| !print_m || !death)
		return (1);
	i =  -1;
	pthread_mutex_init(print_m, NULL);
	*death = e_false;
	while (++i < values->philo_count)
	{
		phil[i].must_die = death;
		phil[i].print_mutex = print_m;
		phil[i].current_time = 0;
	}
	*phil_out = phil;
	sbs_death->check_phil = phil;
	sbs_death->death = death;
	sbs_death->num_phil = values->philo_count;
	return (0);
}
