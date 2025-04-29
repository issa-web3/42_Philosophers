/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:47:10 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/04/29 15:18:26 by ioulkhir         ###   ########.fr       */
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

typedef struct s_philo
{
	int					id;
	int					last_time_eaten;
	pthread_t			thread;
	t_broadcasted_info	*info;
}				t_philo;

typedef struct s_broadcasted_info
{
	t_philo		*philos;
	t_my_data	data;
	int			death_flag;
	mutex		printing_mutex;
}				t_broadcasted_info;

// general utils
int				ft_isdigit(int c);
int				what_time_is_it();

// Parsing functions
t_my_data		parse_data(int ac, char **av);
t_arg			parse_arg(char *str);
int				validation_err(void);

// simulation
int				start_simulation(t_my_data data);
void			*routine(void *ptr);
void			*monitoring(t_broadcasted_info info);
