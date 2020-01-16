/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d_parsing.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/20 11:44:26 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/15 16:57:37 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

char **add_line(char **line)
{
	char **buffer;
	int i;

	i = 0;
	if ((buffer = malloc(sizeof(char *) * (tablen(line) + 2))) == 0)
		return (NULL); //free
	while (line[i] != 0)
	{
		buffer[i] = ft_strdup(line[i]);
		i++;
	}
	free(line);
	buffer[i + 1] = 0;
	return (buffer);
}

char	**parsing(char *file)
{
	char **line;
	int fd;
	int i;

	i = 0;
	fd = open("map.cub", O_RDONLY);
	printf("fd : %d\n", fd);
	if ((line = malloc(sizeof(char *) * 2)) == 0)
		return (NULL);
	line[1] = 0;
	while (get_next_line(fd, &line[i]) > 0)
	{
		line = add_line(line);
		printf("%s\n", line[i]);
		i++;
	}
	printf("ok");
	return (line);
}

int main(void)
{
	char **line;
	int i;

	i = 0;
	line = parsing("map.cub");
	free(line);
	return (0);
}
