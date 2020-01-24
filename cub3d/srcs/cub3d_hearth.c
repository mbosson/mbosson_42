/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d_hearth.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/24 08:39:25 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/24 09:51:23 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

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
