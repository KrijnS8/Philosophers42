/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/15 13:16:12 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/01/22 15:20:21 by krijn         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include "errors.h"
#include "utils.h"
#include "simulation.h"
#include <pthread.h>
#include <stdio.h>

// Usage: ./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
int	main(int argc, char *argv[])
{
	t_simulation	simulation;
	t_config		config;
	t_error			error;

	error = init_config(&config, argc, argv);
	if (error)
		return (print_error(error), 1);
	error = init_simulation(&simulation, config);
	if (error)
		return (print_error(error), destroy_simulation(&simulation), 1);
	error = start_simulation(&simulation);
	if (error)
		return (print_error(error), destroy_simulation(&simulation), 1);
	print_error(error);
	return (destroy_simulation(&simulation), 0);
}
