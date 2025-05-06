/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:57:38 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/05/06 11:57:26 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	think(t_philo *philo)
{
	safe_print(philo, "is thinking");
}

void	zzz(t_philo *philo)
{
	t_my_data	data;

	data = philo->info->data;
	safe_print(philo, "is sleeping");
	ft_sleep(philo, data.time_to_sleep);
}

void	sort_mutexes(mutex **m1, mutex **m2)
{
	mutex	*tmp;

	// fix the order issue
	if (*m1 > *m2)
	{
		tmp = *m1;
		*m1 = *m2;
		*m2 = tmp;
	}
}

void	eat(t_philo *philo)
{
	t_broadcasted_info	*info;
	t_philo				*philos;
	t_my_data			data;
	long				philos_num;
	mutex				*r_fork;
	mutex				*l_fork;

	info = philo->info;
	philos = info->philos;
	data = info->data;
	philos_num = data.philos_num;
	r_fork = &(philos + philo->id - 1)->eating_fork;
	l_fork = &(philos + (philo->id % philos_num))->eating_fork;
	sort_mutexes(&r_fork, &l_fork);
	pthread_mutex_lock(r_fork);
	safe_print(philo, "taken a fork");
	
	if (r_fork == l_fork)
	{
		pthread_mutex_unlock(r_fork);
		ft_sleep(philo, data.time_to_die);
		safe_print(philo, "died");
		safe_set_death_flag(philo);
		return ;
	}
	pthread_mutex_lock(l_fork);
	safe_print(philo, "taken a fork");
	safe_print(philo, "is eating");
	safe_set_time_eaten(philo);
	safe_inc_meals_num(philo);
	safe_inc_total_meals_num(philo);
	ft_sleep(philo, data.time_to_eat);
	pthread_mutex_unlock(r_fork);
	pthread_mutex_unlock(l_fork);
}
