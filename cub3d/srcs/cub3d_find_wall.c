/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d_find_wall.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 17:11:09 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/28 16:42:28 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

float	find_wall_vertical(t_list *player, m_list *map, r_list raycasting)
{
	c_list	Wall;
	long	result;

	printf("------Vertical------\n");
	if (raycasting.ray < M_PI_2 && raycasting.ray > (3 * M_PI / 2))
	{
		Wall.x = player->x / CUBE_SIZE * CUBE_SIZE + CUBE_SIZE;
		Wall.interX = CUBE_SIZE;
	}
	else
	{
		Wall.x = player->x / CUBE_SIZE * CUBE_SIZE - 1;
		Wall.interX = CUBE_SIZE * -1;
	}
	Wall.y = player->y + (player->x - Wall.x) * tan(raycasting.ray);
	Wall.interY = CUBE_SIZE * tan(raycasting.ray);
	Wall.colX = Wall.x / CUBE_SIZE;
	Wall.lineY = Wall.y / CUBE_SIZE;
//	printf("~ First Cube ~\n\nWall.x : %f\n", Wall.x / CUBE_SIZE);
//	printf("Wall.y : %f\n\n", Wall.y / CUBE_SIZE);
	if (Wall.colX < 0 || Wall.colX > map->tabwidth || Wall.lineY < 0 || Wall.lineY > map->tabheight)
	{
		printf("LONG_MAX\n");
		return (LONG_MAX);
	}
	while (map->map[Wall.lineY][Wall.colX] != '1')
	{
		Wall.x += Wall.interX;
	//	printf("Wall.x (boucle): %f\n", Wall.x / CUBE_SIZE);
		Wall.colX = Wall.x / CUBE_SIZE;
		Wall.y += Wall.interY;
	//	printf("Wall.y (boucle): %f\n\n", Wall.y / CUBE_SIZE);
		Wall.lineY = Wall.y / CUBE_SIZE;
		if (Wall.colX < 0 || Wall.colX > map->tabwidth || Wall.lineY < 0 || Wall.lineY > map->tabheight)
		{
			printf("LONG_MAX\n");
			return (LONG_MAX);
		}
	}
	printf("~ Last Cube ~\n");
	printf("Wall.x : %f\n", Wall.x / CUBE_SIZE);
	printf("Wall.y : %f\n\n", Wall.y / CUBE_SIZE);
	result = sqrt(pow(player->x - Wall.x, 2) + pow(player->y - Wall.y, 2));
	printf("result : %ld\n", result);
	return (sqrt(pow(player->x - Wall.x, 2) + pow(player->y - Wall.y, 2)));
}










float		find_wall_horizontal(t_list *player, m_list *map, r_list raycasting)
{
	c_list	Wall;
	long	result;

	printf("\n\n------New Ray------\n");
	printf("\ndir : %f\n", player->dir);
	printf("\nray : %f\n", raycasting.ray);
	printf("player->x : %d\n", player->x / CUBE_SIZE);
	printf("player->y : %d\n", player->y / CUBE_SIZE);
//	printf("tabwidth : %d\n", map->tabwidth);
//	printf("tabheight : %d\n\n", map->tabheight);
	if (raycasting.ray < M_PI && raycasting.ray > 0)
	{
		Wall.y = player->y / CUBE_SIZE * CUBE_SIZE - 1;
		Wall.interY = CUBE_SIZE * -1;
	}
	else
	{
		Wall.y = player->y / CUBE_SIZE * CUBE_SIZE + CUBE_SIZE;
		Wall.interY = CUBE_SIZE;
	}
	Wall.x = player->x + (player->y - Wall.y) / tan(raycasting.ray);
	Wall.interX = CUBE_SIZE / tan(raycasting.ray);
	Wall.colX = Wall.x / CUBE_SIZE;
	Wall.lineY = Wall.y / CUBE_SIZE;
	printf("------Horizontal------\n");
//	printf("~ First Cube ~\nWall.x : %f\n", Wall.x / CUBE_SIZE);
//	printf("Wall.y : %f\n\n", Wall.y / CUBE_SIZE); 
	if (Wall.colX < 0 || Wall.colX > map->tabwidth || Wall.lineY < 0 || Wall.lineY > map->tabheight)
	{
			printf("LONG_MAX\n");
			return (LONG_MAX);
	}
	while (map->map[Wall.lineY][Wall.colX] != '1')
	{
		Wall.x += Wall.interX;
//		printf("Wall.x (boucle): %f\n", Wall.x / CUBE_SIZE);
		Wall.colX = Wall.x / CUBE_SIZE;
		Wall.y += Wall.interY;
		Wall.lineY = Wall.y / CUBE_SIZE;
//		printf("Wall.y (boucle): %f\n\n", Wall.y / CUBE_SIZE);
		if (Wall.colX < 0 || Wall.colX > map->tabwidth || Wall.lineY < 0 || Wall.lineY > map->tabheight)
		{
			printf("LONG_MAX\n");
			return (LONG_MAX);
		}
	}
	printf("~ Last Cube ~\n");
	printf("Wall.x : %f\n", Wall.x / CUBE_SIZE);
	printf("Wall.y : %f\n\n", Wall.y / CUBE_SIZE);
	result = sqrt(pow(player->x - Wall.x, 2) + pow(player->y - Wall.y, 2));
	printf("result : %ld\n", result);
	return (sqrt(pow(player->x - Wall.x, 2) + pow(player->y - Wall.y, 2)));
}









int ray_tracing(d_list *bag)
{
	r_list	raycasting;
	int column;

	clear_wall(bag->mlx->data);
	column = 0;
	raycasting.FOV = FOV_DEG * M_PI / 180;
	printf("FOV : %f\n", raycasting.FOV);
	raycasting.dist_to_screen = (WIDTH_ECRAN / 2) / tan(raycasting.FOV / 2);
	printf("WIDTH_ECRAN : %d\n", WIDTH_ECRAN);
	printf("dist to screen : %f\n", raycasting.dist_to_screen);
	printf("tabheight : %d\n\n", bag->map->tabheight);
	raycasting.middle_of_screen = HEIGHT_ECRAN / 2;
//	printf("\ndist_to_screen : %d\n", raycasting.dist_to_screen);
//	printf("FOV : %f\n", raycasting.FOV);
	raycasting.inter_ray = raycasting.FOV / WIDTH_ECRAN;
//	printf("inter_ray : %f\n", raycasting.inter_ray);
	raycasting.ray = bag->player->dir; //+ raycasting.FOV / 2;
	if (raycasting.ray > 2 * M_PI)
		raycasting.ray -= 2 * M_PI;
//	printf("last_ray : %f\n", raycasting.last_ray);
	printf("dir origine : %f\n", bag->player->dir);;
	while (column < WIDTH_ECRAN)
	{
		if (raycasting.ray < 0)
			raycasting.ray += M_PI * 2;
		raycasting.long_horizontal = find_wall_horizontal(bag->player, bag->map, raycasting);
		raycasting.long_vertical = find_wall_vertical(bag->player, bag->map, raycasting);
		printf("long_vertical : %f\n", raycasting.long_vertical);
		printf("long_horizontal : %f\n", raycasting.long_horizontal);
		raycasting.ray -= raycasting.inter_ray;
		draw_wall(raycasting, bag->mlx, (whose_higher(raycasting) * cos(raycasting.ray - bag->player->dir)), column);
		column++;
	}
	mlx_put_image_to_window(bag->mlx->mlx_ptr, bag->mlx->win_ptr, bag->mlx->img_ptr, 0, 0);
	mlx_string_put(bag->mlx->mlx_ptr, bag->mlx->win_ptr, 10, 10, 0x6464FF, ft_strjoin("x : ", ft_itoa(bag->player->x / 64)));
	mlx_string_put(bag->mlx->mlx_ptr, bag->mlx->win_ptr, 10, 20, 0x6464FF, ft_strjoin("y : ", ft_itoa(bag->player->y / 64)));
	printf("\nlast ray traced : %f\n", bag->player->dir - raycasting.inter_ray);
	printf("Nombre de rayon : %d\n", column);
	return (1);
}
