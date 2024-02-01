/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   config.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 15:59:33 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/02/01 14:05:58 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H
# include "errors.h"
# include <stdbool.h>

typedef struct s_config
{
	int		nbr_of_philos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		times_to_eat;
	bool	finished;
}	t_config;

t_error	init_config(t_config *conf, int argc, char *argv[]);

#endif
