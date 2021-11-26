/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo_1_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:13:25 by gnaida            #+#    #+#             */
/*   Updated: 2021/11/26 17:13:28 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r')
		return (1);
	return (0);
}

static int	out_of_bounds(char c, int sign)
{
	if (c == '8' && sign == 1)
		return (-1);
	else if (c >= '8' && sign == -1)
		return (0);
	else if (c == '7' && sign == 1)
		return (-1);
	else if (c == '7' && sign == -1)
		return (1);
	return (-1);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	i;
	int	sign;

	result = 0;
	i = 0;
	sign = 1;
	while (isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = 1 - 2 * (str[i++] == '-');
	while (ft_isdigit(str[i]))
	{
		if (i == 19)
			return (out_of_bounds(str[i], sign));
		if (i > 19)
		{
			if (sign == 1)
				return (-1);
			if (sign == -1)
				return (0);
		}
		result = result * 10 + (str[i++] - '0');
	}
	return (sign * result);
}
