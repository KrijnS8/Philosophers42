/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosopher.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 16:18:09 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/02/01 14:09:16 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include "simulation.h"
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

t_error	init_philo(t_philo *philo, t_simulation *sim, int id)
{
	philo->id = id;
	philo->config = &sim->config;
	philo->fork_left = &sim->forks[(id - 1) % sim->config.nbr_of_philos];
	philo->fork_right = &sim->forks[id % sim->config.nbr_of_philos];
	philo->start_time = &sim->start_time;
	philo->times_eaten = 0;
	if (pthread_mutex_init(&philo->last_eaten_mutex, NULL) != 0)
		return (ERR_MUTEX);
	return (ERR_OK);
}

static void	*loop(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 1)
		usleep((philo->config->time_to_die / 5) * 1000);
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
	philo->last_eaten = *philo->start_time;
	if (pthread_create(&philo->thread, NULL, loop, philo) != 0)
		return (ERR_THREAD);
	return (ERR_OK);
}

t_error join_thread(t_philo *philo)
{
	pthread_join(philo->thread, NULL);
	return (ERR_OK);
}
