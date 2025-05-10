/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 11:08:27 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/05/10 11:15:40 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <sys/time.h>

typedef pthread_mutex_t mutex;
#define MAX_PHILO_NUM 200
#define NOT_YET 0
#define YES 1
#define SET 13
#define GET 37

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
	long		val;
	char		valid;
}				t_arg;

typedef struct s_general_flag
{
	mutex		mtx;
	long		value;
}				t_general_flag;

typedef struct s_philo
{
	int							id;
	pthread_t					thread;
	mutex						eating_fork;
	mutex						*l_fork;
	mutex						*r_fork;
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
	mutex			printing;
	t_my_data		data;
}				t_broadcasted_info;
