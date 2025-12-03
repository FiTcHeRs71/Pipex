/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdcurot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:33:03 by fdcurot           #+#    #+#             */
/*   Updated: 2025/10/06 14:33:05 by fdcurot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
	{
		return (NULL);
	}
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

/*
FT_LSTLAST (simplified)

NAME
	ft_lstlast -- get the last element of the list
SYNOPSIS
	t_list *ft_lstlast(t_list *lst);
DESCRIPTION
	Returns the last element of the list
PARAMETERS
	lst: the start of the list
RETURN VALUES
	Last element of the list
AUTHORIZED EXTERNAL FUNCTIONS
	None
*/