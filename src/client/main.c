/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle </var/spool/mail/eestelle>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:11:45 by eestelle          #+#    #+#             */
/*   Updated: 2022/02/17 18:39:08 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		printf("PID: %d\n", pid);
		//ft_init_signals();
	}
	else
		ft_putstr_fd("./client [PID Server] \"Your string\"\n", 1);
	return (0);
}
