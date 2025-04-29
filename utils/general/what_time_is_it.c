/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_time_is_it.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 08:41:55 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/04/29 15:10:00 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	what_time_is_it()
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL) != 0)
		return (-1);
	return (tv.tv_usec);
}
