/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle </var/spool/mail/eestelle>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:20:54 by eestelle          #+#    #+#             */
/*   Updated: 2022/02/17 18:32:14 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static	int	ft_isspace(int c)
{
	return (c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v' || c == ' ');
}

static	int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int	ft_atoi(const char *str)
{
	int		result;
	char	sign;

	result = 0;
	sign = 1;
	while (ft_isspace(*(str)))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*(str++) == '-')
			sign = -1;
	}
	while (*str != '\0' && ft_isdigit(*str))
	{
		if (result < 0)
		{
			if (sign == 1)
				return (-1);
			else
				return (0);
		}
		result = result * 10 + (*(str++) - '0');
	}
	return (result * (int)sign);
}
