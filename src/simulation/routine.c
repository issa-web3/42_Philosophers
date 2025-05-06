/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:57:38 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/05/06 11:44:50 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

static int	can_eat(t_philo *self, t_broadcasted_info *info)
{
	int	eaten_n;
	int	max;

	eaten_n = safe_get_meals_num(self);
	max = info->data.times_to_eat;
	if (eaten_n > safe_get_total_meals_num(self) / info->data.philos_num)
		return (0);
	return (eaten_n < max || max == -1);
}

void	*routine(void *ptr)
{
	t_philo				*self;
	t_broadcasted_info	*info;

	self = (t_philo *)ptr;
	info = self->info;
	while (!safe_get_start_flag(self) && !safe_get_fail_flag(self))
		usleep(100);
	if (safe_get_fail_flag(self))
		return (NULL);
	if (self->id % 2 == 0)
		usleep(1000);
	while (!safe_get_death_flag(self))
	{
		if (!can_eat(self, info))
			continue ;
		eat(self);
		zzz(self);
		think(self);
	}
	return (NULL);
}
