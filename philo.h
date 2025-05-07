/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: test <test@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:47:10 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/05/07 16:03:17 by test             ###   ########.fr       */
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
void			eating(t_philo *self);
void	        thinking(t_philo *self);
void	        sleeping(t_philo *self);

// safe functions 
int				safe_getter_setter(t_general_flag *flag, char action, int new_val);
void			set_to_yes(void *ptr);
void			increment(void *ptr);
void			print_action(t_philo *self, char *action);

// clean up
void			destroy_all(t_broadcasted_info *info);
