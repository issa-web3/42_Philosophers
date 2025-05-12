/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:57:38 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/05/12 16:45:31 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	init_mtx(t_broadcasted_info *info)
{
	pthread_mutex_init(&info->death.mtx, NULL);
	info->death.value = NOT_YET;
	pthread_mutex_init(&info->start.mtx, NULL);
	info->start.value = NOT_YET;
	pthread_mutex_init(&info->printing, NULL);
}

static void	handle_failure(t_broadcasted_info *info, long fail_pnt)
{
	long	i;

	i = 0;
	while (i < fail_pnt - 1)
	{
		pthread_join(info->philos[i].thread, NULL);
		pthread_mutex_destroy(&info->philos[i].eating_fork);
		pthread_mutex_destroy(&info->philos[i].meals_num.mtx);
		i++;
	}
	pthread_mutex_destroy(&info->death.mtx);
	pthread_mutex_destroy(&info->start.mtx);
	write(2, "thread creation failed !!!\n", 27);
}

void	init_forks(t_broadcasted_info *info)
{
	t_philo	*curr;
	t_philo	*philos;
	long	i;
	long	num;

	i = -1;
	philos = info->philos;
	num = info->data.philos_num;
	while (++i < num)
	{
		curr = &philos[i];
		curr->r_fork = &curr->eating_fork;
		curr->l_fork = &(philos + (curr->id % num))->eating_fork;
		if (i == num - 1)
		{
			curr->l_fork = &curr->eating_fork;
			curr->r_fork = &(philos + (curr->id % num))->eating_fork;
		}
	}
}

int	init(t_broadcasted_info *info)
{
	int		fail;
	long	i;

	i = -1;
	fail = 0;
	init_mtx(info);
	while (++i < info->data.philos_num && !fail)
	{
		info->philos[i].id = i + 1;
		info->philos[i].info = info;
		info->philos[i].meals_num.value = 0;
		info->philos[i].last_time_eaten.value = get_time_now();
		pthread_mutex_init(&info->philos[i].eating_fork, NULL);
		pthread_mutex_init(&info->philos[i].meals_num.mtx, NULL);
		pthread_mutex_init(&info->philos[i].last_time_eaten.mtx, NULL);
		fail = pthread_create(&info->philos[i].thread, NULL,
				routine, &info->philos[i]) != 0;
	}
	if (fail)
		return (handle_failure(info, i), EXIT_FAILURE);
	fail = pthread_create(&info->shinigami, NULL, shinigami_routine, info) != 0;
	if (!fail)
		return (init_forks(info), EXIT_SUCCESS);
	pthread_join(info->shinigami, NULL);
	return (handle_failure(info, i), EXIT_FAILURE);
}

int	start_simulation(t_broadcasted_info *info)
{
	int	i;

	i = -1;
	safe_getter_setter(&info->start, SET, YES);
	pthread_join(info->shinigami, NULL);
	while (++i < info->data.philos_num)
		pthread_join(info->philos[i].thread, NULL);
	i = -1;
	while (++i < info->data.philos_num)
	{
		pthread_mutex_destroy(&info->philos[i].eating_fork);
		pthread_mutex_destroy(&info->philos[i].meals_num.mtx);
	}
	return (EXIT_SUCCESS);
}
