/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: test <test@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:57:38 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/05/07 15:24:07 by test             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	safe_getter_setter(t_general_flag *flag, char action, int new_val)
{
	int	val;

	pthread_mutex_lock(&flag->mtx);
	if (action == SET)
		flag->value = new_val;
	val = flag->value;
	pthread_mutex_unlock(&flag->mtx);
	return (val);
}
