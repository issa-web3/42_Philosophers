/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 08:41:55 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/05/09 16:06:48 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_sleep(t_philo *philo, long duration)
{
	long	then;

	then = get_time_now();
	while (get_time_now() < then + duration
		&& safe_getter_setter(&philo->info->death, GET, 314) == NOT_YET)
		usleep(100);
}
