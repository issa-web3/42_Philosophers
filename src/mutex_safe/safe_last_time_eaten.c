/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_last_time_eaten.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:57:38 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/05/01 10:11:36 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	safe_get_time_eaten(t_philo *philo)
{
	int	result;

	pthread_mutex_lock(&philo->last_time_eaten_mutex);
	result = philo->last_time_eaten;
	pthread_mutex_unlock(&philo->last_time_eaten_mutex);
	return (result);
}

void	safe_set_time_eaten(t_philo *philo)
{
	pthread_mutex_lock(&philo->last_time_eaten_mutex);
	philo->last_time_eaten = get_time_now();
	pthread_mutex_unlock(&philo->last_time_eaten_mutex);
}
