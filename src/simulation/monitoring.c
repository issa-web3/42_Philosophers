/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:57:38 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/05/06 12:21:17 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	*monitoring(void *ptr)
{
	t_broadcasted_info *info;
	t_philo				*philos;
	t_my_data			data;
	int					all_ate;
	int					i;

	info = (t_broadcasted_info *)ptr;
	philos = info->philos;
	data = info->data;
	safe_set_start_flag(philos);
	while (!safe_get_death_flag(philos))
	{
		// bq4 h4444di, m4hdk h4d1n1 rb1 34t1n1
		// death of a philo
		i = -1;
		all_ate = 1;
		while (++i < data.philos_num)
		{
			if (is_dead(philos[i], data))
			{
				safe_set_death_flag(&philos[i]);
				safe_print(&philos[i], "died");
				return (NULL);
			}
			if (safe_get_meals_num(&philos[i]) < data.times_to_eat)
				all_ate = 0;
		}
		// everyone ate n times
		if (all_ate && data.times_to_eat != -1)
			return (safe_set_death_flag(philos), NULL);
		usleep(10);
	}
	// i = thread_join(philos[i].thread, NULL);
	destroy_all(info);
	return (NULL);
}
