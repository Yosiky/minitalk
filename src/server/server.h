/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle </var/spool/mail/eestelle>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:42:23 by eestelle          #+#    #+#             */
/*   Updated: 2022/02/17 17:59:52 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <sys/types.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

typedef	struct s_string32
{
	int		flag;
	char	arr[32];
	int32_t	bit;
	int32_t	count;
	pid_t	pid;
}	t_string32;

void	ft_putnbr_fd(int n, int fd);
int		ft_init_signals(void);

#endif

