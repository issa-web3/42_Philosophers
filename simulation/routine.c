/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:57:38 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/05/15 15:27:47 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*routine(void *ptr)
{
	t_philo				*self;
	t_broadcasted_info	*info;

	self = ptr;
	info = self->info;
	if (wait_start_flag(info))
		return (NULL);
	if (self->id % 2 == 0)
		usleep(1000);
	while (safe_getter_setter(&info->death, GET, 314) == NOT_YET)
	{
		eating(self);
		if (eaten_enough(self, info->data))
			break ;
		sleeping(self);
		thinking(self);
	}
	return (NULL);
}

void	*shinigami_routine(void *ptr)
{
	t_broadcasted_info	*info;

	info = ptr;
	if (wait_start_flag(info))
		return (NULL);
	while (safe_getter_setter(&info->death, GET, 314) == NOT_YET)
	{
		if (death_or_all_eaten(info))
			safe_getter_setter(&info->death, SET, YES);
		usleep(10);
	}
	return (NULL);
}
