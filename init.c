/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastilh <acastilh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 21:41:57 by acastilh          #+#    #+#             */
/*   Updated: 2023/09/04 06:36:26 by acastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	thread_philo(t_const_philo *data)
{
	int	i;

	i = 0;
	data->philo = malloc(sizeof(t_philo) * data->num_philo);
	if (data->philo == NULL)
		print_error("malloc fail");
	while (i < data->num_philo)
	{
		data->philo[i].id = i + 1;
		if (i == 0)
			data->philo[i].left_fork = data->num_philo - 1;
		else
			data->philo[i].left_fork = i - 1;
		if (i == data->num_philo)
			data->philo[i].right_fork = 0;
		else
			data->philo[i].right_fork = i;
		data->philo[i].last_eat = 0;
		data->philo[i].ate = 0;
		data->philo[i].data = data;
		i++;
	}
	return (0);
}

int	init_mutex(t_const_philo *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philo);
	if (data->forks == NULL)
		print_error("malloc fail");
	while (i < data->num_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			print_error("mutex fail");
		i++;
	}
	if (pthread_mutex_init(&data->meal_check, NULL) != 0)
		print_error("mutex fail");
	if (pthread_mutex_init(&data->writing, NULL) != 0)
		print_error("mutex fail");
	return (0);
}

int	init_philo(char **argv, t_const_philo *data)
{
	data->num_philo = ft_atoi(argv[1]);
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	if (data->num_philo <= 0 || data->time_die <= 0 || \
	data->time_eat <= 0 || data->time_sleep <= 0)
		return (1);
	if (argv[5])
	{
		data->nb_eat = ft_atoi(argv[5]);
		if (data->nb_eat <= 0)
			return (1);
	}
	else
		data->nb_eat = -5;
	data->died = 0;
	if (init_mutex(data))
		return (1);
	if (thread_philo(data))
		return (1);
	data->total_ate = 0;
	data->first_time = time_ms();
	return (0);
}
