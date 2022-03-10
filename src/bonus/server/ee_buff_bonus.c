/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ee_buff.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 01:12:44 by eestelle          #+#    #+#             */
/*   Updated: 2022/02/24 22:13:06 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ee_buff32addbit(t_buff32 *buff, int bit)
{
	if (buff->count_bit == 0)
		buff->str[buff->size] = -1;
	buff->str[buff->size] <<= 1;
	buff->str[buff->size] += bit;
	++buff->count_bit;
	if (buff->count_bit == 8)
	{
		++buff->size;
		buff->count_bit = 0;
		buff->str[buff->size] = -1;
	}		
}
