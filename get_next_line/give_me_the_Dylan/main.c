/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/17 10:21:40 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/24 16:23:09 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(void)
{
	char *line;
	char *file = "file1";
	int fd = open (file, O_RDONLY);
	if (fd == -1)
	{
		printf("unable to open %s\n", file);
		return (0);
	}
	int ret = 1;
	printf("FILE1\n");
	int compt = 1;
	while (ret != -1)
	{
		ret = get_next_line(fd, &line);
		printf("%d | %d | %s\n", compt, ret, line);
		compt++;
		if (compt == 2)
			break;
		if (ret == 0)
			break;
	}
	int fd2 = open ("Xfile", O_RDONLY);
	printf("FILE2\n");
	int compt2 = 0;
	while (ret != -1)
	{
		ret = get_next_line(fd2, &line);
		printf("%d | %d | %s\n", compt, ret, line);
		compt2++;
		if (ret == 0)
			break;
	}
	close(fd2);
	printf("FILE1\n");
	while (ret != -1)
	{
		ret = get_next_line(fd, &line);
		printf("%d | %d | %s\n", compt, ret, line);
		compt++;
		if (ret == 0)
			break;
	}
	close(fd);
	fd2 = open ("file2", O_RDONLY);
	printf("FILE2\n");
	compt2 = 0;
	while (ret != -1)
	{
		ret = get_next_line(fd2, &line);
		printf("%d | %d | %s\n", compt, ret, line);
		compt2++;
		if (ret == 0)
			break;
	}
	close(fd2);
	fd = open(file, O_RDONLY);
	printf("FILE\n");
	char buffer[10001];
	compt = 1;
	while ((ret = read(fd, buffer, 10000)))
		buffer[ret] = 0;
	printf("%s", buffer);
	return (0);
}
