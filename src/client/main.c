/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle </var/spool/mail/eestelle>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:11:45 by eestelle          #+#    #+#             */
/*   Updated: 2022/02/18 00:53:12 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"


t_message	message;

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		ft_init_signals();
		message.str = argv[2];
		message.pid = ft_atoi(argv[1]);
		if (kill(message.pid, SIGUSR1) < 0)
			write(2, "Error: kill\n", 12);
		ft_putstr_fd("Yes, I send signal on server\n", 1);
		while (1)
			pause();
	}
	else
		ft_putstr_fd("./client [PID Server] \"Your string\"\n", 1);
	return (0);
}
