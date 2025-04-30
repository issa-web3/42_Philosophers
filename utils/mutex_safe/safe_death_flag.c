/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_death_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:57:38 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/04/30 15:07:04 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	safe_get_death_flag(t_philo *philo)
{
	t_broadcasted_info	*info;
	int					result;

	info = philo->info;
	pthread_mutex_lock(&info->death_mutex);
	result = info->death_flag;
	pthread_mutex_unlock(&info->death_mutex);
	return (result);
}

void	safe_set_death_flag(t_philo *philo)
{
	t_broadcasted_info	*info;

	info = philo->info;
	pthread_mutex_lock(&info->death_mutex);
	info->death_flag = 1;
	pthread_mutex_unlock(&info->death_mutex);
}
