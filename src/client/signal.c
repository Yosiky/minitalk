/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle </var/spool/mail/eestelle>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:46:11 by eestelle          #+#    #+#             */
/*   Updated: 2022/02/18 10:46:53 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void	send_char()
{
	static int	i = 0;
	int	sig;

	i++;
	if (0x80 & *(message.str))
		sig = SIGUSR2;
	else
		sig = SIGUSR1;
	*(message.str) <<= 1;
	if (i == 8)
	{
		++message.str;
		i = 0;
	}
	if (kill(message.pid, sig) < 0)
	{
		ft_putstr_fd("Error: kill\n", 2);
		exit(0);
	}
	
}

static void	recive_answer(int sig)
{
	(void)sig;
	ft_putstr_fd("Answer is server\n", 1);
	if (kill(message.pid, SIGUSR2) < 0)
		ft_putstr_fd("Error: kill", 1);
	exit(0);
}

static void	send_message(int sig)
{

	(void)sig;
//	ft_putstr_fd("send bit\n", 1);
	send_char();
}

void	ft_init_signals(void)
{
	struct sigaction	act;
	sigset_t			set;

	if (sigemptyset(&set) || sigaddset(&set, SIGUSR1))
	{
		ft_putstr_fd("Error: initial signal SIGUSR1\n", 2);
		exit(1);
	}
	act.sa_handler = send_message;
	act.sa_mask = set;
	sigaction(SIGUSR1, &act, NULL);
	if (sigemptyset(&set) || sigaddset(&set, SIGUSR2))
	{
		ft_putstr_fd("Error: initial signal SIGUSR2\n", 2);
		exit(2);
	}
	act.sa_handler = recive_answer;
	act.sa_mask = set;
	sigaction(SIGUSR2, &act, NULL);
}
