/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:48:26 by hmanilow          #+#    #+#             */
/*   Updated: 2022/05/21 15:49:21 by hmanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef enum e_bool
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

typedef struct s_phil
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

typedef struct s_val
{
	int	philo_count;
	int	die;
	int	eat;
	int	sleep;
	int	repeating;
}				t_val;

typedef struct s_death
{
	t_phil	*this_phil;
	t_bool	*death;
	int		phil_number;
}				t_death;

int		ft_parse(int argc, char **argv, t_val *values);
int		ft_philo_forks_init(t_val *values, t_phil **phils, t_death *sbs_death);
void	*ft_phil_routine(void *p);
void	*ft_check_death(void *d);

void	ft_print_mes(t_phil *phil, char *mes);

int		ft_exit(char *str, int error);
long	ft_get_time(void);
void	ft_checking_usleep(long time_ms);

void	ft_putstr_fd(char *s, int fd);

#endif