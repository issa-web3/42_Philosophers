/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:57:38 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/05/10 11:07:02 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	dad_or_alive(t_philo *philo, t_my_data data)
{
	long	time_now;
	long	hunger_duration;

	time_now = get_time_now();
	hunger_duration = time_now;
	hunger_duration -= safe_getter_setter(&philo->last_time_eaten, GET, 314);
	return (hunger_duration >= data.time_to_die);
}

int	eaten_enough(t_philo *philo, t_my_data data)
{
	return (data.times_to_eat
		<= safe_getter_setter(&philo->meals_num, GET, 314)
	);
}

int	death_or_all_eaten(t_broadcasted_info *info)
{
	t_philo		*philos;
	int			i;
	int			all_eaten;

	i = 0;
	philos = info->philos;
	all_eaten = info->data.times_to_eat != -1;
	while (i < info->data.philos_num)
	{
		if (dad_or_alive(&philos[i], info->data))
			return (print_action(&philos[i], "died"), YES);
		all_eaten &= eaten_enough(&philos[i], info->data);
		usleep(10);
		i++;
	}
	return (all_eaten);
}
