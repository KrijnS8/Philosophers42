/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_actions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/25 12:31:30 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/02/01 14:07:55 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdbool.h>

static long get_elapsed_time(struct timeval *start)
{
	struct timeval	current;

	gettimeofday(&current, NULL);
	return (((current.tv_sec - start->tv_sec) * 1000) +
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
	printf("%ld %d is thinking\n", get_elapsed_time(philo->start_time), philo->id);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork_left->mutex);
	printf("%ld %d has taken a fork\n", get_elapsed_time(philo->start_time), philo->id);
	pthread_mutex_lock(&philo->fork_right->mutex);
	printf("%ld %d has taken a fork\n", get_elapsed_time(philo->start_time), philo->id);
	printf("%ld %d is eating\n", get_elapsed_time(philo->start_time), philo->id);
	usleep(philo->config->time_to_eat * 1000);
	pthread_mutex_lock(&philo->last_eaten_mutex);
	gettimeofday(&philo->last_eaten, NULL);
	pthread_mutex_unlock(&philo->last_eaten_mutex);
	pthread_mutex_unlock(&philo->fork_left->mutex);
	pthread_mutex_unlock(&philo->fork_right->mutex);
	philo->times_eaten++;
}

void	philo_sleep(t_philo *philo)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	printf("%ld %d is sleeping\n", get_elapsed_time(philo->start_time), philo->id);
	usleep(philo->config->time_to_sleep * 1000);
}
