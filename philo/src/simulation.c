/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simulation.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 16:19:01 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/01/25 13:49:04 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"
#include <stdlib.h>
#include <sys/time.h>

void	destroy_simulation(t_simulation *sim)
{
	if (sim->philosophers)
		free(sim->philosophers);
	if (sim->forks)
		free(sim->forks);
}

t_error	start_simulation(t_simulation *sim)
{
	int		i;
	t_error	error;

	gettimeofday(&sim->start_time, NULL);
	i = 0;
	while (i < sim->config.nbr_of_philos)
	{
		error = init_thread(&sim->philosophers[i]);
		if (error)
			return (error);
		i++;
	}
	i = 0;
	while (i < sim->config.nbr_of_philos)
	{
		error = join_thread(&sim->philosophers[i]);
		if (error)
			return (error);
		i++;
	}
	return (error);
}

t_error	init_simulation(t_simulation *sim, t_config config)
{
	int	i;

	sim->config = config;
	sim->philosophers = (t_philo *)malloc(config.nbr_of_philos * sizeof(t_philo));
	sim->forks = (t_fork *)malloc(config.nbr_of_philos * sizeof(t_fork));
	if (!sim->philosophers || !sim->forks)
		return (ERR_MALLOC);
	i = 0;
	while (i < config.nbr_of_philos)
	{
		if (init_fork(&sim->forks[i], i))
			return (ERR_MUTEX);
		init_philo(&sim->philosophers[i], sim, i + 1);
		i++;
	}
	return (ERR_OK);
}
