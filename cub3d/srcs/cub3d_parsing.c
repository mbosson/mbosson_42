/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d_parsing.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/20 11:44:26 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/24 14:57:37 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

static char **add_line(char **line)
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

m_list	*parsing(char *file)
{
	m_list	*map;
	char	**line;
	int		fd;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if ((line = malloc(sizeof(char *) * 2)) == 0)
		return (0);
	if ((map = malloc(sizeof(m_list) * 1)) == 0)
		return (0);
	line[1] = 0;
	while (get_next_line(fd, &line[i++]) > 0)
		line = add_line(line);
	map->map = line;
	map->tabwidth = ft_strlen(map->map[0]) - 2;
	map->tabheight = tablen(map->map) - 2;
	return (map);
}
