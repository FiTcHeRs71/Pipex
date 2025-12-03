/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:58:32 by fducrot           #+#    #+#             */
/*   Updated: 2025/12/01 11:58:32 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>

/* ft_printf.c */

int	ft_printf(const char *str, ...);

/* parse.c */

int	ft_format(va_list arg, char format, int len);

/* ft_print_char.c */

int	ft_putstr_pf(char *str);
int	ft_putchar_pf(int c);

/* ft_print_void.c */

int	ft_putvoid_pf(unsigned long long adrs, char *base);
int	ft_print_adress(unsigned long long adrs, char *base);

/* ft_print_int.c */

int	ft_putnumb_hexa_pf(unsigned int nbr, char *base);
int	ft_putnumb_unsingd_pf(unsigned int nbr);
int	ft_putnumb_int_pf(int nbr);

#endif