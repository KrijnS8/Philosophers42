/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosopher.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 16:18:09 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/01/19 15:26:35 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	init_philo(t_philo *philo, int id, t_config *config, t_fork *forks)
{
	philo->id = id;
	philo->config = config;
	philo->forks = forks;
}
