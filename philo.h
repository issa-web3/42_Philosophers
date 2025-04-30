/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:47:10 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/04/30 11:53:18 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

// general utils
int				ft_isdigit(int c);
long			get_time_now(void);
int				is_dead(t_philo philo, t_my_data data);
void			ft_sleep(long duration);

// Parsing functions
t_my_data		parse_data(int ac, char **av);
t_arg			parse_arg(char *str);
int				validation_err(void);

// simulation
int				start_simulation(t_my_data data);
void			*routine(void *ptr);
void			*monitoring(t_broadcasted_info *info);
void			eat(t_philo *philo);
void	        think(t_philo *philo);
void	        zzz(t_philo *philo);

// safe functions 
void			safe_print(t_philo *philo, char *action);

