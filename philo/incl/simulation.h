/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simulation.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 16:08:10 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/01/25 13:46:19 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_H
# define SIMULATION_H
# include <pthread.h>
# include <sys/time.h>
# include "config.h"
# include "philosopher.h"
# include "fork.h"
# include "errors.h"

typedef struct s_simulation
{
	t_config		config;
	t_philo 		*philosophers;
	t_fork			*forks;
	struct timeval	start_time;
}	t_simulation;

void	destroy_simulation(t_simulation *sim);
t_error	init_simulation(t_simulation *sim, t_config config);
t_error	start_simulation(t_simulation *sim);

#endif
