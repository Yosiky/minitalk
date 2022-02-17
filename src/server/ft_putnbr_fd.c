/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle </var/spool/mail/eestelle>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:42:55 by eestelle          #+#    #+#             */
/*   Updated: 2022/02/17 16:43:18 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ft_putnbr_fd(int n, int fd)
{
	char		arr[10];
	size_t		len;
	long long	value;

	value = n;
	if (value < 0)
	{
		write(fd, "-", 1);
		value *= -1;
	}
	else if (value == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	len = 0;
	while (value)
	{
		arr[10 - 1 - (len++)] = '0' + value % 10;
		value /= 10;
	}
	write(fd, arr + 10 - len, len);
}
