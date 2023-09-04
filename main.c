/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastilh <acastilh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 21:42:20 by acastilh          #+#    #+#             */
/*   Updated: 2023/09/04 08:21:07 by acastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_const_philo	data;

	(void)(argv);
	if (argc < 5 || argc > 6)
		return (print_error("wrong number of arguments"));
	if (init_philo(argv, &data))
		return (print_error("incorrect data"));
	create_thread(&data);
	free_mutex(&data);
	return (0);
}
