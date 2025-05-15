/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 11:08:27 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/05/15 15:41:55 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>

typedef pthread_mutex_t	t_mutex;

# define MAX_PHILO_NUM 200
# define NOT_YET 0
# define YES 1
# define SET 13
# define GET 37

// Structs
typedef struct s_my_data
{
	long	philos_num;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	times_to_eat;
	char	is_valid;
}				t_my_data;

typedef struct s_arg
{
	long		value;
	char		valid;
}				t_arg;

typedef struct s_general_flag
{
	t_mutex		mtx;
	long		value;
}				t_general_flag;

typedef struct s_philo
{
	int							id;
	pthread_t					thread;
	t_mutex						eating_fork;
	t_mutex						*l_fork;
	t_mutex						*r_fork;
	t_general_flag				meals_num;
	t_general_flag				last_time_eaten;
	struct s_broadcasted_info	*info;
}				t_philo;

typedef struct s_broadcasted_info
{
	t_philo			philos[MAX_PHILO_NUM];
	pthread_t		shinigami;
	t_general_flag	start;
	t_general_flag	death;
	t_mutex			printing;
	t_my_data		data;
}				t_broadcasted_info;

#endif
