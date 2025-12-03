/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdcurot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:32:59 by fdcurot           #+#    #+#             */
/*   Updated: 2025/10/06 15:10:13 by fdcurot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void	ft_putstr(void *str)
{
	size_t	i;

	i = 0;
	while (((char *)str)[i])
	{
		write(1, &((char *)str)[i], 1);
		i++;
	}
}*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*
FT_LSTITER (simplified)

NAME
	ft_lstiter -- apply a function to each element's content
SYNOPSIS
	void ft_lstiter(t_list *lst, void (*f)(void *));
DESCRIPTION
	Iterate over the list 'lst' and apply the function 'f' 
	to the content of all elements.
PARAMETERS
	lst: pointer address to one element
	f: function to apply
RETURN VALUES
	None
AUTHORIZED EXTERNAL FUNCTIONS
	None
	*/