/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdcurot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:31:34 by fdcurot           #+#    #+#             */
/*   Updated: 2025/10/06 14:31:34 by fdcurot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/*
ISDIGIT(3) (simplified)

NAME
    isdigit -- decimal-digit character test
SYNOPSIS
    int isdigit(int c)
DESCRIPTION
    The isdigit() function tests for a decimal digit character.
    The value of the argument must be representable as an 
	unsigned char or the value of EOF.
RETURN VALUES
    The isdigit() function return zero if the character tests false 
	and return non-zero if the character tests true.
	*/