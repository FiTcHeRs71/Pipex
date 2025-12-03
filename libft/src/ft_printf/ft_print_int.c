/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:58:01 by fducrot           #+#    #+#             */
/*   Updated: 2025/12/01 13:58:01 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_putnumb_hexa_pf(unsigned int nbr, char *base)
{
	int	len;

	len = 0;
	if (nbr >= 16)
	{
		len += ft_putnumb_hexa_pf((nbr / 16), base);
		len += ft_putnumb_hexa_pf((nbr % 16), base);
	}
	else
	{
		len += ft_putchar_pf(base[nbr]);
	}
	return (len);
}

int	ft_putnumb_unsingd_pf(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr > 9)
	{
		len += ft_putnumb_unsingd_pf(nbr / 10);
	}
	len += ft_putchar_pf((nbr % 10) + 48);
	return (len);
}

int	ft_putnumb_int_pf(int nbr)
{
	long int	n;
	int			len;

	n = nbr;
	len = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		n *= -1;
		len += 1;
	}
	if (n > 9)
	{
		len += ft_putnumb_int_pf(n / 10);
	}
	len += ft_putchar_pf((n % 10) + 48);
	return (len);
}
