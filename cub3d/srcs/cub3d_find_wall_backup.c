/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d_find_wall.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 17:11:09 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 13:43:01 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

t_list	find_wall(t_list *player, char **map)
{
	long CubeY;
	long CubeX;
	long Xinter;
	long Yinter;

	printf("\ndir : %f\n", player->dir);
	printf("player->x : %ld\n", player->x / 64);
	printf("player->y : %ld\n\n", player->y / 64);
	if (player->dir <= M_PI && player->dir > 0)
	{
		CubeY = trunc(player->y / CUBE_SIZE * CUBE_SIZ) - 1;
		Yinter = CUBE_SIZE * -1;
		printf("CubeY : %ld\n\n", player->y / CUBE_SIZE);
	}
	else
	{
		CubeY = trunc(player->y / CUBE_SIZE) * CUBE_SIZE + CUBE_SIZE;
		Yinter = CUBE_SIZE;
	}
	CubeX = player->x + trunc((player->y - CubeY) / tan(player->dir));
	Xinter = trunc(CUBE_SIZE / tan(player->dir));
	printf("\n\n~ First Cube ~\nCubeX : %ld\n", CubeX / CUBE_SIZE);
	printf("CubeY : %ld\n\n", CubeY / CUBE_SIZE);
	while (map[(int)CubeY / CUBE_SIZE][(int)CubeX / CUBE_SIZE] != '1')
	{
		printf("~ New Cube ~\n");
		CubeX = trunc((CubeX + Xinter));
		printf("CubeX : %ld\n", CubeX / CUBE_SIZE);
		CubeY = trunc((CubeY + Yinter));
		printf("CubeY : %ld\n\n", CubeY / CUBE_SIZE);
	}
	return (*player);
}

int main (void)
{
	t_list *player;
	char **map;

	map = parsing("../cub3d.cub");
	player = set_player(map);
	find_wall(player, map);
	return (0);
}
