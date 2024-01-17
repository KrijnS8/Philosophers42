/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 15:18:34 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/01/17 15:21:36 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
