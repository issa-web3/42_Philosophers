/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:24:42 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/05/11 14:36:29 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

t_my_data	parse_data(int ac, char **av)
{
	t_my_data	data;
	t_arg		arg;
	int			i;

	i = 0;
	data.is_valid = (ac == 5 || ac == 6);
	data.times_to_eat = -1;
	while (++i < ac && data.is_valid)
	{
		arg = parse_arg(av[i]);
		data.is_valid &= arg.valid;
		((long *)&data.philos_num)[i - 1] = arg.value;
	}
	data.is_valid &= data.philos_num <= MAX_PHILO_NUM;
	return (data);
}

t_arg	parse_arg(char *str)
{
	t_arg	result;
	int		i;

	i = 0;
	while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	result.value = 0;
	result.valid = 1;
	while (ft_isdigit(str[i]))
	{
		result.value *= 10;
		result.value += str[i] - '0';
		if (result.value > INT_MAX)
		{
			result.valid = 0;
			break ;
		}
		i++;
	}
	if (str[i] || result.value <= 0)
		result.valid = 0;
	return (result);
}

int	validation_err(void)
{
	write(2, "Invalid Usage !!\n", 17);
	write(2, "Usage: ./philo a b c d [e]\n", 27);
	write(2, "\ta: number_of_philosophers (<=200)\n", 35);
	write(2, "\tb: time_to_die (ms)\n", 21);
	write(2, "\tc: time_to_eat (ms)\n", 22);
	write(2, "\td: time_to_sleep (ms)\n", 24);
	write(2, "\te: number_of_times_each_philosopher_must_eat\n", 46);
	write(2, "All arguments must be positive NON-NULL integers !!!\n", 53);
	return (EXIT_FAILURE);
}
