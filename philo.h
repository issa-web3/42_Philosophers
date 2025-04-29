/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:47:10 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/04/29 10:50:47 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

// Structs
// number_of_philosophers time_to_die time_to_eat time_to_sleep
// [number_of_times_each_philosopher_must_eat]
typedef struct s_my_data
{
	/* program args */
	long	philos_num;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	times_to_eat; // [-1]
	/* valid args */
	char	is_valid;
}				t_my_data;

typedef struct s_arg
{
	long		val;
	char		valid;
}				t_arg;

// general utils
int				ft_isdigit(int c);

// Parsing functions
t_my_data		parse_data(int ac, char **av);
t_arg			parse_arg(char *str);
int				validation_err(void);
