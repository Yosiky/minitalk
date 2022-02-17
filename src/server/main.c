/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle </var/spool/mail/eestelle>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:25:17 by eestelle          #+#    #+#             */
/*   Updated: 2022/02/17 16:44:09 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	main(void)
{
	pid_t	pid;

	ft_init_signals();
	write(1, "Server PID: ", 12);
	ft_putnum_fd(getpid(), 1);
	write(1, "\n", 1);
	while (1)
	{
		pause();
	}
	return (0);
}
