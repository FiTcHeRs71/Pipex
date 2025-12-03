/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdcurot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:34:49 by fdcurot           #+#    #+#             */
/*   Updated: 2025/10/06 20:39:57 by fdcurot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s)
	{
		return ;
	}
	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}

/*
FT_STRITERI (simplified)

NAME
    ft_striteri -- apply a function to each character of a string 
	(index specified)
SYNOPSIS
    void ft_striteri(char *s, void (*f)(unsigned int, char*));
DESCRIPTION
    Apply the function 'f' to each characters of the string 's', 
	passing its index as a first parameter.
    Each character is transmitted by address to 'f' so it can be
	 modified if necessary.
	 */