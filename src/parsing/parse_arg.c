/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:24:42 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/04/30 15:26:33 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

t_arg			parse_arg(char *str)
{
	t_arg	result;
	int		i;

	i = 0;
	while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	result.val = 0;
	result.valid = 1;
	while (ft_isdigit(str[i]))
	{
		result.val *= 10;
		result.val += str[i] - '0';
		if (result.val > INT_MAX)
		{
			result.valid = 0;
			break;
		}
		i++;
	}
	result.valid = str[i] == '\0' && result.val > 0;
	return (result);
}
