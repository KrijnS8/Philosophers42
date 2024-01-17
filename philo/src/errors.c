/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 14:45:55 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/01/17 16:34:15 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include <stdio.h>

const char	*error_to_str(t_error error)
{
	return ((const char *[]){
		[ERR_OK] = "",
		[ERR_MISSING_ARGS] = "Please enter 4 or 5 arguments",
		[ERR_INVALID_ARGS] = "One or more arguments are invalid",
		[ERR_MALLOC] = "Malloc failure",
		[ERR_MUTEX] = "Can't setup mutex"
	}[error]);
}

void	print_error(t_error error)
{
	if (!error)
		return ;
	printf("Error\n%s\n", error_to_str(error));
}
