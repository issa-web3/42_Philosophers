/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:57:38 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/04/29 15:20:09 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	*routine(void *ptr)
{
	t_philo				*self;
	t_broadcasted_info	*info;

	self = (t_philo *)ptr;
	info = self->info;
	while (!info->death_flag)
	{
		// eat
		// think
		// sleep
	}
	return (NULL);
}
