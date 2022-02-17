/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle </var/spool/mail/eestelle>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:11:45 by eestelle          #+#    #+#             */
/*   Updated: 2022/02/17 18:49:58 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		ft_init_signals();
		if (kill(pid, SIGUSR1) < 0)
			write(2, "Error: kill\n", 12);
		while (1)
			pause();
	}
	else
		ft_putstr_fd("./client [PID Server] \"Your string\"\n", 1);
	return (0);
}
