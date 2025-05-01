/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:57:38 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/05/01 10:28:34 by ioulkhir         ###   ########.fr       */
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
		fail |= pthread_mutex_init(&philos[i].meals_num_mutex, NULL);
		fail |= pthread_mutex_init(&philos[i].last_time_eaten_mutex, NULL);
		fail |= pthread_mutex_init(&philos[i].eating_fork, NULL);
		fail |= pthread_create(&philos[i].thread, NULL, routine, &philos[i]);
	}
	return (fail);
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
	pthread_mutex_init(&info.printing_mutex, NULL);
	pthread_mutex_init(&info.start_mutex, NULL);
	pthread_mutex_init(&info.death_mutex, NULL);
	if (create_philos(&info) != 0)
		return (free(philos), EXIT_FAILURE);
	monitoring(&info);
	return (EXIT_SUCCESS);
}
