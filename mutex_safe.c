/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_safe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:57:38 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/05/11 14:36:29 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	safe_getter_setter(t_general_flag *flag, char action, long new_val)
{
	long	value;

	pthread_mutex_lock(&flag->mtx);
	if (action == SET)
		flag->value = new_val;
	value = flag->value;
	pthread_mutex_unlock(&flag->mtx);
	return (value);
}

void	print_action(t_philo *self, char *action)
{
	pthread_mutex_lock(&self->info->printing);
	if (safe_getter_setter(&self->info->death, GET, 314) == NOT_YET)
		printf("%ld %d %s\n", get_time_now(), self->id, action);
	if (*action == 'd')
		safe_getter_setter(&self->info->death, SET, YES);
	pthread_mutex_unlock(&self->info->printing);
}
