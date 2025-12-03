/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdcurot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:34:58 by fdcurot           #+#    #+#             */
/*   Updated: 2025/10/06 14:34:58 by fdcurot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len >= dstsize)
	{
		dst_len = dstsize;
	}
	if (dst_len == dstsize)
	{
		return (dstsize + src_len);
	}
	if (src_len < dstsize - dst_len)
	{
		ft_memcpy(dst + dst_len, src, src_len + 1);
	}
	else
	{
		ft_memcpy(dst + dst_len, src, dstsize - dst_len - 1);
		dst[dstsize - 1] = '\0';
	}
	return (dst_len + src_len);
}

/*
STRLCAT(3) (simplified)

NAME
    strlcat -- size-bounded string concatenation
SYNOPSIS
    size_t strlcat(char *dst, const char *src, size_t dstsize);
DESCRIPTION
    The strlcat() function concatenate strings with the same input parameters
	 and outuput result as snprintf(3). It is designed to be safer, more 
	 consistent, and less error prone replacements for the easily misused 
	 function strncat(3).
    strlcat() take the full size of the destination buffer and guarantee 
	NUL-termination if there is room. Note that room for the NUL should be 
	included in dstsize. Also note that strlcat() only operate on true ''C'' 
	strings. This means that both src and dst must be NUL-terminated.
    strlcat() appends string src to the end of dst. It will append at 
	most dstsize - strlen(dst) - 1 characters. It will then NUL-terminate, 
	unless dstsize is 0 or the original dst string was longer than dstsize 
	(in practice this should not happen as it means that either dstsize is 
	incorrect or that dst is not a proper string).
    If the src and dst strings overlap, the behavior is undefinded.
RETURN VALUES
    Like snprintf(3), strlcat() function return the total length of the 
	string it tried to create. That means the initial length of dst plus the 
	length of src.
    If the return value is >= dstsize, the output string has been truncated.
    It is the caller's responsibility to handle this.
	*/