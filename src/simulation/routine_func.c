/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:57:38 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/05/07 20:16:03 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	wait_start_flag(t_broadcasted_info *info)
{
	while (safe_getter_setter(&info->start, GET, 314) == NOT_YET)
		usleep(100);
}

void	sort_mutexes(mutex **m1, mutex **m2)
{
	mutex	*tmp;

	if (*m1 > *m2)
	{
		tmp = *m1;
		*m1 = *m2;
		*m2 = tmp;
	}
}

void	eating(t_philo *self)
{
	mutex			*r_fork;
	mutex			*l_fork;
	t_philo			*philos;
	long			num;

	num = self->info->data.philos_num;
	philos = self->info->philos;
	r_fork = &self->eating_fork;
	l_fork = &(philos + (self->id % num))->eating_fork;
	sort_mutexes(&r_fork, &l_fork);
	pthread_mutex_lock(r_fork);
	print_action(self, "has taken a fork");
	if (r_fork == l_fork)
	{
		pthread_mutex_unlock(r_fork);
		ft_sleep(self, self->info->data.time_to_die);
		return ;
	}
	pthread_mutex_lock(l_fork);
	print_action(self, "has taken a fork");
	print_action(self, "is eating");
	ft_sleep(self, self->info->data.time_to_eat);
	safe_getter_setter(&self->meals_num, SET, 
		safe_getter_setter(&self->meals_num, GET, 314) + 1
	);
	safe_getter_setter(&self->last_time_eaten, SET, get_time_now());
	pthread_mutex_unlock(r_fork);
	pthread_mutex_unlock(l_fork);
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
