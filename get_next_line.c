#include "get_next_line.h"
#include <fcntl.h>

int	ft_ifnot(char *tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (1);
	while (tab[i] && tab[i] != '\n')
		i++;
	return (0 + (i == strlen(tab)));
}

char *ft_strjoin(char *s1, char *s2)
{
	int i;
	int j;
	char *tab;

	i = -1;
	j = -1;
	if(!s1 && !s2)
		return NULL;
	if(!s1)
		s1 = malloc(1);
	tab = malloc(strlen(s1) + strlen(s2) + 1);
	if(!tab)
		return NULL;
	while(s1[++i])
		tab[i] = s1[i];
	while(s2[++j])
		tab[i++] = s2[j];
	tab[i] =  '\0';
	return (free(s1), free(s2), tab);
}

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
	char *line;
	int i;

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
	char *rest;
	int	i;
	int	j;

	i = strlen(line);
	if (!store[i])
		return (free(store), NULL);
	rest = malloc(strlen(store) - strlen(line) + 1);
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

int	main(void)
{
	int fd = open("test2.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	return (0);
}