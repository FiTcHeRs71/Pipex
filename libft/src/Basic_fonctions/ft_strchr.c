/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdcurot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:34:38 by fdcurot           #+#    #+#             */
/*   Updated: 2025/10/06 14:34:38 by fdcurot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	if ((char)c == '\0')
	{
		return ((char *)s);
	}
	return (NULL);
}

/*
STRCHR(3) (simplified)

NAME
    strchr -- locate character in string
SYNOPSIS
    char *strchr(const char *s, int c);
DESCRIPTION
    The strchr() function locates the first occurence of c (converted to a char) 
	in the string pointed to by s. The terminating null character is considered 
	to be part of the string; therefor if c is '\0', the function locate the 
	terminating '\0'.
RETURN VALUES
    The function strchr() return a pointer to the located character, or NULL 
	if the character does not appear in the string.
	*/