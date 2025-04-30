/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:15:59 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/04/30 11:50:57 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	is_dead(t_philo philo, t_my_data data)
{
	long	time_now;
	long	hunger_duration;

	time_now = get_time_now();
	hunger_duration = time_now - philo.last_time_eaten;
	return (hunger_duration > data.time_to_die);
}
