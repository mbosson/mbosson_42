/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d_parsing.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/20 11:44:26 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/13 13:59:17 by mbosson     ###    #+. /#+    ###.fr     */
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

int		recover_value(char *line, t_struct *bag, char c)
{
	int i;
	char buffer[600];

	i = 0;
	if (c == 'R')
	{
		while (ft_is_num(line[0]) == 1)
		{
			buffer[i++] = line[0];
			line++;
		}
		buffer[i] = 0;
		printf("buffer : %s\n", buffer);
		bag->pars->width = ft_atoi(buffer);
		while (line[0] == ' ')
			line++;
		bag->pars->height = ft_atoi(line);
	}
	return (1);
}

int		recover_path(char *line, t_struct *bag)
{
	int i;
	char c;

	i = 0;
	c = line[0];
	if (c == 'S' && line[1] != 'O')
		c = 'P';
	while (line[0] != ' ')
		line++;
	while (line[0] == ' ')
		line++;
	if (c == 'F' || c == 'R')
		return (recover_value(line, bag, c));
	else if (c == 'N')
		bag->pars->path_no = ft_strdup(line);
	else if (c == 'S')
		bag->pars->path_so = ft_strdup(line);
	else if (c == 'W')
		bag->pars->path_we = ft_strdup(line);
	else if (c == 'E')
		bag->pars->path_ea = ft_strdup(line);
	else if (c == 'P')
		bag->pars->path_s = ft_strdup(line);
	return (1);
}

char	*parsing_info(int fd, t_struct *bag)
{
	char	*line;
	int i;

	i = 0;
	if ((line = malloc(sizeof(char *) * 1)) == 0)
		return (0);
	line[1] = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == '1')
			break;
		if (ft_isalpha(line[0]) == 1 || ft_isalpha(line[0]) == 2)
			recover_path(line, bag);
		else if (line[0] != '\n' && line[0] != 0)
		{
			write(1, "Parsing Error.\n", 15);
			exit(1);
		}
	}
	return (line);
}

t_map	*parsing(char *file, t_struct *bag)
{
	t_map	*map;
	char	**line;
	int		fd;
	int		i;

	i = 1;
	fd = open(file, O_RDONLY);
	printf("fd = %d\n", fd);
	if ((bag->pars = malloc(sizeof(t_pars) * 1)) == 0)
		return (0);
	if ((line = malloc(sizeof(char *) * 2)) == 0)
		return (0);
	if ((map = malloc(sizeof(t_map) * 1)) == 0)
		return (0);
	line[1] = 0;
	line[0] = parsing_info(fd, bag);
	line = add_line(line);
	while (get_next_line(fd, &line[i++]) > 0)
	{
		line = add_line(line);
		printf("%s\n", line[i - 1]);
	}
	map->map = line;
	map->tabwidth = ft_strlen(map->map[0]) - 1;
	map->tabheight = tablen(map->map) - 2;
	printf("parsing width screen : %d\n", bag->pars->width);
	printf("parsing height screen : %d\n", bag->pars->height);
	return (map);
}
