/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_test.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/04 17:59:21 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/05 16:58:09 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <unistd.h>
#include <strings.h>

//#ifndef BUFFER_SIZE 
#define BUFFER_SIZE 20

void	*ft_memmove(void *dest, void *src, size_t n)
{
	unsigned int			i;
	const char				*str_src;
	char					*str_src_cpy;
	char					*str_dest;

	str_src = src;
	str_dest = dest;
	str_src_cpy = calloc(sizeof(char), n);
	if (str_src_cpy == 0)
		return (0);
	if (!str_dest && !str_src && n)
		return (0);
	i = 0;
	while (i < n && str_src[i] != 0)
	{
		str_src_cpy[i] = str_src[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		str_dest[i] = str_src_cpy[i];
		i++;
	}
	return (str_dest);
}

int		ft_memccpy(void *dest, void *src, char c, int n)
{
	int				i;
	unsigned char	*strsrc;
	unsigned char	*strdest;

	strsrc = src;
	strdest = dest;
	i = 0;
	while (i < n)
	{
		if (strsrc[i] == c)
			return (i);
		strdest[i] = strsrc[i];
		i++;
	}
	return (0);
}

int tab_len(char **line)
{
	int i;

	i = 0;
	while (line[i][0] != 0)
		i++;
	return (i);
}

int		get_next_line(int fd, char **line)
{
	static	int			position;
	static	char			*buffer;
	int 				count;
	int					result;

	if (fd < 0 || line == 0 
			|| (buffer = malloc(sizeof(char) * BUFFER_SIZE + 1)) == 0)
		return (-1);
	buffer[BUFFER_SIZE] = 0;
	result = 1;
	if (buffer[0] != 0)
		result = read(fd, buffer, BUFFER_SIZE);
	if (result > 0)
	{	
		count = tab_len(line);
		printf("count = %d\n", count);
		position = ft_memccpy(line[count], buffer, '\n', BUFFER_SIZE);
		if (position != 0)
			ft_memmove(buffer, buffer + position, BUFFER_SIZE);
		return (1);
	}
	return (result);
}

int		main()
{
	int				fd;
	char			**buffer;
	int 			i;

	i = 0;
	buffer = calloc(sizeof(char*), 20);
	buffer[19] = 0;
	while (i < 20)
	{
		buffer[i] = calloc(sizeof(char), BUFFER_SIZE);
		i++;
	}
	fd = open("text.txt", O_RDWR);	
	i = 0;
	printf("\nresult get_next_line : %d\n", get_next_line(fd, buffer));
	printf("line 1 : %s\n", buffer[0]);
	printf("\n\nresult get_next_line : %d\n", get_next_line(fd, buffer));
	printf("line 2 : %s\n", buffer[1]);
	printf("\n\nresult get_next_line : %d\n", get_next_line(fd, buffer));
	printf("line 3 : %s\n", buffer[2]);
	printf("\n\nresult get_next_line : %d\n", get_next_line(fd, buffer));
	printf("line 4 : %s\n", buffer[3]);
	free(buffer);
	return (0);
}
