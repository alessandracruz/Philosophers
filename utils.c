/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acruz <acastilh@student.42.rio>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:28:31 by acruz             #+#    #+#             */
/*   Updated: 2023/03/19 20:51:44 by acruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_atoi(const char *str)
{
	int i;
	int number;
	int signal;

	i = 0;
	number = 0;
	signal = 1;

	while (str[i] == ' ' || (str[i] >= 0 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signal = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10;
		number = number + str[i] - 48;
		i++;
	}
	return (number * signal);
}

long long time_ms(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + time.tv_user / 1000);
}

long long time_diff(long long pres, long long past)
{
	return (pres - past);
}

void	fix_delay(long long time, t_const_philo *var)
{
	long long start;
	long long end;

	before = time_ms();
	while (var->died == 0)
	{
		start = time_ms();
		if (time_diff(start, before) >= time)
			break;
		usleep(50);
	}

}

void	print_action(t_const_philo *var, int id, char *string)
{
	pthread_mutex_lock(&(var->writing));
	if (var->died == 0)
	{
		printf("%llims ", time_ms() - var->first_time);
		printf("%i ", id + 1);
		printf("%s ", string);
	}
	pthread_mutex_unlock(&(var->writing));
	return;
}
