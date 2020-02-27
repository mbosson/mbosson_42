/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_print_wall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbosson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 12:47:19 by mbosson           #+#    #+#             */
/*   Updated: 2020/02/27 16:45:00 by mbosson          ###   ########lyon.fr   */
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

void	choose_texture(t_struct *bag, double ray)
{
	if (ray >= 0 && ray < M_PI && bag->map->ori_wall == 0)
	{
		bag->pars->texture = bag->pars->no;
		bag->pars->texture_width = bag->pars->width_no;
		bag->pars->texture_height = bag->pars->height_no;
	}
	else if (ray >= M_PI && ray < M_PI * 2 && bag->map->ori_wall == 0)
	{
		bag->pars->texture = bag->pars->so;
		bag->pars->texture_width = bag->pars->width_so;
		bag->pars->texture_height = bag->pars->height_so;
	}
	else if (ray >= M_PI_2 && ray < 3 * M_PI_2 && bag->map->ori_wall == 1)
	{
		bag->pars->texture = bag->pars->we;
		bag->pars->texture_width = bag->pars->width_we;
		bag->pars->texture_height = bag->pars->height_we;
	}
	else
	{
		bag->pars->texture = bag->pars->ea;
		bag->pars->texture_width = bag->pars->width_ea;
		bag->pars->texture_height = bag->pars->height_ea;
	}
}

void	draw_wall(t_raycasting raycasting, t_mlx *mlx, double dist_to_wall, t_struct *bag)
{
	double	height_of_wall;
	double	height_of_wall_2;
	long	i;
	int		pixel;
	float	bitmap_pixel;
	float	buffer;
	int limit;
	int limit_texture;

	i = 0;
	buffer = 0;
	choose_texture(bag, raycasting.ray);
	pixel = (bag->player->middle_of_screen * bag->pars->width) + raycasting.column;
	bitmap_pixel = bag->pars->texture_width * bag->pars->texture_height / 2 + (int)bag->map->Wall_x % 64;
	height_of_wall = (CUBE_SIZE / dist_to_wall) * raycasting.dist_to_screen;
	raycasting.bitmap_ratio = bag->pars->texture_width / height_of_wall;
	limit = bag->pars->width * bag->pars->height;
	limit_texture = bag->pars->texture_width * bag->pars->texture_height;
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
		if (pixel > limit * 2)
			break;
		if (pixel < limit)
			mlx->data[pixel] = bag->pars->texture[(int)bitmap_pixel] + bag->pars->color_psy;
		pixel += bag->pars->width;
		buffer += raycasting.bitmap_ratio;
		while (buffer >= 1)
		{
			if (bitmap_pixel + bag->pars->texture_width < bag->pars->texture_width * bag->pars->texture_height)
				bitmap_pixel += bag->pars->texture_width;
			buffer -= 1;
		}
		i++;
	}
	pixel = bag->player->middle_of_screen * bag->pars->width + raycasting.column;
	bitmap_pixel = bag->pars->texture_width * bag->pars->texture_height / 2 + (int)bag->map->Wall_x % 64;
	buffer = 0;
	while (i >= 0)
	{
		if (pixel < 0)
			break;
		if (pixel > 0)
			mlx->data[pixel] = bag->pars->texture[(int)bitmap_pixel] + bag->pars->color_psy;
		pixel -= bag->pars->width;
		buffer += raycasting.bitmap_ratio;
		while (buffer >= 1)
		{
			if (bitmap_pixel - bag->pars->texture_width > 0)
				bitmap_pixel -= bag->pars->texture_width;
			buffer -= 1;
		}
		i--;
	}
}
