/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d_set_structs.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/27 13:07:31 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/28 10:14:15 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

int	set_player(d_list *bag)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if ((bag->player = malloc(sizeof(t_list) * 1)) == 0)
		return (0); // free
	while (bag->map->map[i] != 0)
	{
		j = 0;
		while (bag->map->map[i][j] != 0)
		{
			if (ft_isalpha(bag->map->map[i][j]) == 1)
			{
				bag->player->x = j * CUBE_SIZE + CUBE_SIZE / 2;
				bag->player->y = i * CUBE_SIZE + CUBE_SIZE / 2;
				if (bag->map->map[i][j] == 'E')
					bag->player->dir = 2 * M_PI;
				if (bag->map->map[i][j] == 'N')
					bag->player->dir = M_PI_2;
				if (bag->map->map[i][j] == 'W')
					bag->player->dir = M_PI;
				if (bag->map->map[i][j] == 'S')
					bag->player->dir = 3 * M_PI / 2;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (-1);
}

l_list	*set_libx(void)
{
	l_list	*libx;

	int		bpp;
	int		size_line;
	int		endian;
	if ((libx = malloc(sizeof(l_list) * 1)) == 0)
		return (0);
	libx->mlx_ptr = mlx_init();
	libx->win_ptr = mlx_new_window(libx->mlx_ptr, WIDTH_ECRAN, HEIGHT_ECRAN, "Cub3D");
	libx->img_ptr = mlx_new_image(libx->mlx_ptr, WIDTH_ECRAN, HEIGHT_ECRAN);
	libx->data = (unsigned int *)mlx_get_data_addr(libx->img_ptr, &bpp, &size_line, &endian);
	return (libx);
}

d_list	*set_struct(char *file)
{
	d_list	*bag;

	if ((bag = malloc(sizeof(d_list) * 1)) == 0)
		return (NULL);
	bag->map = parsing(file);
	bag->mlx = set_libx();
	set_player(bag);
	return (bag);
}
