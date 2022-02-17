/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle </var/spool/mail/eestelle>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:07:22 by eestelle          #+#    #+#             */
/*   Updated: 2022/02/18 00:50:11 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <sys/types.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

typedef struct s_message
{
	char	*str;
	pid_t	pid;
}	t_message;

int		ft_atoi(const char *str);
void	ft_putstr_fd(char *str, int fd);
void	ft_init_signals(void);

extern t_message	message;

#endif
