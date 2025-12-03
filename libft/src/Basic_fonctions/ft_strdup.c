/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdcurot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:34:44 by fdcurot           #+#    #+#             */
/*   Updated: 2025/10/07 08:41:12 by fdcurot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*dest;

	len = ft_strlen(s1);
	i = 0;
	dest = ft_calloc(len + 1, sizeof(char));
	if (!dest)
	{
		return (NULL);
	}
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
STRDUP(3) (simplified)

NAME
    strdup -- save a copy of a string
SYNOPSIS
    char *strdup(const char *s1);
DESCRIPTION
    The strdup() function allocates sufficient memory for a copy of the 
	string s1, does the copy, and returns a pointer to it. The pointer may 
	subsequently be used as an argument to the function free(3).
    If insufficient memory is available, NULL is returned and errno is
	 set to ENOMEM.
	 */