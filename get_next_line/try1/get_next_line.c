/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/17 10:07:30 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/22 15:24:34 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */
#include "get_next_line.h"

void    cat_e(char *remainder)
{
    int j = 0;
        while (remainder[j])
        {
            if (remainder[j] == '\n')
                printf("\\n");
            else
            printf("%c", remainder[j]);
            j++;
        }
    printf("\n-----------\n");
}
static char *ft_add_rem(char **rem, int end)
{
    int i;
    char *str;
    char *buffer;

    i = 0;
    if (!(str = malloc(end + 1)))
        return (0);
    while (i < end)
    {
        str[i] = rem[0][i];
        i++;
    }

    str[i] = 0;
    buffer = *rem;
    rem[0] = (rem[0][i] == '\n') ? ft_strdup(rem[0] + i + 1) : ft_strdup(rem[0] + i);
    if (!(*rem))
    {
        free(str);
        *rem = buffer;
        return (0);
    }
    free(buffer);
    return (str);
}

int     ft_read(int fd, char **line, int size, char **remainder)
{
    char buffer[size + 1];
    char *tmp;
    int val_read;
    int i;

    //printf("ft_read\n");
    while (1)
    {
        val_read = read(fd, buffer, size);
        if (val_read == -1)
            return(usefull_free(line, -1));
        if (!val_read)
            return (0);
        buffer[val_read] = 0;
        i = 0;
        while (buffer[i] != '\n' && buffer[i])
            i++;
        if (buffer[i] == '\n')
        {
            if(!(*remainder = ft_strdup(buffer + i + 1)))
                return (usefull_free(line, -1));
            buffer[i] = 0;
            tmp = *line;
            if (!(*line = ft_strjoin(*line, buffer)))
                return (usefull_free(&tmp, -1));
            return (usefull_free(&tmp, 1));
        }
        tmp = *line;
        if (!(*line = ft_strjoin(*line, buffer)))
            return (usefull_free(&tmp, -1));
        free (tmp);
    }
}

int     ft_emptyfile(int fd, char **remainder, int size, char **to_free)
{
    int val_read;
    char *buffer;

    buffer = *remainder;
    //printf("emptyfile\n");
    if (!(*remainder = malloc(size + 1)))
    {
        free(*to_free);
        *to_free = 0;
        return (-1);
	}
    free(buffer);
    val_read = read(fd, *remainder, size);
    if (val_read == -1 || !val_read)
    {
        remainder[0] = 0;
        return (val_read);
    }
    remainder[0][val_read] = 0;
    return (1);
}

int		get_next_line(int fd, char **line)
{
	int i;
	static char *remainder[1];

	if (fd < 0 || line == 0)
		return (-1);
	i = 0;
    if (!remainder[0])
        remainder[0] = ft_strdup("");
	while (remainder[0][i] && remainder[0][i] != '\n')
        i++;
    if (remainder[0][i] == '\n')
    {
        if (!(*line = ft_add_rem(remainder, i)))
            return (-1);
        if (!remainder[0][0])
            return (ft_emptyfile(fd, remainder, BUFFER_SIZE, line));
        return (1);
    }
    if (!(*line = ft_add_rem(remainder, i))) //si la static est vide, permet d'initier line a 0
        return (-1);
    i = ft_read(fd, line, BUFFER_SIZE, remainder);
	return (i);
}















