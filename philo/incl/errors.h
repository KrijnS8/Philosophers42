/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errors.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 14:44:35 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/01/17 20:31:52 by krijn         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

typedef enum	s_error
{
	ERR_OK = 0,
	ERR_MISSING_ARGS,
	ERR_INVALID_ARGS,
	ERR_MALLOC,
	ERR_MUTEX,
	ERR_THREAD
}	t_error;

const char	*error_to_str(t_error error);
void		print_error(t_error error);

#endif