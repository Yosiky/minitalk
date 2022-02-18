/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle </var/spool/mail/eestelle>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 03:38:06 by eestelle          #+#    #+#             */
/*   Updated: 2022/02/18 10:46:21 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static int	start_communication(int sig, siginfo_t *info, t_string32 *sym)
{
	//ft_putstr_fd("communication\n", 1);
	if (sig == SIGUSR1 && sym->flag == 1)
	{
		sym->bit = 0;
		sym->flag = 0;
		sym->count = 0;
		sym->pid = info->si_pid;
		if (kill(info->si_pid, SIGUSR1) < 0)
		{
			write(2, "Error: kill\n", 12);
			exit(2);
		}
	//	ft_putstr_fd("start\n", 1);
	}
	else if (sig == SIGUSR2 && sym->flag == 2 && sym->pid == info->si_pid)
	{
		ft_putstr_fd(sym->arr, 1);
		sym->flag = 1;
	}
	return (1);
}

static void	recive_message(int sig, siginfo_t *info, __attribute__((unused)) void *ptr)
{
	static t_string32	sym = {1, "", 0, 0, 0};

	if (sym.flag)
		if (start_communication(sig, info, &sym))
			return ;
	if (info->si_pid != sym.pid)
		return ;
	if (sig == SIGUSR2)
		sym.arr[sym.count] |= 0x01;
	if (sym.bit++ < 7)
		sym.arr[sym.count] <<= 1;
	else if (sym.bit == 8)
	{
		sym.bit = 0;
		++sym.count;
		if (sym.arr[sym.count - 1] == '\0')
		{
			sym.flag = 2;
			if (kill(sym.pid, SIGUSR2) < 0)
			{
				write(2, "Error: kill\n", 12);
				exit(1);
			}
			else
				return ;
		}
	}
	if (kill(sym.pid, SIGUSR1) < 0)
	{
		write(2, "Error: kill\n", 12);
		exit(1);
	}
}

int	ft_init_signals(void)
{
	struct sigaction	act;
	sigset_t			set;

	if (sigemptyset(&set) || sigaddset(&set, SIGUSR1) || sigaddset(&set, SIGUSR2))
		return (-1);
	act.sa_flags = SA_SIGINFO;
	act.sa_mask = set;
	act.sa_sigaction = recive_message;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	return (0);
}
