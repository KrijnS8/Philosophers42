/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosopher.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 16:18:09 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/01/26 13:28:59 by krijn         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include "simulation.h"
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

void	init_philo(t_philo *philo, t_simulation *sim, int id)
{
	philo->id = id;
	philo->config = &sim->config;
	philo->fork_left = &sim->forks[(id - 1) % sim->config.nbr_of_philos];
	philo->fork_right = &sim->forks[id % sim->config.nbr_of_philos];
	philo->start_time = &sim->start_time;
}

static void	*loop(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (true)
	{
		philo_think(philo);
		philo_eat(philo);
		philo_sleep(philo);
	}
	return (philo);
}

t_error	init_thread(t_philo *philo)
{
	if (pthread_create(&philo->thread, NULL, loop, philo) != 0)
		return (ERR_THREAD);
	return (ERR_OK);
}

t_error join_thread(t_philo *philo)
{
	pthread_join(philo->thread, NULL);
	return (ERR_OK);
}
