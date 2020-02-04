/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d_print_wall.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/24 12:30:34 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/04 16:24:47 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

void	clear_wall(unsigned int *data)
{
	long i;
	long limit;

	i = 0;
	limit = HEIGHT_ECRAN * WIDTH_ECRAN;
	while (i < limit)
		data[i++] = 0;
}

void	draw_wall(r_list raycasting, l_list *mlx, double dist_to_wall)
{
	double	height_of_wall;
	double	height_of_wall_2;
	long	i;
	int		pixel;

	i = 0;
	pixel = (raycasting.middle_of_screen * WIDTH_ECRAN) + raycasting.column;
	height_of_wall = (CUBE_SIZE / dist_to_wall) * raycasting.dist_to_screen;
	if (height_of_wall > HEIGHT_ECRAN)
		height_of_wall = HEIGHT_ECRAN - 1;
	height_of_wall_2 = height_of_wall / 2;
	if (raycasting.column == 150)
	{
		printf("\n\ndistance_to_wall : %f\n", dist_to_wall);
		printf("distance_to_screen : %f\n", raycasting.dist_to_screen);
		printf("height_of_wall : %f\n", height_of_wall);
		printf("ray : %f\n", raycasting.ray);
	}
	while (i <= height_of_wall_2)
	{
		if (raycasting.column == 150)
			mlx->data[pixel] = 0x6400FF;
		else
			mlx->data[pixel] = 0x9600A0;
		pixel += WIDTH_ECRAN;
		i++;
	}
	pixel = raycasting.middle_of_screen * WIDTH_ECRAN + raycasting.column;
	while (i >= 0)
	{
		if (raycasting.column == 150)
			mlx->data[pixel] = 0x6400FF;
		else
			mlx->data[pixel] = 0x9600A0;
		pixel -= WIDTH_ECRAN;
		i--;
	}
}
