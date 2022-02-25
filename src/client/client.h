/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:53:51 by eestelle          #+#    #+#             */
/*   Updated: 2022/02/25 13:19:20 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include <stdlib.h>

typedef struct s_state
{
	volatile sig_atomic_t	state;
	int						flag;
}	t_state;

void	init_signal(void);
void	ft_putnbr_fd(int value, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *str);

extern t_state	g_state;

#endif
