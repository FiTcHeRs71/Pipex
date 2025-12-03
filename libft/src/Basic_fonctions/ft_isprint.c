/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdcurot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:31:41 by fdcurot           #+#    #+#             */
/*   Updated: 2025/10/06 14:31:41 by fdcurot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
	{
		return (0);
	}
}

/*
ISASCII(3) (simplified)

NAME
    isascii -- test for ASCII character
SYNOPSIS
    int isascii(int c)
DESCRIPTION
    The isascii() function tests for an ASCII character, 
	which is any character between 0 and octal 0177 inclusive.*/