/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:53:51 by eestelle          #+#    #+#             */
/*   Updated: 2022/02/25 10:33:07 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include <stdlib.h>

void	init_signal(void);
void	ft_putnbr_fd(int value, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *str);

extern volatile sig_atomic_t state;

#endif
