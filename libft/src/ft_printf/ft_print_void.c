/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_void.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 08:43:20 by fducrot           #+#    #+#             */
/*   Updated: 2025/10/10 08:43:28 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_print_adress(unsigned long long adrs, char *base)
{
	int	len;

	len = 0;
	if (adrs >= 16)
	{
		len += ft_print_adress((adrs / 16), base);
		len += ft_print_adress((adrs % 16), base);
	}
	else
	{
		len += ft_putchar_pf(base[adrs]);
	}
	return (len);
}

int	ft_putvoid_pf(unsigned long long adrs, char *base)
{
	int	len;

	len = 0;
	if (!adrs)
	{
		return (ft_putstr_pf("(nil)"));
	}
	len += ft_putstr_pf("0x");
	len += ft_print_adress(adrs, base);
	return (len);
}
