#include "philosophers.h"

//int ft_forks(pthread_mutex_t *forks)
//{
//	pthread_mutex_lock(&forks);
//	printf("take forks");
//	pthread_mutex_unlock(&forks);
//	return 0;
//}

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

//	phil.death = e_true;
//	while (phil.death)
//	{
//		pthread_create();
//
//	}
//	while (1)
//	{
//		pthread_mutex_lock(&forks.forks);
//		printf();
//	}
	return 0;
}
