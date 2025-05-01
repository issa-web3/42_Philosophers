/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:57:38 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/05/01 11:54:05 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	create_philos(t_broadcasted_info *info)
{
	t_my_data	data;
	t_philo		*philos;
	int			fail;
	int			i;

	data = info->data;
	philos = info->philos;
	i = -1;
	fail = 0;
	while (++i < data.philos_num && !fail)
	{
		philos[i].id = i + 1;
		philos[i].info = info;
		philos[i].last_time_eaten = get_time_now();
		philos[i].meals_num = 0;
		pthread_mutex_init(&philos[i].meals_num_mutex, NULL);
		pthread_mutex_init(&philos[i].last_time_eaten_mutex, NULL);
		pthread_mutex_init(&philos[i].eating_fork, NULL);
		fail |= pthread_create(&philos[i].thread, NULL, routine, &philos[i]);
	}
	return (fail);
}

void	destroy_all(t_broadcasted_info *info)
{
	t_my_data	data;
	t_philo		*philos;
	int			i;

	i = -1;
	data = info->data;
	philos = info->philos;
	safe_set_fail_flag(philos);
	while (++i < data.philos_num)
	{
		pthread_join(philos[i].thread, NULL);
		pthread_mutex_destroy(&philos[i].eating_fork);
		pthread_mutex_destroy(&philos[i].meals_num_mutex);
		pthread_mutex_destroy(&philos[i].last_time_eaten_mutex);
	}
	pthread_mutex_destroy(&info->death_mutex);
	pthread_mutex_destroy(&info->start_mutex);
	pthread_mutex_destroy(&info->printing_mutex);
}

int	start_simulation(t_my_data data)
{
	t_philo				*philos;
	t_broadcasted_info	info;

	philos = malloc(data.philos_num * sizeof(t_philo));
	if (philos == NULL)
		return (EXIT_FAILURE);
	info.start_flag = 0;
	info.death_flag = 0;
	info.philos = philos;
	info.data = data;
	info.fail = 0;
	pthread_mutex_init(&info.fail_mutex, NULL);
	pthread_mutex_init(&info.printing_mutex, NULL);
	pthread_mutex_init(&info.start_mutex, NULL);
	pthread_mutex_init(&info.death_mutex, NULL);
	if (create_philos(&info) != 0)
		return (destroy_all(&info), EXIT_FAILURE);
	monitoring(&info);
	return (EXIT_SUCCESS);
}
