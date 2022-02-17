/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle </var/spool/mail/eestelle>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:34:16 by eestelle          #+#    #+#             */
/*   Updated: 2022/02/17 18:37:08 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
	{
		if (*(ptr) == (unsigned char)c)
			return ((void *)ptr);
		ptr++;
	}
	return ((void *)0);
}

static size_t	ft_strlen(const char *s)
{
	return ((size_t)ft_memchr(s, '\0', -1) - (size_t)s);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}
