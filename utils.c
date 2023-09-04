/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastilh <acastilh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 20:15:39 by acastilh          #+#    #+#             */
/*   Updated: 2023/09/04 08:18:58 by acastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(char *str, t_const_philo *data, int pid)
{
	long long	time;

	pthread_mutex_lock(&data->writing);
	if (mealtime_ended(data->philo))
	{
		pthread_mutex_unlock(&data->writing);
		return ;
	}
	time = time_diff(time_ms(), data->first_time);
	printf("%lld %d %s\n", time, pid, str);
	pthread_mutex_unlock(&data->writing);
}

static int	check_max_int(long long n)
{
	if (n > MAX_INT)
	{
		return (-1);
	}
	return (n);
}

int	ft_atoi(const char *str)
{
	int			i;
	long long	number;
	int			signal;

	i = 0;
	number = 0;
	signal = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signal = signal * -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-42);
		number = number * 10;
		number = number + str[i] - 48;
		i++;
	}
	return (check_max_int(number * signal));
}
