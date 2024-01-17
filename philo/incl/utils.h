/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 15:03:36 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/01/17 15:22:55 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <stddef.h>

int		ft_atoi(const char *nptr);
int		ft_is_integer(char *str);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
