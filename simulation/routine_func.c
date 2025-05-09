/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:57:38 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/05/09 18:05:12 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	wait_start_flag(t_broadcasted_info *info)
{
	while (safe_getter_setter(&info->start, GET, 314) == NOT_YET)
		usleep(100);
}

void	eating(t_philo *self)
{
	pthread_mutex_lock(self->r_fork);
	print_action(self, "has taken a fork");
	if (self->r_fork == self->l_fork)
	{
		pthread_mutex_unlock(self->r_fork);
		ft_sleep(self, self->info->data.time_to_die);
		return ;
	}
	pthread_mutex_lock(self->l_fork);
	print_action(self, "has taken a fork");
	print_action(self, "is eating");
	ft_sleep(self, self->info->data.time_to_eat);
	pthread_mutex_unlock(self->r_fork);
	pthread_mutex_unlock(self->l_fork);
	safe_getter_setter(&self->last_time_eaten, SET, get_time_now());
	safe_getter_setter(&self->meals_num, SET, 
		safe_getter_setter(&self->meals_num, GET, 314) + 1
	);
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
