/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioulkhir <ioulkhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:47:10 by ioulkhir          #+#    #+#             */
/*   Updated: 2025/05/09 16:11:38 by ioulkhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

// general utils
int				ft_isdigit(int c);
long			get_time_now(void);
void			ft_sleep(t_philo *philo, long duration);

// Parsing functions
t_my_data		parse_data(int ac, char **av);
t_arg			parse_arg(char *str);
int				validation_err(void);

// simulation
int				init(t_broadcasted_info *info);
int				start_simulation(t_broadcasted_info *info);
void			*routine(void *ptr);
void			wait_start_flag(t_broadcasted_info *info);
void			eating(t_philo *self);
void	        thinking(t_philo *self);
void	        sleeping(t_philo *self);

// SHINIGAMI
void	        *shinigami_routine(void *ptr);
int		        death_or_all_eaten(t_broadcasted_info *info);
int				dad_or_alive(t_philo *philo, t_my_data data);
int				eaten_enough(t_philo *philo, t_my_data data);

// safe functions 
long			safe_getter_setter(t_general_flag *flag, char action, long new_val);
void			print_action(t_philo *self, char *action);

