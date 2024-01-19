/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fork.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/19 15:14:32 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/01/19 15:22:17 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORK_H
# define FORK_H
# include <pthread.h>
# include <stdbool.h>
# include "errors.h"

typedef struct s_simulation	t_simulation;

typedef struct s_fork
{
	int				id;
	bool			locked;
	pthread_mutex_t	mutex;
}	t_fork;

t_error	init_fork(t_fork *fork, int id);

#endif
