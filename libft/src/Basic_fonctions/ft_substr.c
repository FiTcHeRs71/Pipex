/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdcurot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:35:59 by fdcurot           #+#    #+#             */
/*   Updated: 2025/10/07 08:46:02 by fdcurot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	real_len;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	real_len = ft_strlen(s) - start;
	if (real_len > len)
		real_len = len;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	str = ft_calloc(real_len + 1, sizeof(char));
	if (!str)
	{
		return (NULL);
	}
	while (i < real_len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*
FT_SUBSTR (simplified)

NAME
    ft_substr -- extract a substring from a string
SYNOPSIS
    char *ft_substr(const char *s, unsigned int start, size_t len);
DESCRIPTION
    Allocate (with malloc(3)) and return a new string from the string s.
    This new string starts at index 'start' and has a maximum size of 'len'.
PARAMETERS
    s: string from which to extract the new string
    start: start index of the new string in the string 's'
    len: maximum size of the new string
RETURN VALUES
    ft_substr() returns the new string; NULL if the memory allocation failed.
AUTHORIZED EXTERNAL FUNCTIONS
    malloc(3)
	*/