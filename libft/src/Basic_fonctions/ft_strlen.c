/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:20:57 by fducrot           #+#    #+#             */
/*   Updated: 2025/12/08 15:22:42 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

/*
STRLEN(3) (simplified)

NAME
    strlen -- find length of string
SYNOPSIS
    size_t(const char *s);
DESCRIPTION
    The strlen() function computes the length of the string s.
RETURN VALUES
    The strlen() function returns the number of characters that precede 
	the terminating NUL character.
	*/