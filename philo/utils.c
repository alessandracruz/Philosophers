/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastilh <acastilh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 20:15:39 by acastilh          #+#    #+#             */
/*   Updated: 2023/09/06 19:58:17 by acastilh         ###   ########.fr       */
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

long int	ft_atol(const char *str)
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
	return (number * signal);
}
