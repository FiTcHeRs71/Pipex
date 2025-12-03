/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdcurot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:34:54 by fdcurot           #+#    #+#             */
/*   Updated: 2025/10/07 08:52:29 by fdcurot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			len_s1;
	size_t			len_s2;
	unsigned int	i;
	unsigned int	j;
	char			*str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	i = 0;
	j = 0;
	str = ft_calloc(len_s1 + len_s2 + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	return (str);
}

/*
FT_STRJOIN (simplified)

NAME
    ft_strjoin -- concatenate 2 strings in a new string
SYNOPSIS
    char *ft_strjoin(const char *s1, const char *s2);
DESCRIPTION
    Allocate (with malloc(3)) and returns a new string 
	resulting from the concatenation of s1 and s2.
PARAMETERS
    s1: prefix string
    s2: suffix string
RETURN VALUES
    ft_strjoin() returns the new string; NULL if the memory 
	allocation failed.
AUTHORIZED EXTERNAL FUNCTIONS
    malloc(3)
	*/