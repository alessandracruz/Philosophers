/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acruz <acastilh@student.42.rio>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:52:13 by acruz             #+#    #+#             */
/*   Updated: 2023/03/19 20:59:18 by acruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

struct const_philo;

typedef	struct philo
{
	int			id;
	int			ate;
	int			left_fork;
	int			right_fork;
	pthread_t	last_meal;
	struct		const_philo	*var;
}				t_philo;

typedef struct const_philo
{
	int				num_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				nb_eat;
	int				total_ate;
	int				died;
	long long		first_time;
	pthread_mutex_t	meal_check;
	pthread_mutex_t	forks[200];
	pthread_mutex_t	writing;
}				t_const_philo;

//UTILS

int			ft_atoi(const char *str);
long long	time_ms(void);
long long	time_diff(long long pres, long long past);
void		fix_delay(long long time, t_const *var);
void		print_action(t_const_philo *var, int id, char *string);

//ERROR

int	print_error(char *str);

#endif
