/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdcurot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:31:59 by fdcurot           #+#    #+#             */
/*   Updated: 2025/10/06 20:44:56 by fdcurot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
	{
		return ;
	}
	new->next = *lst;
	*lst = new;
}

/*
FT_LSTADD_FRONT (simplified)

NAME
	ft_lstadd_front -- Adds a new element at the front of the list
SYNOPSIS
	void ft_lstadd_front(t_list **lst, t_list *new);
DESCRIPTION
	Add the 'new' element at the front of the list
PARAMETERS
	lst: pointer address to the first element of the list
	new: pointer address of the new element to add to the list
RETURN VALUES
	None
AUTHORIZED EXTERNAL FUNCTIONS
	None
	*/