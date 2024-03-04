//#ifndef 
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 300
# endif

char	*ft_tr(char *str);
// char	*ft_ifnot(char *tab);
int		ft_count(char *str);
char	*get_next_line(int fd);

#endif
