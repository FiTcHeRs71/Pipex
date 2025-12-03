/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdcurot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:28:16 by fdcurot           #+#    #+#             */
/*   Updated: 2025/10/06 14:28:16 by fdcurot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/*
ISALPHA(3) (simplified)

NAME
    isalpha -- alphabetic character test
SYNOPSIS
    int isalpha(int c)
DECRIPTION
    The isalpha() function tests for any character for which isupper(3) 
	or islower(3) is true. 
	The value of the argument must be resprensentable as an unsigned char 
	or the value of EOF.

RETURN VALUES
    The isalpha() function return zero if the character 
	tests false and returns non-zero if the character tests true.
*/