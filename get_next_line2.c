#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

char	*ft_after(char *str)
{
	char	*temp;

	int i, j;
	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	temp = (char *)malloc(strlen(str) - i + 1);
	if (!temp)
		return (NULL);
	j = 0;
	while (str[i])
	{
		temp[j] = str[i];
		j++;
		i++;
	}
	temp[j] = '\0';
	return (temp);
}

int	ft_ifnot(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	return (0 + (i == strlen(str)));
}
char	*ft_tr(char *str)
{
	int		i;
	char	*temp;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	i += (str[i] == '\n');
	temp = malloc(i + 1);
	temp[i] = '\0';
	while(i >= 0)
		temp[i--] = str[i];
	return (temp);
}
char	*ft_strjoint(char *s1, char *s2)
{
	char	*join;

	int i;
	int j;
	if (!s1 || !s2)
		return (NULL);
	join = (char *)malloc(strlen(s1) + strlen(s2) + 1);
	if (!join)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		join[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		join[j] = s2[i];
		i++;
		j++;
	}
	join[j] = '\0';
	return (join);
}

char *ft_re(char str)
{
	int i;


}
char	*get_next_line(int fd)
{
	int			i;
	char		*tab;
	char		*join;
	static char	*store;

	i = 0;
	tab = malloc(BUFFER_SIZE + 1);
	if (!tab)
		return (NULL);
	if (!store)
		store = malloc(1);
	while (ft_ifnot(tab))
	{
		read(fd, tab, BUFFER_SIZE);
		tab[BUFFER_SIZE] = '\0';
		store = ft_strjoint(store, tab);
	}
	join = ft_tr(store);
	store = strcpy(store, store + strlen(store));
	return (join);
}


//N\n--Y\n--O\n


int	main(void)
{
	int	fd1;

	//fd1 = 0;
	fd1 = open("test2.txt", O_RDONLY);
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd1));
}
