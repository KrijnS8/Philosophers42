/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosopher.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 16:18:09 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/01/22 16:27:23 by krijn         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <stdio.h>

void	init_philo(t_philo *philo, int id, t_config *config, t_fork *forks)
{
	philo->id = id;
	philo->config = config;
	philo->forks = forks;
}

static void	*loop(void *arg)
{
	long i = 0;
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (i < 100)
		printf("%d: %ld\n", philo->id, i++);
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
