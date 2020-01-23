/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d_utils.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/15 14:53:31 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/23 15:16:49 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*s2;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s1[len])
		len++;
	if ((s2 = malloc(sizeof(char) * len + 1)) == 0)
		return (0);
	s2[len] = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}

int tablen(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != 0)
		i++;
	return (i);
}

t_list *set_player(char **map)
{
	t_list *player;
	int i;
	int j;

	i = 0;
	j = 0;
	if ((player = malloc(sizeof(t_list) * 1)) == 0)
		return (NULL); // free
	while (map[i] != 0)
	{
		j = 0;
		while (map[i][j] != 0)
		{
			if (ft_isalpha(map[i][j]) == 1)
			{
				player->x = j * CUBE_SIZE + CUBE_SIZE / 2;
				player->y = i * CUBE_SIZE + CUBE_SIZE / 2;
				if (map[i][j] == 'E')
					player->dir = 2 * M_PI;
				if (map[i][j] == 'N')
					player->dir = M_PI_2;
				if (map[i][j] == 'W')
					player->dir = M_PI;
				if (map[i][j] == 'S')
					player->dir = 3 * M_PI / 2;
				return (player);
			}
			j++;
		}
		i++;
	}
	return (player);
}
