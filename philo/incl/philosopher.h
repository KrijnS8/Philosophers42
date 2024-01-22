/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosopher.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/15 13:15:56 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/01/22 15:21:18 by krijn         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include "config.h"

typedef struct s_fork	t_fork;

typedef struct s_philo
{
	int			id;
	pthread_t	thread;
	t_config	*config;
	t_fork		*forks;
}	t_philo;

void	init_philo(t_philo *philo, int id, t_config *config, t_fork *forks);
t_error	init_thread(t_philo *philo);
t_error join_thread(t_philo *philo);

#endif
