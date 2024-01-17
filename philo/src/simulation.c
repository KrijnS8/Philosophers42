/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simulation.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 16:19:01 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/01/17 16:45:13 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"
#include <stdlib.h>

void	destroy_simulation(t_simulation *sim)
{
	if (sim->philosophers)
		free(sim->philosophers);
	if (sim->forks)
		free(sim->forks);
}

t_error	init_simulation(t_simulation *sim, t_config config)
{
	int	i;

	sim->config = config;
	sim->philosophers = (t_philo *)malloc(config.nbr_of_philos * sizeof(t_philo));
	sim->forks = (pthread_mutex_t *)malloc(config.nbr_of_philos * sizeof(pthread_mutex_t));
	if (!sim->philosophers || !sim->forks)
		return (ERR_MALLOC);
	i = 0;
	while (i < config.nbr_of_philos)
	{
		init_philo(&sim->philosophers[i], i, &sim->config);
		if (pthread_mutex_init(&sim->forks[i], NULL) != 0)
			return (ERR_MUTEX);
		i++;
	}
	return (ERR_OK);
}
