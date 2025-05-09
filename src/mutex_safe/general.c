/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:57:38 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/05/09 15:26:06 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

long	safe_getter_setter(t_general_flag *flag, char action, long new_val)
{
	long	val;

	pthread_mutex_lock(&flag->mtx);
	if (action == SET)
		flag->value = new_val;
	val = flag->value;
	pthread_mutex_unlock(&flag->mtx);
	return (val);
}

void	print_action(t_philo *self, char *action)
{
	static int	death = NOT_YET;

	pthread_mutex_lock(&self->info->printing);
	if (death == NOT_YET)
		printf("%ld %d %s\n", get_time_now(), self->id, action);
	death |= *action == 'd';
	if (death == NOT_YET)
		pthread_mutex_unlock(&self->info->printing);
}
