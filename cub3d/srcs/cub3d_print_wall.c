/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d_print_wall.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/24 12:30:34 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/28 13:13:37 by mbosson     ###    #+. /#+    ###.fr     */
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

void	draw_wall(r_list raycasting, l_list *mlx, float dist_to_wall, int column)
{
	float	height_of_wall;
	float	height_of_wall_2;
	long	i;
	int		pixel;

	i = 0;
	pixel = (raycasting.middle_of_screen * WIDTH_ECRAN) + column;
	printf("\n\ndistance_to_wall : %f\n", dist_to_wall);
//	printf("distance_to_screen : %d\n", raycasting.dist_to_screen);
	height_of_wall = (CUBE_SIZE / dist_to_wall) * raycasting.dist_to_screen;
	if (height_of_wall > HEIGHT_ECRAN)
		height_of_wall = HEIGHT_ECRAN;
	height_of_wall_2 = height_of_wall / 2;
	printf("height_of_wall : %f\n", height_of_wall);
	printf("ray : %f\n", raycasting.ray);
	while (i <= height_of_wall_2)
	{
		mlx->data[pixel] = 0x9600A0;
		pixel += WIDTH_ECRAN;
		i++;
	}
	pixel = raycasting.middle_of_screen * WIDTH_ECRAN + column;
	while (i >= 0)
	{
		mlx->data[pixel] = 0x9600A0;
		pixel -= WIDTH_ECRAN;
		i--;
	}
}
