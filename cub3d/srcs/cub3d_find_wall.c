/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d_find_wall.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 17:11:09 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/24 15:49:55 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

long	find_wall_vertical(t_list *player, m_list *map)
{
	c_list	Wall;
	long	result;

	printf("------Vertical------\n");
	if (player->dir < M_PI_2 && player->dir > 3 * M_PI / 2)
	{
		Wall.x = trunc(player->x / CUBE_SIZE * CUBE_SIZE) + 64;
		Wall.interX = CUBE_SIZE;
	}
	else
	{
		Wall.x = trunc(player->x / CUBE_SIZE * CUBE_SIZE) - 1;
		Wall.interX = CUBE_SIZE * -1;
	}
	Wall.y = trunc(player->y + (player->x - Wall.x) * tan(player->dir));
	Wall.interY = trunc(CUBE_SIZE * tan(player->dir));
	Wall.colX = (int)Wall.x / CUBE_SIZE;
	Wall.lineY = (int)Wall.y / CUBE_SIZE;
	printf("~ First Cube ~\nWall.x : %ld\n", Wall.x / CUBE_SIZE);
	printf("Wall.y : %ld\n\n", Wall.y / CUBE_SIZE);
	if (Wall.colX < 0 || Wall.colX > map->tabwidth || Wall.lineY < 0 || Wall.lineY > map->tabheight)
	{
		printf("LONG_MAX\n");
		return (LONG_MAX);
	}
	while (map->map[Wall.lineY][Wall.colX] != '1')
	{
		Wall.x = Wall.x + Wall.interX;
		printf("Wall.x (boucle): %ld\n", Wall.x / CUBE_SIZE);
		Wall.colX = (int)Wall.x / CUBE_SIZE;
		Wall.y = Wall.y + Wall.interY;
		printf("Wall.y (boucle): %ld\n\n", Wall.y / CUBE_SIZE);
		Wall.lineY = (int)Wall.y / CUBE_SIZE;
		if (Wall.colX < 0 || Wall.colX > map->tabwidth || Wall.lineY < 0 || Wall.lineY > map->tabheight)
		{
			printf("LONG_MAX\n");
			return (LONG_MAX);
		}
	}
	printf("~ Last Cube ~\n");
	printf("Wall.x : %ld\n", Wall.x / CUBE_SIZE);
	printf("Wall.y : %ld\n\n", Wall.y / CUBE_SIZE);
	result = (long)sqrt((player->x - Wall.x)^2 + (player->y - Wall.y)^2);
	printf("result : %ld\n", result);
	return (result);
}

long		find_wall_horizontal(t_list *player, m_list *map)
{
	c_list	Wall;
	long	result;

	
	printf("\n\n------New Ray------\n");
	printf("\ndir : %f\n", player->dir);
	printf("player->x : %ld\n", player->x);
	printf("player->y : %ld\n", player->y);
	printf("tabwidth : %d\n", map->tabwidth);
	printf("tabheight : %d\n\n", map->tabheight);
	if (player->dir <= M_PI && player->dir > 0)
	{
		Wall.y = trunc(player->y / CUBE_SIZE * CUBE_SIZE) - 1;
		Wall.interY = CUBE_SIZE * -1;
	}
	else
	{
		Wall.y = trunc(player->y / CUBE_SIZE) * CUBE_SIZE + CUBE_SIZE;
		Wall.interY = CUBE_SIZE;
	}
	Wall.x = player->x + trunc((player->y - Wall.y) / tan(player->dir));
	Wall.interX = trunc(CUBE_SIZE / tan(player->dir));
	Wall.colX = (int)Wall.x / CUBE_SIZE;
	Wall.lineY = (int)Wall.y / CUBE_SIZE;
	printf("------Horizontal------\n");
	printf("~ First Cube ~\nWall.x : %ld\n", Wall.x / CUBE_SIZE);
	printf("Wall.y : %ld\n\n", Wall.y / CUBE_SIZE); 
	if (Wall.colX < 0 || Wall.colX > map->tabwidth || Wall.lineY < 0 || Wall.lineY > map->tabheight)
	{
			printf("LONG_MAX\n");
			return (LONG_MAX);
	}
	while (map->map[Wall.lineY][Wall.colX] != '1')
	{
		Wall.x = Wall.x + Wall.interX;
		printf("Wall.x (boucle): %ld\n", Wall.x / CUBE_SIZE);
		Wall.colX = (int)Wall.x / CUBE_SIZE;
		Wall.y = Wall.y + Wall.interY;
		Wall.lineY = (int)Wall.y / CUBE_SIZE;
		printf("Wall.y (boucle): %ld\n\n", Wall.y / CUBE_SIZE);
		if (Wall.colX < 0 || Wall.colX > map->tabwidth || Wall.lineY < 0 || Wall.lineY > map->tabheight)
		{
			printf("LONG_MAX\n");
			return (LONG_MAX);
		}
	}
	printf("~ Last Cube ~\n");
	printf("Wall.x : %ld\n", Wall.x / CUBE_SIZE);
	printf("Wall.y : %ld\n\n", Wall.y / CUBE_SIZE);
	result = sqrt((double)((player->x - Wall.x)^(2) + (player->y - Wall.y)^(2)));
	printf("result : %ld\n", result);
	return (result);
}

int main(void)
{
	t_list	*player;
	m_list	*map;
	l_list	*mlx;
	r_list	raycasting;
	int column;

	column = 0;
	mlx = set_libx();
	map = parsing("map.cub");
	raycasting.FOV = FOV_DEG * M_PI / 180;
	raycasting.dist_to_screen = (WIDTH_ECRAN / 2) / tan(raycasting.FOV / 2);
	raycasting.middle_of_screen = HEIGHT_ECRAN / 2;
	printf("\ndist_to_screen : %d\n", raycasting.dist_to_screen);
	player = set_player(map->map);
	printf("FOV : %f\n", raycasting.FOV);
	raycasting.inter_ray = raycasting.FOV / WIDTH_ECRAN;
	printf("inter_ray : %f\n", raycasting.inter_ray);
	raycasting.last_ray = player->dir + raycasting.FOV / 2;
	printf("last_ray : %f\n", raycasting.last_ray);
	printf("dir origine : %f\n", player->dir);
	player->dir -= raycasting.FOV / 2;
	printf("first_ray : %f\n", player->dir);
	while (column <= WIDTH_ECRAN)
	{
		raycasting.long_horizontal = find_wall_horizontal(player, map);
		raycasting.long_vertical = find_wall_vertical(player, map);
		printf("long_vertical : %ld\n", raycasting.long_vertical);
		printf("long_horizontal : %ld\n", raycasting.long_horizontal);
		player->dir += raycasting.inter_ray;
		draw_wall(raycasting, mlx, whose_higher(raycasting), column);
//		if (player->dir > M_PI * 2)
//			player->dir -= M_PI_2;
		column++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	printf("\nlast ray traced : %f\n", player->dir - raycasting.inter_ray);
	printf("Nombre de rayon : %d\n", column);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
