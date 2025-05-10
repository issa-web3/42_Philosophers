/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:47:28 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/05/10 11:18:11 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_broadcasted_info	info;
	int					status;

	info.data = parse_data(ac, av);
	if (!info.data.is_valid)
		return (validation_err());
	status = init(&info);
	if (status == EXIT_SUCCESS)
		status = start_simulation(&info);
	return (status);
}
