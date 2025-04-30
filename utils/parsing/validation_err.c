/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_err.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 09:39:10 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/04/30 15:25:54 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	validation_err(void)
{
	write(2, "Invalid Usage !!\n", 17);
	write(2, "Usage: ./philo a b c d [e]\n", 27);
	write(2, "\ta: number_of_philosophers\n", 28);
	write(2, "\tb: time_to_die (ms)\n", 21);
	write(2, "\tc: time_to_eat (ms)\n", 22);
	write(2, "\td: time_to_sleep (ms)\n", 24);
	write(2, "\te: number_of_times_each_philosopher_must_eat\n", 46);
	write(2, "All arguments must be positive NON-NULL integers !!!\n", 53);
	return (EXIT_FAILURE);
}
