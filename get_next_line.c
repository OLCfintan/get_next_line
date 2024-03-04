/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mouk <oel-mouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 04:49:03 by oel-mouk          #+#    #+#             */
/*   Updated: 2024/03/04 04:55:29 by oel-mouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *store)
{
	int		x;
	char	*tab;

	x = 1;
	while (ft_ifnot(store) && x != 0)
	{
		tab = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!tab)
			return (tab);
		x = read(fd, tab, BUFFER_SIZE);
		if ((!store && x == 0) || x == -1)
			return (free(tab), NULL);
		tab[x] = '\0';
		store = ft_strjoin(store, tab);
	}
	return (store);
}

char	*ft_tr(char *store)
{
	char	*line;
	int		i;

	i = 0;
	if (!store)
		return (NULL);
	while (store[i] && store[i] != '\n')
		i++;
	if (store[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = -1;
	while (store[++i] && store[i - 1] != '\n')
		line[i] = store[i];
	line[i] = '\0';
	return (line);
}

char	*ft_after(char *store, char *line)
{
	char	*rest;
	int		i;
	int		j;

	i = ft_strlen(line);
	if (!store[i])
		return (free(store), NULL);
	rest = malloc(ft_strlen(store) - ft_strlen(line) + 1);
	if (!rest)
		return (NULL);
	j = 0;
	while (store[i])
		rest[j++] = store[i++];
	rest[j] = '\0';
	return (free(store), rest);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*tmp;
	static char	*store;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = ft_read(fd, store);
	if (!tmp)
	{
		if (store)
			free(store);
		store = NULL;
		return (NULL);
	}
	line = ft_tr(tmp);
	store = ft_after(tmp, line);
	return (line);
}
