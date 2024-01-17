/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 15:01:15 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/01/17 15:19:59 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	ft_isspace(int c)
{
	return (c == ' ' || c == '\f' || c == '\n' || c == '\r' || \
	c == '\t' || c == '\v');
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] != '\0')
	{
		if (!ft_isdigit(nptr[i]))
			return (result * sign);
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}
