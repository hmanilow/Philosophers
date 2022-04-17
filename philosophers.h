#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

typedef enum	e_bool
{
	e_true,
	e_false
}				t_bool;

typedef struct s_forks
{
	pthread_mutex_t *forks;
	int				phil_id;
	int				fork_id;
	t_bool			use;
}				t_forks;

typedef struct	s_val
{
	int	philo_amount;
	int	die;
	int eat;
	int sleep;
	int repeating;
}				t_val;

typedef struct	s_phil
{
	pthread_t		id_phil;
	t_forks			*right_fork;
	t_forks			*left_fork;
	pthread_t		id_thread;
	int				die;
	int				eat;
	int				sleep;
	long			start_time;
	long			current_time;
	int				last_eating_time;
	t_bool			*must_die;
	int				count_eating;
	pthread_mutex_t	*print_mutex;
}				t_phil;

typedef struct	s_death
{
	t_phil	*check_phil;
	t_bool	*death;
	int		num_phil;
}				t_death;

//int	ft_strncmp(const char *s1, const char *s2);
int ft_forks(pthread_mutex_t *forks);
int ft_parse(int argc, char **argv, t_val *values);
int	ft_philo_forks_init(t_val *values, t_phil **phil_out, t_death *sbs_death);

#endif
