/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_actions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/25 12:31:30 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/02/02 12:34:58 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdbool.h>

long	get_elapsed_time(struct timeval *start)
{
	struct timeval	current;

	gettimeofday(&current, NULL);
	return (((current.tv_sec - start->tv_sec) * 1000) + \
			((current.tv_usec - start->tv_usec) / 1000));
}

bool	philo_check_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->last_eaten_mutex);
	if (get_elapsed_time(&philo->last_eaten) >= philo->config->time_to_die)
	{
		printf("%ld %d died\n", get_elapsed_time(philo->start_time), philo->id);
		pthread_mutex_unlock(&philo->last_eaten_mutex);
		return (true);
	}
	pthread_mutex_unlock(&philo->last_eaten_mutex);
	return (false);
}

void	philo_think(t_philo *philo)
{
	print_action(philo, "is thinking");
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork_left->mutex);
	print_action(philo, "has taken a fork");
	while (philo->fork_right == NULL)
		if (philo->config->finished)
			return ;
	pthread_mutex_lock(&philo->fork_right->mutex);
	print_action(philo, "has taken a fork");
	print_action(philo, "is eating");
	pthread_mutex_lock(&philo->last_eaten_mutex);
	gettimeofday(&philo->last_eaten, NULL);
	pthread_mutex_unlock(&philo->last_eaten_mutex);
	usleep(philo->config->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->fork_left->mutex);
	pthread_mutex_unlock(&philo->fork_right->mutex);
	pthread_mutex_lock(&philo->times_eaten_mutex);
	philo->times_eaten++;
	pthread_mutex_unlock(&philo->times_eaten_mutex);
}

void	philo_sleep(t_philo *philo)
{
	print_action(philo, "is sleeping");
	usleep(philo->config->time_to_sleep * 1000);
}
