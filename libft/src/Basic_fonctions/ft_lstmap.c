/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdcurot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:33:09 by fdcurot           #+#    #+#             */
/*   Updated: 2025/10/07 10:25:33 by fdcurot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_elem;
	void	*new_content;

	new_list = NULL;
	while (lst)
	{
		if (!new_content)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		new_content = f(lst->content);
		new_elem = ft_lstnew(new_content);
		if (!new_elem)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_elem);
		lst = lst->next;
	}
	return (new_list);
}

/*
FT_LSTMAP (simplified)

NAME
	ft_lstmap -- creates a new list resulting from the application 
	of f to each element
SYNOPSIS
	t_list *ft_lstmap(t_list *lst, void (*f)(void *), void (*del)(void *));
DESCRIPTION
	Iterate over the list 'lst' and apply the function 'f' to the content 
	of each elements.
	Create a new list resulting of the successive applications of 'f'.
	The function 'del' is used to destroy the content of an element if necessary.
PARAMETERS
	lst: pointer address to one element
	f: the address of the function to apply
	del: the address of the function that can delete an element's content
RETURN VALUES
	None
AUTHORIZED EXTERNAL FUNCTIONS
	None
	*/