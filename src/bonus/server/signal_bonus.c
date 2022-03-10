/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 00:30:15 by eestelle          #+#    #+#             */
/*   Updated: 2022/02/25 13:30:27 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

static void	processing(int sig, siginfo_t *info,
	__attribute__((unused)) void *ptr)
{
	g_buff.state = 1;
	if (g_buff.flag == 0)
	{
		g_buff.pid = info->si_pid;
		g_buff.sig = SIGUSR1;
	}
	else if (g_buff.flag == 1)
		g_buff.sig = sig;
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
