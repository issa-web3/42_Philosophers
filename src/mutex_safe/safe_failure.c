/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_failure.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:57:38 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/05/01 11:37:49 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	safe_get_fail_flag(t_philo *philo)
{
	t_broadcasted_info	*info;
	int					result;

	info = philo->info;
	pthread_mutex_lock(&info->fail_mutex);
	result = info->fail;
	pthread_mutex_unlock(&info->fail_mutex);
	return (result);
}

void	safe_set_fail_flag(t_philo *philo)
{
	t_broadcasted_info	*info;

	info = philo->info;
	pthread_mutex_lock(&info->fail_mutex);
	info->fail = 1;
	pthread_mutex_unlock(&info->fail_mutex);
}
