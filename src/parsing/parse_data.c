/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 09:32:19 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/04/30 15:25:03 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

t_my_data		parse_data(int ac, char **av)
{
	t_my_data	data;
	t_arg		arg;
	int			i;

	i = 0;
	data.is_valid = (ac == 5 || ac == 6);
	data.times_to_eat = -1;
	while (++i < ac)
	{
		arg = parse_arg(av[i]);
		data.is_valid &= arg.valid;
		((long *)&data.philos_num)[i - 1] = arg.val;
	}
	return (data);
}
