/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:47:10 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/05/01 11:37:58 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <sys/time.h>

typedef pthread_mutex_t mutex;

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

typedef struct s_broadcasted_info
{
	struct s_philo	*philos;
	t_my_data		data;
	int				fail;
	int				death_flag;
	mutex			death_mutex;
	int				start_flag;
	mutex			start_mutex;
	mutex			printing_mutex;
	mutex			fail_mutex;
}					t_broadcasted_info;

typedef struct s_philo
{
	int					id;
	pthread_t			thread;
	long				last_time_eaten;
	int					meals_num;
	mutex				last_time_eaten_mutex;
	mutex				meals_num_mutex;
	mutex				eating_fork;
	t_broadcasted_info	*info;
}				t_philo;
