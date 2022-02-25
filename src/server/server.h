/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 23:56:12 by eestelle          #+#    #+#             */
/*   Updated: 2022/02/25 11:52:16 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERFER_H

# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include <stdlib.h>

typedef struct s_buff32
{
	char	str[33];
	size_t	size;
	size_t	count_bit;
	pid_t	pid;
	char	flag;
	volatile sig_atomic_t	sig;
}	t_buff32;

extern t_buff32	buff;

void	init_signal(void);
void	ft_putnbr_fd(int value, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ee_buff32addbit(t_buff32 *buff, int bit);

#endif

