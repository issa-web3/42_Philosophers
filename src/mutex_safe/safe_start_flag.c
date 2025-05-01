/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_death_flag copy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:57:38 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/04/30 15:19:29 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	safe_get_start_flag(t_philo *philo)
{
	t_broadcasted_info	*info;
	int					result;

	info = philo->info;
	pthread_mutex_lock(&info->start_mutex);
	result = info->start_flag;
	pthread_mutex_unlock(&info->start_mutex);
	return (result);
}

void	safe_set_start_flag(t_philo *philo)
{
	t_broadcasted_info	*info;

	info = philo->info;
	pthread_mutex_lock(&info->start_mutex);
	info->start_flag = 1;
	pthread_mutex_unlock(&info->start_mutex);
}
