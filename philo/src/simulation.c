/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simulation.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 16:19:01 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/02/02 12:25:37 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"
#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>

void	destroy_simulation(t_simulation *sim)
{
	if (sim->philosophers)
		free(sim->philosophers);
	if (sim->forks)
		free(sim->forks);
}

void	monitor_simulation(t_simulation *sim)
{
	int	i;
	int	times_eaten;

	while (!sim->config.finished)
	{
		i = 0;
		times_eaten = 0;
		while (i < sim->config.nbr_of_philos)
		{
			times_eaten += sim->philosophers[i].times_eaten;
			if (philo_check_death(&sim->philosophers[i]))
			{
				sim->config.finished = true;
				break ;
			}
			i++;
		}
		if (sim->config.times_to_eat > 0 && times_eaten >= \
				(sim->config.times_to_eat * sim->config.nbr_of_philos))
			sim->config.finished = true;
	}
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
	monitor_simulation(sim);
	i = 0;
	while (i < sim->config.nbr_of_philos)
	{
		pthread_join(sim->philosophers[i].thread, NULL);
		i++;
	}
	return (error);
}

t_error	init_simulation(t_simulation *sim, t_config config)
{
	int	i;

	sim->config = config;
	sim->philosophers = (t_philo *)malloc(config.nbr_of_philos * \
											sizeof(t_philo));
	sim->forks = (t_fork *)malloc(config.nbr_of_philos * sizeof(t_fork));
	if (!sim->philosophers || !sim->forks)
		return (ERR_MALLOC);
	i = 0;
	while (i < config.nbr_of_philos)
	{
		if (init_fork(&sim->forks[i], i))
			return (ERR_MUTEX);
		if (init_philo(&sim->philosophers[i], sim, i + 1))
			return (ERR_MUTEX);
		i++;
	}
	return (ERR_OK);
}
