#include "philo_bonus.h"

int	ft_exit(char *str, int error)
{
	ft_putstr_fd(str, 2);
	return (error);
}

long	ft_get_time(void)
{
	struct timeval	cur_time;
	long			time;

	gettimeofday(&cur_time, NULL);
	time = (cur_time.tv_sec * 1000) + (cur_time.tv_usec / 1000);
	return (time);
}

void	ft_checking_usleep(long time_ms)
{
	long	start;
	long	cur;

	start = ft_get_time();
	cur = ft_get_time();
	while ((cur - start) < time_ms)
	{
		usleep(10);
		cur = ft_get_time();
	}
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i])
		i++;
	write(fd, s, i);
}

void	ft_print_mes(t_phil *phil, char *mes)
{
	long	cur_time;

	sem_wait(phil->storage->print_s);
	cur_time = ft_get_time();
	phil->cur_time = cur_time - phil->storage->start_time;
	if (phil->died == e_true)
	{
		sem_post(phil->storage->print_s);
		return ;
	}
	printf("%ld %d %s\n", phil->cur_time, phil->id_phil, mes);
	sem_post(phil->storage->print_s);
}
