/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:56:02 by eestelle          #+#    #+#             */
/*   Updated: 2022/02/25 13:04:39 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void	processing(int sig, __attribute__((unused)) siginfo_t *info, __attribute__((unused)) void *ptr)
{
	state.flag = 1;
	if (sig == SIGUSR1)
	{
		//ft_putstr_fd("0", 1);
		state.state = 1;
	}
	if (sig == SIGUSR2)
	{
		//ft_putstr_fd("1", 1);
		state.state = 2;
	}

}

void	init_signal(void)
{
	struct sigaction	act;
	sigset_t			set;
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	act.sa_mask = set;
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = processing;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
}
