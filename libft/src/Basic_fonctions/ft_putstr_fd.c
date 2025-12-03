/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdcurot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:34:23 by fdcurot           #+#    #+#             */
/*   Updated: 2025/10/07 10:56:53 by fdcurot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

/*
NAME
	ft_putstr_fd -- write a string on a specified file descriptor
SYNOPSIS
	void ft_putstr_fd(char *s, int fd);
DESCRIPTION
	Write the string s on the file descriptor fd.
PARAMETERS
	s: string to write
	fd: file descriptor on which to write
RETURN VALUES
	ft_putstr_fd() does not return anything
AUTHORIZED EXTERNAL FUNCTIONS
	write(2)
	*/