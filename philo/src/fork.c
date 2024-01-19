/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fork.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/19 15:17:36 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/01/19 15:21:40 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fork.h"

t_error	init_fork(t_fork *fork, int id)
{
	fork->id = id;
	fork->locked = false;
	if (pthread_mutex_init(&fork->mutex, NULL) != 0)
		return (ERR_MUTEX);
	return (ERR_OK);
}
