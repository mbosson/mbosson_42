/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d_find_wall.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 17:11:09 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/27 16:58:09 by mbosson          ###   ########lyon.fr   */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

double	find_wall_vertical(t_player *player, t_map *map, t_raycasting raycasting)
{
	t_wall	Wall;
	double result;

	Wall.interY = CUBE_SIZE * tan(raycasting.ray);
	if ((raycasting.ray > 0 && raycasting.ray < M_PI_2) || (raycasting.ray > (3 * M_PI / 2) && raycasting.ray < 2 * M_PI))
	{
		Wall.x = (int)player->x / CUBE_SIZE * CUBE_SIZE + CUBE_SIZE;
		Wall.interX = CUBE_SIZE;
		Wall.interY *= -1;
	}
	else
	{
		Wall.x = (int)player->x / CUBE_SIZE * CUBE_SIZE - 0.0001;
		Wall.interX = CUBE_SIZE * -1;
	}
	Wall.y = player->y + (player->x - Wall.x) * tan(raycasting.ray);
	Wall.colX = (Wall.x / CUBE_SIZE);
	Wall.lineY = (Wall.y / CUBE_SIZE);
	if (raycasting.column == 150)
	{
		printf("## VERTICAL ##\n");
		printf("player->dir : %f\n", player->dir);
		printf("ray : %f\n", raycasting.ray);
		printf("inter x : %f\n", Wall.interX);
		printf("inter y : %f\n\n", Wall.interY);
		printf("~ First Cube ~\n");
		printf("Wall.x : %f\n", Wall.x);
		printf("Wall.y : %f\n", Wall.y);
		printf("PosX in map : %d\n", Wall.colX);
		printf("PosY in map : %d\n\n", Wall.lineY);
	}
	if (Wall.colX < 0 || Wall.colX > map->tabwidth || Wall.lineY < 0 || Wall.lineY > map->tabheight)
		return (LONG_MAX);
	while (map->map[Wall.lineY][Wall.colX] != '1')
	{
		Wall.x += Wall.interX;
		Wall.colX = Wall.x / CUBE_SIZE;
		Wall.y += Wall.interY;
		Wall.lineY = Wall.y / CUBE_SIZE;
		if (raycasting.column == 150)
		{
			printf("(Boucle)\n");
			printf("Wall.x : %f\n", Wall.x);
			printf("Wall.y : %f\n", Wall.y);
			printf("PosX in map : %d\n", Wall.colX);
			printf("PosY in map : %d\n\n", Wall.lineY);
		}
		if (Wall.colX < 0 || Wall.colX > map->tabwidth || Wall.lineY < 0 || Wall.lineY > map->tabheight)
			return (LONG_MAX);
	}
	if (raycasting.column == 150)
	{
		printf("~ Last Cube Vertical ~\n");
		printf("Wall.x : %f\n", Wall.x);
		printf("Wall.y : %f\n", Wall.y);
		printf("PosX in map : %d\n", Wall.colX);
		printf("PosY in map : %d\n", Wall.lineY);
	}
	result = sqrt(pow(player->x - Wall.x, 2) + pow(player->y - Wall.y, 2));
	if (raycasting.long_horizontal > result)
	{
		map->Wall_x = Wall.y;
		map->ori_wall = 1;
	}
	return (result);
}




double		find_wall_horizontal(t_player *player, t_map *map, t_raycasting raycasting)
{
	t_wall	Wall;

	if (raycasting.ray < M_PI && raycasting.ray > 0)
	{
		Wall.y = (int)player->y / CUBE_SIZE * CUBE_SIZE - 0.0001;
		Wall.interY = CUBE_SIZE * -1;
		Wall.interX = 1;
	}
	else
	{
		Wall.y = (int)player->y / CUBE_SIZE * CUBE_SIZE + CUBE_SIZE;
		Wall.interY = CUBE_SIZE;
		Wall.interX = -1;
	}
	Wall.x = player->x + (player->y - Wall.y) / tan(raycasting.ray);
	Wall.interX = Wall.interX * (CUBE_SIZE / tan(raycasting.ray));
	Wall.colX = (Wall.x / CUBE_SIZE);
	Wall.lineY = (Wall.y / CUBE_SIZE);
	if (raycasting.column == 150)
	{
		printf("## HORIZONTAL ##\n");
		printf("player->dir : %f\n", player->dir);
		printf("ray : %f\n", raycasting.ray);
		printf("inter x : %f\n", Wall.interX);
		printf("inter y : %f\n\n", Wall.interY);
		printf("~ First Cube ~\n");
		printf("Wall.x : %f\n", Wall.x);
		printf("Wall.y : %f\n", Wall.y);
		printf("PosX in map : %d\n", Wall.colX);
		printf("PosY in map : %d\n\n", Wall.lineY);
	}
	if (Wall.colX < 0 || Wall.colX > map->tabwidth || Wall.lineY < 0 || Wall.lineY > map->tabheight)
			return (LONG_MAX);
	while (map->map[Wall.lineY][Wall.colX] != '1')
	{
		Wall.x += Wall.interX;
		Wall.colX = Wall.x / CUBE_SIZE;
		Wall.y += Wall.interY;
		Wall.lineY = (Wall.y / CUBE_SIZE);
		if (raycasting.column == 150)
		{
			printf("(Boucle)\n");
			printf("Wall.x : %f\n", Wall.x);
			printf("Wall.y : %f\n", Wall.y);
			printf("PosX in map : %d\n", Wall.colX);
			printf("PosY in map : %d\n\n", Wall.lineY);
		}
		if (Wall.colX < 0 || Wall.colX > map->tabwidth || Wall.lineY < 0 || Wall.lineY > map->tabheight)
			return (LONG_MAX);
	}
	if (raycasting.column == 150)
	{
		printf("~ Last Cube Horizontal ~\n");
		printf("Wall.x : %f\n", Wall.x);
		printf("Wall.y : %f\n", Wall.y);
		printf("PosX in map : %d\n", Wall.colX);
		printf("PosY in map : %d\n", Wall.lineY);
	}
	map->Wall_x = Wall.x;
	map->ori_wall = 0;
	return (sqrt(pow(player->x - Wall.x, 2) + pow(player->y - Wall.y, 2)));
}









int ray_tracing(t_struct *bag)
{
	t_raycasting	raycasting;

	raycasting.column = 0;
	clear_wall(bag->mlx->data, bag);
	raycasting.FOV = bag->fov_deg * M_PI / 180;
	raycasting.dist_to_screen = (bag->pars->width / 2) / tan(raycasting.FOV / 2);
	raycasting.inter_ray = raycasting.FOV / bag->pars->width;
	raycasting.ray = bag->player->dir + raycasting.FOV / 2;
	if (raycasting.ray > 2 * M_PI)
		raycasting.ray -= 2 * M_PI;
	while (raycasting.column < bag->pars->width)
	{
		if (raycasting.ray < 0)
			raycasting.ray += M_PI * 2;
		raycasting.long_horizontal = find_wall_horizontal(bag->player, bag->map, raycasting);
		raycasting.long_vertical = find_wall_vertical(bag->player, bag->map, raycasting);
		raycasting.ray -= raycasting.inter_ray;
		draw_wall(raycasting, bag->mlx, whose_higher(&raycasting) * cos(raycasting.ray - bag->player->dir), bag);
		raycasting.column++;
	}
	mlx_put_image_to_window(bag->mlx->mlx_ptr, bag->mlx->win_ptr, bag->mlx->img_ptr, 0, 0);
	mlx_string_put(bag->mlx->mlx_ptr, bag->mlx->win_ptr, 10, 10, 0x6464FF, ft_strjoin("x : ", ft_itoa(bag->player->x / 64)));
	mlx_string_put(bag->mlx->mlx_ptr, bag->mlx->win_ptr, 10, 20, 0x6464FF, ft_strjoin("y : ", ft_itoa(bag->player->y / 64)));
	mlx_string_put(bag->mlx->mlx_ptr, bag->mlx->win_ptr, 10, 30, 0x6464FF, ft_strjoin("Middle of screen : ", ft_itoa(bag->player->middle_of_screen)));
	return (1);
}
