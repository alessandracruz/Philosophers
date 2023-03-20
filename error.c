/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acruz <acastilh@student.42.rio>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 20:53:57 by acruz             #+#    #+#             */
/*   Updated: 2023/03/19 20:59:25 by acruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int print_error(char *str)
{
	printf("Error: ");
	printf("%s\n", str);
	return (1);
}