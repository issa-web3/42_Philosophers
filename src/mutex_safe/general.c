/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: test <test@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:57:38 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/05/07 16:02:27 by test             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	safe_getter_setter(t_general_flag *flag, char action, int new_val)
{
	int	val;

	pthread_mutex_lock(&flag->mtx);
	if (action == SET)
		flag->change_func(&flag->value);
	val = flag->value;
	pthread_mutex_unlock(&flag->mtx);
	return (val);
}

void	set_to_yes(void *ptr)
{
	*(int *)ptr = YES;
}

void	increment(void *ptr)
{
	*(int *)ptr++;
}

void	print_action(t_philo *self, char *action)
{
	pthread_mutex_lock(&self->info->printing);
	printf("%ld %d %s\n", get_time_now(), self->id, action);
	pthread_mutex_unlock(&self->info->printing);
}
