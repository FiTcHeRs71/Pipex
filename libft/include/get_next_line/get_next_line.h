/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 17/10/2025 10:36:01 by fducrot           #+#    #+#             */
/*   Updated: 01/12/2025 14:28:28 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_FD
#  define MAX_FD 1000
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

/* get_next_line_bonus.c */
char	*get_next_line(int fd);
char	*ft_update_static(char *all_files);
char	*ft_define_line(char *all_files);
char	*ft_read_doc(int fd, char *buffer, char *all_files);

/* get_next_line_utils_bonus.c */
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif