/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdcurot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:28:04 by fdcurot           #+#    #+#             */
/*   Updated: 2025/10/06 14:28:04 by fdcurot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/*
ISALNUM(3) (simplified)

NAME
    isalnum -- alphanumeric character test
SYNOPSIS
    int isalnum(int c)
DESCRIPTION
    The isalnum() function tests for any character for which isalpha(3) or 
	isdigit(3) is true. The value of the argument must be representable 
	as an unsigned char or the value of EOF.
RETURN VALUES
    The isalnum() function returns zero if the character tests 
	false and returns non-zero if the character tests true.
	*/