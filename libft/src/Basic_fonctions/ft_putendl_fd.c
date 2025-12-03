/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdcurot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:34:14 by fdcurot           #+#    #+#             */
/*   Updated: 2025/10/06 14:34:17 by fdcurot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

/*FT_PUTENDL_FD (simplified)

NAME
	ft_putendl_fd -- write a string on a specified file descriptor,
		follow by a newline
SYNOPSIS
	void ft_putendl_fd(char *s, int fd);
DESCRIPTION
	ft_putendl_fd() writes the string s, followed by a newline,
		on the file descriptor fd
PARAMETERS
	s: string to write
	fd: the file descriptor on which to write
RETURN VALUES
	ft_putendl_fd() does not return anything
AUTHORIZED EXTERNAL FUNCTIONS
	write(2)
	*/