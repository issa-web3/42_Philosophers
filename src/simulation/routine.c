/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: test <test@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:57:38 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/05/07 14:37:53 by test             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	*routine(void *ptr)
{
	t_philo				*self;
	t_broadcasted_info	*info;

	self = ptr;
	info = self->info;
	wait_start_flag(info);
	while (safe_getter_setter(&info->death, GET, 314) == NOT_YET)
	{
		// routine
		printf("doing nothing %d\n", self->id);
	}
	
	return (NULL);
}

void	*shinigami_routine(void *ptr)
{
	t_broadcasted_info	*info;

	info = ptr;
	wait_start_flag(info);
	while (safe_getter_setter(&info->death, GET, 314) == NOT_YET)
	{
		// routine
		// b94_74d1{m47dk_h4d1n1_rb1_34t1n1}
		printf("doing nothing %d\n", 314);
	}
	
	return (NULL);
}
