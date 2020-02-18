/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d_set_structs.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/27 13:07:31 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/18 15:02:57 by mbosson          ###   ########lyon.fr   */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

int	set_player(t_struct *bag)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if ((bag->player = malloc(sizeof(t_player) * 1)) == 0)
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

void	get_texture_data(t_struct *bag)
{
	void	*img_ptr;
	int size_width;
	int size_height;
	int bpp;
	int endian;
	int size_line;

	img_ptr = mlx_xpm_file_to_image(bag->mlx->mlx_ptr, bag->pars->path_no, &size_width, &size_height);
	bag->pars->no = (unsigned int *)mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
	img_ptr = mlx_xpm_file_to_image(bag->mlx->mlx_ptr, bag->pars->path_so, &size_width, &size_height);
	bag->pars->so = (unsigned int *)mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
	img_ptr = mlx_xpm_file_to_image(bag->mlx->mlx_ptr, bag->pars->path_we, &size_width, &size_height);
	bag->pars->we = (unsigned int *)mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
	img_ptr = mlx_xpm_file_to_image(bag->mlx->mlx_ptr, bag->pars->path_ea, &size_width, &size_height);
	bag->pars->ea = (unsigned int *)mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
	img_ptr = mlx_xpm_file_to_image(bag->mlx->mlx_ptr, bag->pars->path_s, &size_width, &size_height);
	bag->pars->s = (unsigned int *)mlx_get_data_addr(bag->mlx->img_ptr, &bpp, &size_line, &endian);
}

t_key	*set_key_struct(void)
{
	t_key	*key;

	if ((key = malloc(sizeof(t_key) * 1)) == 0)
		exit(1);
	key->w = 0;
	key->s = 0;
	key->a = 0;
	key->d = 0;
	key->left = 0;
	key->right = 0;
	key->up = 0;
	key->down = 0;
	key->esc = 0;
	key->shift = 0;
	return (key);
}

t_mlx	*set_libx(t_struct *bag)
{
	t_mlx	*libx;

	int		bpp;
	int		size_line;
	int		endian;
	if ((libx = malloc(sizeof(t_mlx) * 1)) == 0)
		return (0);
	libx->mlx_ptr = mlx_init();
	libx->win_ptr = mlx_new_window(libx->mlx_ptr, bag->pars->width, bag->pars->height, "Cub3D");
	libx->img_ptr = mlx_new_image(libx->mlx_ptr, bag->pars->width, bag->pars->height);
	libx->data = (unsigned int *)mlx_get_data_addr(libx->img_ptr, &bpp, &size_line, &endian);
	return (libx);
}

t_struct	*set_struct(char *file)
{
	t_struct	*bag;

	if ((bag = malloc(sizeof(t_struct) * 1)) == 0)
		return (NULL);
	bag->map = parsing(file, bag);
	bag->mlx = set_libx(bag);
	bag->key = set_key_struct();
	set_player(bag);
	get_texture_data(bag);
	return (bag);
}
