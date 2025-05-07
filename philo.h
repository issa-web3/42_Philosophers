/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: test <test@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:47:10 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/05/07 14:38:27 by test             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

// general utils
int				ft_isdigit(int c);
long			get_time_now(void);
int				is_dead(t_philo philo, t_my_data data);
void			ft_sleep(t_philo *philo, long duration);

// Parsing functions
t_my_data		parse_data(int ac, char **av);
t_arg			parse_arg(char *str);
int				validation_err(void);

// simulation
int				init(t_broadcasted_info *info);
int				start_simulation(t_broadcasted_info *info);
void			*routine(void *ptr);
void	        *shinigami_routine(void *ptr);
void			wait_start_flag(t_broadcasted_info *info);
void			eat(t_philo *philo);
void	        think(t_philo *philo);
void	        zzz(t_philo *philo);

// safe functions 
int				safe_getter_setter(t_general_flag *flag, char action, int new_val);

// clean up
void			destroy_all(t_broadcasted_info *info);
