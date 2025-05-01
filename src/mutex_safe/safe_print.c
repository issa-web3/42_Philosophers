/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:57:38 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/05/01 07:46:55 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	safe_print(t_philo *philo, char *action)
{
	t_broadcasted_info	*info;

	info = philo->info;
	if (safe_get_death_flag(philo))
		return ;
	pthread_mutex_lock(&info->printing_mutex);
	printf("%ld %d %s\n", get_time_now(), philo->id, action);
	pthread_mutex_unlock(&info->printing_mutex);
}
