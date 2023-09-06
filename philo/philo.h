/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastilh <acastilh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 20:15:02 by acastilh          #+#    #+#             */
/*   Updated: 2023/09/06 19:45:12 by acastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648

struct	s_const_philo;

typedef struct s_philo
{
	int							id;
	int							ate;
	int							left_fork;
	int							right_fork;
	long long					last_eat;
	pthread_t					tid;
	struct s_const_philo		*data;
}				t_philo;

typedef struct s_const_philo
{
	long int		num_philo;
	long int		time_die;
	long int		time_eat;
	long int		time_sleep;
	long int		nb_eat;
	int				total_ate;
	int				died;
	long long		first_time;
	t_philo			*philo;
	pthread_mutex_t	meal_check;
	pthread_mutex_t	*forks;
	pthread_mutex_t	writing;
	pthread_mutex_t	check_die;
}				t_const_philo;

//UTILS

long int	ft_atol(const char *str);
void		print(char *str, t_const_philo *data, int pid);

//TIME

long long	time_ms(void);
long long	time_diff(long long pres, long long past);
void		fix_delay(long long time);

//ERROR

int			print_error(char *str);

//INIT

int			thread_philo(t_const_philo *data);
int			init_mutex(t_const_philo *data);
int			init_philo(char **argv, t_const_philo *data);

//PHILO

void		monitor_philo(t_const_philo *data);
void		*create_thread(t_const_philo *data);
void		free_mutex(t_const_philo *data);

//ROUTINE

void		eating(t_philo *p);
int			mealtime_ended(t_philo *p);
void		*routine(void *philo);

#endif
