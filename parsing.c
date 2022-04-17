#include "philosophers.h"

static int	ft_atoi(char *str)
{
	long int	i;
	long int	k;

	i = 0;
	k = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		k = (k * 10) + str[i] - '0';
		if (k > 2147483647)
			return (1);
		i++;
	}
	return ((int)k);
}

int ft_parse(int argc, char **argv, t_val *values)
{
	if (argc == 5 || argc == 6)
	{
		values->philo_amount = ft_atoi(argv[1]);
		values->die = ft_atoi(argv[2]);
		values->eat = ft_atoi(argv[3]);
		values->sleep = ft_atoi(argv[4]);
		values->repeating = -1;
		if (argc == 6)
			values->repeating = ft_atoi(argv[5]);
	}
	else
		return (1);
	return (0);
}
