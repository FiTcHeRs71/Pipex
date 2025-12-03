/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdcurot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:27:43 by fdcurot           #+#    #+#             */
/*   Updated: 2025/10/06 14:27:43 by fdcurot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*
BZERO(3) (simplified)

NAME
    bzero -- write zeroes to a bye string
SYNOPSIS
    void bzero(void *s, size_t n);
DESCRIPTION
    The bzero() function writes n zeroed bytes to the string s. 
	If n is zero, bzero() does nothing.
	*/