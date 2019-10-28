#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int get_next_line(int fd, char **line)
{
	int	i;
	int 	malloc_value;

	i = 0;
	malloc_value = 10;
	while (line[i])
		i++;
	while(i)
	{
		line[i]= malloc(sizeof(char) * (malloc_value + 1));
		malloc_value = read(fd, line[i], malloc_value);
		if (malloc_value == 0)
			break;
		malloc_value *= 2;
	}
	malloc_value = 0;
	while (line[i][malloc_value])
		malloc_value++;
	line[i] = malloc(sizeof(char) * (malloc_value + 1));
	return (read(fd, line[i], malloc_value));
}

int main(void)
{
	int fd;
	char **line;

	fd = open("test.txt", O_RDWR);
	get_next_line(fd, line);
	printf("%s", line[1]);
	return 0;
}
