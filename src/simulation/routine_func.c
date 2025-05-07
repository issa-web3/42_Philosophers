/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: test <test@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:57:38 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/05/07 16:05:15 by test             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	wait_start_flag(t_broadcasted_info *info)
{
	while (safe_getter_setter(&info->start, GET, 314) == NOT_YET)
		usleep(100);
}

void	eating(t_philo *self)
{
	
}
void	thinking(t_philo *self)
{
	print_action(self, "is thinking");
}
void	sleeping(t_philo *self)
{
	print_action(self, "is sleeping");
	ft_sleep(self, self->info->data.time_to_sleep);
}
