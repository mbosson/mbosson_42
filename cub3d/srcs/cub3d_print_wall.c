/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d_print_wall.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/24 12:30:34 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/24 15:45:26 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_wall(r_list raycasting, l_list *mlx, long dist_to_wall, int column)
{
	long	height_of_wall;
	long	i;
	int	pixel;

	i = 0;
	pixel = raycasting.middle_of_screen * HEIGHT_ECRAN + column;
	printf("\n\ndistance_to_wall : %ld\n", dist_to_wall);
	printf("distance_to_screen : %d\n", raycasting.dist_to_screen);
	height_of_wall = (long)(CUBE_SIZE * raycasting.dist_to_screen / dist_to_wall);
	printf("height_of_wall : %ld\n", height_of_wall);
	while (i <= height_of_wall)
	{
		mlx->data[pixel] = 0x9600A0;
		pixel += HEIGHT_ECRAN;
		i++;
	}
}
