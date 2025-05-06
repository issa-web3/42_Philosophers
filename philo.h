/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:47:10 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/05/06 11:57:48 by ioulkhir         ###   ########.fr       */
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
int				start_simulation(t_my_data data);
void			*routine(void *ptr);
void			*monitoring(void *ptr);
void			eat(t_philo *philo);
void	        think(t_philo *philo);
void	        zzz(t_philo *philo);

// safe functions 
void			safe_print(t_philo *philo, char *action);
int				safe_get_death_flag(t_philo *philo);
void			safe_set_death_flag(t_philo *philo);
int				safe_get_start_flag(t_philo *philo);
void			safe_set_start_flag(t_philo *philo);
int				safe_get_meals_num(t_philo *philo);
int				safe_get_total_meals_num(t_philo *philo);
void			safe_inc_total_meals_num(t_philo *philo);
void			safe_inc_meals_num(t_philo *philo);
int				safe_get_time_eaten(t_philo *philo);
void			safe_set_time_eaten(t_philo *philo);
int				safe_get_fail_flag(t_philo *philo);
void			safe_set_fail_flag(t_philo *philo);

// clean up
void			destroy_all(t_broadcasted_info *info);
