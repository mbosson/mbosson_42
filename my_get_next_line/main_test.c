#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd;
	char buffer[40];
	int result;

	fd = open("test.txt", O_RDWR);
	result = read(fd, buffer, 38);
	buffer[39] = 0;
	ft_putstr(buffer);
	return 0;
}
