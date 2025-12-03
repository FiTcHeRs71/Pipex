/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdcurot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:31:53 by fdcurot           #+#    #+#             */
/*   Updated: 2025/10/07 08:33:46 by fdcurot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!new)
	{
		return ;
	}
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

/*
FT_LSTADD_BACK (simplified)

NAME
	ft_lstadd_back -- adds a new node at the end of the list
SYNOPSIS
	void ft_lstadd_back(t_list **lst, t_list *new);
DESCRIPTION
	Add the 'new' element at the end of the list
PARAMETERS
	lst: pointer address of the first element of the list
	new: pointer address of the new element to add to the list
RETURN VALUES
	None
AUTHORIZED EXTERNAL FUNCTIONS
	None
	*/