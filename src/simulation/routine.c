/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:57:38 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/05/01 07:19:58 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	*routine(void *ptr)
{
	t_philo				*self;
	t_broadcasted_info	*info;

	self = (t_philo *)ptr;
	info = self->info;
	while (!safe_get_start_flag(self))
		usleep(100);
	if (self->id % 2 == 0)
		usleep(100);
	while (!safe_get_death_flag(self))
	{
		if (self->meals_num < info->data.times_to_eat || info->data.times_to_eat == -1)
			eat(self);
		zzz(self);
		think(self);
	}
	return (NULL);
}
