/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_actions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/25 12:31:30 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/01/25 15:39:44 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

static long	get_time_stamp(t_philo *philo)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (((tv.tv_sec - philo->start_time->tv_sec) * 1000) +
			((tv.tv_usec - philo->start_time->tv_usec) / 1000));
}

static long get_elapsed_time(struct timeval *start)
{
	struct timeval	current;

	gettimeofday(&current, NULL);
	return (((current.tv_sec - start->tv_sec) * 1000) +
			((current.tv_usec - start->tv_usec) / 1000));
}

void	philo_think(t_philo *philo)
{
	printf("%ld %d is thinking\n", get_time_stamp(philo), philo->id);
	while (philo->fork_left->locked || philo->fork_right->locked)
		continue ;
	pthread_mutex_lock(&philo->fork_left->mutex);
	philo->fork_left->locked = true;
	pthread_mutex_lock(&philo->fork_right->mutex);
	philo->fork_right->locked = true;
}

void	philo_eat(t_philo *philo)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	printf("%ld %d is eating\n", get_elapsed_time(philo->start_time), philo->id);
	while (get_elapsed_time(&start) < philo->config->time_to_eat)
		continue;
	pthread_mutex_unlock(&philo->fork_left->mutex);
	philo->fork_left->locked = false;
	pthread_mutex_unlock(&philo->fork_right->mutex);
	philo->fork_right->locked = false;
}

void	philo_sleep(t_philo *philo)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	printf("%ld %d is sleeping\n", get_elapsed_time(philo->start_time), philo->id);
	usleep(philo->config->time_to_sleep * 1000);
}
