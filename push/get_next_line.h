/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mouk <oel-mouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 04:49:19 by oel-mouk          #+#    #+#             */
/*   Updated: 2024/03/04 04:58:52 by oel-mouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
#include <stdint.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 300
# endif

int		ft_ifnot(char *tab);
size_t		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char *get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);

#endif
