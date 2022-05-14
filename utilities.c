#include "philosophers.h"

long ft_get_time(void)
{
	struct timeval	cur_time;
	long time;

	gettimeofday(&cur_time, NULL);
	time = (cur_time.tv_sec * 1000) + (cur_time.tv_usec / 1000);
	return (time);
}
