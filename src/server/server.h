/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle </var/spool/mail/eestelle>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:42:23 by eestelle          #+#    #+#             */
/*   Updated: 2022/02/17 16:48:52 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <sys/types.h>
# include <unistd.h>
# include "../../ft_printf/src/ft_printf.h"

typedef	struct s_string32
{
	int		flag;
	char	arr[32];
	int32_t	bit;
	int32_t	count;
	t_pid	pid;
}	t_string32;

void	ft_putnbr_fd(int n, int fd);
void	ft_init_signals(void);

#endif

