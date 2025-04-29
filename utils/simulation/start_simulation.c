/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:57:38 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/04/29 15:19:57 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	init_info(t_broadcasted_info *info)
{
	info->death_flag = 0;
	pthread_mutex_init(&info->printing_mutex, NULL);
}

int	start_simulation(t_my_data data)
{
	t_philo				*philos;
	t_broadcasted_info	info;
	int					i;

	philos = malloc(data.philos_num * sizeof(t_philo));
	if (philos == NULL)
		return (EXIT_FAILURE);
	i = -1;
	int_info(&info);
	info.philos = philos;
	info.data = data;
	while (++i < data.philos_num)
	{
		// init philo
		philos[i].id = i + 1;
		philos[i].info = &info;
		philos[i].last_time_eaten = what_time_is_it();
		// ...
		pthread_create(&philos[i].thread, NULL, routine, &philos[i]);
	}
	// basically chef dyal l philos
	monitoring(info);
	return (EXIT_SUCCESS);
}
