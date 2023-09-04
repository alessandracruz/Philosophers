/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastilh <acastilh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 00:55:59 by acastilh          #+#    #+#             */
/*   Updated: 2023/09/04 06:46:01 by acastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *p)
{
	pthread_mutex_lock(&p->data->forks[p->right_fork]);
	print("has taken a fork", p->data, p->id);
	if (p->data->num_philo != 1)
	{
		pthread_mutex_lock(&p->data->forks[p->left_fork]);
		print("has taken a fork", p->data, p->id);
		print("is eating", p->data, p->id);
		pthread_mutex_lock(&p->data->meal_check);
		p->last_eat = time_diff(time_ms(), p->data->first_time);
		pthread_mutex_unlock(&p->data->meal_check);
		p->ate++;
		fix_delay(p->data->time_eat);
		if (p->ate == p->data->nb_eat)
			p->data->total_ate++;
		pthread_mutex_unlock(&p->data->forks[p->left_fork]);
		pthread_mutex_unlock(&p->data->forks[p->right_fork]);
		return ;
	}
	pthread_mutex_unlock(&p->data->forks[p->right_fork]);
	return ;
}

int	mealtime_ended(t_philo *p)
{
	if (p->data->total_ate == p->data->num_philo)
		return (1);
	pthread_mutex_lock(&p->data->check_die);
	if (p->data->died == 1)
	{
		pthread_mutex_unlock(&p->data->check_die);
		return (1);
	}
	pthread_mutex_unlock(&p->data->check_die);
	return (0);
}

void	*routine(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	if (p->id % 2 == 0)
		usleep(800);
	while (!mealtime_ended(p) && p->ate != p->data->nb_eat)
	{
		eating(p);
		if (p->data->num_philo == 1)
			return (NULL);
		if (mealtime_ended(p))
			return (NULL);
		print("is sleeping", p->data, p->id);
		fix_delay(p->data->time_sleep);
		if (mealtime_ended(p))
			return (NULL);
		print("is thinking", p->data, p->id);
	}
	return (NULL);
}
