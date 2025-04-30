/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:57:38 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/04/30 13:15:37 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

static void	init_info(t_broadcasted_info *info)
{
	info->death_flag = 0;
	pthread_mutex_init(&info->printing_mutex, NULL);
}

int	start_simulation(t_my_data data)
{
	t_philo				*philos;
	mutex				*forks;
	t_broadcasted_info	info;
	int					i;

	philos = malloc(data.philos_num * sizeof(t_philo));
	if (philos == NULL)
		return (EXIT_FAILURE);
	forks = malloc(data.philos_num * sizeof(mutex));
	if (forks == NULL)
		return (free(philos), EXIT_FAILURE);
	i = -1;
	init_info(&info);
	info.philos = philos;
	info.data = data;
	while (++i < data.philos_num)
	{
		// init philo
		philos[i].id = i + 1;
		philos[i].info = &info;
		philos[i].last_time_eaten = get_time_now();
		philos[i].meals_num = 0;
		philos[i].eating_fork = &forks[i];
		pthread_mutex_init(philos[i].eating_fork, NULL);
		// ...
		pthread_create(&philos[i].thread, NULL, routine, &philos[i]);
		pthread_detach(philos[i].thread);
	}
	// basically chef dyal l philos
	monitoring(&info);
	// i = -1;
	// while (++i < data.philos_num)
	// 	pthread_join(philos[i].thread, NULL);
	// free(philos);
	// free(forks);
	write(1, "letsgoooo\n", 11);
	return (EXIT_SUCCESS);
}
