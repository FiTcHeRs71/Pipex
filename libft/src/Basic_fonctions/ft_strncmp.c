/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdcurot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:35:28 by fdcurot           #+#    #+#             */
/*   Updated: 2025/10/06 14:35:28 by fdcurot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	while ((*tmp1 || *tmp2) && (n > 0))
	{
		if (*tmp1 != *tmp2)
		{
			return (*tmp1 - *tmp2);
		}
		tmp1++;
		tmp2++;
		n--;
	}
	return (0);
}

/*
STRNCMP(3) (simplified)

NAME
    strncmp -- compare strings
SYNOPSIS
    int strncmp(const char *s1, const char *s2, size_t n);
DESCRIPTION
    The strncmp() function lexicographically compare the null-terminated 
	strings s1 and s2.
    The strncmp() function compares not more than n characters. 
	Because strncmp() is designed for comparing strings rather than binary data,
	 characters that appear after a '\0' character are not compared.
RETURN VALUES
    The strncmp() function returns an integer greater than, equal to, 
	or less than 0, according as the string s1 is greater than, equal to, 
	or less than the string s2. The comparison is done using unsigned 
	characters, 
	so that '\200' is greater than '\0'.
	*/