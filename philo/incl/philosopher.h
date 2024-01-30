/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosopher.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/15 13:15:56 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/01/30 12:29:49 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <sys/time.h>
# include "config.h"
# include "fork.h"

typedef struct s_simulation	t_simulation;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	t_config		*config;
	t_fork			*fork_left;
	t_fork			*fork_right;
	struct timeval	*start_time;
	struct timeval	last_eaten;
	pthread_mutex_t	last_eaten_mutex;
}	t_philo;

t_error	init_philo(t_philo *philo, t_simulation *sim, int id);
t_error	init_thread(t_philo *philo);
t_error join_thread(t_philo *philo);

bool	philo_check_death(t_philo *philo);

void	philo_think(t_philo *philo);
void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);

#endif
