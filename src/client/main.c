/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:39:38 by eestelle          #+#    #+#             */
/*   Updated: 2022/02/25 13:06:00 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

t_state	state;

static int	send_bit(char c)
{
	if (c)
		return (SIGUSR2);
	else 
		return (SIGUSR1);
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		bit;
	int		sig;
	int		size;

	state.state = 0;
	state.flag = 1;
	bit = 0;
	size = 0;
	state.state = 0;
	if (argc != 3)
	{
		ft_putstr_fd("", 2);
		return (0);
	}
	else 
	{
		init_signal();
		pid = ft_atoi(argv[1]);
		sig = SIGUSR1;
		if (kill(pid, sig) < 0)
		{
			ft_putstr_fd("Error: kill\n", 2);
			exit(0);
		}
		while (1)
		{
			if (state.flag)
			{	
				if (state.state == 1)
				{
					++bit;
					sig = send_bit(argv[2][size] & 0x80);
					/*
					if (sig == SIGUSR1)
						ft_putstr_fd("0", 2);
					else
						ft_putstr_fd("1", 2);
					*/
					argv[2][size] = argv[2][size] << 1;
					if (bit == 8)
					{
						size++;
						bit = 0;
					}
				}
				else if (state.state == 2)
				{
					ft_putstr_fd("Sending message finish\n", 1);
					return (0);
				}
				state.flag = 0;
				if (kill(pid, sig) < 0)
				{
					ft_putstr_fd("Error: kill\n", 2);
					exit(0);
				}
			}
		}
	}
	return (0);
}
