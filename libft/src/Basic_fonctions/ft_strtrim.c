/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdcurot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:35:52 by fdcurot           #+#    #+#             */
/*   Updated: 2025/10/07 08:47:08 by fdcurot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*str;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
	{
		return (NULL);
	}
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
	{
		start++;
	}
	while (end > start && ft_strrchr(set, s1[end]))
	{
		end--;
	}
	str = ft_substr(s1, start, end - start + 1);
	if (!str)
	{
		return (NULL);
	}
	return (str);
}

/*
FT_STRTRIM (simplified)

NAME
    ft_strtrim -- trims character set from string
SYNOPSIS
    char *ft_strtrim(const char *s1, const char *set);
DESCRIPTION
    Allocate (with malloc(3)) and returns a copy of s1, 
	without the characters specified in set at the beginning 
	and the end of s1.
PARAMETERS
    s1: string to trim
    set: characters to trim
RETURN VALUES
    ft_strtrim() returns a trimmed copy of s1; 
	NULL if the memory allocation failed.
AUTHORIZED EXTERNAL FUNCTIONS
    malloc(3)
	*/