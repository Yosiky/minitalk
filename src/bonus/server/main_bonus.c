/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 23:57:17 by eestelle          #+#    #+#             */
/*   Updated: 2022/03/04 11:35:18 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

t_buff32	g_buff;

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

static void	processing(void)
{
	if (g_buff.flag)
	{
		if (g_buff.sig == SIGUSR1)
			ee_buff32addbit(&g_buff, 0);
		else
			ee_buff32addbit(&g_buff, 1);
	}
	else
		g_buff.flag = 1;
	g_buff.sig = SIGUSR1;
	if (g_buff.size)
	{
		write(1, g_buff.str, 1);
		if (g_buff.str[g_buff.size - 1] == '\0')
		{
			g_buff.flag = 0;
			g_buff.sig = SIGUSR2;
		}
		else
			g_buff.sig = SIGUSR1;
		g_buff.size = 0;
	}
	g_buff.state = 0;
}

int	main(void)
{
	ee_buff32init(&g_buff);
	init_signal();
	ft_putstr_fd("PID Server: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	while (1)
	{
		if (g_buff.state)
		{
			processing();
			if (g_buff.flag || g_buff.sig == SIGUSR2)
			{
				if (kill(g_buff.pid, g_buff.sig) < 0)
				{
					ft_putstr_fd("Error: kill\n", 2);
					exit(0);
				}
			}
		}
	}
	return (0);
}
