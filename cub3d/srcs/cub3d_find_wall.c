/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d_find_wall.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 17:11:09 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/23 18:01:49 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"



long	find_wall_vertical(t_list *player, m_list *map)
{
	c_list	Wall;

	printf("------Vertical------\n");
	if (player->dir <= M_PI_2 && player->dir > 3 * M_PI / 2)
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
	printf("\n\n~ First Cube ~\nWall.x : %ld\n", Wall.x / CUBE_SIZE);
	printf("Wall.y : %ld\n\n", Wall.y / CUBE_SIZE);
	if (Wall.colX < 0 || Wall.colX > map->tabheight || Wall.lineY < 0 || Wall.lineY > map->tabwidth)
		return (LONG_MAX);
	while (map->map[Wall.lineY][Wall.colX] != '1')
	{
		printf("~ New Cube ~\n");
		Wall.x = trunc((Wall.x + Wall.interX));
		Wall.colX = (int)Wall.x / CUBE_SIZE;
		printf("Wall.x : %ld\n", Wall.x / CUBE_SIZE);
		Wall.y = trunc((Wall.y + Wall.interY));
		Wall.lineY = (int)Wall.y / CUBE_SIZE;
		printf("Wall.y : %ld\n\n", Wall.y / CUBE_SIZE);
		if (Wall.colX < 0 || Wall.colX > map->tabheight || Wall.lineY < 0 || Wall.lineY > map->tabwidth)
			return (LONG_MAX);
	}
	return ((long)sqrt((player->x - Wall.x)^2 + (player->y - Wall.y)^2));
}

long		find_wall_horizontal(t_list *player, m_list *map)
{
	c_list	Wall;

	printf("\ndir : %f\n", player->dir);
	printf("player->x : %ld\n", player->x / 64);
	printf("player->y : %ld\n", player->y / 64);
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
	printf("------Horizontal------");
	printf("\n\n~ First Cube ~\nWall.x : %ld\n", Wall.x / CUBE_SIZE);
	printf("Wall.y : %ld\n\n", Wall.y / CUBE_SIZE);
	if (Wall.colX < 0 || Wall.colX > map->tabheight || Wall.lineY < 0 || Wall.lineY > map->tabwidth)
		return (LONG_MAX);
	while (map->map[Wall.lineY][Wall.colX] != '1')
	{
		printf("~ New Cube ~\n");
		Wall.x = trunc((Wall.x + Wall.interX));
		Wall.colX = (int)Wall.x / CUBE_SIZE;
		printf("Wall.x : %ld\n", Wall.x / CUBE_SIZE);
		Wall.y = trunc((Wall.y + Wall.interY));
		Wall.lineY = (int)Wall.y / CUBE_SIZE;
		printf("Wall.y : %ld\n\n", Wall.y / CUBE_SIZE);
		if (Wall.colX < 0 || Wall.colX > map->tabheight || Wall.lineY < 0 || Wall.lineY > map->tabwidth)
			return (LONG_MAX);
	}
	return ((long)sqrt((player->x - Wall.x)^2 + (player->y - Wall.y)^2));
}

int main(void)
{
	t_list	*player;
	m_list	*map;
	l_list	*libx;
	long	long_vertical;
	long	long_horizontal;
	float	FOV;
	float	inter_ray;
	float	last_ray;
	int i = 0;

	map = parsing("../cub3d.cub");
	player = set_player(map->map);
	FOV = FOV_DEG * M_PI / 180;
	inter_ray = FOV / WIDHT_ECRAN;
	player->dir  = FOV - FOV / 2;
	last_ray = FOV + FOV / 2;
	printf("\ndir : %f\n", player->dir);
	printf("\nFOV : %f\n", FOV);
	while (player->dir < last_ray)
	{
		long_horizontal = find_wall_horizontal(player, map);
		long_vertical = find_wall_vertical(player, map);
		player->dir += inter_ray;
		i++;
	}
	printf("Nombre de rayon : %d\n", i);
	return (0);
}
