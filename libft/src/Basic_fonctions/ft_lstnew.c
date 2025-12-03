/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdcurot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:33:18 by fdcurot           #+#    #+#             */
/*   Updated: 2025/10/07 08:48:51 by fdcurot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_elem;

	new_elem = malloc(sizeof(t_list));
	if (!new_elem)
	{
		return (NULL);
	}
	new_elem->content = content;
	new_elem->next = NULL;
	return (new_elem);
}

/*
FT_LSTNEW (simplified)

NAME
	ft_lstnew -- create a new list node element
SYNOPSIS
	t_list *ft_lstnew(void *content);
DESCRIPTION
	Allocate (with malloc(3)) and return the new element. The member variable
	'content' is initialized with the value of the 'content' parameter.
	The 'next' variable is initialized to NULL.
PARAMETERS
	content: The content of the new element
RETURN VALUES
	The new element.
AUTHORIZED EXTERNAL FUNCTIONS
	malloc(3)
	*/