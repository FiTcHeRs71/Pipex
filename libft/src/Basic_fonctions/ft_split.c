/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourlogin <youremail@student.42lausanne.ch>    +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 16:39:40 by yourlogin         #+#    #+#             */
/*   Updated: 2025/10/09 16:39:58 by yourlogin        ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(char **tab, size_t count)
{
	while (count > 0)
	{
		free(tab[count - 1]);
		count--;
	}
	free(tab);
}

size_t	ft_counter_of_str(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		count++;
		while ((s[i] && s[i] != c))
			i++;
	}
	return (count);
}

char	**ft_complet_array(char **array_of_string, char c, char const *s)
{
	size_t	i;
	size_t	start;
	size_t	y;

	i = 0;
	y = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		array_of_string[y] = ft_substr(s, start, i - start);
		if (!array_of_string[y])
		{
			return (ft_free(array_of_string, y), NULL);
		}
		y++;
	}
	array_of_string[y] = NULL;
	return (array_of_string);
}

char	**ft_split(char const *s, char c)
{
	char	**array_of_string;
	size_t	count;

	if (!s)
		return (NULL);
	count = ft_counter_of_str(s, c);
	array_of_string = ft_calloc(count + 1, sizeof(char *));
	if (!array_of_string)
	{
		return (NULL);
	}
	if (!ft_complet_array(array_of_string, c, s))
	{
		return (NULL);
	}
	return (array_of_string);
}
/*
FT_SPLIT (simplified)

NAME
    ft_split -- split a string into an array of words
SYNOPSIS
    char **ft_split(const char *s, char c);
DESCRIPTION
    Allocate (with malloc(3)) and returns an array of strings 
	obtained by splitting s with the character c, used as delimiter.
    The returned array must be NUL-terminated.
PARAMETERS
    s: string to split
    c: delimiter character
RETURN VALUES
    ft_split() returns an array of strings resulting 
	from the splitting of s; NULL if the memory allocation failed.
AUTHORIZED EXTERNAL FUNCTIONS
    malloc(3)
	*/