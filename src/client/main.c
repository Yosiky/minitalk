/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:39:38 by eestelle          #+#    #+#             */
/*   Updated: 2022/03/04 11:20:35 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

t_state	g_state;

static int	send_bit(char c)
{
	if (c)
		return (SIGUSR2);
	else
		return (SIGUSR1);
}

static int	processing(char *str, int *bit, int *size)
{
	int	sig;

	sig = SIGUSR1;
	if (g_state.state == 1)
	{
		(*bit)++;
		sig = send_bit(str[*size] & 0x80);
		str[*size] = str[*size] << 1;
		if (*bit == 8)
		{
			(*size)++;
			*bit = 0;
		}
	}
	else if (g_state.state == 2)
	{
		ft_putstr_fd("Sending message finish\n", 1);
		exit(0);
	}
	return (sig);
}

static void	server(pid_t pid, char **argv)
{
	int		bit;
	int		sig;
	int		size;

	bit = 0;
	size = 0;
	while (1)
	{
		if (g_state.flag)
		{	
			sig = processing(argv[2], &bit, &size);
			g_state.flag = 0;
			if (kill(pid, sig) < 0)
			{
				ft_putstr_fd("Error: kill\n", 2);
				exit(0);
			}
		}
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	g_state.state = 0;
	g_state.flag = 1;
	if (argc != 3)
	{
		ft_putstr_fd("Error: You need input:\n./client [PID] [STRING]\n", 2);
		return (0);
	}
	else
	{
		init_signal();
		pid = ft_atoi(argv[1]);
		if (kill(pid, SIGUSR1) < 0)
		{
			ft_putstr_fd("Error: kill\n", 2);
			exit(0);
		}
		server(pid, argv);
	}
	return (0);
}
