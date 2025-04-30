/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:57:38 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/04/30 11:52:22 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	*monitoring(t_broadcasted_info *info)
{
	t_philo		*philos;
	t_my_data	data;
	int			all_ate;
	int			i;

	philos = info->philos;
	data = info->data;
	while (!info->death_flag)
	{
		// bq4 h4444di, m4hdk h4d1n1 rb1 34t1n1
		// death of a philo
		i = -1;
		all_ate = 1;
		while (++i < data.philos_num)
		{
			if (is_dead(philos[i], data))
				return (safe_print(&philos[i], "died"), info->death_flag = 1, NULL);
			if (philos[i].meals_num < data.times_to_eat)
				all_ate = 0;
		}
		// everyone ate n times
		if (all_ate && data.times_to_eat != -1)
			return (info->death_flag = 1, NULL);
	}
	return (NULL);
}
