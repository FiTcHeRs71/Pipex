/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdcurot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:34:02 by fdcurot           #+#    #+#             */
/*   Updated: 2025/10/06 14:34:02 by fdcurot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)s;
	while (len-- > 0)
	{
		*tmp++ = (unsigned char)c;
	}
	return (s);
}

/*
MEMSET(3) (simplified)

NAME
    memset -- fill a byte string with a byte value
SYNOPSIS
    void *memset(void *b, int c, size_t len);
DESCRIPTION
    The memset() function writes len bytes of value c 
	(converted to an unsigned char) to the string b.
RETURN VALUES
    The memset() function returns its first argument.
	*/