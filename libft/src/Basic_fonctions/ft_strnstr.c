/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:28:15 by fducrot           #+#    #+#             */
/*   Updated: 2025/12/01 14:28:15 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] && little[j] && big[i + j] == little[j] && i
			+ j < len)
		{
			j++;
		}
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

/*
STRNSTR(3) (simplified)

NAME
    strnstr -- locate a substring in a string
SYNOPSIS
    char *strnstr(const char *big, const char *little, size_t len);
DESCRIPTION
    The strnstr() function locates the first occurence of the 
	null-terminated string little in the string big, 
	where not more than len characters are searched.
    Characters that appear after a '\0' character are not searched.
RETURN VALUES
    If little is an empty string, big is returned; if little 
	occurs nowhere in big, NULL is returned; otherwise a pointer 
	to the first character of the first occurence of little is returned.
	*/