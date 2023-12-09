/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:25:15 by wteles-d          #+#    #+#             */
/*   Updated: 2023/12/09 21:54:11 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_update(char *buff);
char	*get_next_line(int fd);
int		ft_checknlc(char *buffer);
size_t	ft_strlengnl(const char *str);
size_t	ft_strcpy(char *line, char *aux);
char	*ft_get_line(char *line, char *buff);

#endif