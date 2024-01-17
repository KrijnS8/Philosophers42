/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosopher.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 16:18:09 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/01/17 16:26:40 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	init_philo(t_philo *philo, int id, t_config *config)
{
	philo->id = id;
	philo->config = config;
}
