/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ermartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/22 17:53:21 by ermartin     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/23 19:02:42 by abourbou    ###    #+. /#+    ###.fr     */
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
		current_elem  = current_elem->next;
	}	
	if (fd == current_elem->fd)
		return (&(current_elem->remind));
	if (!(new_elem = ft_calloc(sizeof(t_list))))
		return (0);
	new_elem->fd = fd;
	if (!(new_elem->remind = ft_calloc(1)))	
		return(0);
	current_elem->next = new_elem;
	return (&(new_elem->remind));
}

int		ft_read(int fd, char **reminder)
{
	char	buffer[BUFFER_SIZE + 1];
	int		val_read;
	char	*save;

	if ((val_read = read(fd, buffer, BUFFER_SIZE)) == -1)
		return (0);
	buffer[val_read] = 0;
	save = *reminder;
	if (!(*reminder = ft_strjoin(save, buffer)))
		return (0);
	free(save);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	char	**reminder;
	static	t_list *first_elem;
	int		i;
	int		pos;

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
	while (1)
	{
		i = 0;
		while (reminder[0][i] && reminder[0][i] != '\n')
			i++;
		pos = (reminder[0][i] == '\n') ? 1 : 0; 
		if (reminder[0][i] == '\n' && reminder[0][i + 1])
		{
			if (!(*line = ft_gnl_strdup(reminder)))
				return (ft_lstclear(&first_elem, -1));
			return (1);
		}
		if (!(ft_read(fd, reminder)))
			return (ft_lstclear(&first_elem, -1));
		if ((pos && !reminder[0][i + 1]) || !reminder[0][i])
		{
			if (!(*line = ft_gnl_strdup(reminder)))
				return (ft_lstclear(&first_elem, -1));
			return (0);
		}
	}
	return (1);
}
