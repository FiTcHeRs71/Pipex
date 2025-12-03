/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdcurot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:33:48 by fdcurot           #+#    #+#             */
/*   Updated: 2025/10/06 14:33:48 by fdcurot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!src && !dest)
	{
		return (dest);
	}
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (n-- > 0)
	{
		*d++ = *s++;
	}
	return (dest);
}

/*
MEMCPY(3) (simplified)

NAME
    memcpy -- copy memory area
SYNOPSIS
    void *memcpy(void *dst, const void *src, size_t n);
DESCRIPTION
    The memcpy() function copies n bytes from memory area src 
	to memory area dst. If dstt and src overlap, behavior is undefined.
	 Applications in which dst and src might overlap should use memove(3) 
	 instead.
RETURN VALUES
    The memcpy() function returns the original value of dst
	*/