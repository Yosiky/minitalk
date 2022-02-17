/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle </var/spool/mail/eestelle>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 03:38:06 by eestelle          #+#    #+#             */
/*   Updated: 2022/02/17 16:46:36 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static int	check_state(int sig, siginfo_t *info, t_symbol *sym)
{
	if (sig == SIGUSR1)
	{
		if (kill(info->si_pid, SIGUSR1) < 0)
		{
			write(2, "Error: kill\n", 12);
			exit(2);
		}
		sym->bit = 256;
		sym->flag = 0;
		sym->count = 0;
		sym->pid = info->si_pid;
	}
	else if (sym->pid == info->si_pid)
		sym->flag = 1;
	return (sym->flag);
}

static void	recive_message(int sig, siginfo_t *info, void *ptr)
{
	static t_string32	sym;

	if (sym.flag == 1)
		if (start_communication(sig, info, &sym))
			return ;
	if (info->si_pid != sym->pid)
		return ;
	--sym.bit;
	if (sig == SIGUSR2)
		sym.arr[sym.bit] |= 1 << sym.bit;
	if (sym.bit % 8 == 0)
	{
		++sym.count;
		if (sym.count == 32 || sym.arr[sym.count - 1] == '\0')
			write(1, sym.arr, sym.count);
		if (sym.arr[sym.count - 1] == '\0')
			if (kill(pid, SIGUSR2) < 0)
			{
				write(2, "Error: kill\n", 12);
				sym.symbol = flag;
				exit(1);
			}
	}
}

int32_t	ft_init_signal(void)
{
	struct sigaction	act;
	sigset_t			set;

	if (sigemptyset(&set) || sigaddset(&set, SIGUSR1) || sigaddset(&set, SIGUSR2))
		return (-1);
	act.sa_flag = SA_SIGINFO;
	act.sa_mask = set;
	act.sa_sigaction = recive_message;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	return (0);
}
