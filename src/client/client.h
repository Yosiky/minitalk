/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle </var/spool/mail/eestelle>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:07:22 by eestelle          #+#    #+#             */
/*   Updated: 2022/02/17 18:38:53 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <sys/types.h>
# include <unistd.h>
# include <signal.h>

int		ft_atoi(const char *str);
void	ft_putstr_fd(const char *str, int fd);

#endif
