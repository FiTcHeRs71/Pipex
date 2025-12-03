/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:57:40 by fducrot           #+#    #+#             */
/*   Updated: 2025/12/01 13:57:54 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_putstr_pf(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		return (ft_putstr_pf("(null)"));
	}
	while (str[i])
	{
		write(1, &str[i], 1),
		i++;
	}
	return (i);
}

int	ft_putchar_pf(int c)
{
	write(1, &c, 1);
	return (1);
}
