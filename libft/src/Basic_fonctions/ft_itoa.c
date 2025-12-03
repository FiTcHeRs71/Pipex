/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdcurot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:31:47 by fdcurot           #+#    #+#             */
/*   Updated: 2025/10/07 08:54:54 by fdcurot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_int(int nbr)
{
	int	count;

	count = 0;
	if (nbr == 0)
	{
		count = 1;
		return (count);
	}
	if (nbr < 0)
	{
		nbr *= -1;
		count++;
	}
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	size_t		i;
	size_t		len;
	long int	nbr;
	char		*result;

	i = 0;
	len = ft_count_int(n);
	nbr = n;
	result = ft_calloc(len + 1, sizeof(char));
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (nbr < 0)
	{
		result[0] = '-';
		nbr *= -1;
		i++;
	}
	while (len > i)
	{
		len--;
		result[len] = (nbr % 10) + 48;
		nbr /= 10;
	}
	return (result);
}

/*
FT_ITOA (simplified)

NAME
    ft_itoa -- convert an int to a string
SYNOPSIS
    char *ft_itoa(int n);
DESCRIPTION
    Allocate (with malloc(3)) and returns a string representing n.
    Negative numbers must be handled.
PARAMETERS
    n: int to convert
RETURN VALUES
    ft_itoa() returns the string representing n; NULL if
	 the memory allocation failed.
AUTHORIZED EXTERNAL FUNCTIONS
    malloc(3)
	*/