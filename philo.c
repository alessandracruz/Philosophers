/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastilh <acastilh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 00:44:16 by acastilh          #+#    #+#             */
/*   Updated: 2023/09/04 04:37:17 by acastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_mutex(t_const_philo *data)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&data->check_die);
	pthread_mutex_destroy(&data->meal_check);
	pthread_mutex_destroy(&data->writing);
	while (i < data->num_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	free (data->forks);
	free (data->philo);
}

int	check_philosopher_death(t_const_philo *data, int i, long long end_eat)
{
	if (data->nb_eat && (data->total_ate == data->num_philo))
		return (1);
	if (time_diff(time_ms(), data->first_time) > \
		end_eat + data->time_die)
	{
		pthread_mutex_lock(&data->check_die);
		data->died = 1;
		pthread_mutex_unlock(&data->check_die);
		printf("%lld %d died\n", \
		time_diff(time_ms(), data->first_time), data->philo[i].id);
		return (1);
	}
	return (0);
}

void	monitor_philo(t_const_philo *data)
{
	int			i;
	long long	end_eat;

	while (1)
	{
		i = -1;
		while (++i < data->num_philo)
		{
			pthread_mutex_lock(&data->meal_check);
			end_eat = data->philo[i].last_eat;
			pthread_mutex_unlock(&data->meal_check);
			if (check_philosopher_death(data, i, end_eat))
				return ;
		}
		usleep(20);
	}
}

void	*create_thread(t_const_philo *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		if (pthread_create(&data->philo[i].tid, NULL, routine, \
		&data->philo[i]) != 0)
			return (NULL);
		i++;
	}
	monitor_philo(data);
	i = -1;
	while (++i < data->num_philo)
		pthread_join(data->philo[i].tid, NULL);
	return (NULL);
}
