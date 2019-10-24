/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ermartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/24 14:51:42 by ermartin     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/24 16:43:20 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

char	**ft_search(int fd, t_list *first_elem)
{
	t_list *new_elem;
	t_list *current_elem;

	current_elem = first_elem;
	while (current_elem->next)
	{
		if (fd == current_elem->fd)
			return (&(current_elem->remind));
		current_elem = current_elem->next;
	}
	if (fd == current_elem->fd)
		return (&(current_elem->remind));
	if (!(new_elem = ft_calloc(sizeof(t_list))))
		return (0);
	new_elem->fd = fd;
	if (!(new_elem->remind = ft_calloc(1)))
		return (0);
	current_elem->next = new_elem;
	return (&(new_elem->remind));
}

int		ft_read(int fd, char **reminder)
{
	char	*buffer;
	int		val_read;
	char	*save;

	if (!(buffer = malloc(BUFFER_SIZE + 1)))
		return (0);
	if ((val_read = read(fd, buffer, BUFFER_SIZE)) == -1)
		return (0);
	buffer[val_read] = 0;
	save = *reminder;
	if (!(*reminder = ft_strjoin(save, buffer)))
		return (0);
	free(save);
	free(buffer);
	return (1);
}

int		gnl2(t_list **first_elem, char **line, char **reminder, int fd)
{
	int pos;
	int i;

	i = 0;
	while (reminder[0][i] && reminder[0][i] != '\n')
		i++;
	pos = (reminder[0][i] == '\n') ? 1 : 0;
	if (reminder[0][i] == '\n' && reminder[0][i + 1])
	{
		return ((!(*line = ft_gnl_strdup(reminder))) ? ft_lstclear(first_elem,
			-1) : 1);
	}
	if (!(ft_read(fd, reminder)))
		return (ft_lstclear(first_elem, -1));
	if (!reminder[0][0])
	{
		return ((!(*line = ft_calloc(1))) ? ft_lstclear(first_elem, -1) :
				ft_lstdelone(first_elem, fd));
	}
	if ((pos && !reminder[0][i + 1]) || !reminder[0][i])
	{
		return ((!(*line = ft_gnl_strdup(reminder))) ? ft_lstclear(first_elem,
					-1) : 1);
	}
	return (gnl2(first_elem, line, reminder, fd));
}

int		get_next_line(int fd, char **line)
{
	char			**reminder;
	static	t_list	*first_elem;

	if (fd < 0 || !line)
		return (-1);
	if (!first_elem)
	{
		if (!(first_elem = ft_calloc(sizeof(t_list))))
			return (-1);
		first_elem->fd = fd;
		if (!(first_elem->remind = ft_calloc(1)))
		{
			free(first_elem);
			return (-1);
		}
	}
	if (!(reminder = ft_search(fd, first_elem)))
		return (ft_lstclear(&first_elem, -1));
	return (gnl2(&first_elem, line, reminder, fd));
}
