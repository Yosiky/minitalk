/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 00:30:15 by eestelle          #+#    #+#             */
/*   Updated: 2022/02/24 22:41:09 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void	start_communication(siginfo_t *info, t_buff32 *buff)
{
	buff->flag = 1;
	buff->pid = info->si_pid;
	buff->sig = SIGUSR1;
}

static void	processing(int sig, siginfo_t *info, __attribute__((unused)) void *ptr)
{
	static t_buff32	buff = {"", 0, 0, 0, 0, 0};

	buff.str[32] = '\0';
	if (buff.flag == 0)
	{
		start_communication(info, &buff);
	}
	else if (buff.flag == 1)
	{
		if (sig == SIGUSR1)
			ee_buff32addbit(&buff, 0);
		else
			ee_buff32addbit(&buff, 1);
	}
	//if ((buff.size > 0 && buff.str[buff.size - 1] == '\0') || buff.size == 32)
	if (buff.size)
	{
		write(1, buff.str, 1);
		//ft_putstr_fd(buff.str, 1);
		if (buff.str[buff.size - 1] == '\0')
		{
			buff.flag = 0;
			buff.sig = SIGUSR2;
		}
		else

			buff.sig = SIGUSR1;
		buff.size = 0;
	}
	if (kill(buff.pid, buff.sig) < 0)
	{
		ft_putstr_fd("Error: kill\n", 2);
		exit(0);
	}
}

void	init_signal(void)
{
	struct sigaction	act;
	sigset_t			set;

	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	act.sa_mask = set;
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = processing;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
}
