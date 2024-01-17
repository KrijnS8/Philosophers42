/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simulation.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 16:08:10 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/01/17 16:36:39 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_H
# define SIMULATION_H
# include <pthread.h>
# include "config.h"
# include "philosopher.h"
# include "errors.h"

typedef struct s_simulation
{
	t_config		config;
	t_philo 		*philosophers;
	pthread_mutex_t	*forks;

}	t_simulation;

void	destroy_simulation(t_simulation *sim);
t_error	init_simulation(t_simulation *sim, t_config config);

#endif
