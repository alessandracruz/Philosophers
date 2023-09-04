/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastilh <acastilh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 22:44:59 by acastilh          #+#    #+#             */
/*   Updated: 2023/09/04 06:59:34 by acastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	time_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + time.tv_usec / 1000);
}

long long	time_diff(long long pres, long long past)
{
	return (pres - past);
}

void	fix_delay(long long time)
{
	long long	before;
	long long	now;

	before = time_ms();
	while (1)
	{
		now = time_ms();
		if (time_diff(now, before) >= time)
			break ;
		usleep (100);
	}
}
