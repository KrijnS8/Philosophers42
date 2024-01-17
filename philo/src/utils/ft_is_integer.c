/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_is_integer.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 15:16:06 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/01/17 15:21:48 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	ft_check_limits(char *str, int sign)
{
	size_t	len;

	len = ft_strlen(str);
	if (len == 11 && sign < 0)
		return (ft_strncmp(str, "-2147483648", 11) <= 0);
	if (len > 10)
		return (0);
	if (len == 10 && sign > 0)
		return (ft_strncmp(str, "2147483647", 10) <= 0);
	return (1);
}

int	ft_is_integer(char *str)
{
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
		sign = -sign;
	}
	if (ft_strlen(&(str[i])) < 1)
		return (0);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (ft_check_limits(str, sign));
}
