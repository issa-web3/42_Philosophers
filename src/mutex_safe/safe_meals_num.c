/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_meals_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:57:38 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/05/06 11:43:29 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	safe_get_meals_num(t_philo *philo)
{
	int	result;

	pthread_mutex_lock(&philo->meals_num_mutex);
	result = philo->meals_num;
	pthread_mutex_unlock(&philo->meals_num_mutex);
	return (result);
}

int	safe_get_total_meals_num(t_philo *philo)
{
	int	result;

	pthread_mutex_lock(&philo->info->total_meals_mtx);
	result = philo->info->total_meals_num;
	pthread_mutex_unlock(&philo->info->total_meals_mtx);
	return (result);
}

void	safe_inc_meals_num(t_philo *philo)
{
	pthread_mutex_lock(&philo->meals_num_mutex);
	philo->meals_num++;
	pthread_mutex_unlock(&philo->meals_num_mutex);
}

void	safe_inc_total_meals_num(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->total_meals_mtx);
	philo->info->total_meals_num++;
	pthread_mutex_unlock(&philo->info->total_meals_mtx);
}
