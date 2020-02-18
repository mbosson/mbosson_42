/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_print_wall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbosson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 12:47:19 by mbosson           #+#    #+#             */
/*   Updated: 2020/02/18 15:00:02 by mbosson          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	clear_wall(unsigned int *window, t_struct *bag)
{
	long i;
	long limit;

	i = 0;
	limit = bag->pars->height * bag->pars->width;
	while (i < limit)
		window[i++] = 0;
}

unsigned int	*choose_texture(t_struct *bag, double ray)
{
	if (ray >= 0 && ray < M_PI && bag->map->ori_wall == 0)
		return (bag->pars->no);
	if (ray >= M_PI && ray < M_PI * 2 && bag->map->ori_wall == 0)
		return (bag->pars->so);
	if (ray >= M_PI_2 && ray < 3 * M_PI_2 && bag->map->ori_wall == 1)
		return (bag->pars->we);
	else
		return (bag->pars->ea);
}

void	draw_wall(t_raycasting raycasting, t_mlx *mlx, double dist_to_wall, t_struct *bag)
{
	double	height_of_wall;
	double	height_of_wall_2;
	long	i;
	int		pixel;
	float	bitmap_pixel;
	float	buffer;

	i = 0;
	buffer = 0;
	bag->pars->texture = choose_texture(bag, raycasting.ray);
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
		mlx->data[pixel] = bag->pars->texture[(int)bitmap_pixel];
		pixel += bag->pars->width;
		buffer += raycasting.bitmap_ratio;
		while (buffer >= 1)
		{
			if (bitmap_pixel + 64 < 4096)
				bitmap_pixel += 64;
			buffer -= 1;
		}
		i++;
	}
	pixel = raycasting.middle_of_screen * bag->pars->width + raycasting.column;
	bitmap_pixel = 64 * 32 + (int)bag->map->Wall_x % 64;
	buffer = 0;
	while (i >= 0)
	{
		mlx->data[pixel] = bag->pars->texture[(int)bitmap_pixel];
		pixel -= bag->pars->width;
		buffer += raycasting.bitmap_ratio;
		while (buffer >= 1)
		{
			if (bitmap_pixel - 64 > 0)
				bitmap_pixel -= 64;
			buffer -= 1;
		}
		i--;
	}
}
