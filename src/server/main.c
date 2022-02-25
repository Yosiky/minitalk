/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 23:57:17 by eestelle          #+#    #+#             */
/*   Updated: 2022/02/25 13:05:47 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_buff32	buff;

static void	ee_buff32init(t_buff32 *buff)
{
	buff->flag = 0;
	buff->sig = 0;
	buff->str[0] = 0;
	buff->size = 0;
	buff->count_bit = 0;
	buff->pid = 0;
	buff->state = 0;
}

int	main(void)
{
	ee_buff32init(&buff);
	init_signal();
	ft_putstr_fd("PID Server: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	while (1)
	{
		if (buff.state)
		{
			if (buff.flag)
			{
				/*
				if (buff.sig == SIGUSR1)
					ft_putstr_fd("0", 2);
				else
					ft_putstr_fd("1", 2);
					*/
				if (buff.sig == SIGUSR1)
					ee_buff32addbit(&buff, 0);
				else
					ee_buff32addbit(&buff, 1);
			}
			else
				buff.flag = 1;
			buff.sig = SIGUSR1;
			if (buff.size)
			{
				write(1, buff.str, 1);
				//ft_putstr_fd(buff.str, 1);
				if (buff.str[buff.size - 1] == '\0')
				{
					buff.flag = 0;
					buff.sig = SIGUSR2;
					//ft_putstr_fd("|END|", 2);
				}
				else
					buff.sig = SIGUSR1;
				buff.size = 0;
			}
			buff.state = 0;
			if (buff.flag || buff.sig == SIGUSR2)
			{
				if (kill(buff.pid, buff.sig) < 0)
				{
					ft_putstr_fd("Error: kill\n", 2);
					exit(0);
				}
			}
		}
	}
	return (0);
}
