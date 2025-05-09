/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:57:38 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/05/09 16:11:43 by ioulkhir         ###   ########.fr       */
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

int	init(t_broadcasted_info *info)
{
	int		fail;
	long	i;
	long	j;

	i = 0;
	j = 0;
	fail = 0;
	init_mtx(info);
	while (i < info->data.philos_num && !fail)
	{
		info->philos[i].id = i + 1;
		info->philos[i].info = info;
		info->philos[i].meals_num.value = 0;
		info->philos[i].last_time_eaten.value = get_time_now();
		pthread_mutex_init(&info->philos[i].eating_fork, NULL);
		pthread_mutex_init(&info->philos[i].meals_num.mtx, NULL);
		pthread_mutex_init(&info->philos[i].last_time_eaten.mtx, NULL);
		fail = pthread_create(&info->philos[i].thread, NULL, routine, &info->philos[i]) != 0;
		i++;
	}
	fail |= !fail && pthread_create(&info->shinigami, NULL, shinigami_routine, info) != 0;
	if (!fail)
		return (EXIT_SUCCESS);
	while (j < i - 1)
	{
		pthread_detach(info->philos[j].thread);
		pthread_mutex_destroy(&info->philos[j].eating_fork);
		pthread_mutex_destroy(&info->philos[j].meals_num.mtx);
		j++;
	}
	pthread_mutex_destroy(&info->death.mtx);
	pthread_mutex_destroy(&info->start.mtx);
	pthread_detach(info->shinigami); // we need to make sure the shinigami is not created in the first place
	write(2, "thread creation failed !!!\n", 27);
	return (EXIT_FAILURE);
}

int	start_simulation(t_broadcasted_info *info)
{
	int	i;

	i = -1;
	safe_getter_setter(&info->start, SET, YES);
	pthread_join(info->shinigami, NULL);
	while (++i < info->data.philos_num)
	{
		pthread_detach(info->philos[i].thread);
		pthread_mutex_destroy(&info->philos[i].eating_fork);
		pthread_mutex_destroy(&info->philos[i].meals_num.mtx);
	}
	return (EXIT_FAILURE);
}
