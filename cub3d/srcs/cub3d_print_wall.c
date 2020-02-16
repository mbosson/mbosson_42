/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d_print_wall.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/24 12:30:34 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/13 16:43:22 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

void	clear_wall(unsigned int *data, t_struct *bag)
{
	long i;
	long limit;

	i = 0;
	limit = bag->pars->height * bag->pars->width;
	while (i < limit)
		data[i++] = 0;
}

void	draw_wall(t_raycasting raycasting, t_mlx *mlx, double dist_to_wall, t_struct *bag)
{
	double	height_of_wall;
	double	height_of_wall_2;
	long	i;
	int		pixel;
	float	bitmap_pixel;

	i = 0;
	pixel = (raycasting.middle_of_screen * bag->pars->width) + raycasting.column;
	bitmap_pixel = 64 * 32 + (int)bag->map->Wall_x % 64;
	height_of_wall = (CUBE_SIZE / dist_to_wall) * raycasting.dist_to_screen;
	raycasting.bitmap_ratio = 64 / height_of_wall;
	if (height_of_wall > bag->pars->height)
		height_of_wall = bag->pars->height - 1;
	height_of_wall_2 = height_of_wall / 2;
	if (raycasting.column == 150)
	{
		printf("bitmap_ratio : %f\n", raycasting.bitmap_ratio);
		printf("\n\ndistance_to_wall : %f\n", dist_to_wall);
		printf("distance_to_screen : %f\n", raycasting.dist_to_screen);
		printf("height_of_wall : %f\n", height_of_wall);
		printf("ray : %f\n", raycasting.ray);
	}
	while (i <= height_of_wall_2)
	{
		mlx->data[pixel] = bag->pars->ea[(int)bitmap_pixel];
		pixel += bag->pars->width;
		bitmap_pixel += raycasting.bitmap_ratio;
		i++;
	}
	pixel = raycasting.middle_of_screen * bag->pars->width + raycasting.column;
	bitmap_pixel = 64 * 32 + (int)bag->map->Wall_x % 64;
	while (i >= 0)
	{
		mlx->data[pixel] = bag->pars->ea[(int)bitmap_pixel];
		pixel -= bag->pars->width;
		bitmap_pixel -= raycasting.bitmap_ratio;
		i--;
	}
}
