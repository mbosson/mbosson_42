/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/24 16:28:10 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/24 16:47:45 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count)
{
	size_t	i;
	char	*tmp;

	i = 0;
	if ((count) == 0)
	{
		if ((tmp = malloc(1)) == 0)
			return (0);
		*tmp = 0;
		return (tmp);
	}
	if ((tmp = malloc(count)) == 0)
		return (0);
	while (i < (count))
	{
		tmp[i] = 0;
		i++;
	}
	return ((void *)tmp);
}

char	*ft_gnl_strdup(char **s1)
{
	int		i;
	int		u;
	int		k;
	char	*tmp;
	char	*save;

	u = -1;
	i = 0;
	while (s1[0][i] && s1[0][i] != '\n')
		i++;
	if ((tmp = ft_calloc((i + 1))) == 0)
		return (0);
	while (++u < i)
		tmp[u] = s1[0][u];
	while (s1[0][u])
		u++;
	save = *s1;
	if (!(s1[0] = malloc((u - i + 1))))
		return (0);
	k = -1;
	while (save[0] && save[++k + i + 1])
		s1[0][k] = save[i + 1 + k];
	s1[0][k] = 0;
	free(save);
	return (tmp);
}

int		ft_lstclear(t_list **lst, int return_value)
{
	t_list *current_elem;
	t_list *next_elem;

	if (!lst)
		return (return_value);
	current_elem = *lst;
	while (current_elem)
	{
		next_elem = current_elem->next;
		free(current_elem->remind);
		free(current_elem);
		current_elem = next_elem;
	}
	*lst = 0;
	return (return_value);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*join;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (s2[j])
		j++;
	if (!(join = ft_calloc(i + j + 1 * sizeof(char))))
		return (0);
	i = -1;
	while (s1[++i])
		join[i] = s1[i];
	j = -1;
	while (s2[++j])
		join[i + j] = s2[j];
	return (join);
}

int		ft_lstdelone(t_list **fi, int fd)
{
	t_list	*previous;
	t_list	*current;
	t_list	*save;

	previous = 0;
	current = *fi;
	if (current->fd == fd)
	{
		*fi = current->next;
		free(current->remind);
		free(current);
		return (0);
	}
	while (current->next && current->fd != fd)
	{
		previous = current;
		current = current->next;
	}
	save = current;
	previous->next = current->next;
	free(current->remind);
	free(current);
	return (0);
}

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

	if (!(buffer = malloc(BUFF_SIZE + 1)))
		return (0);
	if ((val_read = read(fd, buffer, BUFF_SIZE)) == -1)
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
