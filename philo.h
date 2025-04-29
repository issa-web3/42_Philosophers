/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:47:10 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/04/29 09:42:01 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

// Structs
// number_of_philosophers time_to_die time_to_eat time_to_sleep
// [number_of_times_each_philosopher_must_eat]
typedef struct s_my_data
{
	/* program args */
	int		philos_num;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		times_to_eat; // [-1]
	/* valid args */
	char	is_valid;
}				t_my_data;


// Parsing functions
t_my_data		parse_data(int ac, char **av);
int				validation_err(void);
