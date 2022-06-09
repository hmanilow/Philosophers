#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <signal.h>
# include <semaphore.h>

typedef enum e_bool
{
	e_false,
	e_true
}				t_bool;

typedef struct s_val
{
	sem_t	*forks;
	sem_t	*print_s;
	sem_t 	*died;
	sem_t	*death_stop;
	int		philo_count;
	int		die;
	int		eat;
	int		sleep;
	int		repeating;
	long	start_time;
}				t_val;

typedef struct s_phil
{
	int		id_phil;
	long	cur_time;
	int		last_eat;
	int		num_eating;
	t_bool	died;
	t_val	*storage;
	pid_t	pid_id;
}				t_phil;

int		ft_parse(int argc, char **argv, t_val *values);
void	ft_init_sem(t_val *storage);
t_phil	*ft_philo_init(t_val *storage);
void	ft_phil_routine(t_phil *phil);
void	*ft_checking_death(void *d);
void	ft_point_destroyer(t_phil *phil, t_val *storage);

int		ft_exit(char *str, int error);
long	ft_get_time(void);
void	ft_checking_usleep(long time_ms);
void	ft_putstr_fd(char *s, int fd);
void	ft_print_mes(t_phil *phil, char *mes);

#endif