/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:38:43 by fducrot           #+#    #+#             */
/*   Updated: 2025/12/09 11:38:53 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	command_error(char *message, char *command)
{
	ft_putstr_fd(message, 2);
	ft_putendl_fd(command, 2);
}