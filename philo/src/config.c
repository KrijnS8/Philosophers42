/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   config.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 16:00:28 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/01/17 16:04:31 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "utils.h"

static t_error	validate_args(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (argc != 5 && argc != 6)
		return (ERR_MISSING_ARGS);
	while (i < argc)
	{
		if (!ft_is_integer(argv[i]))
			return (ERR_INVALID_ARGS);
		i++;
	}
	return (ERR_OK);
}

t_error	init_config(t_config *conf, int argc, char *argv[])
{
	t_error	error;

	error = validate_args(argc, argv);
	if (error)
		return (error);
	conf->nbr_of_philos = ft_atoi(argv[1]);
	conf->time_to_die = ft_atoi(argv[2]);
	conf->time_to_eat = ft_atoi(argv[3]);
	conf->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		conf->times_to_eat = ft_atoi(argv[5]);
	else
		conf->times_to_eat = -1;
	return (ERR_OK);
}
