/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/12 12:30:14 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/15 11:22:14 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int		is_there_n(char *staticstr)
{
	int				i;

	i = 0;
	if (staticstr == 0)
		return (0);
	while (staticstr[i])
	{
		if (staticstr[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int		fill_staticstr(char **staticstr, int start)
{
	char			*buffer;
	int				len;
	int				i;

	i = 0;
	len = 0;
	if ((*staticstr)[start] == '\n')
		start++;
	while ((*staticstr)[start + len] != 0)
		len++;
	if ((buffer = malloc(sizeof(char) * (len + 1))) == 0)
		return (free_all(*staticstr, NULL, 1));
	while ((*staticstr)[start + i] != 0)
	{
		buffer[i] = (*staticstr)[start + i];
		i++;
	}
	buffer[i] = 0;
	free(*staticstr);
	*staticstr = buffer;
	return (1);
}

int		fill_line(char **line, char **staticstr)
{
	int				i;
	int				len;
	char			*buffer;

	i = 0;
	len = 0;
	while ((*staticstr)[len] != '\n' && (*staticstr)[len] != 0)
		len++;
	if ((buffer = malloc(sizeof(char) * (len + 1))) == 0)
		return (free_all(*staticstr, NULL, 1));
	while ((*staticstr)[i] != '\n' && (*staticstr)[i] != 0)
	{
		if ((*staticstr)[i] == '\n')
			(*staticstr)[i] = 0;
		buffer[i] = (*staticstr)[i];
		i++;
	}
	buffer[i] = 0;
	*line = buffer;
	return (fill_staticstr(staticstr, len));
}

int		gnl_return(char **staticstr, char **line, char *str, int finded)
{
	free(str);
	if (fill_line(line, staticstr) == -1)
	{
		free_all(*staticstr, NULL, 1);
		return (-1);
	}
	if (finded == 1)
		return (1);
	free(*staticstr);
	*staticstr = 0;
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static	char	*staticstr;
	char			*str;
	int				finded;
	int				read_size;

	read_size = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || line == 0 || read(fd, staticstr, 0))
		return (-1);
	if (staticstr == 0)
	{
		if ((staticstr = malloc(sizeof(char) * 1)) == 0)
			return (-1);
		staticstr[0] = 0;
	}
	if ((str = malloc(sizeof(char) * (BUFFER_SIZE + 1))) == 0)
		return (free_all(staticstr, str, 1));
	while ((finded = is_there_n(staticstr)) == 0 && read_size != 0)
	{
		if ((read_size = read(fd, str, BUFFER_SIZE)) == -1)
			return (free_all(staticstr, str, 2));
		str[read_size] = 0;
		if ((staticstr = ft_strjoin(staticstr, str)) == 0)
			return (-1);
	}
	return (gnl_return(&staticstr, line, str, finded));
}
