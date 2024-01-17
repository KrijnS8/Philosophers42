/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosopher.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/15 13:15:56 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/01/17 16:27:42 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include "config.h"

typedef struct s_philo
{
	int			id;
	pthread_t	thread;
	t_config	*config;
}	t_philo;

void	init_philo(t_philo *philo, int id, t_config *config);

#endif
