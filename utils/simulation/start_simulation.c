/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:57:38 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/04/30 15:42:48 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	create_philos(t_broadcasted_info *info)
{
	t_my_data	data;
	t_philo		*philos;
	mutex		*forks;
	int			fail;
	int			i;

	data = info->data;
	philos = info->philos;
	forks = info->forks;
	i = -1;
	fail = 0;
	while (++i < data.philos_num && !fail)
	{
		// init philo
		philos[i].id = i + 1;
		philos[i].info = info;
		philos[i].last_time_eaten = get_time_now();
		philos[i].meals_num = 0;
		philos[i].eating_fork = &forks[i];
		pthread_mutex_init(philos[i].eating_fork, NULL);
		// ...
		fail |= pthread_create(&philos[i].thread, NULL, routine, &philos[i]);
	}
	return (fail);
}

int	start_simulation(t_my_data data)
{
	t_philo				*philos;
	mutex				*forks;
	t_broadcasted_info	info;

	philos = malloc(data.philos_num * sizeof(t_philo));
	if (philos == NULL)
		return (EXIT_FAILURE);
	forks = malloc(data.philos_num * sizeof(mutex));
	if (forks == NULL)
		return (free(philos), EXIT_FAILURE);
	info.start_flag = 0;
	info.death_flag = 0;
	pthread_mutex_init(&info.printing_mutex, NULL);
	info.philos = philos;
	info.forks = forks;
	info.data = data;
	if (create_philos(&info) != 0)
		return (EXIT_FAILURE);
	monitoring(&info);
	return (EXIT_SUCCESS);
}
