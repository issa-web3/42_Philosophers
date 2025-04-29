/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:47:28 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/04/29 11:40:35 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_my_data	data;

	data = parse_data(ac, av);
	if (!data.is_valid)
		return (validation_err());
	printf("%ld\n", data.philos_num);
	printf("%ld\n", data.time_to_die);
	printf("%ld\n", data.time_to_eat);
	printf("%ld\n", data.time_to_sleep);
	printf("%ld\n", data.times_to_eat);
}

// number_of_philosophers time_to_die time_to_eat time_to_sleep
// [number_of_times_each_philosopher_must_eat]
