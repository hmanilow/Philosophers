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
	int				id_phil;
	long			cur_time;
	int				last_eat;
	int				num_eating;
	t_bool			died;
	t_val			*storage;
	t_pid			pid_id;
}				t_phil;

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