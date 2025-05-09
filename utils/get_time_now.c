/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time_now.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 08:41:55 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/04/30 08:47:01 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long	first_time()
{
	static long		time;
	struct timeval	tv;

	if (time)
		return (time);
	if (gettimeofday(&tv, NULL) != 0)
		return (-1);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}

long	get_time_now(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
		return (-1);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000) - first_time());
}
