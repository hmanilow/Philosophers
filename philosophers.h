#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

typedef enum	e_bool
{
	e_false,
	e_true
}				t_bool;

typedef struct s_forks
{
	pthread_mutex_t	*forks;
	int				phil_id;
	int				fork_id;
	t_bool			exploit;
}				t_forks;

typedef struct	s_val
{
	int	philo_count;
	int	die;
	int eat;
	int sleep;
	int repeating;
}				t_val;

typedef struct	s_phil
{
	int				id_phil;
	t_forks			*right_f;
	t_forks			*left_f;
	pthread_t		thread_id;
	int				die;
	int				eat;
	int				sleep;
	long			start_time;
	long			cur_time;
	int				last_eat;
	t_bool			*died;
	int				num_eating;
	pthread_mutex_t	*print_mut;
}				t_phil;

typedef struct	s_death
{
	t_phil	*this_phil;
	t_bool	*death;
	int		phil_number;
}				t_death;

int ft_parse(int argc, char **argv, t_val *values);
int	ft_philo_forks_init(t_val *values, t_phil **phils, t_death *sbs_death);
void *ft_phil_routine(void *p);
void *ft_check_death(void *d);

void ft_print_mes(t_phil *phil, char *mes);

long ft_get_time(void);
void ft_checking_usleep(long time_ms);

#endif
