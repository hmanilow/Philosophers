#include "philosophers.h"

static void ft_point_destroyer(t_phil *phil, t_val *values)
{
	int i;

	i = 0;
	pthread_mutex_destroy(phil->print_mutex);
	while (i < values->philo_count)
		pthread_mutex_destroy(phil[i++].right_fork->forks);
	free(phil->right_fork->forks);
	free(phil->right_fork);
	free(phil->print_mutex);
	free(phil->must_die);
	free(phil);
}

static int ft_thr_create(t_val *values, t_phil *phil, t_death *philo_death)
{
	int i;
	pthread_t *thread_id;
	pthread_t thread_death;

	thread_id = (pthread_t *) malloc(sizeof(pthread_t) * values->philo_count);
	i = -1;
	if (pthread_create(&thread_death, NULL, ft_check_death, philo_death))
		return (1);
	while (++i < values->philo_count)
	{
		if (pthread_create(&(thread_id[i]), NULL, ft_philo_routine,
						   &(phil[i])) != 0)
			return (1);
	}
	i = -1;
	if (pthread_join(thread_death, NULL))
		return (1);
	while (++i < values->philo_count)
	{
		if (pthread_join(thread_id[i], NULL) != 0)
			return (1);
	}
	free(thread_id);
	return (0);
}

int main(int argc, char **argv)
{
	t_val	values;
	t_phil	phil;
	t_death	sbs_death;

	if (ft_parse(argc, argv, &values))
	{
		printf("Arg error! You can use 4 or 5 arg.\n");
		return (0);
	}
	if (ft_philo_forks_init(&values, &phil, &sbs_death))
	{
		printf("Init error\n");
		return (0);
	}
	if (ft_thr_create(&values, &phil, &sbs_death)) // phil no &
	{
		printf("Thread error\n");
		return (0);
	}
	ft_point_destroyer(&phil, &values); //phil no &
	return 0;
}
