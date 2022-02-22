/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ee_buff.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle </var/spool/mail/eestelle>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 01:12:44 by eestelle          #+#    #+#             */
/*   Updated: 2022/02/23 01:23:31 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ee_buff32addbit(t_buff32 *buff, int bit)
{
	if (buff->count_bit == 0)
		buff->str[buff->size] = 0;
	buff->str[buff->size] |= bit;
	buff->count_bit = (buff->count_bit + 1) & 0x00000007;
	if (buff->count_bit == 0)
		++buff->size;
	else
		buff->str[buff->size] <<= 1;
}
